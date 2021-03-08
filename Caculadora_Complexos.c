#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 2

struct vetor_salvo{
	float real;
	float imaginario;
	char num[64];
}vetorS[n];

struct vetor_na_hora{
	float real;
	float imaginario;
	char num[64];
}vetorV[n];

int mostrar_salvos=0;
int num_salvo=0;
char resultado[64]="";

int main ()
{
	printf("CALCULADORA DE NUMEROS COMPLEXOS\n");
	void armazenar();
	void mostrar();
	void calcular();
	int sair_menu=0, resp;
	
	do{
		printf("\n\t- MENU -\n\n");
		printf("1. Inserir numeros no vetor: \n");
		printf("2. Imprimir o numero complexo: \n");
		printf("3. Realizar operacoes basicas: \n");
		scanf("%d", &resp);
		
		if ( resp > 3 || resp <= 0 ){
			printf(" Operacao Invalida!!! \n");
		}
		
		else
		{
			
			if ( resp == 1){
				mostrar_salvos = 0;
				armazenar();	
			}
	
			else if ( resp == 2){
				mostrar_salvos = 1;
				mostrar();
			}
	
			else{
				mostrar_salvos = 0;
				calcular();
			}
			
		}
		
	}while (sair_menu == 0);
	
	return 0;
}

void armazenar()
{
	printf("Digite o primeiro numero complexo: \n");
	setbuf(stdin, NULL);
	scanf("%s", vetorS[0].num);
	printf("Digite o segundo numero complexo: \n");
	setbuf(stdin, NULL);
	scanf("%s", vetorS[1].num);
	
	num_salvo = 1;
	system("clear");
}

void mostrar()
{
	if (mostrar_salvos == 1){
		system("clear");
		printf("Valor 1: %s  Valor 2: %s \n", vetorS[0].num, vetorS[1].num);
		main();
	}
	
	else{
		system("clear");
		printf("\nResultado: %s\n", resultado);
		main();
	}
	
}

