#ifndef LISTAORDENADA_H_INCLUDED
#define LItSTAORDENADA_H_INCLUDED

template <typename Tipo>
struct Node {
    Tipo info;
    Node<Tipo> *prox;
};

template <typename Tipo>
struct ListaOrdenada {

    Node<Tipo> *h;

    ListaOrdenada() {
        h=NULL;
    }

    bool ListaVazia() {
        return h==NULL;
    }

    void Insere(Tipo x) {
        Node<Tipo> *aux2;
        Node<Tipo> *aux=new Node<Tipo>;
        aux->info=x;
        if(h==NULL || x < h->info) {
            aux->prox=h;
            h = aux;
        }
        else {
            aux2=h;
            while(aux2->prox!=NULL && x > aux2->prox->info) {
                    aux2=aux2->prox;
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

    Tipo BuscarElemento(Tipo num) {
        for(h; h!=NULL; h=h->prox) {
            if(h->info == num) {
                return h->info;
            }else {
                return NULL; // caso ñ haja elementos
            }
        }
    }

};


#endif // LISTAORDENADA_H_INCLUDED
