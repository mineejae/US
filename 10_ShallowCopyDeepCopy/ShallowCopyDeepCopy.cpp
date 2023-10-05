#include <stdio.h>
#include <iostream>

class CName
{
public:
	CName(const wchar_t* name):szName(nullptr), len(0) // : 왼쪽이 초기화하는 방법
	{
		len = wcslen(name) + 1;// wcslen은 문자열 길이를 구하는 것 wchar_t의
		szName = new wchar_t[len];
		wcscpy_s(szName, len, name);
	}
	// 복사 생성자 및 복사 할당 연산자(C++)
	// 파라메타로 (const CName& Other)와 같이 자산의 클래스 타입을 레퍼런스로 받으면 복사 생성자
	CName(const CName& Other) : szName(nullptr), len(0)
	{
		if (szName != nullptr)
		{
			delete[] szName;
		}

		//Other.szName을 복사해서 szName에 넣는다.(깊은 복사)
		len = wcslen(Other.szName) + 1;
		szName = new wchar_t[len];
		wcscpy_s(szName, len, Other.szName);
	}

	~CName()
	{
		delete[] szName;//대괄호는 array배열 제거
	}

	wchar_t* GetName()
	{
		return szName;
	}

	const CName& operator=(const CName& Other)
	{

		//szName = Other.szName;//Other.szName이 가리키고 있는 곳을 szName도 가리키게 하겠다.(얕은 복사)
		//len = Other.len;

		if (szName != nullptr)
		{
			delete[] szName;
		}

		len = wcslen(Other.szName) + 1;
		szName = new wchar_t[len];
		wcscpy_s(szName, len, Other.szName);
		return *this;
	}
	wchar_t* szName;
	size_t len;
};

int main()
{
	_wsetlocale(LC_ALL, L"Korean");

	CName name1(L"희재");
	CName name2(L"히재");
	wprintf(L"name1=%s", name1.GetName());
	
	name1 = name2;//대입 연산자 처리

	CName name3 = name1;

	wprintf(L"name1=%s", name1.GetName());

}