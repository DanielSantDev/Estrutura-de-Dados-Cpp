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

    Tipo valorMaximo(Node<Tipo> *t) {
        if(t == NULL) {
            return NULL;
        }else {
            if(t->pDir == NULL) {
                return t->info;
                }else {
                    return t->pDir = valorMinimo(t->pDir);
                }
        }
    }

    Tipo valorMinimo(Node<Tipo> *t) {
        if(t == NULL) {
            return NULL;
        }else {
            if(t->pEsq == NULL) {
                return t->info;
                }else {
                    return t->pEsq = valorMinimo(t->pEsq);
                }
            }
        }

    /*void Remover(Num, Node<Tipo> *t) {
        if( t == null){
            return NULL;
        }

    }*/


};


#endif // ARVORE_H_INCLUDED
