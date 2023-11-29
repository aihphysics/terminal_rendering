#include <common.hxx>

#include <point.hxx>

#ifndef euch_vector_class
#define euch_vector_class

class vector : public point {

  public:
 
    vector() : point(){};
    vector( float x, float y, float z ) : point( x, y, z ){}
    

    vector operator+( vector & other );
    vector operator-( vector & other );
    vector operator/( double len );
    vector operator*( double len );
    float operator*( vector & other );

    vector & operator+=( vector & other );
    vector & operator-=( vector & other );
    vector & operator*=( vector & other );

    vector cross( vector & other );

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
