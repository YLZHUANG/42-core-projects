#!/bin/bash

set -e

DB_PASS=$(cat /run/secrets/db_password)
ROOT_DB_PASS=$(cat /run/secrets/db_root_password)
WP_ADMIN_PASS=$(grep WP_ADMIN_PASSWORD /run/secrets/credentials | cut -d '=' -f2)
WP_USER_PASS=$(grep WP_USER_PASSWORD /run/secrets/credentials | cut -d '=' -f2)
DB_NAME="${WORDPRESS_DB_NAME}"
DB_USER="${WORDPRESS_DB_USER}"
DB_HOST="${WORDPRESS_DB_HOST}"
WP_USER_EMAIL="${WP_EMAIL}"
WP_TITLE="${WP_TITLE}"
DOMAIN="${DOMAIN_NAME}"

if [ ! -f /var/www/html/wordpress/wp-config.php ]; then
  curl -o /tmp/latest.tar.gz https://wordpress.org/latest.tar.gz
  mkdir -p /var/www/html/wordpress
  tar -xzf /tmp/latest.tar.gz --strip-components=1 -C /var/www/html/wordpress
  rm /tmp/latest.tar.gz
fi

cd /var/www/html/wordpress

until mysql -h"$DB_HOST" -u"$DB_USER" -p"$DB_PASS" -e "SELECT 1" >/dev/null 2>&1; do
  sleep 3
done
echo "✅ Database connection established"

if [ ! -f wp-config.php ]; then
  wp config create \
    --dbname="$DB_NAME" \
    --dbuser="$DB_USER" \
    --dbpass="$DB_PASS" \
    --dbhost="$DB_HOST" \
    --allow-root
fi

if ! wp core is-installed --allow-root; then
  echo "🛠️ Installing WordPress..."
  wp core install \
    --url="https://${DOMAIN}" \
    --title="${WP_TITLE}" \
    --admin_user="${WP_ADMIN_USER}" \
    --admin_password="${WP_ADMIN_PASS}" \
    --admin_email="${WP_ADMIN_EMAIL}" \
    --skip-email \
    --allow-root

  echo "👤 Creating user..."
  wp user create "${WP_USER}" "${WP_USER_EMAIL}" \
    --user_pass="${WP_USER_PASS}" \
    --role=author \
    --allow-root
fi

chown -R www-data:www-data /var/www/html/wordpress

sed -i 's|^listen = .*|listen = 9000|' /etc/php/7.4/fpm/pool.d/www.conf
exec php-fpm7.4 -F