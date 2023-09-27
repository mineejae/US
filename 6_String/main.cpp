#include <stdio.h>
#include <iostream>

unsigned int GetStringLength(const wchar_t* _pString)
{
	int i = 0;

	while (1)
	{
		wchar_t c = *(_pString + i);//���������� �ּҰ��� ���ڸ� ����

		//if(c == 0)
		if (c == '\0')
		{
			break;
		}

		++i;
	}

	return i;

}

// _Dest : "abcde"
// _pSource : "fghi"

void StringCar(wchar_t* _Dest, unsigned int size, const wchar_t* _pSource)
{

}


int main()
{
	// ���� ó��
	// �ƽ�Ű �ڵ� ��ũ : https://namu.wiki/w/%EC%95%84%EC%8A%A4%ED%82%A4%20%EC%BD%94%EB%93%9C
	// multi-byte
	// 127�� �ƽ�Ű �ڵ� ���� ǥ��, ���ڿ� ���� ���������� ũ�Ⱑ �����
	// �������� ȣȯ�� ���� �ʴ� ������� �ٸ� �ý������� ������ ���ڸ� �˾ƺ��� ���� ����
	// �Ϻ��� �ؽ�Ʈ ������ �ѱ� �����쿡�� ������ �� ���� ������ ������ ����
	// ö���� �ڱ��� ǥ�⸸�� ���� ���ڵ�. �ܱ��� ���� ���� �ٸ� ����ü�谡 �ʿ��� ��� ������
	char c1 = '97';//1Byte(0~255), �ѱ����� ���� ' '���
	printf("c1=%d\n", c1);// �ѱ��� char ��½� %c ���
	char arrC1[10] = "abc�ѱ�";//����� 1Byte, �ѱ��� 2Byte ���, ���ڿ��� ���� " " ���
	printf("arrC1%s\n", arrC1);// ���ڿ� char ��½� %s ���

	// ���̵� ����(wide character)
	// multi-byte�� ������ �ذ��ϱ� ���� ���� �����ڵ� ���
	// ������ ���� ��� ���ڸ� ǥ���� �� �ֱ� ������ �ֱٿ� ���� ����
	// ���� ���� ����ϴ� ����� UTF-8�� �ִ�.
	//2Byte(0~65535)���� �տ� ������ 1bit�� �����ϸ� 32,767�� ǥ������
	// wchar_t���� ���ڸ� ���� ��, �տ� L�� ���δ�.

	wchar_t wc1 = L'a';
	wprintf(L"wc1=%c\n", wc1);// wchar_t���� ����� ���� wprintf�� ���, ��� ���ڿ� �տ� L�� ���δ�.
	
	_wsetlocale(LC_ALL, L"korean"); //���̵� ���� ��� ����
	
	wchar_t arrWC1[10] = L"abc�ѱ�"; // wchar_t�迭�� ���ڿ��� ���� �� �տ� L�� ���δ�.
	wprintf(L"arrWC1=%s\n", arrWC1); // wchar_t���� ����� ���� wprintf�� ���, ��� ���ڿ� �տ� L�� ���δ�

	wchar_t szWChar[10] = L"abcdefghi"; // �������� ���ڿ� �������̶�� ǥ��� '\0'���ڰ� ����. (10���� ���߷��� j �ϳ��� ����� ��)
	wprintf(L"aszWChar=%s\n", szWChar);
	
	wchar_t szWCharLen[20] = L"abcdefg"; // ���ڿ� ���� ���ϱ�(iostream ���̺귯�� �Լ�)
	int size = wcslen(szWCharLen); // ���ڿ� ���� ���ϱ�
	printf("szWCharLen size=%d\n", size);

	wcscat_s(szWCharLen, 20, L"hij"); // ���ڿ� ���̱�(iostream ���̺귯�� �Լ�)
	wprintf(L"szWCharLen=%s\n", szWCharLen);
	

}