#include <iostream>

#define PI 3.14 // por favor no lo hagan

//using namespace std;
int main()
{

  std::cout << "hello world" << std::endl;


  int a; // declaracion
  a = 4; // asignacion

  int b {5}; // decl+ inicializacion
  int c = 6; // un poquito pasado de moda
  

  std::cout << a+b+c << std::endl;
  c = 42; // reasignando
  std::cout << a+b+c << std::endl;
  const float pi {3.1415926};
  std::cout << pi << std::endl;
  std::cout << PI << std::endl;
  //pi = 3.0;
  //std::cout << pi << std::endl;


  
  
  return 0;
}



