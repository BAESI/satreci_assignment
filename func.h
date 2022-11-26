#ifndef SATRECI_FUNC_H
#define SATRECI_FUNC_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void selectMenu(int num);

void dataFileInput();

typedef struct student {
    char name[10];
    int studentNum,kor,eng,mat,soc,sci;
    double evg;
}Student;


#endif SATRECI_FUNC_H