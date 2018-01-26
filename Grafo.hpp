/*
 *	author: Filipe A.S
 *	author: Ericles Oliveira
 *	author: Assis Neto
 *	Arquivo .hpp que possui a estrutura GRAFO e o algoritmo de dijkstra
 *
 */

#ifndef Grafo_hpp__
#define Grafo_hpp__

#define infinito 1000 // definição infinito para controlar o fluxo de analise do algoritmo dijsktras
#define autonomia 10 // autonomia do CurUESPI
#define tanque 50 // limite de gasolina que cabe no CurUESPI
#include <iostream>
using namespace std;
class Grafo {
private:
	int numVertice;
	int origem;
	int custo[10][10];
	int distancia[10];
	int menorDistancia;
	float combustivel;
	
/*
 *	Algoritmo Dijkstra
 *	entradas:
 *	n = numero de vertices
 *	v = origem
 *	cost = matriz com as vertices e seus pesos
 *	dist = vetor armazena distancia
 */
void dijkstra(int n,int v,int cost[10][10],int dist[])
{
 int u,count,flag[10],min;
 for(int i=1;i<=n;i++)
  flag[i]=0,dist[i]=cost[v][i];
 count=2;
 while(count<=n)
 {
  min=99;
  for(int w=1;w<=n;w++)
   if(dist[w]<min && !flag[w])
    min=dist[w],u=w;
  flag[u]=1;
  count++;
  for(int w=1;w<=n;w++)
   if((dist[u]+cost[u][w]<dist[w]) && !flag[w])
    dist[w]=dist[u]+cost[u][w];
 }
}

public:
	//construtor
	Grafo(){
		this->numVertice = 0;
		this->origem = 0;
		this->menorDistancia = 0;
		this->combustivel = 0;
		CriaGrafo();	
	}
	
	/*
	 *	metodo seta a origem a qual ira sair
	 */
	void setOrigem() {
		cout<<"\nEntre com a origem da matriz: ";
		cin>>this->origem;
		MenorDistancia();
	}
	
	/*
	 *	metodo que abastece. Verifica se esta cheio; se nao está, abastece.
	 */
	void setCombustivel(){
		if(this->combustivel == tanque){
			cout<<"\n--TANQUE CHEIO--";
			return;
		}
		
		float gas;
		cout<<"\nTANQUE ATUAL: "<<this->combustivel;				
		cout<<"\nEntre com o combustivel: ";
		cin>>gas;
		
		if(gas + combustivel > tanque){
			cout<<"\nTANQUE NAO SUPORTA VALOR SUPERIOR A "<<tanque;
			cout<<"\nFOI DESPERDIÇADO "<<(gas + combustivel) - tanque<<" DE COMBUSTIVEL. COLOQUE O QUANTIDADE CERTA NA PROXIMA VEZ.";
			this->combustivel = tanque;
			cout<<"\nTANQUE ATUAL: "<< combustivel;
			return;
		} else {
			this->combustivel = gas;
			cout<<"\nTANQUE ATUAL: "<< this->combustivel;
		}
		
		
	}
	
	/*
	 *  metodo verifica se eh possivel percorrer o caminho. Se for, percorre o caminho
	 *	e subtrai do tanque o que gastou.
	 */ 
	void percorrerCaminho(){
		float gasto;
		gasto = menorDistancia * autonomia;	
		
		// calcula menor distancia
		MenorDistancia();
		
		if(combustivel < gasto){
			cout<<"\nCOMBUSTIVEL INSUFICIENTE PARA PERCORRER A DISTANCIA.";
			cout<<"\nTanque: "<<combustivel<<" - Distancia a percorrer: "<<menorDistancia;
			cout<<"\nABASTECA PRIMEIRO.";
			return;
		} else {
			cout<<"\nEH POSSIVEL PERCORRER O CAMINHO.";
			this->combustivel = this->combustivel - gasto;
			cout<<"\nTanque: "<<combustivel<<" - Distancia percorrida: "<<menorDistancia;
			return;
		}
	}
	
	/*
	 *	metodo armazena a menor distancia possivel
	 */
	void MenorDistancia(){
		dijkstra(this->numVertice, this->origem, custo, distancia);
		//printf("\n menor caminho:\n");
		for(int i = 1; i <= this->numVertice; i++)
			if(i!=this->origem){
				//printf("%d->%d,custo=%d\n",this->origem ,i ,distancia[i]);
				menorDistancia = distancia[i];
			}
	}
	
	/*
	 *	retorna a menor distancia
	 */
	void getMenorDistancia(){
		cout<<"\nMENOR DISTANCIA EH: "<<this->menorDistancia;
	}
		
/*
 *	FUNÇÃO QUE CRIA O GRAFO
 */
void CriaGrafo() {	
	
	//setando tanque
	//setCombustivel();
	
	cout<<"\nCRIANDO GRAFO(CAMINHO A PERCORRER):"<<endl;	
	cout<<"\nEntre com o numero de vertices/nos:"; // num de vertices/nós
	cin>>this->numVertice; // armazena vertices/nós
	cout<<"\nEntre com as arestas e seus pesos: "<<endl; // custo da matriz
	for(int i=1;i<=this->numVertice;i++)
  	  for(int j=1;j<=this->numVertice;j++)
  	  {
		cout<<""<<i<<" para "<<j<<" = ";
   	    cin>>custo[i][j];
   	    if(custo[i][j]==0)
    		custo[i][j]=infinito;
  	  }
	//setOrigem();
	//MenorDistancia();
}

	
};

#endif
