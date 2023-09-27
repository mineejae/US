#include <stdio.h>

void BuyItem(int* Money, int price)
{
	// int* Money�� �޸� ������ �Ͼ�� �ʴ´�.
	// �޸𸮿� ȿ������ ����, ������ ������ ���ϴ�.
	*Money -= price;
}

enum ePhoneType
{
	iPhone = 0,
	Galaxys23,
	GalaxyFold,
	GalaxyZ
};

struct stPhoneShop
{
	int iPhoneCnt;
	int Galaxys23;
	int GalaxyFold;
	int GalaxyZ;

	void printPhoneCnt()
	{
		printf("iPhone=%d, Galaxy23=%d, GalaxyFold=%d, GalaxyZ=%d\n",
			iPhoneCnt, Galaxys23, GalaxyFold, GalaxyZ);
	}
};

void BuyPhone(int phoneType, stPhoneShop* pPS)
{
	switch (phoneType)
	{
	case ePhoneType::iPhone: 
		pPS->iPhoneCnt--;//����Ʈ�� �����ϴ� ����ü�� ������ "->"Ű����� �����Ѵ�.
		break;
	case  ePhoneType::Galaxys23:
		pPS->Galaxys23--;//����Ʈ�� �����ϴ� ����ü�� ������ "->"Ű����� �����Ѵ�.
		break;
	case ePhoneType::GalaxyFold:
		pPS->GalaxyFold--;//����Ʈ�� �����ϴ� ����ü�� ������ "->"Ű����� �����Ѵ�.
		break;
	case ePhoneType::GalaxyZ:
		pPS->GalaxyZ--;//����Ʈ�� �����ϴ� ����ü�� ������ "->"Ű����� �����Ѵ�.
		break;

	default:
		break;
	}
}

//Number �޾Ƽ� ȭ�鿡 ����Ѵ�.
void printNumber(const int* number)
{
	//number = nullptr;// ������ �ּ� ���� ������ �� �ִ�.
	//*number = 2;
	printf("print number=%d", *number);
}

void printNumber2(const int* number)
{
	//number = nullptr;
	//number = 4;
	printf("print number=%d", *number);
}

void printPhoneShop(const stPhoneShop* ps)
{
	printf("print iPhoneCnt=%d\n", ps->iPhoneCnt);
}

void printPhoneShop(const stPhoneShop& ps)
{
	printf("print iPhoneCnt=%d\n", ps.iPhoneCnt);
}

