#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

typedef struct Scene
{
	Model dragon; //nap
	Model monkey; //merkúr
	Model cat; //vénusz
	Model dolphin; //föld
	Model fox; //mars
	Model lion; //jupiter
	Model deer; //szaturunusz
	Model bear; //uránusz
	Model pingvin; //neptunusz
	Model dog; //plútó
	Model cube; //ur
	
	
    Material material;

	GLuint texture_id;
	GLuint monkey_texture_id;
	GLuint cat_texture_id;
	GLuint dolphin_texture_id;
	GLuint fox_texture_id;
	GLuint lion_texture_id;
	GLuint deer_texture_id;
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

#endif /* SCENE_H */
