#include "scene.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>



void set_material_params(Scene* scene)
{
    scene->material.ambient.red = 1.0;
    scene->material.ambient.green = 1.0;
    scene->material.ambient.blue = 1.0;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;

    scene->material.specular.red = 1.0;
    scene->material.specular.green = 1.0;
    scene->material.specular.blue = 1.0;

    scene->material.shininess = 1000.0;
}



void load_models_and_textures(Scene* scene)
{	
	load_model(&(scene->dragon), "data/modellek/dragon.obj");
	scene->texture_id = load_texture("data/texturak/sun.png");

	load_model(&(scene->monkey), "data/modellek/monkii.obj");
	scene->monkey_texture_id = load_texture("data/texturak/merkur.png");
	
	load_model(&(scene->cat), "data/modellek/cat.obj");
	scene->cat_texture_id = load_texture("data/texturak/venus.png");
	
	load_model(&(scene->dolphin), "data/modellek/dolphin.obj");
	scene->dolphin_texture_id = load_texture("data/texturak/e2.png");
	
	load_model(&(scene->fox), "data/modellek/fox.obj");
	scene->fox_texture_id = load_texture("data/texturak/mars.png");
	
	load_model(&(scene->lion), "data/modellek/lion.obj");
	scene->lion_texture_id = load_texture("data/texturak/jupiter.png");
	
	load_model(&(scene->deer), "data/modellek/deer.obj");
	scene->deer_texture_id = load_texture("data/texturak/saturn.png");
	
	load_model(&(scene->pingvin), "data/modellek/pingviin.obj");
	scene->pingvin_texture_id = load_texture("data/texturak/neptune.png");
	
	load_model(&(scene->bear), "data/modellek/bear.obj");
	scene->bear_texture_id = load_texture("data/texturak/uranus.png");
	
	load_model(&(scene->dog), "data/modellek/dog.obj");
	scene->dog_texture_id = load_texture("data/texturak/pluto.png");
	
	load_model(&(scene->cube), "data/modellek/cube.obj");
	scene->cube_texture_id = load_texture("data/texturak/ur.png");
	
	scene->help_texture_id = load_texture("data/texturak/help.bmp");
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


void draw_models(Scene* scene) 
{
	int time = glutGet(GLUT_ELAPSED_TIME);
	
	//dragon - Nap 
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->texture_id);
	glScalef(0.2,0.2,0.2); 
	glTranslatef(20,-10,0);
	glRotatef(time/25,0.0f,0.0f,1.0f);	
	draw_model(&(scene->dragon));
	glPopMatrix();
	
	/* monkey - Merkúr */
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->monkey_texture_id);
	glScalef(0.08,0.08,0.08); 
	glTranslatef(-10,10,0);
	glRotatef(time/25,0.0f,0.0f,1.0f);
	draw_model(&(scene->monkey));
	glPopMatrix();
	
	
	/* cat - Vénusz */
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->cat_texture_id);
	glScalef(1.5,1.5,1.5); 
	glTranslatef(5,-1,0);
	glRotatef(-time/25,0.0f,0.0f,1.0f);	
	draw_model(&(scene->cat));
	glPopMatrix();
	
	/* dolphin - Föld */
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->dolphin_texture_id);
	glScalef(0.02,0.02,0.02); 
	glTranslatef(1100,-600,1);
	glRotatef(time/10,0.0f,0.0f,1.0f);	
	draw_model(&(scene->dolphin));
	glPopMatrix();
	
	/* fox - Mars*/
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->fox_texture_id);
	glScalef(0.05,0.05,0.05); 
	glTranslatef(270,-550,0);
	glRotatef(time/10,0.0f,0.0f,1.0f);	
	draw_model(&(scene->fox));
	glPopMatrix(); 
	
	
	/* lion - Jupiter */
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->lion_texture_id);
	glScalef(0.004,0.004,0.004); 
	glTranslatef(1100,-1400,0);
	glRotatef(time/6,0.0f,0.0f,1.0f);	
	draw_model(&(scene->lion));
	glPopMatrix();
	
		
	/* deer - Szaturnusz */
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->deer_texture_id);
	glScalef(0.5,0.5,0.5); 
	glTranslatef(90,-100,0);
	glRotatef(time/5,0.0f,0.0f,1.0f);	
	draw_model(&(scene->deer));
	glPopMatrix();
	
	/* bear - Uránusz*/
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->bear_texture_id);
	glScalef(0.1,0.1,0.1); 
	glTranslatef(45,-70,1);
	glRotatef(time/25,0.0f,0.0f,1.0f);	
	draw_model(&(scene->bear));
	glPopMatrix();
	
	/* pingvin - Neptunusz*/
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->pingvin_texture_id);
	glScalef(0.0008,0.0008,0.0008); 
	glTranslatef(50,-1100,0);
	glRotatef(time/25,0.0f,0.0f,1.0f);	
	draw_model(&(scene->pingvin));
	glPopMatrix();
	
	
	/* dog - Plútó */
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->dog_texture_id);
	glScalef(0.0001,0.0001,0.0001); 
	glTranslatef(10000,-60000,0);
	glRotatef(time/25,0.0f,0.0f,1.0f);	
	draw_model(&(scene->dog));
	glPopMatrix();
	
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->cube_texture_id);
	glScalef(100.0,100.0,100.0); 
	glTranslatef(0,0,0);	
	draw_model(&(scene->cube));
	glPopMatrix();
}


void show_help(Scene* scene)
{
	 glBindTexture(GL_TEXTURE_2D, scene->help_texture_id);
	 
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
