#include "PPMMagic.c"

#define IMAGE_WIDTH 800 
#define IMAGE_HEIGHT 600 

int main(){
	//initialize an image with width and height
	if(create_image(IMAGE_WIDTH, IMAGE_HEIGHT) != 1){return -1;}
	//Draw top rectangle
	draw_rect(0, 0, IMAGE_WIDTH, IMAGE_HEIGHT/4, 0xFF682800);
	//Draw Bottom Rectangle
	draw_rect(0, IMAGE_HEIGHT, IMAGE_WIDTH, IMAGE_HEIGHT-IMAGE_HEIGHT/4, 0xFF682800);
	//Draw middle rectangle
	draw_rect(0,  IMAGE_HEIGHT/4, IMAGE_WIDTH, IMAGE_HEIGHT*3/4, 0xFF2611CE);
	//Draw Center Circle
	draw_circle(IMAGE_WIDTH/2, IMAGE_HEIGHT/2, (IMAGE_WIDTH + IMAGE_HEIGHT)/2/10, 0xFFFFFFFF); 
	//Save the current image, to a file called laos.ppm
	if(save_image("laos.ppm") != 1){return -1;}
	return 1;
}
