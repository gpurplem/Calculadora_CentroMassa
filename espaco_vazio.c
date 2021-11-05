#include "cabecalhos.h"

//Percorre lista de corpos e deleta aquele que não começa com 'c'.
int espaco_vazio(t_corpo *ptr, int num_corpos_total)
{
  int ind = 0;
  for (ind = 0; ind < num_corpos_total; ind++)
  {
    if (ptr[ind].nome[0] != 'c')
    {
      break;
    }
    else
      continue;
  }
  return ind;
}