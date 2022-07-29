#include <math.h>
#include <renderable.hxx>

#ifndef line_class
#define line_class

class line : public renderable{
  protected:
    float x_start;
    float y_start;
    float z_start;
    float x_end;
    float y_end;
    float z_end;
    line * connections;

  public:
    line ( screen * terminal, float x_start, float y_start, float z_start, float x_end, float y_end, float z_end ){
      this->terminal = terminal;
      this->x_start = x_start;
      this->y_start = y_start;
      this->z_start = z_start;
      this->x_end = x_end;
      this->y_end = y_end;
      this->z_end = z_end;
      //this->connections = new line[3];
    }
    void add_connection( line * line );
    void draw();
    void draw( float * output, float * z_buffer );


};

#endif
