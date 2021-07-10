#include "../include/celula.hpp"

Celula<std::string>::Celula() {
  this->item = "";
  this->prox = nullptr;
}

Celula<Buffer>::Celula() {
  this->prox = nullptr;
};
