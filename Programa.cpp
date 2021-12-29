// MAIN
#include <stdio.h>
#include <conio.h>
#include "meuconio.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>
#include "TAD.h"
#define TF 4

void menuB(){
	system("cls");
	char menuzin[][150] = 	{
"._______________________.    ._______________________     ._______________________.    ._______________________.", 
"|        CABINE 1       |    |        CABINE 2       |    |        CABINE 3       |    |       SEM PARAR       |",
"| STATUS:               |    | STATUS:               |    | STATUS:               |    | STATUS:  Ativo        |",
"|_______________________|    |_______________________|    |_______________________|    |_______________________|",
"|                       |    |                       |    |                       |    |                       |",
"|                       |    |                       |    |                       |    |                       |",
"|                       |    |                       |    |                       |    |                       |",
"|                       |    |                       |    |                       |    |                       |",
"|                       |    |                       |    |                       |    |                       |",
"|                       |    |                       |    |                       |    |                       |",
"|                       |    |                       |    |                       |    |                       |",
"|                       |    |                       |    |                       |    |                       |",
"|                       |    |                       |    |                       |    |                       |",
"|                       |    |                       |    |                       |    |                       |",
"|                       |    |                       |    |                       |    |                       |",
"|                       |    |                       |    |                       |    |                       |",
"|                       |    |                       |    |                       |    |                       |",
"|                       |    |                       |    |                       |    |                       |",
"|                       |    |                       |    |                       |    |                       |",
"|                       |    |                       |    |                       |    |                       |",
"|                       |    |                       |    |                       |    |                       |",
"|_______________________|    |_______________________|    |_______________________|    |_______________________|",					
							};
	for(int i = 0; i < sizeof(menuzin)/150; i++){
		printf("   %s\n", menuzin[i]);
	}
}

char menu()
{
    int i;
    system("cls");
    gotoxy(10,1); printf("%c",201);
    gotoxy(110,1); printf("%c",187);
    gotoxy(10,22); printf("%c",200);
    gotoxy(110,22); printf("%c",188);
    gotoxy(52,4); printf("%c",201);
    gotoxy(64,4); printf("%c",187);
    gotoxy(52,6); printf("%c",200);
    gotoxy(64,6); printf("%c",188);
    for(i=2; i<22; i++)
    {
        gotoxy(10,i); printf("%c",186);
        gotoxy(110,i); printf("%c",186);
    }
    for(i=11; i<110; i++)
    {
        gotoxy(i,1); printf("%c",205);
        gotoxy(i,22); printf("%c",205);
    }
    gotoxy(52,5); printf("%c",186);
    gotoxy(64,5); printf("%c",186);
    for(i=53; i<64; i++)
    {
        gotoxy(i,4); printf("%c",205);
        gotoxy(i,6); printf("%c",205);
    }
    
    gotoxy(14,3); printf("[ESC] SAIR");
    gotoxy(54,5); printf("*PEDAGIO*");
    gotoxy(20,10); printf("[A] Desativar cabine");
    gotoxy(48,10); printf("[B] Ativar cabine");
    gotoxy(20,13); printf("[BARRA DE ESPACO] Iniciar pedagio");
    
    for(i=16; i<21; i++)
    {
        gotoxy(79,i); printf("%c",186);
        gotoxy(107,i); printf("%c",186);
    }
    for(i=80; i<107; i++)
    {
        gotoxy(i,16); printf("%c",205);
        gotoxy(i,21); printf("%c",205);
    }
    gotoxy(79,16); printf("%c",201);
    gotoxy(107,16); printf("%c",187);
    gotoxy(79,21); printf("%c",200);
    gotoxy(107,21); printf("%c",188);
    
    gotoxy(81,17); printf("Obs: ");
    gotoxy(82,18); printf("Para ativar/desativar");
    gotoxy(82,19); printf("uma cabine pressione 'P'");
    gotoxy(82,20); printf("durante a simulacao!");
    
    gotoxy(20,18); printf("Opcao:");
    
    return toupper(getche());
}

