#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player
{
private:
	char name[64];
	int money;
public:
	Player();
	explicit Player(char* name);
	explicit Player(int money);
	Player(char* name, int money);
	inline char* getName() { return name; }
	void setName(char* name);
	inline int getMoney() const { return money; }
	void setMoney(int money);
	void Info() const;
};
#endif