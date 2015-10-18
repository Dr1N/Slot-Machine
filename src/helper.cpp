#include "machine.h"
#include "player.h"
#include <cstdlib>
#include <cstdio>
#include <cstring>

void showFirstMenu(char* name)
{
	fflush(stdin);
	char buffer[32];
	printf("==========================\n");
	printf("\tОднорукий бандит:\n");
	printf("==========================\n");
	printf("Введите ваше имя: ");
	gets_s(buffer, 32);
	if(strlen(buffer)) strcpy_s(name, 32, buffer);
}

int showMainMenu()
{
	fflush(stdin);
	int iSelected = 0;
	char* cSelected = new char[8];
	printf("==========================\n");
	printf("\tМеню:\n");
	printf("==========================\n");
	printf("1. Играть\n");
	printf("2. Ставка\n");
	printf("3. Уйти\n");
	printf("\nВаш выбор: ");
	gets_s(cSelected, 8);
	iSelected = atoi(cSelected);
	delete[] cSelected;
	return iSelected;
}

int inputBet(int max)
{
	char *cBet = new char[8];
	int iBet = 0;

	while(!iBet || iBet > max || iBet < 0)
	{
		fflush(stdin);
		fflush(stdout);
		printf("Введите ставку: ");
		gets_s(cBet, 8);
		iBet = atoi(cBet);
	}
	return iBet;
}