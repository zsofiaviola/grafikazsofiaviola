#ifndef SCENE_H
#define SCENE_H

#include "camera.h"

typedef struct Scene
{
    // NOTE: Place for model structures and texture ids.
	
	float teapot_rotation;
} Scene;

/**
 * Initialize the scene.
 */
void init_scene(Scene* scene);

void update_scene(Scene* scene, double time);

/**

 * Draw the scene objects.
 */
void draw_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();
void draw_origin2();
void draw_polygon();
void draw_polygon2();
void draw();
void Show();


#endif /* SCENE_H */

