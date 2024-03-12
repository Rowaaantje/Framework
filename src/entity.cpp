#include <entity.h>

Entity::Entity() 
{
    position = {0.0f, 0.0f, 0.0f};
    rotation = {0.0f, 0.0f, 0.0f};
    scale = {1.0f, 1.0f, 0.0f};

    source = {0, 0, 0, 0,};
    dest = {0, 0, 0, 0,};
    origin = {0, 0};
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
}

void Entity::renderSelect() 
{
    switch (renderMethod)
    {
    case 1: 
        // DrawTexturePro(this->texture(), this->source(), this->dest(), this->origin(), 0, this->color());
        DrawTexturePro(this->texture(), this->source, this->dest, this->origin, 0, this->color());
        // std::cout <<"DrawTexturePro"<<std::endl;
        break;
    default:
        DrawTexture(this->texture(), this->position.x, this->position.y, this->color());
        // std::cout << " ########### Failed load texture ##########" <<std::endl; 
        break;
    }
}

void Entity::setTextureColor(Color c)
{
  this->_textureColor = c;
}

void Entity::drawImageSize(Color c)
{
    DrawRectangle(this->position.x, this->position.y, this->size().x, this->size().y, c);
}


