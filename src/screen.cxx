#include <screen.hxx>

void screen::set_constants( float K2 ){
  this->K2 = K2;
  this->K1 = screen_width * K2 * ( 1 / 0.8 );
}

void screen::set_constants( float K1, float K2 ){
  this->K1 = K1; 
  this->K2 = K2;
}

vec screen::project( const vec & point ){
  float z_inv = 1/point.z;
  int x_p = (int) ((float)this->screen_width/2.0 + (this->K1)*z_inv*point.x);
  int y_p = (int) ((float)this->screen_height/2.0 - (this->K1)*z_inv*point.y);
  return vec( x_p, y_p, z_inv ); 
}

void screen::set_size( int screen_width, int screen_height ){
  this->screen_width = screen_width;
  this->screen_height = screen_height;
}

void screen::reset_frame(){
  for ( int y = 0; y < screen_height; y++ ){
    for ( int x = 0; x < screen_width; x++ ){
      output[screen_width * y + x] = 0;
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

void screen::draw( const obj & object ){
      
  for ( const vec & vertex : object.vertices ){

    vec point = vertex;

    point.rotate( object.rotation );

    point += object.centre;
    point += this->position;
    
    float L = 1.0;

    vec projected = project( point );

    int x_p = projected.x;
    int y_p = projected.y;
    float z_inv = 1.0/projected.z;

    if ( x_p > this->screen_width || y_p > this->screen_height || x_p < 0 || y_p < 0 ) continue;
    if ( z_inv < z_buffer[this->screen_width * y_p + x_p] ) continue;
    z_buffer[this->screen_width * y_p + x_p] = z_inv;
    output[this->screen_width * y_p + x_p] = L;

  }

}

void screen::draw_frame(){

  printf( "\x1b[H" );
  for ( int y = 0; y < screen_height; y+=2 ){
    for ( int x = 0; x < screen_width; x++ ){

      float upper = output[screen_width * y + x];
      float lower = output[screen_width * (y+1) + x];
      int upper_color = ( upper <= 0.0f ) ? 15 : 232 + ( upper*23.0f );
			int lower_color = ( lower <= 0.0f ) ? 15  : 232 + ( lower*23.0f );

			if ( (upper_color == 256 || upper_color == 0) && lower_color == 0 ){ putchar(' '); }
			else printf( "\u001b[48;5;%im\u001b[38;5;%im▄\x1b[0m", upper_color, lower_color );
      output[screen_width * y + x] = 0;
      output[screen_width * (y+1) + x] = 0;
      z_buffer[screen_width * y + x] = 0;
      z_buffer[screen_width * (y+1) + x] = 0;
    }
  }

}

//printf( "▄" );
//range 232-255
//foreground
//\u001b[38;5;CODEm
//background
//\u001b[48;5;CODEm 
