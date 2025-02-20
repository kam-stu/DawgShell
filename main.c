#include "CommandPrompt.h"
#include "ParseCommandLine.h"
#include "ExecutePrompt.h"
#include "Constants.h"

int main() {
    char* input;
    struct ShellCommand command;

    for (;;) {
        input = CommandPrompt();

        if (strlen(input) == 0) {
            free(input);
            continue;
        }

        // exits the program
        if (strcmp(input, "exit") == 0) {
            free(input);
            break;
        }

        command = ParseCommandLine(input);
        ExecuteCommand(command);

        free(input);
    }

    exit(0);
}

