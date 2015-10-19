public class Cliente {
    // Atributo con acceso privado
    private String nombre;	
    private Cuenta cuenta;
    private String numCta;
    // Constructor: inicializa objetos de la clase Cliente
    public Cliente(String nombre, String numCta){
        this.nombre= nombre;
        this.numCta= numCta;
    }
    //Métodos obtenerNombre: devuelve el  nombre
    public String obtenerNombre( ){
        return nombre;
    }  
    //Métodos obtenerCuenta: devuelve el objeto de la clase Cuenta
    public Cuenta obtenerCuenta( ){
        return cuenta;
    } 
    // establecerCuenta: establece el objeto de la clase Cuenta
    public void establecerCuenta(Cuenta cta){
        cuenta = cta;
    }
    // obtenerNombre: devuelve el  numero de cuenta
    public String obtenerNumCta( ){
        return numCta;
    } 
} // Fin de la clase Cuenta
