#ifndef PILHAALOCASEQ_H_INCLUDED
#define PILHAALOCASEQ_H_INCLUDED

//OBS.:
//O código se encontra todo comentado por se tratar de um material de estudo, pesquisa e revisão.

template <typename Tipo> //onde Tipo é um tipo Generico de dado
class Pilha{
private: //método visível apenas em sua própria classe.
    Tipo *v; //cria um ponteiro de tipo genérico
    unsigned int tamanho;
    int topo;
public: //método visível de qualquer lugar, outras classes e instâncias do objeto.

    //função construtura
    //inicializa a variável do tipo Pilha
    Pilha(unsigned tam) {
        tamanho = tam;

        //new é aplicado ao tipo de objeto de dado a ser criado e retorna um ponteiro para o objeto de dado criado
        v = new Tipo[tamanho]; //cria o objeto

        topo = -1;
    }

    //função destrutura
    //liberação de memória alocada pelo ponteiro v(*v)
    ~Pilha() {
        delete []v; // desaloca o vetor apontado por v
    }

    //função insere
    void empilha(Tipo x) {
        topo++; //incrementa uma posição no topo
        v[topo] = x; //o objeto recebe o valor X na posição topo
    }

    //função remover
    Tipo desempilha() {
        Tipo temp = v[topo];
        topo--; //decrementa uma posição no topo
        return temp;
    }

    //topo
    Tipo elementodotopo() {
        return v[topo]; //retorna o elemento do topo
    }

    //verifica se pilha está cheia
    bool pilhacheia() {
        return topo == tamanho -1;
    }

    //verifica se pilha está vazia
    bool pilhavazia() {
        return topo == -1;
    }

    unsigned getTopo() {
        return topo;
    }

    unsigned getTamanho() {
        return tamanho;
    }

    Tipo getValor(unsigned posicao){
        return v[posicao];
    }
};


#endif // PILHAALOCASEQ_H_INCLUDED
