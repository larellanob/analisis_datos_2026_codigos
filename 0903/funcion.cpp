#include <iostream>

int suma(int a, int b) {
  std::cout << "suma entera\n";
  return a+b;
}

float suma(float a, float b, char c) {
  std::cout << "suma float (3 args)\n";
  std::cout << c << std::endl;
  return a+b+c;
}

void helloworld() {
  std::cout << "helo world" << std::endl;
}

int main() {

  int resulti {suma(3,2)};
  std::cout << resulti << std::endl;

  std::cout << suma(3.0, 2.1, 'j') << std::endl;

  helloworld();
  return 0;
}
