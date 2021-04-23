#include <iostream>
using namespace std;

/*CONCEITO DE LISTA LINEAR
Lista linear: � uma estrutura de dados na qual elementos de um mesmo tipo de dado est�o organizados de maneira sequencial.N�o necessariamente, estes elem-
entos est�o fisicamente em sequ�ncia, mas a id�ia � que exista uma ordem l�gica entre eles. Cada elemento da lista � chamado de n�, ou nodo.
Tipos de Listas Lineares; Pilhas e Filas.
__________________________________________________________________________________________________________________________________________________________
**Aloca��o de uma lista**

1--Aloca��o Sequencial/Est�tica/Cont�gua;
Numa lista linear cont�gua, os elementos(n�s) al�m de estarem em uma sequ�ncia l�gica, est�o tamb�m fisicamente em sequ�ncia. A maneira mais simples de ac-
omodar uma lista linear em um computador � atrav�s da utiliza��o de um vetor. A representa��o por vetor explora a sequencialidade da mem�ria de tal forma 
que os n�s de uma lista sejam armazenados em endere�os cont�guos.

2--Aloca��o Encadeada/Din�mica/Ligada
Os elementos n�o est�o necessariamente armazenados sequencialmente na mem�ria, por�m a ordem l�gica entre os elementos que comp�em a lista deve ser mantida.
Nesse tipo de aloca��o, as posi��es da mem�ria s�o alocadas(ou desalocadas) na medida em que s�o necess�rias. Os n�s de uma lista encontram-se ent�o aleat�-
riamente dispostos na mem�ria e s�o interligados por ponteiros, que indicam a posi��o do pr�ximo elemento da tabela. � necess�rio o acr�scimo de um campo a
cada n�, justamente o que indica o endere�� do pr�ximo n� da lista.
___________________________________________________________________________________________________________________________________________________________
Bibliografia
*Estruturas De Dados E Seus Algoritmos
SZWARCFITER, Jayme Luiz; Markenzon, Lilian
Editora LCT*
___________________________________________________________________________________________________________________________________________________________
Pesquisa e C�digos feitos por Daniel Santana.

GitHub: github.com/DanielSantDev
E-mail: daniel10gja@gmail.com
Linkedin: linkedin.com/in/ddanielssantana/
Instagram: instagram.com/daniel_san.t/

*/

/*ESCOLHA O ALGORITMO DE ESTRUTURA DE DADOS QUE DESEJA:
*Pilha1 OU Pilha2
*Fila1 OU Fila2
*Lista
*/
#define Pilha1


#ifdef Pilha1
/*Pilha/Stack -> Lista Linear Restrita;
Pilhas s�o estruturas de dados do tipo LIFO (last-in first-out), onde o �ltimo elemento a ser inserido, ser� o primeiro a ser retirado.
Assim, uma pilha permite acesso a apenas um item de dados - o �ltimo inserido. Para processar o pen�ltimo item inserido, deve-se remover o �ltimo.
*/

//Usando a biblioteca stack;
#include <stack>
int main()
{
    stack<int>Pilha;
    int opc,x;
    do{
    cout<<"1 - Adicionar um numero na Pilha"<<endl;
    cout<<"2 - Remover um numero da Pilha"<<endl;
    cout<<"3 - Ver elemento do topo"<<endl;
    cout<<"4 - Quantidades de elementos da Pilha"<<endl;
    cout<<"5 - Sair"<<endl;
    cin>>opc;
        switch(opc){
            case 1:
                system("cls");
                cout<<"Digite um valor: ";
                cin>>x;
                Pilha.push(x);
                break;
            case 2:
                system("cls");
                if(Pilha.empty()){
                    cout<<"Pilha Vazia";
                }
                else{
                    Pilha.pop();
                }
                break;
            case 3:
                system("cls");
                if(Pilha.empty()){
                    cout<<"Pilha Vazia";
                }
                else{
                    cout<<"Elemento do Topo:"<<Pilha.top()<<"\n\n";

                }
                break;
            case 4:
                system("cls");
                if(Pilha.empty()){
                    cout<<"Pilha Vazia";
                }
                else{
                    cout<<"Quantidade de Elementos: "<<Pilha.size()<<"\n\n";
                }
                break;
            case 6:
                cout<<"Saindo do Programa...";
                break;
            default: cout<<"Opcao incorreta, tente novamente."<<endl;
        }
    }while(opc!=5);
    return 0;
}
#endif

