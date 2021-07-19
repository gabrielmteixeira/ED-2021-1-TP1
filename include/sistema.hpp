//Sistema se refere ao conjunto de servidores
#ifndef SISTEMA
#define SISTEMA
#include "buffer.hpp"

class Sistema {

  public:

    // Inicializa 'numeroDeServidores' como o valor inteiro do parâmetro
    // 'numeroDeServidores' e instância um array de Buffer (com 
    // o tamanho equivalente a 'numeroDeServidores') dinâmicamente e atribui 
    // seu endereço de memória ao ponteiro de Buffer 'Servidores'
    Sistema(int numeroDeServidores);

    // Utiliza da função 'delete' para deletar o array de Buffer apontado
    // por 'Servidores'
    ~Sistema();

    // Adiciona uma célula no final do Buffer armazenado na posição referente
    // ao parâmetro inteiro 'indiceServidor' do array de Buffer apontado por 
    // 'Servidores'. Essa nova célula armazena o valor da variável de string
    // 'dados', passada como parâmetro para o método 
    void info(int indiceServidor, std::string dados);

    // Recebe como parâmetros os inteiros 'indiceServidor' e 'posicaoItem'.
    // Acessa o buffer armazenado na posição 'indiceServidor' do array de Buffer
    // apontado por 'Servidores' e passa para a frente do buffer (frente->prox)
    // a célula na posição referente ao valor 'posicaoItem'
    void warn(int indiceServidor, int posicaoItem);

    // Recebe como parâmetros os inteiros 'indiceServidor1' e 'indiceServidor2'. 
    // Acessa os buffers nas posições 'indiceServidor1' e 'indiceServidor2' 
    // inserindo uma célula nova ao final do segundo para cada uma do primeiro.
    // Essas novas células do buffer referente a 'indiceServidor2' armazenam o 
    // mesmo valor das respectivas do buffer indicado por 'indiceServidor1'. 
    // Tanto a inserção de novas células em um quanto a remoção no outro são 
    // feitas seguindo a política FIFO
    void tran(int indiceServidor1, int indiceServidor2);

    // Recebe como parâmetro o inteiro 'indiceServidor'. Acessa o buffer de
    // posição 'indiceServidor' do array de Buffer apontado por 'Servidores', 
    // remove cada célula que ele contém, seguindo a política FIFO, e imprime
    // seu valor
    void erro(int indiceServidor);

    // Remove a célula da primeira posição (frente->prox) de cada buffer
    // armazenado no array de Buffer apontado por 'Servidores' e adiciona novas
    // no Buffer 'historico', uma para cada removida (os valores armazenados
    // nas novas células de 'historico' são os mesmos que eram armazenados por
    // aquelas removidas dos buffers de 'Servidores')
    void send();

    // Imprime o valor armazenado por cada célula de 'historico', para depois
    // imprimir os valores armazenados nas células de cada buffer armazenado no
    // array de Buffer apontado por 'Servidores', um buffer por vez. As 
    // impressões das células seguem a política FIFO. O método 'limpa()' é
    // chamado após a impressão do conteúdo de cada buffer, a fim de esvaziá-lo.
    void flush();

  private:
    Buffer* Servidores;
    Buffer historico;
    int numeroDeServidores;
};

#endif

