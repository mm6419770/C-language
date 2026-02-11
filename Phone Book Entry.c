#include <stdio.h>
#include <string.h>
#define MAX 100

struct Contact
{
    char name[100];
    int phone;
};

int main ()
{
    int choice;
    char contactName [100];
    int phoneNumber;
    char searchName [100];
    int count = 0;
    struct Contact contacts[MAX];
    char deleteName [100];
    char editName [100];
    int found = 0;
    printf ("   __________________ \n");
    printf ("\n |||Phone book entry||| \n");
    printf ("   __________________ \n");
    printf ("\n Menu : \n");

    do
    {
        printf ("\n 1) Add contact \n");
        printf ("\n 2) Delete contact \n");
        printf ("\n 3) Search by name \n");
        printf ("\n 4) Edit contact \n");
        printf ("\n 5) View all contacts \n");
        printf ("\n 6) Sort contacts (A-Z) \n");
        printf ("\n 7) Exit \n");
        scanf ("%d" ,&choice);
        getchar ();

        switch (choice)
        {
        case 1:     //add contact
            printf ("\n Enter contact name : \n");
            fgets(contactName, sizeof(contactName), stdin);
            contactName[strcspn(contactName, "\n")] = 0;
            printf ("\n Enter phone number : \n");
            scanf ("%d" ,&phoneNumber);
            strcpy(contacts[count].name, contactName);
            contacts[count].phone = phoneNumber;
            printf ("\n Contact added ! \n");
            count++;
            break;

        case 2:     //delete contact
            found = 0;
            printf ("\n Enter contact to delete : \n");
            fgets(deleteName, sizeof(deleteName), stdin);
            deleteName[strcspn(deleteName, "\n")] = 0;

            for (int i=0 ; i<count ; i++)
            {
                if (strcmp(contacts[i].name, deleteName) == 0)
                {
                    for (int j=i ; j<count-1 ; j++)
                    {
                        contacts [j] = contacts [j+1];
                    }
                    count--;
                    found = 1;
                    printf ("\n Contact deleted ! \n");
                    break;
                }
            }
            if (!found)
            {
                printf ("\n Contact not found ! \n");
                break;
            }
            break;

        case 3:     //search by name
            found = 0;
            printf("\n Enter name to search : \n");
            fgets(searchName, sizeof(searchName), stdin);
            searchName[strcspn(searchName, "\n")] = 0;


            for (int i = 0; i < count; i++)
            {
                if (strcmp(contacts[i].name, searchName) == 0)
                {
                    printf("\n Found: %s - %d \n", contacts[i].name, contacts[i].phone);
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                printf("\n Contact not found ! \n");
            }
            break;

            case 4:     // edit contact
                found = 0;
                printf("\n Enter name to edit : \n");
                fgets(editName, sizeof(editName), stdin);
                editName[strcspn(editName, "\n")] = 0;
                for (int i = 0; i < count; i++)
                {
                    if (strcmp(contacts[i].name, editName) == 0)
                    {
                        printf("\n Enter new name : \n");
                        fgets(contacts[i].name, sizeof(contacts[i].name), stdin);
                        contacts[i].name[strcspn(contacts[i].name, "\n")] = 0;


                        printf("\n Enter new phone : \n");
                        scanf("%d", &contacts[i].phone);
                        getchar ();

                        found = 1;
                        printf("\n Contact updated ! \n");
                        break;
                    }
                }

                if (!found)
                {
                    printf("\n Contact not found ! \n");
                }
                break;

            case 5:     //view all contacts
                if (count == 0)
                {
                    printf ("\n No contacts found ! \n");
                }
                else
                {
                    printf ("\n ----Contacts list---- \n");
                    for (int i=0 ; i<count ; i++)
                    {
                        printf ("%d) %s -%d \n", i+1 , contacts[i].name , contacts[i].phone);
                    }
                }
                break;

            case 6:     //sort contacts
                for (int i=0 ; i<count ; i++)
                {
                    for (int j=i+1 ; j<count ; j++)
                    {
                        if (strcmp(contacts [i].name, contacts[j].name) > 0)
                            {
                                struct Contact temp = contacts[i];
                                contacts[i] = contacts[j];
                                contacts[j] = temp;
                            }
                    }
                }
                printf("\n Contacts sorted A-Z ! \n");
                break;

            case 7:
                printf ("\n exiting... \n");
                break;
            default:
                printf ("\n Invalid choice ! Please select from 1-7 \n");
        }
    }
    while (choice != 7);
}
