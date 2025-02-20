#ifndef EXECUTEPROMPT_H
#define EXECUTEPROMPT_H

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "Constants.h"
#include "ParseCommandLine.h"

void ExecuteCommand(struct ShellCommand command);

#endif
