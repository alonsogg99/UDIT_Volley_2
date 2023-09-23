#pragma once
class Player
{
private:
	short x = 0, y = 0;
	char id = 0;
	char name[42] = "";
public:
	Player();
	void Move();
	void Jump();
};

