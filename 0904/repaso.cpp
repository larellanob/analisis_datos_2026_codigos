#include <iostream>
#include <cmath>

int cuadrado(int a) {
  std::cout << "cuadrado int\n"; // \n = newline
  return a*a;
}
float cuadrado(float a) {
  std::cout << "cuadrado float" << std::endl;
  return a*a;
}

void cuadrado(float a, float b, float c, float d);
void cuadrado(int, float *);


int main() {

  int a {8};
  float b {3.2};

  cuadrado(a);
  cuadrado(b);
  cuadrado(2,3,4,5);

  // matriz m2
  float arr1[4];
  arr1[0] = -1;
  arr1[1] = 0;
  arr1[2] = -2;
  arr1[3] = 1;

  // matriz m3
  float arr2[4] { 2.1, 0.7, -7.2, 0.6 };

  cuadrado(4,arr1);

  cuadrado(7,arr2);

  return 0;
}

void cuadrado(float a, float b, float c, float d) {
  float a11 { cuadrado(a) + b*c }; // 
  float a12 { a*b + b*d };
  float a21 { c*a + d*c };
  //float a22 { c*b + cuadrado(d) };
  float a22 { c*b + d*d };

  std::cout << a11 << " " << a12 << std::endl;
  std::cout << a21 << " " << a22 << std::endl;

}

void cuadrado(int n, float *arr) {
  pow(n, 0.5);
  // es entero?
  float raiz = pow(n,0.5);
  std::cout << "raiz " << raiz << std::endl;
  std::cout << "floor " << std::floor(raiz) << std::endl;
  if ( raiz != std::floor(raiz) ) {
    std::cout << "no es matriz cuadrada!" << std::endl;
  } else {
    cuadrado(arr[0], arr[1], arr[2], arr[3]);
  }
}
