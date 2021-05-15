#pragma once

#include "nodoB.hpp"

template<class Clave>
class nodoAVL : public nodoB<Clave> {
private:
public:
  nodoAVL(){}
  // Constructor:
  nodoAVL(const int dat, nodoAVL<Clave> *izq = NULL, nodoAVL<Clave> *der = NULL);
  ~nodoAVL(){};
  int bal;
};

template<class Clave>
nodoAVL<Clave>::nodoAVL(const int dat, nodoAVL<Clave> *izq, nodoAVL<Clave> *der) : bal(0) {
  this->dato = dat;
  this->izdo = izq;
  this->dcho = der;
}