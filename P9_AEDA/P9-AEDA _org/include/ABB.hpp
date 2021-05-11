////////////////////////////////////////////////////////////////////////////////
// Copyright 2021
// Universidad de La Laguna
// Escuela superior de Ingeniería y Tecnología
// Grado en igeniería Informática
// Computablidad y Algoritmia
// Autor: Ana Virginia Giambona Díaz
// Correo: alu0101322650@ull.edu.es
// Fecha: 21/04/2021
// Práctica: Metodos de ordenacion
// 
////////////////////////////////////////////////////////////////////////////


#pragma once

#include <iostream>
#include <queue>
#include <utility>
#include "nodoB.hpp"
#include "AB.hpp"

template<class Clave>
class ABB : public AB<Clave> {
private:
  // nodoB<Clave>* raiz;  // nodoB??
public:
  ABB() {this->raiz = NULL;}
  ~ABB() {this->Podar(this->raiz);}

  nodoB<Clave>* BuscarRama(nodoB<Clave>* nodo, const Clave& clave_dada) const;
  // nodoB<Clave>* Buscar(const Clave& clave_dada) const;
  nodoB<Clave>* Buscar(const Clave& clave_dada) const;

  void Insertar(const Clave& clave_dada);
  void InsertarRama(nodoB<Clave>* &nodo, const Clave& clave_dada);
};

template<class Clave>
nodoB<Clave>* ABB<Clave>::Buscar(const Clave& clave_dada) const{
  return BuscarRama(this->raiz, clave_dada);
}

template<class Clave>
nodoB<Clave>* ABB<Clave>::BuscarRama(nodoB<Clave>* nodo, const Clave& clave_dada) const {
  if (nodo == NULL)
    return NULL;
  if (clave_dada == nodo->dato)
    return nodo;
  if (clave_dada < nodo->dato )
    return BuscarRama(nodo->izdo, clave_dada);
  return BuscarRama(nodo->dcho, clave_dada);
}

template<class Clave>
void ABB<Clave>::Insertar(const Clave& clave_dada) {
  InsertarRama(this->raiz, clave_dada);
}

template<class Clave>
void ABB<Clave>::InsertarRama(nodoB<Clave>* &nodo, const Clave& clave_dada) {
  if (nodo == NULL)
    nodo = new nodoB<Clave>(clave_dada);
  else if (clave_dada < nodo->dato)
    InsertarRama(nodo->izdo, clave_dada);
  else
    InsertarRama(nodo->dcho, clave_dada);
}