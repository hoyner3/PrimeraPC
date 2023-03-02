#include <iostream>

using namespace std;

struct nodo{
    int x;
    nodo* sig;
    nodo(int num){
        x= num;
        sig = NULL;
    }
}*primero;
//inserta al inicio de una lista circular
void insertarInicio(int x){

    nodo* nuevo = new nodo(x);

    if(primero== NULL){
        primero = nuevo;
        nuevo->sig= primero;
    }
    else{

        nuevo->sig = primero;

        nodo* temp = primero;
        while(temp->sig!=primero)//avanza hacia el ultimo de la lista
            temp = temp->sig;

        temp->sig = nuevo;
        primero = nuevo;
    }
}
//inserta al final de una lista circular
void insertarFinal(int x){

    nodo* nuevo = new nodo(x);

    if(primero== NULL){//si la lista esta vacia
        primero = nuevo;//apunta al nuevo nodo
        nuevo->sig= primero;//el nuevo nodo apunta a si mismo 
    }
    else{//si la lista no esta vacia

        nuevo->sig = primero;//el nuevo nodo apunta al primero

        nodo* temp = primero;
        while(temp->sig!=primero)//avanza hacia el ultimo de la lista
            temp = temp->sig;

        temp->sig = nuevo;//el ultimo nodo apunta al nuevo nodo
    //    primero = nuevo;
    }
}
void cargarDatos(){
        insertarInicio(10);
        insertarInicio(8);
        insertarInicio(6);
        insertarFinal(12);
        insertarInicio(4);
        insertarFinal(14);
        insertarInicio(2);
        insertarFinal(16);
}

void imprimir(){
    if(primero == NULL){
        cout<<"\nLista vacia......";
        return;
    }
    nodo*temp = primero;
    do{
        cout<<temp->x<<",  ";
        temp = temp->sig;
    }while(temp != primero);
}

nodo* buscar(int x){
     if(primero == NULL){
        return NULL;
    }
    nodo*temp = primero;
    do{
        if(temp->x  ==  x)
            return temp;

        temp = temp->sig;
    }while(temp != primero);
return NULL;//sino lo encontr�
}
void modificar(int x , int nuevoX){

    nodo* modif= buscar(x);
    if (modif == NULL)
        cout<<"El numero no se encuentra";
    else
        modif->x = nuevoX;
}


int main()
{
    cout << "Lista circular: " << endl;
    cargarDatos();
    imprimir();
    modificar(8, 10);
    modificar(2,10);
    modificar(16, 10);
    cout<<endl;
    imprimir();
    return 0;
}


