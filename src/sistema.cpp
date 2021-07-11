#include "../include/sistema.hpp"

Sistema::Sistema(int numeroDeServidores) {
  this->Servidores = new ListaDeServidor(numeroDeServidores);
}

Sistema::~Sistema() {
  delete(this->Servidores);
}

void Sistema::info(int indiceServidor, std::string dados) {
  Celula<Buffer>* servidor = this->Servidores->getServidor(indiceServidor);
  servidor->item.enfileira(dados);
}

void Sistema::warn(int indiceServidor, int posicaoItem) {
  Celula<Buffer>* servidor = this->Servidores->getServidor(indiceServidor);
  servidor->item.furaFila(posicaoItem);
}

void Sistema::trans(int indiceServidor1, int indiceServidor2) {
  Celula<Buffer>* servidor1 = this->Servidores->getServidor(indiceServidor1);
  Celula<Buffer>* servidor2 = this->Servidores->getServidor(indiceServidor2);

  while(servidor1->item.getTamanho() != 0) {
    servidor2->item.enfileira(servidor1->item.desinfileira());
  }
}

void Sistema::erro(int indiceServidor) {
  Celula<Buffer>* servidor = this->Servidores->getServidor(indiceServidor);
  while(servidor->item.getTamanho() != 0) {
    std::cout << servidor->item.desinfileira() << std::endl;
  }
}

void Sistema::send() {
  Celula<Buffer>* servidor = this->Servidores->getServidor(0);
  for(int i = 0; i < this->Servidores->getTamanho(); i++) {
    if(servidor->item.getTamanho() != 0) {
      this->historico.enfileira(servidor->item.desinfileira());
      servidor = servidor->prox;
    }
  }
}

void Sistema::flush() {
  this->historico.imprime();
  Celula<Buffer>* servidor = this->Servidores->getServidor(0);
  for(int i = 0; i < this->Servidores->getTamanho(); i++) {
    if(servidor->item.getTamanho() != 0) {
      servidor->item.imprime();
      servidor = servidor->prox;
    }
  }
}