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

#pragma once

template<class Clave>
class nodoB {
private:
public:
  nodoB(){}
  // Constructor:
  nodoB(const int dat, nodoB<Clave> *izq = NULL, nodoB<Clave> *der = NULL);
  ~nodoB(){};
  Clave dato;
  nodoB *izdo;
  nodoB *dcho;
};


template<class Clave>
nodoB<Clave>::nodoB(const int dat, nodoB<Clave> *izq, nodoB<Clave> *der) : dato(dat), izdo(izq), dcho(der) {}




