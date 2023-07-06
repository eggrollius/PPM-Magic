#include <stdint.h>
/***HELPER FUNCTIONS***/
int sqr_dist(int x1, int y1, int x2, int y2);
void swap(int *p1, int *p2);
/***INIT FUNCTIONS***/
int create_image(int w, int h);
/***FILE IO FUNCTIONS***/
int save_image(const char *file_path);
/***2D PRIMITIVES***/
void draw_circle(int x1, int y1, int r, uint32_t c);
void draw_rect(int x1, int y1, int x2, int y2, uint32_t c);
void draw_line(int x1, int y1, int x2, int y2, uint32_t c);
/***CANVAS FUNCTIONS***/
void fill_image(uint32_t c);
