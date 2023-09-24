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
unsigned int CalculatorMinus(int x, int y)
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
unsigned int CalculatorDivide(int x, int y)
{
	return x / y;
}

// 나머지 함수 만들기
// CalculatorRemain
unsigned int CalculatorRemain(int x, int y)
{
	return x % y;
}

void CallFunction()
{
	printf("함수 호출됐다!\n");
}

int main()
{
	CallFunction();
	unsigned int nResult = 0;
	nResult = CalculatorSum(1, 1);
	printf("CalculatorSum 실행 결과 = %d\n", nResult);
	nResult = CalculatorMinus(1, 1);
	printf("CalculatorMinus 실행 결과 = %d\n", nResult);
	nResult = CalculatorMultiply(1, 1);
	printf("CalculatorMultiply 실행 결과 = %d\n", nResult);
	nResult = CalculatorDivide(1, 1);
	printf("CalculatorDivide 실행 결과 = %d\n", nResult);
	nResult = CalculatorRemain(1, 1);
	printf("CalculatorRemain 실행 결과 = %d\n", nResult);

}