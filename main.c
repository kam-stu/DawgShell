#include "CommandPrompt.h"

// Execute a shell command
// Note the parameter is a ShellCommand struct
void ExecuteCommand(struct ShellCommand command);


int main() {
    char* input;
    struct ShellCommand command;

    // repeatedly prompt the user for input
    for (;;) {

        // get the user's input
        input = CommandPrompt();
        if (input == NULL) {
            print("There was an error with input.  Please retry");
            return 1;
        }

        // parse the command line
        command = ParseCommandLine(input);

        // execute the command
        ExecuteCommand(command);
    }
    exit(0);
}
