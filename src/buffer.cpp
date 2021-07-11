#include "../include/buffer.hpp"

Buffer::Buffer() {
  this->tamanho = 0;
  this->frente = new Celula<std::string>;
  this->tras = frente;
}

Buffer::~Buffer() {
  this->limpa();
  delete this->frente;
}

int Buffer::getTamanho() {
  return this->tamanho;
}

bool Buffer::vazia() {
  return this->tamanho == 0;
}

void Buffer::enfileira(std::string item) {
  Celula<std::string>* nova;
  nova = new Celula<std::string>();
  nova->item = item;
  this->tras->prox = nova;
  this->tras = nova;
  this->tamanho++;
}

void Buffer::furaFila(int posicao) {
  if((posicao >= this->tamanho) || (posicao < 0)) {
    throw "Erro: Posicao invalida!";
  }
  
  Celula<std::string>* celula = this->frente->prox;
  Celula<std::string>* anterior;
  for(int i = 0; i < posicao; i++) {
    if(i == (posicao - 1)) {
      anterior = celula;
    }

    celula = celula->prox;
  }

  anterior->prox = celula->prox;
  celula->prox = this->frente->prox;
  this->frente->prox = celula;
}

std::string Buffer::desinfileira() {
  Celula<std::string>* celula;
  std::string valor;

  if(tamanho == 0) throw "Fila está vazia!";

  valor = this->frente->prox->item;
  celula = this->frente;
  this->frente = this->frente->prox;
  delete celula;
  this->tamanho--;

  return valor;
}

void Buffer::imprime() {
  Celula<std::string>* celula = this->frente->prox;
  for(int i = 0; i < this->tamanho; i++) {
    std::cout << celula->item << std::endl;
    celula = celula->prox;
  }
}

void Buffer::limpa() {
  Celula<std::string>* celula = this->frente->prox;
  
  while(celula != nullptr) {
    this->frente->prox = celula->prox;
    delete celula;
    celula = this->frente->prox;
  }
  this->tamanho = 0;
  tras = frente;
}