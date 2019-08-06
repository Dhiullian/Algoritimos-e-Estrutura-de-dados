#include <iostream>
#include <locale.h>//Bibliteca de linguagem, adiciona acentua��o e varia��es linguisticas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>//Biblioteca para mapear posicionamento(organiza��o e disposi��o dentro do codigo)
#include <ctype.h>//Biblioteca para converter carecteres minusculos e maiusculos(padroniza��o de exibi��o dentro do codigo)
using namespace std;

//Struct dos dados
struct Pessoa{ 
	char nome[30],sexo;
	int idade;
};typedef struct elemento *Lista;

//Estruct de encadeamento da lista
struct elemento{
	elemento *ant;//ponteiro para o elemento anterior
	Pessoa dado;//armazenamento de informa��es
	elemento *prox;//ponteiro para o proximo elemento
};typedef struct elemento Elem;

//Inicializa a lista vazia
Lista* Criar_lst()
{
	Lista *lst = (Lista*) malloc ( sizeof ( Lista ));
	if (lst != NULL)
		*lst=NULL;
	return lst;
}

//Esvaziar a lista
void Limpa_lst(Lista *lst)
{
	if(lst != NULL)
	{
		Elem *no;
		while((*lst) != NULL)
		{
			no = *lst;
			*lst = (*lst)->prox;
			free(no);
		}
		free(lst);
	}
}

//Inserir um elemento no inicio da lista
int Inserir_inicio(Lista *lst,struct Pessoa dados)
{
	Elem *no = (Elem*)malloc (sizeof (Elem));
	
	if (no == NULL) return 0;
	
	no->dado = dados;
	no->prox = (*lst);
	no->ant = NULL;
	
	if (*lst != NULL)
		(*lst)->ant = no;
	*lst=no;
	
	return 1;
}

//Inserir um elemento no fim da lista
int Inserir_fim (Lista *lst,struct Pessoa dados)
{
	Elem *no = (Elem*)malloc (sizeof (Elem));
	
	if (no == NULL) return 0;
	
	no->dado = dados;
	no->prox = NULL;
	
	if((*lst) == NULL)
	{
		no->ant = NULL;
		*lst = no;
	}
	else
	{
		Elem *aux = *lst;
		while(aux->prox != NULL)
			aux = aux->prox;
		aux->prox = no;
		no->ant = aux;
	}
	return 1;
}

//Ordenar a lista Por ordem alfabetica
void Ordenar(Lista *lst)
{
	Elem *aux, *no= *lst;
	Pessoa dados;
	
	//estrutura de repeti��o Aninhada para comparar os elementos
	for(no; no != NULL;no = no->prox)
	{
		for(aux = no->prox; aux != NULL; aux = aux->prox)
		{
			if(strcmp(no->dado.nome,aux->dado.nome) > 0)
			{
				dados = no->dado;
				no->dado = aux->dado;
				aux->dado = dados;
			}
		}
	}
}

//Imprimir a Lista
void Imprimir(Lista *lst)
{
	Elem *imprimir;
	if ((*lst) == NULL)
	{
		cout<<"N�o � possivel imprimir a lista pois ela est� vazia!"<<endl;
		return;
	}
	cout<<endl<<"--------------------------------------------"<<endl;
	cout<<"Nome";
	cout.fill(' ');//Comando estetico para preenchimento ap�s o campo "Nome" afim de manter o alinhamento desejado
	cout.width(36);//marca o limite do preenchimento.
	cout<<"�dade\tSexo"<<endl;
	cout<<"--------------------------------------------"<<endl;
	
	for(imprimir = *lst;imprimir != NULL; imprimir = imprimir->prox)
	{
		cout<<imprimir->dado.nome;
		//For para alinhamento estetico , strlen conta o n�mero de characteres contido em "nome" e realiza o preenchimento do restante at� o limite(30)
		for (int cont = strlen(imprimir->dado.nome); cont<=30;cont++)	
			cout<<" ";
		cout<<imprimir->dado.idade<<"\t "<<char(toupper(imprimir->dado.sexo))<<endl<<endl;//fun��o toupper converte letras minusculas para maiusculas
	}																				//Porem retorna um valor int por isto necessario usar "Char()" para realizar
}																					//uma convers�o do valor inteiro retornado para um charactere

