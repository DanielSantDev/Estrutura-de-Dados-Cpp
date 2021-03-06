/*
C?digos Desenvolvidos por Daniel Santana.

ME ACOMPANHE PELAS REDES:

GITHUB: github.com/DanielSantDev
LINKEDIN: linkedin.com/in/ddanielssantana/
INSTAGRAM: instagram.com/daniel_san.t/

ENTRE EM CONTATO:

E-mail: daniel10gja@gmail.com

*/

#include <iostream>
#include "FilaAlocacaoSequencial.h"

using namespace std;

int main() {

    unsigned tamanho;
    int opc, valor;
    cout << "FILA COM ALOCACAO SEQUENCIAL\n" << endl;
    cout<<"QUAL O TAMANHO DA FILA? ";
    cin>>tamanho;
    Fila<int> f(tamanho);

    do {
        cout<<"\n1 - INSERIR."<<endl;
        cout<<"2 - REMOVER."<<endl;
        cout<<"3 - ELEMENTO INICIAL."<<endl;
        cout<<"4 - EXIBIR FILA."<<endl;
        cout<<"5 - SAIR DO PROGRAMA."<<endl;
        cout<<"SELECIONE: ";
        cin>>opc;

        switch(opc) {

        case 1:
            cout<<"DIGITE O VALOR: ";
            cin>>valor;
            if( f.filacheia() ) {
                cout<<"A FILA ESTAH CHEIA!"<<endl;
            }
            else {
                f.insere(valor);
                cout<<"INSERIDO COM SUCESSO!"<<endl;
            }

            break;

        case 2:
            if( f.filavazia() ) {
                cout<<"FILA VAZIA"<<endl;
            }
            else {
                cout<<"O NUMERO: "<<f.remover()<<", FOI REMOVIDO COM SUCESSO!"<<endl;
            }
            break;

        case 3:
            if( f.filavazia() ) {
                cout<<"FILA VAZIA."<<endl;
            }
            else {
                cout<<"PRIMEIRO ELEMENTO DA FILA: "<<f.primeiro()<<endl;
            }
            break;

        case 4:
            if( f.filavazia() ) {
                cout<<"A ESTAH FILA VAZIA."<<endl;
            }
            else {
                cout<<"ELEMENTOS DA FILA: "<<endl;
                if(f.getInic() <= f.getFim()) {
                for( int i = f.getInic() ; i <= f.getFim() ; i++ ) {
                    cout<<f.getValor(i)<< " | ";
                    }
                }
                else {
                    for( int i=f.getInic() ; i<f.getTamanho() ; i++ ) {
                        cout<<f.getValor(i)<<" | ";
                    }
                    for( int i=0 ; i<=f.getFim() ; i++ ) {
                        cout<<f.getValor(i)<<" | ";
                    }
                }
            }
            cout<<"\n";
            break;

        case 5:
            cout<<"FIM DO PROGRAMA!"<<endl;
            break;

        default:
            cout<<"OPCAO INVALIDA! TENTE NOVAMENTE!"<<endl;
            break;
        }

    } while (opc !=5);
    return 0;
}
