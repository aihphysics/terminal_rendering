#include <screen.hxx>

void screen::set_constants( float K2 ){
  this->K2 = K2;
  this->K1 = screen_width * K2 * ( 1 / 0.8 );
}

void screen::set_constants( float K1, float K2 ){
  this->K1 = K1; 
  this->K2 = K2;
}

void screen::set_size( int screen_width, int screen_height ){
  this->screen_width = screen_width;
  this->screen_height = screen_height;
}
