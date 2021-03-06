#include "game.h"

void resize_game(Game* game, int width, int height)
{
    game->width = width;
    game->height = height;
    game->left_pad.size = 200;
    game->right_pad.size = 200;
    restart_game(game);
}

void restart_game(Game* game)
{
    float center_x;
    float center_y;

    center_x = game->width / 2;
    center_y = game->height / 2;

    move_pad(&(game->left_pad), center_y, game->height);
    move_pad(&(game->right_pad), center_y, game->height);
    start_ball(&(game->ball), center_x, center_y);
}

void update_game(Game* game, double time)
{
    update_ball(&(game->ball), time);
    
	if (game->ball.x - game->ball.radius < 50) {
        game->ball.x = game->ball.radius + 50;
        game->ball.speed_x *= -1;		
    }
    if (game->ball.x + game->ball.radius > game->width - 50) {
        game->ball.x = game->width - game->ball.radius - 50;
        game->ball.speed_x *= -1;
    }
    if (game->ball.y - game->ball.radius < 0) {
        game->ball.y = game->ball.radius;
        game->ball.speed_y *= -1;
    }
    if (game->ball.y + game->ball.radius > game->height) {
        game->ball.y = game->height - game->ball.radius;
        game->ball.speed_y *= -1;
    }
	
	
	
	
	
	// utkozes kezeles bal oldalt
	if(game->ball.x >= game->width-100) { // x hatarok
		if(!(game->ball.y <= game->right_pad.position+game->right_pad.size && game->ball.y >= game->right_pad.position)) {  // y hatarok
			restart_game(game); // jobb oldalt kiment a labda
		}	
	}
	
	// utkozes kezeles jobb oldalt
/*	if(game->ball.x <= 100) { // x hatarok
		if(!(game->ball.y <= game->left_pad.position+game->left_pad.size && game->ball.y >= game->left_pad.position)) {  // y hatarok
			restart_game(game); // bal oldalt kiment a labda
		}	
		
	}*/
	
	
	

	

}


void move_left_pad(Game* game, float position)
{
    move_pad(&(game->left_pad), position, game->height);	
}

void move_right_pad(Game* game, float position)
{
    move_pad(&(game->right_pad), position, game->height);
}

