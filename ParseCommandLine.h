#ifndef PARSECOMMANDLINE_H
#define PARSECOMMANDLINE_H

#include <string.h>
#include <stdio.h>
#include "Constants.h"

// making the struct
struct ShellCommand {
    char* args[BUFFERSIZE];
    char* fileIn;
    char* fileOut;
};

struct ShellCommand ParseCommandLine(char* input);

#endif