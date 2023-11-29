#include <math.h>
#include <renderable.hxx>

#ifndef line_class
#define line_class

class line : public renderable{

  protected:

    line * connection;
    vector start;
    vector direction;
    vector step;
    double length;

  public:
    line ( screen * terminal, float x_start, float y_start, float z_start, float x_end, float y_end, float z_end ){

      this->terminal = terminal;
      this->start = vector( x_start, y_start, z_start);
      vector end( x_end, y_end, z_end);
      direction = end-start; 
      length = direction.length();
      direction.normalise();
      step = direction/(direction.length()/0.01 );

    }

    void add_connection( line * line );

    void draw();
    void draw( float * output, float * z_buffer );


};

#endif
