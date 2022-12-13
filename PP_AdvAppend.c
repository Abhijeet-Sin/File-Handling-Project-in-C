#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char str[50]={'\0'};
    char app[10]={'\0'};
    char temp='\0';
    int applen=0,pos=0,str_len=0;
    printf("\nENter the String :");
    gets(str);

    printf("\nENter the string u want to insert :");
    gets(app);

    printf("\nEnter the position in which you want to insert :");
    scanf("%d",&pos);

    applen=strlen(app);
    str_len=strlen(str);

    for (int i = str_len-1; i>=pos-1; i--)
    {
        temp=str[i];
        str[i+applen]=temp;
    }

    for (int i = 0; i < applen; i++)
    {
        str[i+pos-1]=app[i];
    }
    
    printf("The new String is : %s",str);

    return 0;
}