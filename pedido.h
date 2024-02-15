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


