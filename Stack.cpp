#include <iostream>
#include <locale.h>
#include <stack>
#include <string>
using namespace std;
//Menu do programa
int menu(){
	int escolha;
	do{
	system("cls");
	cout<<"Escolha uma das opções abaixo:"<<endl;
	cout<<"->1. Empilhar"<<endl;
	cout<<"->2. Desempilhar"<<endl;
	cout<<"->3. Inverter ordem da pilha"<<endl;
	cout<<"->4. Exibir todos os livros da pilha"<<endl;
	cout<<"->0. Sair"<<endl;
	cout<<"Escolha:";
	cin>>escolha;
	fflush(stdin);
	} while (escolha<0 ||escolha>4);
	return escolha;
}
//Declaração da estrutura
struct pilha{	
	stack<string>nome;
	stack<string>autor;
	stack<float>valor;	
	void mostra (){
		cout<<"->"<<nome.top()<<endl;
		cout<<"->"<<autor.top()<<endl;
		cout<<"->"<<"R$"<<valor.top()<<endl;
		cout<<endl;
	}
	void remove(){
		nome.pop();
		autor.pop();
		valor.pop();
	}
	void inserir(string nome1,string autor1, float valor1){
		nome.push(nome1);
		autor.push(autor1);
		valor.push(valor1);
	}
	
};
//Programa principal
int main (){
	setlocale(LC_ALL,"Portuguese");
//Declaração de variaveis
	pilha livro,aux,invert;
	string nome1,autor1;
	float valor1;
	int escolha,i,valor;
//Preenchimento da pilha	
	/*1*/livro.nome.push("Harry Potter");
	livro.autor.push("J. K. Rowling");
	livro.valor.push(139.99);
	/*2*/livro.nome.push("Sherlock holmes");
	livro.autor.push("Arthur Conan");
	livro.valor.push(76.90);
	/*3*/livro.nome.push("Geração de valor");
	livro.autor.push("Flavio Algusto");
	livro.valor.push(31.19);	
	/*4*/livro.nome.push("O Jeito Disney de Encantar Os Clientes");
	livro.autor.push("Michael D. Eisner");
	livro.valor.push(18.90);	
	/*5*/livro.nome.push("O jeito harvard de ser feliz");
	livro.autor.push("Shawn Achor");
	livro.valor.push(30.90);
	/*6*/livro.nome.push("O Mito do Empreendedor");
	livro.autor.push("Micael E. Gerber");
	livro.valor.push(68.20);
	/*7*/livro.nome.push("O mínimo que você precisa saber para não ser um idiota");
	livro.autor.push("Olavo de Carvalho");
	livro.valor.push(52.90);
	/*8*/livro.nome.push("Direitos máximos, deveres mínimos");
	livro.autor.push("Bruno Garschagen");
	livro.valor.push(49.90);
	/*9*/livro.nome.push("38 estratégias para cencer qualquer debate");
	livro.autor.push("Arthur Schopenhauer");
	livro.valor.push(16.90);
	/*10*/livro.nome.push("O Monge e o Executivo");
	livro.autor.push("James C. Hunter");
	livro.valor.push(27.90);
//Fim pilha
	escolha=menu();
	while (escolha !=0)
	{
		switch (escolha)
		{
			case 1:
			
				system("cls");
				cout<<"Informe o nome do livro:";
				getline (cin,nome1);
				fflush(stdin);
				cout<<"Informe o autor:";
				getline(cin,autor1);
				fflush(stdin);
				cout<<"Informe o valor:";
				cin>>valor1;
				fflush(stdin);
				livro.inserir(nome1,autor1,valor1);				
				break;			
			case 2:
				system("cls");
				if (livro.nome.empty() !=1)
				{
					cout<<"Será removido da pilha:"<<endl;
					livro.mostra();
					cout<<endl<<endl;
					livro.remove();
					system("pause");
				}
				else
				{
					cout<<"Não possui elementos a serem removidos da lista."<<endl;
					system("pause");
				}					
				break;
			case 3:
				system("cls");
				i=livro.nome.size();
				while (i>0)
				{
				//Realocação para a pilha auxiliar	
				//	livro.armazenar(nome1,autor1,valor1);			
					nome1=livro.nome.top();
					autor1=livro.autor.top();
					valor1=livro.valor.top();
					aux.inserir(nome1,autor1,valor1);
				//remoção da pilha principal
					livro.remove();
					i--;
				}
				i=aux.nome.size();
				while (i>0)
				{
				//Realocação para a pilha de inversão
					nome1 = aux.nome.top();					
					autor1 = aux.autor.top();					
					valor1 = aux.valor.top();				
					invert.inserir(nome1,autor1,valor1);
				//Remoção da pilha auxiliar
					aux.remove();
					i--;
				}
				i=invert.nome.size();
				while (i>0)
				{
				//Realocando na pilha principal
					nome1 = invert.nome.top();					
					autor1 = invert.autor.top();					
					valor1 = invert.valor.top();
					livro.inserir(nome1,autor1,valor1);
				//Removendo da pilha inversora
					invert.remove();
					i--;
				}		
				cout<<"A sua pilha foi invertida com sucesso!"<<endl<<endl;
				system("pause");
				break;
			case 4:
				i=livro.nome.size();
				system("cls");
				while (i >0)
				{					
				//Exibição
					livro.mostra();
				//armazenamento
					nome1=livro.nome.top();
					autor1=livro.autor.top();
					valor1=livro.valor.top();
				//realocação no auxiliar
					aux.inserir(nome1,autor1,valor1);
				//remoção
					livro.remove();
					i--;				
				}
				i=aux.nome.size();
				while (i > 0)
				{
				//armazenamento
					nome1 =aux.nome.top();
					autor1 = aux.autor.top();
					valor1 = aux.valor.top();
				//Realocação na pilha principal
					livro.inserir(nome1,autor1,valor1);
				//remoção
					aux.remove();
					i--;
				}
				system("pause");
				break;
		}
		escolha = menu();
	}	
}
	

