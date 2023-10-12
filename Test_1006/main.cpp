#include <stdio.h>
#include <iostream>

//주민번호 입력 받으면 생년월일이랑 성별 표기 프로그램
// 13월 이상이면 잘못됨
// 32일생 이상이면 잘못됨
// 뒤에 번호 첫째자리가 1, 3 : 남자
// 뒤에 번호 첫째자리가 2, 4 : 여자

//830714-1
// 만약에 잘못된 주민번호라면 "잘못 입력하셨습니다" 출력

//>주민번호 앞에 자리를 입력해주세요 : 830714
//>주민번호 뒤에 첫째자리를 입력해주세요 : 1
//>83년 07월 14일 남자 출력

// 숫자 하나를 입력하세요 : 3
// 숫자 하나를 더 입력하세요 : 30

// 결과
// R = 첫번째 숫자와 두번째 숫자 사이에 숫자를 모두 더한값
// "3과 30사이에 모든 수를 더하면 %d입니다.", R

//함수 이름 : standardWeight
//맴버 변수 : float height
//리턴 값 : float
//공식 : (height - 100) * 0.9
float standardWeight(float height)
{
    return(height - 100) * 0.9;
}

//함수 이름 : GetBMI
//맴버 변수 : float weight, float standardWeight
//리턴 값 : float
//공식 : (weight - standardWeight)  * 100 / standardWeight
float GetBMI(float weight, float standardWeight)
{
    return (weight - standardWeight) * 100 / standardWeight;
}

// 개속 반복, 0 입력시 종료

BMI를 계산하시겠습니까 ? 0)No 1)Yes
몸무게를 입력해주세요 : weight에 값 입력
키를 입력해주세요 : height에 값 입력
bmi에 따른 등급 판정
등급        비만도 수치
10이하        정상
10초과 20이하    과체중
20 초과        비만


int main()
{
   
    bool bRun = true;

    while(bRun)
    {
        printf("BMI를 계산하시겠습니까? 0)No 1)Yes : ");
        int input = 0;
        scantf_s("%d" , &input);

        switch (input)
        {
        case 0:
            bRun = falsse;
            break;

        case 1:
        {
            int weight = 0, height = 0, BMI = 0;
            printf("몸무게를 입력해주세요 : ");
            scanf_s("%d", &weight);
            printf("키를 입력해주세요 : ");
            scanf_s("%d", &height);
            BMI = GetBMI(weight, standardWeight(height));

            if (10 <= BMI){ 
                printf("정상\n"); 
            }
            else if (10 < BMI && BMI <= 20) {
                printf("과체중\n");
            }
            else if (20 > BMI) {
                printf("비만\n");
            }
        }
            break;
        
        default:
            break;
        }

    int a = 0;
    int b = 0;

    printf("\n숫자 하나를 입력하세요:");
    scanf_s("%d", &a);
    printf("\n숫자 하나 더 입력하세요:");
    scanf_s("%d", &b);


    

    int R = 0;

    for (int i = a; i <= b ; i++)
    {
        R = R +i;
    }


    printf("%d와 %d사이의 모든 수를 더하면 %d입니다\n", a, b, R);

    int a = 0;
    int value = 0;
    int per = 0;

    printf("\n소득세를 계산하시겠습니까? 0)No 1)Yes");
    scanf_s("%d", &a);
    if (a == 1)
    {
        printf("\n연간 총 소득을 입력하세요(만원 단위) :");
        scanf_s("%d", &value);

        if (value > 100000)
        {
            per = 45;
        }
        else if (50000 < value)
        {
            per = 42;
        }
        else if (30000 < value)
        {
            per = 40;
        }
        else if (15000 < value)
        {
            per = 38;
        }
        else if (8800 < value)
        {
            per = 35;
        }
        else if (4600 < value)
        {
            per = 24;
        }
        else if (1200 < value)
        {
            per = 15;
        }
        else
        {
            per = 6;
        }
        printf("당신의 소득세는 %d 퍼센트 내세요\n", per);
    }
    else
    {
        return 0;
    }
}

      
}


    
  

   
