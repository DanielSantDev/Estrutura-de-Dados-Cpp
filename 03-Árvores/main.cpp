#include <iostream>
#include "Arvore.h"

using namespace std;

int main()
{
    cout<<"ARVORE BINARIA DE BUSCA(BST)"<< endl;

    Bst<int> t1;
    int opc,valor;

    while(1){
        cout<<"\n1 - INSERIR ELEMENTO NA ARVORE."<<endl;
        cout<<"2 - REMOVER ELEMENTO."<<endl;
        cout<<"3 - EXIBIR EM PRE-ORDEM."<<endl;
        cout<<"4 - EXIBIR EM POS-ORDEM."<<endl;
        cout<<"5 - EXIBIR EM ORDEM."<<endl;
        cout<<"6 - EXIBIR O MAXIMO DOS NUMEROS."<<endl;
        cout<<"7 - EXIBIR O MINIMO DOS NUMEROS."<<endl;
        cout<<"0 - SAIR."<<endl;
        cout<<"SELECIONE -> ";

        cin>>opc;

        switch(opc) {

        case 1:
            cout<<"DIGITE O VALOR A SER INSERIDO: ";
            cin>>valor;
            t1.insere(t1.pRaiz,valor);
            break;

        case 2:
            cout<<"DIGITE O ELEMENTO A SER REMOVIDO: ";
            cin>>valor;

            break;

        case 3:
            cout<<"EXIBINDO A ARVORE EM PRE-ORDEM:"<<endl;
            t1.preOrdem(t1.pRaiz);
            break;

        case 4:
            cout<<"EXIBINDO A ARVORE EM POS-ORDEM:"<<endl;
            t1.posOrdem(t1.pRaiz);
            break;

        case 5:
            cout<<"EXIBINDO A ARVORE EM ORDEM:"<<endl;
            t1.emOrdem(t1.pRaiz);
            break;

        case 6:
            cout<<"EXIBIR O MAXIMO DOS NUMEROS:"<<endl;

            break;

        case 7:
            cout<<"EXIBIR O MINIMO DOS NUMEROS:"<<endl;

            break;

        case 0:
            return 0;

        default:
            cout<<"TENTE NOVAMENTE."<<endl;
            break;
        }

    }


    return 0;
}
