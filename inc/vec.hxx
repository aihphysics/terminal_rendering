#include <iostream>
#include <iomanip>

#ifndef vec_class
#define vec_class

class vec {

  public:

    float x;
    float y;
    float z;

    vec(){
      this->x = 0;
      this->y = 0;
      this->z = 0;
    }

    vec( float x, float y, float z ){
      this->x = x;
      this->y = y;
      this->z = z;
    }

    void set_x( float x ){ this->x = x; }
    void set_y( float y ){ this->y = y; }
    void set_z( float z ){ this->z = z; }

    void set_xyz( float x, float y, float z );

    vec operator+( vec & other );
    vec operator-( vec & other );
    vec operator/( double len );
    vec operator*( double len );
    float operator*( vec & other );

    vec & operator+=( const vec & other );
    vec & operator-=( const vec & other );
    vec & operator*=( const vec & other );

    vec cross( vec & other );

    friend std::ostream & operator<<( std::ostream & os, const vec & v );

    float length();
    float square_length();

    void rotate_x ( float x_rotation );
    void rotate_y ( float y_rotation );
    void rotate_z ( float z_rotation );
    void rotate ( float x_rotation, float y_rotation, float z_rotation );
    void rotate ( const vec & rotation );

    void boost_x ( float beta );
    void normalise();

};

#endif
