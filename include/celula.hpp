#ifndef CELULA
#define CELULA

template<class T> class Celula {

  public:

    // Chama o construtor padrão do tipo 'T' e atribui 'nullptr' a 'prox'
    Celula() {
      this->item = T();
      this->prox = nullptr;
    };

  private:
    T item;
    Celula* prox;

  friend class Buffer;
  friend class Sistema;
};

#endif