#include <common.hxx>

#ifndef lvector_class
#define lvector_class

class lvector {

  protected:
    float t;
    float x;
    float y;
    float z;

  public:
    lvector(){
      this->t = 0;
      this->x = 0;
      this->y = 0;
      this->z = 0;
    }

    lvector( float t, float x, float y, float z ){
      this->t = t;
      this->x = x;
      this->y = y;
      this->z = z;
    }

};

#endif
