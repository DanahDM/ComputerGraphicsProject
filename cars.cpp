#include <stdio.h>
#include <dos.h>
#include <conio.h>
#include "graphics.h"

using namespace std;

void circlePlotPoints(int xCenter, int yCenter, int x, int y)
{
	putpixel(xCenter + x, yCenter + y, 0);
	putpixel(xCenter - x, yCenter + y, 0);
	putpixel(xCenter + x, yCenter - y, 0);
	putpixel(xCenter - x, yCenter - y, 0);
	putpixel(xCenter + y, yCenter + x, 0);
	putpixel(xCenter - y, yCenter + x, 0);
	putpixel(xCenter + y, yCenter - x, 0);
	putpixel(xCenter - y, yCenter - x, 0);
}

void circleMidpoint(int xCenter, int yCenter, int radius)
{
	
	int x = 0;
	int y = radius;
	int f = 1 - radius;

	circlePlotPoints(xCenter, yCenter, x, y);
	while (x < y) {
		x++;
		if (f < 0)
			f += 2 * x + 1;
		else {
			y--;
			f += 2 * (x - y) + 1;
		}
		circlePlotPoints(xCenter, yCenter, x, y);
	}
}
void drawGround(){
setfillstyle(1,7);
floodfill(1,1,15);
setcolor(WHITE);
rectangle(10,10,15,460);
setfillstyle(1,15);
floodfill(11,31,WHITE);
//1
rectangle(10,10,170,15);
floodfill(169,14,WHITE);
//2
rectangle(10,100,170,105);
floodfill(169,104,WHITE);
//3
rectangle(10,190,170,195);
floodfill(169,194,WHITE);
//4
rectangle(10,280,170,285);
floodfill(169,284,WHITE);
//5
rectangle(10,370,170,375);
floodfill(169,374,WHITE);
//6
rectangle(10,460,170,465);
floodfill(169,464,WHITE);
}

void drawStaticCars(){
//car1
setcolor(15);
rectangle(50,20,130,40);
rectangle(30,40,150,65);
setfillstyle(1,RED);
floodfill(51,21,15);
floodfill(31,41,15);

setcolor(0);
circleMidpoint(60,70,20);
circleMidpoint(120,70,20);
setfillstyle(1,8);
floodfill(60,70,0);
floodfill(120,70,0);

//car2
setcolor(15);
rectangle(50,110,130,130);
rectangle(30,130,150,155);
setfillstyle(1,YELLOW);
floodfill(51,111,15);
floodfill(31,131,15);

setcolor(0);
circleMidpoint(60,160,20);
circleMidpoint(120,160,20);
setfillstyle(1,8);
floodfill(60,150,0);
floodfill(120,150,0);


//car4
setcolor(15);
rectangle(50,290,130,310);
rectangle(30,310,150,335);
setfillstyle(1,BLUE);
floodfill(51,291,15);
floodfill(31,311,15);

setcolor(0);
circleMidpoint(60,340,20);
circleMidpoint(120,340,20);
setfillstyle(1,8);
floodfill(60,340,0);
floodfill(120,340,0);

//car5
setcolor(15);
rectangle(50,380,130,400);
rectangle(30,400,150,425);
setfillstyle(1,MAGENTA);
floodfill(51,381,15);
floodfill(31,401,15);

setcolor(0);
circleMidpoint(60,430,20);
circleMidpoint(120,430,20);
setfillstyle(1,8);
floodfill(60,430,0);
floodfill(120,430,0);

}


void drawMovingCar(int i){

//car3
setcolor(15);
rectangle(250-i,200,330-i,220);
rectangle(230-i,220,350-i,245);
setfillstyle(1,GREEN);
floodfill(251-i,201,15);
floodfill(231-i,221,15);

setcolor(0);
circleMidpoint(260-i,250,20);
circleMidpoint(320-i,250,20);
setfillstyle(1,8);
floodfill(260-i,250,0);
floodfill(320-i,250,0);



}

int main(){
int GD=DETECT,GM;
	initgraph(&GD,&GM,"c:\tc\bgi");	



	for(int i = 0; i < 200; i++){
	cleardevice();
	setcolor(WHITE);
    rectangle(0,0,645,480);

	
	drawGround();
	drawStaticCars();
	drawMovingCar(i);
	delay(60);
	
	}

	getch();

	return 0;
    
}
