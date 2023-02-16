// Tarea numero 2 de la clase de Estructuras de Datos
#include <iostream>
#include <cmath>
#include<ctime>
#include <cstdlib>
#include<string>
using namespace std;
void llenarArreglo (int arreglo[10]){
    for (int i = 0; i < 10; i++)
    {
        cout << "Digite un numero: " << endl;
        cin >> arreglo[i];
    }

   

}
void imprimirArreglo (int arreglo[10]){
    cout << "Los numeros del arreglo son: ";
    cout << "[";
    for (int i = 0; i < 10; i++)
    {
        if ((i >= 1) && (i <= 10))
        {
            cout << ",";
        }
        cout <<arreglo[i];
    }
    cout << "]" << endl;
    
}
void parImpar (int arreglo[10]){
    int par = 0;
    int impar = 0;
    int numpar[10];
    int numimpar[10];
    for (int i = 0; i < 10; i++)
    {
        if (arreglo[i] % 2 == 0)
        {
            numpar[par] = arreglo[i];
            par++;
        }
        else
        {
            numimpar[impar] = arreglo[i];
            impar++;
        }
    }
    cout << "Los numeros pares son: ";
    cout << "[";
    for (int i = 0; i < par; i++)
    {
        if ((i >= 1) && (i <= par))
        {
            cout << ",";
        }
        cout <<numpar[i];
    }
    cout << "]" << endl;
    cout << "Los numeros impares son: ";
    cout << "[";
    for (int i = 0; i < impar; i++)
    {
        if ((i >= 1) && (i <= impar))
        {
            cout << ",";
        }
        cout <<numimpar[i];
    }
    cout << "]" << endl;
    cout << "La cantidad de numeros pares es: " << par << endl;
    cout << "La cantidad de numeros impares es: " << impar << endl;
    
}
void llenarArregloChar (char vocales[5]){
    for (int i = 0; i < 5; i++)
    {
        cout << "Digite una vocal: " << endl;
        cin >> vocales[i];
    }
    

}
void imprimirArregloChar (char vocales[5]){
    cout << "Las vocales del arreglo son: ";
    cout << "[";
    for (int i = 0; i < 5; i++)
    {
        if ((i >= 1) && (i <= 5))
        {
            cout << ",";
        }
        cout <<vocales[i];
    }
    cout << "]" << endl;
    
}
void mayusculasMinusculas(char vocales[5]){
    int mayusculas = 0;
    int minusculas = 0;
    char mayus[5];
    char minus[5];
    for (int i = 0; i < 5; i++)
    {
        if (vocales[i] == 'a' || vocales[i] == 'e' || vocales[i] == 'i' || vocales[i] == 'o' || vocales[i] == 'u')
        {
            minus[minusculas] = vocales[i];
            minusculas++;
        }
        else
        {
            mayus[mayusculas] = vocales[i];
            mayusculas++;
        }
    }
    cout << "Las vocales en minusculas son: ";
    cout << "[";
    for (int i = 0; i < minusculas; i++)
    {
        if ((i >= 1) && (i <= minusculas))
        {
            cout << ",";
        }
        cout <<minus[i];
    }
    cout << "]" << endl;
    cout << "Las vocales en mayusculas son: ";
    cout << "[";
    for (int i = 0; i < mayusculas; i++)
    {
        if ((i >= 1) && (i <= mayusculas))
        {
            cout << ",";
        }
        cout <<mayus[i];
    }
    cout << "]" << endl;
    cout << "La cantidad de vocales en minusculas es: " << minusculas << endl;
    cout << "La cantidad de vocales en mayusculas es: " << mayusculas << endl;
    
}
void llenarMatriz (int matriz[5][5]){

    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matriz[i][j] = rand() % 100 + 1;
        }
        
    }
    
}
void imprimirMatriz (int matriz[5][5]){

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if ((j >= 1) && (j <= 4))
            {
                
                cout << "-";
            }
            cout << matriz[i][j];
            
        }
        cout << endl;
        
    }
}
void elevarMatriz (int matriz[5][5], int matriz2[5][5]){
    cout << "A cuanto quiere elevar la matriz: "<< endl;
    int elevacion;
    cin >> elevacion;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {

            matriz2[i][j] = pow(matriz[i][j], elevacion);
        }
        
    }
    cout << "La matriz elevada a " << elevacion << " es: " << endl;
    
    imprimirMatriz(matriz2);
}
void llenarMatrizChar (char matrizChar[5][5]){
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << "Digite una letra: " << endl;
            cin >> matrizChar[i][j];


        }
        
    }
    
}
void imprimirMatrizChar (char matrizChar[5][5]){

    cout << "La matriz de letras es: " << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if ((j >= 1) && (j <= 4))
            {
                
                cout << "-";
            }
            cout << matrizChar[i][j];
            
        }
        cout << endl;
        
    }
}

void repetidaLetraMatriz (char matrizChar[5][5]){
    int contador = 0;
    char letra;
    cout <<"Digite la letra que desea buscar en la matriz:" << endl;
    
    cin >> letra;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++){

            if (matrizChar[i][j]  == letra)
            {
                contador++;
            }
            
        }
        
    }
    cout << "La letra " << letra << " se repite " << contador << " veces" << endl;
    
}


void numeroRepetidos (int arreglo[10], int matriz[5][5]){
    int cont = 0;
    int numero;
    imprimirArreglo(arreglo);
    cout << endl;
    cout << "Los numeros de la matriz son:" << endl;
    imprimirMatriz(matriz);
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if (arreglo[i] == matriz[j][k])
                {   
                    numero = arreglo[i];
                    cont++;
                }
              
                
            }
            
        }
        if (cont > 0)
        {
        cout << "El numero " << numero << " se repite " << cont << " veces" << endl;
        }
        
        cont = 0;
        
    }
}

int arreglo[10];
int main(){
    // menu de opciones
    bool bandera = true;
    while (bandera==true)
    {
        int opcion;
        cout<<endl;
        cout << "Menu de opciones" << endl;
        cout << "1. Ejercicio arreglo enteros" << endl;
        cout << "2. Ejercicio arreglo char" << endl;
        cout << "3. Ejercicio matriz int" << endl;
        cout << "4. Ejercicio matriz string" << endl;
        cout << "5. Ejercicio combinacion 1,3" << endl;
        cout << "6. Salir"<< endl;
        cin >> opcion;

        switch (opcion){
        case 1:
            
            llenarArreglo(arreglo);
            imprimirArreglo(arreglo);
            parImpar(arreglo);
        
            break;
        case 2:
            char vocales[5];
            llenarArregloChar(vocales);
            imprimirArregloChar(vocales);
            mayusculasMinusculas(vocales);
            break;
        case 3:
            int matriz[5][5];
            int matriz2[5][5];
            llenarMatriz(matriz);
            cout << "La matriz original es: " << endl;
            imprimirMatriz(matriz);
            elevarMatriz(matriz,matriz2);
            
            break;    
        case 4:
            char matrizChar[5][5];
            llenarMatrizChar(matrizChar);
            imprimirMatrizChar(matrizChar);
            repetidaLetraMatriz(matrizChar);
            break;
        case 5:
            numeroRepetidos(arreglo,matriz);

            break;
        case 6:
            bandera = false;
            break;        
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    }
    return 0;
}