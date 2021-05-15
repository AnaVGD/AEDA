
#pragma once

#include <iostream>
#include <queue>
#include <utility>
#include "nodoAVL.hpp"

template<class Clave>
class AVL : public ABB<Clave> {
 private:
  /* data */
 public:
  AVL(){};
  ~AVL(){};

  void rotacion_II (nodoAVL<Clave>* &nodo);
  void rotacion_DD (nodoAVL<Clave>* &nodo);
  void rotacion_ID (nodoAVL<Clave>* &nodo);
  void rotacion_DI (nodoAVL<Clave>* &nodo);

  bool ModoTraza = false;

  bool& getModoTraza() {
    return ModoTraza;
  }

  void Insertar(const Clave &ClaveDada);
  void inserta_bal(nodoAVL<Clave>* &nodo, nodoAVL<Clave>* nuevo, bool& crece);
  void insert_re_balancea_izda(nodoAVL<Clave>* &nodo, bool& crece);
  void insert_re_balancea_dcha(nodoAVL<Clave>* &nodo, bool& crece);

  void eliminar(Clave clave_dada);
  void elimina_rama(nodoAVL<Clave>* &nodo, Clave ClaveDada, bool& decrece);

  void sustituye(nodoAVL<Clave>* &eliminado, nodoAVL<Clave>* &sust, bool &decrece);
  void eliminar_re_balancea_izda(nodoAVL<Clave>* &nodo, bool& decrece);
  void eliminar_re_balancea_dcha (nodoAVL<Clave>* &nodo, bool& decrece);
};

template<class Clave>
void AVL<Clave>::rotacion_II(nodoAVL<Clave>* &nodo) {
  if (ModoTraza) {
    std::cout << "\nDesbalanceo" << std::endl;
    AB<Clave>::Imprimir(AB<Clave>::raiz);
  }
  nodoAVL<Clave>* nodo1 = reinterpret_cast<nodoAVL<Clave>*&>(nodo->izdo);
  reinterpret_cast<nodoAVL<Clave>*&>(nodo->izdo) = reinterpret_cast<nodoAVL<Clave>*&>(nodo1->dcho);
  reinterpret_cast<nodoAVL<Clave>*&>(nodo1->dcho) = nodo;
  if (nodo1->bal == 1) {
    nodo->bal = 0;
    nodo1->bal = 0;
  }
  // nodo1->bal == 0
  else { 
    nodo->bal = 1;
    nodo1->bal = -1;
  }
  nodo = nodo1;
  if (ModoTraza) 
    std::cout << "\nRotacion II en [" << reinterpret_cast<nodoAVL<Clave>*&>(nodo->izdo)->dato << "]" << std::endl;
}



template<class Clave>
void AVL<Clave>::rotacion_DD(nodoAVL<Clave>* &nodo) {
  if (ModoTraza) {
    std::cout << "\nDesbalanceo" << std::endl;
    AB<Clave>::Imprimir(AB<Clave>::raiz);
  }
  nodoAVL<Clave>* nodo1 = reinterpret_cast<nodoAVL<Clave>*&>(nodo->dcho);
  reinterpret_cast<nodoAVL<Clave>*&>(nodo->dcho) = reinterpret_cast<nodoAVL<Clave>*&>(nodo1->izdo);
  reinterpret_cast<nodoAVL<Clave>*&>(nodo1->izdo) = nodo;
  if (nodo1->bal == -1) {
    nodo->bal = 0;
    nodo1->bal = 0;
  }
  // nodo1->bal == 0
  else { 
    nodo->bal = -1;
    nodo1->bal = 1;
  }
  nodo = nodo1;
  if (ModoTraza) 
    std::cout << "\nRotacion DD en [" << reinterpret_cast<nodoAVL<Clave>*&>(nodo->dcho)->dato << "]" << std::endl;
}

