#include <entity.h>

Entity::Entity() 
{
    position = {0.0f, 0.0f, 0.0f};
    rotation = {0.0f, 0.0f, 0.0f};
    scale = {100.0f, 100.0f, 0.0f};
}   

Entity::~Entity() 
{
	removeTexture();
}

void Entity::update(float deltaTime) 
{
   
}

void Entity::draw()
{
    
}

void Entity::addChild(Entity* child)
{
    _children.push_back(child);
}

void Entity::removeChild(Entity* child)
{
    delete child;
}

void Entity::removeTexture()
{
    if(IsTextureReady(this->_texture))
    UnloadTexture(this->_texture);
}

void Entity::addTexture(char *filePath)
{
    removeTexture();
    if (IsPathFile(filePath))
        this->_texture = LoadTexture(filePath);

        if(_texture.id == 0){ 
            perror(" ########### Failed load texture ##########" ); 
        }
        // else {
        //     std::cout << "loaded texture : " << filePath << std::endl;
        // }
}

void Entity::setTextureColor(Color c)
{
  this->_textureColor = c;
}

void Entity::drawImageSize(Color c)
{
    DrawRectangle(this->position.x, this->position.y, this->size().x, this->size().y, c);
}



