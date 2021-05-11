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


template<class Clave>
class AB {
protected:
  nodoB<Clave> *raiz;
public:
  AB() : raiz(NULL) {}
  virtual ~AB() { Podar(raiz); }

  void Podar(nodoB<Clave>* &nodo);
  bool EsVacio(nodoB<Clave> *nodo);
  bool EsHoja(nodoB<Clave> *nodo);

  void BuscarPrint(const Clave& x) const;
  virtual nodoB<Clave>* Buscar(const Clave& x) const;
  virtual nodoB<Clave>* BuscarRama( nodoB<Clave>* nodo, Clave clave_dada) const;

  void ImprimirNodo() const;
  void Imprimir(nodoB<Clave> *Raiz) const;

  const int Tam() const;
  const int TamRama(nodoB<Clave>* nodo) const;

  virtual void Insertar(const Clave& clave_dada);
  virtual void InsertaRama(const Clave& dato, nodoB<Clave>* nodo);
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

// Imprime si la clave ha sido encontrada o no depende de lo que devuelva la 
// funcion Buscar
template<class Clave>
void AB<Clave>::BuscarPrint(const Clave& x) const {
  if (Buscar(x) == NULL) {
    std::cout << "No encontrado\n";
  } else {
    std::cout << "Encontrado\n"; /// Mejorar
  }
}

// Llama a la funcion Buscar Rama, recibe por parameytos la clave a buscar
template<class Clave>
nodoB<Clave>* AB<Clave>::Buscar(const Clave& clave_dada ) const { 
  return BuscarRama(raiz, clave_dada); 
}

// Busca la rama a partir del recorrido por niveles, recibe por parametros el
// nodo y la cabe a buscar
template<class Clave>
nodoB<Clave>* AB<Clave>::BuscarRama(nodoB<Clave>* nodo, Clave clave_dada) const {
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
      //Incremento de nivel
      Nivel_actual = nivel; 
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

// Llama a la funcion tamRama y devuelve el tamaño
template<class Clave>
const int AB<Clave>::Tam() const { 
  return TamRama(raiz); 
}

// Clacula el tamaño de la rama, recibe por parametros el nodo
template<class Clave>
const int AB<Clave>::TamRama(nodoB<Clave>* nodo) const {
  if (nodo == NULL) return 0;
  return (1 + TamRama(nodo->izdo) + TamRama(nodo->dcho));
}

// Funcion incertar comprueba que le nodo no sea nulo, si lo es crea la raiz,
// si no lo es llama a la funcion insertarRama, recibe por parametro la clave a
// insertar
template<class Clave>
void AB<Clave>::Insertar(const Clave& dato) {
  if (raiz == NULL)
    raiz = new nodoB<Clave>(dato, NULL, NULL);
  else InsertaRama(dato, raiz);
}

// Recibe el dato a insertar y el nodo
template<class Clave>
void AB<Clave>::InsertaRama(const Clave& dato, nodoB<Clave>* nodo) {
  if (TamRama(nodo->izdo) <= TamRama(nodo->dcho)) {
    if (nodo->izdo != NULL)
      InsertaRama(dato, nodo->izdo);
    else
      nodo->izdo = new nodoB<Clave>(dato, NULL, NULL);
  } else {
    if (nodo->dcho != NULL)
      InsertaRama(dato, nodo->dcho);
    else
      nodo->dcho = new nodoB<Clave>(dato, NULL, NULL);
  }
}

// Laama a la funcion Imprimir
template<class Clave>
void AB<Clave>::ImprimirNodo() const {
  Imprimir(raiz);
}

// Recibe la raiz y imprime el nodo a travez del recorrido por niveles
template<class Clave>
void AB<Clave>::Imprimir(nodoB<Clave> *Raiz) const {
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