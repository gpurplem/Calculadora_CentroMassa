#include "cabecalhos.h"

void funcao_CalcularCM(int num_corpos, t_corpo *ptr, char mapa[20][50])
{
	float massa_tmp = 0.0;
	float massa_total = 0.0;
	float x_total = 0.0, x_tmp = 0.0;
  float y_total = 0.0, y_tmp = 0.0;

  for (int z = 0; z < num_corpos; z++)
  {
    if (ptr[z].nome[0] == 'c')
    {
      massa_tmp = ptr[z].massa;
      massa_tmp = massa_tmp + massa_total;
      massa_total = massa_tmp;
    }
  }
  for (int z = 0; z < num_corpos; z++)
  {
    if (ptr[z].nome[0] == 'c')
    {
      x_tmp = ptr[z].x * ptr[z].massa;
      x_tmp = x_tmp + x_total;
      x_total = x_tmp;
    }
  }
  for (int z = 0; z < num_corpos; z++)
  {
    if (ptr[z].nome[0] == 'c')
    {
      y_tmp = ptr[z].y * ptr[z].massa;
      y_tmp = y_tmp + y_total;
      y_total = y_tmp;
    }
  }

  for (int b = 0; b < num_corpos; b++)
  {
    if (ptr[b].nome[0] == 'c')
    {
      if (massa_total / (num_corpos - 1) < ptr[b].massa)
      {
        mapa[ptr[b].y][ptr[b].x] = 'X';
      }
      else if (massa_total / (num_corpos - 1) >= ptr[b].massa)
      {
        mapa[ptr[b].y][ptr[b].x] = 'x';
      }
    }
  }
  putchar('\n');
  putchar('\n');

  mapa[(int)(y_total / massa_total)][(int)(x_total / massa_total)] = '@';

  for (int l = 0; l < 20; l++)
  {
    for (int c = 0; c < 50; c++)
    {
      if (mapa[l][c] == 'x' || mapa[l][c] == 'X')
      {
        if (mapa[l][c + 1] == ' ' && mapa[l][c + 2] == ' ' && mapa[l][c + 3] == ' ' && mapa[l][c + 4] == ' ' && c < 46)
        {
          for (int p = 0; p < num_corpos; p++)
          {
            if (ptr[p].y == l && ptr[p].x == c && ptr[p].nome[0] == 'c')
            {
              mapa[l][c + 1] = '(';
              mapa[l][c + 2] = ptr[p].nome[0];
              mapa[l][c + 3] = ptr[p].nome[1];
              mapa[l][c + 4] = ')';
            }
          }
        }
      }

      if (mapa[l][c] == '@')
      {
        int yyy, xxx;
        int prim_y, seg_y, prim_x, seg_x;
        yyy = (int)(y_total / massa_total);
        xxx = (int)(x_total / massa_total);

        prim_y = yyy / 10;
        seg_y = yyy - (prim_y * 10);
        prim_x = xxx / 10;
        seg_x = xxx - (prim_x * 10);

        if (mapa[l][c + 1] == ' ' && mapa[l][c + 2] == ' ' && mapa[l][c + 3] == ' ' && mapa[l][c + 4] == ' ' && mapa[l][c + 5] == ' ' && mapa[l][c + 6] == ' ' && mapa[l][c + 7] == ' ' && c < 42)
        {
          mapa[l][c + 1] = '(';
          mapa[l][c + 2] = (char)prim_y + '0';
          mapa[l][c + 3] = (char)seg_y + '0';
          mapa[l][c + 4] = ',';
          mapa[l][c + 5] = (char)prim_x + '0';
          mapa[l][c + 6] = (char)seg_x + '0';
          mapa[l][c + 7] = ')';
        }
      }
    }
  }

  f_mapa(mapa);

  massa_total = 0.0;
  x_total = 0.0;
  y_total = 0.0;

  for (int a = 0; a < 20; a++)
  {
    for (int b = 0; b < 50; b++)
    {
      mapa[a][b] = ' ';
    }
  }
}