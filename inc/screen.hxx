
#include <vec.hxx>
#include <cstdio>
#include <obj.hxx>

#ifndef screen_class
#define screen_class

/*
 * Screen class
 *
 * Contains the buffers the objects are drawn to and the functionality to draw 
 * Contained constants allow positioning of camera and perspective effects.
 */
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

    // buffers for terminal output
    float * output;
    float * z_buffer;

    /*
     * Screen constructor
     *
     * @param K1 first screen constant
     * @param K2 second screen constant
     * @param screen_width width of terminal
     * @param screen_height height of terminal
     */
    screen ( float K1, float K2, int screen_width, int screen_height ){

      position = vec( 0, 0, K2 );
      this->K1 = K1;
      this->K2 = K2;
      this->screen_width = screen_width;
      this->screen_height = screen_height;

      output = new float[screen_width*screen_height]();
      z_buffer = new float[screen_width*screen_height]();

    }

    // resize screen
    void set_size( int screen_width, int screen_height );

    // determine the screen constants
    void set_constants( float K2 );
    void set_constants( float K1, float K2 );

    /*
     * project
     *
     * function to project a point in the object space into the screen space.
     * projection operation is dependent on K1 and K2
     *
     * @param coordinate of point in the object space
     * @return coordinate vector of projected point
     */
    vec project( const vec & point );

    // draw utilities
    void clear_screen();
    void reset_frame();

    /*
     * draw_frame
     *
     * Draw the output buffer to the terminal.
     * Performs splitting of screen space into the 2:1 characters using background information.
     * Grayscale colorisation (lets not get crazy yet)
     * Cleans output and z buffer.
     */
    void draw_frame();


    /*
     * draw
     *
     * Draws an object to the screen space and z buffers.
     * performs projection of a full object into the screen space
     *
     * @param object input object with vertices and faces.
     */
    void draw( const obj & object );

};


#endif
