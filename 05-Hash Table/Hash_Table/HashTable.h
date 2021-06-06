#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

#define W 5

template <typename Tipo>
struct Node {
    Tipo info;
    Node<Tipo> *prox;
};

template <typename Tipo>
struct Hash {
    Node<Tipo> *h[W];

    Hash(){
        for( i=0;i<W;i++) {
            h[i] = NULL;
        }
    }

    int fht(int x) {
        return x % W;
    }

    bool ListaVazia(int lista) {
        return h[lista]==NULL;
    }

    void Insere(Tipo x) {
        Node<Tipo> *aux2;
        Node<Tipo> *aux = new Node<Tipo>;
        aux->info = x;
        int p = fht(x);
        if (h[p] == NULL || x<=h[p]->info) {
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

    Tipo Remover() {
        Tipo temp=h->info;
        Node<Tipo> *aux=h;
        h = h->prox;
        delete aux;
        return temp;
    }



};

#endif // HASHTABLE_H_INCLUDED
