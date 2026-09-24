#include <iostream>

int main() {

  int a {25};
  std::cout << "el valor de a es " << a << std::endl;
  std::cout << "la direccion de memoria de a es " << &a << std::endl;

  //int r {a};
  int &r {a}; // referencia
  std::cout << "r y a " << r << a << std::endl;
  r = 18;
  std::cout << "r y a " << r << " " << a << std::endl;


  int *b; // puntero (de int)
  std::cout << b << std::endl;
  b = &a;
  std::cout << b << std::endl;
  std::cout << b << std::endl;
  std::cout << b << std::endl;
  int *c {&a};
  std::cout << c << std::endl;

  // a que valor apunta b?
  // dereferenciar
  std::cout << *b << std::endl;


  return 0;
  
}
