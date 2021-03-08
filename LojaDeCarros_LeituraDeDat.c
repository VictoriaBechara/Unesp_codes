#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//tamanho maximo da lista
#define TamMax 1000

//struct para salvar os dados dos veiculos
struct CadCarros
{
	int id;
	int lugares;	
	int link;
	char disponibilidade;
	char ar_con;
	char placa[64];
	char fabricante[64];	
	char modelo[64];
	char categoria[64];
	char datainicio[64];
	char datafinal[64];
	float km;
};

//transformando a struct em uma variavel
struct CadCarros lista[TamMax];

//funcoes usadas durante o programa
void arquivo();
void inserir();
void remover();
void listar_data();
void listar_hoje();
void verificar();
void reserva();
void liberar();
void atualizar();
void atualizararq();
void mostrar();

//variavel global para definir o indice  
int i=0;

//variavel global para o arquivo nao abrir amis de uma vez
int operador = 0;

int main()
{	
	system("clear");
	
    int opcao,operador;
    
    inicio:
    	
    if(operador == 0)
	{
    	operador = 1;
    	arquivo(); //abertura do arquivo	
	}
    
    //menu
    system("clear");
    printf(" //MENU DE CONTROLE DE LOCACAO DE CARROS//  \n\n");
    printf("1 - Inserir um novo carro  \n2 - Remover um carro  \n3 - Listar carros  \n4 - Listar carros disponiveis hoje  \n5 - Verificar validade de devolucao \n");
    printf("6 - Fazer reserva  \n7 - Liberar reserva  \n8 - Atualizar dados de um determinado veiculo  \n9 - SAIR (seus dados serao salvos)  \n");
    printf("\n");
    printf("Opcao: \t");
    
    opcao = getchar();
    printf("\n");
    
    switch (opcao) {
    case '1':
        inserir();
        break;
    case '2':
        remover();
        break;
    case '3':
        listar_data();
        break;
    case '4':
        listar_hoje();
        break;
	case '5':
        verificar();
        break;
	case '6':
        reserva();
        break;
	case '7':
        liberar();
        break;
	case '8':
        atualizar();
        break;	
	case '0':
    	mostrar();
    	break;			    
    case '9':
    	atualizararq();
        printf("\t Voce pediu para sair, prencione qualquer tecla para continuar\n");
        break;

        
    default:
        printf("\t Voce deve escolher uma opcao valida\n");
        printf("\t Precione qualquer tecla para voltar ao menu\n");
        printf("\n");
        system("pause");
        goto inicio;
    }
    return 0;
}


void arquivo()
{
	system("clear");
	char linha[200];
	
	FILE*arq;
	arq = fopen("listacarros.dat", "r");  
	
	if (arq == NULL)
	{
		printf("Erro na abertura do arquivo!!!\n");
	}
	
	else
	{
		printf("Arquivo aberto com sucesso\n");
	}
	
	//agora o arquivo ira receber os dados inseridos pelo usuario abaixo
	
	while (!feof(arq))
	{
		fgets(linha, 199, arq);
		sscanf(linha,"%d %s %s %s", &lista[i].id, lista[i].placa, lista[i].fabricante, lista[i].modelo);
		strcpy(linha, "");
		printf("id: %d\t placa: %s \n", lista[i].id, lista[i].placa);
		
		fgets(linha, 199, arq);
		sscanf(linha,"%c %s %d %c", &lista[i].disponibilidade, lista[i].categoria, &lista[i].lugares, &lista[i].ar_con);
		strcpy(linha, "");
		
		fgets(linha, 199, arq);
		sscanf(linha,"%f", &lista[i].km);
		strcpy(linha, "");
		
		fgets(linha, 199, arq);
		sscanf(linha,"%s %s", lista[i].datainicio, lista[i].datafinal);
		strcpy(linha, "");
		
		i++;
	}
	
	i--;
	fclose(arq); 

	return;
}

