#ifndef PILHALIGADA_H_INCLUDED
#define PILHALIGADA_H_INCLUDED

template <typename Tipo>
struct Node {
    Tipo info;
    Node<Tipo> *prox;
};

template <typename Tipo>
class Pilha {
private:
    Node<Tipo> *topo;//Declara a struct Node

public:

    Pilha() {
       topo = NULL;
    }

    //Inserção de um elemento no topo
    bool empilha(Tipo x) {
       bool v = true;
       Node<Tipo> *aux=new Node<Tipo>;
       if(aux == NULL) {
        v = false;
       }
       else {
            aux->info = x;
            aux->prox = topo;
            topo = aux;
       }
       return v;
    }

    //Remoção do elemento do Topo
    Tipo desempilha() {
        Tipo temp = topo->info;
        Node<Tipo> *aux = topo;
        topo = topo->prox;
        delete aux;
        return temp;
    }

    Tipo elementodotopo() {
        return topo->info;
    }

    /*O nó descritor está inicialmente vazio, seu campo next tem o valor nulo.
    Assim, um procedimento para verificar se a lista está vazia deve verificar o valor desse campo*/
    bool pilhavazia() {
        return topo == NULL;
    }

    Node<Tipo> *getTopo() {
        return topo;
    }

};

#endif // PILHALIGADA_H_INCLUDED
