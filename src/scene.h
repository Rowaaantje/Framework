#ifndef SCENE_H
#define SCENE_H

#include "entity.h"
#include <vector>
#include <map>

class Scene : public Entity 
{ 
 public:
  	/// @brief Constructor of a Scene
	Scene(uint16_t width, uint16_t height, const char* windowName);

	/// @brief Deconstructor of a scene
	~Scene();

	/// @brief Updates the scene for a given frame time
    virtual void update(float deltaTime);

    /// @brief draw the scene
	void draw(float deltaTime);

	void run(float deltaTime);

	/// @brief Adds an entity to the scene
    void addEntity(Entity* entity);

    /// @brief Removes an entity from the scene
    void removeEntity(Entity* entity);

	void drawAllEntities(float deltaTime);

	/// @brief Gets a pointer to the Camera2D
    /// @return Camera2D* a pointer to the Camera2D
    Camera2D* getCamera() const;

private:
	std::vector<Entity*> entities;
};

#endif /* SCENE_H */
