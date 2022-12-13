#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 
int main()
{
    char orignal[40]="This is STRING";
    char Duplicate[40]="This is STRING also part 2";
    char truplicate[40]="This is";
    printf("Origional String: %s\n",orignal);
    printf("Duplicate String: %s\n",Duplicate);
    printf("Duplicate String: %s\n",truplicate);

    // //MEMCPY: void * memcpy ( void * destination, const void * source, size_t num );

    // //Copies the values of num bytes from the location pointed to by source directly to the memory block pointed to by destination.

    // memcpy(orignal,Duplicate,sizeof(Duplicate));
      
    // printf("\nOrigional String: %s\n",orignal);
    // printf("Duplicate String: %s\n",Duplicate);
    
    // for (int i = 0; i < 30; i++)
    // {
    //     printf("\n%c",orignal[i]);
    // }
    

    //MEMMOVE():-void * memmove ( void * destination, const void * source, size_t num );
    //Copies the values of num bytes from the location pointed by source to the memory block pointed by destination.
    //Copying takes place as if an intermediate buffer were used, allowing the destination and source to overlap.

    // memmove (Duplicate+15,Duplicate,15);
    // puts (Duplicate);
    // for (int i = 0; i < 30; i++)
    // {
    //     printf("\n%c",Duplicate[i]);
    // }
    // printf("%s",Duplicate);
    // return 0;

    // // STRCPY:- char * strcpy ( char * destination, const char * source );
    // // Copies the C string pointed by source into the array pointed by destination,
    // // including the terminating null character (and stopping at that point).
    // //Destination is returned.
    // strcpy(orignal,Duplicate);
    // printf("\nOrigional String: %s\n",orignal);
    // printf("Duplicate String: %s\n",Duplicate);
    
    // /* copy to sized buffer (overflow safe): */
    // strncpy ( Duplicate, truplicate, sizeof(Duplicate) );
    // printf("\nDuplicate String: %s\n",Duplicate);

    //  /* partial copy (only 5 chars): */
    //  strncpy ( orignal, Duplicate, 7);
    // orignal[7] = '\0';   /* null character manually added */
    // printf("\nOrigional String: %s\n",orignal);

    // //STRCAT():- char * strcat ( char * destination, const char * source );
    // //Appends a copy of the source string to the destination string. 
    // //The terminating null character in destination is overwritten by the first character of source,
    // //A null-character is included at the end of the new string formed by the concatenation of both in destination.
    // //Destination is returned.
    // strcat(orignal,truplicate);
    // printf("\nOrigional String: %s\n",orignal);
    // strcat(orignal,"concat");
    // printf("\nOrigional String: %s\n",orignal);

    // //STRNcat():-char * strncat ( char * destination, const char * source, size_t num );
    // //Appends the first num characters of source to destination, plus a terminating null-character.
    // //If the length of the C string in source is less than num, only the content up to the terminating null-character is copied.
    // //Destination is returned.
    // strncat(orignal,Duplicate,5);
    // printf("\nOrigional String: %s\n",orignal);
    // strncat(orignal,"concat",5);
    // printf("\nOrigional String: %s\n",orignal);
    // strncat(orignal,Duplicate,sizeof(Duplicate)/4);
    // printf("\nOrigional String: %s\n",orignal);

    // //MEMCMP():- int memcmp ( const void * ptr1, const void * ptr2, size_t num );
    // //Compares the first num bytes of the block of memory pointed by ptr1 to the first num bytes pointed by ptr2, 
    // //returning zero if they all match or a value different from zero representing which is greater if they do not.
    // //Unlike strcmp, the function does not stop comparing after finding a null character.
    // //Returns an integral value indicating the relationship between the content of the memory blocks
    // printf("\n%d\n",memcmp(orignal,Duplicate,sizeof(orignal)));
    // printf("%d\n",  memcmp(orignal,Duplicate,12));
    // printf("%d", memcmp(orignal,truplicate,sizeof(truplicate)));

    //STRCMP():-int strcmp ( const char * str1, const char * str2 );
    //This function starts comparing the first character of each string. If they are equal to each other,
    //It continues with the following pairs until the characters differ or until a terminating null-character is reached.
    // char answer[]={"papaya"};
    // char input[30]={'\0'};
    // int i=0;
    // do
    // {
    //     if(i!=0)
    //     {
    //     printf("Wrong Answer\n\n");
    //     }
    //     printf("\nMy Favourite fruit is? : ");
    //     gets(input);
    //     i++;
        
    // } while (strcmp(answer,input)!=0);
    // printf("CORRECT ANSWER!!!!!!!!!!");
    char str[128];
 
    printf("Enter a string: ");
    scanf("%[A-Z]s", str);
    printf("You entered: %s\n", str);
    fflush(stdin);
    printf("Enter a string: ");
    scanf("%[^o]s", str);
    printf("You entered: %s\n", str);
    fflush(stdin);
    printf("Enter a string with spaces: ");
    scanf("%[^\n]s", str);
 
    printf("You entered: %s\n", str);

}