#ifdef Pilha2
struct Pilha{
	int topo;
	int capa;
	float *pElem;
};

void criarpilha( struct Pilha *p, int c ){
   p->topo = -1;
   p->capa = c;
   p->pElem = (float*) malloc (c * sizeof(float));
}
int estavazia ( struct Pilha *p ){
   if(p->topo == -1)
      return 1;
   else
      return 0;

}

int estacheia(struct Pilha *p){
	if (p->topo == p->capa - 1)
		return 1;
	else
		return 0;
}

void empilhar ( struct Pilha *p, float v){
	p->topo++;
	p->pElem [p->topo] = v;
}

float desempilhar ( struct Pilha *p ){
   float aux = p->pElem [p->topo];
   p->topo--;
   return aux;
}

float retornatopo ( struct Pilha *p ){
   return p->pElem [p->topo];
}

int main(){
	struct Pilha minhapilha;
	int capacidade, op;
	float valor;

	printf( "\nCapacidade da pilha? " );
	scanf( "%d", &capacidade );

	criarpilha (&minhapilha, capacidade);

	while( 1 ){
		printf("\n1- empilhar(push)\n");
		printf("2- desempilhar(pop)\n");
		printf("3- Mostrar o topo(top) \n");
		printf("4- sair\n");
		printf("\nopcao? ");
		scanf("%d", &op);
		switch (op){
			case 1: //push
				if(estacheia( &minhapilha ) == 1)
					printf("\nPILHA CHEIA! \n");
				else {
					printf("\nVALOR? ");
					scanf("%f", &valor);
					empilhar (&minhapilha, valor);
				}
				break;
			case 2: //pop
				if (estavazia(&minhapilha) == 1)
					printf( "\nPILHA VAZIA! \n" );
				else{
					valor = desempilhar (&minhapilha);
					printf ( "\n%.1f DESEMPILHADO!\n", valor );
				}
				break;
			case 3: //top
				if (estavazia (&minhapilha) == 1)
					printf( "\nPILHA VAZIA!\n" );
				else {
					valor = retornatopo (&minhapilha);
					printf ( "\nTOPO: %.1f\n", valor );
				}
				break;
			case 4:
				exit(0);
			default: printf( "\nOPCAO INVALIDA! \n" );
		}
	}
}
#endif // Pilha2


#ifdef Fila1
/*Fila/Queue
Fila s�o estruturas de dados do tipo FIFO (first-in first-out), onde o primeiro elemento a ser inserido,ser� o primeiro
a ser retirado, ou seja, adiciona-se itens no fim e remove-se do in�cio. A implementa��o de filas pode ser realizada
atrav�s de vetor (aloca��o do espa�o de mem�ria para os elementos � cont�gua) ou atrav�s de listas encadeadas.
Fila � uma lista linear restrita pelo fato das opera��es de acesso e remo��o serem realizadas em uma das extremidades
chamada in�cio e a opera��o de inser��o ser realizada na outra extremidade chama fim.
Os Elementos s�o os N�s, a remo��o de um elemento da fila � realizada apenas alterando-se a informa��o da posi��o do �ltimo.
As refer�ncias primeiro e �ltimo circundam at� o inicio do vetor, desta forma a fila simula uma representa��o Circular
*/

//Usando a biblioteca queue;
#include <queue>

