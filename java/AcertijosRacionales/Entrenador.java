import java.util.Random;
import java.util.Scanner;

public class Entrenador{

    public Entrenador () {
        
    }

    private void mostrarOpciones () {
        System.out.println("\nBienvenido al entrenador de racionalizacion, motherfucker!");

        System.out.println("1. Suma");
        System.out.println("2. Resta");
        System.out.println("3. Multiplicacion");
        System.out.println("4. Division");
        System.out.println("0. Salir\n");
    }
    
    public static void main(String []args){
	
        Entrenador entrenador = new Entrenador();

        Scanner input = new Scanner (System.in);
        int operacionSeleccionada, numeradorAcertijo, denominadorAcertijo;
        Random random = new Random();
	
        do {

            entrenador.mostrarOpciones();
            System.out.println("Dame la operacion, motherfucker!");
            operacionSeleccionada = input.nextInt();

            if(operacionSeleccionada == 0)
                break;

            Racional operando1 = new Racional(random.nextInt(10), random.nextInt(10));
            Racional operando2 = new Racional(random.nextInt(10), random.nextInt(10));

            Acertijo acertijoActual = new Acertijo(operacionSeleccionada, operando1, operando2);
            System.out.println(acertijoActual.toString());

            int numerador = -1, denominador = -1;
            System.out.println("Dame la respuesta motherfucker!");
            System.out.println("Numerador? - ");
            numerador = input.nextInt();
            System.out.println("Denominador? - ");
            denominador = input.nextInt();
            Racional respuesta = new Racional(numerador, denominador);
            
            if (respuesta.equals(acertijoActual.getRespuesta())) {
                System.out.println("felicidades acertaste");
                continue;
            }
            
            System.out.println("lo sentimos vuelve a intentarlo");
            System.out.println(respuesta
                               + " no es igual a " 
                               + acertijoActual.getRespuesta());
        } while (operacionSeleccionada != 0);

    }
} 







