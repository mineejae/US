#include "money.h"
#include <stdio.h>

static int s_money = 0;// �� s_money�� �ؿ� s_money�� �ٸ���

extern int g_money; //������ ����� �� �ƴ϶� ������ ���� ���̶�� �̸� �˷��ִ� ��

int addMoney(int money)
{
	int t_money = 0;//���� ����
	t_money += money;
	g_money += money;

	printf("t_money=%d\n", t_money);
	printf("g_money=%d\n", g_money);
	return 0;

}

int useMoney(int money)
{
	return 0;
}
