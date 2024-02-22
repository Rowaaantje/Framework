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

	/// @brief Updates the scene for a given frame time
	// @brief Update the scene. This function is PURE VIRTUAL. You MUST implement it when extending from Scene.
	/// @return void
	virtual void update(float deltaTime) = 0;

    /// @brief draw the scene
	/// @return void
	void draw(float deltaTime);

	void run(float deltaTime);

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
	void updateEntity(Entity* entity, float deltaTime);

	std::vector<Entity*> entities;
};

#endif /* SCENE_H */
