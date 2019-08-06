#include <iostream>
#include <locale.h>
#include <queue>
#include <string>
using namespace std;
//Menu do programa
int menu(){
	int escolha;
	do{
	system("cls");
	cout<<"Escolha uma das opções abaixo:"<<endl;
	cout<<"[1] Inserir"<<endl;
	cout<<"[2] Retirar"<<endl;
	cout<<"[3] Inverter ordem da fila"<<endl;
	cout<<"[4] Exibir todos os livros da fila"<<endl;
	cout<<"[0] Sair"<<endl;
	cout<<"Escolha:";
	cin>>escolha;
	fflush(stdin);
	} while (escolha<0 ||escolha>4);
	return escolha;
}
struct fila{
	queue<string>nome;
	queue<string>autor;
	queue<float>valor;
};
int main ()
{
	setlocale(LC_ALL,"Portuguese");
//Variaveis
	fila livro,aux,inverter;
	string livro1,autor1,*p_nome,*p_autor,*fim_autor,*fim_nome;
	float valor1,*p_valor,*fim_valor;
	int escolha,cont;
//Inserir livros na fila
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
//Inicio programa
	escolha=menu();
	while (escolha != 0)
	{
		switch (escolha)
		{
		//Inserir livro na fila
			case 1:
				system("cls");
				cout<<"Informe o nome do livro que será inserido:";
				getline(cin,livro1);
				fflush(stdin);
				livro.nome.push(livro1);
				cout<<"Informe o autor de "<<livro1<<":";
				getline(cin,autor1);
				fflush(stdin);
				livro.autor.push(autor1);
				cout<<"Informe o valor do livro "<<livro1<<":";
				cin>>valor1;
				fflush(stdin);
				livro.valor.push(valor1);
				break;
		//Retirar livro da fila							
			case 2:
				system("cls");
				cout<<"Será removido da fila:"<<endl;
				cout<<"Livro:"<<livro.nome.front()<<endl<<"Autor:"<<livro.autor.front()<<endl<<"Valor:R$"<<livro.valor.front()<<endl<<endl;
				livro.nome.pop();
				livro.autor.pop();
				livro.valor.pop();
				system("pause");
				break;			
			case 3:
		//Inverter a ordem da fila	
				system("cls");
				p_nome=&livro.nome.front();
				p_autor=&livro.autor.front();
				p_valor=&livro.valor.front();
				fim_nome=&livro.nome.back();
				fim_autor=&livro.autor.back();
				fim_valor=&livro.valor.back();
				while (p_nome<fim_nome)
				{
				//Inverter nome
					livro1=*p_nome;
					*p_nome=*fim_nome;
					*fim_nome=livro1;
				//Inverter autor
					autor1=*p_autor;
					*p_autor=*fim_autor;
					*fim_autor=autor1;	
				//Inverter valor
					valor1=*p_valor;
					*p_valor=*fim_valor;
					*fim_valor=valor1;	
				//movimentação dos ponteiros
				p_nome++,p_autor++,p_valor++,fim_nome--,fim_autor--,fim_valor--;
				}
				cout<<"Sua pilha foi invertida com sucesso!"<<endl<<endl;
				system("pause");
				break;
		//Exibir todos os elementos da fila
			case 4:
				system("cls");
				cont=0;
				p_nome=&livro.nome.front();
				p_autor=&livro.autor.front();
				p_valor=&livro.valor.front();
				while(cont < livro.nome.size())
				{
					cout<<"Livro:"<<*p_nome<<endl<<"Autor:"<<*p_autor<<endl<<"Valor:R$"<<*p_valor<<endl<<endl;
					p_nome++;
					p_autor++;
					p_valor++;
					cont++;
				}
				system("pause");				
				break;			
		}		
		escolha=menu();
	}	
}
