#include <math.h>

#ifndef rend_obj
#define rend_obj
#include <renderable.hxx>
#endif

class sphere : public renderable{
  private:
    float rad;
    const float screen_x = 237;
    const float screen_y = 57;


  public:
    sphere(float r, float x, float y, float z, light * main_light){
      rad = r; x_c = x; y_c = y; z_c = z;  
      light_source = main_light;
    }

    void set_constants(float K2){
      s_K2 = K2;
      //s_K1 = 57*K2*1/(8*(rad));
      s_K1 = screen_y*K2*(1/0.8);
    }

    void draw(char (&output)[237][57], float (&z_buffer)[237][57]);
};
