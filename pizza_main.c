#include "pedido.h"
#include <stdio.h>

int main(){
 
  PEDIDO pedido = {.pedidoInfo = {0}};
  PEDIDO listaDePedidos[LIST_SIZE] = {0};

  menu(&pedido, listaDePedidos);
   
  return 0;

}



