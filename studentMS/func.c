#include "func.h"

Student students[3000];
int dataNum = 0;

void custom_strcpy(char *str1,char *str2) {
    while (*str2 != '\0') {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';

}

int custom_strlen(char *str) {
    int cnt = 0;
    while(str[cnt] != '\0') {
        ++cnt;
    }
    return cnt;
}

char* custom_strtok(char *str, char* delim) {
    char* sStr;
    static char* tstr;
    int i;

    if (str != NULL) {
        sStr = str;
    }
    else {
        sStr = tstr;
    }
    if (custom_strlen(sStr) < 1 ) {
        return NULL;
    }
    for (i = 0; i < custom_strlen(sStr); i++) {
        if (sStr[i] == (*delim) || sStr[i] == '\0') {
            sStr[i] = '\0';
            break;
        }
    }
    tstr=&sStr[i+1];
    return sStr;
}

int custom_atoi(char* cdata) {
    int sign = 1;
    int data = 0;

    if (*cdata == '\n') {
        return 0;
    }
    if (*cdata == '-') {
        sign = -1;
    }
    while (*cdata) {
        if (*cdata >= '0' && *cdata <= '9') {
            data = data * 10 + *cdata - '0';
        }
        cdata++;
    }
    return data * sign;
}

void printStudentList() {
    printf("이름    학번     국어     영어     수학     사회     과학     평균\n");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < dataNum; i++) {
        printf("%s    %d      %d      %d      %d      %d     %d     %.2f\n",students[i].name,students[i].studentNum,
               students[i].kor,students[i].eng,students[i].mat,students[i].soc,students[i].sci,students[i].avg);
    }
    printf("---------------------------------------------------------\n");
}

int str_compare(char* str1,char* str2) {
    while (*str1 != '\0' || *str2 != '\0') {
        if (*str1 > *str2) {
            return 1;
        }
        else if (*str1 < *str2) {
            return -1;
        }
        else {
            str1++;
            str2++;
        }
    }
    return 0;
}

int addStudent() {
    char inputName[10];
    int inputStudentNum;
    int inputKor;
    int inputEng;
    int inputMat;
    int inputSoc;
    int inputSci;

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

    char buffer[100];

    fp = fopen("studentlist.txt","a");
    fputs("\n",fp);
    fputs(inputName,fp);
    fputs(",",fp);
    sprintf(buffer, "%d", inputStudentNum);
    fputs(buffer,fp);
    fputs(",",fp);
    sprintf(buffer, "%d", inputKor);
    fputs(buffer,fp);
    fputs(",",fp);
    sprintf(buffer, "%d", inputEng);
    fputs(buffer,fp);
    fputs(",",fp);
    sprintf(buffer, "%d", inputMat);
    fputs(buffer,fp);
    fputs(",",fp);
    sprintf(buffer, "%d", inputSoc);
    fputs(buffer,fp);
    fputs(",",fp);
    sprintf(buffer, "%d", inputSci);
    fputs(buffer,fp);
    fclose(fp);

    printf("학생 정보 입력을 완료하였습니다.\n");
    printf("-------------------------------------\n");

    dataNum = 0;
    dataFileInput();
}

int deleteStudent() {

    int deleteStudentNum;
    int status = 0;

    printf("등록된 학생 정보를 삭제합니다.\n");
    printf("삭제할 학생의 학번을 입력해주세요: ");
    scanf("%d",&deleteStudentNum);

    // 해당 학생을 탐색
    for (int i = 0; i < dataNum; i++) {
        if (students[i].studentNum == deleteStudentNum) {
            for (int j = i; j < dataNum; j++) {
                    students[j] = students[j+1];
            }
            status = 1;
            dataNum--;
        }
    }
    if (status == 0) {
        printf("해당 학생이 존재하지 않습니다.\n");
        printf("-------------------------------------\n");
    }
    else {
        FILE *fp;
        char buffer[100];

        fp = fopen("studentlist.txt","w");

        for (int i = 0; i < dataNum; i++) {
            fputs(students[i].name, fp);
            fputs(",", fp);
            sprintf(buffer, "%d", students[i].studentNum);
            fputs(buffer, fp);
            fputs(",", fp);
            sprintf(buffer, "%d", students[i].kor);
            fputs(buffer, fp);
            fputs(",", fp);
            sprintf(buffer, "%d", students[i].eng);
            fputs(buffer, fp);
            fputs(",", fp);
            sprintf(buffer, "%d", students[i].mat);
            fputs(buffer, fp);
            fputs(",", fp);
            sprintf(buffer, "%d", students[i].soc);
            fputs(buffer, fp);
            fputs(",", fp);
            sprintf(buffer, "%d", students[i].sci);
            fputs(buffer, fp);
            if (i != dataNum-1) {
                fputs("\n", fp);
            }
        }
        fclose(fp);
        printf("해당 학생의 정보를 삭제하였습니다.\n");
        printf("-------------------------------------\n");
    }
}

void printSortList() {
    Student temp;
    int num;

    printf("학생정보를 출력합니다.\n");
    printf("1.이름순 2.학번순 3.평균순 0.종료\n");
    printf("원하는 정렬방식의 번호를 입력해주세요: ");
    scanf("%d",&num);

    switch (num) {
        case 1: {
            printf("이름순정렬\n");
            for (int i = 0; i<dataNum-1; i++) {
                for (int j = i+1; j < dataNum; j++ ) {
                    if (str_compare(students[i].name,students[j].name) > 0) {
                        temp = students[i];
                        students[i] = students[j];
                        students[j] = temp;
                    }
                }
            }
            break;
        }
        case 2: {
            printf("학번순정렬\n");
            for (int i = 0; i<dataNum-1; i++) {
                for (int j = i+1; j < dataNum; j++ ) {
                    if ( students[i].studentNum > students[j].studentNum) {
                        temp = students[i];
                        students[i] = students[j];
                        students[j] = temp;
                    }
                }
            }
            break;
        }
        case 3: {
            printf("평균순정렬\n");
            for (int i = 0; i<dataNum-1; i++) {
                for (int j = i+1; j < dataNum; j++ ) {
                    if ( students[i].avg < students[j].avg) {
                        temp = students[i];
                        students[i] = students[j];
                        students[j] = temp;
                    }
                }
            }
            break;
        }
    }
    printStudentList();
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

int dataFileInput() {

    char listLine[100];
    FILE *fp;
    fp = fopen("studentlist.txt", "r");

    if (fp == NULL) {
        printf("데이터 파일을 불러오는데 실패하였습니다. 프로그램을 종료합니다.\n");
        return 1;
    }
    else {
        while(fgets(listLine, 100, fp) != NULL) {
            char *tmp;
            int tempStudentData[6];
            tmp = custom_strtok(listLine, ",");
            //students[dataNum].name = tmp;
            custom_strcpy(students[dataNum].name,tmp);
            for(int i = 0; i < 6; i++) {
                tmp = custom_strtok(NULL, ",");
                tempStudentData[i] = custom_atoi(tmp);
            }
            students[dataNum].studentNum = tempStudentData[0];
            students[dataNum].kor = tempStudentData[1];
            students[dataNum].eng = tempStudentData[2];
            students[dataNum].mat = tempStudentData[3];
            students[dataNum].soc = tempStudentData[4];
            students[dataNum].sci = tempStudentData[5];
            students[dataNum].avg = ((double)students[dataNum].kor + (double)students[dataNum].eng + (double)students[dataNum].mat +
                    (double)students[dataNum].soc + (double)students[dataNum].sci)/5;
            dataNum++;
        }
    }
    fclose(fp);
    return 0;
}