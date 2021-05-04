#pragma once

#include <iostream>
#include <queue>
#include <utility>
#include "nodoB.hpp"


template<class Clave>
class AB {
private:
  nodoB<Clave> *raiz;
public:
  AB() : raiz(NULL) {}
  ~AB() { Podar(raiz); }

  void Podar(nodoB<Clave>* &nodo);
  bool EsVacio(nodoB<Clave> *nodo);
  bool EsHoja(nodoB<Clave> *nodo);


  void Buscar2(const Clave& x) const;
  nodoB<Clave>* Buscar(const Clave& x) const;
  nodoB<Clave>* BuscarRama( nodoB<Clave>* nodo, int clave_dada) const;

  void imprimir2() const;
  void imprimir(nodoB<Clave> *Raiz) const;

  const int Tam() const;
  const int TamRama(nodoB<Clave>* nodo) const;

  void inserta(const Clave& x);
  void insertaEquilRama(const Clave& dato, nodoB<Clave>* nodo);
};

template<class Clave>
void AB<Clave>::Podar(nodoB<Clave>* &nodo) {
  if (nodo == NULL) return ;
  Podar(nodo->izdo); // Podar subarbol izquierdo
  Podar(nodo->dcho); // Podar subarbol derecho
  delete nodo; // Eliminar nodo
  nodo = NULL;
}

template<class Clave>
bool AB<Clave>::EsVacio(nodoB<Clave> *nodo) {
return nodo == NULL;
}

template<class Clave>
bool AB<Clave>::EsHoja(nodoB<Clave> *nodo) {
return !nodo->dcho && !nodo->izdo;
}


template<class Clave>
void AB<Clave>::Buscar2(const Clave& x) const {
  if (Buscar(x) == NULL) {
    std::cout << "No encontrado\n";
  } else {
    std::cout << "Encontrado\n"; /// Mejorar
  }
}

template<class Clave>
nodoB<Clave>* AB<Clave>::Buscar(const Clave& clave_dada ) const { 
  return BuscarRama(raiz, clave_dada); 
}

// template<class Clave>
// nodoB<Clave>* AB<Clave>::BuscarRama(nodoB<Clave>* nodo, int clave_dada) const {
//   if (nodo == NULL){
//     return NULL;
//   }
//   if (clave_dada == nodo->dato){
//     return nodo;
//   }
//   if (clave_dada > nodo->dato){
//     return BuscarRama(nodo->dcho, clave_dada);
//   }
//   return BuscarRama(nodo->izdo, clave_dada);
// } 

template<class Clave>
nodoB<Clave>* AB<Clave>::BuscarRama(nodoB<Clave>* nodo, int clave_dada) const {
  std::queue<std::pair<nodoB<Clave>*, int>> Q;
  // nodoB<Clave> *nodo;
  int nivel, Nivel_actual = 0;
  Q.push(std::make_pair(raiz, 0));
  while (!Q.empty()) {
    std::pair<nodoB<Clave>*, int> nodoNivel = Q.front();
    nodo = nodoNivel.first;
    nivel = nodoNivel.second;
    Q.pop();
    if(nivel > Nivel_actual)
      Nivel_actual = nivel; //Incremento de nivel
    if(nodo != NULL) {
      if(nodo->dato == clave_dada){
        return nodo;
      }
      Q.push(std::make_pair(nodo->izdo, nivel+1));
      Q.push(std::make_pair(nodo->dcho, nivel+1));
    }
  }
  return NULL;
} 

template<class Clave>
const int AB<Clave>::Tam() const { 
  return TamRama(raiz); 
}

template<class Clave>
const int AB<Clave>::TamRama(nodoB<Clave>* nodo) const {
  if (nodo == NULL) return 0;
  return (1 + TamRama(nodo->izdo) + TamRama(nodo->dcho));
}

template<class Clave>
void AB<Clave>::inserta(const Clave& dato) {
  if (raiz == NULL)
    raiz = new nodoB<Clave>(dato, NULL, NULL);
  else insertaEquilRama(dato, raiz);
}

template<class Clave>
void AB<Clave>::insertaEquilRama(const Clave& dato, nodoB<Clave>* nodo) {
  if (TamRama(nodo->izdo) <= TamRama(nodo->dcho)) {
    if (nodo->izdo != NULL)
      insertaEquilRama(dato, nodo->izdo);
    else
      nodo->izdo = new nodoB<Clave>(dato, NULL, NULL);
  } else {
    if (nodo->dcho != NULL)
      insertaEquilRama(dato, nodo->dcho);
    else
      nodo->dcho = new nodoB<Clave>(dato, NULL, NULL);
  }
}

template<class Clave>
void AB<Clave>::imprimir2() const {
  imprimir(raiz);
}


template<class Clave>
void AB<Clave>::imprimir(nodoB<Clave> *Raiz) const {
  std::queue<std::pair<nodoB<Clave>*, int>> Q;
  nodoB<Clave> *nodo;
  int nivel, Nivel_actual = 0;
  Q.push(std::make_pair(Raiz, 0));
  while (!Q.empty()) {
    std::pair<nodoB<Clave>*, int> nodoNivel = Q.front();
    nodo = nodoNivel.first;
    nivel = nodoNivel.second;
    Q.pop();
    if(nivel > Nivel_actual) {
      Nivel_actual = nivel; //Incremento de nivel
      std::cout << "\nNivel " << Nivel_actual << ": ";
    } else if (Nivel_actual == 0) {
      std::cout << "Nivel 0: ";
    }
    if(nodo != NULL) {
      std::cout << "[" << nodo->dato << "]";
      Q.push(std::make_pair(nodo->izdo, nivel+1));
      Q.push(std::make_pair(nodo->dcho, nivel+1));
    } else { 
      std::cout << "[.]";
    }
  }
}