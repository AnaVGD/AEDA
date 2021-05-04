#include "AB.hpp"

#include <iostream>

using Clave = int;

int menu();

int main(){

  AB<Clave> tree;
  Clave clave;
  
  int fin = 0;
  
  while (fin == 0) {
   
    switch ( menu()) {
      case 1:
        std::cout << "Introduzca la cable a incertar" << std::endl;
        std::cin >> clave;
        std::cout << std::endl;
        std::cout << "Insertar: " << clave << std::endl;
        tree.inserta(clave);
        tree.imprimir2();
        break;
      case 2:
        std::cout << "Introduzca la cable a buscar" << std::endl;
        std::cin >> clave;
        std::cout << std::endl;
        std::cout << "Buscar: " << clave << std::endl;
        tree.Buscar2(clave);
        std::cout << std::endl;
        tree.imprimir2();
        break;
      case 0:
        fin = 1;
        break;
      default:
        std::cout << "Caracter erroneo" << std::endl;
        break;
    }
  }
}

int menu() {
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "Seleccione las siguientes opciones para el arbol:" << std::endl;
  std::cout << "[0] Salir\n[1] Insertar Clave\n[2] Buscar Clave" << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << std::endl;
  int opciones;
  std::cin >> opciones;
  return opciones;
}