template<class Clave>
void AVL<Clave>::rotacion_ID(nodoAVL<Clave>* &nodo) {
  if (ModoTraza) {
    std::cout << "\nDesbalanceo" << std::endl;
    AB<Clave>::Imprimir(AB<Clave>::raiz);
  }
  nodoAVL<Clave>* nodo1 = reinterpret_cast<nodoAVL<Clave>*&>(nodo->izdo);
  nodoAVL<Clave>* nodo2 = reinterpret_cast<nodoAVL<Clave>*&>(nodo1->dcho);
  reinterpret_cast<nodoAVL<Clave>*&>(nodo->izdo) = reinterpret_cast<nodoAVL<Clave>*&>(nodo2->dcho);
  reinterpret_cast<nodoAVL<Clave>*&>(nodo2->dcho) = nodo;
  reinterpret_cast<nodoAVL<Clave>*&>(nodo1->dcho) = reinterpret_cast<nodoAVL<Clave>*&>(nodo2->izdo);
  reinterpret_cast<nodoAVL<Clave>*&>(nodo2->izdo) = nodo1;
  if (nodo2->bal == -1)
    nodo1->bal = 1;
  else nodo1->bal = 0;
  if (nodo2->bal == 1)
    nodo->bal = -1;
  else nodo->bal = 0;
  nodo2->bal = 0;
  nodo = nodo2;
  if (ModoTraza) 
    std::cout << "Rotacion ID en [" << nodo2->dato << "]" << std::endl;
}

template<class Clave>
void AVL<Clave>::rotacion_DI(nodoAVL<Clave>* &nodo) {
  if (ModoTraza) {
    std::cout << "\nDesbalanceo" << std::endl;
    AB<Clave>::Imprimir(AB<Clave>::raiz);
  }
  nodoAVL<Clave>* nodo1 = reinterpret_cast<nodoAVL<Clave>*&>(nodo->dcho);
  nodoAVL<Clave>* nodo2 = reinterpret_cast<nodoAVL<Clave>*&>(nodo1->izdo);
  reinterpret_cast<nodoAVL<Clave>*&>(nodo->dcho) = reinterpret_cast<nodoAVL<Clave>*&>(nodo2->izdo);
  reinterpret_cast<nodoAVL<Clave>*&>(nodo2->izdo) = nodo;
  reinterpret_cast<nodoAVL<Clave>*&>(nodo1->izdo) = reinterpret_cast<nodoAVL<Clave>*&>(nodo2->dcho);
  reinterpret_cast<nodoAVL<Clave>*&>(nodo2->dcho) = nodo1;
  if (nodo2->bal == 1)
    nodo1->bal = -1;
  else nodo1->bal = 0;
  if (nodo2->bal == -1)
    nodo->bal = 1;
  else nodo->bal = 0;
  nodo2->bal = 0;
  nodo = nodo2;
  if (ModoTraza) 
    std::cout << "\nRotacion DI en [" << nodo2->dato << "]" << std::endl;
}

template<class Clave>
void AVL<Clave>::Insertar(const Clave& ClaveDada) {
  nodoAVL<Clave>* nuevo = new nodoAVL<Clave>(ClaveDada);
  bool crece = false;
  inserta_bal(reinterpret_cast<nodoAVL<Clave>*&>(AB<Clave>::raiz), nuevo, crece);
}

template<class Clave>
void AVL<Clave>::inserta_bal(nodoAVL<Clave>* &nodo, nodoAVL<Clave>* nuevo, bool& crece) {
  if (nodo == NULL) {
    nodo = nuevo;
    crece = true;
  }
  else if (nuevo->dato < nodo->dato) {
    inserta_bal(reinterpret_cast<nodoAVL<Clave>*&>(nodo->izdo), nuevo, crece);
    if (crece) insert_re_balancea_izda(nodo, crece);
  } else {
    inserta_bal(reinterpret_cast<nodoAVL<Clave>*&>(nodo->dcho), nuevo, crece);
    if (crece) insert_re_balancea_dcha(nodo, crece);
  }
}

template<class Clave>
void AVL<Clave>::insert_re_balancea_izda(nodoAVL<Clave>* &nodo, bool& crece) {
  switch (nodo->bal) {
    case -1: nodo->bal = 0;
      crece = false;
    break;
    case 0: 
      nodo->bal = 1 ;
    break;
    case 1: nodoAVL<Clave>* nodo1 = reinterpret_cast<nodoAVL<Clave>*&>(nodo->izdo);
      if (nodo1->bal == 1)
      rotacion_II(nodo);
      else rotacion_ID(nodo);
      crece = false;
  }
}

