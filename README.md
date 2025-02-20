# DawgShell
Names:
Grayson Lessard
Kam Stuckey

Description:
A program that mimics the functions of a linux terminal that features multiple different command functionalities.
Featuring I/O redirection, simple linux commands, and invlaid input handling.

- Displays current working directory as a prompt
- Parses user input to separate given commands and arguments
- Supports shell commands (cd, ls, etc.)
- Supports input and output redirection
- Executes *most* commands in child proccesses

# Design Implementations
- Each function is written in its own .c file with its own header (.h) to keep the code more organized and allow us to work on it simultaneously without messing each other up
- Main incorporates all c and header files to compile 


In order to compile the code, you must use all file names.  This is what the compilation should look like:
```bash
gcc Main.c CommandPrompt.c ExecutePrompt.c ParseCommandLine.c -o techshell
```