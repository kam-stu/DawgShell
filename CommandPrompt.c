#include "CommandPrompt.h"

// Display current working directory and return user input
char* CommandPrompt() {
    char *wd = malloc(BUFFERSIZE);
    char *input = malloc(BUFFERSIZE);

    printf("Right before directory\n");
    // gets current working directory and sets it do wd array
    if (getcwd(wd, BUFFERSIZE) == NULL) {
        perror("getcwd failed");
        free(wd);
        return NULL;
    }

    // prints working directory w/ "$" (prompt symbol)
    printf("%s%s", wd, PROMPT_SYMBOL);
    fflush(stdout);

    if (fgets(input, BUFFERSIZE, stdin) == NULL) {
        perror("Failed to set input");
        free(input);
        return NULL;
    }

    // removes the newline character
    input[strcspn(input, "\n")] = 0;
    fflush(stdout);
    
    return input;
}