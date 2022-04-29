#include <math.h>
#include <light.hxx>
#include <common.hxx>



#ifndef rend_obj
#define rend_obj

class renderable {
  public:
    float x_c, y_c, z_c;
    float v_x, v_y, v_z;
    float a_x, a_y, a_z;
    float r_x, r_y, r_z;
    float v_rx, v_ry, v_rz;
    float s_K1, s_K2;
    light * light_source;
    screen * term;
    renderable(){ 
      x_c = 0, y_c = 0, z_c = 0;
    }
    virtual void draw(char (&output)[421][109], float (&z_buffer)[421][109]) = 0;
};

#endif
