#ifndef SATRECI_FUNC_H
#define SATRECI_FUNC_H
#include <stdio.h>

void custom_strcpy(char *str1,char *str2);

int custom_strlen(char *str);

char* custom_strtok(char *str, char* delim);

int custom_atoi(char* cdata);

int dataFileInput();

void printStudentList();

int str_compare(char* str1,char* str2);

int addStudent();

int deleteStudent();

void printSortList();

void selectMenu(int num);

typedef struct student {
    char name[20];
    int studentNum,kor,eng,mat,soc,sci;
    double evg;
}Student;


#endif SATRECI_FUNC_H