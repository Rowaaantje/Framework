/*
	todo actualy draw entities with drawAllEntities();
*/

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

    /// @brief draw the scene
	/// @return void
	void draw(float deltaTime);

	/// @brief update this Scene
	/// @param deltaTime the number of seconds since the last update
	/// @return void
	virtual void updateScene(float deltaTime);

	/// @brief Wether the scene is active or not
	bool isActive() { return !WindowShouldClose(); };

	/// @brief Adds an entity to the scene
	/// @return void
    void addEntity(Entity* entity);

	/// @brief Gets a pointer to the Camera2D
    /// @return Camera2D* a pointer to the Camera2D
    Camera2D* getCamera() const;

// protected:

private:
	/// @brief draw each entity from the list entities
	/// @return void
	void updateEntity(float deltaTime);

	std::vector<Entity*> entities;
};

#endif /* SCENE_H */
