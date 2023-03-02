// Hecho por: Hoyner Alexander Zamora Calderon


#include <iostream>
#include <vector>

using namespace std;
// Contructor de la lista circular
struct listaC{
    int numero;
    listaC *sig;
    listaC (int num){
        numero = num;
        sig = NULL;
    }
}*primeroC;// este es el puntero que apunta al primer nodo de la lista

// Contructor de la lista doble
struct listaD{
    int edad;
    int cedula;
    string nombre;
    listaD *sig;
    listaD *ant;
    listaD (string n, int e, int c){
        edad = e;
        cedula = c;
        nombre = n;
        sig = NULL;
        ant = NULL;
    }
}*primeroD;// este es el puntero que apunta al primer nodo de la lista

struct listaPersonal{
    int edad;
    int cedula;
    string nombre;
    listaPersonal *sig;
    listaPersonal(string n, int e, int c){
        edad = e;
        cedula = c;
        nombre = n;
        sig = NULL; 
    }


}*primeroP;// este es el puntero que apunta al primer nodo de la lista

//Funcion para recorrer la lista doble en busca de cedulas repetidas 
bool buscarCedula(int c){
    if (primeroD == NULL){
        return false;
    }
    listaD *temp = primeroD;
    while(temp != NULL){
        if(temp -> cedula == c){
            return true;
        }
        temp = temp -> sig;
    }
    return false;
}

// Funcion para inserción al final de la lista doble .....3
void insertarFinalD(string n, int e, int c){

    if (buscarCedula(c) == true){
        cout<<endl;
        cout<<"La cedula ya existe"<<endl;
        return;
    }
    listaD *nuevo = new listaD(n,e,c);//crea un nuevo nodo con los datos que se le pasa por parametro
    if (primeroD == NULL){
        primeroD = nuevo;//apunta al nuevo nodo
        return; //termina la funcion
    }else{
        listaD *temp = primeroD;
        while(temp -> sig != NULL){
            temp = temp -> sig;
        }
        temp -> sig = nuevo;
        nuevo -> ant = temp;
    }

}
// Funcion para inserción al final de la lista personal 
void insertarFinalP(string n, int e, int c){
    listaPersonal *nuevo = new listaPersonal(n,e,c);//crea un nuevo nodo con los datos que se le pasa por parametro
    if (primeroP == NULL){
        primeroP = nuevo;//apunta al nuevo nodo
        return; //termina la funcion
    }else{
        listaPersonal *temp = primeroP;
        while(temp -> sig != NULL){
            temp = temp -> sig;
        }
        temp -> sig = nuevo;
    }


}
// Funcion para inserción ordenada para la lista circular....4
void insertarOrdenadoC(int num){
    listaC *nuevo = new listaC(num);//crea un nuevo nodo con el numero que se le pasa por parametro
    if (primeroC == NULL){
        primeroC = nuevo;//apunta al nuevo nodo
        nuevo -> sig = primeroC;//el nuevo nodo apunta a si mismo
        return; //termina la funcion
    }else if(num < primeroC -> numero){//si el numero es menor al primero
        
        nuevo->sig = primeroC;//el nuevo nodo apunta al primero

        listaC* temp = primeroC;//crea un nodo temporal
        while(temp->sig!=primeroC)//avanza hacia el ultimo de la lista
            temp = temp->sig;//avanza hacia el ultimo de la lista

        temp->sig = nuevo;//el ultimo nodo apunta al nuevo nodo
        primeroC = nuevo;//el primero apunta al nuevo nodo

       
    }else{

        listaC *temp = primeroC;
        while(temp -> sig != primeroC && temp -> sig -> numero < num){
            temp = temp -> sig;
        }
        nuevo -> sig = temp -> sig;
        temp -> sig = nuevo;
        
    }
}
// Funcion cargar datos quemados, inserte 10 datos en la lista circular.... 1
void cargarDatosC(){

    insertarOrdenadoC(20);
    insertarOrdenadoC(18);
    insertarOrdenadoC(10);
    insertarOrdenadoC(8);
    insertarOrdenadoC(6);
    insertarOrdenadoC(12);
    insertarOrdenadoC(4);
    insertarOrdenadoC(2);
    insertarOrdenadoC(14);
    insertarOrdenadoC(16);
    
}
// Funcion cargar datos quemados, inserte 8 datos en la lista doble ...1
void cargarDatosD(){
    insertarFinalD("Juan", 4, 123456);
    insertarFinalD("Pedro", 18, 123457);
    insertarFinalD("Maria", 10, 123458);
    insertarFinalD("Jose", 8, 123459);
    insertarFinalD("Luis", 6, 123460);
    insertarFinalD("Ana", 12, 123461);
    insertarFinalD("Luisa", 4, 123462);
    insertarFinalD("Carlos", 4, 123463);
    insertarFinalD("Luis", 14, 123463);//cedula repetida no se inserta
}

