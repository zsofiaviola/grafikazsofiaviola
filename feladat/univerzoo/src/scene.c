#include "scene.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>

GLfloat	rot = 0.0f;	
GLuint skybox[6];


void init_scene(Scene* scene)
{
	load_model(&(scene->dragon), "dragon.obj");
	scene->texture_id = load_texture("sun.png");

	load_model(&(scene->Gopher), "monkey.obj");
	scene->Gopher_texture_id = load_texture("merkur.png");
	
	load_model(&(scene->cat), "cat.obj");
	scene->cat_texture_id = load_texture("venus.png");
	
	load_model(&(scene->dolphin), "dolphin.obj");
	scene->dolphin_texture_id = load_texture("e2.png");
	
	load_model(&(scene->Camel), "Camel.obj");
	scene->Camel_texture_id = load_texture("mars.png");

	
	load_model(&(scene->lion), "lion.obj");
	scene->lion_texture_id = load_texture("jupiter.png");
	
	load_model(&(scene->turtle), "turtle.obj");
	scene->turtle_texture_id = load_texture("saturn.png");
	
	load_model(&(scene->pingvin), "pingviin.obj");
	scene->pingvin_texture_id = load_texture("neptune.png");
	
	load_model(&(scene->bear), "bear.obj");
	scene->bear_texture_id = load_texture("uranus.png");
	
	load_model(&(scene->dog), "dog.obj");
	scene->dog_texture_id = load_texture("pluto.png");
	
	load_model(&(scene->cube), "cube.obj");
	scene->cube_texture_id = load_texture("ur.png");
	
	// help_texture
	scene->help_texture_id = load_texture("help.bmp");
	

    scene->material.ambient.red = 1.0;
    scene->material.ambient.green = 1.0;
    scene->material.ambient.blue = 1.0;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;

    scene->material.specular.red = 1.0;
    scene->material.specular.green = 1.0;
    scene->material.specular.blue = 1.0;

    scene->material.shininess = 100.0;
}

void set_lighting(GLfloat brightness)
{
    /*float ambient_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float diffuse_light[] = { 1.0f, 0.0f, 0.0, 0.0f };
    float specular_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };*/
	
	float ambient_light[] = { brightness, brightness, brightness, brightness };
    float diffuse_light[] = { brightness, brightness, brightness, brightness };
    float specular_light[] = { brightness, brightness, brightness, brightness };
	
    float position[] = { 10.0f, 0.0f, 0.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void set_material(const Material* material)
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

void draw_scene(const Scene* scene)
{
	int i;
    set_material(&(scene->material));
    //set_lighting(0.0f);

	
	//dragon - Nap 
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->texture_id);
	glScalef(0.2,0.2,0.2); 
	glTranslatef(10,0,0);
	glRotatef(rot*1.5,0.0f,0.0f,1.0f);	
	draw_model(&(scene->dragon));
	glPopMatrix();
	
	/* monkey - Merkúr */
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->Gopher_texture_id);
	glScalef(0.006,0.006,0.006); 
	glTranslatef(-50,200,0);
	glRotatef(rot*1.5,0.0f,0.0f,1.0f);
	draw_model(&(scene->Gopher));
	glPopMatrix();
	
	
	/* cat - Vénusz */
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->cat_texture_id);
	glScalef(1.5,1.5,1.5); 
	glTranslatef(5,-1,0);
	glRotatef(rot*1.5,0.0f,0.0f,1.0f);	
	draw_model(&(scene->cat));
	glPopMatrix();
	
	/* dolphin - Föld */
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->dolphin_texture_id);
	glScalef(0.02,0.02,0.02); 
	glTranslatef(1100,-600,1);
	glRotatef(rot*1,0.0f,0.0f,1.0f);	
	draw_model(&(scene->dolphin));
	glPopMatrix();
	
	/* camel - Mars*/
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->Camel_texture_id);
	glScalef(0.0005,0.0005,0.0005); 
	glTranslatef(2700,-5500,0);
	glRotatef(rot*4,0.0f,0.0f,1.0f);	
	draw_model(&(scene->Camel));
	glPopMatrix(); 
	
	
	/* lion - Jupiter */
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->lion_texture_id);
	glScalef(0.004,0.004,0.004); 
	glTranslatef(1100,-1400,0);
	glRotatef(rot*1.5,0.0f,0.0f,1.0f);	
	draw_model(&(scene->lion));
	glPopMatrix();
	
		
	/* turtle - Szaturnusz */
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->turtle_texture_id);
	glScalef(0.005,0.005,0.005); 
	glTranslatef(120,-620,0);
	glRotatef(rot*1,0.0f,0.0f,1.0f);	
	draw_model(&(scene->turtle));
	glPopMatrix();
	
	/* bear - Uránusz*/
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->bear_texture_id);
	glScalef(0.1,0.1,0.1); 
	glTranslatef(45,-70,1);
	glRotatef(rot*1,0.0f,0.0f,1.0f);	
	draw_model(&(scene->bear));
	glPopMatrix();
	
	/* pingvin - Neptunusz*/
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->pingvin_texture_id);
	glScalef(0.0008,0.0008,0.0008); 
	glTranslatef(50,-1100,0);
	glRotatef(rot*1,0.0f,0.0f,1.0f);	
	draw_model(&(scene->pingvin));
	glPopMatrix();
	
	
	
	/* dog - Plútó */
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->dog_texture_id);
	glScalef(0.0001,0.0001,0.0001); 
	glTranslatef(10000,-60000,0);
	glRotatef(rot*4,0.0f,0.0f,1.0f);	
	draw_model(&(scene->dog));
	glPopMatrix();
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->cube_texture_id);
	glScalef(100.0,100.0,100.0); 
	glTranslatef(0,0,0);	
	draw_model(&(scene->cube));
	glPopMatrix();
	
	
	rot += 0.8f;
	if(rot == 360) {
		rot = 0;
	}

	
	
	
	
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







