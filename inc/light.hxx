#ifndef light_obj
#define light_obj

class light{
  public:
    float x_pos, y_pos, z_pos;
    float x_dir, y_dir, z_dir;
    light();
    light(float x, float y, float z);
};

#endif
