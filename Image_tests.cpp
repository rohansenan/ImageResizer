// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Image_test_helpers.h"
#include "unit_test_framework.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Sets various pixels in a 2x2 Image and checks
// that Image_print produces the correct output.
TEST(test_print_basic) {
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(img, 2, 2);
  Image_set_pixel(img, 0, 0, red);
  Image_set_pixel(img, 0, 1, green);
  Image_set_pixel(img, 1, 0, blue);
  Image_set_pixel(img, 1, 1, white);

  // Capture our output
  ostringstream s;
  Image_print(img, s);

  // Correct output
  ostringstream correct;
  correct << "P3\n2 2\n255\n";
  correct << "255 0 0 0 255 0 \n";
  correct << "0 0 255 255 255 255 \n";
  ASSERT_EQUAL(s.str(), correct.str());

  delete img; // delete the Image
}

TEST(test_matrix_height_and_width)
{
  Image *img = new Image;

  Image_init(img, 3, 5);

  ASSERT_EQUAL(Image_width(img), 3);
  ASSERT_EQUAL(Image_height(img), 5);

  delete img;
}

TEST(test_image_init_for_inputstream)
{
  string input = "P3 \n 3 \t 5 \t 255 255 0 255 255 255 0 0 0 255 0 0 255 0 255 0 0 0 0 255 255 0 255 255 255 0 0 0 0 0 0 0 0 0 0 0 0";
  std::istringstream ss_input(input);

  Image *img = new Image;

  Image_init(img, ss_input);

  ASSERT_EQUAL(Image_width(img), 3);
  ASSERT_EQUAL(Image_height(img), 5);

  delete img;
}

TEST(test_image_get_pixel)
{
  string input = "P3 \n 3 \t 5 \t 255 255 0 255 255 255 0 0 0 255 0 0 255 0 255 0 0 0 0 255 255 0 255 255 255 0 0 0 0 0 0 0 0 0 0 0 0";
  std::istringstream ss_input(input);

  Image *img = new Image;

  Image_init(img, ss_input);

  Pixel p = Image_get_pixel(img, 1, 1);

  ASSERT_EQUAL(p.r, 0);
  ASSERT_EQUAL(p.g, 255);
  ASSERT_EQUAL(p.b, 0);
}

TEST(test_image_set_pixel)
{
  string input = "P3 \n 3 \t 5 \t 255 255 0 255 255 255 0 0 0 255 0 0 255 0 255 0 0 0 0 255 255 0 255 255 255 0 0 0 0 0 0 0 0 0 0 0 0";
  std::istringstream ss_input(input);

  Image *img = new Image;

  Image_init(img, ss_input);

  Pixel p;
  p.r = 201;
  p.g = 199;
  p.b = 137;

  Image_set_pixel(img, 1, 2, p);

  Pixel color = Image_get_pixel(img, 1, 2);

  ASSERT_EQUAL(color.r, 201);
  ASSERT_EQUAL(color.g, 199);
  ASSERT_EQUAL(color.b, 137);
}

TEST(test_image_fill)
{
  Image *img = new Image;

  Image_init(img, 3, 5);

  Pixel p;
  p.r = 201;
  p.g = 199;
  p.b = 137;

  Image_fill(img, p);

  Pixel color1 = Image_get_pixel(img, 0, 0);
  Pixel color2 = Image_get_pixel(img, 3, 2);
  Pixel color3 = Image_get_pixel(img, 4, 2);

  ASSERT_EQUAL(color1.r, 201);
  ASSERT_EQUAL(color1.g, 199);
  ASSERT_EQUAL(color1.b, 137);

  ASSERT_EQUAL(color2.r, 201);
  ASSERT_EQUAL(color2.g, 199);
  ASSERT_EQUAL(color2.b, 137);

  ASSERT_EQUAL(color3.r, 201);
  ASSERT_EQUAL(color3.g, 199);
  ASSERT_EQUAL(color3.b, 137);
}
// IMPLEMENT YOUR TEST FUNCTIONS HERE
// You are encouraged to use any functions from Image_test_helpers.h as needed.

// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
