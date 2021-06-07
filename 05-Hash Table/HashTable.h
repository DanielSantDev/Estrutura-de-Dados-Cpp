#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

#define W 5

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

    int fht(int x) {
        return x % W;
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

    int BuscarElemento(int num) {
        Node *aux;
        for(h ; h!=NULL ; h = aux->prox) {
            if(aux->info == num) {
                return aux->info;
            }else {
                return NULL; // caso ñ haja elementos
            }
        }
    }

    /*void Remover(int x) {
        int temp = h->info;
        int *aux=h;
        h = h->prox;
        delete aux;
        return temp;
    }*/

};

#endif // HASHTABLE_H_INCLUDED
