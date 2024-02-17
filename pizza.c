#include "pizza.h"
#include <stdio.h>

void selecionaTamanho(PIZZA* pizza){

  printf("Então qual tamanho deseja?\n");
  printf("P - Aperte (p) para pequena\nM - Aperte (m) para media\nG - Aperte (g) para grande\n\n");

  char tamanho;
  
  do{

  scanf(" %c", &tamanho);

    switch(tamanho){
      case 'p':
        pizza->tamanho = pequena;        
        break;

      case 'm':
        pizza->tamanho = media;
        break;

      case 'g':
        pizza->tamanho = grande;
        break;
    
      default:
       printf("Escolha uma opção\n");
       break;
    }

  } while(tamanho != 'p' && tamanho != 'm' && tamanho != 'g');

}

void selecionaSabor(PIZZA* pizza){

  printf("E sua pizza vai ser de quê?\n");
  printf("1 - Tradicional\n2 - Calabresa\n3 - Tomate seco e rúcula\n4 - Quatro queijos\n5 - Filé mingnon\n\n");

  char opcao;

  do{

    scanf(" %c", &opcao);

    switch(opcao){
      case '1':
        pizza->sabor = tradicional;
        break;
      case '2':
        pizza->sabor = calabresa;
        break;
      case '3':
        pizza->sabor = tomate_seco_rucula;
        break;
     case '4':
        pizza->sabor = quatro_queijos;
        break;
      case '5':
        pizza->sabor = file_mingnon;
        break;
      default:
        printf("Selecione um sabor!\n");
        opcao = 0;
        break;      
      }

  }while(opcao == 0);

}


