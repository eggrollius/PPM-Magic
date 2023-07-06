#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#include "PPMMagic.h"
void swap(int *p1, int *p2){
	int swap = *p1;
	*p1 = *p2;
	*p2 = swap;
}
uint32_t *image;///Global var for an array of the image
int w; int h; //Image width and height


int create_image(int width, int height){
	image = (uint32_t*)malloc(width*height*sizeof(uint32_t));	
	if(!image){return -1;}
	w = width; h = height;	
	return 1;
}

void fill_image(uint32_t c){
	//PARAMS: image to operate on, width, height, color
	for(uint32_t y = 0; y < h; ++y){
		for(uint32_t x = 0; x < w; ++x){
			image[y*w+x] = c;	
		}
	}	
}

void draw_rect(int x1, int y1, int x2, int y2, uint32_t c){
	if(x1 > x2){
		swap(&x1, &x2);
	}
	if(y1 > y2){
		swap(&y1, &y2);
	}

	for(int x = x1; x < x2; ++x){
		if(0 <= x && x <= w){
			for(int y = y1; y < y2; ++y){
				if(0 <= y && y <= h){
					image[y*w+x] = c;
				}
			}
		}
	}
}

void draw_circle(int x1, int y1, int r, uint32_t c){
	for(int x = x1-r; x < x1+r; ++x){
		if(0 <= x && x <= w){
			for(int y = y1-r; y < y1+r; ++y){
				if(0 <= y && y <= h){
					if(sqr_dist(x, y, x1, y1) <= r*r){
						image[y*w+x] = c;
					}
				}
			}
		}
	}
}

void draw_line(int x1, int y1, int x2, int y2, uint32_t c){
	int dy = y2 - y1;
	int dx = x2 - x1;
	int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
	double xInc = (double)dx/steps;
	double yInc = (double)dy/steps;

	double x = (double)x1;
	double y = (double)y1;
	for(int i = 0; i < steps; ++i){
		if(0 <= x && x < w && 0 <= y && y < h){	
			image[((int)round(y))*w + ((int)round(x))] = c;
		}	
		x += xInc;
		y += yInc;
	}
}

int save_image(const char *file_path){
	FILE *f = fopen(file_path, "wb");
	if(f == NULL){return -1;}	
	fprintf(f, "P6\n%d %d 255\n", w, h);
	for(int y = 0; y < h; ++y){
		for(int x = 0; x < w; ++x){
			uint32_t pixel_color = image[y*w+x];	
			uint8_t bytes[3] = {
				//0x00FF00FF
				(pixel_color >> 0) & 0xFF,
				(pixel_color >> 8) & 0xFF,
				(pixel_color >> 16) & 0xFF 
			};
			fwrite(bytes, sizeof(bytes), 1, f);
		}
	}
	fclose(f);
	free(image);
	return 1;
	
}


int sqr_dist(int x1, int y1, int x2, int y2){
	return (y2-y1)*(y2-y1) + (x2-x1)*(x2-x1);
}
