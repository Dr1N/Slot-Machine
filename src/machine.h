#include "roll.h"
#include "player.h"

#ifndef _MACHINE_H_
#define _MACHINE_H_

enum RESULT {BEGIN = -1, LOSE, WIN, JACKPOT};

class Machine
{
private:
	int n_roll;
	int money;
	int bet;
	int maxBet;
	int minBet;
	RESULT result;
	Roll *rolls;
	Player *player;

public:
	Machine();
	explicit Machine(int size);
	Machine(int size, int money);
	~Machine();
	
	int getRolls() const { return n_roll; }
	void setRolls(int rolls);

	inline int getMoney() const { return money; }
	void setMoney(int money);
	
	inline int getBet() const { return bet; }
	void setBet(int bet);
	
	inline int getMaxBet() const { return maxBet; }
	void setMaxBet(int maxBet);

	inline int getMinBet() const { return minBet; }
	void setMinBet(int minBet);

	inline Player* getPlayer() const { return player; }
	void setPlayer (Player *player);

	void moveRolls();
	void drawPoints(int pause = 0) const;
	void Info() const;
	void gameInfo() const;

	bool play();
};
#endif