#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char answer;
    char choice;
    char name [100];
    char password [10];
    int length;
    double amount;
    double balance = 0;

    printf ("************************ \n");
    printf ("* Welcome to the bank !*\n");
    printf ("************************ \n");

    do
    {
        printf ("Already have an account ? Y/N \n");
        scanf (" %c" ,&answer);
        answer = toupper (answer);

        // new user

        if (answer == 'N')
        {
            printf ("\n Create an account \n");
            printf ("\n Enter username : \n");
            scanf ("%s" ,name);
            do
            {
            printf ("\n Make an 8-digit password : \n");
            scanf ("%s" ,password);
            length = strlen (password);

                if (length != 8)
                {
                    printf("\n Invalid password! Re-enter password ! \n");
                }
            }
            while (length != 8);
            printf ("\n Account created successfully ! \n");
        }

        // old user

        else if (answer == 'Y')
        {
        do
        {
            printf ("\n Enter your 8-digit password : \n");
            scanf ("%s" ,password);
            length = strlen (password);
            if (length != 8)
            {
                printf ("\n Please re-enter password ! \n");
            }
        }
        while (length != 8);
        printf ("\n Welcome back ! \n");
        }
        else
        {
            printf ("Invalid choice ! \n");
        }
    }
    while (answer != 'Y' && answer != 'N');

    //Bank menu

    do
    {
        printf("\nPlease select what option you want:\n");
        printf("'A' -> Deposit \n");
        printf("'B' -> Withdraw \n");
        printf("'C' -> Check Balance \n");
        printf("'D'-> Transfer Money \n");
        printf("'E' -> Exit \n");
        scanf (" %c" ,&choice);
        choice = toupper (choice);

        if (choice == 'A')
        {
            printf ("Enter amount to deposit : \n");
            scanf ("%lf" ,&amount);
            balance += amount;
            printf ("Operation done successfully ! \n");
            printf ("Current balance = $%.2f \n" ,balance);
        }

        else if (choice == 'B')
        {
            printf ("Enter amount to withdraw : \n");
            scanf ("%lf" ,&amount);
            if (amount > balance)
            {
                printf ("Insufficient amount ! \n");
                printf ("Operation failed ! \n");
            }
            else
            {
               balance -= amount;
               printf ("Operation done successfully ! \n");
            }
            printf ("Current balance = $%.2f \n" ,balance);
        }
        else if (choice == 'C')
        {
            printf ("Current balance = $%.2f \n" ,balance);
        }
        else if (choice == 'D')
        {
            printf ("Enter amount to transfer : \n");
            scanf ("%lf" ,&amount);
            if (amount > balance)
            {
                printf ("Insufficient amount ! \n");
                printf ("Operation failed ! \n");
            }
            else
            {
               balance -= amount;
               printf ("Operation done successfully ! \n");
            }
            printf ("Current balance = $%.2f \n" ,balance);
        }
        else if (choice == 'E')
        {
            printf ("Thank you for using the bank ! \n");
        }
        else
        {
            printf ("Invalid choice \n");
        }

    }

    while (choice != 'E');

    return 0;
}