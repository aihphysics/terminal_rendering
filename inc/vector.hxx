#include <common.hxx>

#include <point.hxx>

#ifndef euch_vector_class
#define euch_vector_class

class euch_vector : public point {

  public:
 
    euch_vector() : point(){};
    euch_vector( float x, float y, float z ) : point( x, y, z ){}
    

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
