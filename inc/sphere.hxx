#include <math.h>
#include <renderable.hxx>

#ifndef sphere_class
#define sphere_class

class sphere : public renderable{
  private:
    float radius;

  public:
    sphere(screen * terminal, light * light_source, float radius, float x_centre, float y_centre, float z_centre ){
      this->radius = radius; 
      this->x_centre = x_centre; 
      this->y_centre = y_centre;
      this->z_centre = z_centre;  
      this->light_source = light_source;
      this->terminal = terminal;
    }

    void draw( float * output, float * z_buffer );
    void draw();

};

#endif
