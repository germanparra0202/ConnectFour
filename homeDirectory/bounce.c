/* German Parra
 * Fundamentals of Computing lab9
 * bounc.c
 * Collaborated with sebastian Gutierrez
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include "gfx.h"

int main() {
	
	// Setting the dimensions for the window 
	int width = 600;
	int height = 400;

	// Will be the center of the circle used in x (xc) and y (yc) directions
	float xc = 100;
	float yc = 100;
	
	srand(time(0));
	int seed = rand();
	srand(seed);

	int radius = 30; // circle with radius 30

	// Will generate the random values, vx velocity in x and vy velocity in y
	float vx = -5 + rand()%10;
	float vy = -5 + rand()%10;

	// Initialize the char c to an unused character
	char c = 0;

	// Will pause at this time to show the user clearly
	int times = 25000;

	// Opens window to user
	gfx_open(width,height,"bounce.c");

	// Will q isn't hit, the program will keep running
	while(c != 'q') {
		gfx_clear();
		// Puts circle with radius 30 and center xc, yc
		gfx_circle(xc,yc, radius);
		gfx_flush();

		// The random vx and vy given from the rand() function
		xc = xc + vx;
		yc = yc + vy;

		// If walls hit, will go the other direction
		if(xc > width - radius || xc < radius) 
			vx = -vx;
		if(yc < radius || yc > height - radius)
			vy = -vy;
		// If the mouse it hit, will place it in a new location 
		if(c == 1) {
			float xCen, yCen;
			float xVel,yVel;
			// once again gets the random numbers
			xVel = -5 + rand()%10;
			yVel = -5 + rand()%10;
		
			xCen = gfx_xpos();
			yCen = gfx_ypos();
			c = 0;

			if(xCen > width - radius || xCen < radius)
				continue;
			if(yCen < radius || yCen > height - radius)
				continue;
			// Will generate the new simulation of the circle
			while(c != 1) {
				gfx_clear();
				gfx_circle(xCen ,yCen ,radius);
				gfx_flush();
				xCen = xCen + xVel;
				yCen = yCen + yVel;
				// conditions if it hits the wall
				if(xCen > width - radius || xCen < radius)
					xVel = -xVel;
				if(yCen < radius || yCen > height - radius)
					yVel = -yVel;
				if(gfx_event_waiting())
					c = gfx_wait();
			
					if(c == 'q')
						break;
				
				usleep(times);
			}
		}
		if(gfx_event_waiting())
			c = gfx_wait();
		
		usleep(times);
	}
	
	return 0;
}
