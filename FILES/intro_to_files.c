/*File is a collection of data stored on a secondary storage device, such as a hard disk, that the computer treats as a single unit
 Files help preserve data even when a program terminates or the computer shuts down, making it easier to store, transfer, and manage information
 Types of Files
Text Files: These are simple files that contain plain text and can be read using any text editor like Notepad. They are easy to read and edit but offer less security and take more storage space.
Binary Files: These files store data in binary form (0's and 1's). They are more compact, harder to read without special software, and provide better security.*/

#include <stdio.h>

int main() {
    FILE *fp;

    // Writing to a file
    fp = fopen("example.txt", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    fprintf(fp, "Hello, file!\n");
    fclose(fp);

    // Reading from a file
    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    char str[100];
    while (fgets(str, 100, fp) != NULL) {
        printf("%s", str);
    }
    fclose(fp);
    return 0;
}