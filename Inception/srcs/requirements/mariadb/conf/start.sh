#!/bin/sh

DB_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)
DB_PASSWORD=$(cat /run/secrets/db_password)
DB_NAME="${MYSQL_DATABASE}"
DB_USER="${MYSQL_USER}"

mkdir -p /run/mysqld
chown mysql:mysql /run/mysqld


    mysql_install_db --user=mysql --datadir=/var/lib/mysql
    chown -R mysql:mysql /var/lib/mysql
    mysqld_safe --user=mysql --datadir=/var/lib/mysql --skip-networking &
    
    echo "⏳ Waiting for MariaDB to be ready..."
    for i in $(seq 1 30); do
        if mysqladmin ping --silent; then break; fi
        sleep 1
    done

    mysqladmin -u root password "${DB_ROOT_PASSWORD}"

    mysql -u root -p"${DB_ROOT_PASSWORD}" <<-EOF
    CREATE DATABASE IF NOT EXISTS \`${DB_NAME}\`;
    CREATE USER IF NOT EXISTS '${DB_USER}'@'localhost' IDENTIFIED BY '${DB_PASSWORD}';
    CREATE USER IF NOT EXISTS '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';
    ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';
    GRANT ALL PRIVILEGES ON \`${DB_NAME}\`.* TO '${DB_USER}'@'localhost';
    GRANT ALL PRIVILEGES ON \`${DB_NAME}\`.* TO '${DB_USER}'@'%';
    FLUSH PRIVILEGES;
EOF

    mysqladmin -u root -p"${DB_ROOT_PASSWORD}" shutdown
    sleep 2

exec mysqld --user=mysql --skip-networking=0 --bind-address=0.0.0.0
