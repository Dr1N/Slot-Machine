#include "player.h"
#include <cstring>
#include <cstdio>

Player::Player() : money(1000)
{
	strcpy_s(name, "Unnamed");
}

Player::Player(char* n) : money(1000)
{
	n ? strcpy_s(name, n) : strcpy_s(name, "Unnamed");
}

Player::Player(int m) : money(1000)
{
	strcpy_s(name, "Unnamed");
	if(m > 0 && m <= 5000000)
		money = m;
}

Player::Player(char* n, int m) : money(1000)
{
	if(m > 0 && m <= 5000000)
	{
		money = m;
	}
	n ? strcpy_s(name, n) : strcpy_s(name, "Unnamed");
}

void Player::setName(char* n)
{
	if(strlen(n))
	{
		strcpy_s(name, n);
	}
}

void Player::setMoney(int m)
{
	if(m >= 0 && m <= 5000000)
		money = m;
}

void Player::Info() const
{
	printf("-----Игрок-----\n");
	printf("Имя:\t%s\n", name);
	printf("Деньги:\t%d\n", money);
}