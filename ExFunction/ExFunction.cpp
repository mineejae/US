#include <stdio.h>

#include "Sum.h"
#include "Minus.h"
#include "Multi.h"
#include "Divide.h"


//�Լ� �̸� : Sum
//�Ű� ����(�Ķ��Ÿ) : int a, int b
//��ȯ �� : int
//a�� b�� ���� ����� ��ȯ�Ͻÿ�

//�Լ� �̸� : Multi
//�Ű� ����(�Ķ��Ÿ) : int a, int b
//��ȯ �� : int
//a�� b�� ���ϱ��� ����� ��ȯ�Ͻÿ�

//�Լ� �̸� : Divid
//�Ű� ����(�Ķ��Ÿ) : float a, float b
//��ȯ �� : float
//a�� b�� �������� ����� ��ȯ�Ͻÿ�

// Ŭ���� �̸� : CShop
// �ɹ� ���� : m_value(�⺻��:0)
// �ɹ� �Լ� �߰� : printValue
// printValue �Լ� ��� : "Value=%d"�� m_value ���

// Ŭ���� �̸� : CPhoneShop
// �θ� Ŭ���� : CShop
// ������ �Ķ��Ÿ : int PhoneCnt ( m_PhoneCnt�� �� ���� )
// ������ �Ķ��Ÿ : int PhonePrice ( m_PhonePrice�� �� ���� )
// �ɹ� ���� : m_PhoneCnt
// �ɹ� ���� : m_PhonePrice
// printValue �Լ� ��� : "Value=%d"�� m_PhoneCnt * m_PhonePrice���

//CPhoneShop(10, 100) ���� �� ��ü�� printValue ���

// Ŭ���� �̸� : CFruitShop
// ������ �Ķ��Ÿ : int FruitCnt ( m_FruitCnt�� �� ���� )
// ������ �Ķ��Ÿ : int FruitPrice ( m_FruitPrice�� �� ���� )
// �θ� Ŭ���� : CShop
// �ɹ� ���� : m_FruitCnt
// �ɹ� ���� : m_FruitPrice
// printValue �Լ� ��� : "Value=%d"�� m_FruitCnt * m_FruitPrice���

//CFruitShop(10, 100) ���� �� ��ü�� printValue ���


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
	//printf�� "Sum=%d"�� Sum�Լ� ��� ���
	//printf�� "Minus=%d\n"�� Minus�Լ� ��� ���
	//printf�� "Multi=%d\n"�� Multi�Լ� ��� ���
	//printf�� "Divid=%d\n"�� Divid�Լ� ��� ���

	int Sum1 = 5;// �̰� ���� �����ϻ�
	int arr[] = { 1, 2, 3 };
	printf("Sum=%d\n", Sum(2, 4));

	printf("Minus=%d\n", Minus(9, 1));

	printf("Multi=%d\n", Multi(1, 9));

	printf("Divide=%f\n", Divide(6, 2));

	Average(Sum1, 1, 3, 6);// void�� �Լ� ȣ��/ Sum1�� int &Sum�� ����, 1�� int a�� ����, 3�� int b�� ����, 6�� int c�� ����
	printf("AverageSum=%d\n", Sum1); //��ȯ���� ���� void�� �Լ��̱� ������ ȣ���� ���ؼ� ���� ����, 'Sum1'�� ����� ���� �ҷ���


	printf("ArraySum=%d\n", ArraySum(arr, 3));

	CPhoneShop Phone(10, 100);// Phone�� �׳� �̸� class�� ���� �̸�
	
	CFruitShop Fruit(10, 100);// Fruit�� ���� ���� class�� ���� �̸�

	Phone.printValue(); // class�� �ִ� �Լ��� �ҷ��� �� ���������� 'Phone'�̶�� class�̸�.����Լ�();
	Fruit.printValue();
}