//Imprimir percorrendo a lista de traz para a frente(inverso)
void Imprimir_inverso(Lista *lst)
{
	Elem *imprimir;
	
	if ((*lst) == NULL)
	{
		cout<<"N�o � possivel imprimir a lista pois ela est� vazia!"<<endl;
		return;
	}
	
	cout<<endl<<"--------------------------------------------"<<endl;
	cout<<"Nome";
	cout.fill(' ');
	cout.width(36);
	cout<<"�dade\tSexo"<<endl;
	cout<<"--------------------------------------------"<<endl;
	
	imprimir = *lst;
	
	while(imprimir->prox != NULL)
		imprimir = imprimir->prox;
		
	for(imprimir;imprimir != NULL; imprimir = imprimir->ant)
	{
		cout<<imprimir->dado.nome;
		for (int cont = strlen(imprimir->dado.nome); cont<=30;cont++)	
			cout<<" ";
		cout<<imprimir->dado.idade<<"\t "<<char(toupper(imprimir->dado.sexo))<<endl<<endl;
	}
}
//Remover elemento realizando compara��o de nome
int Buscar_remover (Lista *lst,char busca[30])
{
		Elem *no = *lst;
		
		while(no != NULL && strcmp(no->dado.nome,busca)!= 0)
			no = no->prox;
			
		if (no == NULL)//Elemento n�o encontrado
		{
			cout<<busca<<" N�o foi encontrado na lista."<<endl<<endl;
			return 0;		
		}
		cout<<no->dado.nome<<" foi removido da lista."<<endl<<endl;
		
		if (no->ant == NULL)//Remove primeiro elemento
			*lst = no->prox;
			
		else
			no->ant->prox = no->prox;
			
		if (no->prox != NULL)//meio lista ou fim
			no->prox->ant = no->ant;
			
		free(no);	
}

//Remover elemento da lista
int Remover_inicio(Lista *lst)
{
	if ((*lst) == NULL)//Verifica��o de lista vazia
	{
		cout<<"N�o � possivel remover o primeiro elemento da lista pois ela est� vazia!"<<endl;
		return 1;
	}
	
	Elem *no = *lst;
	*lst = no->prox;

	cout<<no->dado.nome<<" Foi removido da lista.";
	
	if (no->prox != NULL)//verifica se o proximo � diferente de null caso seja altera o ponteiro
		no->prox->ant = NULL;
		
	free(no);	
}

//Remover elemento do fim da lista
int Remover_fim(Lista *lst)
{
	if ((*lst) == NULL)
	{
		cout<<"N�o � possivel remover o �ltimo elemento da lista pois ela est� vazia!"<<endl;
		return 1;
	}
		Elem *no = *lst;
		
		while(no->prox != NULL )
			no = no->prox;
			
		cout<<no->dado.nome<<" foi removido da lista."<<endl<<endl;
		
		if (no->ant == NULL)
			*lst = no->prox;
			
		else
			no->ant->prox = NULL;
			
		free(no);	
}

//Menu do progama
int menu ()
{
	int escolha;
	
	do
	{
		system("cls");
		cout<<"----------------------------------------------"<<endl;
		cout<<"Escolha uma op��o:                            "<<endl;
		cout<<"----------------------------------------------"<<endl;	
		cout<<" [1] - Inserir uma pessoa no in�cio da lista. "<<endl;	
		cout<<"                                              "<<endl;
		cout<<" [2] - Inserir uma pessoa no fim da lista.    "<<endl;	
		cout<<"                                              "<<endl;	
		cout<<" [3] - Organizar lista em ordem alfabetica.   "<<endl;
		cout<<"                                              "<<endl;		
		cout<<" [4] - Imprimir a lista.                      "<<endl;
		cout<<"                                              "<<endl;	
		cout<<" [5] - Imprimir a lista inversa.              "<<endl;
		cout<<"                                              "<<endl;		
		cout<<" [6] - Buscar e remover pelo nome.            "<<endl;
		cout<<"                                              "<<endl;		
		cout<<" [7] - Remover o primeiro elemento.           "<<endl;
		cout<<"                                              "<<endl;	
		cout<<" [8] - Remover o �ltimo elemento.             "<<endl;
		cout<<"                                              "<<endl;		
		cout<<" [0] - Encerrar o programa.                   "<<endl;
		cout<<"----------------------------------------------"<<endl;
		cout<<" Escolha:";
		cin>>escolha;
	}while(escolha < 0 || escolha > 8);
	
	return escolha;
}

