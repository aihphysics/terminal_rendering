#include <math.h>
#include <stdio.h>
#include <renderable.hxx>

class torus : public renderable {
  private:
    const float screen_x = 421;
    const float screen_y = 109;
    float r_1;
    float r_2;
    float s_K2;
    float s_K1;

  public:
    torus(float r_tube, float r_inner){
      r_1 = r_tube; r_2 = r_inner;
    }
    void set_constants(float K2){
      s_K2 = K2;
      //s_K1 = screen_y*s_K2*1/(4*(r_1+r_2));
      s_K1 = screen_y*s_K2*(1/0.8);
      // torus rmax = 3.3
      // s_K1 = 57 * 100 * 1/(4*3.3) = 431;
      // sphere rmax = 0.1
      // s_K1 = 57 * 100 * 1/0.8 = 7125
      //r_1 + r_2 = 3.3

    }

    void draw(char (&output)[421][109], float (&z_buffer)[421][109]) override;
    void draw(char (&output)[421][109], float (&z_buffer)[421][109], float A, float B);

};
