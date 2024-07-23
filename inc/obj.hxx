#include <math.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <stdexcept>
#include <functional>

#include <common.hxx>
#include <vec.hxx>

#ifndef obj_class
#define obj_class

/* 
 * enum for types of entries in an obj file
 * 
 * Limited types of entry, simplified obj compatibility
 */
enum file_entry {
  vertex,
  face,
  loop,
  pass
};



/*
 * Split Strings
 *
 * String splitting function
 *
 * @param split_line reference to vector for putting the split strings
 * @param string string to be split
 * @param delim delimiter to split string by
 */
void split_string(std::vector<std::string> & split_line, const std::string & string, std::string delim );

/*
 * obj_hash
 * 
 * Simplified hashing function for simple obj files
 *
 * @param str input string, pre-split, just the indicator
 * @return enum for the type of line
 */
file_entry obj_hash( const std::string & str );

/*
 * stl_hash
 * 
 * Hashing function for stl file lines
 *
 * @param str input string, pre-split, just the indicator
 * @return enum for the type of line
 */
file_entry stl_hash( const std::string & str );

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

    // position and rotation of the object
    vec centre, rotation;

    // lorentz boost along x-axis
    float beta_x;

    /* 
     * Parse file
     *
     * parser for both obj and stl files
     *
     * @param input input file stream
     * @param hash function for this filetype
     */
    void parse_file( std::ifstream & input, std::function<file_entry(const std::string & str)> hash ){
      std::string line = "";
      std::vector< std::string > split = {};
      split.reserve( 10 );
      std::vector<int> current_face = {};
      while ( std::getline( input, line ) ){
        split.clear();
        split_string( split, line, " " );
        line = "";
        if ( split.size() <= 3 ){ continue; }
        switch ( hash( split.at( 0 ) ) ){
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
          case( loop ):
            std::runtime_error( "stl parsing not yet implemented" );            
          case( pass ):
            continue;
        }
      }
    }

  public:

    /* 
     * Object constructor
     * Parses files, currently only processes vertex and face information data.
     *
     * @param filepath Location of file containing a 3d object.
     */
    obj( const std::string & filepath ){

      this->filepath = filepath;
      std::ifstream input( filepath );
      
      std::function< file_entry( const std::string & str )> hash;
      if ( filepath.find( ".stl" ) != std::string::npos ){
        hash = stl_hash;
      } else if ( filepath.find( ".obj" ) != std::string::npos ){
        hash = obj_hash;
      } else {
        throw std::runtime_error( "unsupported filetype" );
      }
      
      parse_file( input, hash );

      return; 
    };

    /*
     * Print vertices and face indices
     * Function to output parsed object to stdouut
     */
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

    /* 
     * Rotate object
     * Sets 3d rotation of object.
     * @param x_rotation rotation around x axis in radians
     * @param y_rotation rotation around y axis in radians
     * @param z_rotation rotation around z axis in radians
     */
    void set_rotation( float x_rotation, float y_rotation, float z_rotation ){
      this->rotation = vec(x_rotation, y_rotation, z_rotation);
    }


    /* 
     * Rotate object
     * Sets 3d rotation of object.
     * @param rotation rotation vector in radians around each of the axes
     */
    void set_rotation( vec & rotation ){
      this->rotation = rotation;
    }

    /* 
     * Position object
     * Sets 3d centre of the object.
     * @param x_position position around x axis in radians
     * @param y_position position around y axis in radians
     * @param z_position position around z axis in radians
     */
    void set_position( float x_position, float y_position, float z_position ){
      this->centre = vec(x_position, y_position, z_position);
    }

    /* 
     * Position object
     * Sets 3d centre of object.
     * @param position coordinate vector to centre the object on.
     */
    void set_position( vec & position ){
      this->centre = position;
    }

    /*
     * Friend class of screen
     * To allow rendering of the object to the buffers.
     */
    friend screen;
  
};

#endif
