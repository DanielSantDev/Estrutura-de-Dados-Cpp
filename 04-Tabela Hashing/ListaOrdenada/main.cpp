#include <iostream>
#include "Lista_Ordenada.h"

using namespace std;

int main()
{
    cout << "  LISTA ORDENADA !" << endl;
    ListaOrdenada<int> Lista;

    int opc,num;

    do{
        cout<<"\n1 - INSERIR ELEMENTO."<<endl;
        cout<<"2 - REMOVER ELEMENTO."<<endl;
        cout<<"3 - BUSCAR ELEMENTO."<<endl;
        cout<<"4 - EXIBIR A LISTA."<<endl;
        cout<<"5 - FIM"<<endl;

        cout<<"\nDIGITE A OPCAO DESEJADA: ";
        cin>>opc;

        switch(opc)
        {
            case 1:
                cout<<"DIGITE O ELEMENTO: "<<endl;
                cin>>num;
                Lista.Insere(num);
                cout<<"NUMERO INSERIDO COM SUCESSO\n";
                break;

            case 2:
                cout<<"NUMERO "<< Lista.Remover() <<" REMOVIDO COM SUCESSO\n";
                break;

            case 3:
                cout<<"DIGITE O ELEMENTO: "<<endl;
                cin>>num;
                cout<<"ELEMENTO: "<<Lista.BuscarElemento(num)<<" FOI ENCONTRADO."<<endl;
                break;

            case 4:
                if(Lista.ListaVazia()) {
                    cout<<"A LISTA ESTAH VAZIA";
                }else {
                Node<int> *aux=Lista.h;
                while (aux != NULL) {
                cout<<aux->info<<" - ";
                aux = aux->prox;
                    }
                }
                break;

            case 5:
                cout<<"FIM DO PROGRAMA";
                break;

            default:
                cout<<"PFVR, DIGITE NOVAMENTE!"<<endl;
                break;
        }

    }while(opc!=5);
    return 0;
}

