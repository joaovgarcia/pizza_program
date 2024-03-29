#include "pedido.h"
#include <stdio.h>

void adicionaPedido(PEDIDO* pedido, PEDIDO* listaDePedidos){
    
  printf("Confirmar pedido: %s?\n\n", mostraPedido(pedido));
  
  char escolha = 0;

  do{
    printf("Aperte (s) para confirmar OU aperte (n) para cancelar.\n");
    scanf(" %c", &escolha);
    if(escolha != 's' && escolha != 'n'){
      printf("Selecione uma opção!\n"); 
      escolha = 0;
    }else if(escolha == 'n'){
      printf("Pedido cancelado!\n\n"); 
      return;
    }
  }while(escolha == 0);
  printf("Seu pedido foi adicionado com sucesso!\n\n");

  listaDePedidos[pedido->numeroDoPedido] = *pedido;
  pedido->numeroDoPedido++;
}

void listarPedidos(PEDIDO* pedido, PEDIDO* listaDePedidos){
char sair = 0;

  printf("Aperte qualquer tecla para sair.\n");
do{
  for(int i = 0; i < pedido->numeroDoPedido; i++){
    printf("%s",mostraPedido(&listaDePedidos[i]));
  }
}while (scanf(" %c", &sair) == 0); 
}

char* mostraPedido(PEDIDO* pedido){
  char* enum_tamanho[3] = {"pequena", "media", "grande"};
  char* enum_sabor[10] = {"Tradicional", "Calabresa", "Tomate Seco Rúcula", "Quatro queijos", "Filé mingnon",
    "X-Burger", "X-Tude", "X-Salada", "X-Picanha", "X-Frango"};

  if(pedido->produto.escolhaProduto == 1){
    snprintf(pedido->pedidoInfo, sizeof(pedido->pedidoInfo),
           "Pedido lanche sabor %s\nValor: %.2f\n",
            enum_sabor[pedido->produto.lanche.sabor], pedido->valorPedido);
  }
  if(pedido->produto.escolhaProduto == 2){
    snprintf(pedido->pedidoInfo, sizeof(pedido->pedidoInfo),
           "Pedido pizza %s sabor %s\nValor: %.2f\n",
            enum_tamanho[pedido->produto.pizza.tamanho], enum_sabor[pedido->produto.pizza.sabor], pedido->valorPedido);

  }
  return pedido->pedidoInfo;
}

void calculaValor(PEDIDO* pedido){
  
  float valorTotal = 0;

  if(pedido->produto.escolhaProduto == 1) {

    switch(pedido->produto.lanche.sabor){

      case 5:
        valorTotal+=5.10;
        break;
      case 6:
        valorTotal+=6.49;
        break;
      case 7:
        valorTotal+=7.00;
        break;
      case 8:
        valorTotal+=6.20;
        break;
      case 9:
        valorTotal+=4.60;
        break;
      default:
        printf("Isso não era pra ter acontecido!\n");
        return;
    }
  }else if(pedido->produto.escolhaProduto == 2){

    if(pedido->produto.pizza.tamanho == 0)
      valorTotal+=5.00;
    else if(pedido->produto.pizza.tamanho == 0)
      valorTotal+=10.00;
    else
      valorTotal+=15;

     switch(pedido->produto.pizza.sabor){

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

  }
  pedido->valorPedido = valorTotal;
}

void Pedir(PRODUTO* produto){
 
  selecionaProduto(produto, &produto->escolhaProduto);
    if(produto->escolhaProduto == 2){
      selecionaTamanho(produto);
      selecionaSabor(produto);
    }
    if(produto->escolhaProduto == 1){
      selecionaSabor(produto);
    }

}

void menu(PEDIDO* pedido, PEDIDO* listaDePedidos){
  
  printf("------ Bem vindo! ------\n\n");
  
  char continuar;
  

  do{
    
    printf("Selecione uma opção:\n\n");
    printf("1 - Aperte (1) Para pedir.\n2 - Aperte (2) Para listar pedidos\n");
    printf("Aperte (x) para sair\n\n");
    scanf(" %c", &continuar);

    switch(continuar){
      case '1':
        Pedir(&pedido->produto);
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
