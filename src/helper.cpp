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
	printf("\t��������� ������:\n");
	printf("==========================\n");
	printf("������� ���� ���: ");
	gets_s(buffer, 32);
	if(strlen(buffer)) strcpy_s(name, 32, buffer);
}

int showMainMenu()
{
	fflush(stdin);
	int iSelected = 0;
	char* cSelected = new char[8];
	printf("==========================\n");
	printf("\t����:\n");
	printf("==========================\n");
	printf("1. ������\n");
	printf("2. ������\n");
	printf("3. ����\n");
	printf("\n��� �����: ");
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
		printf("������� ������: ");
		gets_s(cBet, 8);
		iBet = atoi(cBet);
	}
	return iBet;
}