int main ()
{
//Sele��o de idioma para utiliza��o de acentos
	setlocale(LC_ALL,"Portuguese");
	
//Declara��o de variaveis
	Lista *lst;
	Pessoa Dado_pessoa;
	int escolha;
	char busca[30];
	
//Inicio Lista
	lst=Criar_lst();
	
//iniciando Menu
	escolha = menu();
	
	while ( escolha !=0)
	{
		switch (escolha)
		{
			// [1] - Inserir uma pessoa no in�cio da lista
			case 1:
	
				system("cls");
				cout<<endl<<"---------------------------------------"<<endl;
				cout<<"Nome:";
				(fflush(stdin));//Limpa o buffer do teclado para evitar erros no gets
				gets(Dado_pessoa.nome);
				(fflush(stdin));
				cout<<"---------------------------------------"<<endl;
				cout<<"Sexo:";
				cin>>Dado_pessoa.sexo;
				cout<<"---------------------------------------"<<endl;
				cout<<"�dade:";
				cin>>Dado_pessoa.idade;
				cout<<"---------------------------------------"<<endl<<endl;
				
				Inserir_inicio(lst,Dado_pessoa);//Armazena os dados recebidos na "struct pessoa" para depois passar as informa��es para o novo n�
				
				cout<<"Precione Qualquer tecla para retornar ao menu...";
				system("pause>>NULL");				
				break;
				
			// [2] - Inserir uma pessoa no fim da lista
			case 2:
				
				system("cls");
				cout<<endl<<"---------------------------------------"<<endl;
				cout<<"Nome:";
				(fflush(stdin));//Limpa o buffer do teclado para evitar erros no gets
				gets(Dado_pessoa.nome);
				(fflush(stdin));
				cout<<"---------------------------------------"<<endl;
				cout<<"Sexo:";
				cin>>Dado_pessoa.sexo;
				cout<<"---------------------------------------"<<endl;
				cout<<"�dade:";
				cin>>Dado_pessoa.idade;
				cout<<"---------------------------------------"<<endl<<endl;
				
				Inserir_fim(lst,Dado_pessoa);//Armazena os dados recebidos na "struct pessoa" para depois passar as informa��es para o novo no
				
				cout<<"Precione Qualquer tecla para retornar ao menu...";
				system("pause>>NULL");				
				break;
				
			// [3] - Organizar lista em ordem alfabetica
			case 3:
				system("cls");
				if ((*lst) == NULL)//Verifica��o de lista vazia
					cout<<"N�o foi possivel ordernar a lista pois ela est� vazia!"<<endl<<endl;
					
				else
				{
					Ordenar(lst);//Fun��o de ordena��o que recebe a lista como parametro
					cout<<endl<<"lista Ordenada com Sucesso!"<<endl<<endl;
				}				
				cout<<"Precione Qualquer tecla para retornar ao menu...";
				system("pause>>NULL");				
				break;
				
			// [4] - Imprimir a lista.
			case 4:
				system("cls");	
				Imprimir(lst);//Fun��o de impress�o da lista(completa)
				cout<<endl<<"Precione Qualquer tecla para retornar ao menu...";
				system("pause>>NULL");
				break;
				
			//[5] - Imprimir a lista inversa
			case 5:
				system("cls");
				Imprimir_inverso(lst);//Fun��o de impress�o da lista (inversa)
				cout<<endl<<"Precione Qualquer tecla para retornar ao menu...";
				system("pause>>NULL");
				break;
				
			// [6] - Buscar e remover pelo nome
			case 6:
				system("cls");
				if ((*lst) == NULL)//Verifica��o de lista vazia
					cout<<"N�o � possivel remover um nome da lista pois ela est� vazia!"<<endl;	
						
				else
				{
					cout<<"Informe o nome que ser� removido:";
					fflush(stdin);
					gets(busca);
					fflush(stdin);
					system("cls");
					Buscar_remover(lst,busca);
				}				
				cout<<endl<<"Precione Qualquer tecla para retornar ao menu...";
				system("pause>>NULL");
				break;
				
			// [7] - Remover o primeiro elemento
			case 7:
				system("cls");
				Remover_inicio(lst);
				cout<<endl<<"Precione Qualquer tecla para retornar ao menu...";
				system("pause>>NULL");
				break;
				
			//	[8] - Remover o �ltimo elemento.
			case 8:
				system("cls");
				Remover_fim(lst);
				cout<<endl<<"Precione Qualquer tecla para retornar ao menu...";
				system("pause>>NULL");
				break;
				
		}
		escolha= menu();
	}
	Limpa_lst(lst);//Esvazia a lista antes de encerrar o programa
}
