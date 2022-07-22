#include <math.h>
#include <common.hxx>
#include <light.hxx>



#ifndef rend_obj
#define rend_obj

class renderable {

  protected:
    float x, y, z;
    float v_x, v_y, v_z;
    float a_x, a_y, a_z;
    float r_x, r_y, r_z;
    float v_rx, v_ry, v_rz;
    light * light_source;
    screen * terminal;

  public:
    renderable(){ 
      x = 0, y = 0, z = 0;
    }
    virtual void draw( char * output, float * z_buffer ) = 0;

};

#endif
