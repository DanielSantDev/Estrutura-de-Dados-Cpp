#include <iostream>
#include "pilhaligada.h"

/*
***ALOCA��O ENCADEADA/DIN�MICA/LIGADA***

    OS ELEMENTOS N�O EST�O NECESSARIAMENTE ARMAZENADOS SEQUENCIALMENTE NA MEM�RIA,
POR�M A ORDEM L�GICA ENTRE OS ELEMENTOS QUE COMP�EM A LISTA DEVE SER MANTIDA. NESSE
TIPO DE ALOCA��O, AS POSI��ES DA MEM�RIA S�O ALOCADAS(OU DESALOCADAS) NA MEDIDA EM
QUE S�O NECESS�RIAS. OS N�S DE UMA LISTA ENCONTRAM-SE ENT�O ALEAT�RIAMENTE DISPOSTOS
NA MEM�RIA E S�O INTERLIGADOS POR PONTEIROS, QUE INDICAM A POSI��O DO PR�XIMO ELEMENTO
DA TABELA. � NECESS�RIO O ACR�SCIMO DE UM CAMPO A CADA N�, JUSTAMENTE O QUE INDICA O
ENDERE�O DO PR�XIMO N� DA LISTA.

    UMA LISTA LIGADA � UMA ESTRUTURA QUE CORRESPONDE A UMA SEQU�NCIA L�GICA DE ENTRADAS
OU N�S. TIPICAMENTE, EM UMA LISTA LIGADA H� UM OU DOIS PONTOS CONHECIDOS DE ACESSO --
NORMALMENTE O TOPO DA LISTA (SEU PRIMEIRO ELEMENTO) E EVENTUALMENTE O FIM DA LISTA
(SEU �LTIMO ELEMENTO). CADA N� ARMAZENA TAMB�M A LOCALIZA��O DO PR�XIMO ELEMENTO NA
SEQU�NCIA, OU SEJA, DE SEU N� SUCESSOR. DESSE MODO, O ARMAZENAMENTO DE UMA LISTA N�O
REQUER UMA �REA CONT�GUA DE MEM�RIA.

***MANIPULA��O DE N�***

    UM N� � ESSENCIALMENTE UMA ESTRUTURA COM DOIS CAMPOS DE INTERESSE: INFO, O CONTE�DO
DO N�, E NEXT, UMA REFER�NCIA PARA O PR�XIMO N� DA LISTA. A ENTRADA QUE DETERMINA O TOPO
DA LISTA DEVE SER REGISTRADA � PARTE DA LISTA. ESSA INFORMA��O � TIPICAMENTE MANTIDA EM
UM N� DESCRITOR DA LISTA. A ENTRADA QUE MARCA O FIM DA LISTA N�O PRECISA DE INDICA��O
ESPECIAL -- TIPICAMENTE, O PONTEIRO NULO COMO VALOR DE NEXT MARCA O FINAL DA LISTA.

    N� DE UMA LITA � UM REGISTRO COM A SEGUINTE ESTRUTURA:
    **INFO: ALOCA RECURSOS(�REA DE MEM�RIA) PARA GUARDAR A INFORMA��O ESPECIFICADA NOS
ARGUMENTOS. RETORNA UMA REFER�NCIA PARA O N� CRIADO, DO TIPO NODE
    **NODE(): LIBERA OS RECURSOS USADOS PELO N�

    PARA ESTABELECER A LIGA��O ENTRE UM N� J� PERTENCENTE A UMA LISTA E UM NOVO N�, BASTA
FAZER COM QUE O NOVO N� REFERENCIE NO CAMPO NEXT O N� QUE ANTERIORMENTE ERA REFERENCIADO
PELO N� ORIGINAL -- MESMO QUE ESSE CAMPO TENHA O VALOR NULO. PARA CONCLUIR A CONEX�O, O N�
ORIGINAL DEVE TER ATUALIZADO O CAMPO NEXT PARA REFERENCIAR O NOVO N�.

***IMPLEMENTA��ES DA LISTA***

    FILAS E PILHAS S�O ESTRUTURAS USUALMENTE IMPLEMENTADAS ATRAV�S DE LISTAS, RESTRIGINDO A
POL�TICA DE MANIPULA��O DOS ELEMENTOS DA LISTA

    **A SEGUIR, TEMOS UMA IMPLEMENTA��O DE UMA PILHA COM ALOCA��O LIGADA EM C++.
    **A PILHA E SUAS RESPECTIVAS FUN��ES DE MANIPULA��O SE ENCONTRAM NO ARQUIVO HEADER (pilhaligada.h).
*/

using namespace std;

int main()
{
    cout << "PILHA COM ALOCACAO LIGADA\n" << endl;
    Pilha<int> p;
    int x, opc;
    do{
        cout<<"\n1 - EMPILHAR."<<endl;
        cout<<"2 - DESEMPILHAR."<<endl;
        cout<<"3 - ELEMENTO DO TOPO."<<endl;
        cout<<"4 - EXIBIR A PILHA."<<endl;
        cout<<"5 - FIM"<<endl;
        cout<<"SELECIONE: ";
        cin>>opc;
        switch(opc){
        case 1:
            cout<<"DIGITE O VALOR:";
            cin>>x;
            if (p.empilha(x)){
                cout<<"SUCESSO!"<<endl;
            }
            else{
                cout<<"PILHA CHEIA."<<endl;
            }
            break;
        case 2:
            if(p.pilhavazia()){
                cout<<"PILHA VAZIA."<<endl;
            }
            else{
                cout<<"DESEMPILHA:"<<p.desempilha()<<endl;
            }
            break;
        case 3:
            if(p.pilhavazia()){
                cout<<"PILHA VAZIA."<<endl;
            }
            else{
                cout<<"ELEMENTO DO TOPO:"<<p.elementodotopo()<<endl;
            }
            break;
        case 4:
            cout<<"ELEMENTOS DA PILHA: ";
            if(p.pilhavazia()){
                cout<<"PILHA VAZIA."<<endl;
            }
            else{
               Node<int> *aux = p.getTopo();
               while(aux != NULL){
                 cout<<aux->info<< " ";
                 aux = aux->prox;
               }
               cout<<endl;
            }
            break;
        case 5:
            cout<<"FIM."<<endl;
            break;
        default:
            cout<<"OPCAO INVALIDA."<<endl;
            break;
        }
    }while (opc != 5);
    return 0;
}
