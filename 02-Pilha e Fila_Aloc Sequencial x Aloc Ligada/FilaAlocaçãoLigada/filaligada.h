#ifndef FILALIGADA_H_INCLUDED
#define FILALIGADA_H_INCLUDED

template <typename Tipo>
struct Node {
    Tipo info;
    Node<Tipo> * prox;
};

template <typename Tipo>
class Fila {
private:
    Node<Tipo> *inic;
    Node<Tipo> *fim;
public:

    Fila() {
        inic=NULL;
        fim =NULL;
    }

    bool insere(Tipo x) {
        bool v = true;
        Node<Tipo> * aux=new Node<Tipo>;
        if (aux == NULL) {
            v = false;
        }
        else {
            aux->info = x;
            aux->prox = NULL;
            if (inic == NULL){
                inic = aux;
            }
            else {
                fim->prox=aux;
            }
        fim=aux;
        }
        return v;
    }

    Tipo remover() {
        Tipo temp=inic->info;
        Node<Tipo> *aux=inic;
        inic = inic->prox;
        if(inic == NULL){
            fim=NULL;
        }
        delete aux;
        return temp;
    }

    bool filavazia() {
        return inic==NULL;
    }

    Tipo primeiro() {
        return inic->info;
    }

    Node<Tipo> *getInic() {
        return inic;
    }

};
#endif // FILALIGADA_H_INCLUDED
