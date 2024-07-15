#include <math.h>
#include <vector>
#include <vec.hxx>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>

/* 
 * enum for types of entries in an obj file
 * 
 * Limited types of entry, simplified obj compatibility
 */
enum obj_entry{
  vertex,
  face,
  pass
};


/*
 * Split Strings
 *
 * String splitting function
 *
 * @parameter split_line reference to vector for putting the split strings
 * @parameter string string to be split
 * @parameter delim delimiter to split string by
 */
void split_string(std::vector<std::string> & split_line, const std::string & string, std::string delim ){
  std::istringstream str_stream{ string };
  std::string token = "";
  while( getline( str_stream, token, *( delim.c_str() ) ) ){ 
    split_line.push_back(token);
  }
}

/*
 * obj_hash
 * 
 * Simplified hashing function for simple obj files
 * Will throw for unsupported obj file
 *
 * @parameter str input string, pre-split, just the indicator
 * @return enum for the type of line
 */
obj_entry obj_hash( const std::string & str ){
  if ( str == "v" ){ return vertex; }
  if ( str == "f" ){ return face; }
  else { return pass; }
  //else { throw std::runtime_error("Unsupported .obj format"); }
}


#ifndef obj_class
#define obj_class

class obj {

  private:
    std::vector<vec> vertices;
    std::vector<std::vector<int>> faces;

  public:

    obj( const std::string & filepath ){
      std::ifstream input( filepath );
      
      std::string line = "";
      while ( std::getline( input, line ) ){

        std::vector< std::string > split = {};
        split.reserve( 10 );
        split_string( split, line, " " );
        if ( split.size() <= 4 ){ continue; }
        switch ( obj_hash( split.at( 0 ) ) ){
          case( vertex ):
            vertices.push_back( vec( std::stof( split.at(1) ), std::stof( split.at(2) ), std::stof( split.at( 3 ) ) ) );
          case( face ):
            faces.push_back( std::vector<int>{ std::stoi( split.at(1) ), std::stoi( split.at(2) ), std::stoi( split.at( 3 ) ) } );
          case( pass ):
            continue;
        }
      }
    };

};

#endif
