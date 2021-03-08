#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#define VetorA 2000
#define	VetorB 200000

//gerador de vetor
void criar(int *vetA, int *vetB)
{	
	int i, seed;

    puts("Qual o valor da semente de geracao aleatoria (entre 0 e 1000)?");
    scanf("%d",&seed);
    srand(seed);
    
    for (i=0; i < 2000; i++)
       vetA[i] = rand( )%100000;

    for (i=0; i < 200000; i++)
       vetB[i] = rand( )%100000;
      
	system("clear");   
}

//bubble sort
void bolha(int *vetB, double *segundos_main)
{
	int aux;
	double segundos;
	struct timeval comeco, fim;
	
	gettimeofday(&comeco, NULL);
	
	for (int i=0; i<VetorB-1; i++)
	{
		for (int j=0; j<VetorB-1-i; j++)
		{
			if (vetB[j] > vetB[j+1])
			{
				aux = vetB[j];
				vetB[j] = vetB[j+1];
				vetB[j+1] = aux;
				
			}
		}
	}

	gettimeofday(&fim, NULL);
	
	segundos = (fim.tv_sec - comeco.tv_sec) + ((fim.tv_usec - comeco.tv_usec)/1000000.0);
	(*segundos_main) = segundos;
	
	printf("Tempo de execucao (bubble)    : %f \n", segundos);
	
}

//ordenar por insercao
void insertion(int *vetB, double *segundos_main)
{
	int j;
	int aux;
	double segundos;
	struct timeval comeco, fim;
	
	gettimeofday(&comeco, NULL);
	
	for (int i=1; i<VetorB; i++)
	{
		aux = vetB[i];
		j = i-1;
		
		while ( j >= 0 && vetB[j] > aux)
		{
			vetB[j+1] = vetB[j];
			j--;
		}
		
		vetB[j+1] = aux;
	
	}

	gettimeofday(&fim, NULL);
	
	segundos = (fim.tv_sec - comeco.tv_sec) + ((fim.tv_usec - comeco.tv_usec)/1000000.0);
	(*segundos_main) = segundos;
	
	printf("Tempo de execucao (insercao)  : %f \n", segundos);
	
}

//ordenar por selecao
void selection(int *vetB, double *segundos_main)
{
	int aux;
	int aux2;
	double segundos;
	struct timeval comeco, fim;
	
	gettimeofday(&comeco, NULL);
	
	for (int i=0; i<VetorB; i++)
	{
		aux = i;
		
		for (int j=i+1; j<VetorB; j++)
		{
			if ( vetB[j] < vetB[aux])
			{
				aux = j;
			}
		}
		
		aux2 = vetB[i];
		vetB[i] = vetB[aux];
		vetB[aux] = aux2;
		
	}

	gettimeofday(&fim, NULL);
	
	segundos = (fim.tv_sec - comeco.tv_sec) + ((fim.tv_usec - comeco.tv_usec)/1000000.0);
	(*segundos_main) = segundos;
	
	printf("Tempo de execucao (selection) : %f \n", segundos);
}

//busca sequencial
void sequencial(int *vetA, int *vetB, double *segundos_busca)
{
	int contador=0;
	bool sair=false;
	double segundos;
	struct timeval comeco, fim;
	
	gettimeofday(&comeco, NULL);
	
	for (int i=0; i<VetorA; i++)
	{
		for (int j=0; j<VetorB && !sair; j++)
		{
			if ( vetA[i] == vetB[j])
			{
				contador++;
				sair = true;
			}
		}
		
		sair = false;		
	}
	
	gettimeofday(&fim, NULL);
	
	
	segundos = (fim.tv_sec - comeco.tv_sec) + ((fim.tv_usec - comeco.tv_usec)/1000000.0);
	(*segundos_busca) = segundos;
	
	printf("Tempo de execucao (sequencial): %f \n", segundos);
	printf("Contador                      : %d \n", contador);
	
}

//busca binaria
void binaria(int *vetA, int *vetB, double *segundos_busca)
{
	int low;
	int high;
	int meio;
	int contador=0;
	bool sair=false;
	double segundos;
	struct timeval comeco, fim;
	
	gettimeofday(&comeco, NULL);
	
	for (int i=0; i<VetorA; i++)
	{
		low = 0;
		high = VetorB-1;
		meio = (high + low)/2;
		sair=false;
		
		while (low <= high && !sair)
		{
			if (vetB[meio] == vetA[i])
			{
				contador++;
				sair = true;		
			}
			
			if (vetB[meio] < vetA[i])
			{
				low = meio+1;
			}
			
			else
				high = meio-1;
			
			meio = (high + low)/2;	
		}		
	}
	
	gettimeofday(&fim, NULL);
	
	
	segundos = (fim.tv_sec - comeco.tv_sec) + ((fim.tv_usec - comeco.tv_usec)/1000000.0);
	(*segundos_busca) = segundos;
	
	printf("Tempo de execucao (binaria)   : %f \n", segundos);
	printf("Contador                      : %d \n", contador);
}

