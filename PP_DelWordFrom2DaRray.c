#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char WordToDel[10];
    char words[10][10]={'\0'};
    char del[10][10]={'\0'};
    int i=0,ch=1,found=0;
    do{
        printf("Enter a word: ");
        gets(words[i]);
        i++;
        printf("\nEnter 0 to quit entering and 1 to enter: ");
        scanf("%d",&ch);
        fflush(stdin);
    }while(ch!=0);

    printf("\n\n The the words Array is :");
    for (int j = 0; j < i; j++)
    {
        printf("%s \n",words[j]);
    }
    
    printf("\nEnter the word you want to delete: ");
    gets(WordToDel);
    for (int j = 0; j < i; j++)
    {
        
     if (strcmp(words[j],WordToDel)==0)
     {
        found+=1;
     }
     for (int l = 0; l < strlen(words[j+found]); l++)
     {
        del[j][l]=words[j+found][l];
     }        
    }

    printf("\n\n The new Words Array is :\n");
    for (int j = 0; j < i; j++)
    {
        printf("%s \n",del[j]);
    }
}