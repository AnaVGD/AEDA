#pragma once

template<class Clave>
class nodoB {
private:
public:
  nodoB(){}
  // Constructor:
  nodoB(const int dat, nodoB *izq = NULL, nodoB *der = NULL);
  ~nodoB(){};
  Clave dato;
  nodoB *izdo;
  nodoB *dcho;
};


template<class Clave>
nodoB<Clave>::nodoB(const int dat, nodoB<Clave> *izq, nodoB<Clave> *der) : dato(dat), izdo(izq), dcho(der) {}




