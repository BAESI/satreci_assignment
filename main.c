#include "func.h"

int main(int argc, char *argv[]) {

    dataFileInput();
    printf("성적 관리 프로그램을 시작합니다.\n");
    while(1) {
        int num;
        printf("1.성적입력 2.성적삭제 3.정렬출력 0.종료\n");
        printf("원하는 기능의 번호를 입력해주세요: ");
        scanf("%d", &num);
        if (num == 0) {
            printf("프로그램을 종료합니다.");
            break;
        }
        selectMenu(num);
    }
    return 0;
}
