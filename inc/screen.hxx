
#include <vec.hxx>
#include <cstdio>

#ifndef screen_class
#define screen_class

class screen {
  
  public:
    // screen dimensions
    int screen_width, screen_height;
    float x_origin, y_origin, z_origin;

    // screen co-ordinates
    vec position;

    // screen constants
    float K2;
    float K1;

    float * output;
    float * z_buffer;

    screen ( float K1, float K2, int screen_width, int screen_height ){

      position = vec( 0, 0, K2 );
      this->K1 = K1;
      this->K2 = K2;
      this->screen_width = screen_width;
      this->screen_height = screen_height;

      output = new float[screen_width*screen_height]();
      z_buffer = new float[screen_width*screen_height]();

    }

    void set_size( int screen_width, int screen_height );
    void set_constants( float K2 );
    void set_constants( float K1, float K2 );

    vec project( const vec & point );

    void clear_screen();
    void reset_frame();
    void draw_frame();



};

#endif
