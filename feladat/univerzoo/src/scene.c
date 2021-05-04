#include "scene.h"
#include <GL/glut.h>
#include <obj/load.h>
#include <obj/draw.h>


void set_material_params(Scene* scene)
{
    scene->material.ambient.red = 0.2;
    scene->material.ambient.green = 0.2;
    scene->material.ambient.blue = 0.2;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;

    scene->material.specular.red = 1.0;
    scene->material.specular.green = 1.0;
    scene->material.specular.blue = 1.0;

    scene->material.shininess = 100.0;
}



void load_models_and_textures(Scene* scene)
{	
	const char model_path[11][27] =
	{ 
	  "data/modellek/dragon.obj",
	  "data/modellek/monkii.obj",
	  "data/modellek/cat.obj",
	  "data/modellek/dolphin.obj",
	  "data/modellek/fox.obj",
	  "data/modellek/lion.obj",
	  "data/modellek/deer.obj",
	  "data/modellek/pingviin.obj",
	  "data/modellek/bear.obj",
	  "data/modellek/dog.obj",
	  "data/modellek/cube.obj"  
	};

	const char texture_path[12][28] =
	{ 
	  "data/texturak/sun.png",
	  "data/texturak/merkur.png",
	  "data/texturak/venus.png",
	  "data/texturak/e2.png",
	  "data/texturak/mars.png",
	  "data/texturak/jupiter.png",
	  "data/texturak/saturn.png",
	  "data/texturak/neptune.png",
	  "data/texturak/uranus.png",
	  "data/texturak/pluto.png",
	  "data/texturak/ur.png",
	  "data/texturak/help.bmp"
	};

	int i = 0;
	
	for(i = 0; i < 11; i = i + 1) {
		load_model(&(scene->models[i]), model_path[i]);
		scene->textures[i] = load_texture(texture_path[i]);
	}
	
	scene->textures[11] = load_texture(texture_path[11]);
}


void draw_a_model(Scene* scene, int index, GLfloat scale, GLfloat trX, GLfloat trY, GLfloat trZ, GLfloat rotA, GLfloat rotX, GLfloat rotY, GLfloat rotZ) 
{
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->textures[index]);
	glScalef(scale,scale,scale); 
	glTranslatef(trX,trY,trZ);
	glRotatef(rotA,rotX,rotY,rotZ);	
	draw_model(&(scene->models[index]));
	glPopMatrix();	
}


void draw_models(Scene* scene) 
{
	int time = glutGet(GLUT_ELAPSED_TIME);
	
	GLfloat modelScale[11] = {0.2, 0.08, 1.5, 0.02, 0.05, 0.004, 0.5, 0.0008, 0.1, 0.0001, 100.0};

	GLfloat modelTranslateX[11] = {20, -10, 5, 1100, 270, 1100, 90, 50, 45, 10000, 0};
	GLfloat modelTranslateY[11] = {-10, 10, -1, -600, -550, -1400, -100, -1100, -70, -60000, 0};
	GLfloat modelTranslateZ[11] = {0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0};
	
	GLfloat modelRotateA[11] = {time/25, time/25, -time/25, time/10, time/10, time/6, time/5, time/25, time/25, time/25, 0};
	GLfloat modelRotateX[11] = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
	GLfloat modelRotateY[11] = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
	GLfloat modelRotateZ[11] = {1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f};

	int i = 0;
	
	for(i = 0; i < 11; i = i + 1) {
		draw_a_model(scene, i, modelScale[i], modelTranslateX[i], modelTranslateY[i], modelTranslateZ[i], modelRotateA[i], modelRotateX[i], modelRotateY[i], modelRotateZ[i]);
	}
}


void set_lighting(GLfloat brightness)
{
	float ambient_light[] = { brightness, brightness, brightness, brightness };
    float diffuse_light[] = { brightness, brightness, brightness, brightness };
    float specular_light[] = { brightness, brightness, brightness, brightness };
    float position[] = { 700.0f, 700.0f, 700.0f, 100.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);	
}


void set_material(Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}


void show_help(Scene* scene)
{
	 glBindTexture(GL_TEXTURE_2D, scene->textures[11]);
	 
     glBegin(GL_QUADS);
     {
        glTexCoord2f(0.0, 0.0);
        glVertex3f(-1, 1, -2);
            
        glTexCoord2f(1.0, 0.0);
        glVertex3f(1, 1, -2);
            
        glTexCoord2f(1.0, 1.0);
        glVertex3f(1, -1, -2);
            
        glTexCoord2f(0.0, 1.0);
        glVertex3f(-1, -1, -2);
     }
    glEnd();
 
}


void init_scene(Scene* scene)
{
	load_models_and_textures(scene);
	
	set_material_params(scene);
	
	set_lighting(0.75f); // alap fenyero
}


void draw_scene(Scene* scene)
{
    set_material(&(scene->material));
	
	draw_models(scene); 
}
