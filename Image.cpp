// Project UID af1f95f547e44c8ea88730dfb185559d

#include <cassert>
#include "Image.h"
#include "Matrix.h"

using namespace std;

// REQUIRES: img points to an Image
//           0 < width && width <= MAX_MATRIX_WIDTH
//           0 < height && height <= MAX_MATRIX_HEIGHT
// MODIFIES: *img
// EFFECTS:  Initializes the Image with the given width and height.
// NOTE:     Do NOT use new or delete here.
void Image_init(Image* img, int width, int height) {
  img->width = width;
  img->height = height;
}

// REQUIRES: img points to an Image
//           is contains an image in PPM format without comments
//           (any kind of whitespace is ok)
// MODIFIES: *img
// EFFECTS:  Initializes the Image by reading in an image in PPM format
//           from the given input stream.
// NOTE:     See the project spec for a discussion of PPM format.
// NOTE:     Do NOT use new or delete here.
void Image_init(Image* img, std::istream& is) {
  int idx=0;
  string x;
  int y;
  is >> x;
  is >> img->width >> img->height;
  is >> y;
  while(!is.eof())
   {
    is >> img->red_channel.data[idx];
    is >> img->green_channel.data[idx];
    is >> img->blue_channel.data[idx];
    idx+=1;
   }
}

// REQUIRES: img points to a valid Image
// EFFECTS:  Writes the image to the given output stream in PPM format.
//           You must use the kind of whitespace specified here.
//           First, prints out the header for the image like this:
//             P3 [newline]
//             WIDTH [space] HEIGHT [newline]
//             255 [newline]
//           Next, prints out the rows of the image, each followed by a
//           newline. Each pixel in a row is printed as three ints
//           for its red, green, and blue components, in that order. Each
//           int is followed by a space. This means that there will be an
//           "extra" space at the end of each line. See the project spec
//           for an example.
void Image_print(const Image* img, std::ostream& os) {
  os << "P3" << '\n'<< img->width << " "<< img->height << '\n' << "255" << '\n'; 
  for(int i = 0; i < img->height; i ++)
  {
        for(int j = 0; j < img->width; j ++)
      {
        int idx = (img->width * i) + j;
        os << img->red_channel.data[idx] <<" ";
        os << img->green_channel.data[idx] <<" ";
        os << img->blue_channel.data[idx] <<" ";
      }
      os <<'\n';
  }
}

// REQUIRES: img points to a valid Image
// EFFECTS:  Returns the width of the Image.
int Image_width(const Image* img) {
  return img->width; // TODO Replace with your implementation!
}

// REQUIRES: img points to a valid Image
// EFFECTS:  Returns the height of the Image.
int Image_height(const Image* img) {
  return img->height; // TODO Replace with your implementation!
}

// REQUIRES: img points to a valid Image
//           0 <= row && row < Image_height(img)
//           0 <= column && column < Image_width(img)
// EFFECTS:  Returns the pixel in the Image at the given row and column.
Pixel Image_get_pixel(const Image* img, int row, int column) {
  int idx = (img->width * row) + column;
  Pixel p;
  p.r = img->red_channel.data[idx];
  p.g = img->green_channel.data[idx];
  p.b = img->blue_channel.data[idx];
  return p;
}

// REQUIRES: img points to a valid Image
//           0 <= row && row < Image_height(img)
//           0 <= column && column < Image_width(img)
// MODIFIES: *img
// EFFECTS:  Sets the pixel in the Image at the given row and column
//           to the given color.
void Image_set_pixel(Image* img, int row, int column, Pixel color) {
   int idx = (img->width * row) + column;
  img->red_channel.data[idx]=color.r;
  img->green_channel.data[idx]=color.g;
  img->blue_channel.data[idx]=color.b;
}

// REQUIRES: img points to a valid Image
// MODIFIES: *img
// EFFECTS:  Sets each pixel in the image to the given color.
void Image_fill(Image* img, Pixel color) {
 for( int idx =0; idx < img->width * img->height ; idx ++)
    {
     img->red_channel.data[idx] = color.r;
     img->green_channel.data[idx] =color.g;
     img->blue_channel.data[idx] =color.b;
    }

}
