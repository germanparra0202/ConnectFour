/* German Parra
 * Fundamentals of Computing 
 * lab9
 * funanim.c
 * Display objects of different color, circular motion, and give the user an option
 */

// Libraries
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<math.h>

#include "gfx.h"

// Function Prototypes, Will print the four objects
void dispDiamond(int, int, int);
void dispTrap(int, int, int);
void dispCross(int, int, int);
void dispShip(int, int, int);

int main() {

	// Variables for the window dimensions, size of objects, c user input
	int width = 600;
	int height = 700;
	int size = 50;
	char c = 0;

	// Variables for motion of the circles and placement
	int radius = 30;
	float i = 0;
	
	// Pausetime
	int pausetime = 7000;

	// Opens window 
	gfx_open(width, height, "Animation Window");
	
	// Will keep running until q is hit
	while(c != 'q') {
			
		gfx_clear();
		// Displaying four objects after it's been cleared so it's always displayed
	    dispTrap(500,600, size); // bottom right of the screen
		dispDiamond(500, 100, size); // top right of the screen
		dispCross(100, 600, size); // bottom left of the screen
		dispShip(100,100, size); // top left of the screen

		// Yellow messages to let the user know how to run the program
		gfx_color(255,0,0);
		gfx_text(200, 100,"Left click mouse for fast clockwise motion");
		gfx_text(200, 150,"Right click mouse for fast counterclockwise");
		gfx_text(200,200, "Press any other key to reset it");

		gfx_flush();

		// Color for the circle doing the motion
		gfx_color(255, 255, 255);
		
		// Center of the screen
		float a = width/2;
		float b = height/2;	
	
		// Getting new values of circle and displaying current cirlce
		a = a+(200*cos(i));
		b = b+(200*sin(i));
		gfx_circle(a,b, radius);
		a = 300;
		b = 350;
		i = i + 0.01;
		
		// Option when user cicks left mouse, fast clockwise
		if(c == 1) {
			i = i + .1;
		}
		// Option when user clicks right mouse, fast counterclockwise
		else if(c == 3 || c == 2) {
			i = i -.1;	
		}
		
		// Any other option will return it to its original behavior

		if(gfx_event_waiting()) 
			c = gfx_wait();

		usleep(pausetime);
		}

	return 0;
}

// Will create the Diamond of color Orange when user hits d or 
void dispDiamond(int a, int b, int size) {
	
	gfx_color(255, 165, 0);
	int x = size/2;
	gfx_line(a, b+x, a+x, b); // top right line
	gfx_line(a, b+x, a-x, b); // top left line
	gfx_line(a-x, b, a, b-x); // bottom left line
	gfx_line(a, b-x, a+x, b); // bottom right line
}

void dispTrap(int a, int b, int size) {

	gfx_color(255, 255, 0);
	int x = size/2;
	gfx_line(a+x, b+x, a-x, b+x); // top line
	gfx_line(a+size, b-x, a-size, b-x); // bottom line
	gfx_line(a+size, b-x, a+x, b+x); // right side 
	gfx_line(a-size, b-x, a-x, b+x); // left side
}

void dispCross(int a, int b, int size) {
	
	int x = size/2;
	gfx_color(255, 105, 180);
	// creating 12 lines
	gfx_line(a+10,b+x,a-10,b+x); //top
	gfx_line(a-10,b+x,a-10,b+10); //left top
	gfx_line(a-10,b+10,a-x,b+10); // left flat
	gfx_line(a-x,b+10, a-x, b-10); // left side
	gfx_line(a-x,b-10, a-10,b-10); // left flat bottom
	gfx_line(a-10,b-10,a-10,b-size); // left side bottom
	gfx_line(a-10, b-size, a+10, b-size); // bottom flat
	gfx_line(a+10, b-size,a+10,b-10); // right side bottom
	gfx_line(a+10,b-10,a+x,b-10); // bottom flat right
	gfx_line(a+x,b-10,a+x,b+10); // right side top
	gfx_line(a+x,b+10,a+10,b+10); // top right flat
	gfx_line(a+10,b+10,a+10,b+x); // top right side

}

void dispShip(int a, int b, int size) {

	int x = size/2;	
	gfx_color(0,255,0);
	// creating 5 lines
	gfx_line(a-20,b-size,a,b+size); // left upwards line
	gfx_line(a,b+size,a+20,b-size); // right downwards line
	gfx_line(a+20, b-size,a-size-10,b+x); //upwards right line
	gfx_line(a-size-10, b+x, a+size+10, b+x); // straight line
	gfx_line(a+size+10, b+x, a-20,b-size); // right downwards line
}
