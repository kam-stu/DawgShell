#include "ExecutePrompt.h"
#include "ParseCommandLine.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
Struct Format: 

struct ShellCommand {
    char* args[BUFFERSIZE];
    char* fileIn;
    char* fileOut;
};
*/

void ExecuteCommand(struct ShellCommand command) {
    // Handle "cd" separately
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
            if (command.fileOut) {
                FILE* fileOut = fopen(command.fileOut, "w");
                dup2(fileno(fileOut), 1);
                fclose(fileOut);
            }
            else if(command.fileIn) {
                FILE* fileIn = fopen(command.fileIn, "r");
                dup2(fileno(fileIn), 0);
                fclose(fileIn);
            }
            int error = execvp(command.args[0], command.args);
            if (error) {
                perror("Error 2");
                exit(1);
            }
        }
        wait(NULL);
        printf("\n");
    }
}

    