void limpaTela()
{
	int x,y;
	textbackground(11);
	for(x=5;x<22;x++)
	{
		gotoxy(5,x); printf("                       ");
		gotoxy(34,x); printf("                       ");
		gotoxy(63,x); printf("                       ");
		gotoxy(92,x); printf("                       ");
	}	
	textcolor(0);
}	

void printaCabine(F fila, int i)
{
	elemento aux;
	int c,l=6;
	while(!vazia(fila))
	{
		if(i==0)
		{
			c=6;
			aux = retirar(fila);
			gotoxy(c,l); printf("Placa: %s",aux.placa);
		}
		if(i==1)
		{
			c=35;
			aux = retirar(fila);
			gotoxy(c,l); printf("Placa: %s",aux.placa);
		}
		if(i==2)
		{
			c=64;
			aux = retirar(fila);
			gotoxy(c,l); printf("Placa: %s",aux.placa);
		}
		if(i==3)
		{
			c=93;
			aux = retirar(fila);
			gotoxy(c,l); printf("Placa: %s",aux.placa);
		}
		l+=2;
	}
}

void retangulinho(int ut,int &x)
{
	int i;
	
	gotoxy(4,24); printf("%c",201);
    gotoxy(115,24); printf("%c",187);
    gotoxy(4,30); printf("%c",200);
    gotoxy(115,30); printf("%c",188);
    for(i=25; i<30; i++)
    {
        gotoxy(4,i); printf("%c",186);
        gotoxy(115,i); printf("%c",186);
    }
    for(i=5; i<115; i++)
    {
        gotoxy(i,24); printf("%c",205);
        gotoxy(i,30); printf("%c",205);
    }
    if(ut != 0 && ut % 60 ==0)
    	x++;
    if(x>0)
    {
    	gotoxy(6,25); printf("Hora(s): %d:%d   ",x,ut-x*60);
	}
	else
	{
		gotoxy(6,25); printf("Hora(s): %d:%d   ",x,ut);
	}
}

void infoRet(int qtdSaida, int esperaSaida,int automoveis[],int tot_tempo)
{
	if(qtdSaida > 0)
	{
		gotoxy(6,27); printf("Tp medio saida: %.2fmin      ",(float)esperaSaida/qtdSaida);		
	}
	else
	{
		gotoxy(6,27); printf("Tp medio saida: calculando...");
	}
    gotoxy(6,29); printf("Tp medio p/ atendimento: %.2fmin  ",(float)tot_tempo/automoveis[3]);
    gotoxy(45,25); printf("Carros: %d",automoveis[0]);
    gotoxy(45,27); printf("Motos: %d",automoveis[1]);
    gotoxy(45,29); printf("Caminhoes: %d",automoveis[2]);
}

void totalCat(elemento aux,int automoveis[])
{
    if(stricmp(aux.categoria,"Passeio")==0)
        automoveis[0]++;
    if(stricmp(aux.categoria,"Moto")==0)
        automoveis[1]++;
    if(stricmp(aux.categoria,"Caminhao")==0)
        automoveis[2]++;
    automoveis[3] = automoveis[0] + automoveis[1] + automoveis[2];
}

void ativaCabine(F fila[])
{
	int cabine;
	do
	{
		system("cls");
		printf("\n\t\t\t\t\t\t**ATIVA CABINE**\n");
    	printf("\nQual cabine voce deseja ativar: ( 1 - 2 - 3 - 0 sair)\n\n\tCabine 1 (Padrao) - Cabine 2 (Padrao) - Cabine 3 (Padrao)?\n\tOpcao: ");
    	scanf("%d",&cabine);
    	if(cabine>3)
    	{
    		printf("\n Cabine invalida, digite novamente.\n");
    		getch();
		}		
	}while(cabine>3 && cabine != 0);
	if(cabine != 0)
	{
		if(fila[cabine-1].status == 0)
		{
			ativar(fila[cabine-1]);
			printf("\n Cabine %d foi ativada com sucesso!\n",cabine);
		}
		else
			printf("\n Cabine %d ja esta ativa!",cabine);
		getch();
	}
}

