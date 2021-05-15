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
#include "AVL.hpp"

#include <iostream>

using Clave = int;

int menu(AB<Clave>* tree);

int main(){

  Clave clave;
  AB<Clave>* tree = new AVL<Clave>;
  
  int fin = 0;
  
  while (fin == 0) {
    switch (menu(tree)) {
      case 0:
        fin = 1;
        break;
      case 1:
        std::cout << "Introduzca la cable a insertar" << std::endl;
        std::cin >> clave;
        std::cout << std::endl;
        std::cout << "Insertar: " << clave << std::endl;
        tree->Insertar(clave);
        tree->ImprimirNodo();
        break;
      case 2:
        std::cout << "Introduzca la clave a buscar" << std::endl;
        std::cin >> clave;
        std::cout << std::endl;
        std::cout << "Buscar: " << clave << std::endl;
        tree->BuscarPrint(clave);
        std::cout << std::endl;
        tree->ImprimirNodo();
        break;
      case 3:
        std::cout << "Introduzca la cable a eliminar" << std::endl;
        std::cin >> clave;
        std::cout << std::endl;
        if (tree->Buscar(clave) != NULL){
          std::cout << "Eliminar: " << clave << std::endl;
          std::cout << std::endl;
          tree->eliminar(clave);
          tree->ImprimirNodo();
        } else {
          std::cout << "esta" << std::endl;
        }
        break;
      case 4:
        if (tree->getModoTraza()){
          // std::cout <<;
          bool& ModoT = tree->getModoTraza();
          ModoT = false;
        } else {
          bool& ModoT = tree->getModoTraza();
          ModoT = true;
        }
        break;
      default:
        std::cout << "Caracter erroneo" << std::endl;
        break;
    }
  }
}

// Menu 
int menu(AB<Clave>* tree) {
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "Seleccione las siguientes opciones para el arbol:" << std::endl;
  std::cout << "[0] Salir\n[1] Insertar Clave\n[2] Buscar Clave" << std::endl;
  if (tree->getModoTraza()) 
    std::cout << "[4] Desactivar Modo Traza" << std::endl;
  else
    std::cout << "[4] Activar Modo Traza" << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << std::endl;
  int opciones;
  std::cin >> opciones;
  return opciones;
}