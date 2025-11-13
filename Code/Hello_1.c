#include<stdio.h>
#include<string.h>

char *get_filename_from_path(char *path){
    char *filename = path;
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

    // by replacing the '.' with '\0', we effectively remove the executable extension (i.e. .exe)
    if(dot != NULL){
        *dot = '\0';
    }

    // returns the file name
    return filename;
}

int main(int argc, char *argv[])
{
    printf("Hello World\n");
    printf("-----------------------------------------\n");

    char *filename = get_filename_from_path(argv[0]);

    if (argc < 2){
        printf("Too few arguments. . .\n");
        printf("Try using: %s <arg_1> <arg_2> ... <arg_n>\n", filename);
    }
    return 0;
}