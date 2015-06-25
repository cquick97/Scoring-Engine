#!/usr/bin/env python3

# This is a scoring engine based on CyberPatriot.
# Will loop every 10 seconds to check functions that are specified.
# If it is fixed, it will edit an HTML document to show the scores.
# Only real limitation to this is that the python file is plaintext and could
# easily be found and read by a competitor to get all the answers. Need to
# check into a way to stop that.

# Completed
# Backdoors
# Sudoers file
# Password Age
# User password
# Hidden users
# SSH root login
# User not in 'group'
# Installed software (ex: hydra)
# Running service (open port)
# Hidden media files

#import os.path
import os
import time
import re
from simplepam import authenticate # https://pypi.python.org/pypi/simplepam/0.1.5
import psutil # https://github.com/giampaolo/psutil

def backdoor(report, path):
    if os.path.isfile(path) == False:
        report.write("\n<li>Backdoor from '%s' removed!\n" % path)
        print("Backdoor from '%s' removed!" % path)
        global found
        found += 1
    return

def sudoers(report, path):
    if os.path.isfile("/etc/sudoers.d/" + path) == False:
        report.write("\n<li>Sudoers file secure\n")
        print("Sudoers file secure")
        global found
        found += 1
    return

def pw_age(report, choice, not_val):
    if "PASS_" + choice + "_DAYS" + '\t' + not_val not in open("/etc/login.defs").read():
        report.write("\n<li>%s password age set\n" % choice)
        print("%s password age set." % choice)
        global found
        found += 1
    return

def password(report, user, password):
    print(authenticate(user, password, service='sshd'))
    if authenticate(user, password, service='sshd') == False:
        report.write("\n<li>Insecure password changed for %s\n" % user)
        print("Insecure password changed for %s" % user)
        global found
        found += 1
    return

def hidden_user(report, name):
    if (
        name not in open("/etc/shadow").read() and
        name not in open("/etc/passwd").read()
        ):
        report.write("\n<li>Hidden user %s has been removed\n" % name)
        print("Hidden user %s has been removed" % name)
        global found
        found += 1
    return

def ssh_root_login(report):
    if ("PermitRootLogin yes" in open("/etc/ssh/sshd_config").read()):
        report.write("\n<li>Root SSH login disabled\n")
        print("Root SSH login disabled")
        global found
        found += 1
    return

def groups(report, user, group):
    # if user not in group
    with open("/etc/group") as file:
        for line in file:
            if re.search('^' + group, line) and user not in line:
                report.write("\n<li>%s has been removed from group %s\n" % (user,group))
                print("%s has been removed from group %s" % (user,group))
                global found
                found += 1
    return

def installed(report, path):
    if os.path.isfile(path) == False:
        name = path.split('/')
        report.write("\n<li>%s has been removed\n" % name[-1])
        print("%s has been removed" % name[-1])
        global found
        found += 1
    return

def services(report, service, status):
    # Used to check services enabled or disabled
    service_list = list()
    for i in psutil.process_iter():
        service_list.append(str(i))

    if any(service in s for s in service_list):
        if status == 1:
            report.write("\n<li>%s has been enabled\n" % service)
            print("%s has been enabled" % service)
            global found
            found += 1
    else:
        report.write("\n<li>%s has been disabled\n" % service)
        print("%s has been disabled" % service)
        global found
        found += 1
    return

def media(report, directory, extension):
    if all(extension not in s for s in os.listdir(directory)):
        print("Forbidden files removed")
        global found
        found += 1
    return

# Begin actual program
while True:
    found = 0
    with open("/home/leon/Desktop/scorereport.html", "w") as report:
        report.write("<!DOCTYPE html>\n")
        report.write("<head>\n")
        report.write("<meta charset=\"UTF-8\">\n")
        report.write("<title>Score Report</title>\n")
        report.write("</head>\n\n")
        report.write("<body>\n")
        report.write("<center><b>Score Report</b></center>\n")
        report.write("<ol>\n")

        backdoor(report, "/var/www/html/c99.php")
        sudoers(report, "all")
        pw_age(report, "MAX", "99999")  # MAX/MIN, value it shouldn't be
        hidden_user(report, "toor")
        password(report, "root", "root")
        password(report, "jack", "jack")
        groups(report, "tyler", "adm")
        installed(report, "/usr/bin/hydra")
        services(report, "vsftpd", 0) # 0 = disable, 1 = enable
        ssh_root_login(report)

        report.write("</ol>\n")
        report.write("<br></br>")
        report.write("<center><b>" + str(found) + " out of 10 vulnerabilities found.</b></center>\n")
        report.write("</body>\n")
        report.write("</html>\n")
    time.sleep(10)