void desativaCabine(F fila[])
{
	int cabine;
	do
	{
		system("cls");
		printf("\n\t\t\t\t\t\t**DESATIVA CABINE**\n");
    	printf("\nQual cabine voce deseja desativar: ( 1 - 2 - 3 - 0 sair)\n\n\tCabine 1 (Padrao) - Cabine 2 (Padrao) - Cabine 3 (Padrao)?\n\tOpcao: ");
    	scanf("%d",&cabine);
    	if(cabine>3)
    	{
    		printf("\n Cabine invalida, digite novamente.\n");
    		getch();
		}		
	}while(cabine>3 && cabine != 0);
	if(cabine != 0)
	{
		if(fila[cabine-1].status == 1)
		{
			desativar(fila[cabine-1]);
			printf("\n Cabine %d foi desativada com sucesso!\n",cabine);
		}
		else
			printf("\n Cabine %d ja esta desativada!",cabine);
		getch();
	}
}

void statusCabine(F fila[])
{
	textcolor(7);
	if(fila[0].status==1)
	{
		textbackground(2);
		gotoxy(14,3); printf("Ativado");
	}
	else
	{
		textbackground(4);
		gotoxy(14,3); printf("Desativado");
	}
		
	if(fila[1].status==1)
	{
		textbackground(2);
		gotoxy(43,3); printf("Ativado");
	}
	else
	{
		textbackground(4);
		gotoxy(43,3); printf("Desativado");
	}
	if(fila[2].status==1)
	{
		textbackground(2);
		gotoxy(72,3); printf("Ativado");
	}
	else
	{
		textbackground(4);
		gotoxy(72,3); printf("Desativado");
	}
	textcolor(7);
	textbackground(2);
	gotoxy(101,3); printf("Ativado");
	gotoxy(4,25);
}

void porHora(int semparar[],int &totalVeiculos, int automoveis[],int qtdHora[])
{
	totalVeiculos = automoveis[3] - totalVeiculos;
	qtdHora[0] = semparar[0] - qtdHora[0];
	qtdHora[1] = semparar[1] - qtdHora[1];
	qtdHora[2] = semparar[2] - qtdHora[2];
	qtdHora[3] = qtdHora[0] + qtdHora[1] + qtdHora[2];	
	
	gotoxy(65,25); printf("Sem parar p/h:");
	gotoxy(67,27); printf("Carros: %d   ",qtdHora[0]);
    gotoxy(67,28); printf("Motos: %d   ",qtdHora[1]);
    gotoxy(67,29); printf("Caminhoes: %d   ",qtdHora[2]);
    gotoxy(88,29); printf("Num veiculos p/h: %d  ",totalVeiculos);
    
}

int infoFilas(F fila[])
{
	int i,x=0;
	for(i=0;i<TF;i++)
		if(vazia(fila[i]))
			x++;
	if(x < 4)
		return 0;
	return 1;		
}

