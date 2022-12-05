#include<iostream>
#include<string>
#include"Player.h"
#include"Enemy.h"
#include"Combat.h"
#include<Windows.h>




int main()
{
	Player member1("NoobProgrammer", 20, 15, 3, 30);
	Enemy bandit("Bandit", 20, 15, 3, 20);
	Combat combat;

	combat.kombat(member1, bandit, combat);
}