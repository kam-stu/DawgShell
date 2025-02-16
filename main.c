#include "CommandPrompt.h"
#include "ParseCommandLine.h"
#include "ExecutePrompt.h"

int main() {
    char* input;
    struct ShellCommand command;

    // repeatedly prompt the user for input
    for (;;) {
        printf("test 1");
        // get the user's input
        input = CommandPrompt();
        printf("%s", input);
        if (input == NULL) {
            printf("There was an error with input.  Please retry");
            return 1;
        }
        // parse the command line
        command = ParseCommandLine(input);

        // execute the command
        ExecuteCommand(command);
    }
    exit(0);
}