executar(char NomeArq[], F fila[])
{
	FILE *arq = fopen(NomeArq,"r");
	if(arq == NULL)
		printf("ERRO DE ABERTURA (ARQUIVO)\n");
	else
	{
		int i, x=0, ut=0, automoveis[4], semparar[4], esperaSaida=0, qtdSaida=0, totalVeiculos=0, qtdHora[4], qtd, tot_tempo=0, tamanho = 70;
		char tecla;
		menuB();
		statusCabine(fila);
		textbackground(11);
		textcolor(0);
		//PRINTA AS OBS
		elemento aux, atendimento[TF-1];
		for(i=0;i<TF-1;i++)
		{
			atendimento[i].tempo =0;
			automoveis[i]=0; //carros		motos			caminhoes		total veiculos
			semparar[i]=0; //carros		motos			caminhoes		total veiculos
			qtdHora[i] = 0;
		}
		srand(time(NULL));
		while(!feof(arq) || infoFilas(fila) == 0)
		{
			retangulinho(ut,x);
			if(ut % 2 == 0 && !feof(arq))
			{
				int random = 0;
				fscanf(arq,"%s %s %s %d %s %d %d\n",&aux.placa,&aux.cor,&aux.fabricante,&aux.eixo,&aux.categoria,&aux.prioridade,&aux.tempo);
				random = rand() % (TF-1);
				aux.tempo_inicio=ut;
				tot_tempo+=aux.tempo;
				totalCat(aux,automoveis);
				if(fila[random].status == 1 && aux.prioridade > 0)
				{
					if(!cheia(fila[random]))
					{
						inserir(fila[random],aux);
					}
				}
				else
				{
					
					if(aux.prioridade > 0)//TRATAR DE CAIR NAS DUAS CABINES SE ESTIVER ATIVAS, CONTANDO QUE UMA ESTEJA DESATIVADA
					{
						int x = random;
						while(random == x)
							random = rand()%(TF-1);
						int y = random;
						if(x != random && fila[random].status == 1)
						{
							if(!cheia(fila[random]))
							{
								inserir(fila[random],aux);										
							}
						}
						else //TRATAR DE CAIR SOMENTA NA ULTIMA CABINE SE ESTIVER ATIVA, CONTANDO QUE DUAS ESTEJAM DESATIVADAS
						{
							while(random == x || random == y)
								random = rand()%(TF-1);
							if(fila[random].status == 1)
							{
								if(!cheia(fila[random]))
								{
									inserir(fila[random],aux);
								}
							}
							else //SE TODAS AS CABINES ESTIVER DESATIVADAS
							{
								system("cls");
								printf("\n\tTODAS AS CABINES ESTAO DESATIVADAS!");
								ativaCabine(fila);
								system("cls");
								menuB();
								statusCabine(fila);
							}	
						}													
					}
					else// INSERIR NO SEM PARAR
					{
						if(!cheia(fila[TF-1]))
						{
							inserir(fila[TF-1],aux);
							totalCat(aux,semparar);	
						}
					}
						
				}	
			}
			limpaTela();
				
			for(i=0;i<TF;i++)//PRINTA TODOS OS CAMPOS EMBAIXO DAS CABINES E OS VEICULOS QUE CHEGAM
			{
				printaCabine(fila[i],i);
			}
			for(i=0;i<TF-1;i++)//RODA O TEMPO
			{
				if(atendimento[i].tempo > 0)
				{
					atendimento[i].tempo--;
					if(atendimento[i].tempo == 0)
					{
						qtdSaida++;
						esperaSaida+= (ut - atendimento[i].tempo_inicio);
						tamanho --;
					}
						
				}
			}
			for(i=0;i<TF-1;i++)// AQUI ELE RECEBER O PRIMERIO CARRO DA FILA
			{
				if(atendimento[i].tempo == 0 && !vazia(fila[i]))
				{
					atendimento[i] = retirar(fila[i]);
				}
			}
			if(!vazia(fila[TF-1]))//TRATA O SEM PARAR
			{
				elemento passou = retirar(fila[TF-1]);
			}
			infoRet(qtdSaida, esperaSaida, automoveis, tot_tempo);
			if(ut != 0 && ut % 60 == 0)
			{
				porHora(semparar,totalVeiculos,automoveis,qtdHora);	
			}
			ut++;
			for(int i =0;i<12000;i++)
	        {
	            if(kbhit() && toupper(getch()) == 'P')
	            {
	            	int op;
	            	system("cls");
					do{
						
						printf("\nAtivar(1) ou Desativar(2) cabine?\n");
						scanf("%d",&op);
						if(op == 1)
							ativaCabine(fila);
						else if(op == 2)
							desativaCabine(fila);
						else
						{
							printf("\nVoce digitou um numero diferente de 1 e 2!\n");
							getch();
						}
						printf("\nDigite ""ESPACO"" para continuar o programa!");
						tecla = toupper(getch());
					}while(tecla != ' ');
					menuB();
					statusCabine(fila);	
					textbackground(11);
					textcolor(0);
				}
			}
			infoFilas(fila);
		}
		getch();
		system("cls");
		gotoxy(60,15); printf("FIM!");
	}	
	fclose(arq);
	getch();
}

int main()
{
	textbackground(11);
    textcolor(0);
	int i;
	char op;
	F fila[4];
	for(i=0;i<4;i++)
		inicializar(fila[i]);
	
	do{
		op=menu();
		switch(op)
		{
			case ' ':
				system("cls");
        		executar("pedagio.txt",fila);
           		getch();
				break;
				
			case 'A':
				desativaCabine(fila);
				break;
				
			case 'B':
				ativaCabine(fila);
				break;
		}
	}while(op != 27);
	
	return 1;
}
