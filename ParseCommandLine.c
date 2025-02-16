#include <string.h>
#include <stdio.h>

// making the struct
struct ShellCommand {
    char* args;
    char* fileIn;
    char* fileOut;
};

// Process the user input (As a shell command)
// Note the return type is a ShellCommand struct
struct ShellCommand ParseCommandLine(char* input);

struct ShellCommand ParseCommandLine(char* input) {
    struct ShellCommand cmd;
    char* token;

    token = strtok(input, " ");
    while (token != NULL) {
        // case 1 (input needs to be redirected)
        if (strcmp(token, "<") == 0){

            if (token != NULL) {
                cmd.fileIn = strdup(token);
            }

        // case 2 (output needs to be redirected)
        } else if (strcmp(token, ">") == 0) {

            if (token != NULL) {
                cmd.fileOut = strdup(token);
            }

        }

    }

    return cmd;
}

// testing parsing
int main () {
    struct ShellCommand cmd;

    cmd = ParseCommandLine("ls -lh");

    printf("Args: %s", cmd.args);
    printf("I/O: %s \t %s", cmd.fileIn, cmd.fileOut);

}