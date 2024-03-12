#ifndef BLOCK_H
#define BLOCK_H

#include <entity.h>

#define BLOCK_SIZE 16
#define BLOCK_COUNT 4
#define BLOCK_FPS 4
#define BLOCK_TIME 1.0f / BLOCK_FPS

///Class Definition: Your Block class inherits from a Entity
class Block : public Entity 
{
public:
	Block();
	virtual ~Block();
	virtual void update(float deltaTime);
	void draw(float deltaTime);

	
protected:
	int spriteIndex = 0;
	float playerTimer = BLOCK_TIME;

private:
};

#endif /* BLOCK_H */