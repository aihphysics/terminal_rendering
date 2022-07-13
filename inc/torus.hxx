#include <math.h>
#include <stdio.h>
#include <renderable.hxx>

class torus : public renderable {
  private:
    const float screen_x = screen_width;
    const float screen_y = screen_height;
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

    void draw(char (&output)[(int) screen_width][(int) screen_height], float (&z_buffer)[(int) screen_width][(int) screen_height]) override;
    void draw(char (&output)[(int) screen_width][(int) screen_height], float (&z_buffer)[(int) screen_width][(int) screen_height], float A, float B);

};
