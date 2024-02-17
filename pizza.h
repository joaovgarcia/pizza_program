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

void selecionaTamanho(PIZZA* pizza);
void selecionaSabor(PIZZA* pizza);

