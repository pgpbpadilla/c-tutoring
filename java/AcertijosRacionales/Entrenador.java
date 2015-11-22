import java.util.Random;
import java.util.Scanner;
import javax.swing.*;
import java.awt.*;

public class Entrenador extends JFrame {

    public Entrenador () {
        setTitle("Racionales");
        setSize(300, 250);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    private void mostrarOpciones () {
        System.out.println("\nBienvenido al entrenador de racionalizacion, motherfucker!");

        System.out.println("1. Suma");
        System.out.println("2. Resta");
        System.out.println("3. Multiplicacion");
        System.out.println("4. Division");
        System.out.println("0. Salir\n");
    }
    
    private void crearInterfaz() {
        JLabel tituloMenu = new JLabel("Selecciona el tipo de operacion");
        JPanel panelOpciones = new JPanel();
	
        JLabel tituloRespuesta = new JLabel("Respuesta");
        JTextField respuesta = new JTextField();
        JButton verificar = new JButton("Verificar");
	
        JRadioButton suma = new JRadioButton("Suma");
        JRadioButton resta = new JRadioButton("Resta");
        JRadioButton multiplicacion = new JRadioButton("Multiplicacion");
        JRadioButton division = new JRadioButton("Division");

       
        Container panelVentana = this.getContentPane();
        panelVentana.setLayout(null); // Borrar configuracion de layout

        tituloMenu.setBounds(10, 10, 280, 20);
        panelVentana.add(tituloMenu);

        panelOpciones.setBounds(10, 40, 280, 70);

        panelOpciones.add(suma);
        panelOpciones.add(resta);
        panelOpciones.add(multiplicacion);
        panelOpciones.add(division);

        panelVentana.add(panelOpciones);
    
        tituloRespuesta.setBounds(10, 120, 280, 20 );
        panelVentana.add(tituloRespuesta);

        respuesta.setBounds(10, 150, 130, 20);
        panelVentana.add(respuesta);
    
        verificar.setBounds(160, 150, 130, 20);
        panelVentana.add(verificar);

        this.revalidate();
	
    }

    private void entrenarConLineaDeComandos() {
	
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
    
    public static void main(String []args){
        // Tipo nombre = new Tipo()
        Entrenador entrenador = new Entrenador();
        entrenador.setVisible(true);
        entrenador.crearInterfaz();
    }
} 







