#ifndef BLOCK_H
#define BLOCK_H


#include "entity.h"
///Class Definition: Your Player class inherits from a Scene
/// @brief The Player class is the Scene implementation.
class Block : public Entity 
{
public:
	Block();
	virtual ~Block();
	virtual void update(float deltaTime);

	Vector3 scale {100, 100, 0};
	
private:
	Rectangle block; 

};

#endif /* BLOCK_H */
