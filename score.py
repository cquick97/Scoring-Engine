#!/usr/bin/env python

# This is a scoring engine based on CyberPatriot.

import os.path
import time

def c99(file):
    if os.path.isfile("/var/www/c99.php") == False:
        file.write("\n<li>C99 Shell removed!\n")
        print("C99 Shell Removed!")
    return

while True:
    with open("/home/connor/scorereport.html", "w") as file:
        file.write("<!DOCTYPE html>\n")
        file.write("<head>\n")
        file.write("<meta charset=\"UTF-8\">\n")
        file.write("<title>Score Report</title>\n")
        file.write("</head>\n\n")
        file.write("<body>\n")
        file.write("<center><b>Score Report</b></center>\n")
        file.write("<ol>\n")
        c99(file)
        file.write("</ol>\n")
        file.write("</body>\n")
        file.write("</html>\n")
    time.sleep(10)



