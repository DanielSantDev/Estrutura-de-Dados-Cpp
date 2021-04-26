#include <iostream>
#include "pilhaligada.h"

/*
***ALOCAÇÃO ENCADEADA/DINÂMICA/LIGADA***

    OS ELEMENTOS NÃO ESTÃO NECESSARIAMENTE ARMAZENADOS SEQUENCIALMENTE NA MEMÓRIA,
PORÉM A ORDEM LÓGICA ENTRE OS ELEMENTOS QUE COMPÕEM A LISTA DEVE SER MANTIDA. NESSE
TIPO DE ALOCAÇÃO, AS POSIÇÕES DA MEMÓRIA SÃO ALOCADAS(OU DESALOCADAS) NA MEDIDA EM
QUE SÃO NECESSÁRIAS. OS NÓS DE UMA LISTA ENCONTRAM-SE ENTÃO ALEATÓRIAMENTE DISPOSTOS
NA MEMÓRIA E SÃO INTERLIGADOS POR PONTEIROS, QUE INDICAM A POSIÇÃO DO PRÓXIMO ELEMENTO
DA TABELA. É NECESSÁRIO O ACRÉSCIMO DE UM CAMPO A CADA NÓ, JUSTAMENTE O QUE INDICA O
ENDEREÇO DO PRÓXIMO NÓ DA LISTA.

    UMA LISTA LIGADA É UMA ESTRUTURA QUE CORRESPONDE A UMA SEQUÊNCIA LÓGICA DE ENTRADAS
OU NÓS. TIPICAMENTE, EM UMA LISTA LIGADA HÁ UM OU DOIS PONTOS CONHECIDOS DE ACESSO --
NORMALMENTE O TOPO DA LISTA (SEU PRIMEIRO ELEMENTO) E EVENTUALMENTE O FIM DA LISTA
(SEU ÚLTIMO ELEMENTO). CADA NÓ ARMAZENA TAMBÉM A LOCALIZAÇÃO DO PRÓXIMO ELEMENTO NA
SEQUÊNCIA, OU SEJA, DE SEU NÓ SUCESSOR. DESSE MODO, O ARMAZENAMENTO DE UMA LISTA NÃO
REQUER UMA ÁREA CONTÍGUA DE MEMÓRIA.

***MANIPULAÇÃO DE NÓ***

    UM NÓ É ESSENCIALMENTE UMA ESTRUTURA COM DOIS CAMPOS DE INTERESSE: INFO, O CONTEÚDO
DO NÓ, E NEXT, UMA REFERÊNCIA PARA O PRÓXIMO NÓ DA LISTA. A ENTRADA QUE DETERMINA O TOPO
DA LISTA DEVE SER REGISTRADA À PARTE DA LISTA. ESSA INFORMAÇÃO É TIPICAMENTE MANTIDA EM
UM NÓ DESCRITOR DA LISTA. A ENTRADA QUE MARCA O FIM DA LISTA NÃO PRECISA DE INDICAÇÃO
ESPECIAL -- TIPICAMENTE, O PONTEIRO NULO COMO VALOR DE NEXT MARCA O FINAL DA LISTA.

    NÓ DE UMA LITA É UM REGISTRO COM A SEGUINTE ESTRUTURA:
    **INFO: ALOCA RECURSOS(ÁREA DE MEMÓRIA) PARA GUARDAR A INFORMAÇÃO ESPECIFICADA NOS
ARGUMENTOS. RETORNA UMA REFERÊNCIA PARA O NÓ CRIADO, DO TIPO NODE
    **NODE(): LIBERA OS RECURSOS USADOS PELO NÓ

    PARA ESTABELECER A LIGAÇÃO ENTRE UM NÓ JÁ PERTENCENTE A UMA LISTA E UM NOVO NÓ, BASTA
FAZER COM QUE O NOVO NÓ REFERENCIE NO CAMPO NEXT O NÓ QUE ANTERIORMENTE ERA REFERENCIADO
PELO NÓ ORIGINAL -- MESMO QUE ESSE CAMPO TENHA O VALOR NULO. PARA CONCLUIR A CONEXãO, O NÓ
ORIGINAL DEVE TER ATUALIZADO O CAMPO NEXT PARA REFERENCIAR O NOVO NÓ.

***IMPLEMENTAÇÕES DA LISTA***

    FILAS E PILHAS SÃO ESTRUTURAS USUALMENTE IMPLEMENTADAS ATRAVÉS DE LISTAS, RESTRIGINDO A
POLÍTICA DE MANIPULAÇÃO DOS ELEMENTOS DA LISTA

    **A SEGUIR, TEMOS UMA IMPLEMENTAÇÃO DE UMA PILHA COM ALOCAÇÃO LIGADA EM C++.
    **A PILHA E SUAS RESPECTIVAS FUNÇÕES DE MANIPULAÇÃO SE ENCONTRAM NO ARQUIVO HEADER (pilhaligada.h).
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
