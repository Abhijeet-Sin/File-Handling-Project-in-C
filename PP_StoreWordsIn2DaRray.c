#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char serword[10];
    char words[10][10]={'\0'};
    int length=0,j=0,i;
    char str[10]={'\0'};    
    FILE * p=NULL;
    p=fopen("C:\\Users\\Admin\\C_file_handling\\test1.txt","r+");

    if(p==NULL)
    {
        printf("Create FILE first Before Reading\n");
        exit(1);
    }

    while (!feof(p))
    {
        fscanf(p," %s",str);
        length=strlen(str);
        for (i = 0; i<=length; i++)
        {
            words[j][i]=str[i];
        }
        j+=1;
    }

    fclose(p);
    
    for(i=0; i<j; i++) {
         printf("%s", words[i]);
         printf("\n");
         
   }
   
   
}