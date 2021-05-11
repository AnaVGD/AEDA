////////////////////////////////////////////////////////////////////////////////
// Copyright 2021
// Universidad de La Laguna
// Escuela superior de Ingeniería y Tecnología
// Grado en igeniería Informática
// Computablidad y Algoritmia
// Autor: Ana Virginia Giambona Díaz
// Correo: alu0101322650@ull.edu.es
// Fecha: 11/05/2021
// Práctica: Arbol Binario de busqueda
// 
////////////////////////////////////////////////////////////////////////////


#include "ABB.hpp"
#include "AB.hpp"

#include <iostream>

using Clave = int;

int menu();

int main(){

  ABB<Clave> tree;
  AB<Clave> arbol;
  Clave clave;
  char opt;
  
  int fin = 0;
  std::cout << "Selecione el tipo de arbol binario" << std::endl;
  std::cout << "[e] Equilibrado\n[b] Busqueda\n[s] Salir" << std::endl;
  std::cin >> opt;
  
  if (opt == 'e') {
    while (fin == 0) {
      switch (menu()) {
        case 1:
          std::cout << "Introduzca la clave a insertar" << std::endl;
          std::cin >> clave;
          std::cout << std::endl;
          std::cout << "Insertar: " << clave << std::endl;
          arbol.Insertar(clave);
          arbol.ImprimirNodo();
          break;
        case 2:
          std::cout << "Introduzca la clave a buscar" << std::endl;
          std::cin >> clave;
          std::cout << std::endl;
          std::cout << "Buscar: " << clave << std::endl;
          arbol.BuscarPrint(clave);
          std::cout << std::endl;
          arbol.ImprimirNodo();
          break;
        case 0:
          fin = 1;
          break;
        default:
          std::cout << "Caracter erroneo" << std::endl;
          break;
      }
    } 
  } else if (opt == 'b') {
    while (fin == 0) {
      switch (menu()) {
        case 1:
          std::cout << "Introduzca la cable a insertar" << std::endl;
          std::cin >> clave;
          std::cout << std::endl;
          std::cout << "Insertar: " << clave << std::endl;
          tree.Insertar(clave);
          tree.ImprimirNodo();
          break;
        case 2:
          std::cout << "Introduzca la clave a buscar" << std::endl;
          std::cin >> clave;
          std::cout << std::endl;
          std::cout << "Buscar: " << clave << std::endl;
          tree.BuscarPrint(clave);
          std::cout << std::endl;
          tree.ImprimirNodo();
          break;
        case 0:
          fin = 1;
          break;
        default:
          std::cout << "Caracter erroneo" << std::endl;
          break;
      }
    }
  } else if (opt == 's') {  
      fin = 1; 
  } else {
      std::cout << "Seleccion incorrecta" << std::endl;
  }
}

// Menu 
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