#include "ExecutePrompt.h"
/*
Struct Format: 

struct ShellCommand {
    char* args[BUFFERSIZE];
    char* fileIn;
    char* fileOut;
};
*/



void ExecuteCommand(struct ShellCommand command) {

    // handles cd itself
    if (strcmp(command.args[0], "cd") == 0) {
        chdir(command.args[1]);
    }
    else  {
        pid_t p = fork();
        if (p < 0) {
            perror("Fork Failed");
            exit(1);
        }
        // child process
        if (p == 0) {
            execvp(command.args[0], command.args);
            exit(0);
        }
    }
}
