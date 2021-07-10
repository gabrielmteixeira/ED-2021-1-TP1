#ifndef BUFFER
#define BUFFER
#include <string>
#include <iostream>
#include "celula.hpp"

class Buffer {

  public:
    Buffer();
    ~Buffer();

    int getTamanho();
    bool vazia();
    void enfileira(std::string item);
    void furaFila(int posicao);
    std::string desinfileira();
    void imprime();
    void limpa();

  private:
    int tamanho;
    Celula<std::string>* frente;
    Celula<std::string>* tras;
};

#endif