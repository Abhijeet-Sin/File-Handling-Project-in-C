#include<stdio.h>
#include<stdlib.h>

int main()
{
    char str[100];
    char reading_arr[100];
    FILE *fp =NULL;
    fp=fopen("test1.txt","r+");
    if (fp==NULL)
    {
        printf("File not found\n");
        exit(1);
    }

    // printf("Enter Into The File : ");
    // gets(str);
    // fflush(stdin);
    // fputs(str,fp);
    // printf("the contents are updated in the file \n");
    
    fscanf(fp,"%s",reading_arr);
    printf("the contents of the file are : %s",reading_arr);
    fscanf(fp,"%s",reading_arr);
    printf("the contents of the file are : %s",reading_arr);
    fscanf(fp,"%s",reading_arr);
    printf("the contents of the file are : %s",reading_arr);

}