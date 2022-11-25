#include "func.h"

void addStudent() {

}

void deleteStudent() {

}

void printSortList() {

}

void selectMenu(int num) {
    switch (num) {
        case 1: {
            addStudent();
            break;
        }
        case 2: {
            deleteStudent();
            break;
        }
        case 3: {
            printSortList();
            break;
        }
        default: {
            printf("잘못된 번호를 입력하였습니다.");
        }
    }
}