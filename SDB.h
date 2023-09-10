#ifndef SDB_H
#define SDB_H
#include "STD.h"

#define MAX_SIZE 10 // max size of database stack

// DataBase
typedef struct SimpleDb
{
    uint32 Student_ID;
    uint32 Student_year;
    uint32 Course1_ID;
    uint32 Course1_grade;
    uint32 Course2_ID;
    uint32 Course2_grade;
    uint32 Course3_ID;
    uint32 Course3_grade;
} student;

// Function Declaration
Bool SDB_IsFull();
uint8 SDB_GetUsedSize();
Bool SDB_AddEntry();
void SDB_DeleteEntry(uint32 id);
Bool SDB_ReadEntry (uint32 id);
void SDB_GetList(uint8 *count, uint32 *list);
Bool SDB_IsIdExist(uint32 id);

struct SimpleDb database[MAX_SIZE]; // the database array


#endif