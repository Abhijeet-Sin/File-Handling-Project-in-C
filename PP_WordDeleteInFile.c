#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void delete(char inputDelWord[])
{
    int i= 0, j=0;
    char letter='\0';
    int numberOfwords=0;
    char WordContainer[10][10]={'\0'};

    FILE *dfp = NULL;
    dfp=fopen("TempFile.txt","r+");
    if (dfp==NULL)
    {
        printf("The provided File path cannot be opened");

    }

    //While loop to store Content of File WOrd By WOrd In 2D Array
    while (!feof(dfp))
    {
        letter=fgetc(dfp);
       if (letter==' '||letter=='\0')
       {
         WordContainer[j][i]='\0';
         j++;
         i=0;
       }else{
        WordContainer[j][i]=letter;
        i++;
       }        
    }
    WordContainer[j][i-1]='\0';
    numberOfwords=j;
    j=0;

    fclose(dfp);

    //Finding out if DELETE WORD is EQUAL To THE words in the 2D Array And updating the array
    for (int i = 0; i <= numberOfwords; i++)
    {
        if (strcmp(WordContainer[i],inputDelWord)==0)
        {
            WordContainer[i][j]='\0';
        }
    }
    
    dfp=fopen("TempFile.txt","w");

    if (dfp==NULL)
    {
        printf("The provided File path cannot be opened");
    }
    for (int i = 0; i <= numberOfwords; i++)
    {
        if (WordContainer[i][j]=='\0')
        {
            continue;
        }else
        {
            fprintf(dfp,"%s ", WordContainer[i]);
        }        
    }

    fclose(dfp);
    
    printf("The contents of the file is : ");
    for (int i = 0; i <= numberOfwords; i++)
    {
        if (WordContainer[i][j]=='\0')
        {
            continue;
        }else
        {
            printf("%s ", WordContainer[i]);
        }        
    }
    

    
}

int main()
{
    char InpStr[50]={'\0'};
    char DelStr[10]={'\0'};
    char c='\0';
    int temp=0, i=0;

    fflush(stdin);
    
    printf("Enter the text into the file:");
    gets(InpStr);

    FILE *fp=NULL;
    fp=fopen("TempFile.txt","w");
    if (fp==NULL)
    {
        printf("The provided File path cannot be opened");
        exit(1);
    }
    
    temp=strlen(InpStr);
    while (i<temp)
    {
        c=InpStr[i];
        fputc(c,fp);
        i++;
    }

    fclose(fp);

    printf("Enter the word You want to delete: ");
    gets(DelStr);
    delete(DelStr);

    return 0;
}