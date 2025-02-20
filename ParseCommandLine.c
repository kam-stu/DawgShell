#include "ParseCommandLine.h"

struct ShellCommand ParseCommandLine(char* input) {
    struct ShellCommand cmd;
    cmd.fileIn = NULL;
    cmd.fileOut = NULL;

    char* token;
    int arg_index = 0;

    token = strtok(input, " ");

    while (token != NULL) {
        // handles input redirection
        if (strcmp(token, "<") == 0) {
            token = strtok(NULL, " ");
            if (token) cmd.fileIn = strdup(token);
        } 
        // handles output redirection
        else if (strcmp(token, ">") == 0) {
            token = strtok(NULL, " ");
            if (token) cmd.fileOut = strdup(token);
        }
        else {
            cmd.args[arg_index++] = strdup(token);
        }
        token = strtok(NULL, " ");
    }

    // changes the last element in the array to NULL for execvp()
    cmd.args[arg_index] = NULL;
    return cmd;
}