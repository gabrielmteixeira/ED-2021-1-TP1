#include "../include/buffer.hpp"

int main() {

  Buffer teste;
  std::cout << teste.vazia() << std::endl;
  std::cout << teste.getTamanho() << std::endl;

  std::string lista[5];
  lista[0] = "primeiro";
  lista[1] = "segundo";
  lista[2] = "terceiro";
  lista[3] = "quarto";
  lista[4] = "quinto";
  for(int i = 0; i < 5; i++) {
    teste.enfileira(lista[i]);
  }
  std::cout << teste.vazia() << std::endl;
  std::cout << teste.getTamanho() << std::endl;
  std::cout << "Antes de furar fila:" << std::endl;
  teste.imprime();
  teste.furaFila(4);
  std::cout << "Depois de furar fila:" << std::endl;
  teste.imprime();
  std::cout << "Desinfilera:" << std::endl;
  std::cout << teste.desinfileira() << std::endl << std::endl;
  std::cout << "Limpa:" << std::endl;
  teste.limpa();
  std::cout << teste.getTamanho() << std::endl;
  std::cout << teste.vazia() << std::endl;
  teste.imprime();

  return 0;
}