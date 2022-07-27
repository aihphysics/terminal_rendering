#include <renderable.hxx>

#ifndef cylinder_class
#define cylinder_class

class cylinder : public renderable{
  protected:
    float radius;
    float length;

  public:
    cylinder( screen * terminal, light * light_source, float x_centre, float y_centre, float z_centre, float radius, float length ){

      this->x_centre = x_centre;
      this->y_centre = y_centre;
      this->z_centre = z_centre;
      this->length = length;
      this->radius = radius;

    }
    
    void draw( char * output, float * z_buffer );
    void draw();
};

#endif
