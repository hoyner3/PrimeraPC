import java.util.*;
public class App {
    public static void main(String[] args){

       // numero aleatorio entre 0 y 100
        int aleatorio = (int) (Math.random() * 100);
        Scanner entrada = new Scanner(System.in);
        int numero = 0;
         
        int intentos = 0;
        while (numero != aleatorio){
            intentos++;
            System.out.println("Introduce un numero: ");
            numero = entrada.nextInt();
            if (numero < aleatorio){
                System.out.println("Mas alto");
            }else if (numero > aleatorio){
                System.out.println("Mas bajo");
            }

        }
        System.out.println("Correcto, has necesitado " + intentos + " intentos");
        numero = 0;
        aleatorio = (int) (Math.random() * 100);
        intentos = 0;
        do{
            intentos++;
            System.out.println("Introduce un numero: ");
            numero = entrada.nextInt();
            if (numero < aleatorio){
                System.out.println("Mas alto");
            }else if (numero > aleatorio){
                System.out.println("Mas bajo");
            }

        }while (numero != aleatorio);
        System.out.println("Correcto, has necesitado " + intentos + " intentos");

        
    }

}
