#include "../studentMS/func.h"
#include <stdio.h>

int main() {

    //dataFileInput()
    printf("dataFileInput() : ");
    if (dataFileInput() == 0) {
        printf("PASS\n");
    }
    else {
        printf("FAIL\n");
    }

    //custom_strlen(char *str)
    printf("custom_strlen(char *str) : ");
    char testStr1[10] = "1234";
    if (custom_strlen(testStr1) == 4) {
        printf("PASS\n");
    }
    else {
        printf("FAIL\n");
    }

    //char* custom_strtok(char *str, char* delim)
    printf("custom_strtok(char *str, char* delim) : ");
    char testStr2[100] = "THIS IS TEST";
    char* result = custom_strtok(testStr2," ");

    if (str_compare(result,"THIS") == 0) {
        printf("PASS\n");
    }
    else {
        printf("FAIL\n");
    }

    //int custom_atoi(char* cdata);
    printf("custom_atoi(char* cdata) : ");
    char testNum[2] = "10";
    if (custom_atoi(testNum) == 10) {
        printf("PASS\n");
    }
    else {
        printf("FAIL\n");
    }

    //int str_compare(char* str1,char* str2);
    printf("str_compare(char* str1,char* str2) : ");
    char testStr3[5] = "abcde";
    if (str_compare(testStr3,"abcde") == 0) {
        printf("PASS\n");
    }
    else {
        printf("FAIL\n");
    }

    //int addStudent();
    //int deleteStudent();
    //void custom_strcpy(char *str1,char *str2);
    //void printStudentList();
    //void printSortList();
    //void selectMenu(int num);



}