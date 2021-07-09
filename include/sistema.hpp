//Sistema se refere ao conjunto de servidores
#ifndef SISTEMA
#define SISTEMA
#include "buffer.hpp"

class Sistema {

  public:
    Sistema();


  private:


};

#endif

class ListaDeServidor {
  ListaDeServidor(int quantidadeServidores);
  ~ListaDeServidor();

  Buffer getServidor(int pos);
  void InsereFinal (Buffer servidor);
  


};

class CelulaServidor {

  public:
    CelulaServidor();
  
  private:
    Buffer servidor;
    CelulaServidor *prox;

  friend class ListaDeServidor;
};