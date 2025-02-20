#ifndef PARSECOMMANDLINE_H
#define PARSECOMMANDLINE_H

#include <string.h>
#include <stdio.h>
#include "Constants.h"

// struct design
struct ShellCommand {
    char* args[BUFFERSIZE];
    char* fileIn;
    char* fileOut;
};

struct ShellCommand ParseCommandLine(char* input);

#endif