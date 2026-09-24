#include <iostream>

double by_value(double a) {
  a = a+10.0;
  return a;
}

void by_reference(double &a){
  a = a+10;
}


int main() {
  double a { 3.19948 };

  double b { by_value(a)};

  by_value(3.19948);

  std::cout << a << " " << b << std::endl;

  by_reference(a);
  std::cout << a << std::endl;
  
  return 0;
}
