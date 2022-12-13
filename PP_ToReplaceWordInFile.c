#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void replace(char toReplace[],char replacement[])
{
    int strlength=strcmp(toReplace,replacement);
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

    //Finding out if replace WORD is EQUAL To THE words in the 2D Array And updating the array
    for (int i = 0; i <= numberOfwords; i++)
    {
        if (strcmp(WordContainer[i],toReplace)==0)
        {
           if (strcmp(toReplace,replacement)<0)
           {
             for (int j = 0; j < strlen(replacement); j++)
                {
                    WordContainer[i][j]=replacement[j]; 
                }
             for (int j = strlen(replacement); j < strlen(WordContainer[i]); j++)
                {
                    WordContainer[i][j]='\0';
                }
           }else{
             for (int j = 0; j < strlen(replacement); j++)
                {
                    WordContainer[i][j]=replacement[j];
                }
           }
           
        }
    }
    
    dfp=fopen("TempFile.txt","w");

    if (dfp==NULL)
    {
        printf("The provided File path cannot be opened");
    }
    for (int i = 0; i <= numberOfwords; i++)
    {
        fprintf(dfp,"%s ", WordContainer[i]);
    }

    fclose(dfp);
    
    printf("The contents of the file is : ");
    for (int i = 0; i <= numberOfwords; i++)
    {
        printf("%s ", WordContainer[i]);        
    }    
}


int main()
{
    char InpStr[50]={'\0'};
    char ToRep[10]={'\0'};
    char Rep[10]={'\0'};
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

    printf("Enter the word You want to Replace: ");
    gets(ToRep);

    printf("\nenter the new word: ");
    gets(Rep);

    replace(ToRep,Rep);

    return 0;
}