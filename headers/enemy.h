#ifndef ENEMY_H
#define ENEMY_H

#include <entity.h>
#include <player.h>

class Enemy: public Entity
{
public:
	Enemy(Player* player);
	virtual ~Enemy();

	void update(float deltaTime);

	float sTime;
	float countdownTime;
	void randomPosition(float deltaTime);

private:
	/* add your private declarations */
	Player* player;

};

#endif /* ENEMY_H */