int main(){
    queue<int>Fila;
    int opc,x;
    do{
    cout<<"1 - Adicionar um numero na Fila"<<endl;
    cout<<"2 - Remover um numero da Fila"<<endl;
    cout<<"3 - Ver o ulitmo elemento da Fila"<<endl;
    cout<<"4 - Ver o primeiro elemento da Fila"<<endl;
    cout<<"5 - Quantidades de elementos da Fila"<<endl;
    cout<<"6 - Sair do programa."<<endl;
    cin>>opc;
        switch(opc){
            case 1:
                system("cls");
                cout<<"Digite um valor: ";
                cin>>x;
                Fila.push(x);
                break;
            case 2:
                system("cls");
                if(Fila.empty()){
                    cout<<"Fila Vazia";
                }
                else{
                    Fila.pop();
                }
                break;
            case 3:
                system("cls");
                if(Fila.empty()){
                    cout<<"Fila Vazia";
                }
                else{
                    cout<<"Ultimo Elemento: "<<Fila.back()<<"\n";
                }
                break;
            case 4:
                system("cls");
                if(Fila.empty()){
                    cout<<"Fila Vazia";
                }
                else{
                    cout<<"Primeiro Elemento: "<<Fila.front()<<"\n";
                }
                break;
            case 5:
                system("cls");
                if(Fila.empty()){
                    cout<<"Fila Vazia";
                }
                else{
                    cout<<"Quantidade de Elementos: "<<Fila.size()<<"\n\n";
                }
                break;
            case 6:
                cout<<"Saindo do Programa...";
                break;
            default: cout<<"Opcao incorreta, tente novamente."<<endl;
        }
    }while(opc!=6);
    return 0;
}
#endif // Fila1

#ifdef Fila2

struct Fila{
	int capacidade;
	float *dados;
	int primeiro;
	int ultimo;
	int nItens;
};

void criarFila( struct Fila *f, int c ){
	f->capacidade = c;
	f->dados = (float*) malloc (f->capacidade * sizeof(float));
	f->primeiro = 0;
	f->ultimo = -1;
	f->nItens = 0;
}

void inserir(struct Fila *f, int v){

	if(f->ultimo == f->capacidade-1){
        f->ultimo = -1;
	}

	f->ultimo++;
	f->dados[f->ultimo] = v;
	f->nItens++;
}

int remover( struct Fila *f ){

	int temp = f->dados[f->primeiro++];

	if(f->primeiro == f->capacidade){
		f->primeiro = 0;
	}

	f->nItens--;
	return temp;
}

int estaVazia( struct Fila *f ){
	return (f->nItens==0);
}

int estaCheia( struct Fila *f ){
	return (f->nItens == f->capacidade);
}

void mostrarFila(struct Fila *f){
	int cont, i;
	for ( cont=0, i= f->primeiro; cont < f->nItens; cont++){
		printf("%.2f\t",f->dados[i++]);
		if (i == f->capacidade){
            i=0;
		}
	}
	printf("\n\n");
}

int main(){
	int opcao, capa;
	float valor;
	struct Fila umaFila;
	printf("Qual serah a capacidade da fila? ");
	scanf("%d",&capa);
	criarFila(&umaFila, capa);

	while(1){
		printf("\n1 - Inserir elemento\n2 - Remover elemento\n3 - Mostrar Fila\n0 - Sair\n\nOpcao? ");
		scanf("%d", &opcao);
		switch(opcao){
			case 0: exit(0);
			case 1: // insere elemento
				if (estaCheia(&umaFila)){
					printf("\nFila Cheia!!!\n\n");
				}
				else{
					printf("\nQual o valor do elemento a ser inserido? ");
					scanf("%f", &valor);
					inserir(&umaFila,valor);
				}
				break;
			case 2: // remove elemento
				if (estaVazia(&umaFila)){
					printf("\nFila vazia!\n\n");
				}
				else{
					valor = remover(&umaFila);
					printf("\n%1f removido com sucesso\n\n", valor) ;
				}
				break;
				case 3: // mostrar fila
					if (estaVazia(&umaFila)){
						printf("\nFila vazia!!!\n\n");
					}
					else{
						printf("\nConteudo da fila => ");
						mostrarFila(&umaFila);
					}
					break;
				default:
					printf("\nOpcao Invalida\n\n");
		}
	}
	return 0;
}
#endif // Fila2

