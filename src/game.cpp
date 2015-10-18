#include "machine.h"
#include "player.h"
#include "helper.h"
#include <cstdio>
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Game objects

	Machine machine;
	Player player;
		
	int menuSelected = 0;
	int playerBet = 0;
	char playerName[32] = {'\0'};
	bool exit = false;
	
	//Get name

	showFirstMenu(playerName);
	player.setName(playerName);
	
	//Init 

	machine.setMoney(10000);
	machine.setPlayer(&player);
	
	//Game

	while(machine.getPlayer()->getMoney() > 0)
	{
		system("cls");
		machine.gameInfo();
		
		if(!(menuSelected = showMainMenu()))
			continue;
		
		switch(menuSelected)
		{
		case PLAY:
			machine.play();
			break;
		case BET:
			playerBet = inputBet(machine.getMaxBet());
			machine.setBet(playerBet);
			break;
		case EXIT:
			exit = true;
			break;
		}
		if(exit) break;
	}

	//End game

	system("cls");
	machine.gameInfo();
	printf("\nСпасибо за игру :)\n");
	printf("Ваши деньги: %d\n\n", machine.getPlayer()->getMoney());
	getchar();
	return 0;
}