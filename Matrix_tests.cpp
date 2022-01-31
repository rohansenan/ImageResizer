// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Matrix_test_helpers.h"
#include "unit_test_framework.h"

using namespace std;

// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill_basic) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory


  const int width = 3;
  const int height = 5;
  const int value = 42;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}

// ADD YOUR TESTS HERE
// You are encouraged to use any functions from Matrix_test_helpers.h as needed.
TEST(test_matrix_width_and_height)
{
  Matrix *mat = new Matrix;

  Matrix_init(mat, 5, 3);

  ASSERT_EQUAL(Matrix_width(mat), 5);
  ASSERT_EQUAL(Matrix_height(mat), 3);

  delete mat;
}

TEST(test_matrix_row_and_column)
{
  Matrix *mat = new Matrix;

  Matrix_init(mat, 5, 3);
  Matrix_fill(mat, 12);
  int *ptr = mat->data + 3;
  int *ptr2 = mat->data + 7;

  ASSERT_EQUAL(Matrix_row(mat, ptr), 0);
  ASSERT_EQUAL(Matrix_column(mat, ptr), 3);

  ASSERT_EQUAL(Matrix_row(mat, ptr2), 1);
  ASSERT_EQUAL(Matrix_column(mat, ptr2), 2);

  delete mat;
}

TEST(test_matrix_at)
{
  Matrix *mat = new Matrix;

  Matrix_init(mat, 5, 3);
  Matrix_fill(mat, 0);
  mat->data[7] = 12;
  int *ptr = mat->data + 7;
  
  ASSERT_EQUAL(*Matrix_at(mat, Matrix_row(mat, ptr), Matrix_column(mat, ptr)), 12);
  ASSERT_EQUAL(Matrix_at(mat, Matrix_row(mat, ptr), Matrix_column(mat, ptr)), ptr);

  delete mat;
}

TEST(test_matrix_fill_border)
{
  Matrix *mat = new Matrix;

  Matrix_init(mat, 5, 3);
  Matrix_fill(mat, 0);
  Matrix_fill_border(mat, 12);
  for (int i = 0; i < mat->height; ++i)
  {
    for (int j = 0; j < mat->width; ++j)
    {
      if (i == 0 || i == mat->height - 1 || j == 0 || j == mat->width -1)
      {
        ASSERT_EQUAL(*Matrix_at(mat, i, j), 12);
      }
      else
      {
        ASSERT_EQUAL(*Matrix_at(mat, i, j), 0);
      }
    }
  }
  
  delete mat;
}

TEST(test_matrix_max)
{
  Matrix *mat = new Matrix;

  Matrix_init(mat, 5, 3);
  Matrix_fill(mat, 0);
  *Matrix_at(mat, 1, 3) = 12;
  *Matrix_at(mat, 0, 0) = 9;
  ASSERT_EQUAL(Matrix_max(mat), 12);

  delete mat;
}

TEST(test_column_of_min_value)
{
  Matrix *mat = new Matrix;

  Matrix_init(mat, 5, 3);
  Matrix_fill(mat, 0);

}

// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
