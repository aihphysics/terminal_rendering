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

void screen::reset_frame(){
  for ( int y = 0; y < screen_height; y++ ){
    for ( int x = 0; x < screen_width; x++ ){
      output[screen_width * y + x] = ' ';
      z_buffer[screen_width * y + x] = 0;
    }
  }
  printf( "\x1b[H" );
}

void screen::clear_screen(){
  for ( int y = 0; y < screen_height; y++ ){
    for ( int x = 0; x < screen_width; x++ ){
      putchar(' ');
    }
  }
  printf( "\x1b[H" );
}

void screen::draw_frame(){
  printf( "\x1b[H" );
  for ( int y = 0; y < screen_height; y++ ){
    for ( int x = 0; x < screen_width; x++ ){
      putchar( output[screen_width * y + x] );
      output[screen_width * y + x] = ' ';
      z_buffer[screen_width * y + x] = 0;
    }
  }
}
