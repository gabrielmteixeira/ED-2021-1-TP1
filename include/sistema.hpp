//Sistema se refere ao conjunto de servidores
#ifndef SISTEMA
#define SISTEMA
#include "buffer.hpp"
#include "celula.hpp"

class Sistema {

  public:
    Sistema(int numeroDeServidores);
    void info(int servidor, std::string dados);
    void warn(int servidor, int posicaoItem);
    void trans(int servidor1, int servidor2);
    void erro(int servidor);
    void send();
    void flush();
    void limpa();

  private:
    ListaDeServidor* Servidores;
    Buffer historico;

};

//Cada célula da lista representa um servidor com seu próprio buffer
class ListaDeServidor {
  public:
    ListaDeServidor(int numeroDeServidores);
    ~ListaDeServidor();

    Buffer getServidor(int pos);
    void InsereFinal (Buffer servidor);
    void Limpa();
  
  private:
     Celula<Buffer>* primeiro;
     Celula<Buffer>* ultimo;
     Celula<Buffer> posiciona(int pos, bool antes);
};

#endif


