#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

typedef struct Scene
{
	Model dragon; //nap
	Model Gopher; //merkúr
	Model cat; //vénusz
	Model dolphin; //föld
	Model Camel; //mars
	Model lion; //jupiter
	Model turtle; //szaturunusz
	Model bear; //uránusz
	Model pingvin; //neptunusz
	Model dog; //plútó
	Model cube;
	
	
    Material material;

	GLuint texture_id;
	GLuint Gopher_texture_id;
	GLuint cat_texture_id;
	GLuint dolphin_texture_id;
	GLuint Camel_texture_id;
	GLuint lion_texture_id;
	GLuint turtle_texture_id;
	GLuint bear_texture_id;
	GLuint pingvin_texture_id;
	GLuint dog_texture_id;
	GLuint cube_texture_id;
	GLuint help_texture_id;
	
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
void set_material(const Material* material);

/**
 * Draw the scene objects.
 */
void draw_scene(const Scene* scene);



#endif /* SCENE_H */
