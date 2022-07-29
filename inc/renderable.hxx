#include <math.h>
#include <common.hxx>
#include <light.hxx>
#include <screen.hxx>


#ifndef renderable_class
#define renderable_class

class renderable {

  protected:
    float x_centre, y_centre, z_centre;
    float x_rotation, y_rotation, z_rotation;
    float x_velocity, y_velocity, z_velocity;
    float x_acceleration, y_acceleration, z_acceleration;

    float v_rx, v_ry, v_rz;
    light * light_source;
    screen * terminal;

  public:
    renderable(){ 
      x_centre = 0, y_centre = 0, z_centre = 0;
    }

    virtual void draw() = 0;
    virtual void draw( float * output, float * z_buffer ) = 0;

    void set_rotation( float x_rotation, float y_rotation, float z_rotation ){
      this->x_rotation = x_rotation;
      this->y_rotation = y_rotation;
      this->z_rotation = z_rotation;
    }

};

#endif
