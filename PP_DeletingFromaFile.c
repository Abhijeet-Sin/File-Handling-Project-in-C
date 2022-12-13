
//Deleting from array
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    

    char WordToDel[10]; 
    char words[10][10]={'\0'};
    char str[10]={'\0'};  
    char del[10][10]={'\0'};
    int length=0,j=0,i=0,z,ch=1,found=0; 
    char input;
    int NumberOfWords=0;

 //store in array from file
    FILE * p=NULL;

    p=fopen("ArrayToFile.txt","r+");

    if(p==NULL)
    {
        printf("File not found\n");
        exit(1);
    }

    while (!feof(p))
    {
        fscanf(p," %s",str);
        length=strlen(str);
        for (z = 0; z<=length; z++)
        {
            words[j][z]=str[z];
        }
        j+=1;
    }
    NumberOfWords=j;

//deleting in array

    printf("\n\nThe the words Array is :\n");
    for (int j = 0; j < NumberOfWords; j++)
    {
        printf("%s \n",words[j]);
    }
    
    printf("\nEnter the word you want to delete: ");
    gets(WordToDel);
    for (int j = 0; j < NumberOfWords; j++)
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

    printf("\n\nThe new Words Array is :\n");
    for (int j = 0; j < NumberOfWords; j++)
    {
        printf("%s \n",del[j]);
    }


//storing 2dRRAY IN FILE
    rewind(p);
    for (int j = 0; j < NumberOfWords ; j++)
    {
        // for (int k = 0; k < strlen(words[j]); k++)
        // {
        //     input=words[j][k];
        //     putc(input,p);
        // }
        fprintf(p,"%s ",del[j]);
    }
    fclose(p);
}