//Funcion para imprimir la lista circular .....7
void imprimirListaC(){
    if (primeroC == NULL){
        cout << "La lista esta vacia" << endl;
        return;
    }
    listaC *temp = primeroC;
    do{
        cout << temp -> numero << ",";
        temp = temp -> sig;

    } while(temp != primeroC);
    cout << endl;
}


//Funcion para imprimir la lista doble ......7
void imprimirListaD(){
    if (primeroD == NULL){
        cout << "La lista esta vacia" << endl;
        return;
    }
    listaD *temp = primeroD;
    cout << "------------------"<<endl;
    do{
        cout << temp -> nombre <<endl;
        cout << temp -> edad <<endl;
        cout << temp -> cedula <<endl;
        cout << "------------------" <<endl;
        temp = temp -> sig;//avanza al siguiente nodo

    } while(temp != NULL);
    cout << endl;
    
}
//Funcion para imprimir lista que tienen la misma edad .....8
void imprimirListaEdad(){
    if (primeroD == NULL){
        cout << "La lista esta vacia" << endl;
        return;
    }
    listaD *temp = primeroD;
    listaD *temp2 = primeroD;
    temp2 = temp2 -> sig;//avanza al siguiente nodo

    int cont = 0;
    
    do{

        while (temp2 != NULL)
        {
            
            if(temp -> edad == temp2 -> edad){
                cont++;
                
            }
            if (cont == 1){
                cout << "------------------"<<endl;
                cout << "Nombre: "<<temp -> nombre <<endl;
                cout << "Edad: "<<temp -> edad <<endl;
                
                cout << "------------------" <<endl;
                cout << "Nombre: "<<temp2 -> nombre <<endl;
                cout << "Edad: "<<temp2 -> edad <<endl;
                cout << "------------------" <<endl;
                
            }
            else if (cont > 1){
                cout <<"Nombre: "<< temp2 -> nombre <<endl;
                cout <<"Edad: "<< temp2 -> edad <<endl;
                
                cout << "------------------" <<endl;
            }
            temp2 = temp2 -> sig;
            
        }
        cont = 0;
        
        
        
        temp = temp -> sig;

    }while(temp != NULL);   
    cout << endl;
}
//Funcion para imprimir los numeros de la lista circular que no aparece en la lista dobles .....9
void imprimirListaFaltante(vector<int>& numeros){//vector de numeros que no aparecen en la lista doble
int n;
    if (primeroC == NULL){
        cout << "La lista esta vacia" << endl;
        return;
    }
    
    listaC *temp = primeroC;
    listaD *temp2 = primeroD;
    
    int cont = 0;
    
    do{
        do{

            if(temp -> numero == temp2 -> edad){
                cont = 1;
                
            }
            if (cont == 1){//si el numero aparece en la lista doble

                break;//termina el ciclo
            }
            temp2 = temp2 -> sig;
        }while (temp2 != NULL);
        temp2 = primeroD;
        if(cont == 0){
            cout << "Este numero de edad que no aparece en la lista doble" <<endl;
            cout << temp -> numero <<endl;
            n = temp -> numero;
            numeros.push_back(n);
            
        }
        cont = 0;
        temp = temp -> sig;
    }while (temp != primeroC);
    //retornar lista de numeros que no aparecen en la lista doble
}
//Funcion para insertar datos personales en la lista doble ....10
void insertarDatosPersonales()
{
    int contador = 0;
    cout << "Ingrese la cantidad de personas que desea ingresar: ";
    cin >> contador;
    for (int i = 0; i < contador; i++)
    {
        string nombre;
        int edad;
        int cedula;
        
        cout << "Ingrese el nombre: ";
        cin >> nombre;
        cout << "Ingrese la edad: ";
        cin >> edad;
        cout << "Ingrese la cedula: ";
        cin >> cedula;
        insertarFinalP(nombre, edad, cedula);
    }

}

