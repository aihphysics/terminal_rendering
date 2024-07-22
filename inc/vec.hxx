#include <iostream>
#include <iomanip>

#ifndef vec_class
#define vec_class

class vec {

  public:
  
    // three coordinates
    float x;
    float y;
    float z;

    // empty constructor
    vec(){
      this->x = 0;
      this->y = 0;
      this->z = 0;
    }

    /*
     * Constructor with values
     *
     * @param x first coordinate
     * @param y second coordinate
     * @param z third coordinate
     */
    vec( float x, float y, float z ){
      this->x = x;
      this->y = y;
      this->z = z;
    }

    // setters for x y and z. Obsolete, not necessary
    void set_x( float x ){ this->x = x; }
    void set_y( float y ){ this->y = y; }
    void set_z( float z ){ this->z = z; }
    void set_xyz( float x, float y, float z );

    // operator overloads with inner and scalar products
    vec operator+( vec & other );
    vec operator-( vec & other );
    vec operator/( double len );
    vec operator*( double len );
    float operator*( vec & other );
    vec & operator+=( const vec & other );
    vec & operator-=( const vec & other );
    vec & operator*=( const vec & other );

    // cross product 
    vec cross( vec & other );

    // friend function for std::cout
    friend std::ostream & operator<<( std::ostream & os, const vec & v );

    // various length returns
    float length();
    float square_length();

    // rotation operators
    void rotate_x ( float x_rotation );
    void rotate_y ( float y_rotation );
    void rotate_z ( float z_rotation );
    void rotate ( float x_rotation, float y_rotation, float z_rotation );
    void rotate ( const vec & rotation );

    // x direction lorentz boost
    void boost_x ( float beta );

    // normalise vector to unit length
    void normalise();

};

#endif
