#ifndef BLOCK_H
#define BLOCK_H


#include "entity.h"
///Class Definition: Your Block class inherits from a Entity
class Block : public Entity 
{
public:
	Block();
	virtual ~Block();
	virtual void update(float deltaTime);
	void draw(float deltaTime);

	Vector3 scale {100, 100, 0};
	
protected:
	Rectangle block;

private:
};

#endif /* BLOCK_H */