//Funcion 6 .......11
void combinacion(const vector<int>& numeros){
    listaPersonal *temp = primeroP;
    for (int i = 0; i < numeros.size(); i++)
    {
        while(temp != NULL){

            if(numeros[i] == temp -> edad){
                int e = temp -> edad;
                string n = temp -> nombre;
                int c = temp -> cedula;
                insertarFinalD(n,e,c);


            }
            temp = temp -> sig;

        }
        temp = primeroP;
    }

}
//Funcion main.
int main(){
    vector<int> numeros;
   
    bool bandera = true;
    int opcion;
    while (bandera == true)
    {
        cout<<endl;
        cout << "Menu de tarea 4....." << endl;
        cout << "1. Realice un metodo para cargar datos quemados, inserte 10 datos en la lista circular y 8 en la lista doble."<<endl;
        cout << "2. Imprimir la listas."<<endl;
        cout << "3. Imprimir lista que tienen la misma edad."<<endl;
        cout << "4. Imprimir los numeros de la lista circular que no aparece en la lista dobles."<<endl;
        cout << "5. Insertar datos personales en la lista doble."<<endl;
        cout << "6. Solicitar datos de persona del metodo 10 y buscar cada nuemro de edad faltante de la lista circular del metodo 9 y luego insertelos en la lista doble del metodo 5."<<endl;
        cout << "7. Salir."<<endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            cout << "1. Realice un metodo para cargar datos quemados, inserte 10 datos en la lista circular y 8 en la lista doble."<<endl;
            cout << "Cargando datos en la lista circular..."<<endl;
            cargarDatosC();

            cout << "Cargando datos en la lista doble..."<<endl;
            cargarDatosD();

            break;
        case 2:
            cout<<endl;
            cout << "Sub menu para imprimir listas."<<endl;
            int opcion2;
            cout << "1. Imprimir lista circular."<<endl;
            cout << "2. Imprimir lista doble."<<endl;
            cout << "Ingrese una opcion: ";
            cin >> opcion2;
            if (opcion2 == 1){
                cout << "Lista circular: "<<endl;
                imprimirListaC();
            }else if (opcion2 == 2){
            
                cout << "Lista doble: "<<endl;
                imprimirListaD();
            }
            
            break;
        case 3:
            cout << "3. Imprimir lista que tienen la misma edad."<<endl;
            imprimirListaEdad();

            break;
        case 4:
            cout << "4. Imprimir los numeros de la lista circular que no aparece en la lista dobles."<<endl;
            cout << "Lista de numeros faltantes: "<<endl;
            imprimirListaFaltante(numeros);
            break;
        case 5:
            cout << "5. Insertar datos personales en la lista doble."<<endl;
            insertarDatosPersonales();
            break;
        case 6:    
            cout << "6. Solicitar datos de persona del metodo 10 y buscar cada nuemro de edad faltante de la lista circular del metodo 9 y luego insertelos en la lista doble del metodo 5."<<endl;
            combinacion(numeros);
            
            break;
        case 7:
            cout << "7. Salir."<<endl;
            bandera = false;
            break;
        default:
            cout << "Opcion no valida."<<endl;
            break;
                
        }
    }
    return 0; 
}