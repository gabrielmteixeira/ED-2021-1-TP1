//Sistema se refere ao conjunto de servidores
#ifndef SISTEMA
#define SISTEMA
#include "buffer.hpp"

class Sistema {

  public:
    Sistema(int numeroDeServidores);
    ~Sistema();

    void info(int indiceServidor, std::string dados);
    void warn(int indiceServidor, int posicaoItem);
    void tran(int indiceServidor1, int indiceServidor2);
    void erro(int indiceServidor);
    void send();
    void flush();

  private:
    Buffer* Servidores;
    Buffer historico;
    int numeroDeServidores;
};

#endif

