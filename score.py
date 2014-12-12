#!/usr/bin/env python

# This is a scoring engine based on CyberPatriot.

# Vulns:
#   C99 Shell
#   Sudo allows all users for no password
#   Maximum password age set in /etc/login.defs

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

def root_pw(report):
    # Using the probability that any password changed will have a different
    # hash. Almost impossible chance it will be the same.
    p = pam.pam()
    if p.authenticate('root', 'root', 'sshd') == False:
        report.write("\n<li>Insecure root password changed\n")
        print("Insecure root password changed")
    return

def hidden_user(report):
    if (
        "toor:$1$Mf.LwAFR$vkGdl1CjOv3ioN" in open("/etc/shadow").read() and
        "toor:x:0:0:root:/root:/bin/bash" in open("/etc/passwd").read()
        ):
        report.write("\n<li>Hidden user has been removed\n")
        print("Hidden user has been removed")
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
        c99(report)
        sudoers(report)
        max_pw_age(report)
        root_pw(report)
        hidden_user(report)
        report.write("</ol>\n")
        report.write("</body>\n")
        report.write("</html>\n")
    time.sleep(10)



