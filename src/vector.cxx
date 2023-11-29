#include <euch_vector.hxx>
#include <math.h>


euch_vector euch_vector::operator+( euch_vector & other ){

  return euch_vector( this->x + other.x, this->y + other.y, this->z + other.z );

}

euch_vector euch_vector::operator-( euch_vector & other ){

  return euch_vector( this->x - other.x, this->y - other.y, this->z - other.z );

}

euch_vector & euch_vector::operator+=( euch_vector & other ){

  this->x += other.x;
  this->y += other.y;
  this->z += other.z;
  return *this;

}

euch_vector & euch_vector::operator-=( euch_vector & other ){

  this->x -= other.x;
  this->y -= other.y;
  this->z -= other.z;
  return *this;

}

float euch_vector::operator*( euch_vector & other ){

  return (this->x*other.x + this->y*other.y + this->z*other.z);

}
euch_vector euch_vector::operator*( double len ){

  return euch_vector( this->x*len, this->y*len, this->z*len );
}

euch_vector euch_vector::operator/( double len ){

  return euch_vector( this->x/len, this->y/len, this->z/len );

}

euch_vector euch_vector::cross( euch_vector & other ){

  float x_result = this->y*other.z - this->z*other.y;
  float y_result = this->z*other.x - this->x*other.z;
  float z_result = this->x*other.y - this->y*other.x;

  return euch_vector( x_result, y_result, z_result );

}

float euch_vector::length(){

    return std::sqrt(this->x*this->x + this->y*this->y + this->z*this->z);

}

float euch_vector::square_length(){

    return (this->x*this->x + this->y*this->y + this->z*this->z);

}

void euch_vector::normalise(){

  float norm = this->length();
  this->x /= norm;
  this->y /= norm;
  this->z /= norm;

}

void euch_vector::rotate_x( float x_rotation ){

  float y_temp;
  y_temp =  this->y*cos(x_rotation) + this->z*sin(x_rotation);
  z = -this->y*sin(x_rotation) + this->z*cos(x_rotation);
  y = y_temp;

}

void euch_vector::rotate_y( float y_rotation ){

  float x_temp;
  x_temp =  this->x*cos(y_rotation) + this->z*sin(y_rotation);
  z = -this->x*sin(y_rotation) + this->z*cos(y_rotation);
  x = x_temp;

}

void euch_vector::rotate_z( float z_rotation ){

  float x_temp;
  x_temp =  this->x*cos(z_rotation) + this->y*sin(z_rotation);
  y = -this->x*sin(z_rotation) + this->y*cos(z_rotation);
  x = x_temp;

}

void euch_vector::boost_x( float beta ){

  x = x*( sqrt( 1-(beta*beta) ) );

}







