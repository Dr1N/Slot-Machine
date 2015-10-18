#ifndef _ROLL_H_
#define _ROLL_H_

class Roll
{
private:
	short point;
public:
	Roll() : point(0) {}
	explicit Roll(short p);
	inline short getPoint() const { return point; }
	void setPoint(short p);
	short rotate();
};
#endif