//Inserir um novo carro no cadastro 1
void inserir()
{	
	system("clear");
	printf("Digite o ID do carro: \n");
	scanf("%d", &lista[i].id);
	setbuf(stdin,NULL);
	printf("Digite a placa do carro: \n");
	scanf("%s", lista[i].placa);
	setbuf(stdin,NULL);
	printf("Digite o fabricante: \n");
	scanf("%s", lista[i].fabricante);
	setbuf(stdin,NULL);
	printf("Digite o modelo: \n");
	scanf("%s", lista[i].modelo);
	setbuf(stdin,NULL);
	printf("Digite a disponibilidade (<S>im / <N>ao): \n");
	scanf("%c", &lista[i].disponibilidade);
	setbuf(stdin,NULL);
	printf("Digite a categoria (Compacto, Medio, Grande, SUV, Minivan): \n");
	scanf("%s", lista[i].categoria);
	printf("Digite o numero de lugares: \n");
	scanf("%d", &lista[i].lugares);
	setbuf(stdin,NULL);
	printf("Deseja ar-condicionado (<S>im / <N>ao): \n");
	scanf("%c", &lista[i].ar_con);
	printf("Digite a quilometragem: \n");
	scanf("%f", &lista[i].km);
	
	//definindo a data inicial como 0/0/0
	strcpy(lista[i].datainicio,"0/0/0");
	strcpy(lista[i].datafinal,"0/0/0");
	
	i++;
	
	printf("\t\nArquivo salvo com sucesso!!\n");
	printf("\n");
	printf("\nDIGITE ENTER PARA VOLTAR AO MENU \n");
	setbuf(stdin,NULL);
	getchar();
	system("clear");
	main();
}

// Remover um carro do cadastro 2
void remover()
{
	system("clear");
	
	int aux_id;
	int aux;
	int aux1;
	int remover;
	int indice;
	int erro=0;
	
	//mostrar os carros do sistema
	printf("ID's dos carros cadastrados no sistema\n");
	for ( aux1 = 0; aux1 < i; aux1++ )
	{
		printf("ID: %d \t\n", lista[aux1].id);
	}
	
	printf("Digite o ID do carro que deseja fazer a remocao: \n");
	scanf("%d", &aux_id);
	
	for ( aux = 0; aux < i ; aux++ )
	{
		if (lista[aux].id == aux_id)
		{
			indice = aux;
			lista[indice].link = -10;
			printf("Carro: %d\n Removido com sucesso!\n", indice);
			break;
		}
		
		else
			erro++;
		
	}
	
	if ( erro == 1)
		printf("ID invalido... \n");
	
	printf("\nDIGITE ENTER PARA VOLTAR AO MENU \n");
	setbuf(stdin,NULL);
	getchar();
	system("clear");
	main();	
		
}

//Listar carros de uma determinada categoria que estejam dispon�veis em uma determinada data 3
void listar_data()
{
	system("clear");
	char aux_categoria[64];
	char aux_retirada[64];
	char aux_devolucao[64];
	char barra;
	int dia1, mes1, ano1;
	int diaS,mesS,anoS,dia2S,mes2S,ano2S;
	int aux;
	char resp;
	int erro=0;
	
	//recebendo dados do usuario para a verificacao
	setbuf(stdin,NULL);
	printf("Digite a categoria escolhida para a verificacao (Compacto, Medio, Grande, SUV, Minivan): \n");
	scanf("%s", aux_categoria);
	setbuf(stdin,NULL);
	printf("Digite a data (dd/mm/aaaa): \n");
	scanf("%s", aux_retirada);
	
	for(aux = 0; aux < i; aux++)
	{
		if (lista[aux].link != -10)
		{
		
			if(strcmp(lista[aux].categoria,aux_categoria) == 0)
			{
				//conversao da data de string para inteiro
				sscanf(aux_retirada,"%d %c %d %c %d", &dia1, &barra, &mes1, &barra, &ano1); 
				sscanf(lista[aux].datainicio,"%d %c %d %c %d", &diaS, &barra, &mesS, &barra, &anoS);
				sscanf(lista[aux].datafinal,"%d %c %d %c %d", &dia2S, &barra, &mes2S, &barra, &ano2S);	
				
				//comparacao de dados
				if( anoS <= ano1 <= ano2S && mesS <= mes1 <= mes2S && diaS <= dia1 <= dia2S )
				{
					printf("O carro da categoria: %s \tID: %d \nDurante os dias %d/%d/%d ate %d/%d/%d \nEsta INDISPONIVEL para locacao \n", lista[aux].categoria, lista[aux].id, diaS, mesS, anoS, dia2S, mes2S, ano2S);
					break;
				}
			
				//mostrar os carros disponiveis
				else 
				{
					printf("O carro da categoria: %s \tID: %d esta DISPONIVEL \n", lista[aux].categoria, lista[aux].id);
					break;
				}
			}
			
		}
		
		else
			erro++;
			
	}
	
	if (erro == 1)
	{
		printf("Nao existe esse carro em nosso sistema... \n");
	}
	
	printf("\nDIGITE ENTER PARA VOLTAR AO MENU \n");
	setbuf(stdin,NULL);
	getchar();
	system("clear");
	main();		
}

