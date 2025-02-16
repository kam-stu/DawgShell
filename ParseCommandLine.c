#include "ParseCommandLine.h"

struct ShellCommand ParseCommandLine(char* input) {
    char* token;
    struct ShellCommand cmd;
    cmd.fileIn = NULL;
    cmd.fileOut = NULL;
    
    token = strtok(input, " ");
    while (token != NULL) {
        // case 1 (input needs to be redirected)
        if (strcmp(token, "<") == 0){

            // go to next token and set the fileIn to that token
            if (token != NULL) {
                token = strtok(NULL, " ");
                cmd.fileIn = strdup(token);
            }

        // case 2 (output needs to be redirected)
        } else if (strcmp(token, ">") == 0) {

            // go to next token and set the fileOut to that token
            if (token != NULL) {
                token = strtok(NULL, " ");
                cmd.fileOut = strdup(token);
            }
        }
    }
    return cmd;
}