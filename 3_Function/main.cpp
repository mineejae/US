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
unsigned int CalculatorMinus(int x, int y)
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
unsigned int CalculatorDivide(int x, int y)
{
	return x / y;
}

// ������ �Լ� �����
// CalculatorRemain
unsigned int CalculatorRemain(int x, int y)
{
	return x % y;
}

void CallFunction()
{
	printf("�Լ� ȣ��ƴ�!\n");
}

int main()
{
	CallFunction();
	unsigned int nResult = 0;
	nResult = CalculatorSum(1, 1);
	printf("CalculatorSum ���� ��� = %d\n", nResult);
	nResult = CalculatorMinus(1, 1);
	printf("CalculatorMinus ���� ��� = %d\n", nResult);
	nResult = CalculatorMultiply(1, 1);
	printf("CalculatorMultiply ���� ��� = %d\n", nResult);
	nResult = CalculatorDivide(1, 1);
	printf("CalculatorDivide ���� ��� = %d\n", nResult);
	nResult = CalculatorRemain(1, 1);
	printf("CalculatorRemain ���� ��� = %d\n", nResult);

}