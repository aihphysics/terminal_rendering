#include <math.h>
#include <renderable.hxx>

#ifndef line_class
#define line_class

class line : public renderable{
  public:
    float len;
    line *connections[15];
    line (float l, float x, float y, float z){
      len = l; x_c = x; y_c = y; z_c = z;
    }
    void add_connection(line next_line);// need to add checking that this connects to the current ends of a line;
};

#endif
