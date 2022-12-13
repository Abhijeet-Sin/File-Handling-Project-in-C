#This is the Code For Project With Description
//This header file includes different variables, macros, and functions to perform input and output
#include <stdio.h>
//To use functions such as strcmp, strlen and strcpy
#include <string.h>
//To use fflush(stdin) and exit()
#include <stdlib.h>

//Every Funnction has its local variables so it doesn't matter if they are same in name.

//WRITE function
void write()
{   
    //str[] array to store the string from the user that you want to write on a file 
    char str[100];    
    printf("Enter the String to write in the file :");

    //Taking input using gets(Array_you_want_to_store_data_in) function
    gets(str);
    
    //Creating the file pointer
    FILE * p=NULL;

    //Opening the file in write mode coz file needs to be created if FILE is not Present
    p=fopen("Task_ONE.txt","w");

    //Checking if the file pointer is null and if NULL the following error message is dsplayed
    if(p==NULL)
    {
        printf("The FIle Was Not\n");
    }else{
        //Write in file using fgets(Array_from_which_you_want_to_insert_in_file, FILE_pointer) function
        fputs(str,p);
       
    }
    //Closing the file to release the memory it returns 0 on sucess and EOF on failure
    //EOF is a onstant defined in stdio.h as a negative integer value which denotes a end of file has reached
    fclose(p);

    //printing sucess message
    printf("\nSucessfully WRITTEN on FILE!!!\n");
}

//READ function
void read()
{
    //str[] array to store the string that you got after reading from the file
    char str[100];    

    //Initialising starting point as NULL
    FILE * p=NULL;

    //Opening FILE in READ mode
    p=fopen("Task_ONE.txt","r");

    if(p==NULL)
    {
        printf("Create FILE first Before Reading\n");
    }else{
        //Read from file using fgets(Array_you_want_to_store_data_in, Size_of_array, FILE_POINTER) function
        printf("\nThe Contents of the FILE are: %s ",fgets(str,100,p));
        printf("\n");
    }
    fclose(p);
}

//Append function
void append()
{   
    char str[100];    
    FILE * p=NULL;
    //Opening FILE in APPEND MODE
    p=fopen("Task_ONE.txt","a");

    if(p==NULL)
    {
        printf("Create FILE first Before Reading\n");
    }else{
        //Code to Read from file
        printf("\nEnter the text you want to APPEND: ");
        gets(str);
        //putting the contents off the str[] array in the file using fputs(Array_from_which_you_want_to_insert_in_file, FILE POINTER)
        fputs(str,p);
        printf("\nSucessfully APPENDED!!!\n");
    }
    //All files need to be closed after opening because every time u open a file a descriptor is allocated.
    //Number of descriptor available to a process is limited and is limited by /OPEN_MAX control in sys/limits.h and controlled by ulimit -n flag
    //DEscriptor is an unsigned integer used by a process to identify an open file
    fclose(p);
}

// Function to delete a word from the file that the user wants to delete it takes the word user wants to delete as input
void delete(char inputDelWord[])
{
    int i= 0, j=0;
    //letter is a char type variable used to store a single letter of the word
    char letter='\0';

    //number of words of the array
    int numberOfwords=0;
    
    //WordContainer[][] is a 2-D array that is used store one word of the file in one row at a time and all the content is stored in all rows
    char WordContainer[10][10]={'\0'};

    FILE *p = NULL;

    //File is opened in r+mode so that we can read as well as write from the file instead of using r and w seperately 
    p=fopen("Task_ONE.txt","r+");
    if (p==NULL)
    {
        printf("\nThe provided File path cannot be opened");

    }

    //While loop to store Content of File WOrd By WOrd In 2D Array
    //feof(File Pointer) is the function that returns 1 when file pointer is at the end of the file  
    while (!feof(p))
    {
        //Storing the content one letter at a time in letter
        letter=fgetc(p);

        //Reading content till we hit a space or end of file
       if (letter==' '||letter=='\0')
       {
        //here j represents the row and i represents the column 
        //we are initialising the last character of the row with '\0' so that we can convert each row to string from array of character array to array of string array
         WordContainer[j][i]='\0';
         j++;
         i=0;
       }else{
        //if the space is not hit then keep on storing and increment row
        WordContainer[j][i]=letter;
        i++;
       }        
    }
    // adding '\0' to the end of the last insrtion coz after inserting the last element it will reach eof and  it will come out of the loop
    WordContainer[j][i-1]='\0';
    //setting no of words equal to j as no of rows are equal to no of words as we are storing line by line
    numberOfwords=j;
    j=0;

    fclose(p);

    //Finding out if DELETE WORD is EQUAL To THE words in the 2D Array And updating the array
    for (int i = 0; i <= numberOfwords; i++)
    {
        //Comparing the input from the user to the contents of the WordsContainer[][] array if match setting the first element as '\0'
        //using strcmp(string1,string2) function to compare if the 2 strings are equal
        if (strcmp(WordContainer[i],inputDelWord)==0)
        {
            WordContainer[i][j]='\0';
        }
    }
    
    
    //opening the file in write mode to write the contents of the WordsContainer 
    p=fopen("Task_ONE.txt","w");

    if (p==NULL)
    {
        printf("The provided File path cannot be opened");
    }

    for (int i = 0; i <= numberOfwords; i++)
    {
        //checking if the 1st index of each row is 0 or not
        //if zero then we increment i 
        if (WordContainer[i][j]=='\0')
        {
            //used to skip the content below it or jump back to the loop
            continue;
        }else
        {
            //writing the content in the file
            fprintf(p,"%s ", WordContainer[i]);
        }        
    }
    memset(WordContainer, '\0', sizeof(WordContainer[0][0]) * 10 * 10);
    
    fclose(p);

    char str_read [100]={'\0'};
    p=fopen("Task_ONE.txt","r");
    fgets(str_read,100,p);
    printf("The contents of the file is : %s",str_read);
    fclose(p);

}

