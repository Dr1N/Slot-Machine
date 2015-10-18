#include "machine.h"
#include <cstdio>
#include <ctime>
#include <Windows.h>

Machine::Machine() : n_roll(3), money(1000), 
	maxBet(100), minBet(10), result(BEGIN), rolls(0), bet(10), player(0)
{
	rolls = new Roll[n_roll];
}

Machine::Machine(int r) : n_roll(3), money(1000), 
	maxBet(100), minBet(10), result(BEGIN), rolls(0), bet(10), player(0)
{
	if(r >= 3 && r <= 6) 
		n_roll = r;
	rolls = new Roll[n_roll];
}

Machine::Machine(int r, int m) : n_roll(3), money(1000), 
	maxBet(100), minBet(10), result(BEGIN), rolls(0), bet(10), player(0)
{
	if(r >= 3 && r <= 6) 
		n_roll = r;
	if(m > 0 && m <= 5000000)
		money = m;
	rolls = new Roll[n_roll];
}

Machine::~Machine()
{
	if(rolls) 
		delete[] rolls;
}

void Machine::setRolls(int r)
{
	if(r >= 3 && r <= 6) 
		n_roll = r;
}

void Machine::setMoney(int m)
{
	if(m > 0 && m <= 5000000)
		money = m;
}

void Machine::setBet(int b)
{
	if(b <= 0) 
		bet = minBet;
	else if(b >= maxBet)
		bet = maxBet;
	else
		bet = b;
}

void Machine::setMaxBet(int b)
{
	b <= money ? maxBet = b : maxBet = money;
}

void Machine::setMinBet(int b)
{
	b >= 0 || b < maxBet ? minBet = b : minBet = 10;
}

void Machine::setPlayer(Player *p)
{
	if(p) player = p;
}

void Machine::moveRolls()
{	
	srand((int)time(NULL));
	for(int i = 0; i < n_roll; i++)
		rolls[i].rotate();
}

void Machine::drawPoints(int pause) const
{
	printf("Points:");
	for(int i = 0; i < n_roll; i++)
	{
		Sleep(pause);
		printf("\tRoll %d:\t%d\n", i + 1, rolls[i].getPoint());
	}
}

void Machine::Info() const
{
	printf("-----Machine-----\n");
	printf("Rolls:\t%d\n", n_roll);
	printf("Money:\t%d\n", money);
	printf("Bet:\t%d\n\n", bet);
	drawPoints();
}

void Machine::gameInfo() const
{
	printf("==========================\n");
	printf("\t����:\n");
	printf("==========================\n");
	printf("��� ������:\t%s\n",player->getName());
	printf("������:\t\t%d\n",player->getMoney());
	printf("������:\t\t%d\n",bet);
	printf("���� ���:\t%d\n\n",money);
	printf("==========================\n");
	drawPoints();
	printf("���������: ");
	switch(result)
	{
	case BEGIN:
		printf("�������(�)\n");
		break;
	case LOSE:
		printf("�� ���������\n");
		break;
	case WIN:
		printf("�� ��������\n");
		break;
	case JACKPOT:
		printf("�������!\n");
		break;
	}
}

bool Machine::play()
{
	if(money > 0 && player->getMoney() > 0 && money >= bet && player->getMoney() >= bet)
	{
		moveRolls();
		
		//Result

		for(int i = 1; i < n_roll; i++)
		{
			if(rolls[0].getPoint() != rolls[i].getPoint())
			{
				result = LOSE;
				break;
			}
		}
		if(result == WIN && rolls[0].getPoint() == 7)
		{
			result = JACKPOT;
		}
		
		switch(result)
		{
		case LOSE:
			printf("�� ���������\n");
			money += bet;
			player->setMoney(player->getMoney() - bet); 
			break;
		case WIN:
			printf("�� ��������\n");
			if(money >= 5 * bet)
			{
				money -= 5 * bet;
				player->setMoney(player->getMoney() + 5 * bet);
			}
			else
			{
				player->setMoney(player->getMoney() + money);
				money = 0;
				return false;
			}
			break;
		case JACKPOT:
			printf("!!!JACKPOT!!!\n");
			player->setMoney(player->getMoney() + money);
			money = 0;
			return false;
		}
	}
	return false;
}