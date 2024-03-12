#ifndef SWORD_H
#define SWORD_H

#include <entity.h>

#define SWORD_SIZE 16
#define SWORD_COUNT 4
#define SWORD_FPS 4
#define SWORD_TIME 1.0f / SWORD_FPS

///Class Definition: Your SWORD class inherits from a Entity
class Sword : public Entity 
{
public:
	Sword();
	virtual ~Sword();
	virtual void update(float deltaTime);
	void draw(float deltaTime);

	
protected:
	int spriteIndex = 0;
	float playerTimer = SWORD_TIME;

private:
};

#endif /* SWORD_H */