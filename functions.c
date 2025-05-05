/*
  Alunos:
    BOSCO LOURIMAR BEZERRA DE LIMA FILHO
    DAVI GOMES MANDES 
*/

#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

void editarInformacao(Cadastro *usuarios, int indice){
  int opcao = 0;

  do {
    printf("\nEscolha uma opcao para editar:\n");
    printf("1 - Editar Login\n2 - Editar Senha\n3 - Editar Nome\n4 - Editar Endereco\n5 - Editar Telefone\n6 - Editar Data de Nascimento\n7 - Sair\nResposta: ");
    scanf("%d", &opcao);

    switch(opcao){
      case 1:
        printf("Novo Login: ");
        scanf("%s", usuarios[indice].login);
        break;
      case 2:
        printf("Nova Senha: ");
        scanf("%s", usuarios[indice].senha);
        break;
      case 3:
        printf("Novo Nome: ");
        scanf("%s", usuarios[indice].nome);
        break;
      case 4:
        printf("Novo Endereco: ");
        scanf("%s", usuarios[indice].endereco);
        break;
      case 5:
        printf("Novo Telefone: ");
        scanf("%s", usuarios[indice].telefone);
        break;
      case 6:
        printf("Nova Data de Nascimento: ");
        scanf("%s", usuarios[indice].dataNascimento);
        break;
      case 7:
        printf("Saindo da edição...\n");
        break;
      default:
        printf("Opcao invalida\n");
        break;
    }
  } while(opcao != 7);
}


void login(Cadastro *usuarios){
  char login[20];
  char senha[20];
  printf("Login: \n");
  scanf("%s", login);
  printf("Senha: \n");
  scanf("%s", senha);

  for(int i = 0; i < 10; i++){
    if(strcmp(usuarios[i].login, login) == 0 && strcmp(usuarios[i].senha, senha) == 0){
      printf("Login realizado com sucesso\n");

      int opcao = 0;
      do {
        printf("1 - Editar Informacao\n2 - Voltar a Tela Inicial\nResposta: ");
        scanf("%d", &opcao);

        switch(opcao){
          case 1:
            editarInformacao(usuarios, i);
            break;
          case 2:
            printf("Voltando à tela inicial...\n");
            break;
          default:
            printf("Opcao invalida\n");
            break;
        }
      } while(opcao != 2);

      return; 
    }
  }

  printf("Login ou senha incorretos\n");
}



void cadastro(Cadastro *usuarios, int indice){
  printf("Login: \n");
  scanf("%s", usuarios[indice].login); 
  printf("Senha: \n");
  scanf("%s", usuarios[indice].senha);  
  printf("Nome: \n");
  scanf("%s", usuarios[indice].nome);  
  printf("Endereco: \n");
  scanf("%s", usuarios[indice].endereco);
  printf("Telefone: \n");
  scanf("%s", usuarios[indice].telefone);
  printf("Nascimento: (dd/mm/aaaa) \n");
  scanf("%s", usuarios[indice].dataNascimento); 
}

void listarUsuarios(Cadastro *usuarios, int indice) {
    printf("Nome | Telefone | Endereco | Nascimento\n\n");

    for (int i = 0; i < indice; i++) {
        printf("%s | %s | %s |%s\n", usuarios[i].nome, usuarios[i].endereco, usuarios[i].telefone, usuarios[i].dataNascimento);
    }
}

void deletarUsuarios(Cadastro *usuarios, int *indice) {
    int opcao;
    printf("\n1 - Deletar todos os usuarios\n2 - Deletar usuario especifico\n3 - Voltar\nEscolha uma opcao: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        *indice = 0; 
        printf("Todos os usuários foram deletados.\n");
    } else if (opcao == 2) {
        char nome[30];
        int encontrado = 0;
        printf("Digite o nome do usuario que deseja deletar: ");
        scanf("%s", nome);

        for (int i = 0; i < *indice; i++) {
            if (strcmp(usuarios[i].nome, nome) == 0) {

                for (int j = i; j < *indice - 1; j++) {
                    usuarios[j] = usuarios[j + 1];
                }
                (*indice)--;
                printf("Usuário deletado com sucesso.\n");
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            printf("Usuário não encontrado.\n");
        }
    } else if (opcao == 3) {
        printf("Voltando...\n");
    } else {
        printf("Opcao invalida.\n");
    }
}


void telaInicial(){
  printf("---Registrador Sistema---\n");
  printf("1 - Fazer Login\n2 - Fazer Cadastro\n3 - Mostrar Usuários\n4 - Deletar Usuários\n5 - Sair\nResposta:");
}
