/*
* Copyright 2024 Rowan Pijnaker
*/

#ifndef Entity_H
#define Entity_H

#include "raylib.h"
#include <config.h>
#include <map>
#include <vector>
#include <string>

#include <iostream>
#include <cmath>
#include <cstdlib>

#include <algorithm>
#include <cstdlib>	
#include <time.h> 		

class Entity
{
public:
	/// @brief Constructor of Entity
	Entity();
	/// @brief Destructor of Entity
	virtual ~Entity();

    Vector3 position;
    Vector3 rotation;
    Vector3 scale;

	/// @brief Update the entity.
	/// @return void
	virtual void update(float deltaTime) = 0;

	/// @brief Add an Entity as child to an Entity
	/// @param child The Entity you are adding as child
	/// @return void
    void addChild(Entity* child);
	/// @brief Removes an entity from the scene
	/// @return void
    void removeChild(Entity* child);

	/// @brief Add a texture to an Entity
	/// @param filePath string of local path to the texture
	/// @return void
	void addTexture(char *filePath);
	/// @brief Remove the texture from an Entity
  	/// @return void
	void removeTexture();
	/// @brief Add a Color to an texture
	/// @param c Color from an texture
	/// @return void
	void setTextureColor(Color c);
	// draw actual image size of image
	/// @return void
	/// @param c Color from an texture
    void drawImageSize(Color c);

	/// @brief Getter for the children of an Entity
	/// @return std::vector<Entity> of the children of an Entity
	const std::vector<Entity *> &children() { return _children; };
	/// @brief Getter for the parent of an Entity
	/// @return Parent of an Entity
	Entity *parent() { return _parent; };
	/// @brief Getter for the texture of an Entity
	/// @return texture of an _texture
	Texture2D texture() {return _texture; };
	/// @brief Getter for the _textureColor of an Entity
	/// @return color of an _textureColor
	Color color() { return _textureColor; };
	Vector2 size() { return Vector2{(float)_texture.width, (float)_texture.height}; };

	//select how you want to render your texture 
	int renderMethod = 0;
	virtual void renderSelect(); 

protected:
	Vector2 _worldPosition;

private:
	/// @brief Texture of an Entity
	Texture2D _texture;
	Rectangle _rectangle;
	Color _textureColor;
	
	// identity
	int _guid; ///< @brief The _guid of this Entity
	static int _nextGuid; ///< @brief The _nextGuid of this Entity
	
	// data structure
	Entity* _parent; /// @brief _parent of an Entity
	std::vector<Entity*> _children; ///< @brief The _children of this Entity

	
};

#endif /* Entity_H */
