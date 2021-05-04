#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>


typedef struct Scene
{
	Material material;
	Model models[11];
	GLuint textures[12];
} Scene;



/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting(GLfloat brightness);

/**
 * Set the current material.
 */
void set_material(Material* material);

/**
 * Draw the scene objects.
 */
void draw_scene(Scene* scene);

/**
 * Load models and corresponding textures.
 */
void load_models_and_textures(Scene* scene);

/**
 * Set the material params.
 */
void set_material_params(Scene* scene);

/**
 * Draw the models.
 */
void draw_models(Scene* scene);

/**
 * Draw a model.
 */
void draw_a_model(Scene* scene, int index, GLfloat scale, GLfloat trX, GLfloat trY, GLfloat trZ, GLfloat rotA, GLfloat rotX, GLfloat rotY, GLfloat rotZ); 


#endif /* SCENE_H */
