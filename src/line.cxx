#include <line.hxx>

void line::draw(){
  this->draw( terminal->output, terminal->z_buffer );
}

void line::draw(char * output, float * z_buffer ){
  return;
}
