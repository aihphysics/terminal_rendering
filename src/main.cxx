#include <main.hxx>

#include <sphere.hxx>
#include <torus.hxx>

#include <chrono>

using namespace std::chrono_literals;

//const int screen_x = 237;
//const int screen_y = 57;

const int screen_x = 421;
const int screen_y = 109;


//const float K1 = screen_x*K2*3/(8*(R1+R2));
//const float K2 = 1000;
const float K2 = 50;
//const float K1 = screen_y*K2*1/0.4;


void loop(torus & tor, sphere & sph, char (&out)[421][109], float (&z)[421][109]){

  for (int i = 0; i < 1e30; i++){
  
    tor.draw(out, z,i/20.0,i/20.0);
    sph.draw(out, z);

    printf("\x1b[H");
    for (int j = 0; j < screen_y; j++) {
      for (int i = 0; i < screen_x; i++) {
        putchar(out[i][j]);
      }
      putchar('\n');
    }

    // timing;
    std::this_thread::sleep_for(100ms);
    // clear
    std::fill_n(&out[0][0], sizeof(out)/sizeof(out[0][0]), ' ');
    std::fill_n(&z[0][0], sizeof(z)/sizeof(z[0][0]),0);

  }

}



int main(int argc, char * argv[], char * env[]){

  // create and fill buffers
  char output[screen_x][screen_y];
  float z_buffer[screen_x][screen_y];
	std::fill_n(&output[0][0], sizeof(output)/sizeof(output[0][0]), ' ');
	std::fill_n(&z_buffer[0][0], sizeof(z_buffer)/sizeof(z_buffer[0][0]),0);

  // create timers
  std::chrono::system_clock::time_point start;
  std::chrono::system_clock::time_point check;
  double ms;

  light light_source(0,1,-1);

  // create objects
  torus orbiting_torus(   0.3/25.0,   6.0/25.0);

  sphere test_sphere(  3.3/25.0,   0.0,  0.0,  0.0,    &light_source);
  //sphere central_sphere(  3.3/25.0,   0.0,  0.0,  0.0,    &light_source);
  //sphere upper_sphere(    3.3/25.0,   0.0,  0.0,  0.0,    &light_source);
  //sphere lower_sphere(    3.3/25.0,  -0.5,  0.0,  0.0,    &light_source);
  //central_sphere.set_constants(K2);
  //upper_sphere.set_constants(K2);
  //lower_sphere.set_constants(K2);
  orbiting_torus.set_constants(K2);
  test_sphere.set_constants(K2);
  //std::vector<renderable*> objects;
  //objects.push_back(&orbiting_torus);
  //objects.push_back(&central_sphere);
  
  std::thread ex_loop(loop, std::ref(orbiting_torus),std::ref(test_sphere), std::ref(output),std::ref(z_buffer));

  ex_loop.join();



  
  // start loop
//  for (int i = 0; i < 1e10; i++){
//
//    //for (renderable * obj : objects){
//    //  std::cout << "starts" << std::endl;
//    //  //obj->draw(output,z_buffer);
//    //  //orbiting_torus.draw(output,z_buffer,i/20.0,i/20.0);
//    //}
//    //central_sphere.draw(output, z_buffer);
//    //upper_sphere.draw(output, z_buffer);
//    //lower_sphere.draw(output, z_buffer);
//
//    orbiting_torus.draw(output,z_buffer,i/20.0,i/20.0);
//    test_sphere.draw(output,z_buffer);
//
//    //central_sphere.draw(output,z_buffer);
//    //upper_sphere.draw(output,z_buffer);
//    //lower_sphere.draw(output,z_buffer);
//
//    printf("\x1b[H");
//    for (int j = 0; j < screen_y; j++) {
//      for (int i = 0; i < screen_x; i++) {
//        putchar(output[i][j]);
//      }
//      putchar('\n');
//    }
//
//    // timing loop;
//    start  = std::chrono::high_resolution_clock::now();
//    do{
//      check  = std::chrono::high_resolution_clock::now();
//      ms = std::chrono::duration_cast<std::chrono::milliseconds>(check - start).count();
//    } while ( ms < 100);
//    std::fill_n(&output[0][0], sizeof(output)/sizeof(output[0][0]), ' ');
//	  std::fill_n(&z_buffer[0][0], sizeof(z_buffer)/sizeof(z_buffer[0][0]),0);
//
//  }

 
  return 0;
}

// IDEAS THAT NEED IMPLEMENTED
// PROPER HEADER GUARDS -- DONE
// DISENTANGLE THE TORUS CALCULATIONS 
// LIGHT SOURCES AS AN ARRAY
// L-BUFFER
// RE-EVALUATE CAMERA AT ORIGIN
// ADD USER CONTROL INPUT ON CAMERA
// CREATE ROTATION OBJECTS
// DO LINE ATTACHMENTS
// DO RESOLUTION CALCULATION FOR STEPS
// ADD
