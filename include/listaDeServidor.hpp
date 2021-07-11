#ifndef LISTA_DE_SERVIDOR
#define LISTA_DE_SERVIDOR

#include "buffer.hpp"
#include "celula.hpp"

//Cada célula da lista representa um servidor com seu próprio buffer
class ListaDeServidor {
  public:
    ListaDeServidor(int numeroDeServidores);
    ~ListaDeServidor();

    Celula<Buffer>* getServidor(int posicao);
    int getTamanho();
    void insereFinal();
    void limpa();
  
  private:
    int tamanho;
    Celula<Buffer>* primeiro;
    Celula<Buffer>* ultimo;
};

#endif