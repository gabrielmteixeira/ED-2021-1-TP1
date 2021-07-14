#include "../include/sistema.hpp"

Sistema::Sistema(int numeroDeServidores) {
  this->numeroDeServidores = numeroDeServidores;
  this->Servidores = new Buffer[numeroDeServidores];
}

Sistema::~Sistema() {
  delete[] this->Servidores;
}

void Sistema::info(int indiceServidor, std::string dados) {
  this->Servidores[indiceServidor].enfileira(dados);
}

void Sistema::warn(int indiceServidor, int posicaoItem) {\
  this->Servidores[indiceServidor].furaFila(posicaoItem);
}

void Sistema::tran(int indiceServidor1, int indiceServidor2) {
  while(this->Servidores[indiceServidor1].getTamanho() != 0) {
    this->Servidores[indiceServidor2].enfileira(
      this->Servidores[indiceServidor1].desinfileira());
  }
}

void Sistema::erro(int indiceServidor) {
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