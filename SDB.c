#include "STD.h"
#include "SDB.h"
#include <stdio.h>

int32 top = -1; // indicates the top of the database

Bool SDB_IsFull() // checks is the database is full or not
{
    if(top == MAX_SIZE-1) 
    {
        return truee;
    }
    else 
    {
        return falsee;
    }
}

uint8 SDB_GetUsedSize() // returns the used size of the database
{
    return (top+1);
}

Bool SDB_AddEntry() // adding an entry to the array
{
    if(SDB_IsFull()) // check if the database is full or not first
    {
        printf("Database is Full! \n");
        return falsee;
    }
    uint32 ID; // temp variables for the scanf function
    uint32 year;
    uint32 C1_ID;
    uint32 C1_grade;
    uint32 C2_ID;
    uint32 C2_grade;
    uint32 C3_ID;
    uint32 C3_grade;
    printf("Enter Student Id: "); 
    scanf("%d",&ID);                     // taking the data as input from console
    printf("Enter Student Year: ");
    scanf("%d",&year);
    printf("Enter Course 1 ID: ");
    scanf("%d",&C1_ID);
    printf("Enter Course 1 Grade: ");
    scanf("%d",&C1_grade);
    printf("Enter Course 2 ID: ");
    scanf("%d",&C2_ID);
    printf("Enter Course 2 Grade: ");
    scanf("%d",&C2_grade);
    printf("Enter Course 3 ID: ");
    scanf("%d",&C3_ID);
    printf("Enter Course 3 Grade: ");
    scanf("%d",&C3_grade);

    if(C1_grade > 100 || C1_grade < 0 || C2_grade > 100 || C2_grade < 0 ||
                                                        C3_grade > 100 || C3_grade < 0)
    {
        printf("Incorrect Data! \n");   // checking if the data is correct or not
        return falsee;
    }
    else
    {
        top++;                               // increase top as max
        database[top].Student_ID = ID;          // adding the data into the database
        database[top].Student_year = year;
        database[top].Course1_ID = C1_ID;
        database[top].Course1_grade = C1_grade;
        database[top].Course2_ID = C2_ID;
        database[top].Course2_grade = C2_grade;
        database[top].Course3_ID = C3_ID;
        database[top].Course3_grade = C3_grade;

        printf("Data Added Successfuly \n");
        return truee;
    }
}

void SDB_DeleteEntry(uint32 id)  // deletes an entry from the database
{
    int position;
    int i;
    if(top==-1)  // checks if the database is empty or not
    {
        printf("The database is empty! \n");
    }
    else if(SDB_IsIdExist(id) == 0) // checks if the ID exists or not
    {
        printf("The ID wasn't found! \n");
    }
    for(i = 0; i <= top; i++)  // delete operation, finds first the ID, then 
    {                           // copies the elements one step back
        if(database[i].Student_ID == id)
        {
            for(int j = i; j<top ; j++)
            {
                database[j] = database[j+1];
            }
            top--;
            printf("The ID is deleted successfully \n");
        }
    }
}

Bool SDB_ReadEntry (uint32 id) // display's the data of a certain ID
{
    for(int i = 0; i<=top ; i++)
    {
        if(database[i].Student_ID == id)
        {
            printf("Student ID: %d \n", database[i].Student_ID);
            printf("Student Year: %d \n", database[i].Student_year);
            printf("Course 1 ID: %d \n", database[i].Course1_ID);
            printf("Course 1 Grade: %d \n", database[i].Course1_grade);
            printf("Course 2 ID: %d \n",database[i].Course2_ID);
            printf("Course 2 Grade: %d \n", database[i].Course2_grade);
            printf("Course 3 ID: %d \n",database[i].Course3_ID);
            printf("Course 3 Grade: %d \n", database[i].Course3_grade);
            return truee;
        }
    }
    printf("ID not found!");
    return falsee;
}

void SDB_GetList(uint8 *count, uint32 *list) // copies the IDs of all students in database
{                                             // into list and stores their count
    *count=top+1;
    for(int i=0;i<=top;i++)
    {
        list[i]=database[i].Student_ID;
    }
    printf("List is obtained successfully! \n");
}

Bool SDB_IsIdExist(uint32 id) // checks if the ID exists in the database or not
{
    for(int i = 0; i<=top ; i++)
    {
        if(database[i].Student_ID == id)
        {
            return truee;
        }
    }
    return falsee;
}