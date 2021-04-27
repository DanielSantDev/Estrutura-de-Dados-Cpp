
/*
Códigos Desenvolvidos por Daniel Santana.

ME ACOMPANHE PELAS REDES:

GITHUB: github.com/DanielSantDev
LINKEDIN: linkedin.com/in/ddanielssantana/
INSTAGRAM: instagram.com/daniel_san.t/

ENTRE EM CONTATO:

E-mail: daniel10gja@gmail.com

*/

#include <iostream>
#include "PilhaAlocacaoSequencial.h"

using namespace std;

int main() {

    unsigned tamanho;
    int opc, valor;
    cout<<"PILHA COM ALOCACAO SEQUENCIAL \n"<<endl;
    cout<<"Qual o tamanho da pilha? ";
    cin>>tamanho;

    Pilha<int> p(tamanho);

    do {

        cout<<"\n1 - EMPILHAR."<<endl;
        cout<<"2 - DESEMPILHAR."<<endl;
        cout<<"3 - ELEMENTO DO TOPO."<<endl;
        cout<<"4 - EXIBIR A PILHA."<<endl;
        cout<<"5 - FIM"<<endl;
        cout<<"SELECIONE: ";
        cin>>opc;

        switch(opc) {

        case 1:
            if( p.pilhacheia() ) {
                cout<<"PILHA CHEIA."<<endl;
            }
            else {
                cout<<"DIGITE O VALOR:";
                cin>>valor;
                p.empilha(valor);
                cout<<"SUCESSO!"<<endl;
            }
            break;

        case 2:
            if( p.pilhavazia() ) {
                cout<<"PILHA VAZIA."<<endl;
            }
            else {
                cout<<"DESEMPILHA: "<<p.desempilha()<<endl;
            }
            break;

        case 3:
            if( p.pilhavazia() ) {
                cout<<"PILHA VAZIA."<<endl;
            }
            else {
                cout<<"ELEMENTO DO TOPO: "<<p.elementodotopo()<<endl;
            }
            break;

        case 4:
            if( p.pilhavazia() ) {
                cout<<"PILHA VAZIA."<<endl;
            }
            else {
                cout<<"ELEMENTOS DA PILHA: "<<endl;
                for(int i=0; i<=p.getTopo();i++){
                    cout<<p.getValor(i)<< " ";
                }
                cout<<"\n\n";
            }
            break;

            case 9:
            cout<<"FIM."<<endl;
            break;

        default:
            cout<<"OPCAO INVALIDA."<<endl;
            break;
        }

    }while (opc !=9);
    return 0;
}
