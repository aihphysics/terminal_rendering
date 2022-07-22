#include <math.h>
#include <renderable.hxx>

class sphere : public renderable{
  private:
    float radius;

  public:
    sphere(float radius, float x, float y, float z, light * light_source){
      this->radius = rad; 
      this->x = x; 
      this->y = y;
      this->z = z;  
      this->light_source = light_source;
    }

    void draw( char * output, float * z_buffer );

};
