#include <stdio.h>
#include "Calc01234.h"



int main()
{
	bool bRun = true;
	while (bRun)
	{ 
		int nInput = 0;
		int num1, num2;

		printf("� ������ �Ͻðڽ��ϱ�?(0:���ϱ�, 1:����, 2:���ϱ�, 3:������, 4:������):");
		scanf_s("%d", &nInput);
		switch (nInput)
		{
		case 0:
		{
			printf("���� 2���� �Է��ϼ���(num1 mum2);");
			scanf_s("%d %d", &num1, &num2);
			printf("�μ��� ���� %d�Դϴ�.\n", Sum(num1, num2));
		}
		break;

		case 1:
		{
			printf("���� 2���� �Է��ϼ���(num1 mum2);");
			scanf_s("%d %d", &num1, &num2);
			printf("�μ��� ���� %d�Դϴ�.\n", Minus(num1, num2));
		}
		break;

		case 2:
		{
			printf("���� 2���� �Է��ϼ���(num1 mum2);");
			scanf_s("%d %d", &num1, &num2);
			printf("�μ��� ���� %d�Դϴ�.\n", Multifly(num1, num2));
		}
		break;

		case 3:
		{
			printf("���� 2���� �Է��ϼ���(num1 mum2);");
			scanf_s("%d %d", &num1, &num2);
			printf("�μ��� �������� %f�Դϴ�.\n", Divide(num1, num2));
		}
		break;

		case 4:
		{
			printf("���� 2���� �Է��ϼ���(num1 mum2);");
			scanf_s("%d %d", &num1, &num2);
			printf("�μ��� ������ �������� %d�Դϴ�.\n", Remain(num1, num2));
		}
		break;

		default:
			break;
		}


	

		printf("���⸦ �����Ͻðڽ��ϱ�?(0:No 1:Yes):");
		scanf_s("%d", &nInput);

		switch (nInput)
		{case 1:
			bRun = false;
			break;
		}
	}
	//bool bRun = true;
	//while (bRun)
	//{
	//	int num1, num2;

	//}

	return 0;
}