#include <iostream>
#include <string>
#include <fstream>
#include "sistema.hpp"


int main (int argc, char* argv[]) {
  std::ifstream entrada(argv[1]);
  std::string texto;
  getline(entrada, texto);
  Sistema sistema(std::stoi(texto));
  try {
    while(getline(entrada, texto)) {
      std::string delimitador = " ";
      std::string comando = texto.substr(0, texto.find(delimitador));

      if(comando == "INFO") {
        std::string dado = texto.substr(8, (texto.size() - 10));
        std::string servidor = texto.substr(5, texto.find("\"") - 6);
        sistema.info(std::stoi(servidor), dado);

      } else if(comando == "WARN") {
        std::string servidorPosicao = texto.substr(5, texto.size() - 6);
        std::string servidor, posicao;
        bool passou = false;
        for(size_t i = 0; i < servidorPosicao.size(); i++) {
          if(servidorPosicao[i] != ' ' && !passou) {
            servidor.push_back(servidorPosicao[i]);
          } else if (servidorPosicao[i] == ' ') {
            passou = true;
          } else {
            posicao.push_back(servidorPosicao[i]);
          }
        }
        sistema.warn(std::stoi(servidor), std::stoi(posicao));

      } else if(comando == "TRAN") {
        std::string servidorPosicao = texto.substr(5, texto.size() - 6);
        std::string servidor1, servidor2;
        bool passou = false;
        for(size_t i = 0; i < servidorPosicao.size(); i++) {
          if(servidorPosicao[i] != ' ' && !passou) {
            servidor1.push_back(servidorPosicao[i]);
          } else if (servidorPosicao[i] == ' ') {
            passou = true;
          } else {
            servidor2.push_back(servidorPosicao[i]);
          }
        }
        sistema.tran(std::stoi(servidor1), std::stoi(servidor2));

      } else if(comando == "ERRO") {
        std::string servidor = texto.substr(5, texto.size() - 6);
        std::cout << "ERRO " << servidor << std::endl;
        sistema.erro(std::stoi(servidor));

      } else if((comando == "SEND\r") || (comando == "SEND")) {
        sistema.send();
      } else if((comando == "FLUSH\r") || (comando == "FLUSH")) {
        sistema.flush();
      }
    }
  } catch(const char* error) {
    std::cerr << error << std::endl;
  }

  return 0;
}