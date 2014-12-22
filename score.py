#!/usr/bin/env python

# This is a scoring engine based on CyberPatriot.

# Vulns:
#   C99 Shell
#   Sudo allows all users for no password
#   Maximum password age set in /etc/login.defs
#   Passwords
#   Groups
#   Hidden user

import os.path
import time
import re
from simplepam import authenticate # https://pypi.python.org/pypi/simplepam/0.1.5
import psutil # https://github.com/giampaolo/psutil

def backdoor(report, path):
    if os.path.isfile(path) == False:
        report.write("\n<li>Backdoor from '%s' removed!\n" % path)
        print("Backdoor from '%s' removed!" % path)
    return

def sudoers(report):
    if os.path.isfile("/etc/sudoers.d/all") == False:
        report.write("\n<li>Sudoers file secure\n")
        print("Sudoers file secure")
    return

def max_pw_age(report):
    if "PASS_MAX_DAYS" + '\t' + "99999" not in open("/etc/login.defs").read():
        report.write("\n<li>Maximum password age set\n")
        print("Maximum password age set.")
    return

def password(report, user, password):
    print(authenticate(user, password, service='sshd'))
    if authenticate(user, password, service='sshd') == False:
        report.write("\n<li>Insecure password changed for %s\n" % user)
        print("Insecure password changed for %s" % user)
    return

def hidden_user(report, name):
    if (
        name not in open("/etc/shadow").read() and
        name not in open("/etc/passwd").read()
        ):
        report.write("\n<li>Hidden user %s has been removed\n" % name)
        print("Hidden user %s has been removed" % name)
    return

def ssh_root_login(report):
    if ("PermitRootLogin yes" in open("/etc/ssh/sshd_config").read()):
        report.write("\n<li>Root SSH login disabled\n")
        print("Root SSH login disabled")
    return

def groups(report, user, group):
    # if user not in group
    with open("/etc/group") as file:
        for line in file:
            if re.search('^' + group, line) and user not in line:
                report.write("\n<li>%s has been removed from group %s\n" % (user,group))
                print("%s has been removed from group %s" % (user,group))
    return

def installed(report, path):
    if os.path.isfile(path) == False:
        name = path.split('/')
        report.write("\n<li>%s has been removed\n" % name[-1])
        print("%s has been removed" % name[-1])
    return

def services(report, service, status):
    # Used to check services enabled or disabled
    #service_list = psutil.get_process_list()
    service_list = list()
    for i in psutil.get_process_list():
        service_list.append(str(i))

    if any(service in s for s in service_list):
        if status == 1:
            report.write("\n<li>%s has been enabled\n" % service)
            print("%s has been enabled" % service)
    else:
        report.write("\n<li>%s has been disabled\n" % service)
        print("%s has been disabled" % service)


# Begin actual program
while True:
    with open("/home/connor/scorereport.html", "w") as report:
        report.write("<!DOCTYPE html>\n")
        report.write("<head>\n")
        report.write("<meta charset=\"UTF-8\">\n")
        report.write("<title>Score Report</title>\n")
        report.write("</head>\n\n")
        report.write("<body>\n")
        report.write("<center><b>Score Report</b></center>\n")
        report.write("<ol>\n")

        #backdoor(report, "/var/www/c99.php")
        #sudoers(report)
        #max_pw_age(report)
        #hidden_user(report, "toor")
        #password(report, "root", "root")
        #password(report, "jack", "jack")
        #groups(report, "leon", "adm")
        #installed(report, "/usr/local/bin/hydra")
        #services(report, "sshd", 0) # 0 = disable, 1 = enable

        report.write("</ol>\n")
        report.write("</body>\n")
        report.write("</html>\n")
    time.sleep(10)



