#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

#define W 4

struct Node{
    int info;
    Node *prox;
};

struct Hash {
    Node *h[W];

    Hash(){
        for (int i=0;i < W; i++){
            h[i] = NULL;
        }
    }

    //fun��o de espalhamento
    int fht(int x) {
        return x % W; //chave % tamanho
    }

    bool ListaVazia(int lista) {
        return h[lista]==NULL;
    }

    void Insere(int x) {
        Node *aux2;
        Node *aux = new Node;
        aux->info = x;
        int p = fht(x);
        if (h[p] == NULL || x <= h[p]->info) {
            aux->prox = h[p];
            h[p] = aux;
        }
        else {
            aux2 = h[p];
            while(aux2->prox != NULL && x > aux2->prox->info) {
                aux2 = aux2->prox;
            }
            aux->prox = aux2->prox;
            aux2->prox = aux;
        }
    }

    int BuscarElemento(int x) {
        Node *aux;

        for(int i=0; i<W; i++) {
            aux = h[i];
            while(aux != NULL){
                if(x == aux->info) {
                    return i;
                }
                aux = aux->prox;
            }
        }
        return -1;
    }

    bool Remover(int x) {
        for(int i=0; i<W; i++) {
            //Se Lista � vazia ou se N�mero a ser removido � menor ao Elemento que est� na Cabe�a da Lista
            if (h[i] == NULL || x < h[i]->info) {
                continue;
            }
            else{
                //Se N�mero a ser removido � igual ao elemento da Cabe�a da Lista
                if(x == h[i]->info) {
                    Node *aux = h[i];
                    h[i] = h[i]->prox; //O pr�ximo Valor se torna a Cabe�a da Lista
                    delete aux;
                    return true;
                }

                Node *aux = h[i];

                while (aux->prox != NULL && x > aux->prox->info) {
                    aux = aux->prox;
                }

                if (aux->prox == NULL || aux->prox->info != x) {
                    continue;
                }
                else{
                    Node *aux2 = aux->prox;
                    aux->prox = aux->prox->prox;
                    delete aux2;
                    return true;
                }
            }
        }
        return false;
    }

};

#endif // HASHTABLE_H_INCLUDED
