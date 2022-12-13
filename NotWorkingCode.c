//Replace Function
// void replace()
// {
//     char ser[10];    
//     char rep[10];
//     int slen,count=0,arrtravel=0,occCounter=0;
//     int pointerpos=0,occurances[20]={0};
//     char c;

//     printf("Enter the word you Want to Search");
//     scanf("%s",&ser);
//     strlen(ser);
//     printf("Enter the word you want to replace this word with");
//     scanf("%s",&rep);

//     FILE * p=NULL;
//     p=fopen("Task_ONE.txt","a+");
//     if(p==NULL)
//     {
//         printf("Create FILE first Before Replacing\n");
//     }else{
//         //Code to Search in The file
//        while (!feof)
//        {
//         c=fgetc(p);
//         if(slen==count)
//         {
//             pointerpos=ftell(p);
//             occurances[occCounter]=pointerpos;
//         }
//         if (c==' ')
//         {
//             count=0;
//             arrtravel=0;
//         }else{
//             if(c==ser[0])
//             {
//                 if(c==ser[arrtravel])
//                 {
//                     count+=1;
//                     arrtravel+=1;
//                 }
//             }
//             }
//        } 

//        for (int i = 0; i < 20; i++)
//        {
//         if((occurances[i]-slen)>=0)
//         {
//             fseek(p,(occurances[i]-slen),SEEK_SET);
//             fputs(rep,p);
//         }
//        }
       
//     }
//     fclose(p);
//     printf("\nSucessfully REPLACED!!!\n");
// }

// //Delete Function
// void delete()
// {
//     char str[100];   
//     char del[10]; 
//     FILE * p=NULL;
//     FILE *temp=NULL;

//     printf("enter the word you want to delete");
//     gets(del);


//     p=fopen("Task_ONE.txt","r");
//     temp=fopen("TempFile.txt","w");


//     if(p==NULL||temp==NULL)
//     {
//         printf("File not found \n");
//         exit(1);
//     }

//     while(!feof)
//     {
//         fgets(str,100,p);
//         removeAll(str,del);
//         fputs(str,temp);
//     }

//     rename("TempFile","Task_ONE");
//     fclose(p);
//     fclose(temp);
// }

// //removeAll function copied from web
// void removeAll(char * str, const char * toRemove)
// {
//     int i, j, stringLen, toRemoveLen;
//     int found;

//     stringLen   = strlen(str);      // Length of string
//     toRemoveLen = strlen(toRemove); // Length of word to remove


//     for(i=0; i <= stringLen - toRemoveLen; i++)
//     {
//         /* Match word with string */
//         found = 1;
//         for(j=0; j < toRemoveLen; j++)
//         {
//             if(str[i + j] != toRemove[j])
//             {
//                 found = 0;
//                 break;
//             }
//         }

//         /* If it is not a word */
//         if(str[i + j] != ' ' && str[i + j] != '\t' && str[i + j] != '\n' && str[i + j] != '\0') 
//         {
//             found = 0;
//         }

//         /*
//          * If word is found then shift all characters to left
//          * and decrement the string length
//          */
//         if(found == 1)
//         {
//             for(j=i; j <= stringLen - toRemoveLen; j++)
//             {
//                 str[j] = str[j + toRemoveLen];
//             }

//             stringLen = stringLen - toRemoveLen;

//             // We will match next occurrence of word from current index.
//             i--;
//         }
//     }

#include<stdio.h>

// //Delete function
// void delete()
// {
    
//     char WordToDel[10]={'\0'}; ; 
//     char words[10][10]={'\0'};
//     char str[10]={'\0'};  
//     char del[10][10]={'\0'};
//     int length=0,j=0,i=0,z,ch=1,found=0; 
//     int NumberOfWords=0;

//  //store in array from file
//     FILE * p=NULL;

//     p=fopen("Task_ONE.txt","r+");

//     if(p==NULL)
//     {
//         printf("File not found\n");
//         exit(1);
//     }

//     while (!feof(p))
//     {
//         for (int i = 0; i < 10; i++)
//         {
//             str[i]='\0';
//         }
        
//         fscanf(p," %s",str);
//         length=strlen(str);
//         for (z = 0; z<length; z++)
//         {
//             words[j][z]=str[z];
//         }
//         j+=1;
//     }
//     NumberOfWords=j;

// //deleting in array