#ifdef Lista
/*Listas Lineares Encadeadas: Os elementos, n�s, n�o est�o necessariamente armazenados sequencialmente na mem�ria.
Assim, para manter a ordem l�gica dos elementos, as listas lineares encadeadas podem ser implementadas de dois jeitos;

1 - Listas Encadeadas: numa lista linear simplesmente encadeada cada elemento possui, al�m do espa�o para armazenamento da
informa��o, um espa�o para armazenar uma refer�ncia da localiza��o na mem�ria onde o pr�ximo elemento da lista (ou o anterior) se encontra.

2 - Listas Duplamente Encadeadas: Numa lista linear duplamente encadeada cada elemento possui, al�m do espa�o para armazenamento da
informa��o, um espa�o para armazenar a referencia da localiza��o de mem�ria onde se encontra o pr�ximo elemento da lista e outro espa�o
para armazenar a referencia da localiza��o de mem�ria onde se encontra o elemento anterior.
* A vantagem da utiliza��o de lista duplamente encadeada sobre a lista simplesmente encadeada � a maior facilidade para navega��o, que na
lista duplamente encadeada pode ser feita nos dois sentidos, ou seja, do in�cio para o fim e do fim para o in�cio. Isso facilita a realiza��o
de opera��es tais como inclus�o e remo��o de n�s, pois diminui a quantidade de vari�veis auxiliares necess�rias.
*Vantagens
*-Melhor utiliza��o dos recursos de mem�ria
*-N�o precisa movimentar os elementos nas opera��es de inser��o e remo��o

*Desvantagens
*-Acesso indireto aos elementos
*-Necessidade de percorrer a lista para acessar um elemento
*/

struct Nodo{
	int info;
	struct Nodo *prox;
};

struct ListaSimplesEnc {
	struct Nodo *prim;
};

void criarLista (struct ListaSimplesEnc *pList) {
	pList -> prim = NULL;
}

void mostrarLista (struct ListaSimplesEnc *pList){
	struct Nodo *p;
	for (p = pList -> prim; p != NULL; p = p->prox) {
		printf("%d\t", p->info);
	}
	printf("\n");
}

void inserirIni (struct ListaSimplesEnc *pList, int v){
	struct Nodo *novo;
	novo = (struct Nodo*) malloc (sizeof (struct Nodo));
	novo -> info = v;
	novo -> prox = pList -> prim;
	pList -> prim = novo;
}

void removerIni (struct ListaSimplesEnc *pList){
	struct Nodo *pAux = pList -> prim;
	pList -> prim = pList -> prim -> prox;
	free(pAux);
}

void inserirOrd (struct ListaSimplesEnc *pList, int v){
	struct Nodo *novo;
	novo = (struct Nodo*) malloc (sizeof (struct Nodo));
	novo -> info = v;
	struct Nodo *pAtu, *pAnt;
	pAnt = NULL;
	pAtu = pList -> prim;
	while ( pAtu != NULL && pAtu->info < v){
		pAnt = pAtu;
		pAtu = pAtu -> prox;
	}
	novo -> prox = pAtu -> prox;
	pAnt -> prox = novo;
}

int estaVazia(struct ListaSimplesEnc *pList) {
	return (pList->prim == NULL);
}

int main(){
	struct ListaSimplesEnc minhaLista;
	int valor, op;

	criarLista(&minhaLista);

	while( 1 ){
		printf( "1 - Inserir elemento no inicio\n" );
		printf( "2 - Inserir elemento em ordem (so se a lista estiver ordenada)\n" );
		printf( "3 - Remover elemento no inicio\n" );
		printf( "4 - Remover elemento\n" );
		printf( "5 - Mostrar lista\n" );
		printf( "6 - Sair\n" );
		printf( "Opcao? " );
		scanf( "%d", &op );
		switch( op ){
			case 1: // inserir elemento no inicio
				printf( "Valor? " );
				scanf( "%d", &valor );
				inserirIni(&minhaLista, valor);
				break;
			case 2: // inserir elemento ordenado
				printf( "Valor? " );
				scanf( "%d", &valor );
				inserirOrd(&minhaLista, valor);
				break;
			case 3: // remover o primeiro
				break;
			case 4: // remover determinado elemento
				break;
			case 5: //  mostrar lista
				if (estaVazia(&minhaLista)) {
					printf("Lista vazia");
				}
				else {
					mostrarLista(&minhaLista);
				}
				break;
			case 6: // abandonar o programa
				exit(0);
		}
	}
	return 0;
}
#endif // Lista
