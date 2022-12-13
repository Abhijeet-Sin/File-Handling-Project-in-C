#include <stdio.h>

void menu(int choiceOne)
{
    switch(choiceOne)
    {
        case 1:
        printf(" This is the 1st Case %d \n", choiceOne);
        break;

        case 2:
        printf(" This is the 2nd Case %d \n", choiceOne);
        break;

        case 3:
        printf(" This is the 3rd case %d \n", choiceOne);
        break;

        default:
        printf(" This is the default CASE \n");
        break;
    }
}

int main()
{
    int choice;
    printf("----------------------------------------------------\n");
    printf("__________________Welcome to menu!__________________\n");
    printf("----------------------------------------------------\n");
    printf("------------------Enter your Choice-----------------\n");
    do{
        printf("\n Enter your choice or -1 to QUIT : ");
        scanf("%d",&choice);
        menu(choice);
    }while(choice!=(-1));
    return 0;
}