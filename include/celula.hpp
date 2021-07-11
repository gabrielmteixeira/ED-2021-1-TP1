#ifndef CELULA
#define CELULA
#include "buffer.hpp"
// #include "sistema.hpp"

template<class T> class Celula {

  public:
    Celula() {
      this->item = T();
      this->prox = nullptr;
    };

  private:
    T item;
    Celula* prox;

  friend class Buffer;
  friend class ListaDeServidor;
};

#endif