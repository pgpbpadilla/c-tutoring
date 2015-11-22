import java.util.*;

public class Cliente {
    // Atributo con acceso privado
    private String nombre;	
    private ArrayList<Cuenta> cuentas;

    // Constructor: inicializa objetos de la clase Cliente
    public Cliente(String nombre){
        this.nombre= nombre;
	cuentas = new ArrayList<Cuenta> ();
    }
    //Métodos obtenerNombre: devuelve el  nombre
    public String obtenerNombre( ){
        return nombre;
    }  

    public Cuenta obtenerCuenta(int indice){
        return cuentas.get(indice);
    } 

    public void agregarCuenta(Cuenta cta){
        cuentas.add(cta);
    }

    public int obtenerNumCuentas( ){
        return cuentas.size();
    } 

    public String toString() {
        String s = "";

        s += "\nNombre: " + nombre;
	for (Cuenta c: cuentas) {
	    s += "\nCuenta: "
		+ "\n\t" + c.toString();
	}
        
        return s;
    }

    public void reportarEdosDeCuenta(){
	System.out.println("### Estados de cuenta ###");
	for(Cuenta c: cuentas) {
	    System.out.println(c.toString());
	}
	System.out.println("### Fin de Estados de cuenta ###");
    }
} // Fin de la clase Cuenta
