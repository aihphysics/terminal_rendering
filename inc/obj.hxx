#include <math.h>
#include <vector>
#include <vec.hxx>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>

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
}


#ifndef obj_class
#define obj_class

/*
 * obj
 *
 * Class for importing and preparing .obj files for rendering
 */


class obj {

  private:
    std::string filepath;
    std::vector<vec> vertices;
    std::vector<std::vector<int>> faces;


  public:

    obj( const std::string & filepath ){
      this->filepath = filepath;
      std::ifstream input( filepath );

      std::string line = "";
      std::vector< std::string > split = {};
      split.reserve( 10 );
      std::vector<int> current_face = {};
      while ( std::getline( input, line ) ){
        split.clear();
        split_string( split, line, " " );
        line = "";
        if ( split.size() <= 3 ){ continue; }
        switch ( obj_hash( split.at( 0 ) ) ){
          case( vertex ):
            vertices.push_back( vec( std::stof( split.at(1) ), std::stof( split.at(2) ), std::stof( split.at( 3 ) ) ) );
            break;
          case( face ):
            current_face.clear();
            current_face.reserve( split.size()-1 );
            std::transform( split.begin()+1, split.end(), std::back_inserter( current_face ),
                [](const std::string & str){ return std::stoi( str ); } );
            faces.push_back( std::move(current_face) );
            break;
          case( pass ):
            continue;
        }
      }
    };

    void print(){
      std::cout << "Filepath: " << filepath << "\n" << "Vertices: " << "\n";
      for ( vec & vertex : vertices ){ std::cout << std::setw(4 ) << vertex << "\n"; }
      std::cout << std::setw(0 ) << "Faces: " << "\n"; 
      for ( const std::vector<int> & face: faces ){
        std::cout << std::setw(4 );
        for ( const int & idx : face ){ std::cout << idx  << " "; }
        std::cout << "\n";
      }
      
      std::cout << std::flush;
    }

};

#endif