//Function to replace a word from the file it takes the word user wants to replace and the new word as parameter
void replace(char toReplace[],char replacement[])
{
    //str length is used to store a -ve or +ve value that tells which string is biger
    //if -ve then string entered by the user is bigger if +ve the nstring entered by the user is smaller
    int strlength=strcmp(toReplace,replacement);
    int i= 0, j=0;
    char letter='\0';
    int numberOfwords=0;
    char WordContainer[10][10]={'\0'};

    FILE *p = NULL;
    p=fopen("Task_ONE.txt","r+");
    if (p==NULL)
    {
        printf("The provided File path cannot be opened");

    }

    //While loop to store Content of File WOrd By WOrd In 2D Array
    while (!feof(p))
    {
        letter=fgetc(p);
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

    fclose(p);

    //Finding out if replace WORD is EQUAL To THE words in the 2D Array And updating the array
    for (int i = 0; i <= numberOfwords; i++)
    {
        //checking if the string in WordsContainer is equal to the word user wants to delete
        if (strcmp(WordContainer[i],toReplace)==0)
        {
            //Checking if new word is smaller than the old word
           if (strlen(toReplace)>strlen(replacement))
           {
             //if the replacement word is smaller then we need to either set the contents of the array as '\0' 
            //OR we need to put the rest of the contents as '\0' after the replacement is done as as old word was bigger than the replacement   
             for (int j = 0; j < strlen(replacement); j++)
                {
                    WordContainer[i][j]=replacement[j]; 
                }
            //entering '\0' at the end of the replacement to make it a string
             for (int j = strlen(replacement); j < strlen(WordContainer[i]); j++)
                {
                    WordContainer[i][j]='\0';
                }
           }else{
             //if new word is bigger then we can store it as it is
             for (int j = 0; j < strlen(replacement); j++)
                {
                    WordContainer[i][j]=replacement[j];
                }
           }
           
        }
    }
    
    //writing the contents of the updated WordsContainer[][] array in the FILE
    p=fopen("Task_ONE.txt","w");

    if (p==NULL)
    {
        printf("The provided File path cannot be opened");
    }
    for (int i = 0; i <= numberOfwords; i++)
    {
        fprintf(p,"%s ", WordContainer[i]);
    }

    fclose(p);
    
    char str_read [100]={'\0'};
    p=fopen("Task_ONE.txt","r");
    fgets(str_read,100,p);
    printf("The contents of the file is : %s",str_read);
    fclose(p);
}

//This Function Appends the content Before or after a WORD
void avdApend()
{
    //to store the contents of the file
    char str[50]={'\0'};
    
    //the word user wants to add 
    char app[10]={'\0'};
    
    //variable used to help in shifting contents in array
    char temp='\0';

    //corrector is the length of the word after which user wants to append
    //str_len is the length of the string
    int applen=0,pos=0,str_len=0,choice=0,corrector=0;
    
    FILE *p = NULL;
    p=fopen("Task_ONE.txt","r+");
    if (p==NULL)
    {
        printf("The provided File path cannot be opened");
    }

    printf("\nEnter the string u want to insert and End String with a Space:");
    gets(app);
    
    printf("Do you want to append from the beginning or end of the word:\n* Enter 1 to append in the begining \n* Enter 2 to append in the end \n-> Enter your input :");
    scanf("%d",&choice);

    printf("\nEnter the position of the 1st letter of the word from where you want to append: ");
    scanf("%d",&pos);
    //used to clear the buffer or we can use get(ch) because after scanf \n character remains in buffer only
    fflush(stdin);

    fgets(str,50,p);

    //finding the length of the string user wants to append
    applen=strlen(app);
    //finding the lenth of the file 
    str_len=strlen(str);

    //to check the choice of user if he wants to append at the starting of the word or ending of the word
    if (choice==1) //entering at the starting
    {
        //running the for loop from the end of the strig and making space to insert the new append string user wants to enter
    for (int i = str_len-1; i>=pos-1; i--)
    {
        temp=str[i];
        str[i+applen]=temp;
    }

    //for loop till the length of the the string the user wants to enter
    for (int i = 0; i < applen; i++)
    {
        //inputing the new string at the space we created earlier
        str[i+pos-1]=app[i];
    }
    }else if (choice==2) //if user wants to enter after the given word
    {
    //here 50 has been randomly added to run the loop as no word can be bigger than 50
    for (int i = pos; i<50; i++)
    {
        //checking for space or NULL character to know the end of the  word 
        //if the condition becomes true that means word has ended and the length of the word is noted and the loop is exited
        if ((str[i]== ' ')||(str[i]== '\0'))
        {
            corrector= i-pos+2;
            break;
        }
    }
    //running the for loop from the end of the strig and making space to insert the new append string user wants to enter
    for (int i = str_len-1; i>=pos - 1+ corrector; i--)
    {
        temp=str[i];
        str[i+applen]=temp;
    }
    //Inserting the append word after the given word
    for (int i = 0; i < applen; i++)
    {
        str[i+pos-1+corrector]=app[i];
    }
   }
    //rewinding the location of the pointer as it has already travelled the end of the file and is at the end
    rewind(p);//rewinding it to the beginning
    //storing the contents of the str in the Task_ONE.txt file
    fputs(str,p);
    //closing the file pointer
    fclose(p);
}

//MENU function
void menu(int choiceOne)
{
    //Using switch Statement to find the choice entered by the user  
    switch(choiceOne)
    {
        
        case 1://to create or write onto an existing file
        printf("\nYou Selected To WRITE on FILE \n");
        write();
        break;

        case 2://to read from an existing file
        printf("\n You Selected To READ from FILE\n");
        read();
        break;

        case 3://to append at the end of a file
        printf("\nYou Selected To APPEND on FILE\n");
        append();
        break;

        case 4://to delete a word from a file
        printf("\nYou Selected To DELETE a word From the File\n");
        //word that user wants to delete
        char DelStr[10]={'\0'};
        printf("\nEnter the word You want to delete: ");
        gets(DelStr);
        //delete(the_word_user_wants_to_delete) function to delete a word that the user has given as input
        delete(DelStr);
        break;
        
        case 5://to search and replace a given word from the file
        printf("\nYou Selected To SEARCH and REPLACE from FILE");
        char ToRep[10]={'\0'};
        char Rep[10]={'\0'};
        printf("\nWhich word You want to Replace: ");
        gets(ToRep);
        printf("\nEnter the Replacement word: ");
        gets(Rep);
        replace(ToRep,Rep);
        break;

        case 6://to append after or before a word 
        printf("\n You Selected AdvAPPEND ON FILE\n");
        avdApend();
        break;

        //if the user enetrs an input not belonging to the above group of input then this case is run
        default:
        printf("\nPls Enter A Valid Input Or (-1) To Quit \n");
        break;
    }
}

//MAIN function
int main()
{
    //to take the choice from the user and display te menu
    int choice;
    printf("----------------------------------------------------\n");
    printf("__________________Welcome to menu!__________________\n");
    printf("----------------------------------------------------\n");
    printf("------------------Enter your Choice-----------------\n");
    printf("-----------1. For CREATE and WRITE on FILE----------\n");
    printf("-----------2. To Display the contents of the file---\n");
    printf("-----------3. To APPEND in the file-----------------\n");
    printf("-----------4. To DELETE a word in the File----------\n");
    printf("-----------5. To REPLACE a word in the file---------\n");
    printf("-----------6. To APPEND on a word in the file-------\n");
    
    //do{}while() loop to iterate and collect choices from the user one by one
    do{     
        printf("\n Enter your choice or -1 to QUIT : ");
        scanf("%d",&choice);
        fflush(stdin);
        menu(choice);
    }while(choice!=(-1));
    //return 0 that tells the compiler that the program has sucessfully been executed
    return 0;
}
