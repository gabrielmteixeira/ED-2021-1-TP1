#ifndef BUFFER
#define BUFFER
#include <string>
#include <iostream>
#include "celula.hpp"

class Buffer {

  public:

    // Atribui a 'tamanho' o valor 0, inicializa 'frente' com o endereço de
    // memória de uma instância de 'Celula' alocada dinamicamente e atribui a 
    // 'tras' o valor de 'frente'
    Buffer();

    // Chama o método 'limpa()' e utiliza a função 'delete' para deletar
    // 'frente'
    ~Buffer();
    
    // Retorna o valor inteiro do atributo 'tamanho'
    int getTamanho();

    // Adiciona uma célula, contendo a string passada através do parâmetro
    // 'item', no final do buffer e incrementa o valor de 'tamanho' em 1
    void enfileira(std::string item);

    // Posiciona a célula referente à posição passada como parâmetro (tendo 0
    // como índice da primeira célula que armazena um dado) na primeira posição
    // do buffer (indicada por 'frente->prox')
    void furaFila(int posicao);

    // Remove a primeira célula do buffer (frente->prox), retorna a string que
    // ela armazena e reduz em 1 o valor de 'tamanho'
    std::string desenfileira();

    // Imprime a string armazenada por todas as células do buffer (sendo
    // frente->prox a primeira), seguindo a política FIFO
    void imprime();

    // Utiliza a função 'delete' para deletar todas as células do buffer 
    // (a partir de frente->prox), então define 'tamanho' como 0 e 
    // atribui 'frente' a 'tamanho'
    void limpa();

  private:
    int tamanho;
    Celula<std::string>* frente;
    Celula<std::string>* tras;
};

#endif