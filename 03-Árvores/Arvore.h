#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

#include <iostream>
using namespace std;
template <typename Tipo>

struct Node {
    Tipo info;
    Node<Tipo> *pEsq;
    Node<Tipo> *pDir;
};



template <typename Tipo>
struct Bst {

    Node<Tipo> *pRaiz;

    Bst() {
        pRaiz=NULL;
    }

    void insere(Node<Tipo> *&t,Tipo x) {
        if(t==NULL) {
            t=new Node<Tipo>;
            t->info=x;
            t->pEsq=NULL;
            t->pDir=NULL;
        }
        else{
            if(x < t->info) {
                insere(t->pEsq,x);
            }
            else{
                insere(t->pDir,x);
            }
        }
    }

    void preOrdem(Node<Tipo> *t) {
            if(t!=NULL){
                cout<<t->info<<" ";
                preOrdem(t->pEsq);
                preOrdem(t->pDir);
            }
    }

    void posOrdem(Node<Tipo> *t) {
            if(t!=NULL){
                posOrdem(t->pEsq);
                posOrdem(t->pDir);
                cout<<t->info<<" ";
            }
    }

    void emOrdem(Node<Tipo> *t) {
            if(t!=NULL) {
                emOrdem(t->pEsq);
                cout<<t->info<<" ";
                emOrdem(t->pDir);
            }
    }

    int Remover(Node<Tipo>*&t, int valor) {
        Node<Tipo>*temp = NULL;
        if(t == NULL) {
            return 0;
        }
        if(valor == t->info) {
            temp = t;
            if(pRaiz->pEsq == NULL)
                t = t->pDir;
            else if(t->pDir == NULL)
                t = t->pEsq;
            else
            {
                t = temp;
            }
            delete temp;
            return 1;
        }
        else if(valor < t->info) {
            return Remover(t->pEsq, valor);
        }
        else {
            return Remover(t->pDir, valor);
        }
    }

    int valorMaximo(Node<Tipo> *t) {
        if(t!=NULL) {
            Node<Tipo> *aux;
            aux=t;
            while(aux->pDir!=NULL) {
                aux = aux->pDir;
            }
            return aux->info;
        }
        return 0;
    }


    int valorMinimo(Node<Tipo> *t) {
        if(t!=NULL) {
            Node<Tipo> *aux;
            aux=t;
            while(aux->pEsq!=NULL) {
                aux = aux->pEsq;
            }
            return aux->info;
        }
        return 0;
    }

    /*int Remover(Node<Tipo> *t,Tipo x) {
        Node<Tipo> *aux;
        aux=t;
        if(t!=NULL) {
                if(x < aux->info) {
                    aux->pEsq = Remover(aux->pEsq, x);
                } else
                if(x > aux->info) {
                    aux->pDir = Remover(aux->pDir, x);
                } else
                if(aux->pEsq == NULL) {
                    return aux->pDir;
                } else
                if(aux->pDir == NULL) {
                    return aux->pEsq;
                } else {
                return aux;
                }
        }
    }*/

};


#endif // ARVORE_H_INCLUDED
