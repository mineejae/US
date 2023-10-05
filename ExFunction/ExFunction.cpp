#include <stdio.h>

#include "Sum.h"
#include "Minus.h"
#include "Multi.h"
#include "Divide.h"


//함수 이름 : Sum
//매개 변수(파라메타) : int a, int b
//반환 값 : int
//a와 b를 합한 결과를 반환하시오

//함수 이름 : Multi
//매개 변수(파라메타) : int a, int b
//반환 값 : int
//a와 b를 곱하기한 결과를 반환하시오

//함수 이름 : Divid
//매개 변수(파라메타) : float a, float b
//반환 값 : float
//a와 b를 나누기한 결과를 반환하시오

// 클래스 이름 : CShop
// 맴버 변수 : m_value(기본값:0)
// 맴버 함수 추가 : printValue
// printValue 함수 결과 : "Value=%d"로 m_value 출력

// 클래스 이름 : CPhoneShop
// 부모 클래스 : CShop
// 생성자 파라메타 : int PhoneCnt ( m_PhoneCnt에 값 적용 )
// 생성자 파라메타 : int PhonePrice ( m_PhonePrice에 값 적용 )
// 맴버 변수 : m_PhoneCnt
// 맴버 변수 : m_PhonePrice
// printValue 함수 결과 : "Value=%d"로 m_PhoneCnt * m_PhonePrice출력

//CPhoneShop(10, 100) 생성 후 객체에 printValue 출력

// 클래스 이름 : CFruitShop
// 생성자 파라메타 : int FruitCnt ( m_FruitCnt에 값 적용 )
// 생성자 파라메타 : int FruitPrice ( m_FruitPrice에 값 적용 )
// 부모 클래스 : CShop
// 맴버 변수 : m_FruitCnt
// 맴버 변수 : m_FruitPrice
// printValue 함수 결과 : "Value=%d"로 m_FruitCnt * m_FruitPrice출력

//CFruitShop(10, 100) 생성 후 객체에 printValue 출력


class CShop
{
public:
	int  m_value = 0;

	void printValue()
	{
		printf("Value=%d\n", m_value);
	}
};

class CPhoneShop : public CShop
{
public:
	int m_PhoneCnt;
	int m_PhonePrice;

	CPhoneShop(int PhoneCnt, int PhonePrice) : m_PhoneCnt(PhoneCnt), m_PhonePrice(PhonePrice)
	{

	}

	void printValue()
	{
		printf("Value=%d\n", m_PhoneCnt * m_PhonePrice);
	}
};

class CFruitShop : public CShop
{
public:
	int m_FruitCnt;
	int  m_FruitPrice;

	CFruitShop(int FruitCnt, int FruitPrice) : m_FruitCnt(FruitCnt), m_FruitPrice(FruitPrice)
	{

	}

	void printValue()
	{
		printf("Value=%d\n", m_FruitCnt * m_FruitPrice);
	}

};

void Average(int &sum, int a, int b, int c)
{
	sum = (a + b + c) / 3;
}

int ArraySum(int* arr, int length)
{
	int Num = 0;

	for (int i = 0; i < length; i++)
	{
		Num += arr[i];
	}
	return Num;
}

int main()
{
	//printf로 "Sum=%d"로 Sum함수 결과 출력
	//printf로 "Minus=%d\n"로 Minus함수 결과 출력
	//printf로 "Multi=%d\n"로 Multi함수 결과 출력
	//printf로 "Divid=%d\n"로 Divid함수 결과 출력

	int Sum1 = 5;// 이건 그저 변수일뿐
	int arr[] = { 1, 2, 3 };
	printf("Sum=%d\n", Sum(2, 4));

	printf("Minus=%d\n", Minus(9, 1));

	printf("Multi=%d\n", Multi(1, 9));

	printf("Divide=%f\n", Divide(6, 2));

	Average(Sum1, 1, 3, 6);// void형 함수 호출/ Sum1을 int &Sum에 전달, 1을 int a에 전달, 3을 int b에 전달, 6을 int c에 전달
	printf("AverageSum=%d\n", Sum1); //반환값이 없는 void형 함수이기 때문에 호출을 위해서 따로 빼냄, 'Sum1'에 저장된 값을 불러옴


	printf("ArraySum=%d\n", ArraySum(arr, 3));

	CPhoneShop Phone(10, 100);// Phone은 그냥 이름 class에 대한 이름
	
	CFruitShop Fruit(10, 100);// Fruit도 내가 지은 class에 대한 이름

	Phone.printValue(); // class에 있는 함수를 불러올 땐 위에서붙인 'Phone'이라는 class이름.멤버함수();
	Fruit.printValue();
}