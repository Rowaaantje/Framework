#ifndef CAMERA_H
#define CAMERA_H

#include "raylib.h"

class CameraF
{
public:
	CameraF();
	virtual ~CameraF();
	virtual void update(float deltaTime);

    Camera2D camera = { 0 };
    Vector2 offset;         // Camera offset (displacement from target)
    Vector2 target;         // Camera target (rotation and zoom origin)
    float rotation;         // Camera rotation in degrees
    float zoom;             // Camera zoom (scaling), should be 1.0f by default
    

private:
	/* add your private declarations */

};

#endif /* CAMERA_H */
