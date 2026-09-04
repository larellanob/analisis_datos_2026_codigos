#include <iostream>

int main() {
  // cast
  int a {4};
  float b;
  b = (float) a; // cast estilo C (viejo)
  float c = static_cast<float>(a); // moderno
  std::cout << c << std::endl;

  float d {14.8};
  int e = static_cast<int>(d);
  std::cout << e << std::endl;
  
}
