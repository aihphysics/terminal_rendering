#include <math.h>
#include <renderable.hxx>

#ifndef cube_class
#define cube_class

class cube : public renderable{

  protected:
    float width;
    float height;
    float depth;

  public:
    cube(screen * terminal, light * light_source, float x_centre, float y_centre, float z_centre, float width, float height, float depth ){
      this->x_centre = x_centre; 
      this->y_centre = y_centre;
      this->z_centre = z_centre;  
      this->width = width;
      this->height = height;
      this->depth = depth;
      this->light_source = light_source;
      this->terminal = terminal;
    }

    void draw();
    void draw( char * output, float * z_buffer );
    void set_rotation( float x_rotation, float y_rotation, float z_rotation ){
      this->x_rotation = x_rotation;
      this->y_rotation = y_rotation;
      this->z_rotation = z_rotation;
    }


};

#endif
