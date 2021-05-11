#pragma once

template<class Clave>
class nodoBB {
 private:
 public:
  nodoBB(){}
  // Constructor:
  nodoBB(const int dat, const int cl, nodoBB *izq = NULL, nodoBB *der = NULL);
  ~nodoBB(){};
  Clave dato;
  Clave clave;
  nodoBB *izdo;
  nodoBB *dcho;
};


template<class Clave>
nodoBB<Clave>::nodoBB(const int dat, const int cl, nodoBB<Clave> *izq, nodoBB<Clave> *der) : dato(dat), clave(cl), izdo(izq), dcho(der) {}



