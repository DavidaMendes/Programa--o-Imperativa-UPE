/*
  Alunos:
    BOSCO LOURIMAR BEZERRA DE LIMA FILHO
    DAVI GOMES MANDES 
*/

#include <stdio.h>
#include <string.h> 
#include "struct.h"
#include "functions.h"


int main()
{
  Cadastro *usuarios = calloc(10, sizeof(Cadastro));
  
  int opcao = 0, contador = 0;

  if(contador >= 10){
    printf("Limite de usuarios atingido");
    return 0;
  }

  do{
    telaInicial();
    
    scanf("%d", &opcao);
    switch(opcao){
      case 1:
        login(usuarios);
        break;
      case 2:
        if (contador >= 10) {
          printf("Limite de usuários atingido\n");
        } else {
          cadastro(usuarios, contador);
          contador++;
          break;
        }
      case 3:
        listarUsuarios(usuarios, contador);
        break;
      case 4:
        deletarUsuarios(usuarios, &contador);
        break;
      case 5:
        printf("Sair");
        break;
      default:  
        printf("Opcao invalida");
        free(usuarios);
      }  

    
  }while(opcao != 5);

  free(usuarios);

  return 0;
}