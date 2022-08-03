#include <common.hxx>

#ifndef euch_vector_class
#define euch_vector_class

class euch_vector {

  public:

    float x;
    float y;
    float z;

    euch_vector(){
      this->x = 0;
      this->y = 0;
      this->z = 0;
    }

    euch_vector( float x, float y, float z ){
      this->x = x;
      this->y = y;
      this->z = z;
    }

    void set_x( float x ){ this->x = x; }
    void set_y( float y ){ this->y = y; }
    void set_z( float z ){ this->z = z; }

    void set_xyz( float x, float y, float z );

    euch_vector operator+( euch_vector & other );
    euch_vector operator-( euch_vector & other );
    euch_vector operator/( double len );
    euch_vector operator*( double len );
    float operator*( euch_vector & other );

    euch_vector & operator+=( euch_vector & other );
    euch_vector & operator-=( euch_vector & other );
    euch_vector & operator*=( euch_vector & other );

    euch_vector cross( euch_vector & other );

    float length();
    float square_length();

    void rotate_x ( float x_rotation );
    void rotate_y ( float y_rotation );
    void rotate_z ( float z_rotation );
    void rotate_xyz ( float x_rotation, float y_rotation, float z_rotation );

    void boost_x ( float beta );
    void normalise();


};

#endif