template<class Clave>
void AVL<Clave>::insert_re_balancea_dcha (nodoAVL<Clave>* &nodo, bool& crece) {
  switch (nodo->bal) {
    case 1: nodo->bal = 0;
      crece = false;
    break;
    case 0: 
      nodo->bal = -1;
    break;
    case -1: 
      nodoAVL<Clave>* nodo1 = reinterpret_cast<nodoAVL<Clave>*&>(nodo->dcho);
    if (nodo1->bal == -1)
      rotacion_DD(nodo);
    else rotacion_DI(nodo);
    crece = false;
  }
}


template<class Clave>
void AVL<Clave>::eliminar(Clave clave_dada) {
  bool decrece = false;
  elimina_rama(reinterpret_cast<nodoAVL<Clave>*&>(AB<Clave>::raiz), clave_dada, decrece);
}

template<class Clave>
void AVL<Clave>::elimina_rama(nodoAVL<Clave>* &nodo, Clave clave_dada, bool& decrece) {
  if (nodo == NULL) return;
  if (clave_dada < nodo->dato) {
    elimina_rama(reinterpret_cast<nodoAVL<Clave>*&>(nodo->izdo), clave_dada, decrece);
    if (decrece)
    eliminar_re_balancea_izda(nodo,decrece);
  }
  else if (clave_dada > nodo->dato) {
    elimina_rama(reinterpret_cast<nodoAVL<Clave>*&>(nodo->dcho), clave_dada, decrece);
    if (decrece)
    eliminar_re_balancea_dcha(nodo,decrece);
  // nodo->clave == clave_dada(encontrado)
  } else { 
    nodoAVL<Clave>* Eliminado = nodo;
    if (reinterpret_cast<nodoAVL<Clave>*&>(nodo->izdo) == NULL) {
      nodo = reinterpret_cast<nodoAVL<Clave>*&>(nodo->dcho);
      decrece = true;
    }
    else if (reinterpret_cast<nodoAVL<Clave>*&>(nodo->dcho) == NULL) {
      nodo = reinterpret_cast<nodoAVL<Clave>*&>(nodo->izdo);
      decrece = true;
    }
    else {
      sustituye(Eliminado, reinterpret_cast<nodoAVL<Clave>*&>(nodo->izdo), decrece);
      if (decrece)
      eliminar_re_balancea_izda(nodo,decrece);
    }
    delete Eliminado;
  }
}

template<class Clave>
void AVL<Clave>::sustituye(nodoAVL<Clave>* &eliminado, nodoAVL<Clave>* &sust, bool &decrece) {
  if (reinterpret_cast<nodoAVL<Clave>*&>(sust->dcho) != NULL) {
    sustituye(eliminado, reinterpret_cast<nodoAVL<Clave>*&>(sust->dcho), decrece);
    if (decrece)
    eliminar_re_balancea_dcha(sust, decrece);
  }
  else {
    eliminado->dato = sust->dato;
    eliminado = sust;
    sust = reinterpret_cast<nodoAVL<Clave>*&>(sust->izdo);
    decrece = true;
  }
}

template<class Clave>
void AVL<Clave>::eliminar_re_balancea_izda(nodoAVL<Clave>* &nodo, bool& decrece) {
  switch (nodo->bal) {
    case -1: {
      nodoAVL<Clave>* nodo1 = reinterpret_cast<nodoAVL<Clave>*&>(nodo->dcho);
      if (nodo1->bal > 0)
      rotacion_DI(nodo);
      else {
        if (nodo1->bal == 0)
          decrece = false;
          rotacion_DD(nodo);
        }
      break;
    }
    case 0: 
      nodo->bal = -1;
      decrece = false;
      break;
    case 1: 
      nodo->bal = 0;
  }
}


template<class Clave>
void AVL<Clave>::eliminar_re_balancea_dcha (nodoAVL<Clave>* &nodo, bool& decrece) {
  switch (nodo->bal) {
    case 1: {
      nodoAVL<Clave>* nodo1 = reinterpret_cast<nodoAVL<Clave>*&>(nodo->izdo);
      if (nodo1->bal < 0)
      rotacion_ID(nodo);
      else {
        if (nodo1->bal == 0)
          decrece = false;
          rotacion_II(nodo);
        }
      break ;
    }
      case 0: {}
        nodo->bal = 1;
        decrece = false;
    break;
    case -1:
      nodo->bal = 0;
  }
}