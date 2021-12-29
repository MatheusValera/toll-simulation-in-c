#define MAXFILA	50
// CATEGORIA {	MOTO | CAMINHAO | PASSEIO }
// STATUS { 1 - ATIVA | 0 - DESATIVADA }
struct elemento{
	int eixo,prioridade,tempo,tempo_inicio;
	char placa[12],cor[12],fabricante[20],categoria[10];
};

struct F{
	int inicio,fim,cont,status;
	elemento veiculo[MAXFILA];
};

void inicializar(F &fila);
char vazia(F fila);
char cheia(F fila);
void inserir(F &fila, elemento aux);
elemento retirar(F &fila);
void exibir(F fila);
elemento fila_inicio(F fila);
elemento fila_fim(F fila);

void inicializar(F &fila)
{
	fila.cont = fila.inicio = 0;
	fila.fim = -1;
	fila.status=1;
}

void desativar(F &fila)
{
	fila.status=0;
}

void ativar(F &fila)
{
	fila.status=1;
}

char vazia(F fila)
{
	return fila.cont==0;
}

char cheia(F fila)
{
	return fila.cont==MAXFILA;
}

int calcPos(int pos){
	if(pos<0)
		return MAXFILA-1;
	return pos;
}

void inserir(F &fila,elemento aux)
{
	fila.fim++;
	if(fila.fim==MAXFILA)
		fila.fim=0;
	fila.veiculo[fila.fim] = aux;
	fila.cont++;
	elemento aux2;
	int pos = fila.fim;
	while(pos != fila.inicio && fila.veiculo[pos].prioridade < fila.veiculo[calcPos(pos-1)].prioridade)
	{
		aux2 = fila.veiculo[pos];
		fila.veiculo[pos] = fila.veiculo[pos-1];	
		fila.veiculo[pos-1] = aux2;
		
		pos = calcPos(pos-1);
	}
}

elemento retirar(F &fila)
{
	fila.cont--;
	elemento aux = fila.veiculo[fila.inicio++];
	if(fila.inicio==MAXFILA)
		fila.inicio=0;
	return aux;
}

void exibir(F fila)
{
	elemento aux;
	while(!vazia(fila))
		{
			aux=retirar(fila);
			printf("Placa: %s\tCor: %s\tFabricante: %s\tNumero de Eixos: %d\tCategoria: %s\tPrioridade: %d\tTempo de Atendimento: %d\n\n\n",aux.placa,aux.cor,aux.fabricante,aux.eixo,aux.categoria,aux.prioridade,aux.tempo);
		}
}

elemento fila_inicio(F fila)
{
	elemento aux = fila.veiculo[fila.inicio];
	return aux;
}

elemento fila_fim(F fila)
{
	elemento aux = fila.veiculo[fila.fim];
	return aux;
}

