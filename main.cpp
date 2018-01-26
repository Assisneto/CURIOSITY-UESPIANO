/*
 *	author: Filipe A.S
 *	author: Ericles Oliveira
 *	author: Assis Neto
 *	Arquivo .cpp executa projeto
 *
 */

#include <iostream>
#include "Grafo.hpp"
#include <stdio.h>
using namespace std;
int main(){	
	
	Grafo * grafo;
	int aux = 0;
	
	int controle1;
	do {
		cout<<"\n--MENU--"<<endl;
		cout<<"\n1 - CRIAR GRAFO.";
		cout<<"\n2 - SETAR ORIGEM DE SAIDA.";
		cout<<"\n3 - VER MENOR DISTANCIA.";
		cout<<"\n4 - ABASTERCER CurUESPI.";
		cout<<"\n5 - PERCORRER CAMINHO.";
		cout<<"\n0 - SAIR.\n= ";
		cin>>controle1;
	
		switch(controle1)
		{
		case 1:
			grafo = new Grafo(); // instancia da classe Grafo
			aux = 1;
			break;			
		case 2:
			if(aux == 1){
			grafo->setOrigem();
			break;
		}else{
			cout<<"Impossivel realiza essa operação pois ainda não existe um grafo";
			break;
		}
		case 3:
			if(aux == 1){
			grafo->getMenorDistancia();
			break;
		}else{
			cout<<"Impossivel realiza essa operação pois ainda não existe um grafo";
			break;
		}
		case 4:
			if (aux == 1){
			grafo->setCombustivel();
			break;
		}else{
			cout<<"Impossivel realiza essa operação pois ainda não existe um grafo";
			break;
		}
		case 5:
			if(aux == 1){
			grafo->percorrerCaminho();
			break;
		}else{
			cout<<"Impossivel realiza essa operação pois ainda não existe um grafo";
			break;
		}			
		default:
			break;
		}
	} while(controle1 != 0);
	
	//imprime a menor distancia
	//printf("Menor distancia eh: %d", grafo->getMenorDistancia());
	
	
	
	
	return 0;
}
