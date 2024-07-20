#include <math.h>
#include <vec.hxx>

vec vec::operator+( vec & other ){

  return vec( this->x + other.x, this->y + other.y, this->z + other.z );

}

vec vec::operator-( vec & other ){

  return vec( this->x - other.x, this->y - other.y, this->z - other.z );

}

vec & vec::operator+=( const vec & other ){

  this->x += other.x;
  this->y += other.y;
  this->z += other.z;
  return *this;

}

vec & vec::operator-=( const vec & other ){

  this->x -= other.x;
  this->y -= other.y;
  this->z -= other.z;
  return *this;

}

float vec::operator*( vec & other ){

  return (this->x*other.x + this->y*other.y + this->z*other.z);

}
vec vec::operator*( double len ){

  return vec( this->x*len, this->y*len, this->z*len );
}

vec vec::operator/( double len ){

  return vec( this->x/len, this->y/len, this->z/len );

}

vec vec::cross( vec & other ){

  float x_result = this->y*other.z - this->z*other.y;
  float y_result = this->z*other.x - this->x*other.z;
  float z_result = this->x*other.y - this->y*other.x;

  return vec( x_result, y_result, z_result );

}


std::ostream & operator<<( std::ostream & os, const vec & v ){
  os << std::setprecision(3) <<  "(" << v.x << "," << v.y << "," << v.z << ")";
  return os;
}

float vec::length(){

    return std::sqrt(this->x*this->x + this->y*this->y + this->z*this->z);

}

float vec::square_length(){

    return (this->x*this->x + this->y*this->y + this->z*this->z);

}

void vec::normalise(){

  float norm = this->length();
  this->x /= norm;
  this->y /= norm;
  this->z /= norm;

}

void vec::rotate_x( float x_rotation ){

  float y_temp;
  y_temp =  this->y*cos(x_rotation) + this->z*sin(x_rotation);
  z = -this->y*sin(x_rotation) + this->z*cos(x_rotation);
  y = y_temp;

}

void vec::rotate_y( float y_rotation ){

  float x_temp;
  x_temp =  this->x*cos(y_rotation) + this->z*sin(y_rotation);
  z = -this->x*sin(y_rotation) + this->z*cos(y_rotation);
  x = x_temp;

}

void vec::rotate_z( float z_rotation ){

  float x_temp;
  x_temp =  this->x*cos(z_rotation) + this->y*sin(z_rotation);
  y = -this->x*sin(z_rotation) + this->y*cos(z_rotation);
  x = x_temp;

}

void vec::rotate(float x_rotation, float y_rotation, float z_rotation   ){
  rotate( vec( x_rotation, y_rotation, z_rotation ) );
}


void vec::rotate( const vec & rotation ){
  this->rotate_x( rotation.x );
  this->rotate_y( rotation.x );
  this->rotate_z( rotation.x );
}

void vec::boost_x( float beta ){

  x = x*( sqrt( 1-(beta*beta) ) );

}
