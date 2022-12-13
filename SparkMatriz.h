#ifndef __SparkMatriz_H__
#define __SparkMatriz_H__
#include "LinkedList.h"
#include <sstream>


class SparkMatriz
{
private:
    int valor;
    int dimension;
    LinkedList *head;
    SparkMatriz *next;
public:
    SparkMatriz(int);
    LinkedList* getLista();
    SparkMatriz* getNext();
    int getValor();
    void setNext(SparkMatriz*);
    string stringEnd();
    ~SparkMatriz();
    void cout();
    void print();
    void add(int);
    void deleteA(int);
};

SparkMatriz::SparkMatriz(int NuevoV)
{
    this->dimension=0;
    this->valor=NuevoV;
    this->head=new LinkedList();
    this->next=nullptr;
}

void SparkMatriz::add(int ValorA){   
    if(this->head->search(ValorA)==true || ValorA==this->getValor()){return;}
    this->head->add(ValorA); this->dimension+=1;  
    return;}

void SparkMatriz::deleteA(int ValorA){
    if(this->head->search(ValorA)==true){
        this->head->deleteA(ValorA); this->dimension-=1; 
    }
    return;}

void SparkMatriz::cout(){std::cout<<"Dimension: "<<this->dimension;}

void SparkMatriz::print(){std::cout<<this->valor<<": ";  this->head->print(); return;}

void SparkMatriz::setNext(SparkMatriz* nuevo){this->next=nuevo;return;}

int SparkMatriz::getValor(){return this->valor;}

string SparkMatriz::stringEnd(){
    if(head==nullptr){return "";}
    string cadenaValores = head->values();
    int i =0;
    string valorString (std::to_string(this->getValor()));
    string salida="";
    while (cadenaValores[i]!='$')
    {
        if(cadenaValores[i]!='-'){
            string valueString(1,cadenaValores[i]);
            stringstream intValue(valueString);
            int intValues = 0;
            intValue >> intValues;
            if ( intValues > this->getValor()) 
            {
                salida+= valorString+" -- "+cadenaValores[i]+";\n";
            } 
        }
        i++;
    }
    return salida;
}

LinkedList* SparkMatriz::getLista(){return this->head;}

SparkMatriz* SparkMatriz::getNext(){return this->next;}

SparkMatriz::~SparkMatriz()
{
}

#endif