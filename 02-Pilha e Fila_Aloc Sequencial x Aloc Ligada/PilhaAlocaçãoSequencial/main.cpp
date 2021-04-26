#include <iostream>
#include "pilhaalocaseq.h"
using namespace std;
int main()
{
    cout << "Pilha em Alocacao Sequencial" << endl;
    unsigned tamanho;
    int opc, valor;
    cout<<"Qual o tamanho da pilha?";
    cin>>tamanho;
    Pilha<int> p(tamanho);

    do{
        cout<<"1-empilhar"<<endl;
        cout<<"2-desempilhar"<<endl;
        cout<<"3-elemento do topo"<<endl;
        cout<<"4-exibir"<<endl;
        cout<<"9-fim"<<endl;
        cout<<"Selecione:";
        cin>>opc;
        switch(opc){
        case 1:
            if(p.pilhacheia()){
                cout<<"Pilha cheia...."<<endl;
            }
            else{
                cout<<"Digite o valor: ";
                cin>>valor;
                p.empilha(valor);
                cout<<"Sucesso"<<endl;
            }
            break;
        case 2:
            if(p.pilhavazia()){
                cout<<"Pilha vazia..."<<endl;
            }
            else{
                cout<<"Desempilha: "<<p.desempilha()<<endl;
            }
            break;
        case 3:
            if(p.pilhavazia()){
                cout<<"Pilha vazia..."<<endl;
            }
            else{
                cout<<"Elem. do topo:"<<p.elementodotopo()<<endl;
            }
            break;
        case 4:
            if(p.pilhavazia()){
                cout<<"Pilha vazia..."<<endl;
            }
            else{
                cout<<"Elementos da Pilha:"<<endl;
                for(int i=0; i<=p.getTopo();i++){
                    cout<<p.getValor(i)<< " ";
                }
                cout<<"\n\n";
            }
            break;
            case 9:
            cout<<"Fim...."<<endl;
            break;
        default:
            cout<<"opcao invalida..."<<endl;
            break;
        }

    }while (opc !=9);
    return 0;
}