//     printf("\nThe the words Array is :\n");
//     for (int j = 0; j < NumberOfWords; j++)
//     {
//         printf("%s ",words[j]);
//     }
    
//     printf("\n");

//     printf("\nEnter the word you want to delete: ");
//     gets(WordToDel);
//     NumberOfWords--;
//     for (int j = 0; j < NumberOfWords; j++)
//     {
        
//      if (strcmp(words[j+found],WordToDel)==0)
//      {
//         found++;
//         for (int l = 0; l < strlen(words[j+found]); l++)
//         {
//             del[j][l]=words[j+found][l];
//             del[j][l+1]='\0';
//         }   
//      }else{
//             for (int l = 0; l < strlen(words[j+found]); l++)
//             {   
//                 del[j][l]=words[j+found][l];
//                 del[j][l+1]='\0';
//             }   
//         }
//     }
//     fclose(p);

//     printf("\nThe Contents of the FILE are is :\n");
//     for (int j = 0; j < NumberOfWords; j++)
//     {
//         printf("%s ",del[j]);
//     }

//     printf("\n");

// //storing 2dRRAY IN FILE
//     p=fopen("Task_ONE.txt","w");
//     for (int j = 0; j < NumberOfWords; j++)
//     {
//         // for (int k = 0; k < strlen(words[j]); k++)
//         // {
//         //     input=words[j][k];
//         //     putc(input,p);
//         // }
//         fprintf(p,"%s ",del[j]);
//     }
//     fclose(p);

// }


// //Replace a word
// void Replace()
// {
    
//     char WordToDel[10]={'\0'}; 
//     char WordToReplace[10]={'\0'}; ;
//     char words[10][10]={'\0'};
//     char str[10]={'\0'};  
//     char del[10][10]={'\0'};
//     int length=0,j=0,i=0,z,ch=1,found=0; 
//     char input={'\0'}; 
//     int NumberOfWords=0;

//  //store in array from file
//     FILE * p=NULL;

//     p=fopen("Task_ONE.txt","r+");

//     if(p==NULL)
//     {
//         printf("File not found\n");
//         exit(1);
//     }

//     while (!feof(p))
//     {
//         fscanf(p," %s",str);
//         length=strlen(str);
//         for (z = 0; z<=length; z++)
//         {
//             words[j][z]=str[z];
//         }
//         j+=1;
//     }
//     NumberOfWords=j;

// //deleting in array

//     printf("\nThe the words Array is :\n");
//     for (int j = 0; j < NumberOfWords; j++)
//     {
//         printf("%s ",words[j]);
//     }
    
//     printf("\n");

//     printf("\nEnter the word you want to Replace: ");
//     gets(WordToDel);
//     printf("\nEnter the word you want to Replace WITH: ");
//     gets(WordToReplace);
    
//     for (int j = 0; j < NumberOfWords; j++)
//     {
        
//      if (strcmp(words[j],WordToDel)==0)
//      {
//         for (int l = 0; l < strlen(WordToReplace); l++)
//         {
//             del[j][l]=WordToReplace[l];
//         }   
//      }else{

//             for (int l = 0; l < strlen(words[j]); l++)
//             {
//                del[j][l]=words[j][l];
//              }  
//         } 

//     }

//     fclose(p);

//     printf("\nThe new Words Array is :\n");
//     for (int j = 0; j < NumberOfWords; j++)
//     {
//         printf("%s ",del[j]);
//     }

//      printf("\n");

// //storing 2dRRAY IN FILE
//     p=fopen("Task_ONE.txt","w");
//     for (int j = 0; j < NumberOfWords ; j++)
//     {
//         // for (int k = 0; k < strlen(words[j]); k++)
//         // {
//         //     input=words[j][k];
//         //     putc(input,p);
//         // }
//         fprintf(p,"%s ",del[j]);
//     }
//     fclose(p);
// }

// #include<stdio.h>
// #include<string.h>

// void removeWord(char *str)
// {
//     int i,j=0,k=0;
//     char words[10][20];
//     printf("this point is reached");
//     for (i=0;str[i]!='\0';i++)
//     {
      
//     }
//     printf("\nthe words array is :-");

//     for ( i = 0; i < 10; i++)
//     {
//         for (int a = 0; a < 20; a++)
//         {
            
//         }
        
//     }
    
// }

// int main()
// {
//     char string[100];
//     printf("enter a String :");
//     gets(string);
//     printf("\nwill this print");
//     removeWord(string);
    
// }