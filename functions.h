/*
  Alunos:
    BOSCO LOURIMAR BEZERRA DE LIMA FILHO
    DAVI GOMES MANDES 
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "struct.h"

void cadastro(Cadastro *usuarios, int indice);
void listarUsuarios(Cadastro *usuarios, int indice);
void editarInformacao(Cadastro *usuarios, int indice);
void login(Cadastro *usuarios);
void deletarUsuarios(Cadastro *usuarios, int *indice);
void telaInicial(void);

#endif //FUNCTIONS_H