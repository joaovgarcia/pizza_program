#include <stdio.h>

enum tamanho{
  pequena,
  media,
  grande
};

enum sabores{
  tradicional,
  calabresa,
  tomate_seco_rucula,
  quatro_queijos,
  file_mingnon,
  xburger,
  xtudo,
  xsalada,
  xpicanha,
  xfrango,
};

typedef enum tamanho TAMANHO;
typedef enum sabores SABOR;

typedef struct lanche LANCHE;
typedef struct pizza PIZZA;
typedef  struct produto PRODUTO;



struct lanche{
  
  SABOR sabor;
  float valorLanche;

};

struct pizza{
  SABOR sabor;
  TAMANHO tamanho;
  float valorPizza;
};

struct produto {
  union{
    LANCHE lanche;
    PIZZA pizza; 
  };
  int escolhaProduto;
};

void selecionaTamanho(PRODUTO* produto);
void selecionaSabor(PRODUTO* produto);
int selecionaProduto(PRODUTO* produto, int* escolhaProduto);
