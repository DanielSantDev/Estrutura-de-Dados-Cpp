#include <iostream>
#include "HashTable.h"

using namespace std;

int main()
{
    cout<<" *** TABELA HASHING *** "<<endl;
    Hash HT;

    int opc, num;

    do {
        cout<<"\n1 - INSERIR NOVO ELEMENTO."<<endl;
        cout<<"2 - REALIZAR A BUSCA DE UM ELEMENTO."<<endl;
        cout<<"3 - EXCLUIR UM ELEMENTO."<<endl;
        cout<<"4 - EXIBIR HASH TABLE."<<endl;
        cout<<"5 - SAIR."<<endl;

        cout<<"DIGITE A OPCAO DESEJADA: "<<endl;
        cin>>opc;

        switch(opc)
        {
            case 1:
                cout<<"DIGITE O ELEMENTO";
                cin>>num;
                HT.Insere(num);
                cout<<"O NUMERO "<<num<<", FOI INSERIDO!"<<endl;
                break;

            case 2:
                cout<<"A TABELA ESTAH VAZIA"<<endl;
                cout<<"DIGITE O ELEMENTO A SER BUSCADO: ";
                cin>>num;
                //HT.BuscarElemento(num);
                break;

            case 3:
                cout<<"DIGITE O ELEMENTO: "<<endl;
                cin>>num;
                //HT.Remover(num);
                break;

            case 4:
                cout<<"TABELA HASH: "<<endl;
                for (int i=0;i < W;i++){
                    Node *aux = HT.h[i];
                    cout<<"H[ "<<i<<" ]->";
                    while(aux !=NULL){
                        cout<<aux->info<<"->";
                        aux = aux->prox;
                    }
                    cout<<endl;
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