// Listar carros que estejam dispon�veis hoje 4
void listar_hoje()
{
	system("clear");
	
	char aux_data[64];
	char barra;
	int ano, mes, dia;
	int anoS, mesS, diaS;
	int ano2S, mes2S, dia2S;
	int aux;
	
	setbuf(stdin,NULL);
	printf("Digite a data de hoje para a verificacao (dd/mm/aaaa): \n");
	scanf("%s", aux_data);
	
	for (aux = 0; aux < i; aux++)
	{
		if (lista[aux].link != -10)
		{
		
			sscanf(aux_data, "%d %c %d %c %d", &ano, &barra, &mes, &barra, &dia);
			sscanf(lista[aux].datainicio,"%d %c %d %c %d", &diaS, &barra, &mesS, &barra, &anoS);
			sscanf(lista[aux].datafinal,"%d %c %d %c %d", &dia2S, &barra, &mes2S, &barra, &ano2S);	
		
			//verificacao de data
			if (anoS <= ano <= ano2S && mesS<= mes <= mes2S && diaS <= dia <= dia2S)
			{
				printf("Carro: %d \tCategoria: %s = INDISPONIVEL \n", lista[aux].id, lista[aux].categoria);
			}
		
			else
			{
				printf("Carro: %d \tCategoria: %s = DISPONIVEL \n", lista[aux].id, lista[aux].categoria);
			}
			
		}
		
	}
	
	printf("\nDIGITE ENTER PARA VOLTAR AO MENU \n");
	setbuf(stdin,NULL);
	getchar();
	system("clear");
	main();
	
}

//verificar quando um determinado carro deve ser devolvido 5
void verificar()
{
	system("clear");
	
	int aux_id;
	int aux1;
	int aux2,id_valido=0;
	
	//mostrar os carros do sistema
	printf("ID's dos carros cadastrados no sistema\n");
	for ( aux1 = 0; aux1 < i; aux1++ )
	{
		if (lista[aux1].link != -10)
		printf("\tID: %d \t\n", lista[aux1].id);
	}
	
	printf("Digite o ID para verificacao de validade do carro: \n");
	scanf("%d", &aux_id);
	
	for ( aux2 = 0; aux2 < i ; aux2++ )
	{
		if (lista[aux1].link != -10)
		{
		
			if (lista[aux2].id == aux_id)
			{
				printf("Carro %d \tLocacao vence em: %s \n", aux2+1, lista[aux2].datafinal);
				id_valido++;
			}
			
		}
		
	}
	
	if(id_valido == 0)
	{
		printf("Nao existe tal id no nosso sistema de cadastro\n");
	}
	
	printf("\nDIGITE ENTER PARA VOLTAR AO MENU \n");
	setbuf(stdin,NULL);
	getchar();
	system("clear");
	main();
}

