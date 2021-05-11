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
////////////////////////////////////////////////////////////////////////////////


// Metodo de ordenacion shellsort
#pragma once

#include <iostream>
#include <vector>
#include <algorithm>


class Key
{
private:
  int dato;
  int cont = 0;
public:
  Key(){}
  ~Key(){}

  void read(std::istream &is);
  void write(std::ostream &os) const;
  
  Key &operator=(const int &num);
  bool operator>(const Key &num);
  bool operator<(const Key &num);

  int getcont() const;

  operator int() const {
    return dato;
  }
};


int Key::getcont() const {
  return cont;
}

std::istream &operator>>(std::istream &is, Key &k){
  k.read(is);
  return is;
}

std::ostream &operator<<(std::ostream &os, Key &k){
  k.write(os);
  return os;
}


void Key::read(std::istream &is){
  is >> dato;
}


void Key::write(std::ostream &os) const {
  os << dato;
}


Key &Key::operator=(const int &num){
  dato = num;
  return *this;
}

bool Key::operator>(const Key &num){
  cont++;
  return (dato > num.dato);
}

bool Key::operator<(const Key &num){
  cont++;
  return (dato < num.dato);
}