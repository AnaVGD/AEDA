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

#include <iostream>
#include <queue>
#include <utility>
#include "nodoB.hpp"
#include "AB.hpp"

// Hereda la clase AB de la pravtica pasada
template<class Clave>
class ABB : public AB<Clave> {
 private:
 public:
  ABB() {this->raiz = NULL;}
  ~ABB() {this->Podar(this->raiz);}

  nodoB<Clave>* BuscarRama(nodoB<Clave>* nodo, const Clave& clave_dada) const;
  // nodoB<Clave>* Buscar(const Clave& clave_dada) const;
  nodoB<Clave>* Buscar(const Clave& clave_dada) const;

  virtual void Insertar(const Clave& clave_dada);
  virtual void InsertarRama(nodoB<Clave>* &nodo, const Clave& clave_dada);
};

// Recibe la clave a buscar y devuelve un bool si la encontrado o no en el nodo
// la funcion se encarga de llamar a la funcion BuscarRama
template<class Clave>
nodoB<Clave>* ABB<Clave>::Buscar(const Clave& clave_dada) const{
  return BuscarRama(this->raiz, clave_dada);
}

// Recibe la clave a buscar y devuelve un bool si la encontrado o no en el nodo,
// Busca a partir del recorrido por niveles
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

// Funcion insertar llama a la funcion insertarRama, ricibe por parametros la
// clave a insertar
template<class Clave>
void ABB<Clave>::Insertar(const Clave& clave_dada) {
  // std::cout << "B" << std::endl;
  InsertarRama(this->raiz, clave_dada);
}

// Recibe por parametros el nodo y la clave a insertar
template<class Clave>
void ABB<Clave>::InsertarRama(nodoB<Clave>* &nodo, const Clave& clave_dada) {
  if (nodo == NULL)
    nodo = new nodoB<Clave>(clave_dada);
  else if (clave_dada < nodo->dato)
    InsertarRama(nodo->izdo, clave_dada);
  else
    InsertarRama(nodo->dcho, clave_dada);
}