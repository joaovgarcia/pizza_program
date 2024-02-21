#include "produto.h"
#include <stdio.h>

int selecionaProduto(PRODUTO* produto, int* escolhaProduto){

  printf("O que deseja pedir hoje?\n");
  printf("1 - Para lanche\n2 - Para pizza\n");
  
    int decisao;

    do{
      scanf(" %d", &decisao);
      *escolhaProduto = decisao;

    }while((decisao =! 1) && (decisao != 2));
  
  printf("%d\n", *escolhaProduto);
  return *escolhaProduto;
  

}

void selecionaTamanho(PRODUTO* produto){

  printf("Então qual tamanho deseja?\n");
  printf("P - Aperte (p) para pequena\nM - Aperte (m) para media\nG - Aperte (g) para grande\n\n");

  char tamanho;
  

  do{

  scanf(" %c", &tamanho);

    switch(tamanho){
      case 'p':
        produto->pizza.tamanho = 0;    
        break;

      case 'm':
        produto->pizza.tamanho = 1;
        break;

      case 'g':
        produto->pizza.tamanho = 2; 
        break;
    
      default:
       printf("Escolha uma opção\n");
       break;
    }

  } while(tamanho != 'p' && tamanho != 'm' && tamanho != 'g');

}

void selecionaSabor(PRODUTO* produto){

  printf("E sua produto vai ser de quê?\n");

  char opcao = 0;
  
  do{
    
    if(produto->escolhaProduto == 1){
    

      printf("1 - X-Burger\n2 - X-Tudo\n3 - X-Salada\n4 - X-Picanha\n5 - X-Frango\n\n");
      
      scanf(" %c", &opcao);

      switch(opcao){
        case '1':
          produto->lanche.sabor = 5;
          break;
        case '2':
          produto->lanche.sabor = 6;
          break;
        case '3':
          produto->lanche.sabor = 7;
          break;
        case '4':
          produto->lanche.sabor = 8;
          break;
        case '5':
          produto->lanche.sabor = 9;
          break;
      default:
        printf("Selecione um sabor!\n");
        opcao = 0;
        break;      
      }

    }else if(produto->escolhaProduto == 2) {

      printf("1 - Tradicional\n2 - Calabresa\n3 - Tomate seco e rúcula\n4 - Quatro queijos\n5 - Filé mingnon\n\n");
      
      scanf(" %c", &opcao);

      switch(opcao){
        case '1':
          produto->pizza.sabor = 0;
          break;
        case '2':
          produto->pizza.sabor = 1;
          break;
        case '3':
          produto->pizza.sabor = 2;
          break;
        case '4':
          produto->pizza.sabor = 3;
          break;
        case '5':
          produto->pizza.sabor = 4;
          break;
        default:
          printf("Selecione um sabor!\n");
          opcao = 0;
          break;
      }

    }

  }while(opcao == 0);

}


