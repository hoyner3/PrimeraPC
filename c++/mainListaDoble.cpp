#include <iostream>

using namespace std;
struct nodo{

    int num;
    nodo* sig;
    nodo* ant;

    nodo(int x){
        num = x;
        sig = NULL;
        ant = NULL;
    }
}*primero;
//Inserta al inicio de una lista doblemente enlazada
void insertarInicio(int x){
    nodo*nuevo = new nodo(x);
    if(primero == NULL)
        primero = nuevo;
    else{

        nuevo->sig = primero;
        primero->ant = nuevo;
        primero = nuevo;
    }
}
void insertarFinal(int x){
    nodo*nuevo = new nodo(x);
    if(primero == NULL)
        primero = nuevo;
    else{
            nodo*temp = primero;
            while(temp->sig != NULL)
                temp = temp->sig;//avanzar hasta el ultimo nodo

            temp->sig =nuevo;
            nuevo->ant = temp;
    }
}
void imprimir(){

    if(primero== NULL)
        cout<<"No hay lista doble";
    else{
        nodo*temp = primero;
        while(temp != NULL){
            cout<<temp->num<<",  ";
            temp = temp->sig;
        }
    }
}

void imprimir2(){

    if(primero== NULL)
        cout<<"No hay lista doble";
    else{
        nodo*temp = primero;
        while(temp->sig != NULL){
                 temp = temp->sig;
        }//una vez en el ultimo nodo empiezo a devolverme

         while(temp != NULL){
                cout<<temp->num<<",  ";
                 temp = temp->ant;
        }
    }
}
//imprime uno de el inicio y otro del final, asi hasta el final e inicio de la lista
void imprimir3(){
    if(primero== NULL)
        cout<<"No existe lista";
    else{
        nodo*t1 = primero;
        nodo*t2= primero;
        while(t2->sig != NULL){
                 t2 = t2->sig;//avanzar hasta el ultimo
        }
        //ahora imprimir intercalado
        while((t1!= NULL) && (t2!= NULL)){
                cout<<t1->num<<",  "<<t2->num<<",  ";
                t1 = t1->sig;
                t2= t2->ant;
        }
    }
}
void eliminar(int x){
    if(primero == NULL)
        cout<<"No hay lista";
    else{
        if(primero->num ==x){
            primero = primero->sig;
            if(primero!=NULL)
                primero->ant = NULL;
        }
        else{//no es el primero, puede ser en medio o al final
            nodo*temp = primero;
            while(temp!= NULL){
                if(temp->num == x){
                    temp->ant->sig = temp->sig;
                    if(temp->sig != NULL)//que no sea el ultimo
                        temp->sig->ant = temp->ant;
                }
                temp = temp->sig;
            }
        }
    }
}
void cargarDatos(){
        insertarInicio(9);
         insertarFinal(11);
        insertarInicio(7);
        insertarInicio(5);
        insertarInicio(3);
        insertarInicio(1);
        insertarFinal(13);
         insertarFinal(15);
        insertarOrdenado(12);
        insertarOrdenado(6);
        insertarOrdenado(18);
        insertarOrdenado(16);

        imprimir();
        cout<<endl;
        imprimir2();
}
//inserta ordenado ascendente en lista DOBLE
void insertarOrdenado(int x){
    nodo*nuevo = new nodo(x);

    if(primero == NULL)//lista vacia
        primero = nuevo;
    else if(x < primero->num){//insertar al inicio
            nuevo->sig = primero;//nuevo->sig apunta a primero
            primero->ant = nuevo;//primero->ant apunta a nuevo
            primero = nuevo;

    }
    else{
        nodo*temp = primero;
        nodo*t2;
        while(temp != NULL){
            if(x < temp->num ){
                nuevo->sig = temp;
                nuevo->ant = temp->ant;
                temp->ant->sig = nuevo;
                temp->ant = nuevo;
                return;//termine y se salga del ciclo
            }
            t2= temp;
            temp = temp->sig;
        }
        if(temp == NULL){
                t2->sig = nuevo;
                nuevo->ant = t2;
       //     insertarFinal(x);
        }

    }
}

int main()
{
    cout << "Lista Doble" << endl;
    cargarDatos();
     cout << "\n\nLista Doble, impresi�n Intercado" << endl;
    imprimir3();
    eliminar(1);
    eliminar(13);
    eliminar(15);
     cout<<endl;
    imprimir();
    cout<<endl;
    imprimir2();

    cout<<"\n\nLista ordenada"<<endl;
    imprimir();
    return 0;
}









