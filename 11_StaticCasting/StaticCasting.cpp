#include <iostream>


class CBase
{
public:
	int a = 1;
};

class CChild1 : public CBase
{
public:
	void printB()
	{
		printf("Child1::printB=%f\n", b);
	}

	float b = 3.14;//4byte
};

class CChild2 : public CBase
{
public:
	void printB()
	{
		printf("Child2::printC=%d\n", c);
	}

	float c = 3;//4byte
};


int main()
{
	CBase* pBase = new CChild1;
	// pBase->printB(); // CBase* 포인트로 캐스팅(읽어온다) 하기 때문에 printB에 접근 불가능

	// 기본 캐스팅 방법
	// 강제로 CBase* 포인터에 메모리를 CChild1 클래스 메모리 틀에 맞춰 읽어온다.
	CChild1* pChild1 = (CChild1*)pBase;
	pChild1->printB();
	// 아래와 같이 포인트를 잘못 가리키는 실수를 할 경우 문제가 발생할 수 있다.
	// 강제로 int* 포인터에 메모리를 CChild*에 맞추면
	// 서로 맞지 않아 문제가 차후 발생할 수 있는데 문제 없이 컴파일이 됨
	// 차후에 문제 발생시 어디서 문제가 발생했는지 찾기 어려움

	int* a = new int(0);
	pChild1 = (CChild1*)a;

	// static_cast : 정적 캐스팅 (컴파일 단계에서 변환)
	// 강제 int* 포인터에 메모리를 CChild*에 맞추려고 하면 컴파일 불가
	// pChild1 = static_cast<CChild1*>(a);
	// 에러 "잘못된 형식 변환입니다."
	
	pChild1 = static_cast<CChild1*>(pBase);
	pChild1->printB();

	// static_casts는 부모의 형태만 확인, 컴파일 단계에서 실행되므로 어떤 형태가 들어오는지 알 수 없음
	// 자식이 다르면 확인하지 않기 때문에 에러X, 컴파일 문제X, 정상적으로 빌드됨
	// 어디서 문제가 발생했는지 찾기 어려움
	// static_cast시에는 반드시 캐스팅하는 대상의 형태를 확인해야함
	CBase* pBase2 = new CChild1;
	CChild2* pChild2 = static_cast<CChild2*>(pBase2);
	pChild2->printB();

	// float을 int형으로 강제로 메모리를 읽어서 출력해서 3.14f의 int 형태의 값 출력
	float fvalue = 3.14f;
	int* pl = (int*)&fvalue;
	printf("pl=%d", *pl);

	delete pBase;
	delete a;
	delete pBase2;
	
}