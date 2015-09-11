/*
 * File:   main.cpp
 * Author: Chuck  and Nobusada
 *
 * Created on September 10, 2015, 10:27 AM
 * TODO -1: Motherfucking english
 * TODO 1: BTree de struct para Classe
 * TODO 2.1: BTree - Balancear a inserção e a remoção
 * TODO 2.2: Fazer uma HashTable com tratamento de colisão
 * TODO 3: Colocar BTree e a busca em outro arquivo e importar o header específico
 */

#include "main.h"

using namespace std;

static int tam=10;

// TODO: Não é melhor transformar isso em uma Classe? "C+" vs C++
struct ArvoreB {

    int valor;
    ArvoreB *esquerda;
    ArvoreB *direita;

    ArvoreB(int val) {
        // Constructor.  Make a node containing str.
        valor = val;
        esquerda = NULL;
        direita = NULL;
    }

};

void inserirBtree(ArvoreB *&raiz,int valor){
    // TODO: balancear a inserção na BTree

    if(raiz==NULL){
        raiz = new ArvoreB(valor);
    }
    else if (raiz->valor>valor){
        inserirBtree(raiz->esquerda,valor);
    }
    else if (raiz->valor<valor){
        inserirBtree(raiz->direita,valor);
    }
}

void imprimirBtree(ArvoreB *raiz){
    // TODO: balancear a remoção na BTree

    if(raiz==NULL){
        return;
    }
    if(raiz->esquerda!=NULL){
        imprimirBtree(raiz->esquerda);
    }
    cout<<raiz->valor<<" ";

    if(raiz->direita!=NULL){
        imprimirBtree(raiz->direita);
    }
}

void procurarBtree(ArvoreB *raiz, int chave, int cont){

    cont++;
    if(raiz==NULL){
        cout<<"Valor nao encontrado"<<endl;
        return;
    }
    cout<<"Comparou "<<raiz->valor<<" e a chave "<<chave<<endl;
    if(raiz->valor==chave){
        cout<<"MATCH!"<<endl;
        cout<<"Numero de iteracoes: "<<cont;
        return;
    }
    else if (raiz->valor<chave){
        cout<<"Chave maior"<<endl;
        procurarBtree(raiz->direita,chave,cont);
        return;
    }
    cout<<"Chave menor"<<endl;

    procurarBtree(raiz->esquerda,chave, cont);

}

void buscaBinaria(vector <int> v, int chave, int cont, int inicio, int fim){

    cont++;
    int i = (inicio+fim)/2;

    cout<<"Comparou "<<v[i]<<" e a chave "<<chave<<endl;

    if(v[i]==chave){
        cout<<"Numero de iterações binárias: ";
        cout<<cont<<endl;
    }
    else if (inicio==fim){
        cout<<"Número inexistente."<<endl;
        return;
    }
    else if (v[i]<chave){
        cout<<"Chave maior"<<endl;
        buscaBinaria(v,chave,cont,i++,fim);
    }
    else{
        cout<<"Chave menor"<<endl;
        buscaBinaria(v,chave,cont,inicio,i-1);
    }

}


int main(int argc, char** argv) {

    srand(time(NULL));
    vector <int> v;
    int r, chave, cont,t;
    ArvoreB *raiz;
    raiz = NULL;

    cout<<"Valores inseridos:"<<endl;

    for(int i=0;i<tam;i++){
        r = 1+ rand() % 99;

        cout<<r<<" ";
        v.push_back(r);
        inserirBtree(raiz,r);
    }
    cout<<endl;

    cout<<"Vetor organizado:"<<endl;

    sort(v.begin(), v.end());

    for(int i=0;i<tam;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    cout<<"Btree organizada: ";
    imprimirBtree(raiz);
    cout<<endl;
    cout<<endl;
    cout<<endl;

    cout<<"Digite a chave que procura: ";
    cin>>chave;
    // TODO: Transformar isso em um método no arquivo auxiliar e só chamar a função
    cont=0;
    for(int i=0;i<tam;i++){
        cont++;
        if(chave==v[i]){
            break;
        }
    }
    cout<<endl<<"Número de iteracoes sequenciais: "<<cont<<endl;
    cont=0;


    buscaBinaria(v,chave,0,0,(tam-1)); // TODO: Adicionar o parâmetro verbose

    procurarBtree(raiz,chave,0); // TODO: Adicionar o parâmetro verbose

    system("PAUSE");

    return 0;
}