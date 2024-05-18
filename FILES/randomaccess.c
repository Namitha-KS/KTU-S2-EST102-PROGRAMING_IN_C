/*random access to files allows you to move the file pointer to a specific position for reading or writing data. This is more efficient than sequential access when you need to access data at arbitrary locations within the file.

Key Functions for Random Access
1. rewind(): Sets the file pointer to the beginning of the file.

>> rewind(file pointer)

2. fseek() : Moves the file pointer to a specified location.

>> fseek(file pointer, offset, origin)
offset - integer
origin - SEEK_SET, SEEK_CUR, or SEEK_END
    SEEK_SET : 

3. ftell() : Returns the current position of the file pointer.

>> ftell(file pointer)
*/




#include <stdio.h>

int main()
{
    FILE *fp = fopen("example.txt","r");
    if(fp==NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    // Moved the pointer to the first of the file and read
    rewind(fp);

    // char buffer[100];
    // fgets(buffer, 100, fp);
    // printf("FIRST LINE : %s", buffer);

    fseek(fp, -12, SEEK_END);
    char buffer[100];
    fgets(buffer, 100, fp);
    printf("SECOND LINE : %s\n", buffer);

    printf("CURRENT POSITION : %ld", ftell(fp));

    fclose(fp);

}