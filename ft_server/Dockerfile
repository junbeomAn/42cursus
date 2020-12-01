FROM debian:buster

LABEL maintainer "juan <juan@student.42seoul.kr>"

RUN apt update && apt upgrade \
&& apt-get install -y vim \
					nginx \
					openssl \
					php7.3-fpm \
					php-mysql \
					mariadb-server \
					php-mbstring \
					wget

WORKDIR /var/www/html

COPY srcs/* ./

EXPOSE 80 443

CMD bash ft_server.sh
