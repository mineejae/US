#include "money.h"
#include <stdio.h>

static int s_money = 0;// 이 s_money와 밑에 s_money는 다른애

extern int g_money; //변수를 만드는 게 아니라 변수가 나올 것이라고 미리 알려주는 것

int addMoney(int money)
{
	int t_money = 0;//지역 변수
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