//fazer a reserva de um carro de uma determinada categoria para um certo periodo 6
void reserva()
{
	system("clear");
	
	char aux_reserva[64];
	char aux_inicio[64];
	char aux_final[64];
	char barra;
	int dia1, mes1, ano1;
	int dia2, ano2, mes2;
	int anoS, mesS, diaS;
	int ano2S, mes2S, dia2S;
	int aux;
	int aux1;
	
	//mostrar os carros do sistema
	printf("Categoria  e ID dos carros cadastrados no sistema\n");
	for ( aux1 = 0; aux1 < i; aux1++ )
	{
		if (lista[aux1].link != -10)
		printf("\t%s \n\t%d\t\n", lista[aux1].categoria, lista[aux1].id);
	}
	
	setbuf(stdin,NULL);
	printf("Digite a categoria do carro que deseja realizar a reserva: \n");
	scanf("%s", aux_reserva);
	
	for ( aux = 0; aux < i; aux++ )
	{
		
		if (strcmp(lista[aux].categoria,aux_reserva) == 0)
		{
			if (lista[aux1].link != -10)
			{
			
				{
					printf("Digite o periodo\n");
					setbuf(stdin,NULL);
					printf("Inicio:   ");
					scanf("%s", aux_inicio);
					setbuf(stdin,NULL);
					printf("Final:   ");
					scanf("%s", aux_final);
			
					sscanf(aux_inicio, "%d %c %d %c %d", &dia1, &barra, &mes1, &barra, &ano1);
					sscanf(aux_final, "%d %c %d %c %d", &dia2, &barra, &mes2, &barra, &ano2);
					sscanf(lista[aux].datainicio,"%d %c %d %c %d", &diaS, &barra, &mesS, &barra, &anoS);
					sscanf(lista[aux].datafinal,"%d %c %d %c %d", &dia2S, &barra, &mes2S, &barra, &ano2S);	
			
					if( anoS <= ano1 <= ano2S && mesS<= mes1 <= mes2S && diaS <= dia1 <= dia2S || anoS <= ano2 <= ano2S && mesS<= mes2 <= mes2S && diaS <= dia2 <= dia2S )
					{
				
						printf("O carro da categoria: %s \tID: %d \tdurante os dias %d/%d/%d ate %d/%d/%d \n", lista[aux].categoria, i, diaS, mesS, anoS, dia2S, mes2S, ano2S);
						printf("Esta INDISPONIVEL para reserva!!\n");
					}
			
					else
					{
						printf("Reserva efetuada com sucesso! \n");
						lista[aux].disponibilidade = 'N';
						strcpy(lista[aux].datainicio,aux_inicio);
						strcpy(lista[aux].datafinal,aux_final);
					
					}
			
				}
				
			}
			
		}
		
	}
	
	printf("\nDIGITE ENTER PARA VOLTAR AO MENU \n");
	setbuf(stdin,NULL);
	getchar();
	system("clear");
	main();
	
}

//liberar reserva de um carro quando nao ocorrer a retirada no dia reservado 7
void liberar()
{
	system("clear");
	
	int aux_id;
	int aux;
	int aux1;
	int dia, mes, ano, diaS, mesS, anoS;
	char aux_data[64];
	char barra;
	
	printf("\n");
	setbuf(stdin,NULL);
	printf("Digite a data de hoje (dd/mm/aaaa): \n");
	scanf("%s", aux_data);
	
	printf("ID's dos carros cadastrados no sistema\n");
	for ( aux1 = 0; aux1 < i; aux1++ )
	{
		if (lista[aux1].link != -10)
		printf("\tID: %d \n", lista[aux1].id);
	}
	
	printf("\n");
	printf("Digite o ID para liberar a reserva: \n");
	scanf("%d", &aux_id);
	
	for ( aux = 0; aux < i; aux++)
	{
		if (lista[aux1].link != -10)
		{

			sscanf(aux_data, "%d %c %d %c %d", &dia, &barra, &mes, &barra, &ano);
			sscanf(lista[aux].datafinal,"%d %c %d %c %d", &diaS, &barra, &mesS, &barra, &anoS);
		
			if ( aux_id == lista[aux].id )
			{
			
				if (anoS <= ano && mesS <= mes && diaS <= dia && lista[aux].disponibilidade == 'N')
				{
					lista[aux].disponibilidade = 'S';
					strcpy (lista[aux].datainicio, "0/0/0");
					strcpy (lista[aux].datafinal, "0/0/0");
					printf("Reserva liberada com sucesso \n");
				}
			
				else
				{
					printf("O carro de ID: %d ja esta disponivel para reserva!! \n", lista[aux].id);
				}

			}
	
		}
		
	}
	
	printf("\nDIGITE ENTER PARA VOLTAR AO MENU \n");
	setbuf(stdin,NULL);
	getchar();
	system("clear");
	main();
	
}

