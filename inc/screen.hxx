
#include <common.hxx>

class screen {
  
  public:
    // screen dimensions
    int screen_x{421}, screen_y{109};
    // origin coordinates, not currently used, should be 0
    float x_origin, y_origin, z_origin;
    // screen co-ordinates
    float x_pos, y_pos, z_pos;
    // screen constants
    float K1, K2;

    screen (float x_width, float y_height, float k_1, float k_2){
      screen_x = x_width; screen_y = y_height;
      x_pos = 0; y_pos = 0; z_pos = 0;
      K1 = k_1; K2 = k_2;
    }
    
    void set_constants(float k_2);
    void set_constants(float k_1,float k_2);
    void assign_object(renderable & object);

};
