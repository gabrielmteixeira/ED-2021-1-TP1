#include "../include/sistema.hpp"

Sistema::Sistema(int numeroDeServidores) {
  this->numeroDeServidores = numeroDeServidores;
  this->Servidores = new Buffer[numeroDeServidores];
}

Sistema::~Sistema() {
  delete[] this->Servidores;
}

void Sistema::info(int indiceServidor, std::string dados) {
  if((indiceServidor >= this->numeroDeServidores) ||
   (indiceServidor < 0)) {
    throw "Erro: Índice invalido!";
  }

  this->Servidores[indiceServidor].enfileira(dados);
}

void Sistema::warn(int indiceServidor, int posicaoItem) {
  if((indiceServidor >= this->numeroDeServidores) ||
    (indiceServidor < 0) ||
    (posicaoItem >= this->Servidores[indiceServidor].getTamanho()) ||
    (posicaoItem < 0)) {
      throw "Erro: Índice invalido!";      
  }
  this->Servidores[indiceServidor].furaFila(posicaoItem);
}

void Sistema::tran(int indiceServidor1, int indiceServidor2) {
  if((indiceServidor1 >= this->numeroDeServidores) ||
    (indiceServidor2 >= this->numeroDeServidores) ||
   (indiceServidor1 < 0) ||
   (indiceServidor2 < 0)) {
    throw "Erro: Índice invalido!";
  }
  while(this->Servidores[indiceServidor1].getTamanho() != 0) {
    this->Servidores[indiceServidor2].enfileira(
      this->Servidores[indiceServidor1].desinfileira());
  }
}

void Sistema::erro(int indiceServidor) {
  if((indiceServidor >= this->numeroDeServidores) ||
   (indiceServidor < 0)) {
    throw "Erro: Índice invalido!";
  }
  while(this->Servidores[indiceServidor].getTamanho() != 0) {
    std::cout << this->Servidores[indiceServidor].desinfileira() << std::endl;
  }
}

void Sistema::send() {
  for(int i = 0; i < this->numeroDeServidores; i++) {
    if(this->Servidores[i].getTamanho() != 0) {
      this->historico.enfileira(this->Servidores[i].desinfileira());
    }
  }
}

void Sistema::flush() {
  this->historico.imprime();
  for(int i = 0; i < this->numeroDeServidores; i++) {
    if(this->Servidores[i].getTamanho() != 0) {
      this->Servidores[i].imprime();
    }
  }
}