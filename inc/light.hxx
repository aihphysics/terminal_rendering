#include <math.h>

#include <euch_vector.hxx>

#ifndef light_class
#define light_class

class light{

  public:
    
    euch_vector light_vec;
    light();
    light(float x_dir, float y_dir, float z_dir);
};

#endif
