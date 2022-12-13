#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void avdApend()
{
    char str[50]={'\0'};
    char app[10]={'\0'};
    char temp='\0';
    int applen=0,pos=0,str_len=0,choice=0,corrector=0;
  
    FILE *p = NULL;
    p=fopen("TempFile.txt","r+");
    if (p==NULL)
    {
        printf("The provided File path cannot be opened");
    }

    printf("\nEnter the string u want to insert and End String with a Space:");
    gets(app);
    
    printf("Do you want to append from the beginning or end of the word:\nEnter 1 to append in the begining\nEnter 2 to append in the end\nEnter your input :");
    scanf("%d",&choice);

    printf("\nEnter the position of the 1st letter of the word from where you want to append: ");
    scanf("%d",&pos);
    fflush(stdin);

    fgets(str,50,p);

    applen=strlen(app);
    str_len=strlen(str);

   if (choice==1)
   {
    for (int i = str_len-1; i>=pos-1; i--)
    {
        temp=str[i];
        str[i+applen]=temp;
    }

    for (int i = 0; i < applen; i++)
    {
        str[i+pos-1]=app[i];
    }
   }else if (choice==2)
   {
    for (int i = pos; i<50; i++)
    {
        if (str[i]== ' ')
        {
            corrector= i-pos+2;
            break;
        }
        
    }  
    for (int i = str_len-1; i>=pos - 1+ corrector; i--)
    {
        temp=str[i];
        str[i+applen]=temp;
    }
    for (int i = 0; i < applen; i++)
    {
        str[i+pos-1+corrector]=app[i];
    }
   }
    
    rewind(p);
    fputs(str,p);
    fclose(p);
}


int main()
{
    avdApend();
    return 0;
}