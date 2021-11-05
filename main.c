#include "cabecalhos.h"

int main()
{
  printf("\n         ***Calculadora de Centro de Massa***\n\n");

	//Vars corpo e menu.
  char corpo_a_deletar[3];
  char corpo_a_modificar[3];
  int i;
  int Opcao_menu;

	//Vars massa.
  int cont_del = 0, cont_del_;

	//Corpos.
  t_corpo *ptr = (t_corpo *)malloc(sizeof(t_corpo) * 1);
  int num_corpos = 1;

	//Inicializa mapa vazio.
  char mapa[20][50];
  for (int r = 0; r < 20; r++)
  {
    for (int s = 0; s < 50; s++)
    {
      mapa[r][s] = ' ';
    }
  }

  do
  {
    puts("   *MENU*\n1 - Adicionar\n2 - Remover\n3 - Modificar\n4 - Sair\n");
    scanf("%d", &Opcao_menu);
    if (Opcao_menu < 1 || Opcao_menu > 4)
    {
      printf("\n\nOpção Inválida. Tente novamente\n\n");
    }

    switch (Opcao_menu)
    {
    case 1:
      i = espaco_vazio(ptr, num_corpos);

			adicionar(ptr, i);

      num_corpos++;

      ptr = (t_corpo *)realloc((t_corpo *)ptr, sizeof(t_corpo) * num_corpos);

      funcao_CalcularCM(num_corpos, ptr, mapa);
      break;

    case 2:
      if (num_corpos == 1)
      {
        printf("\nUnderflow.\n\n");
        break;
      }
      printf("Qual o nome do corpo: \n");
      scanf("%s", corpo_a_deletar);

      for (cont_del = 0; cont_del < num_corpos - 1; cont_del++)
      {
        if ((strcmp(ptr[cont_del].nome, corpo_a_deletar)) == 0)
        {
          strcpy(ptr[cont_del].nome, "0");
          cont_del_ = cont_del;
          break;
        }
      }

      funcao_CalcularCM(num_corpos, ptr, mapa);
      break;

    case 3:
			if (num_corpos == 1)
      {
        printf("\nNão há corpos ainda.\n\n");
        break;
      }

			alterar(corpo_a_modificar, num_corpos, ptr);

      funcao_CalcularCM(num_corpos, ptr, mapa);
    }
  } while (Opcao_menu != 4);

  return 0;
}