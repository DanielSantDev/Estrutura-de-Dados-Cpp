#ifndef FILAALOCAOSEQUENCIAL_H_INCLUDED
#define FILAALOCAOSEQUENCIAL_H_INCLUDED

template <typename Tipo>
class Fila {
private:
    int fim, inic;
    unsigned qtde; //quantidade de elementos da fila
    unsigned tamanho; //tamanho da fila

    //ponteiro para um array/vetor
    Tipo *v;

public:

    Fila(unsigned tam) {
        fim=-1;
        inic=0;
        qtde=0;
        tamanho = tam;
        v = new Tipo[tamanho];
    }

    ~Fila() {
        delete []v;
    }

    void insere(Tipo x) {
        fim++; //incrementa a posição fim
        if(fim==tamanho) {
            fim=0;
        }
        v[fim]=x;
        qtde++;
    }

    //O primeiro elemento a ser removido está no início da fila
    Tipo remover() {
        Tipo temp = v[inic];
        inic++; /*inicio incrementa, pois um elemento foi removido
                  *aumentando a posição do inicio da fila.*/
        if(inic==tamanho) {
            inic=0;
        }
        qtde--;
        return temp;
    }

    Tipo primeiro() {
        return v[inic];
    }

    bool filacheia() {
        return qtde==tamanho;
    }

    bool filavazia() {
        return qtde==0;
    }

    int getFim() {
        return fim;
    }

    int getInic() {
        return inic;
    }

    unsigned getQtde() {
        return qtde;
    }

    Tipo getValor(unsigned posicao) {
        return v[posicao];
    }

    unsigned getTamanho() {
        return tamanho;
    }

};



#endif // FILAALOCAOSEQUENCIAL_H_INCLUDED
