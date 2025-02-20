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
    // handle "cd" separately
    if (strcmp(command.args[0], "cd") == 0) {
        int num = chdir(command.args[1]);

        if (num < 0) {
            perror("Error 13");
        }
    }
    else{
        pid_t p = fork();
        if (p < 0) {
            perror("Fork Failed");
            exit(1);
        }

        // Child process
        if (p == 0) {
            // case 1:
            // if output redirection occurs, redirects standard output
            if (command.fileOut) {
                FILE* fileOut = fopen(command.fileOut, "w");
                dup2(fileno(fileOut), 1);
                fclose(fileOut);
            }
            // case 2:
            // if input redirection occurs, redirects standard input
            else if(command.fileIn) {
                FILE* fileIn = fopen(command.fileIn, "r");
                dup2(fileno(fileIn), 0);
                fclose(fileIn);
            }
            // command input by user does not exist
            int error = execvp(command.args[0], command.args);
            if (error) {
                perror("Error 2");
                exit(1);
            }
        }
        // wait for process to finish
        wait(NULL);
        printf("\n");
    }
}

    

