#include<stdio.h>
#include<string.h>

char *get_filename_from_path(char *path){
    // sets filename to path
    char *filename = path;

    // finds the last occurence of '\'
    char *separator = strrchr(path, '\\');

    // strrchr is used to find the last occurence of a character in a string
    // and returns a pointer to that character
    // returns null if not found, i.e. path is actually a filename

    if (separator != NULL){
        // sets filename to the next character after the separator character '\'
        filename = separator + 1;
    }

    // finds the last occurence of '.' to locate the .exe part
    char *dot = strrchr(filename, '.');

    // by replacing the '.' with '\0', we effectively remove the executable extension (i.e. Hello_1.exe\0 becomes Hello_1\0exe\0)
    if(dot != NULL){
        *dot = '\0';
    }

    // returns the file name
    return filename;
}

int main(int argc, char *argv[])
{
    // Start of the program
    printf("Hello World\n");
    printf("-----------------------------------------\n\n");



    // gets the name of the executable
    char *filename = get_filename_from_path(argv[0]);



    // if there are no arguments except for the executable itself
    if (argc < 2){
        printf("Too few arguments. . .\n");
        printf("Try using: %s <arg_1> <arg_2> ... <arg_n>\n", filename);
        printf("\n-----------------------------------------\n\n");
    }



    // iterates through the arguments if any
    for (int i = 1; i < argc; i++){
        // Sets the current argument
        char *current_arg = argv[i];


        // If the current argument is -v or --version
        if (strcmp(current_arg, "-v") == 0 || strcmp(current_arg, "--version") == 0){
            printf("%s, version 1.0, LesssGooo\n", filename);
        }


        // If the current argument is -h or --help
        if (strcmp(current_arg, "-h") == 0 || strcmp(current_arg, "--help") == 0){
            printf("Usage: %s <arg_1> <arg_2> ... <arg_n>\n", filename);
            printf("Options for arguments:\n");
            
            {
                printf("\t-v, --version\t\tPrints the version of the program\n");
                printf("\t-h, --help\t\tPrints this help message\n");
                printf("\t<anything_else>\t\tPrints the argument and its index and the number of characters in it.\n");
            }
        }


        // If the current argument is anything else
        else{
            printf("Argument: %s,\tChars: %zu, Index: %d\n", current_arg, strlen(current_arg), i);
        }

        printf("\n-----------------------------------------\n\n");
    }
    
    
    
    // End of the program
    printf("------------Program Finished-------------\n");
    return 0;
}