#include <math.h>
#include <common.hxx>
#include <light.hxx>
#include <screen.hxx>


#ifndef renderable_class
#define renderable_class

class renderable {

  protected:
    float x_centre, y_centre, z_centre;
    float v_x, v_y, v_z;
    float a_x, a_y, a_z;
    float r_x, r_y, r_z;
    float v_rx, v_ry, v_rz;
    light * light_source;
    screen * terminal;

  public:
    renderable(){ 
      x_centre = 0, y_centre = 0, z_centre = 0;
    }
    virtual void draw( char * output, float * z_buffer ) = 0;

};

#endif
