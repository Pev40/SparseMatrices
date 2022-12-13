#ifndef __NODO_H__
#define __NODO_H__

class Nodo
{
private:
    int Dato;
    Nodo* next=nullptr;
public:
    Nodo(int);
    ~Nodo();
    int getDato();
    void setDato(int);
    void eliminar();
    Nodo* getNext();
    void setNext(Nodo*);
};

Nodo::Nodo(int DatoNuevo)
{
    this->Dato=DatoNuevo;
}
void Nodo::setDato(int DatoNuevo){this->Dato=DatoNuevo;  return;}

void Nodo::setNext(Nodo* NuevoNodo){this->next=NuevoNodo;  return;}

int Nodo::getDato(){return this->Dato;}

void Nodo::eliminar(){this->next=nullptr;return;}

Nodo* Nodo::getNext(){return this->next;}

Nodo::~Nodo()
{}

#endif