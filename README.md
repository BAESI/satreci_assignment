# 쎄트렉아이 우주9팀 코딩과제

성적 관리 프로그램 제작

|  분야  |      내용     |
| ----- | ------------ |
| 개발환경 | Macbook pro 14 |
|  Used |  <img src="https://img.shields.io/badge/C-A8B9CC?style=flat-square&logo=C&logoColor=white"/> <img src="https://img.shields.io/badge/CMake-064F8C?style=flat-square&logo=CMake&logoColor=white"/> <img src="https://img.shields.io/badge/CLion-000000?style=flat-square&logo=CLion&logoColor=white"/>|

## 주요 기능
* 학생 정보 등록
* 학생 정보 삭제
* 학생 목록 출력
  * 이름순 출력
  * 학번순 출력
  * 평균순 출력

## 테스팅
별도의 테스팅 프레임워크를 사용하지 않았습니다. <br>CMakeLists.txt 파일에 Testing execution code 아래에 주석처리된 코드를 주석을 풀고 상단의 프로그램 실행 코드를 주석처리하고 빌드하면 테스팅이 진행됩니다. 테스팅 결과 custom_atoi 함수가 때때로 정상으로 작동안함을 확인했습니다.<br><br>
<img width="485" alt="스크린샷 2022-12-02 오후 4 13 38" src="https://user-images.githubusercontent.com/28686402/205237755-143466d8-6f60-452b-bba6-e8534c929694.png">

## 실행 방법
현재 cmake-build-debug 디렉토리안에 studentlist.txt 파일안에 기본데이터가 저장되어 있는 상태입니다.<br> 
프로그램을 실행시키기 위해 CMakeLists.txt 파일에서 Testing execution code 아래의 코드가 주석처리 되어 있는지 확인 후 cmake-bulid-debug 디렉토리에서 ./satrci 명령어를 통해 프로그램을 실행할 수 있습니다.<br>

![image](https://user-images.githubusercontent.com/28686402/204726626-b3abf779-b86e-4604-a666-52a7c46007b0.png)
