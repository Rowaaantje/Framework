#include <entity.h>

int Entity::_nextGuid = 0;

Entity::Entity()
{
  _guid = _nextGuid++;

  _parent = nullptr;

  position = {0.0f, 0.0f, 0.0f};
  rotation = {0.0f, 0.0f, 0.0f};
  scale = {1.0f, 1.0f, 1.0f};
}

Entity::~Entity()
{
  removeTexture();
}

void Entity::update(float deltaTime)
{
}

void Entity::addChild(Entity *child)
{
  if (child->_parent != nullptr)
  {
    child->_parent->removeChild(child);
  }

  // Check if the child is already a child of this entity
  for (Entity *existingChild : _children)
  {
    if (existingChild->_guid == child->_guid)
    {
      std::cout << "Child with GUID: " << child->_guid << " is already a child of this entity." << std::endl;
      return;
    }
  }
  // Set the current entity as the parent of the child.
  child->_parent = this;
  // Add the child to the list of children of the current entity
  _children.push_back(child);
  std::cout << "Added entity with GUID: " << child->_guid << std::endl;
}

void Entity::removeChild(Entity *child)
{

  std::vector<Entity *>::iterator it = _children.begin();
  while (it != _children.end())
  { // Iterate through the list of children of the current entity.
    if ((*it)->_guid == child->_guid)
    {                           // Find the child by comparing their unique identifiers (_guid).
      child->_parent = nullptr; // Disconnect the child from the current entity by setting its parent to nullptr.
      it = _children.erase(it); // Remove the child from the list of children and update the iterator.
      std::cout << "Removed child with GUID: " << child->_guid << std::endl;
    }
    else
    {
      ++it; // Move to the next child in the list.
    }
  }
}

void Entity::removeTexture()
{
  if (IsTextureReady(this->_texture))
    UnloadTexture(this->_texture);
}

void Entity::addTexture(char *filePath)
{
  removeTexture();
  if (IsPathFile(filePath))
    this->_texture = LoadTexture(filePath);

  if (_texture.id == 0)
  {
    perror(" ########### Failed loading texture ##########");
  }
}

void Entity::renderSelect()
{
  switch (renderMethod)
  {
  default:
    DrawTexture(this->texture(), this->position.x, this->position.y, this->color());
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
