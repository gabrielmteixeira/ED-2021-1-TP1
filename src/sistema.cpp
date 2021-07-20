#include "../include/sistema.hpp"

Sistema::Sistema(int numeroDeServidores) {
  this->numeroDeServidores = numeroDeServidores;
  this->servidores = new Buffer[numeroDeServidores];
}

Sistema::~Sistema() {
  delete[] this->servidores;
}

void Sistema::info(int indiceServidor, std::string dados) {
  if((indiceServidor >= this->numeroDeServidores) ||
   (indiceServidor < 0)) {
    throw "Erro: Índice invalido!";
  }

  this->servidores[indiceServidor].enfileira(dados);
}

void Sistema::warn(int indiceServidor, int posicaoItem) {
  if((indiceServidor >= this->numeroDeServidores) ||
    (indiceServidor < 0) ||
    (posicaoItem >= this->servidores[indiceServidor].getTamanho()) ||
    (posicaoItem < 0)) {
      throw "Erro: Índice invalido!";      
  }
  this->servidores[indiceServidor].furaFila(posicaoItem);
}

void Sistema::tran(int indiceServidor1, int indiceServidor2) {
  if((indiceServidor1 >= this->numeroDeServidores) ||
    (indiceServidor2 >= this->numeroDeServidores) ||
   (indiceServidor1 < 0) ||
   (indiceServidor2 < 0)) {
    throw "Erro: Índice invalido!";
  }
  while(this->servidores[indiceServidor1].getTamanho() != 0) {
    this->servidores[indiceServidor2].enfileira(
      this->servidores[indiceServidor1].desenfileira());
  }
}

void Sistema::erro(int indiceServidor) {
  if((indiceServidor >= this->numeroDeServidores) ||
   (indiceServidor < 0)) {
    throw "Erro: Índice invalido!";
  }
  while(this->servidores[indiceServidor].getTamanho() != 0) {
    std::cout << this->servidores[indiceServidor].desenfileira() << std::endl;
  }
}

void Sistema::send() {
  for(int i = 0; i < this->numeroDeServidores; i++) {
    if(this->servidores[i].getTamanho() != 0) {
      this->historico.enfileira(this->servidores[i].desenfileira());
    }
  }
}

void Sistema::flush() {
  this->historico.imprime();
  this->historico.limpa();
  for(int i = 0; i < this->numeroDeServidores; i++) {
    if(this->servidores[i].getTamanho() != 0) {
      this->servidores[i].imprime();
      this->servidores[i].limpa();
    }
  }
}