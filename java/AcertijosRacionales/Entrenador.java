import java.util.Random;
import java.util.Scanner;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class Entrenador extends JFrame implements ItemListener, ActionListener {

    private JLabel tituloMenu;
    private JPanel panelOpciones;
	
    private JLabel tituloRespuesta;
    private JLabel acertijo;
    private JTextField respuesta;
    private JButton verificar;

    private ArrayList<JRadioButton> opciones;
    private JRadioButton suma;
    private JRadioButton resta;
    private JRadioButton multiplicacion;
    private JRadioButton division;

    private Acertijo acertijoActual;
    
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

    private Acertijo crearNuevoAcertijo(int operacionSeleccionada){
        Random random = new Random();
        Racional operando1 = new Racional(random.nextInt(10), random.nextInt(10));
        Racional operando2 = new Racional(random.nextInt(10), random.nextInt(10));
        Acertijo acertijo = new Acertijo(operacionSeleccionada, operando1, operando2);
        return acertijo;
    }
    private void actualizaOpciones(JRadioButton boton) {
        System.out.println("Actualizar Seleccion: " + boton.getText());
        // limpia todas las opciones, menos la seleccionada
        for (JRadioButton b: opciones) {
            if (b != boton && b.isSelected()) {
                System.out.println("Limpiando opcion: " + b.getText());
                b.setSelected(false);
            }
        }
        
        establecerAcertijo(crearNuevoAcertijo(leerSeleccion()));
    }

    public void itemStateChanged(ItemEvent e) {

        JRadioButton botonSeleccionado = (JRadioButton)e.getSource();

        if (false == botonSeleccionado.isSelected()) {
            return;
        }

        System.out.println("Seleccion: " + botonSeleccionado.getText());
        actualizaOpciones(botonSeleccionado);
    }    

    private Racional crearRespuesta(String cadena) {
        if("".equals(cadena)){
            return new Racional(0,0);
        }

        // 123/345 => n = 123; d = 345
        // String.split(String separador)
        // "abc-efg".split("-") => ["abc", "efg"]
        String [] elementos = cadena.split("/"); // "123/345" => ["123", "345"]

        // "123" =?> 123
        // Integer.parseInt(String s) => int
        int n = Integer.parseInt(elementos[0]);
        int d = Integer.parseInt(elementos[1]);

        return new Racional(n, d);
    }

    public void actionPerformed(ActionEvent actionEvent) {
        System.out.println("-ActionPerformed-");
        System.out.println(respuesta.getText());

        Racional respuestaUsuario = crearRespuesta(respuesta.getText());

        if (acertijoActual.getRespuesta().equals(respuestaUsuario)) {
            respuesta.setForeground(Color.BLUE); 
        } else {
            acertijo.setForeground(Color.RED);
            respuesta.setForeground(Color.RED);
        }
	
    }

    private void crearInterfaz() {

        tituloMenu = new JLabel("Selecciona el tipo de operacion");
        panelOpciones = new JPanel();
	
        tituloRespuesta = new JLabel("Respuesta");
        acertijo = new JLabel();
        respuesta = new JTextField();
        verificar = new JButton("Verificar");
        verificar.addActionListener(this);
	
        suma = new JRadioButton("Suma");
        suma.addItemListener(this);
        resta = new JRadioButton("Resta");
        resta.addItemListener(this);
        multiplicacion = new JRadioButton("Multiplicacion");
        multiplicacion.addItemListener(this);
        division = new JRadioButton("Division");
        division.addItemListener(this);

        opciones = new ArrayList();

        opciones.add(suma);
        opciones.add(resta);
        opciones.add(multiplicacion);
        opciones.add(division);

       
        Container panelVentana = this.getContentPane();
        panelVentana.setLayout(null); // Borrar configuracion de layout

        tituloMenu.setBounds(10, 10, 280, 20);
        panelVentana.add(tituloMenu);

        panelOpciones.setBounds(10, 40, 280, 70);

        suma.setSelected(true); // Opcion por defecto es Sumar
        panelOpciones.add(suma);
        panelOpciones.add(resta);
        panelOpciones.add(multiplicacion);
        panelOpciones.add(division);

        panelVentana.add(panelOpciones);

        acertijo.setBounds(10, 120, 280, 20);
        panelVentana.add(acertijo);

        tituloRespuesta.setBounds(10, 150, 280, 20 );
        panelVentana.add(tituloRespuesta);

        respuesta.setBounds(10, 180, 130, 20);
        panelVentana.add(respuesta);
    
        verificar.setBounds(160, 180, 130, 20);
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

    private int leerSeleccion() {
        
        if (suma.isSelected()) {
            return 1;
        }

        if (resta.isSelected()) {
            return 2;
        }

        if (multiplicacion.isSelected()) {
            return 3;
        }

        if (division.isSelected()) {
            return 4;
        }
	
        return 1;
    }

    private void establecerAcertijo(Acertijo a){
        acertijo.setText(a.toString()); // actualizar la etiqueda acertijo con el texto `Acertijo.toString`
        acertijoActual = a;
        acertijo.setForeground(Color.BLACK);
        respuesta.setForeground(Color.BLACK);
        respuesta.setText("");
        
    }

    public static void main(String []args){
        // Tipo nombre = new Tipo()
        Entrenador entrenador = new Entrenador();
        entrenador.setVisible(true);
        entrenador.crearInterfaz();
        
        int operacionSeleccionada = entrenador.leerSeleccion();

        Acertijo acertijo = entrenador.crearNuevoAcertijo(operacionSeleccionada);
        entrenador.establecerAcertijo(acertijo);
    }
} 







