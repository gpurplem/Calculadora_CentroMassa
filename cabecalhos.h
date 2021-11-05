#ifndef __CABE__
#define __CABE__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _corpo_
{
  char nome[3];
  float massa;
  int x;
  int y;
} t_corpo;

void funcao_CalcularCM(int num_corpos, t_corpo *ptr, char mapa[20][50]);

int espaco_vazio(t_corpo *ptr, int num_corpos_total);

void f_mapa(char mapa[20][50]);

void adicionar(t_corpo* ptr, int i);
void alterar(char corpo_a_modificar[], int num_corpos, t_corpo* ptr);

#endif