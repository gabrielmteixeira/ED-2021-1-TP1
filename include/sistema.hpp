//Sistema se refere ao conjunto de servidores
#ifndef SISTEMA
#define SISTEMA
#include "buffer.hpp"
#include "celula.hpp"
#include "listaDeServidor.hpp"

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

#endif

