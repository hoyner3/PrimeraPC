// Tarea 1.
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<string>
#include <ctime>
using namespace std;
//Funcion para el ejercicio numero random
void ejercicio1()
{
    
    cout<<"######## Ejercicio de numero random ########"<<endl;
    int numRandom = 0;
    srand(time(NULL));//genera un numero random  cada vez que se ejecuta el programa.
    numRandom = 1 + rand() % 100;//genera un numero random entre 1 y 100
    int numUsuario = 0;
    int cantidad = 0;
    //cout<<"El numero random es: "<<numRandom << endl;
    cout<<"Digite un numero: "<< endl;
    cin>>numUsuario;
    
    while(numUsuario != numRandom)
    {
        if (numUsuario == numRandom)
        {
            cout<<"El numero es correcto"<< endl;
        }
        else if (numUsuario > numRandom)
        {
            cout<<"El numero es menor"<< endl;
            cout<<"Digite otro numero: "<< endl;
            cin>>numUsuario;
            cantidad++;
        }
        else if (numUsuario < numRandom)
        {
            cout<<"El numero es mayor"<<  endl;
            cout<<"Digite otro numero: "<< endl;
            cin>>numUsuario;
            cantidad++;
        }
    }
    cout<<"El numero de intentos es: "<< cantidad << endl;
    return;
}
//Funcion para el ejercicio del dado
void ejercicio2()
{
    cout<<"######## Ejercicio del dado ########"<<endl;
    int op = 0;
    cout<<"Lanzar dado \n1.si \n2.no"<<endl;
    cin>>op;
    if (op == 1)
    {
        int dado = 0;
        srand(time(NULL));
        dado = 1 + rand() % 6 ;
        cout<<"El numero que salio al lanzar el dado fue: "<< dado <<endl;
        
        
        for (int i = 0; i < 2; i++)
        {
            int opcion = 0;
            cout<<"Lanzar dado \n1.si \n2.no"<<endl;
            cin>>opcion;
            if (opcion == 1)
            {
                int dado2 = 0;
                srand(time(NULL));
                dado2 = 1 + rand() % 6;
                cout<<"El numero que salio al lanzar el dado fue: "<< dado2 <<endl;
                if (dado2 > dado)
                {
                    cout<<"se supero el numero del dado anterior"<<endl;
                }
                else if (dado2 < dado)
                {
                    cout<<"No se supero el numero del dado anterior"<<endl;
                }
                else if (dado2 == dado)
                {
                    cout<<"El numero del dado anterior es igual al numero del dado actual"<<endl;
                }
            }
            else
            {
                cout<<"No se lanzo el dado"<<endl;
                i--;
            }
            
            
        }
        
    }
    else
    {
        cout<<"No se lanzo el dado"<<endl;
    }
    return; 
}
//Funcion para el ejercicio de la informacion personal del profesor
void ejercicio3()
{
    cout<<"######## Ejercicio de la informacion personal del profesor ########"<<endl;
    string nombre = "";
    string direccion= "";
    string correo= "";
    string añosLaborar= "";
    string objetivoVida= "";
    string salario= "";
    cout<<"Ingrese la informacion personal del profesor: "<<endl;
    cin.ignore();
    cout<<"Nombre completo: "<<endl;
    getline(cin,nombre);
    
    cout<<"Direccion exacta: "<<endl;
    getline(cin,direccion);
   
    cout<<"Correo electronico: "<<endl;
    getline(cin,correo);
    
    cout<<"Anos laborando: "<<endl;
    getline(cin,añosLaborar);
    
    cout<<"Objetivo de vida: "<<endl;
    getline(cin,objetivoVida);
   
    cout<<"Salario base: "<<endl;
    getline(cin,salario);
    
    cout<<"Informacion personal del profesor: "<<endl;
    cout<<"Nombre completo: "<<nombre<<endl;
    cout<<"Direccion exacta: "<<direccion<<endl;
    cout<<"Correo electronico: "<<correo<<endl;
    cout<<"Anos laborando: "<<añosLaborar<<endl;
    cout<<"Objetivo de vida: "<<objetivoVida<<endl;
    cout<<"Salario base: "<<salario<<endl;
    return;
}
//Funcion para el ejercicio de figura
void ejercicio4()
{
    cout<<"######## Ejercicio de la figura ########"<<endl;
    int cantCaracter = 10;
    int espa = 4;
    for (int fila=0; fila<10; fila++)
    {

        for (int espacios=0; espacios<=espa; espacios++)
        {
            cout<<" ";
        }
        cout<<"+";
        cout<<endl;
        for (int cantidad=0; cantidad<=cantCaracter; cantidad++)
        {
            cout<<"+";
        }
        
        cout << endl;
        
    }

    cout<<""<<endl;
}
//Funcion para el ejercicio de la frase
void ejercicio5(string phrase, char c) 
{
  int count = 0;
  for (int i = 0; i < phrase.length(); i++) {
    if (phrase[i] == c) {
      count++;
    }
  }
  cout << "El caracter '" << c << "' se repite " << count << " veces en la frase." << endl;
}
//Funcion para el ejercicio de la hora
void ejercicio6()
{
    cout<<"######## Ejercicio de la hora ########"<<endl;
    time_t now = time(nullptr); // get current time
    tm* timeinfo = localtime(&now); // convert to local time

    int hour = timeinfo->tm_hour;
    int min = timeinfo->tm_min;
    //int sec = timeinfo->tm_sec;   

    string am_pm = "";
    // set AM/PM
    if (hour >= 12)
    {
        am_pm = "pm";
    }
    else
    {
        am_pm = "am";
    }

    // convert to 12-hour clock
    if (hour % 12 == 0)
    {
        hour = 12;
    }
    else
    {
        hour = hour % 12;
    }

    cout << "Hora actual es " << hour << ":"<< min << " "<< am_pm << endl;
    int hour24 = timeinfo->tm_hour;
    if (hour24 == 15)
    {
        cout<<"Son las 3 de la tarde"<<endl;

    }
    else if(hour24 > 15)
    {
        int hora12pm = 24 - hour24;
        int horarestante = hora12pm + 15;
        int minrestante = 60 - min;
        cout<<"Son las "<< hour <<":"<< min << " "<< am_pm <<" faltan "<<horarestante<<":"<<minrestante<<" para las 3:00 pm"<<endl;
        

    }

    cout<<""<<endl;
    return;
}
// este es el main de la tarea 1
int main()
{
    
    bool bandera = true;
    while (bandera==true)
    {
        int opcion;
        cout<<"######## Menu de ejercicios ########"<<endl;
        cout<<"Digite 1 = Ejercicio numero random"<<endl;
        cout<<"Digite 2 = Ejercicio del dado"<<endl;
        cout<<"Digite 3 = Ejercicio de la informacion personal del profesor"<<endl;
        cout<<"Digite 4 = Ejercicio de figura"<<endl;
        cout<<"Digite 5 = Ejercicio de la frase"<<endl;
        cout<<"Digite 6 = Ejercicio de la hora"<<endl;
        cout<<"Digite 0 para salir"<<endl;
        cout<<"Digite numero del ejercicio que deseas: "<<endl;
        
        cin >> opcion;
        string frase = ""; 
        char c; 
        switch(opcion)
        {
            case 1:
                ejercicio1();
                break;
            case 2:
                ejercicio2();
                break;
            case 3: 
                ejercicio3();
                break;
            case 4:
                ejercicio4();
                break;
            case 5:
                
                cin.ignore();
                cout << "Ingrese una frase: ";
                getline(cin, frase);
                cout << "Ingrese un caracter para buscar: ";
                cin >> c;
                ejercicio5(frase, c);
                
                                
                break;
            case 6:
                ejercicio6();
                break;
            case 0:
                bandera = false;
                break;
            default:
                cout<<"Opcion no valida"<<endl;
            
        } 
    }
    
    return 0;
}