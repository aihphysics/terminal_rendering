#include <common.hxx>

#ifndef point_class
#define point_class

class point {

  public:

    float x;
    float y;
    float z;

    point() {
      this->x = 0;
      this->y = 0;
      this->z = 0;
    }

    point( float x, float y, float z) {
      this->x = x;
      this->y = y;
      this->z = z;
    }

    void set_x( float x ){ this->x = x; }
    void set_y( float y ){ this->y = y; }
    void set_z( float z ){ this->z = z; }
    void set_xyz( float x, float y, float z );




};


#endif
