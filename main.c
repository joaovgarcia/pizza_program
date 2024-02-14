#include <stdio.h>

typedef enum tamanhopizza{
  pequena,
  media,
  grande
}TAMANHO;

typedef enum sabores{
  tradicional,
  calabresa,
  tomate_seco_rucula,
  quatro_queijos,
  file_mingnon
}SABOR;

typedef struct pizza{
  int SABOR;
  int TAMANHO;
  float valor;
}PIZZA;

void selecionaTamanho();
void selecionaSabor();
void calculaValor();
void mostraPedido(int sabor, int tamanho);
void novoPedido();
void Pedido();

PIZZA pedido;

int main(){
  
  printf("------ Bem vindo ao Pizza Program! ------\n\n");

  Pedido();
  
  mostraPedido(pedido.SABOR, pedido.TAMANHO);
  
  novoPedido();

}

void Pedido(){

  selecionaTamanho();

  selecionaSabor();

}


void novoPedido(){

  printf("Deseja fazer um novo pedido?\n\n");
  printf("Aperte (s) para pedir novamente. Ou aperte (x) para finalizar: ");

  char novopedido;
  scanf(" %c", &novopedido);
  switch (novopedido) {
    case 's':
      main();
      break;
    case 'x':
      break;
  }

}

void mostraPedido(int sabor, int tamanho){
  char* enum_tamanho[3] = {"pequena", "media", "grande"};
  char* enum_sabor[5] = {"Tradicional", "Calabresa", "Tomate Seco Rúcula", "Quatro queijos", "Filé mingnon"};


  printf("Pizza %s sabor %s.\n",enum_tamanho[tamanho], enum_sabor[sabor]);

}

void selecionaTamanho(){

  printf("Sabemos que veio atrás de pizza, então qual tamanho deseja?\n");
  printf("P - Aperte (p) para pequena\nM - Aperte (m) para media\nG - Aperte (g) para grande\n\n");

  char tamanho;
  
  do{

  scanf(" %c", &tamanho);

    switch(tamanho){
      case 'p':
        pedido.TAMANHO = pequena;
        break;

      case 'm':
        pedido.TAMANHO = media;
        break;

      case 'g':
        pedido.TAMANHO = grande;
        break;
    
      default:
       printf("Escolha uma opção\n");
       break;
    }

  } while(tamanho != 'p' && tamanho != 'm' && tamanho != 'g');

}

void selecionaSabor(){

  printf("E sua pizza vai ser de quê?\n");
  printf("1 - Tradicional\n2 - Calabresa\n3 - Tomate seco e rúcula\n4 - Quatro queijos\n5 - Filé mingnon\n\n");

  char opcao;

  do{

    scanf(" %c", &opcao);

    switch(opcao){
      case '1':
        pedido.SABOR = tradicional;
        break;
      case '2':
        pedido.SABOR = calabresa;
        break;
      case '3':
        pedido.SABOR = tomate_seco_rucula;
        break;
     case '4':
        pedido.SABOR = quatro_queijos;
        break;
      case '5':
        pedido.SABOR = file_mingnon;
        break;
      default:
        printf("Selecione um sabor!\n");
        opcao = 0;
        break;      
      }

  }while(opcao == 0);

}
