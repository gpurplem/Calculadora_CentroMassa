#include "cabecalhos.h"

//Mostra mapa atualizado.
void f_mapa(char mapa[20][50])
{
  for (int a = 0; a < 20; a++)
  {
    for (int b = 0; b < 50; b++)
    {
      printf("%c", mapa[a][b]);
    }
    putchar('\n');
  }
  putchar('\n');
}