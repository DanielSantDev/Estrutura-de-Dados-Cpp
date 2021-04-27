#include <iostream>
#include "filaligada.h"

/*
Pesquisa e C�digos feitos por Daniel Santana.

GitHub: github.com/DanielSantDev
E-mail: daniel10gja@gmail.com
Linkedin: linkedin.com/in/ddanielssantana/
Instagram: instagram.com/daniel_san.t/

*/

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

    **A SEGUIR, TEMOS UMA IMPLEMENTA��O DE UMA FILA COM ALOCA��O LIGADA EM C++.
    **A FILA E SUAS RESPECTIVAS FUN��ES DE MANIPULA��O SE ENCONTRAM NO ARQUIVO HEADER (filaligada.h).

    Bibliografia
    *Estruturas De Dados E Seus Algoritmos
    SZWARCFITER, Jayme Luiz; Markenzon, Lilian
    Editora LCT*

*/

using namespace std;

int main() {

    cout << "FILA COM ALOCACAO LIGADA\n" << endl;
    Fila<int> f;
    int opc, valor;

    do{
        cout<<"\n1 - INSERIR."<<endl;
        cout<<"2 - REMOVER."<<endl;
        cout<<"3 - EXIBIR PRIMEIRO DA FILA."<<endl;
        cout<<"4 - EXIBIR FILA."<<endl;
        cout<<"5 - SAIR."<<endl;
        cout<<"SELECIONE -> ";
        cin>>opc;

        switch(opc) {

        case 1:
            cout<<"DIGITE O VALOR: ";
            cin>>valor;
            if(f.insere(valor)) {
                cout<<"NUMERO INSERIDO COM SUCESSO!"<<endl;
            }
            else {
                cout<<"A FILA EST� CHEIA."<<endl;
            }
            break;

        case 2:
            if(f.filavazia()) {
                cout<<"FILA VAZIA."<<endl;
            }
            else {
                cout<<"NUMERO: " <<f.remover()<<", REMOVIDO COM SUCESSO!"<<endl;

            }
            break;

        case 3:
            if(f.filavazia()) {
                cout<<"FILA VAZIA."<<endl;
            }
            else {
                cout<<"PRIMEIRO ELEMNETO: "<<f.primeiro()<<endl;

            }
            break;

        case 4:
            if(f.filavazia()) {
                cout<<"FILA VAZIA."<<endl;
            }
            else {
                cout<<"ELEMENTOS DA FILA: ";
                Node<int> *aux = f.getInic();
                while(aux != NULL){
                    cout<<aux->info<<" | ";
                    aux=aux->prox;
                }
                cout<<endl;
            }
            break;
        }

    } while( opc != 5 );

    return 0;
}
