#include "cabecalhos.h"

	void alterar(char corpo_a_modificar[], int num_corpos, t_corpo* ptr){

		int n_x = 0, n_y = 0;
  	int cont_mod = 0, cont_mod_ = 0;
		float n_massa;
	
		printf("Qual o nome do corpo: \n");
		scanf("%s", corpo_a_modificar);
		fflush(stdin);
		printf("Qual a nova massa do corpo: \n");
		scanf("%f", &n_massa);
		fflush(stdin);
		printf("Informe a nova coordenada x e y (x y): \n");
		scanf("%d %d", &n_y, &n_x);
		fflush(stdin);

		for (cont_mod = 0; cont_mod < num_corpos - 1; cont_mod++)
		{
			if ((strcmp(ptr[cont_mod].nome, corpo_a_modificar)) == 0)
			{
				cont_mod_ = cont_mod;
				ptr[cont_mod_].massa = n_massa;
				ptr[cont_mod_].y = n_y;
				ptr[cont_mod_].x = n_x;
				break;
			}
		}	
}