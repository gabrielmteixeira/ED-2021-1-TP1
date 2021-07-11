//Sistema se refere ao conjunto de servidores
#ifndef SISTEMA
#define SISTEMA
#include "buffer.hpp"
#include "listaDeServidor.hpp"
#include "celula.hpp"

class Sistema {

  public:
    Sistema(int numeroDeServidores);
    ~Sistema();

    void info(int indiceServidor, std::string dados);
    void warn(int indiceServidor, int posicaoItem);
    void trans(int indiceServidor1, int indiceServidor2);
    void erro(int indiceServidor);
    void send();
    void flush();

  private:
    ListaDeServidor* Servidores;
    Buffer historico;
};

#endif

