#include <obj.hxx>

void split_string(std::vector<std::string> & split_line, const std::string & string, std::string delim ){
  std::istringstream str_stream{ string };
  std::string token = "";
  while( getline( str_stream, token, *( delim.c_str() ) ) ){ 
    split_line.push_back(token);
  }
}

obj_entry obj_hash( const std::string & str ){
  if ( str == "v" ){ return vertex; }
  if ( str == "f" ){ return face; }
  else { return pass; }
}
