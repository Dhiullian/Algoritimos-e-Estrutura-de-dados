// ler uma quantidade qualquer de números e armazenalos na memoria dinamicamente, parar a leitura quanto receber valor negativo
#include <iostream>
#include <locale.h>
#include <stdlib.h>
using namespace std;
int main ()
{
	setlocale(LC_ALL,"Portuguese");
	int *vet,cont=0,aux,i=0,**p;
	vet=(int*)malloc(sizeof(int));
	p=&vet;
	while(1)
	{
		system("cls");
		if (cont > 0)
		{
			vet=(int*)realloc(vet,sizeof(int)*cont+1);
			if (vet==NULL)
			{
				cout<<"Memoria insuficiente";
				exit(1);
			}
		}
		cout<<"Informe um valor positivo para inserir no vetor,caso o valor seja negativo encerrara á parte de preenchimento do vetor:"<<endl<<"->";
		cin>>aux;
		vet[cont]=aux;
		cont++;
		if(aux<0)
			break;
	}
	system("cls");
	cout<<"O vetor preenchido é composto pelos números:"<<endl;
	while (i < cont-1)
	{
		cout<<(*p)[i]<<"\t";
		i++;
	}
	free(vet);	
}
