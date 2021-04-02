#include "scene.h"

#include <GL/glut.h>

void init_scene(Scene* scene)
{
	scene->teapot_rotation=0.0;
}

void update_scene(Scene* scene, double time){
	
	scene->teapot_rotation += 5.0 * time;
}

void draw_scene(const Scene* scene)
{
	//draw_origin();
	//draw_origin2();
	//draw_polygon();
	//draw_polygon2();
	draw();
	//Show();
	
	
	/*glPushMatrix();
	glRotatef(scene->teapot_rotation, 1, 0, 0);
	glutWireTeapot(1);
	glPopMatrix();*/
}

void draw_origin()
{
   /* glBegin(GL_LINE_LOOP);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();*/

}

void draw_origin2()
{
	int i, k;
	glPushMatrix();
	for(k=0;k < 10; ++k){
		glPushMatrix();
	
		for (i=0; i< 10; ++i){
			
			glTranslatef(0,0,1);
			glBegin(GL_TRIANGLES);

			glColor3f(1, 0, 0);
		   
			glVertex3f(1, 0, 0);

			glColor3f(0, 1, 0);
			
			glVertex3f(0, 1, 0);

			glColor3f(0, 0, 1);
			
			glVertex3f(0, 0, 1);

			glEnd();
		}
		glPopMatrix();
		 glTranslatef(1,0,0);
		 
		
}
glPopMatrix();


	
}

void draw_polygon()
{
	GLfloat p1[3] = {0,0,1};
	GLfloat p2[3] = {1,0,1};
	GLfloat p3[3] = {1,1,1};
	GLfloat p4[3] = {0,1,1};
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex3fv(p1);
	glColor3f(1, 0, 0);
	glVertex3fv(p2);
	glColor3f(0, 1, 0);
	glVertex3fv(p3);
	glColor3f(1, 1, 0);
	glVertex3fv(p4);
	glEnd();
}


void draw_polygon2()
{
	
glColor3f(1, 0, 0);
glBegin(GL_POLYGON);

glVertex3f(-0.60, 0.77, 0); // <--- -0.60 instead of -0.68
glVertex3f(-0.68, 0.77, 0); // <--- -0.68 instead of -0.60
glVertex3f(-0.7, 0.68, 0);
glVertex3f(-0.64, 0.63, 0);
glVertex3f(-0.58, 0.68, 0);

glEnd();
}

void draw() {
			
			
			/*glPushMatrix();
			glTranslatef(0,0,1);
			glBegin(GL_TRIANGLES);
			
			
			glColor3f(1, 0, 0);
			glVertex3f(1, 0, 0);
			
			glColor3f(0, 1, 0);
			glVertex3f(0, 1, 0);
			
			glColor3f(0, 0, 1);
			glVertex3f(0, 0, 1);
			
			glVertex3f(-10, 10, 0);
			
			
			glColor3f(1, 0, 0);
			glVertex3f(0, 0, 1);
			
			glColor3f(0, 1, 0);
			glVertex3f(0, 1, 0)
			;
			glColor3f(0, 0, 1);
			glVertex3f(1, 0, 0);
			
			glVertex3f(10, -10, 0);
			
			/*glColor3f(1, 0, 0);
			glVertex3f(100, 0, 0);
			glColor3f(0, 1, 0);
			glVertex3f(0, 100, 0);
			glColor3f(0, 0, 1);
			glVertex3f(0, 0, 100);
			glVertex3f(-30, 30, 0);
			
			glColor3f(1, 0, 0);
			glVertex3f(100, 0, 0);
			glColor3f(0, 1, 0);
			glVertex3f(0, 100, 0);
			glColor3f(0, 0, 1);
			glVertex3f(0, 0, 100);
			glVertex3f(-40, 30, 0);
			
			glColor3f(1, 0, 0);
			glVertex3f(100, 0, 0);
			glColor3f(0, 1, 0);
			glVertex3f(0, 100, 0);
			glColor3f(0, 0, 1);
			glVertex3f(0, 0, 100);
			glVertex3f(-50, 50, 0);*/
			
			GLfloat p1[3] = {0,0,1};
			GLfloat p2[3] = {1,0,1};
			GLfloat p3[3] = {1,1,1};
			GLfloat p4[3] = {0,1,1};
			glBegin(GL_TRIANGLE_FAN);
			glVertex3fv(p1);
			glVertex3fv(p2);
			glVertex3fv(p3);
			glVertex3fv(p4);
			glEnd();
						

			

}

  
 
void Show()
{
	

 glBegin(GL_QUADS);
 glColor3f(1, 0, 0);
 glVertex3f(-50, 0, 0);
 glColor3f(1, 0, 0);
 glVertex3f( 0, 50, 0);
 glColor3f(1, 0, 0);
 glVertex3f( 50, 0, 0);
 glColor3f(1, 0, 0);
 glVertex3f( 0, -50, 0);
glEnd();


}
 


