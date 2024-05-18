/*random access
1. rewind() : sets file pointer to the beginning of the file
rewind(file pointer)

2. fseek() : moves file pointer to specific/desired location
fseek(file pointer, offset, origin)
offset : integer value
origin : SEEK_SET , SEEK_CUR , SEEK_END

3. ftell() : current position
ftell(file pointer)
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