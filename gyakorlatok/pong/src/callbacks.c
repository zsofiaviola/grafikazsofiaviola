#include "callbacks.h"
#include "draw.h"

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    draw_game(&game);

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height)
{
    resize_game(&game, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -200, 200);
    glViewport(0, 0, width, height);
}

void motion(int x, int y)
{
    move_right_pad(&game, y);
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    float left_pad_position;
    left_pad_position = game.left_pad.position;
	
	float ballSize;
    ballSize = game.ball.radius;
	
    switch (key) {
    case 'w':
        left_pad_position -= 10;
        break;
    case 's':
        left_pad_position += 10;
        break;
	case 'e':
        ballSize += 5;
        break;
	case 'r':
        ballSize -= 5;
        break;
    }
	
	if (ballSize >=100 || ballSize <= 10) {
		ballSize = 50;
	}

	move_left_pad(&game, left_pad_position);
	set_ball_size(&game.ball, ballSize);

    glutPostRedisplay();
}


void idle()
{
    static int last_frame_time = 0;
    int current_time;
    double elapsed_time;
   
    current_time = glutGet(GLUT_ELAPSED_TIME);
    elapsed_time = (double)(current_time - last_frame_time) / 1000;
    last_frame_time = current_time;

    update_game(&game, elapsed_time);
    glutPostRedisplay();
}

