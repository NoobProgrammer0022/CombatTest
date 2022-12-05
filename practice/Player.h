#pragma once

#include<string>

class Player
{
private:
	std::string name;
	int health;
	int attack;
	int defence;
	int speed;

public:
	Player();
	Player(std:: string, int, int, int, int);
	void setName(std::string);
	void setHealth(int);
	void setAttack(int);
	void setDefence(int);
	void setSpeed(int);
	std::string getName();
	int  getHealth();
	int  getAttack();
	int  getDefence();
	int  getSpeed();
	
};

Player::Player()    // default constructor if I ever get all these values that means I did not pass the values that needed to be passed using the other constructor
{
	name = " ";
	health = 0;
	attack = 0;
	defence = 0;
	speed = 0;

}


Player::Player(std::string n,int h, int a, int d, int s)
{
	name = n;
	health = h;
	attack = a;					// each letter in parameter list is the first letter of the stat they go to. 
	defence = d;				// ex h stands for health // a stands for attack // d stands for defense // s stands for speed // n stands for name
	speed = s;

}

void Player::setName(std::string n)
{
	name = n;
}

void Player::setHealth(int h)
{
	health = h;
}

void Player::setAttack(int a)
{
	attack = a;
}

void Player::setDefence(int d)
{
	defence = d;
}

void Player::setSpeed(int s)
{
	speed = s;
}

std::string Player::getName()
{
	return name;
}

int Player::getHealth()
{
	return health;
}

int Player::getAttack()
{
	return attack;
}

int Player::getDefence()
{
	return defence;
}

int Player::getSpeed()
{
	return speed;
}