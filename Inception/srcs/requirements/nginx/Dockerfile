FROM alpine:3.21
RUN apk update && apk upgrade && apk add --no-cache nginx openssl

RUN mkdir -p /etc/nginx/ssl
RUN mkdir -p /run/nginx
RUN mkdir -p /var/log/nginx
RUN mkdir -p /var/www/html/wordpress


COPY conf/nginx.conf /etc/nginx/nginx.conf
COPY tools/nginx.crt /etc/nginx/ssl/nginx.crt
COPY tools/nginx.key /etc/nginx/ssl/nginx.key

EXPOSE 443
CMD ["nginx", "-g", "daemon off;"]
