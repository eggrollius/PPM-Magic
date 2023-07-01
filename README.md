# PPM Magic C Image Library Documentation

The C Image Library is a lightweight library that provides functions for creating and manipulating PPM (Portable Pixmap) images. It allows you to draw shapes, lines, and fill the image with colors. The library provides the flexibility to save the generated images to a file in PPM format.

## Table of Contents

- [Library Functions](#library-functions)
  - [create_image](#create_image)
  - [fill_image](#fill_image)
  - [draw_rect](#draw_rect)
  - [draw_circle](#draw_circle)
  - [draw_line](#draw_line)
  - [save_image](#save_image)
- [Helper Functions](#helper-functions)
  - [sqr_dist](#sqr_dist)
  - [swap](#swap)

## Library Functions

### `int create_image(int width, int height)`

This function creates a new image with the specified width and height. It allocates memory for the image pixels and sets the global variables `w` (image width) and `h` (image height) accordingly.

- Parameters:
  - `width`: Width of the image in pixels.
  - `height`: Height of the image in pixels.
- Returns:
  - `1` if the image creation was successful.
  - `-1` if memory allocation failed.

### `void fill_image(uint32_t c)`

This function fills the entire image with the specified color. Each pixel in the image is set to the given color.

- Parameters:
  - `c`: Color value to fill the image with.

### `void draw_rect(int x1, int y1, int x2, int y2, uint32_t c)`

This function draws a rectangle on the image, specified by the top-left corner `(x1, y1)` and the bottom-right corner `(x2, y2)`. The rectangle is filled with the specified color.

- Parameters:
  - `x1`: X-coordinate of the top-left corner of the rectangle.
  - `y1`: Y-coordinate of the top-left corner of the rectangle.
  - `x2`: X-coordinate of the bottom-right corner of the rectangle.
  - `y2`: Y-coordinate of the bottom-right corner of the rectangle.
  - `c`: Color value to fill the rectangle with.

### `void draw_circle(int x1, int y1, int r, uint32_t c)`

This function draws a circle on the image, centered at `(x1, y1)` with the specified radius `r`. The circle is filled with the specified color.

- Parameters:
  - `x1`: X-coordinate of the center of the circle.
  - `y1`: Y-coordinate of the center of the circle.
  - `r`: Radius of the circle.
  - `c`: Color value to fill the circle with.

### `void draw_line(int x1, int y1, int x2, int y2, uint32_t c)`

This function draws a line on the image, connecting the points `(x1, y1)` and `(x2, y2)`. The line is drawn using Bresenham's algorithm and is colored with the specified color.

- Parameters:
  - `x1`: X-coordinate of the starting point of the line.
  - `y1`: Y-coordinate of the starting point of the line.
  - `x2`: X-coordinate of the ending point of the line.
  - `y2`: Y-coordinate of the ending point of the line.
  - `c`: Color value to draw the line with.

### `int save

_image(const char *file_path)`

This function saves the current image to a file in PPM format. It writes the image data as a binary PPM file with a header specifying the image width, height, and color depth. The image pixels are stored row by row.

- Parameters:
  - `file_path`: Path to the file where the image should be saved.
- Returns:
  - `1` if the image was successfully saved.
  - `-1` if there was an error opening the file.

## Helper Functions

### `int sqr_dist(int x1, int y1, int x2, int y2)`

This function calculates the squared distance between two points `(x1, y1)` and `(x2, y2)`.

- Parameters:
  - `x1`: X-coordinate of the first point.
  - `y1`: Y-coordinate of the first point.
  - `x2`: X-coordinate of the second point.
  - `y2`: Y-coordinate of the second point.
- Returns:
  - Squared distance between the two points.

### `void swap(int *p1, int *p2)`

This function swaps the values of two integers using a temporary variable.

- Parameters:
  - `p1`: Pointer to the first integer.
  - `p2`: Pointer to the second integer.

---

That's the documentation for your C Image Library! You can use this as a reference to understand the library's functions and how to use them in your projects.