void calcular()
{
	int sair_escolha=0, resp, resp_usar_vetorV;
	float real;
	float imaginario; 
	char realC[64];
	char imaginarioC[64];
	
	if (num_salvo == 1){
		
		do
		{
			printf("Deseja utilizar os numeros ja salvos? (1 - sim || 2 - nao)\n");
			scanf("%d", &resp_usar_vetorV);
			
			if ( resp_usar_vetorV > 2 || resp_usar_vetorV <= 0){
				printf(" Erro!!!! Operacao invalida\n");
			}
			
			else if(resp_usar_vetorV == 1){
				resp = 1;
				sair_escolha = 1;
			}

			else if(resp_usar_vetorV == 2){
				resp = 2;
				sair_escolha = 1;
			}
			
		}while(sair_escolha == 0);
		
		sair_escolha = 0;
		
		if (resp == 1){
			
			do{
				system("clear");
				printf("Escolha a operacao\n");
				printf("1. Soma\n");
				printf("2. Subtracao\n");
				printf("3. Multiplicacao\n");
				printf("4. Divisao\n");
				scanf("%d", &resp);
				
				if (resp == 1){
					sair_escolha = 1;
				}
				
				else if (resp == 2){
					sair_escolha = 1;
				}
				
				else if (resp == 3){
					sair_escolha = 1;
				}
				
				else if (resp == 4){
					sair_escolha = 1;
				}
				
				else{
					printf("Operacao invalida!!!\n");
				}
				
			}while(sair_escolha == 0);
			
			if (resp == 1){
				strcpy(resultado, "");
				sscanf(vetorS[0].num, "%f %f", &vetorS[0].real, &vetorS[0].imaginario);
        		sscanf(vetorS[1].num, "%f %f", &vetorS[1].real, &vetorS[1].imaginario);
        		
        		real = vetorS[0].real + vetorS[1].real;
				imaginario = vetorS[0].imaginario + vetorS[1].imaginario;
				
				gcvt(real, 64, realC);
				gcvt(imaginario, 64, imaginarioC);
				
				if (real == 0 && imaginario == 0){
              		strcat(resultado, "0");
          		}
          		
          		else{
          			
          			if (imaginario > 0){
          				strcat(resultado, realC);
          				strcat(resultado, "+");
          				strcat(resultado, imaginarioC);
          				strcat(resultado, "i");
					}
					
					else{
						strcat(resultado, realC);
          				strcat(resultado, imaginarioC);
          				strcat(resultado, "i");
					}
				}
				
				mostrar();
			}
			
			else if (resp == 2){
				strcpy(resultado, "");
				sscanf(vetorS[0].num, "%f %f", &vetorS[0].real, &vetorS[0].imaginario);
        		sscanf(vetorS[1].num, "%f %f", &vetorS[1].real, &vetorS[1].imaginario);
        		
        		real = vetorS[0].real - vetorS[1].real;
				imaginario = vetorS[0].imaginario - vetorS[1].imaginario;
				
				gcvt(real, 64, realC);
				gcvt(imaginario, 64, imaginarioC);
				
				if (real == 0 && imaginario == 0){
              		strcat(resultado, "0");
          		}
          		
          		else{
          			
          			if (imaginario > 0){
          				strcat(resultado, realC);
          				strcat(resultado, "+");
          				strcat(resultado, imaginarioC);
          				strcat(resultado, "i");
					}
					
					else{
						strcat(resultado, realC);
          				strcat(resultado, imaginarioC);
          				strcat(resultado, "i");
					}
				}
				
				mostrar();
			}
			
			else if (resp == 3){
				strcpy(resultado, "");
				sscanf(vetorS[0].num, "%f %f", &vetorS[0].real, &vetorS[0].imaginario);
        		sscanf(vetorS[1].num, "%f %f", &vetorS[1].real, &vetorS[1].imaginario);
        		
        		real = (vetorS[0].real * vetorS[1].real) + ((vetorS[0].imaginario * vetorS[1].imaginario)*-1);
        	    imaginario = (vetorS[0].real * vetorS[1].imaginario) + (vetorS[0].imaginario * vetorS[1].real);
				
				gcvt(real, 64, realC);
				gcvt(imaginario, 64, imaginarioC);
				
				if (real == 0 && imaginario == 0){
              		strcat(resultado, "0");
          		}
          		
          		else{
          			
          			if (imaginario > 0){
          				strcat(resultado, realC);
          				strcat(resultado, "+");
          				strcat(resultado, imaginarioC);
          				strcat(resultado, "i");
					}
					
					else{
						strcat(resultado, realC);
          				strcat(resultado, imaginarioC);
          				strcat(resultado, "i");
					}
				}
				
				mostrar();
			}
			
			else{
				strcpy(resultado, "");
				
				float denominadorInteiro = vetorS[1].real * vetorS[1].real; 
          		float denominadorImaginario = (vetorS[1].imaginario * (vetorS[1].imaginario * -1))*-1; 
            	float denominador = denominadorInteiro + denominadorImaginario; 
            	char denominadorC[64]; 
            	gcvt(denominador, 60, denominadorC);

            	real = (vetorS[0].real * vetorS[1].real) + ((vetorS[0].imaginario * (vetorS[1].imaginario*-1))*-1);
            	imaginario = (vetorS[0].real * (vetorS[1].imaginario * -1)) + (vetorS[0].imaginario * vetorS[1].real);

            	gcvt(real, 60, realC);
            	gcvt(imaginario, 60, imaginarioC);

            	if(denominador == 0){
            	    printf("\n\tDivisao por 0 !!!\n\n");
					main();
            	}
            	
            	if (real == 0 && imaginario == 0){
               		strcat(resultado, "0");
                	strcat(resultado, "/");
                	strcat(resultado, denominadorC);
            	}
            	
	            else{

	                if (real !=0 && imaginario == 0){
	                    strcat(resultado, realC);
	                    strcat(resultado, "/");
	                    strcat(resultado, denominadorC);
	                }
    
	              	else if (real ==0 && imaginario != 0){
	                   	strcat(resultado, imaginarioC);
	                    strcat(resultado, "i");
	                    strcat(resultado, "/");
	                    strcat(resultado, denominadorC);
	                }
               
                else{
                    strcat(resultado, realC);
                   
                    if(imaginario > 0){
                        strcat(resultado, "+");
                        strcat(resultado, imaginarioC);
                        strcat(resultado, "i");
                        strcat(resultado, "/");
                        strcat(resultado, denominadorC);
                    }
                    
                    else{
                        strcat(resultado, imaginarioC);
                        strcat(resultado, "i");
                        strcat(resultado, "/");
                        strcat(resultado, denominadorC);
                    }
                }
            }
            
                mostrar();

			}	
		}
	}
	
	if(num_salvo == 0 || resp == 2){
		system("clear");
		printf("Digite o primeiro numero complexo: \n");
		setbuf(stdin, NULL);
		scanf("%s", vetorV[0].num);
		printf("Digite o segundo numero complexo: \n");
		setbuf(stdin, NULL);
		scanf("%s", vetorV[1].num);
	
		do{
			system("clear");
			printf("Escolha a operacao\n");
			printf("1. Soma\n");
			printf("2. Subtracao\n");
			printf("3. Multiplicacao\n");
			printf("4. Divisao\n");
			scanf("%d", &resp);
				
			if (resp == 1){
				sair_escolha = 1;
			}
				
			else if (resp == 2){
				sair_escolha = 1;
			}
				
			else if (resp == 3){
				sair_escolha = 1;
			}
				
			else if (resp == 4){
				sair_escolha = 1;
			}
				
			else{
				printf("Operacao invalida!!!\n");
			}
				
		}while(sair_escolha == 0);
			
		if (resp == 1){
			strcpy(resultado, "");
			sscanf(vetorV[0].num, "%f %f", &vetorV[0].real, &vetorV[0].imaginario);
       		sscanf(vetorV[1].num, "%f %f", &vetorV[1].real, &vetorV[1].imaginario);
        	
        	real = vetorV[0].real + vetorV[1].real;
			imaginario = vetorV[0].imaginario + vetorV[1].imaginario;
				
			gcvt(real, 64, realC);
			gcvt(imaginario, 64, imaginarioC);
				
			if (real == 0 && imaginario == 0){
             	strcat(resultado, "0");
          	}
       	
          	else{
          			
          		if (imaginario > 0){
          			strcat(resultado, realC);
          			strcat(resultado, "+");
          			strcat(resultado, imaginarioC);
          			strcat(resultado, "i");
				}
					
				else{
					strcat(resultado, realC);
          			strcat(resultado, imaginarioC);
          			strcat(resultado, "i");
				}
			}
				
			mostrar();
		}
			
		else if (resp == 2){
			strcpy(resultado, "");
			sscanf(vetorV[0].num, "%f %f", &vetorV[0].real, &vetorV[0].imaginario);
        	sscanf(vetorV[1].num, "%f %f", &vetorV[1].real, &vetorV[1].imaginario);
        		
       		real = vetorV[0].real - vetorV[1].real;
			imaginario = vetorV[0].imaginario - vetorV[1].imaginario;
				
			gcvt(real, 64, realC);
			gcvt(imaginario, 64, imaginarioC);
				
			if (real == 0 && imaginario == 0){
           		strcat(resultado, "0");
          	}
          	
         	else{
          		
          		if (imaginario > 0){
          			strcat(resultado, realC);
          			strcat(resultado, "+");
          			strcat(resultado, imaginarioC);
          			strcat(resultado, "i");
				}
					
				else{
					strcat(resultado, realC);
         			strcat(resultado, imaginarioC);
          			strcat(resultado, "i");
				}
			}
				
			mostrar();
		}
			
		else if (resp == 3){
			strcpy(resultado, "");
			sscanf(vetorV[0].num, "%f %f", &vetorV[0].real, &vetorV[0].imaginario);
        	sscanf(vetorV[1].num, "%f %f", &vetorV[1].real, &vetorV[1].imaginario);
        		
        	real = (vetorV[0].real * vetorV[1].real) + ((vetorV[0].imaginario * vetorV[1].imaginario)*-1);
            imaginario = (vetorV[0].real * vetorV[1].imaginario) + (vetorV[0].imaginario * vetorV[1].real);
				
			gcvt(real, 64, realC);
			gcvt(imaginario, 64, imaginarioC);
				
			if (real == 0 && imaginario == 0){
          		strcat(resultado, "0");
       		}
          		
          	else{
          			
          		if (imaginario > 0){
          			strcat(resultado, realC);
         			strcat(resultado, "+");
          			strcat(resultado, imaginarioC);
          			strcat(resultado, "i");
				}
					
				else{
					strcat(resultado, realC);
         			strcat(resultado, imaginarioC);
          			strcat(resultado, "i");
				}
			}
				
			mostrar();
		}
			
		else{
			strcpy(resultado, "");

			sscanf(vetorV[0].num, "%f %f", &vetorV[0].real, &vetorV[0].imaginario);
        	sscanf(vetorV[1].num, "%f %f", &vetorV[1].real, &vetorV[1].imaginario);
				
			float denominadorInteiro = vetorV[1].real * vetorV[1].real; 
          	float denominadorImaginario = (vetorV[1].imaginario * (vetorV[1].imaginario * -1))*-1; 
            float denominador = denominadorInteiro + denominadorImaginario; 
            char denominadorC[64]; 
            gcvt(denominador, 60, denominadorC);

            real = (vetorV[0].real * vetorV[1].real) + ((vetorV[0].imaginario * (vetorV[1].imaginario*-1))*-1);
            imaginario = (vetorV[0].real * (vetorV[1].imaginario * -1)) + (vetorV[0].imaginario * vetorV[1].real);

           	gcvt(real, 60, realC);
            gcvt(imaginario, 60, imaginarioC);

            if(denominador == 0){
                printf("\n\tDivisao por 0\n\n");
				main();
            }
            	
        	if (real == 0 && imaginario == 0){
            	strcat(resultado, "0");
               	strcat(resultado, "/");
               	strcat(resultado, denominadorC);
           	}
            	
	        else{

	            if (real !=0 && imaginario == 0){
	                strcat(resultado, realC);
	                strcat(resultado, "/");
	                strcat(resultado, denominadorC);
	            }
    
	            else if (real ==0 && imaginario != 0){
	              	strcat(resultado, imaginarioC);
	                strcat(resultado, "i");
	                strcat(resultado, "/");
	                strcat(resultado, denominadorC);
	            }
               
            else{
                strcat(resultado, realC);
                   
                if(imaginario > 0){
                    strcat(resultado, "+");
                    strcat(resultado, imaginarioC);
                    strcat(resultado, "i");
                    strcat(resultado, "/");
                    strcat(resultado, denominadorC);
                }
                    
                else{
                    strcat(resultado, imaginarioC);
                    strcat(resultado, "i");
                    strcat(resultado, "/");
                    strcat(resultado, denominadorC);
                }
            }
        }
            
            mostrar();

		}
			
	}
	
}
