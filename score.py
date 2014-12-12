#!/usr/bin/env python

# This is a scoring engine based on CyberPatriot.

# Vulns:
#   C99 Shell
#   Sudo allows all users for no password
#   Maximum password age set in /etc/login.defs

import os.path
import time
import re

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
        max_pw_age(report)
        report.write("</ol>\n")
        report.write("</body>\n")
        report.write("</html>\n")
    time.sleep(10)



