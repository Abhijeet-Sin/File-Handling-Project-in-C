#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{

    char words[10][10]={'\0'};
    int i=0,ch=1;
    char input;
    do{
        printf("Enter a word: ");
        gets(words[i]);
        i++;
        printf("\nEnter 0 to quit entering and 1 to enter: ");
        scanf("%d",&ch);
        fflush(stdin);
    }while(ch!=0);

    printf("\n\n The the words Array is :\n");
    for (int j = 0; j < i; j++)
    {
        printf("%s \n",words[j]);
    }

    FILE *fp =NULL;
    fp=fopen("ArrayToFile.txt","a");
    if (fp==NULL)
    {
        printf("word not found");
        exit(1);
    }
    
    for (int j = 0; j < i; j++)
    {
        // for (int k = 0; k < strlen(words[j]); k++)
        // {
        //     input=words[j][k];
        //     fputc(input,fp);
        // }
        fprintf(fp,"%s ",words[j]);
    }
    
}