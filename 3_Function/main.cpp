#include <stdio.h>

// �Լ���
// unsinged int : ��ȯ �ڷ���<-Output
// CalculatorSum : �Լ� �̸�(�Ķ��Ÿ)
unsigned int CalculatorSum(int x, int y)
{//->�Լ� ����
	return x + y;//<-��ȯ �� ���� ó��
	printf("�Լ� �����ߴ�.\n");
	

	printf("�Լ� ������.\n");
}//->�Լ� ��

// ���� �Լ� �����
// CalculatorMinus
int CalculatorMinus(int x, int y)
{
	return x - y;

}

// ���ϱ� �Լ� �����
// CalculatorMultiply
unsigned int CalculatorMultiply(int x, int y)
{
	return x * y;
}

// ������ �Լ� �����
// CalculatorDivide
float CalculatorDivide(float x, float y)
{
	return x / y;
}

// ������ �Լ� �����
// CalculatorRemain
float CalculatorRemain(int x, int y)
{
	return x % y;
}

//Factorial �Լ�
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
//int Factorial2(int Num); �������� �ݺ�ó�� �������� Num�� �ִ´� ex) 10->Num
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

int ReFactorial(int Num) //����Լ�
{
	if (Num == 1)
	{
		return 1;
	}

	return Num * ReFactorial(Num - 1); //����Ǵ°� �ƴ϶� �����Լ��� �� ȣ���
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
	printf("�Լ� ȣ��ƴ�!\n");
}

//1~n���� �� ���ϴ� �Լ�
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

int main() // �����ϱ� ���� �ڵ���� �� �� �ʿ� ���� �����ڵ常 �ּ�ó��
{
	//CallFunction();
	//unsigned int nResult = 0;
	//nResult = CalculatorSum(1, 1);
	//printf("CalculatorSum ���� ��� = %d\n", nResult);
	//nResult = CalculatorMinus(1, 1);
	//printf("CalculatorMinus ���� ��� = %d\n", nResult);
	//nResult = CalculatorMultiply(1, 1);
	//printf("CalculatorMultiply ���� ��� = %d\n", nResult);
	//nResult = CalculatorDivide(1, 1);
	//printf("CalculatorDivide ���� ��� = %d\n", nResult);
	//nResult = CalculatorRemain(10, 4);
	//printf("CalculatorRemain ���� ��� = %d\n", nResult);


	// �ݺ���
	//// for��
	//for (/*�ʱ� ����*/int i = 0;/*�ݺ� ���� üũ*/i < 10;/*�ݺ� �� ó��*/++i)
	//{// <-�ݺ� ó���� �ڵ� ����

	//	printf("%d Hello\n", i);
	//}// <-�ݺ� ó���� �ڵ� ��

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
	// 5 Factorial ���ض�
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
	//	printf("break ������\n");
	//	break;//�� ��ɾ ������ while ��� �����Ѵ�. �Ʒ� �ڵ� ����ȵ�
	//	printf("break ������\n");
	//}

	////while��
	////<- �� ���ǽ��� true�� �Ʒ� ���� �ȿ� �ڵ带 �����Ѵ�.
	////<- �� ���ǽ��� false��while���� �����ϰ� ���� �ڵ带 �����Ѵ�.
	//while (i<= 10/*���ǽ�*/)
	//{// <-�ݺ� ó���� �ڵ� ����
	//	nResult *= i;
	//	i++;
	//}// <-�ݺ� ó���� �ڵ� ����
	//printf("while Factorial = %d", nResult);

	//0~Num ¦���� ���ϱ�
	//int i = 0, Num = 10;
	//int nResult = 0;
	//while (i <= Num)
	//{
	//	i++;
	//	if (i % 2 != 0)
	//		continue; //���� �ڵ带 �������� �ʰ� while �ڵ带 ��� ����
	//	
	//	nResult += i;
	//	
	//}
	//printf("0~Num\nEvenSum=%d", nResult);

	// ���� �ڵ� for������ ����ÿ�

	int Num = 10;
	int nResult = 0;

	//for (int i = 0; i <= Num; i++) ¦���� ���� ��
	//{
	//
	//	if (i % 2 != 0) //Ȧ���� ��
	//	{
	//		continue; //���� �ڵ带 �������� �ʰ� while �ڵ带 ��� ����
	//	}
	//		
	//	nResult += i;

	//}
	//printf("0~Num\nEvenSum=%d", nResult);

	for (int i = 0; i <= Num; i++) //Ȧ���� ���� ��
	{

		if (i % 2 == 0) //¦���� ��
		{
			continue; //���� �ڵ带 �������� �ʰ� while �ڵ带 ��� ����
		}

		nResult += i;

	}
	printf("0~Num\nEvenSum=%d", nResult);

	AAA();
	
}