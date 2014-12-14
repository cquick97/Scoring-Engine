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
import pam

def c99(report):
    if os.path.isfile("/var/www/c99.php") == False:
        report.write("\n<li>C99 Shell removed!\n")
        print("C99 Shell Removed!")
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
    p = pam.pam()
    if p.authenticate(user, password, 'sshd') == False:
        report.write("\n<li>Insecure password changed for %s\n" % user)
        print("Insecure password changed for %s" % user)
    return

def hidden_user(report):
    if (
        "toor" not in open("/etc/shadow").read() and
        "toor" not in open("/etc/passwd").read()
        ):
        report.write("\n<li>Hidden user has been removed\n")
        print("Hidden user has been removed")
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
        #c99(report)
        #sudoers(report)
        #max_pw_age(report)
        #hidden_user(report)
        #password(report, "root", "root")
        #password(report, "jack", "jack")
        #groups(report, "leon", "adm")
        #installed(report, "/usr/local/bin/hydra")
        report.write("</ol>\n")
        report.write("</body>\n")
        report.write("</html>\n")
    time.sleep(10)



