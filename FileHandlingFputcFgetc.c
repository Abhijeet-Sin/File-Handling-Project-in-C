#include <stdio.h>

int main()
{
    int i=0;
    char ch;
    char str[]={"This is the DEFAULT value that is present in Array"};
    
    printf("\nThe Default value present in the array is : %s \n",str);
    printf("Enter the String to write in the file \n");
    gets(str);
    
    //Opening the file
    FILE * p=NULL;
    p=fopen("fgetc_and_putc.txt","w");

    if(p==NULL)
    {
        printf("The FIle Was Not\n");
    }else{
        //Code to Write in file
        fputs(str,p);
       
    }
    fclose(p);
    printf("THE DATA has been INPUTTED \n");
    
    //Read mode
    p=fopen("fgetc_and_putc.txt","r");
    char str_one[50];
    if(p==NULL)
    {
        printf("The FIle Was Not\n");
    }else{
        //Code to Write in file
        printf("%s",fgets(str_one,50,p));
       
    }
    fclose(p);
    // *p=NULL;
    // //Code to display the contents of a file
    // i=0;
    // p=fopen("fgetc_and_putc.txt","r");
    // if(p==NULL)
    // {
    //     printf("The FIle Was Not CREATED\n");
    // }else{
    //     //Code to Write in file
    //     while (!feof)
    //     {
    //         ch=fgetc(p);
    //         printf("%c",ch);
    //         str[i]=ch;
    //         i++;
    //     }

    // }
    return 0;
}