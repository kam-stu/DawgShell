#include "CommandPrompt.h"

// Display current working directory and return user input
char* CommandPrompt() {
    char *wd = malloc(BUFFERSIZE);
    char *input = malloc(BUFFERSIZE);

    // gets current working directory and sets it do wd array
    if (getcwd(wd, BUFFERSIZE) == NULL) {
        perror("getcwd failed");
        free(wd);
        return NULL;
    }

    // prints working directory w/ "$" (prompt symbol)
    printf("%s%s", wd, PROMPT_SYMBOL);

    if (fgets(input, BUFFERSIZE, stdin) == NULL) {
        perror("Failed to set input");
        free(input);
        return NULL;
    }

    printf("You entered: %s", input);
    return input;
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