#include "CommandPrompt.h"

// Display current working directory and return user input
char* CommandPrompt() {
    char *wd = malloc(BUFFERSIZE);

    // gets current working directory and sets it do wd array
    if (getcwd(wd, BUFFERSIZE) == NULL) {
        perror("getcwd failed");
        free(wd);
        return NULL;
    }

    // prints working directory w/ "$" (prompt symbol)
    printf("%s%s", wd, PROMPT_SYMBOL);
    return wd;
}

// testing function
int main() {
    char* input;

    input = CommandPrompt();

    if (input != NULL) {
        free(input);
    }

    return 0;
}