int main()
{
	int a = 0;
	int b = 0;
	//�����͸� ����ϴ� ����
	// �޸𸮿� ȿ������ ����, ������ ������ ���ϴ�.
	// int* pA : ������ ������ ����(pA�� ���ִ� �ּҿ� int���� ũ�⸸ŭ �����ϰڴ�)
	// nullptr : ������ ������ �ʱ�ȭ ��(�ּҰ��� �������)
	// �������� NULL�� ����ߴµ� NULL = 0�� �ǹ� �׷��� 0�̶� �ǹ̰� �����ؼ� ���� �߻�
	// �ּҰ��� ��������̶�� ��Ȯ�� �ǹ̸� ���� nullptr ���
	// �����Ϳ� ũ��(x32���� 4Byte, x64���� 8Byte)
	int* pA = nullptr;
	pA = &a;//a�ּҰ��� pA�� �ִ´�.
	//* : ���۷�Ʈ �����Ѵ�.(�ּҰ� ����Ű�� �ִ� ���� �����Ѵ�.)
	b = *pA;  //b�� pA�� ����Ű�� �ִ� �ּҿ� ���� �ִ´�.
	*pA = a; // pA = &a; == *pA = a;
	//	10;  //pA�� ����Ű�� �ִ� �ּҿ� ���� 10���� �����Ѵ�.

	//-----------------------------------------------------------------------------------//
	
	int num1 = 0;
	int num2 = 0;
	int* pNum = nullptr;
	pNum = &num1;   //pNum�� num1�� �ּҰ��� �ִ´�.(pNum�� num1�� ����Ű�� �ִ� ����)
	printf("pNum=%d\n", *pNum);// num1�� ���� 0
	*pNum = 20;     //pNum�� ����Ű�� �ִ� num1�� 20�� �ִ´�.
	printf("pNum=%d\n", *pNum); // num1�� ���� 20
	pNum = &num2;   //pNum�� num2�� �ּҰ��� �ִ´�. (pNum�� num2�� ����Ű�� �ִ� ����)
	printf("pNum=%d\n", *pNum); // num2�� ���� 0
	*pNum = 30;     //pNum�� ����Ű�� �ִ� num2�� 30�� �ִ´�.
	printf("pNum=%d\n", *pNum); // num2�� ����30
	printf("num1=%d num2=%d\n", num1, num2);

	//-----------------------------------------------------------------------------------//
	int Money = 10000;

	BuyItem(&Money, 1000);
	printf("MyMoney+%d\n", Money);

	stPhoneShop stPS;
	stPS.iPhoneCnt = 100;
	stPS.Galaxys23 = 100;
	stPS.GalaxyFold = 100;
	stPS.GalaxyZ = 100;

	BuyPhone(ePhoneType::Galaxys23, &stPS);
	stPS.printPhoneCnt();

	//-----------------------------------------------------------------------------------//
	// �迭�� ������

	int arrlnt[10] = { 0,10,20,30,40,50,60,70,80,90 };
	int* plnt = nullptr;
	plnt = arrlnt;
	printf("plnt=%d\n", *plnt);
	plnt += 1; // �迭�����Ϳ����� 1�� ���Ѱ� +1�� �ƴ϶� �迭�����Ϳ� �ּҸ� ����Ų��.
	printf("plnt=%d\n", *plnt);

	short arrS[10] = { 0,10,20,30,40,50,60,70,80,90 };// short�� 2byte
	plnt = (int*)arrS;//(int*)�� ����ؼ�int*�� ������ ����ȯ(Cast)�Ѵ�.
	plnt += 1;//plnt�� int*�̹Ƿ� int(4Byte)��ŭ ���� �ּ� ���� �����Ѵ�.
	short* pS = (short*)plnt;//int(4Byte)��ŭ �̵��� �ּ� ���� Short(2Byte) 2�� �̵��� ��
	printf("pS=%d\n", *pS);

	// x32 ��Ű���� = x86 ��Ű����
	// int32(4Byte) = 0 ~ 4,294,967,295(Byte)

	// �Ʒ� �迭�� ���� ������� ���
	int arr[10] = { 10, 2, 78, 53, 6, 33, 27, 99, 7, 31 };
	

	for (int i = 0; i < 10; i++) // for( ; ; )�ʱ� ���� �����ϸ� �ݺ�, ��ó��
	{
		for (int j = i+1; j < 10; j++)
		{
			if(arr[i] > arr[j])
			{ 
			int Num = arr[i];// num�� ������� ������ ��!
			arr[i] = arr[j];
			arr[j] = Num;
			}
		}
	}
		
	for (int value : arr) //for each -> for(���ʴ�� �ҷ��� �迭��:�迭), value�� ���� �����ϴ� �̸����� ����Ʈ �ȿ��� �����ϰ�
	{
		printf("%d ", value);
	}


	//const ���ȭ ���� ���� ���ϰ� �ϴ� ���
	//�Ǽ��� ���� �� �־ ����� Ƚ���� ���� �� �ִ�.(����� : ���׸� ã�ų� �����ϴ� ��� ����)
	const int cint = 100;//���

	int value = 0;
	int value2 = 0;
	int*pValue = &value;
	//const int* pValue = &value;// �����Ͱ� ����Ű�� ���� ���� �Ұ�, ������ �� ���� ����, ���� ����
	//int const* pValue = &value;// �����Ͱ� ����Ű�� ���� ���� �Ұ�, ������ �� ���� ����, ���� ����
	//int* const pValue = &value;// �����Ͱ� ����Ű�� ���� ���� ����, ������ �� ���� �Ұ�, ���� ����
	//const int* const pValue = &value;// �����Ͱ� ����Ű�� ���� ���� �Ұ�, ������ �� ���� �Ұ�, ���� ����
	//int const* const pValue = &value;// �����Ͱ� ����Ű�� ���� ���� �Ұ�, ������ �� ���� �Ұ�, ���� ����

	*pValue = 2;
	pValue = &value2;
	printf("pValue=%d\n", *pValue);

	printNumber(&value);
	printNumber2(&value);
}