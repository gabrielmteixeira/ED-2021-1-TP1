#include "../include/listaDeServidor.hpp"

ListaDeServidor::ListaDeServidor(int numeroDeServidores) {
  this->tamanho = numeroDeServidores;
  this->primeiro = new Celula<Buffer>();
  this->ultimo = this->primeiro;
  
  for(int i = 0; i < this->tamanho; i++) {
    this->insereFinal();
  }
}

ListaDeServidor::~ListaDeServidor() {
  this->limpa();
  delete this->primeiro;
}

Celula<Buffer>* ListaDeServidor::getServidor(int posicao) {
  if((posicao >= this->tamanho) || (posicao < 0)) {
    throw "Erro: Posicao invalida!";
  }
  
  Celula<Buffer>* celula = this->primeiro->prox;
  for(int i = 0; i < posicao; i++) {
    celula = celula->prox;
  }

  return celula;
}

void ListaDeServidor::insereFinal() {
  Celula<Buffer>* nova = new Celula<Buffer>();
  this->ultimo->prox = nova;
  this->ultimo = nova;
}

void ListaDeServidor::limpa() {
  Celula<Buffer>* celula = this->primeiro->prox;

  while(celula!=nullptr) {
    this->primeiro->prox = celula->prox;
    delete celula;
    celula = this->primeiro->prox;
  }
  this->ultimo = this->primeiro;
  this->tamanho = 0;
}