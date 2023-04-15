#include <stdio.h>
#define OUT_FILE_NAME datap2.txt

void copy(FILE* out, FILE* in)
{
    int ch;
    while ((ch = fgetc(in))!= EOF)
    {
        fputc(ch, out);
    }  
}

int main(void){
    FILE* fp = fopen("datap2.txt", "w");
    if (fp ==NULL)
    {
        printf("Error");
    }
    else
    {
        copy(fp, stdin);
    }
    fclose(fp);

    return 0;
}


// Win: Crtl + z , Enter
// Linux: Crtl D