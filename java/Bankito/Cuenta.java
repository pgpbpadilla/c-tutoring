import java.util.*;

public class Cuenta {
    // Atributo con acceso privado
    private double saldo;
    private int numCuenta;
    // Constructor: inicializa objetos de la clase Cuenta
    public Cuenta(double saldoInicial){
        saldo = saldoInicial;
	Random random = new Random();
	numCuenta = random.nextInt(500);
    }
    //Métodos
    // Consultar: devuelve el saldo actual
    public double consultar( ){
        return saldo;
    }
    //Métodos
    // Depositar: incrementa el saldo en el monto indicado
    public void depositar(double monto ){
        saldo = saldo + monto;
    }
    // Retirar: decrementael saldo en el monto indicado siempre que el monto sea mayor o igual al saldo
    public void retirar(double monto ){
        if( saldo >= monto ) {
            saldo = saldo -monto;
        }
        else{
            System.out.println("Saldo insuficiente");
        }
    }

    public String toString() {
	String s = "";
	s += "Num. Cuenta: " + numCuenta;
	s += "\n\tSaldo: " +  saldo;
        return s;
    }

} // Fin de la clase Cuenta
