#include <stdio.h>

// 함수형
// unsinged int : 반환 자료형<-Output
// CalculatorSum : 함수 이름(파라메타)
unsigned int CalculatorSum(int x, int y)
{//->함수 시작
	return x + y;//<-반환 및 종료 처리
	printf("함수 시작했다.\n");
	

	printf("함수 끝났다.\n");
}//->함수 끝

// 빼기 함수 만들기
// CalculatorMinus
int CalculatorMinus(int x, int y)
{
	return x - y;

}

// 곱하기 함수 만들기
// CalculatorMultiply
unsigned int CalculatorMultiply(int x, int y)
{
	return x * y;
}

// 나누기 함수 만들기
// CalculatorDivide
float CalculatorDivide(float x, float y)
{
	return x / y;
}

// 나머지 함수 만들기
// CalculatorRemain
float CalculatorRemain(int x, int y)
{
	return x % y;
}

//Factorial 함수
//int Factorial(int Num)
//{
//	int FacResult = 1;
//	for (int i = Num;i > 0; --i)
//	{
//		FacResult *= i;
//	}
//
//	return FacResult;
//}
//int Factorial2(int Num); 포문에서 반복처리 범위값을 Num에 넣는다 ex) 10->Num
//{
//	int FacResult = 1;
//	for (int i = 1; i <= Num; ++i)
//	{
//		FacResult *= i;
//	}
//
//	return FacResult;
//}

//int FacResult = 1;
//
//for (int i = 1;i < 10;++i)
//{
//	FacResult *= i;
//
//}
//printf("FacResult = %d", FacResult);

int ReFactorial(int Num) //재기함수
{
	if (Num == 1)
	{
		return 1;
	}

	return Num * ReFactorial(Num - 1); //종료되는게 아니라 리팩함수가 또 호출됨
}

int AAA()
{
	while (1)
	{
		printf("1st While! Start\n");
		break;
		printf("1st While! End\n");
	}

	while (1)
	{
		printf("2nd While! Start\n");
		break;
		printf("2nd While! End\n");
	}

	while (1)
	{
		printf("3rd While! Start\n");
		break;
		printf("3rd While! End\n");
	}

	return 0;
}

void CallFunction()
{
	printf("함수 호출됐다!\n");
}

//1~n까지 합 구하는 함수
//int SumToN(int Num)

int SumToN(int Num)
{
int SumResult = 1;
for (int i = 1; i <= Num; ++i)
{
	SumResult += i;
}
return SumResult;
}

int main() // 실행하기 싫은 코드들을 다 할 필요 없이 메인코드만 주석처리
{
	//CallFunction();
	//unsigned int nResult = 0;
	//nResult = CalculatorSum(1, 1);
	//printf("CalculatorSum 실행 결과 = %d\n", nResult);
	//nResult = CalculatorMinus(1, 1);
	//printf("CalculatorMinus 실행 결과 = %d\n", nResult);
	//nResult = CalculatorMultiply(1, 1);
	//printf("CalculatorMultiply 실행 결과 = %d\n", nResult);
	//nResult = CalculatorDivide(1, 1);
	//printf("CalculatorDivide 실행 결과 = %d\n", nResult);
	//nResult = CalculatorRemain(10, 4);
	//printf("CalculatorRemain 실행 결과 = %d\n", nResult);


	// 반복문
	//// for문
	//for (/*초기 설정*/int i = 0;/*반복 조건 체크*/i < 10;/*반복 후 처리*/++i)
	//{// <-반복 처리할 코드 시작

	//	printf("%d Hello\n", i);
	//}// <-반복 처리할 코드 끝

	////for (int i = 0;i < 10;++i)
	////{
	////	printf("Hello\n");
	////}
	//int a = 0;
	//for (; a < 5; ++a)
	//{
	//	printf("Hello\n");
	//}

	//for (int b = 0   ;    b < 10   ;    b = b + 2 ) // b+=2
	//{
	//	printf("HelloB\n");
	//}

	//Factorial
	// 5 Factorial 구해라
	// 5 * 4 * 3 * 2 * 1 = 15;

	/*printf("Factorial FacResult = %d\n", Factorial(5));
	printf("Factorial2 FacResult = %d\n", Factorial2(5));
	printf("ReFactorial FacResult = %d\n", ReFactorial(5));*/

	//int nResult = 1;
	//int i = 1;

	//while (true)
	//{
	//	printf("i=%d\n", i); 
	//	i++;
	//	printf("break 실행전\n");
	//	break;//이 명령어를 만나면 while 즉시 종료한다. 아래 코드 실행안됨
	//	printf("break 실행후\n");
	//}

	////while문
	////<- 이 조건식이 true면 아래 가로 안에 코드를 실행한다.
	////<- 이 조건식이 false면while문을 종료하고 다음 코드를 실행한다.
	//while (i<= 10/*조건식*/)
	//{// <-반복 처리할 코드 시작
	//	nResult *= i;
	//	i++;
	//}// <-반복 처리할 코드 종료
	//printf("while Factorial = %d", nResult);

	//0~Num 짝수만 더하기
	//int i = 0, Num = 10;
	//int nResult = 0;
	//while (i <= Num)
	//{
	//	i++;
	//	if (i % 2 != 0)
	//		continue; //다음 코드를 실행하지 않고 while 코드를 계속 실행
	//	
	//	nResult += i;
	//	
	//}
	//printf("0~Num\nEvenSum=%d", nResult);

	// 위에 코드 for문으로 만드시오

	int Num = 10;
	int nResult = 0;

	//for (int i = 0; i <= Num; i++) 짝수만 더할 때
	//{
	//
	//	if (i % 2 != 0) //홀수일 때
	//	{
	//		continue; //다음 코드를 실행하지 않고 while 코드를 계속 실행
	//	}
	//		
	//	nResult += i;

	//}
	//printf("0~Num\nEvenSum=%d", nResult);

	for (int i = 0; i <= Num; i++) //홀수만 더할 때
	{

		if (i % 2 == 0) //짝수일 때
		{
			continue; //다음 코드를 실행하지 않고 while 코드를 계속 실행
		}

		nResult += i;

	}
	printf("0~Num\nEvenSum=%d", nResult);

	AAA();
	
}