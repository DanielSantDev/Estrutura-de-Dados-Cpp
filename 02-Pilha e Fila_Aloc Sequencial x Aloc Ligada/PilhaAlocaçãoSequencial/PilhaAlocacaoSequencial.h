#ifndef PILHAALOCASEQ_H_INCLUDED
#define PILHAALOCASEQ_H_INCLUDED

//OBS.:
//O c�digo se encontra todo comentado por se tratar de um material de estudo, pesquisa e revis�o.

template <typename Tipo> //onde Tipo � um tipo Generico de dado
class Pilha{
private: //m�todo vis�vel apenas em sua pr�pria classe.
    Tipo *v; //cria um ponteiro de tipo gen�rico
    unsigned int tamanho;
    int topo;
public: //m�todo vis�vel de qualquer lugar, outras classes e inst�ncias do objeto.

    //fun��o construtura
    //inicializa a vari�vel do tipo Pilha
    Pilha(unsigned tam) {
        tamanho = tam;

        //new � aplicado ao tipo de objeto de dado a ser criado e retorna um ponteiro para o objeto de dado criado
        v = new Tipo[tamanho]; //cria o objeto

        topo = -1;
    }

    //fun��o destrutura
    //libera��o de mem�ria alocada pelo ponteiro v(*v)
    ~Pilha() {
        delete []v; // desaloca o vetor apontado por v
    }

    //fun��o insere
    void empilha(Tipo x) {
        topo++; //incrementa uma posi��o no topo
        v[topo] = x; //o objeto recebe o valor X na posi��o topo
    }

    //fun��o remover
    Tipo desempilha() {
        Tipo temp = v[topo];
        topo--; //decrementa uma posi��o no topo
        return temp;
    }

    //topo
    Tipo elementodotopo() {
        return v[topo]; //retorna o elemento do topo
    }

    //verifica se pilha est� cheia
    bool pilhacheia() {
        return topo == tamanho -1;
    }

    //verifica se pilha est� vazia
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
