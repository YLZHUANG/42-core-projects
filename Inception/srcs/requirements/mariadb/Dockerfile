FROM debian:bullseye

ENV DEBIAN_FRONTEND=noninteractive

# Install MariaDB server and clean up to reduce image size
RUN apt-get update && \
    apt-get install -y mariadb-server && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Copy your start script and give it execute permissions
COPY conf/start.sh /start.sh
RUN chmod +x /start.sh

# Ensure MariaDB directories exist (safety net)
RUN mkdir -p /var/lib/mysql /run/mysqld && \
    chown -R mysql:mysql /var/lib/mysql /run/mysqld

VOLUME /var/lib/mysql

EXPOSE 3306

ENTRYPOINT ["/start.sh"]
