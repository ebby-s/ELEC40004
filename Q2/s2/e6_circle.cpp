#include <iostream>
#include <string>
#include <cmath>

using namespace std;


struct image{
// TODO (e6): complete the definition of this type
    int width;
    int height;
    float *pixels;
};

void image_destroy(image *p)
{
    // TODO(e6) : provide a definition of this function
    delete[] p->pixels;
    delete[] p;
}

void image_set_pixel(image *p, int x, int y, float value)
{
// TODO (e7) : implement me
    *(p->pixels+y*(p->width)+x) = value;
}

float image_get_pixel(image *p, int x, int y)
{
// TODO (e7) : implement me
    return *(p->pixels+y*(p->width)+x);
}



////////////////////////////////////////////////
// Don't change this part.

image *image_create(int width, int height)
{
    // Do not change this function. Your type and functions should be compatible
    // with the values this creates.
    image *res=new image[1];
    
    res->width=width;
    res->height=height;
    res->pixels=new float[width*height];

    // Clear the image
    for(int i=0; i<width*height; i++){
        res->pixels[i]=0;
    }

    return res;
}

int image_width(image *p)
{
    return p->width;
}

int image_height(image *p)
{
    return p->height;
}

void image_draw_circle(image *p, int width, int height, float size)
{
    float pi2 = 6.283185307;
    for(float theta=0; theta < pi2 ; theta += pi2/3000){
        float x=(sin(theta) * 0.9 * size) * width/2 + width/2;
        float y=(cos(theta) * 0.9 * size) * height/2 + height/2; 
        image_set_pixel(p, x, y, 1);
    }
}

void image_write_pgm(image *p)
{
    cout << "P1" << endl;
    cout << image_width(p) << " " << image_height(p) << endl;
    for(int y=0; y<image_height(p); y++){
        for(int x=0; x<image_width(p); x++){
            cout << image_get_pixel(p, x, y) << " ";
        }
        cout << endl;
    }
}


int main()
{
    int w, h;
    cin >> w >> h;

    cerr << "Creating image..." << endl;
    image *i=image_create(w,h);

    cerr << "Drawing circle..." << endl;
    for(float r=1.0; r>=0.1; r-=0.2){
        image_draw_circle(i, w, h, r);
    }

    cerr << "Writing image as pgm..." << endl;
    image_write_pgm(i);

    cerr << "Destroying image..." << endl;
    image_destroy(i);

    cerr << "Done." << endl;
}


