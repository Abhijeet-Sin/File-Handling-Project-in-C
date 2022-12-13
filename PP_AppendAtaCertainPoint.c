#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void advanceAppend(char searchWord[], int frontORback,char insertWord[])
{
    char wordContainer[10][10]={'\0'};
    char updatesContainer[10][10]={'\0'};
    char letter='\0';
    int found=0;
    int i=0,j=0;
    int noOfWords=0;
    FILE *p=NULL;
    p=fopen("TempFile.txt","r+");
    if(p==NULL)
    {
        printf("SOme ERROR has Ocured and FILE cannot be opened");
    }

    //Searching for the word in file;
    while (!feof)
    {
        letter=fgetc(p);
        if (letter==' ',letter=='\0')
        {
            wordContainer[i][j]='\0';
            i++;
            j=0;
        }else{
            wordContainer[i][j]=letter;
            j++;
        }
    }

    noOfWords=i;
    i=0;
    j=0;
    
    //Searching the word entered by the user;
    for (int i = 0; i < noOfWords; i++)
    {
        if (strcmp(wordContainer[i],searchWord)==0)
        {
            if (frontORback<0)
            {
                for (int j = 0; j< strlen(insertWord); j++)
                {
                    updatesContainer[i+found][j]=searchWord[j];
                }
                
            }else
            {
                for (int j = 0; j< strlen(insertWord); j++)
                {
                    updatesContainer[i+found][j]=wordContainer[i][j];
                }
            }
            found++;
            if (frontORback>=0)
            {
                for (int j = 0; j < strlen(searchWord); j++)
                {
                    updatesContainer[i+found][j]=searchWord[j];
                } 
            }           
        }
        
        for (int j = 0; j < strlen(wordContainer[i]); j++)
        {
            updatesContainer[i+found][j]=wordContainer[i][j];
        }        
        noOfWords=i+found;
    }  
    rewind(p);
    for (int i = 0; i < noOfWords ; i++)
    {
        for (int j = 0; j < strlen(updatesContainer[i]); j++)
        {
            letter=updatesContainer[i][j];
            fputc(letter,p);
        }
        
    }
    
}

int main()
{
    char ser[10];
    int fORb;
    char text[10];
    fflush(stdin);
    printf("Enter WHere you want to append");
    gets(ser);
    printf("press -ve to enter before the word or +ve to enter after the word");
    scanf("%d",&fORb);
    fflush(stdin);
    printf("Enter the text you want to append");
    gets(text);
    advanceAppend(ser,fORb,text);
    return 0;
}