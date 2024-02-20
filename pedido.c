#include "pedido.h"
#include <stdio.h>

void adicionaPedido(PEDIDO* pedido, PEDIDO* listaDePedidos){
  
  listaDePedidos[pedido->numeroDoPedido] = *pedido;

  pedido->numeroDoPedido++;
  printf("Seu pedido foi adicionado com sucesso!\n\n");

}

void listarPedidos(PEDIDO* pedido, PEDIDO* listaDePedidos){

 
  for(int i = 0; i < pedido->numeroDoPedido; i++){
    printf("Pedido: %s\n", mostraPedido(&listaDePedidos[i]));
  }
}

char* mostraPedido(PEDIDO* pedido){
  char* enum_tamanho[3] = {"pequena", "media", "grande"};
  char* enum_sabor[5] = {"Tradicional", "Calabresa", "Tomate Seco Rúcula", "Quatro queijos", "Filé mingnon"};


  snprintf(pedido->pedidoInfo, sizeof(pedido->pedidoInfo),
           "Pizza %s sabor %s\nValor: %.2f\n",
           enum_tamanho[pedido->pizza.tamanho], enum_sabor[pedido->pizza.sabor], pedido->valorPedido);

  return pedido->pedidoInfo;

}

void calculaValor(PEDIDO* pedido){
  
  float valorTotal = 0;

  if(pedido->pizza.tamanho == pequena) {
    valorTotal+=24.59;
  }else if (pedido->pizza.tamanho == media) {
    valorTotal+=35.30;
  }else{
    valorTotal+=39.19;
  }

  switch(pedido->pizza.sabor){

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

  pedido->valorPedido = valorTotal;

}

void PedirPizza(PIZZA* pizza){
  
  selecionaTamanho(pizza);
  selecionaSabor(pizza);
}

void menu(PEDIDO* pedido, PEDIDO* listaDePedidos){
  
  printf("------ Bem vindo ao Pizza Program! ------\n\n");
  
  char continuar;
  

  do{
    
    printf("O que deseja fazer agora?\n");
    printf("1 - Para pedir pizza.\n2 - Para listar pedidos.\n");
    printf("Aperte (x) para sair\n\n");
    scanf(" %c", &continuar);

    switch(continuar){
      case '1':
        PedirPizza(&pedido->pizza);
        calculaValor(pedido);
        adicionaPedido(pedido, listaDePedidos);
        break;
      case '2':
        listarPedidos(pedido, listaDePedidos);
        break;
      case 'x':
        printf("Até mais!\n");
        break;
      default:
        printf("Escolha uma opção!\n\n");
        break;
    }

  }while(continuar != 'x');

}
