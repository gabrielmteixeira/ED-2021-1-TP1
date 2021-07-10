#ifndef CELULA
#define CELULA
#include "buffer.hpp"
// #include "sistema.hpp"

template<class T> class Celula {

  public:
    Celula();

  private:
    T item;
    Celula* prox;

  friend class Buffer;
  // friend class ListaDeServidor;
};

#endif