/* CSE 20311
 * German Parra
 * Fundamentals of Computing lab9
 * symbol.c
 */

#include<stdio.h>
#include<unistd.h>
#include<math.h>
#include<string.h>

#include "gfx.h"

void displaySquare(int, int, int);
void displayCircle(int, int, int);
void displayTriangle(int, int, int);
void displayPoly(int, int, int, int);

int main() {
	// Assigned to a random number that won't be used
	char c = 0;
	int SIZE = 50;

	gfx_open(600, 400, "symbol.c Parra, German");
	// Will continue going until the program is quit with q
	while(c != 'q') {

		c = gfx_wait();
		// For left mouse key, therefore don't need the '1'
		if(c == 1 || c == '1') {
			int a = gfx_xpos();
			int b = gfx_ypos();
			displaySquare(a,b, SIZE);
		}
		// Calls circle function (not needed but included for color)
		else if(c == 'c') {
			int a = gfx_xpos();
			int b = gfx_ypos();
			displayCircle(a, b, SIZE);
		}
		// Calls triangle function
		else if(c == 't') {
			int a = gfx_xpos();
			int b = gfx_ypos();
			displayTriangle(a, b, SIZE);
		}
		else if(c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9') {
			int a, b;
			int n;
			n = c-48;
			// gets position of the mouse
			a = gfx_xpos();
			b = gfx_ypos();
			// calls function
			displayPoly(a, b, n, SIZE); 
		}
		// Clears it if one choses esc
		else if(c == 27) {
			gfx_clear();
		}
	}
	return 0;
}

void displaySquare(int a,int b, int SIZE) {
	
	gfx_color(0,0,255); // color should be blue for square
	
	float x = SIZE/2;
	gfx_line(a+x,b+x, a-x,b+x);// top right to top left
	gfx_line(a+x,b-x, a-x,b-x); // bottom right to bottom left
	gfx_line(a+x,b+x, a+x,b-x); // top right to bottom right
	gfx_line(a-x,b+x, a-x,b-x);// top left to bottom left

}

// don't need a function but included for the color
void displayCircle(int a, int b, int SIZE) {
	
	gfx_color(255,255,255); // white cirlce 
	gfx_circle(a,b,SIZE);
}

// Function for getting the three lines for the triangle
void displayTriangle(int a, int b, int SIZE) {
	
	gfx_color(0,255,0); // need a green triangle
	float x = SIZE/2; 

	gfx_line(a-x, b-x, a+x, b-x); // bottom left corner to bottom right
	gfx_line(a-x, b-x, a, b+x);// bottom left to top
	gfx_line(a+x, b-x, a, b+x);// bottom right to top
}

void displayPoly(int x, int y, int n, int SIZE) {
	
	gfx_color(128,0,128); // need a purple color now
	int i;
	float k;
	k = (2*M_PI)/n;
	for(i = 0; i < n; i++) { // gets the proper lines no matter how many sides the polygon has
		gfx_line(x+SIZE*cos(k*i), y - SIZE*sin(k*i), x+SIZE*cos(k*(i+1)), y-SIZE*sin(k*(i+1)));
	}
}
