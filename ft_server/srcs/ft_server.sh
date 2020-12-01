#!/bin/bash

cd /var/www/html

# nginx config
mv default /etc/nginx/sites-available/

# ssl
openssl req -x509 \
	-nodes \
	-newkey rsa:2048 \
	-sha256 \
	-days 3650 \
	-subj "/C=KR/ST=ULSAN/L=ULSAN/O=INNOACA/OU=42SEOUL/CN=localhost" \
	-keyout /etc/ssl/private/nginx-selfsigned.key \
	-out /etc/ssl/certs/nginx-selfsigned.crt

mv self-signed.conf /etc/nginx/snippets/

# php
mv cli-php.ini /etc/php/7.3/cli/php.ini
mv fpm-php.ini /etc/php/7.3/fpm/php.ini

# phpmyadmin
tar -xvf phpMyAdmin-5.0.4-all-languages.tar.gz
mv phpMyAdmin-5.0.4-all-languages phpmyadmin
mv config.inc.php phpmyadmin
mkdir phpmyadmin/tmp
chgrp www-data phpmyadmin/tmp
chmod 774 phpmyadmin/tmp
ln -s /var/www/html/phpmyadmin /home/phpmyadmin
rm phpMyAdmin-5.0.4-all-languages.tar.gz

# database
service mysql start
mysql -u root --skip-password < /var/www/html/phpmyadmin/sql/create_tables.sql
mysql -u root --skip-password < create_usr.sql
mysql -u root --skip-password < create_wp.sql

# wordpress
tar -xvf latest.tar.gz
mv wp-config.php wordpress/
ln -s /var/www/html/wordpress /home/wordpress
rm latest.tar.gz

service nginx start
service php7.3-fpm start
service mysql restart

bash
