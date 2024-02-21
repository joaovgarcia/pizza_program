#include "produto.h"
#include <stdio.h>

#define LIST_SIZE 999

typedef struct pedido{
 
  char pedidoInfo[LIST_SIZE];
  PRODUTO produto;
  float valorPedido;
  int numeroDoPedido;

}PEDIDO;

void menu(PEDIDO* pedido, PEDIDO* listaDePedidos);
void Pedir(PRODUTO* produto);
void calculaValor(PEDIDO* pedido);
void adicionaPedido(PEDIDO* pedido, PEDIDO* listaDePedidos);
void listarPedidos(PEDIDO* pedido, PEDIDO* listaDePedidos);
char* mostraPedido(PEDIDO* pedido);
