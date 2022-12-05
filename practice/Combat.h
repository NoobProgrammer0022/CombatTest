#pragma once

#include<ctime>
#include<cstdlib>
#include<Windows.h>


class Combat
{
private:
	int randomNumGen(int);                     // random num generator protected from outside use.
public:
	int attack(int);
	int defence(int);
	int speed(int);
	void displayMenu();
	int decision();
	void kombat(Player, Enemy, Combat);
};

int Combat::randomNumGen(int maxRange)   // this function will accept the stat the player or enemy has as the maxvalue to generate a number for attack/defence/speed
{
	unsigned seed = 0;
	seed = time(0);							// gets the seed from time function
	srand(seed);

	int randomNum = 0;

	randomNum = 1 + rand() % maxRange;
	return randomNum;
}

int Combat::attack(int attackValue)
{
	int damage = 0;
	damage = randomNumGen(attackValue);  
	return damage;
}

int Combat::defence(int defenceValue)
{
	int block = 0;
	block = randomNumGen(defenceValue);   
	return block;
}

int Combat::speed(int speedValue)				// not used at this time when used it will determine who attacks first. 
{
	int speed = 0;
	speed = randomNumGen(speedValue);
	return speed;
}

void Combat::displayMenu()
{
	std::cout << " 1. Attack " << std::endl;
	std::cout << " 2. defend " << std::endl;
}

int Combat::decision()								// this gets the decision from user and also protects from bad input
{
	std::cout << " Action? ";
	int choice = 0;
	std::cin >> choice;
	while (choice < 1 || choice > 2)
	{
		std::cout << " Invalid option. " << std::endl;
		std::cout << " Action? ";
		std::cin >> choice;
	}
	return choice;
}

void Combat::kombat(Player member1, Enemy enemy, Combat combat)
{
	int plyrattack = 0, enemattack = 0, plyrDef = 0, enemdef = 0, plyrhealth = 0, enemHealth = 0;
	while (member1.getHealth() > 0 && enemy.getHealth() > 0)
	{
		std::cout << "Name: " << member1.getName() << " Health: " << member1.getHealth() << std::endl << std::endl;
		std::cout << "Name: " << enemy.getName() << " Health: " << enemy.getHealth() << std::endl << std::endl;
		displayMenu();

		plyrhealth = member1.getHealth();
		enemHealth = enemy.getHealth();

		if (decision() == 1)
		{
			std::cout << member1.getName() << " is attacking..... " << std::endl;
			Sleep(1000);
			plyrattack = combat.attack(member1.getAttack());

			std::cout << enemy.getName() << " is defending..... " << std::endl;
			Sleep(1000);
			enemdef = combat.defence(enemy.getDefence());
			(plyrattack - enemdef) < 0 ? plyrattack = 0, enemdef = 0 : plyrattack += 0;         // prevents negative numbers from adding to health
			enemy.setHealth(enemHealth - (plyrattack - enemdef));


			std::cout << enemy.getName() << " is attacking. " << std::endl;
			Sleep(1000);
			enemattack = combat.attack(enemy.getAttack());

			std::cout << member1.getName() << " is defending..... " << std::endl;
			Sleep(1000);
			plyrDef = combat.defence(member1.getDefence());
			(enemattack - plyrDef) < 0 ? enemattack = 0, plyrDef = 0 : enemattack += 0;       // prevents negative numbers from adding to health
			member1.setHealth(plyrhealth - (enemattack - plyrDef));

		}
		/* defend option is not done yet. My intention here is I will make a seperate function that will randomly generate either attack or defend for the enemy. later there will be skills and
		items the ai and the player can use. this is barebones at this time I just wanted to get the attack working for now so ignore everything in the else section here. dont choose option 2 
		at this time. */
		else
		{

		}
		system("cls");
	}

	//******************************************************************************DISPLAYS WHO WINS****************************************************************************************
	if (member1.getHealth() > enemy.getHealth())
	{
		if(member1.getHealth() > 0)
		std::cout << member1.getName() << " Wins! with " << member1.getHealth() << " health left" << std::endl;
	}

	if (enemy.getHealth() > member1.getHealth())
	{
		if (enemy.getHealth() > 0)
			std::cout << enemy.getName() << " Wins! with " << enemy.getHealth() << " health left" << std::endl;
	}
	if (member1.getHealth() <= 0 && enemy.getHealth() <= 0)
	{
		std::cout << " Both players died lol!" << std::endl;
		std::cout << member1.getName() << " Had " << member1.getHealth() << " Health left" << std::endl;
		std::cout << enemy.getName() << " Had " << enemy.getHealth() << " Health left" << std::endl;

	}
	//****************************************************************************************************************************************************************************************
}