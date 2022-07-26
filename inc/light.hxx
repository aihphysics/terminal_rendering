#include <math.h>

#ifndef light_class
#define light_class

class light{
  public:
    float x_pos, y_pos, z_pos;
    float x_dir, y_dir, z_dir;
    light();
    light(float x_dir, float y_dir, float z_dir);
};

#endif
