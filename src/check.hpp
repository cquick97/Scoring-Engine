#ifndef __CHECK_H_INCLUDED__
#define __CHECK_H_INCLUDED__

bool isFileExist(const char *fileName);

bool isStringInFile(const char *fileName, const char *searchString);

bool isPortOpen(const char *portNumber);

#endif
