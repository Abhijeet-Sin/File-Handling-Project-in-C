#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char serword[10];
    char words[10][10];
    int i=0,ch=1;
    do{
        printf("Enter a word: ");
        gets(words[i]);
        i++;
        printf("\nEnter 0 to quit entering and 1 to enter: ");
        scanf("%d",&ch);
        fflush(stdin);
    }while(ch!=0);

    
    printf("\nEnter the word you want to search: ");
    gets(serword);
    for (int j = 0; j < i; j++)
    {
     if (strcmp(words[j],serword)==0)
     {
         printf("\n\nWord found at %d position",j);
     }
        
    }
}