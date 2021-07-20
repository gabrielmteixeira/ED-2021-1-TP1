#include <iostream>
#include <string>
#include <fstream>
#include "sistema.hpp"

// Função main que recebe como um dos parâmetros os arquivos de entrada.
// Trata a entrada, inicializando uma instância da classe 'Sistema', passando
// como parâmetro para o construtor o valor da primeira linha do arquivo de
// entrada. Chama, a partir da instância de 'sistema' mencionada anteriormente,
// cada método especificado em cada linha da entrada.
int main (int argc, char* argv[]) {
  std::ifstream entrada(argv[1]);
  std::string texto;
  getline(entrada, texto);
  Sistema sistema(std::stoi(texto));
  try {
    while(getline(entrada, texto)) {

      // O int 'tamanho' e o 'if' que o modifica são implementados pois no
      // OS Windows existe um caractere '\r' no momento da quebra de linha.
      // Dessa forma, subtrai-se 1 do tamanho caso esse caractere exista para 
      // que um input de texto tenha o mesmo tamanho independentemente do OS.
      int tamanho = texto.size();
      if(texto[tamanho - 1] == '\r') {
        tamanho--;
      }
      std::string delimitador = " ";
      std::string comando = texto.substr(0, texto.find(delimitador));

      if(comando == "INFO") {

        // O tamanho da substring é definido como 'tamanho - 9' pois 9 é número
        // de caracteres na string que não fazem parte do dado armazenado, ou
        // seja, essa subtração resulta no tamanho da substring equivalente a 
        // esse dado.
        std::string dado = texto.substr(texto.find("\"") + 1, (tamanho - 9));

        // texto.find("\"") - 6 -> find("\"") retorna o índice do primeiro 
        // caractere '"' na string, que é equivalente ao tamanho da substring 
        // que vai até o caractere imediatamente antes das aspas. O 6 é
        // subtraído pois é o número de caracteres que não são referentes ao
        // índice do servidor no qual deseja-se adicionar informação nessa
        // substring mencionada anteriormente. Assim,
        // o inteiro resultante é o tamanho do número que representa o índice
        // do servidor desejado.
        std::string servidor = texto.substr(5, texto.find("\"") - 6);
        sistema.info(std::stoi(servidor), dado);

      } else if(comando == "WARN") {

        // O tamanho da substring é definido como 'tamanho - 5' pois 5 é número
        // de caracteres na string além daqueles que representam os índices do
        // servidor, dado que quer-se acessar e o espaço entre eles, ou seja,
        // essa subtração resulta no tamanho da substring equivalente a esses
        // dois índices e ao espaço.
        std::string servidorPosicao = texto.substr(5, tamanho - 5);
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

        // O tamanho da substring é definido como 'tamanho - 5' pois 5 é número
        // de caracteres na string além daqueles que representam os índices dos
        // servidores e o espaço entre eles, ou seja, essa subtração resulta no
        // tamanho da substring equivalente a esses dois índices e ao espaço.        
        std::string servidores = texto.substr(5, tamanho - 5);
        std::string servidor1, servidor2;
        bool passou = false;
        for(size_t i = 0; i < servidores.size(); i++) {
          if(servidores[i] != ' ' && !passou) {
            servidor1.push_back(servidores[i]);
          } else if (servidores[i] == ' ') {
            passou = true;
          } else {
            servidor2.push_back(servidores[i]);
          }
        }
        sistema.tran(std::stoi(servidor1), std::stoi(servidor2));

      } else if(comando == "ERRO") {

        // O tamanho da substring é definido como 'tamanho - 5' pois 5 é número
        // de caracteres na string além daqueles que representam o índice do
        // servidor a que o comando se refere, ou seja, essa subtração resulta
        // no tamanho da substring equivalente a esse índice.
        std::string servidor = texto.substr(5, tamanho - 5);
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