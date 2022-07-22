
#include <common.hxx>

class screen {
  
  public:

    // screen dimensions
    int screen_width, screen_height;
    float x_origin, y_origin, z_origin;

    // screen co-ordinates
    float x_pos, y_pos, z_pos;

    // screen constants
    float K2;
    float K1;

    char * output;
    char * z_buffer;

    screen (float k_1, float k_2){
      x_pos = 0; y_pos = 0; z_pos = 0;
      K1 = k_1; K2 = k_2;
    }
    
    void set_size(float k_1,float k_2){
    void set_constants(float k_2);
    void set_constants(float k_1,float k_2);
    //void assign_object(renderable & object);

};
