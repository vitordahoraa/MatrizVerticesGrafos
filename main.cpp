#include <iostream>
using namespace std;
bool menuInicial(){
    char resposta;
  bool ehDirigido;
  cout << "O grafo vai ser dirigido ou não? (y/n)\n";
  try{
  cin >> resposta;
  if(resposta != 'y' && resposta != 'n'){
    throw "\nInput Inválido, coloque y ou n\n";
    } 
  }catch(char const* message){
      cout << message << endl << endl;
      menuInicial();
    };
  if(resposta == 'y')
    ehDirigido = true;
  else
    ehDirigido = false;

  
  return ehDirigido;
  
}
int main() {
  bool ehDirigido2 = menuInicial();

  int** matrizAdj;
  
  int vertices,numVertice;
  cout << "Quantas vértices há no seu grafo?\n";
  cin >> vertices;
  
  matrizAdj = new int*[vertices];
  for (int i = 0;i<vertices;i++){
    matrizAdj[i] = new int[vertices]; //Se der pau, olhar aqui
    for(int j=0;j<vertices;j++)
      matrizAdj[i][j] = 0;
  }

  int i = 0;
  while(i < vertices){
    int cont = 0;
    try{
      cout << "Qual a adjacência da vértice " << i + 1 << " (escreva 0 para ir para a próxima vértice)\n";
      cin >> numVertice;
      if(numVertice == 0)
        i++;
      else{
        if(numVertice > vertices|| numVertice < 0)
          throw "Você é jumento\n";
        else{
          matrizAdj[i][numVertice - 1] = 1;
          if(ehDirigido2 == false)
            matrizAdj[numVertice - 1][i] = 1;
        }
          
        for (int i = 0;i<vertices;i++){
          cout << endl;
        for(int j=0;j<vertices;j++)
          cout << matrizAdj[i][j];
        }
      }
    } catch(char const* message){
        cout << message;
      }
  }
  cout << "banana";
}