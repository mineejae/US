#include <stdio.h>
#include <iostream>

// x64일 경우 클래스 크기 8/16/24/32 순으로 8Byte 간격으로 할당
// RTTI 공간 할당 8Byte + 4Byte = 12Byte
// 12Byte 담을 수 있는 최소한의 공간은 16Byte
class CBase
{
public:

	// 가상 함수
	// virtual 키워드를 함수 앞에 붙인다.
	// 자식 클래스에서 함수를 override를 해서 재구현 가능
	// 가상 함수가 되면 RTTI정보를 가리키는 포인터 변수 공간 8Byte(x64 기준) 할당
	// RTTI 포인터는 해당 클래스에 정보를 가리키게 됨
	// dynamic_cast시 클래스의 크기를 참조하는게 아니라 추가로 할당된 RTTI 포인터에 클래스의 정보를 참조
	virtual void printX()
	{
		printf("X=%d", m_X);
	}
	int m_X = 10;
};

class CChild1 : public CBase
{
public:
	void printY()
	{
		printf("Y=%d", m_Y);
	}
	int m_Y = 20;
};

class CChild2 : public CBase
{
public:
	void printZ()
	{
		printf("Z=%d", m_Z);
	}
	int m_Z = 20;
};

int main()
{
	// RTTI(Run Time Type Information/Identification)
	int64_t i64 = sizeof(CBase);
	printf("CBase Size=%I64d\n", i64);// sizeof : 객체에 크기 반환 가능
	printf("CChild1 Size=%I64d\n", sizeof(CChild1));// sizeof : 객체에 크기 반환 기능

	int64_t* pB = (int64_t*)new CBase;
	int64_t* pC = (int64_t*)new CChild1;
	printf("pB[0]=%I64d, pB[1]=%d", pB[0], (int)pB[1]);
	printf("pC[0]=%I64d, pC[1]=%d, pC[2]=%d", pC[0], (int)pC[1], (int)pC[2]);
	delete pB;
	delete pC;

	CBase* pBase[] = { new CChild1, new CChild2 };

	for (CBase* pTemp : pBase)
	{
		pTemp->printX();

		// dynamic_cast
		// <CChild*> 캐스팅(형변환)할 클래스 타입
		// (pTemp) : 캐스팅(형변환)할 객체
		// CChild1* pChild : 형변환 결과 반환값(캐스팅 성공시 캐스팅된 객체 반환, 캐스팅 실패시 nullptr 반환)
		CChild1* pChild = dynamic_cast<CChild1*>(pTemp);
		if (pChild == nullptr)
			continue;

		pChild->printY();
	}

	for (CBase* pTemp : pBase)
	{
		delete pTemp;
	}
}