//busca ponderada
void ponderada(int *vetA, int *vetB, double *segundos_busca)
{
	int low;
	int high;
	int meio;
	int contador=0;
	bool sair=false;
	double segundos;
	struct timeval comeco, fim;
	
	gettimeofday(&comeco, NULL);
	
	for (int i=0; i<VetorA; i++)
	{
		low = 0;
		sair=false;
		high = VetorB-1;
		
		while (low <= high && vetA[i] >= vetB[low] && vetA[i] <= vetB[high] && !sair)
		{
			meio = low + (((double)(high - low) / (vetB[high] - vetB[low])) * (vetA[i] - vetB[low]));
			
			if (vetB[meio] == vetA[i])
			{
				contador++;
				sair = true;		
			}
			
			if (vetB[meio] < vetA[i])
			{
				low = meio+1;
			}
			
			else
				high = meio-1;
			
			meio = (high + low)/2;	
		}		
	}
	
	gettimeofday(&fim, NULL);
	
	
	segundos = (fim.tv_sec - comeco.tv_sec) + ((fim.tv_usec - comeco.tv_usec)/1000000.0);
	(*segundos_busca) = segundos;
	
	printf("Tempo de execucao (ponderada) : %f \n", segundos);
	printf("Contador                      : %d \n", contador);
}

//soma de tempos
void soma(double *seg, double *ord)
{
	printf("Soma dos segundos             : %f \n\n", (*seg)+(*ord));
	
}

//funcao principal
int main()
{
	bool sair=false;
	int a[VetorA], b[VetorB];
	double segundos_busca; //segundos que demoraram para realizar a busca
	double segundos_ord; //segundos que demoraram para realizar a ordenacao 
	
    int opcao;
    
    while (!sair)
    {	
		//menu
	    printf(" //METODOS DE ORDENACAO E DE BUSCA//  \n\n");
	    printf("1  - Busca sequencial com vetor B desordenado  \n2  - Busca sequencial com vetor B ordenado pelo bubble sort  \n3  - Busca binaria    com vetor B ordenado pelo bubble sort \n");
	    printf("4  - Busca ponderada  com vetor B ordenado pelo bubble sort  \n5  - Busca sequencial com vetor B ordenado pelo insertion sort  \n");
	    printf("6  - Busca binaria    com vetor B ordenado pelo insertion sort \n7  - Busca ponderada  com vetor B ordenado pelo insertion sort \n");
	    printf("8  - Busca sequencial com vetor B ordenado pelo selection sort \n9  - Busca binaria    com vetor B ordenado pelo selection sort \n");
	    printf("10 - Busca ponderada  com vetor B ordenado pelo selection sort \n11 - Sair \n");
	    printf("\n");
	    printf("Opcao: \t");
	    
	    scanf("%d", &opcao);
	    printf("\n");
	    
	    switch (opcao) {
	    case 1:
	        criar(a, b);
	        sequencial(a, b, &segundos_busca);
	        soma(&segundos_busca, &segundos_ord);
	        break;
	    case 2:
	        criar(a, b);
	        bolha(b, &segundos_ord);
	        sequencial(a, b, &segundos_busca);
	        soma(&segundos_busca, &segundos_ord);
	        break;
	    case 3:
	        criar(a, b);
	        bolha(b, &segundos_ord);
	        binaria(a, b, &segundos_busca);
	        soma(&segundos_busca, &segundos_ord);
	        break;
	    case 4:
	        criar(a, b);
	        bolha(b, &segundos_ord);
	        ponderada(a, b, &segundos_busca);
	        soma(&segundos_busca, &segundos_ord);
	        break;
		case 5:
	        criar(a, b);
	        insertion(b, &segundos_ord);
	        sequencial(a, b, &segundos_busca);
	        soma(&segundos_busca, &segundos_ord);
	        break;
		case 6:
	        criar(a, b);
	        insertion(b, &segundos_ord);
	        binaria(a, b, &segundos_busca);
	        soma(&segundos_busca, &segundos_ord);
	        break;
		case 7:
	        criar(a, b);
	        insertion(b, &segundos_ord);
	        ponderada(a, b, &segundos_busca);
	        soma(&segundos_busca, &segundos_ord);
	        break;
		case 8:
	        criar(a, b);
	        selection(b, &segundos_ord);
	        sequencial(a, b, &segundos_busca);
	        soma(&segundos_busca, &segundos_ord);
	        break;
		case 9:
			criar(a, b);
			selection(b, &segundos_ord);
			binaria(a, b, &segundos_busca);
			soma(&segundos_busca, &segundos_ord);
			break;
		case 10:
			criar(a, b);
			selection(b, &segundos_ord);
			ponderada(a, b, &segundos_busca);
			soma(&segundos_busca, &segundos_ord);
			break;		    
	    case 11:
	        printf("\t Voce pediu para sair, prencione qualquer tecla para continuar\n");
	        sair=true;
	        break;
	
	    default:
	    	system("clear");
	        printf("\t Voce deve escolher uma opcao valida\n");
	        printf("\n");
	    }
	}
	
	return 0;
}
