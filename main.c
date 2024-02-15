#include <string.h>
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
  SABOR sabor;
  TAMANHO tamanho;
  float valorPizza;
}PIZZA;

typedef struct pedido{
 
  char pedidoInfo[99];
  PIZZA pizza;
  float valorPedido;
  int numeroDoPedido;

}PEDIDO;

void selecionaTamanho();
void selecionaSabor();
void calculaValor();
char* mostraPedido(PEDIDO* pedido);
void novoPedido();
void adicionaPedido();
void listarPedidos();
void Pedido();

PEDIDO listaDePedidos[99];
PEDIDO pedido;

int main(){
  
  printf("------ Bem vindo ao Pizza Program! ------\n\n");

  Pedido();

  novoPedido();

  return 0;

}

void Pedido(){

  selecionaTamanho();

  selecionaSabor();

  calculaValor();

  adicionaPedido();

  listarPedidos();

    
}

void adicionaPedido(){
  
  for(int i = pedido.numeroDoPedido; i <= pedido.numeroDoPedido; i++){
    listaDePedidos[i] = pedido;
    break;
  }

  pedido.numeroDoPedido++;
  printf("Seu pedido foi adicionado com sucesso!\n");

}

void listarPedidos(){

 
  for(int i = 0; i < pedido.numeroDoPedido; i++){
    printf("Pedido: %s\n", mostraPedido(&listaDePedidos[i]));
  }
}

char* mostraPedido(PEDIDO* pedido){
  char* enum_tamanho[3] = {"pequena", "media", "grande"};
  char* enum_sabor[5] = {"Tradicional", "Calabresa", "Tomate Seco Rúcula", "Quatro queijos", "Filé mingnon"};


 /*printf("Pedido numero: %d - Pizza %s sabor %s.\nTOTAL: %.2f\n\n",
         pedido.numeroDoPedido+1, enum_tamanho[pedido.pizza.tamanho], enum_sabor[pedido.pizza.sabor], pedido.valorPedido);*/
  
  
  snprintf(pedido->pedidoInfo, sizeof(pedido->pedidoInfo),
           "Pizza %s sabor %s\nValor: %.2f",
           enum_tamanho[pedido->pizza.tamanho], enum_sabor[pedido->pizza.sabor], pedido->valorPedido);

  return pedido->pedidoInfo;

}


void calculaValor(){
  
  float valorTotal = 0;

  if(pedido.pizza.tamanho == pequena) {
    valorTotal+=24.59;
  }else if (pedido.pizza.tamanho == media) {
    valorTotal+=35.30;
  }else{
    valorTotal+=39.19;
  }

  switch(pedido.pizza.sabor){

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

  pedido.valorPedido = valorTotal;

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

void selecionaTamanho(){

  printf("Sabemos que veio atrás de pizza, então qual tamanho deseja?\n");
  printf("P - Aperte (p) para pequena\nM - Aperte (m) para media\nG - Aperte (g) para grande\n\n");

  char tamanho;
  
  do{

  scanf(" %c", &tamanho);

    switch(tamanho){
      case 'p':
        pedido.pizza.tamanho = pequena;
        break;

      case 'm':
        pedido.pizza.tamanho = media;
        break;

      case 'g':
        pedido.pizza.tamanho = grande;
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
        pedido.pizza.sabor = tradicional;
        break;
      case '2':
        pedido.pizza.sabor = calabresa;
        break;
      case '3':
        pedido.pizza.sabor = tomate_seco_rucula;
        break;
     case '4':
        pedido.pizza.sabor = quatro_queijos;
        break;
      case '5':
        pedido.pizza.sabor = file_mingnon;
        break;
      default:
        printf("Selecione um sabor!\n");
        opcao = 0;
        break;      
      }

  }while(opcao == 0);

}


