#include <stdio.h>
#include "MyClass.h"

struct stMyStruct// ������
{
	int a;
};

//Class(����, �ڷ���)
//Class�� ����� ���� Type�̶�� �Ѵ�.
//C++�� Ŭ������ ������ ������(����) ������(private, protected, public)�� ����
// �׼����� ����Ǵ� ����� ������ �� �Լ��� �ִ� ����� ���� ���� �Ǵ� ������ ������ �����.
// �׼��� �����ڸ� ����Ͽ� ������ �� �Լ��� ����� �� ĸ��ȭ��� �Ѵ�.
// Class�� �ѱ۷� �����ϸ� ��Ʋ�̶�� ��, ��밡���� ��ü�� �ƴ�
// ��ü�� �����ϱ� ���� ����� ��Ÿ����.
 
// ��ü(object)
// Class�� ����ؼ� ������ �� ��ü��� �Ѵ�.
// Class�� ������ �������� �����ǰ� �޸𸮿��� ������ ������

// ��ü ���� ���α׷���
// ��ü ���� ���α׷����� ��ǻ�� ���α׷��� ��ɾ��� ������� ���� �ð����� ��� �������� ������ ����
// ��, "��ü"���� �������� ������ ������� �ϴ� �з�����
// ������ ��ü�� �޽����� �ְ�ް�, �����͸� ���������� ó���� �� �ִ�.

class CMyClass// ������
{
	// ���� ������
	// private: �ܺο��� ���� �Ұ�
	// protected : ��Ӱ����� �� ������ ����, �̿ܿ��� ���� �Ұ�
	// public : ��𼭵� ���� ����
	
	// ���� ���� �����ڰ� ������ �⺻������ private
	int m_b;//Ŭ���� �ȿ� ����� ������ �ɹ� ������� �Ѵ�. (�����ڵ��� ���������� �ɹ�������� �� ǥ���ϱ� �� 'm_'�� ���̱⵵ �Ѵ�.)

public:
	// ������
	// Ŭ������ ������ �� ȣ��Ǵ� �Լ�
	// �������� �ʾƵ� �⺻ �����ڰ� ����
	// �����ڵ� private���� �ܺο� ȣ�� �Ұ�. �ݵ�� public���� �������־� ��.
	// �����ڵ� �Ķ��Ÿ�� ������ Ÿ�Կ� ���� Overload(Ÿ�Ժ� ������ �Լ��� ����)�� �� �ִ�.
	// (int value = 0) �̷� ������� ������ �Ķ��Ÿ�� �־��� �� �ִ�.
	// �Ķ��Ÿ ������ ���°� �Է� ��Ŀ� ���� ������ �Ұ����ϸ� ������ �߻��Ѵ�.
	// :a(valueA), m_b(0), c(0) <- �̷� ������� ������ �ɹ������� �ʱⰪ�� ������ �� �ִ�.
	// �Ķ��Ÿ ������ ���°� �Է� ��Ŀ� ���� ������ �Ұ����ϸ� ������ �߻��Ѵ�.

	CMyClass(int valueA = 0):a(valueA), m_b(0), c(0)
	{
		printf("������A ȣ���\n");
	}

	CMyClass(int valueA, int valueB) :a(valueA), m_b(valueB), c(0)
	{
		printf("������B ȣ���\n");
	}

	CMyClass(int valueA, int valueB, int valueC) :a(valueA), m_b(valueB), c(valueC)
	{
		printf("������C ȣ���\n");
	}

	// �ı���
	// Ŭ������ �ı��ɶ� ȣ��Ǵ� �Լ�
	// �������� �ʾƵ� �⺻ �ı��� ����
	// �ı��ڵ� public�� �ƴϸ� ȣ���� �Ұ���, �ݵ�� public���� ����
	~CMyClass()
	{
		printf("�ı��� ȣ���\n");
	}

	void PrintB()
	{
		printf("B=%d", m_b);
	}

	void PrintAllValue()
	{
		printf("A=%d, B=%dn C=%d\n", a, m_b, c);
	}

	void SetC(int num)
	{
		// �Ϲ������� this Ű����� ������
		// this : Ŭ���� �ȿ� �Լ��� ȣ���� ��� ��ü�� �ǹ���
		this->c = num;
	}

	// ������ �����ε�(Operator Overloading)
	// ���Կ����� (�⺻������ ������)
	// const CMyClass& : �������� ��ȯ�� ������
	// operator = �����ε� �� ������
	// (const CMyClass& other) : �����ʿ� �Էµ� ����
	// const : ������ ���� ���
	// & : ����

	//cMy3 = cMy + cMy2;
	//cMy3 = cMyClass(a + other.a, m_b + other.m_b, c + other.c);
	const CMyClass& operator=(const CMyClass& other) 
	{
		a = other.a;
		m_b = other.m_b;
		c = other.c;

		return *this;
	}

	const CMyClass& operator+(const CMyClass& other)
	{
		return CMyClass(a + other.a, m_b + other.m_b, c + other.c);
	}
public:
	int a;
protected:
private:
	int c;
};



int main()
{
	{

		// ���۷��� ����
		// �޸� ������ ���� �ʰ� ������ �����Ͽ� �޸𸮸� ȿ�������� ����ϱ� ���� ������

		int num = 100;
		stMyStruct stTest;
		
		// ������ ������ ������ ������ �ּҰ��� �����Ѵ�.
		// ������ ������ �ּҰ��� ������ ����Ű�� �ִ� �ּ� ���� �ٸ���.
		int* pNum = &num;// pNum ������ �������� num�� �ּ� ���� ����. ��, pNum�� num������ ����Ű�� �ִ�.
		stMyStruct* pTest = &stTest;
		pTest->a = 0;
		printf("&pNum != &num ? %d\n", (int(&pNum) != int(&num)));

		// ���۷��� ������ ���� ����� �ּҰ��� �����ϴ�.
		int& refNum = num;
		stMyStruct* refTest = &stTest;
		refTest->a = 0;
		printf("&refNum != &num ? %d\n", (int(&refNum) == int(&num)));
	}
	
	int a;

	stMyStruct stMy;
	stMy.a = 0;



	CMyClass cMy(100);//-> ������A ȣ���
	CMyClass cMy2(100, 200);//-> ������B ȣ���
	printf("cMy.a=%d\n", cMy.a);
	cMy.a = 0;
	cMy.SetC(0);// Ư�� ������ �����ϱ� ���� �Լ��� �����ؼ� �����ϴ°� �⺻ ��Ģ�̴�.
	//cMy.c = 100;// ���� ������ private���� �Ǿ��ִٸ� �����ڰ� ���� �������� ����� �ǵ��� �ִٴ� ��

	CMyClass2 aa;

	CMyClass cMy3;
	cMy.a = 1000;
	cMy.PrintAllValue();
	cMy2.PrintAllValue();
	cMy3 = cMy + cMy2;
	cMy3.PrintAllValue();

	cMy = cMy2;
	
	
}//<-�ı��� ȣ���