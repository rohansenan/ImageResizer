// Project UID af1f95f547e44c8ea88730dfb185559d

#include <iostream>
#include "Image.h"
# include <fstream>
#include "processing.h"
#include "Matrix.h"
using namespace std;

int main(int argc, char *argv[])
{   
    string input = argv[1];
    string output = argv[2];
    int width = atoi(argv[3]);
    int height;
    Image* img = new Image;
    ifstream fin(input);
    
    

    if (!fin.is_open())
    {
        cout << "Error opening file: " << input << endl;
        return 1;
    }

    Image_init(img, fin);
    switch(argc)
    {
        case 4:  height = img->height;
        break;

        case 5:  height = atoi(argv[4]);
        break;

        default: cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
     << "WIDTH and HEIGHT must be less than or equal to original" << endl;
     return 1; 
    }
    
    
    if (width<0||width>img->width||height<0||height>img->height)
    {
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
     << "WIDTH and HEIGHT must be less than or equal to original" << endl;
     return 1; 
    }

    ofstream fout(output);
    if (!fout.is_open())
    {
        cout << "Error opening file: " << output << endl;
        return 1;
    }
    

    seam_carve(img, width, height);
    Image_print(img, fout);

}