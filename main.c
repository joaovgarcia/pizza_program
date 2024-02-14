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
void mostraPedido(int sabor, int tamanho, float valor);
void novoPedido();
void Pedido();

PIZZA pedido;

int main(){
  
  printf("------ Bem vindo ao Pizza Program! ------\n\n");

  Pedido();

  mostraPedido(pedido.SABOR, pedido.TAMANHO, pedido.valor);
  
  novoPedido();

}

void Pedido(){

  selecionaTamanho();

  selecionaSabor();

  calculaValor();

}

void calculaValor(){
  
  float valorTotal = 0;

  if(pedido.TAMANHO == pequena) {
    valorTotal+=24.59;
  }else if (pedido.TAMANHO == media) {
    valorTotal+=35.30;
  }else{
    valorTotal+=39.19;
  }

  switch(pedido.SABOR){

    case 0:
      valorTotal+=5.79;
      break;
    case 1:
      valorTotal+=7.49;
      break;
    case 2:
      valorTotal+=4.00;
      break;
    case 3:
      valorTotal+=8.50;
      break;
    case 4:
      valorTotal+=11.69;
      break;
    default:
      printf("Isso não era pra ter acontecido!\n");
      return;
  }

  pedido.valor = valorTotal;

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

void mostraPedido(int sabor, int tamanho, float valor){
  char* enum_tamanho[3] = {"pequena", "media", "grande"};
  char* enum_sabor[5] = {"Tradicional", "Calabresa", "Tomate Seco Rúcula", "Quatro queijos", "Filé mingnon"};


  printf("Pizza %s sabor %s.\nTOTAL: %.2f\n\n",enum_tamanho[tamanho], enum_sabor[sabor], pedido.valor);

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
