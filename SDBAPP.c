#include <stdio.h>
#include "STD.h"
#include "SDB.h"

uint8 num = 1;   // global variable for the while loop
void SDB_action(uint8 choice)
{
    switch(choice) // checks on the input given and calls the function accordingly
    {
        case 0: num = 0; break; // case exit // num=0 is used for the while loop
                                // if the num became 0, exit command is executed
        case 1: SDB_AddEntry(); break; // case add entry
        case 2: 
        {
            printf("Used size: %d \n" ,SDB_GetUsedSize()); 
            break;
        }
        case 3: // case read entry
        {
            uint32 id;
            printf("Enter an ID: ");
            scanf("%d",&id); // taking input the id to read data
            printf("%d \n", SDB_ReadEntry (id));
            break;
        }
        case 4: // case gets the ID to the list
        {
            uint8 count;
            uint32 list[10];
            uint8 size = SDB_GetUsedSize();
            SDB_GetList(&count, list);
            for(int i=0; i<=size; i++) // dispays the IDs from the database from list
            {
                printf("list[%d] = %d \n",i,list[i]);
            }
            break;
        }
        case 5: // case cheking the id exists or not
        {
            uint32 id;
            printf("Enter an ID: ");
            scanf("%d",&id);
            if(SDB_IsIdExist(id)==0) // if 0 does not exist
            {
                printf("The ID is not Found! \n");
            }
            else
            {
                printf("The ID exists! \n");
            }
            break;
        }
        case 6: // case delete entry
        {
            uint32 id;
            printf("Enter an ID: ");
            scanf("%d",&id);  // taking input the ID to delete the entry
            SDB_DeleteEntry(id);
            break;
        }
        case 7: // case checks if the database is full or not
        {
            if(SDB_IsFull()==0)
            {
                printf("The Database is NOT FULL! \n");
            }
            else
            {
                printf("The Database is FULL! \n");
            }
            break;
        }
        default: printf("Enter a Valid Choice: \n");break;
    }
}

void SDB_APP() // method for continously taking input and sending it to SDB_action
{
    while(num) // loop used for repeating the operation as long as 0 
    {           // or a num greater than 7 is entered
        uint8 operation;
        printf("\n");                   // operation menu
        printf("To add entry--------------------------------------> 1 \n"); 
        printf("To get used size in database----------------------> 2 \n");
        printf("To read student data------------------------------> 3 \n");
        printf("To get the list of all student IDs----------------> 4 \n");
        printf("To check if ID exists-----------------------------> 5 \n");
        printf("To delete student data----------------------------> 6 \n");
        printf("To check is database is full----------------------> 7 \n");
        printf("To exit-------------------------------------------> 0 \n");
        scanf("%d",&operation); // taking the input operation
        SDB_action(operation); // calling the method to execute the specified function
    }
}

