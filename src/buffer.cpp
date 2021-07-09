#include "../include/buffer.hpp"

Buffer::Buffer() {
  this->tamanho = 0;
  this->frente = new TipoCelula;
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

TipoCelula::TipoCelula() {
  this->prox = nullptr;
}

