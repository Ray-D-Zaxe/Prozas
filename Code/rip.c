#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h> // For lstat



void ls(const char *path){
    // Returns a pointer to a directory stream
    // Returns NULL if the directory doesn't exist or can't be opened due to denied permissions
    DIR *dir = opendir(path);

    // Checks for errors
    if (dir == NULL){
        perror("Error in opendir");
        return;
    }

    //
    struct dirent *entry;
    struct stat entry_stat;
    long long total_blocks = 0;
    char full_path[1024];
    while((entry = readdir(dir)) != NULL) {
        // Construct the full path to the entry (i.e. path/path/file.extention)
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        // Use lstat to get file information (lstat handles symbolic links correctly)
        if (lstat(full_path, &entry_stat) == 0) {
            // st_blocks gives the number of 512-byte blocks allocated
            total_blocks+= entry_stat.st_blocks;
        }
    }
    while((entry = readdir(dir)) != NULL) {
        printf("Name: %s\t\tSize: %zu\n", entry->d_name, entry->d_reclen);
    }
    // Closes the directory stream
    closedir(dir);
}



int main(int argc, char *argv[]) {
    printf("RipIt\n");

    const char *targetPath;

    if (argc > 1) {
        targetPath = argv[1];
    } else {
        targetPath = ".";
    }
    
    
    
    ls(targetPath);

    return 0;
}