#ifndef __LinkedList_H__
#define __LinkedList_H__
#include "Nodo.h"
#include <iostream>
using namespace std;
class LinkedList
{
private:
    Nodo* head;
public:
    LinkedList();
    void add(int);
    void deleteA(int);
    bool search(int);
    void print();
    string values();
    ~LinkedList();
};

LinkedList::LinkedList()
{
    this->head=nullptr;
}

void LinkedList::add(int NuevaNodo){
    if(this->head==nullptr){
        Nodo* nuevo = new Nodo(NuevaNodo);
        this->head=nuevo;
        return;
    }
    Nodo* auxiliar = head;
    while (true)
    {
        if(auxiliar->getNext() == nullptr){
            Nodo* nuevo = new Nodo(NuevaNodo);
            auxiliar->setNext(nuevo);
            return;
        }
        if(auxiliar->getNext()!=nullptr){
            if(auxiliar->getNext()->getDato()==NuevaNodo){return;}
            if(auxiliar->getNext()->getDato()>NuevaNodo){
                Nodo* nuevo = new Nodo(NuevaNodo);
                nuevo->setNext(auxiliar->getNext());
                auxiliar->setNext(nuevo);
                return;
            }
        }
        auxiliar = auxiliar->getNext();
    }
    return;
}

bool LinkedList::search(int BuscarNodo){
    Nodo* auxiliar = head;
    while (auxiliar!=nullptr)
    {
        //std::cout<<auxiliar->getDato();
        if(auxiliar->getDato()==BuscarNodo){
      //      std::cout<<"Existe";
            return true;}
        auxiliar = auxiliar->getNext();
    }
    //std::cout<<"No existe";
    return false;
}

void LinkedList::deleteA(int NodoEliminar){
    if(head==nullptr){ return;}
    if(head->getDato()==NodoEliminar){
        Nodo* auxiliarelim = head;
        head=head->getNext();
        auxiliarelim->eliminar();
        delete[] auxiliarelim;
        return;
    }   
    Nodo* auxiliar = head;
    if (search(NodoEliminar)==true)
{
    while (auxiliar!=nullptr )
    {
        if(auxiliar->getNext()->getDato()==NodoEliminar){
            break;
        }
        if(auxiliar->getNext()==nullptr){return;}
        auxiliar = auxiliar->getNext();
    }

    if(auxiliar->getNext()->getNext()==nullptr){
        Nodo* auxiliarelim = auxiliar->getNext();
        auxiliar->eliminar();
        auxiliarelim->eliminar();
        delete[] auxiliarelim;
        return;
    }
    Nodo* auxiliarelim = auxiliar->getNext();
    auxiliar->setNext(auxiliar->getNext()->getNext());
    auxiliarelim->eliminar();
    delete[] auxiliarelim;
    return;
}
return;
}

void LinkedList::print(){
   // std::cout<<"Aqui en imprimir";
    if (head==nullptr){std::cout<<"No existen Nodos"; return; }
    Nodo* auxiliar = head;    
    while (auxiliar!=nullptr)
    {
        std::cout<<auxiliar->getDato()<<" -> ";
        auxiliar=auxiliar->getNext();
    }
    
}
/*string LinkedList::values(){
    string salida = "";
    if (head==nullptr){std::cout<<"No existen Nodos"; return salida; }
    Nodo* auxiliar = head;    
    while (auxiliar!=nullptr)
    {
        string num_cstr(std::to_string(auxiliar->getDato()));
        salida +=num_cstr+"-";
        auxiliar=auxiliar->getNext();
    }
    salida +="$";
     return salida;
}*/

LinkedList::~LinkedList()
{
}



#endif