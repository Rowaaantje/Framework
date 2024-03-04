#ifndef ENEMY_H
#define ENEMY_H

#include <entity.h>
#include <player.h>

class Enemy: public Entity
{
public:
	Enemy();
	virtual ~Enemy();

	void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* ENEMY_H */
