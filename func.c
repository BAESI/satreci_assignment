#include "func.h"

Student students[100];
Student students_add[100];
int dataNum = 0;

/*void appandChar(char* char1, char* char2) {
    while(*char1) {
        char1++;
    }
    while(*char2) {
        *char1 = *char2;
        char2++;
        char1++;
    }
    *char1 = '\0';
}*/


int addStudent() {
    char inputName[10];
    int inputStudentNum;
    int inputKor;
    int inputEng;
    int inputMat;
    int inputSoc;
    int inputSci;
    char inputString[100];

    FILE *fp;

    printf("새로운 학생의 정보를 추가합니다.\n");
    printf("학생 이름을 입력하세요: ");
    scanf("%s",inputName);

    printf("학번을 입력하세요: ");
    scanf("%d",&inputStudentNum);
    for (int i = 0; i < dataNum; i++) {
        if ( inputStudentNum == students[i].studentNum ) {
            printf("이미 존재하는 학번입니다. 정보입력을 종료합니다.\n");
            printf("-------------------------------------\n");
            return 0;
        }
    }

    printf("국어점수를 입력해주세요(0 ~ 100): ");
    scanf("%d",&inputKor);
    if (inputKor > 100 || inputKor < 0) {
        printf("잘못된 점수를 입력하였습니다. 정보입력을 종료합니다.\n");
        printf("-------------------------------------\n");
        return 0;
    }

    printf("영어점수를 입력해주세요(0 ~ 100): ");
    scanf("%d",&inputEng);
    if (inputEng > 100 || inputEng < 0) {
        printf("잘못된 점수를 입력하였습니다. 정보입력을 종료합니다.\n");
        printf("-------------------------------------\n");
        return 0;
    }

    printf("수학점수를 입력해주세요(0 ~ 100): ");
    scanf("%d",&inputMat);
    if (inputMat > 100 || inputMat < 0) {
        printf("잘못된 점수를 입력하였습니다. 정보입력을 종료합니다.\n");
        printf("-------------------------------------\n");
        return 0;
    }

    printf("사회점수를 입력해주세요(0 ~ 100): ");
    scanf("%d",&inputSoc);
    if (inputSoc > 100 || inputSoc < 0) {
        printf("잘못된 점수를 입력하였습니다. 정보입력을 종료합니다.\n");
        printf("-------------------------------------\n");
        return 0;
    }

    printf("과학점수를 입력해주세요(0 ~ 100): ");
    scanf("%d",&inputSci);
    if (inputSci > 100 || inputSci < 0) {
        printf("잘못된 점수를 입력하였습니다. 정보입력을 종료합니다.\n");
        printf("-------------------------------------\n");
        return 0;
    }

    char studentNumberToChar[1000];
    char korToChar[100];
    char engToChar[100];
    char matToChar[100];
    char socToChar[100];
    char sciToChar[100];

    sprintf(studentNumberToChar, "%d", inputStudentNum);
    sprintf(korToChar, "%d", inputKor);
    sprintf(engToChar, "%d", inputEng);
    sprintf(matToChar, "%d", inputMat);
    sprintf(socToChar, "%d", inputSoc);
    sprintf(sciToChar, "%d", inputSci);

    fp = fopen("studentlist.txt","a");
    fputs("\n",fp);
    fputs(inputName,fp);
    fputs(",",fp);
    fputs(studentNumberToChar,fp);
    fputs(",",fp);
    fputs(korToChar,fp);
    fputs(",",fp);
    fputs(engToChar,fp);
    fputs(",",fp);
    fputs(matToChar,fp);
    fputs(",",fp);
    fputs(socToChar,fp);
    fputs(",",fp);
    fputs(sciToChar,fp);
    fclose(fp);

    printf("학생 정보 입력을 완료하였습니다.\n");
    printf("-------------------------------------\n");

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

void dataFileInput() {
    char listLine[100];
    FILE *fp;
    fp = fopen("studentlist.txt", "r");

    if (fp == NULL) {
        printf("데이터 파일을 불러오는데 실패하였습니다. 프로그램을 종료합니다.\n");
        exit(0);
    }
    else {
        while(fgets(listLine, 100, fp) != NULL) {
            char *tmp;
            int tempStudentData[6];
            tmp = strtok(listLine, ",");
            //students[dataNum].name = tmp;
            strcpy(students[dataNum].name,tmp);
            for(int i = 0; i < 6; i++) {
                tmp = strtok(NULL, ",");
                tempStudentData[i] = atoi(tmp);
            }
            students[dataNum].studentNum = tempStudentData[0];
            students[dataNum].kor = tempStudentData[1];
            students[dataNum].eng = tempStudentData[2];
            students[dataNum].mat = tempStudentData[3];
            students[dataNum].soc = tempStudentData[4];
            students[dataNum].sci = tempStudentData[5];
            students[dataNum].evg = ((double)students[dataNum].kor + (double)students[dataNum].eng + (double)students[dataNum].mat +
                    (double)students[dataNum].soc + (double)students[dataNum].sci)/5;
            dataNum++;
        }
    }
    fclose(fp);
}