//Atualizar os dados de um ve�culo no seu retorno 8
void atualizar()
{
	system("clear");
	
	int aux;
	int aux1;
	int aux_att;
	char aux_ar;
	char aux_disponibilidade;
	float aux_km;
	
	printf("ID's dos carros cadastrados no sistema\n");
	for ( aux1 = 0; aux1 < i; aux1++ )
	{	
		if (lista[aux1].link != -10)
			printf("\tID: %d \n", lista[aux1].id);
	}
	
	printf("\n");
	printf("Digite o ID do carro para a atualizacao de dados no sistema: \n");
	scanf("%d", &aux_att);
	
	for ( aux = 0; aux < i; aux++)
	{
		//if (lista[aux].link != -10)
		//{
		
			if ( lista[aux].id == aux_att)
			{
				if (lista[aux].link != -10)
				{
					setbuf(stdin,NULL);
					printf("O ar-condicionado funciona? (<S>im / <N>ao) \n");
					scanf("%c", &aux_ar);
					setbuf(stdin,NULL);
					printf("O veiculo esta disponivel atualmente? (<S>im / <N>ao) \n");
					scanf("%c", &aux_disponibilidade);
					printf("Digite a nova quilometragem: \n");
					scanf("%f", &aux_km);
					printf("AVISO: as datas de insercao e retirada foram modificadas para 0/0/0 \n");
			
					lista[aux].ar_con = aux_ar;
					lista[aux].disponibilidade = aux_disponibilidade;
					lista[aux].km = aux_km;
					strcpy (lista[aux].datainicio, "0/0/0");
					strcpy (lista[aux].datafinal, "0/0/0");
				}   
   
			}
		//}
	}
	
	printf("\nDIGITE ENTER PARA VOLTAR AO MENU \n");
	setbuf(stdin,NULL);
	getchar();
	system("clear");
	main();
	
}

//Fechar o programa atualizando o arquivo de cadastro 9
void atualizararq()
{
	FILE *fp;
	fp = fopen("listacarros.dat","w+");
	
	if(fp == NULL)
	{
		puts("Erro ao salvar... \n");
	}
	
	else
	{
		for(int x = 0; x < i; x++)
		{
			if(lista[x].link != -10)
			{
				fprintf(fp,"%d %s %s %s\n",lista[x].id, lista[x].placa, lista[x].fabricante, lista[x].modelo);
				fprintf(fp,"%c %s %d %c\n",lista[x].disponibilidade, lista[x].categoria, lista[x].lugares, lista[x].ar_con);
				fprintf(fp,"%f\n", lista[x].km);
				fprintf(fp,"%s %s\n", lista[x].datainicio, lista[x].datafinal);
			}
		}
	}
	
}

//teste som alooou 0
void mostrar()
{
	system("clear");
	int aux;
	
	for ( aux = 0; aux < i; aux++)
	{
		if (lista[aux].link != -10)
		{
			printf("Carro      %d \n", aux+1);
			printf("ID:        %d\n", lista[aux].id);
			printf("Categoria: %s\n", lista[aux].categoria);
			printf("Km:        %2.f\n", lista[aux].km);
			printf("Ar-cond:   %c\n", lista[aux].ar_con);
			printf("Data de insercao: %s \nData de retirada: %s \n", lista[aux].datainicio, lista[aux].datafinal);
			printf("Disponibilidade: %c\n", lista[aux].disponibilidade);
			printf("\n");
		}
		
	}
	
	printf("\nDIGITE ENTER PARA VOLTAR AO MENU \n");
	setbuf(stdin,NULL);
	getchar();
	system("clear");
	main();
}
