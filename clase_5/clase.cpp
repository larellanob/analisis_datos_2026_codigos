#include <iostream>

class particula {
private:
  // atributos
  float mass;
  float E {0.0};
  float p[3] { 0.0, 0.0, 0.0}; // momentum x,y,z
  float x[3] { 0.0, 0.0, 0.0}; // posicion x,y,z

  // miembros (funciones)
public:
  particula() {};  // constructor (defecto)
  particula(float m ) { mass = m; }; // constructor
  particula(float m0, float E0 ) {
    mass = m0;
    E = E0;
  }; // constructor
  ~particula() {}; // destructor
  // setter y getters
  void set_E(float E0) { E = E0; };
  float get_mass() { return mass; };
  float get_E() { return E; };
  float E_colision(particula p2) {
    std::cout << "colisionamos dos particulas!" << std::endl;
    float E1 = E;
    float E2 = p2.get_E();
    return E1+E2;
  };


  
};

// herencia
// clase lepton derivada de particula
class lepton: public particula {
private:
  float n_leptonico { 1 };
public:
  lepton(float m0, float E0 ) : particula(m0, E0) {
    std::cout << "se ha creado un nuevo lepton" << std::endl;
  }
  float get_lepton() { return n_leptonico; }
};

int main() {
  int a;
  particula p;
  std::cout << p.get_mass() << std::endl;
  std::cout << p.get_E() << std::endl;
  p.set_E(500);
  std::cout << p.get_E() << std::endl;
  
  particula p2(2.3, 700);
  std::cout << p2.get_mass() << std::endl;
  std::cout << p2.get_E() << std::endl;

  particula p3(100, 1000);
  std::cout << p3.get_mass() << std::endl;
  std::cout << p3.get_E() << std::endl;

  std::cout << p2.E_colision(p3) << std::endl;
  std::cout << p3.E_colision(p2) << std::endl;

  //lepton l(105.66, 1000);
  //lepton l; // tenemos constructor por defector
  lepton l(105.66, 1000);
  std::cout << l.get_mass() << std::endl;
  std::cout << l.get_E() << std::endl;
  std::cout << l.get_lepton() << std::endl;
  
  return 0;
}
