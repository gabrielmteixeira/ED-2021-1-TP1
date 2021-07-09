#ifndef BUFFER
#define BUFFER
#include <string>

class Buffer {

  public:
    Buffer();
    ~Buffer();

    int getTamanho();
    bool vazia();
    void enfileira(std::string);
    std::string desinfileira();
    void imprime();
    void limpa();

  private:
    int tamanho;
    Celula* frente;
    Celula* tras;
};

class Celula {

  public:
    Celula();

  private:
    std::string item;
    Celula *prox;

  friend class Buffer;
};

#endif