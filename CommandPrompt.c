#include "CommandPrompt.h"

// Display current working directory and return user input
char* CommandPrompt() {
    char *wd = malloc(BUFFERSIZE);
    char *input = malloc(BUFFERSIZE);

    if (getcwd(wd, BUFFERSIZE) == NULL) {
        perror("getcwd failed");
        free(wd);
        free(input);
        exit(1);
    }

    printf("%s%s", wd, PROMPT_SYMBOL);
    fflush(stdout);

    // gets the input
    if (fgets(input, BUFFERSIZE, stdin) == NULL) {
        perror("Failed to set input");
        free(input);
        free(wd);
        exit(1);
    }

    // remove newline character
    input[strcspn(input, "\n")] = 0;
    
    free(wd);
    return input;
}
