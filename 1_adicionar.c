#include "cabecalhos.h"

void adicionar(t_corpo* ptr, int i){
		printf("Qual o nome do corpo (comece com 'c'): \n");
		scanf("%s", ptr[i].nome);
		fflush(stdin);

		printf("Qual a massa do corpo: \n");
		scanf("%f", &ptr[i].massa);
		fflush(stdin);

		printf("Informe a coordenada linha e coluna: \n");
		scanf("%d %d", &ptr[i].y, &ptr[i].x);
		fflush(stdin);
}
		  