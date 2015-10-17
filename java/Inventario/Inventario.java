import java.util.Scanner;
import java.util.ArrayList;

public class Inventario {
  
    private class Transaccion {
        public int tipoProducto;
        public int cantidad;
    }
    
    private ArrayList usbs;
    private ArrayList laptops;
    private ArrayList audifonos;
    private double precioUSB;
    private double precioLaptop;
    private double precioAudifonos;
    
    public Inventario(){
      
        usbs = new ArrayList();     
        laptops = new ArrayList();
        audifonos = new ArrayList();
        precioUSB = 100.0;
        precioLaptop = 5000.0;
        precioAudifonos = 250.0;
    } 
    
    public String toString(){
      
        String descripcionInventario = "";

        // "USB (Kingston) - Cantidad: 30 - Precio - $40";
        // "Laptop (Acer) - Cantidad: 30 - Precio - $50";

        descripcionInventario+= "\nUSB\tCantidad: " + usbs.size() + "\tPrecio: " + precioUSB;
        descripcionInventario+= "\nLaptop\tCantidad: " + laptops.size() + "\tPrecio: " + precioLaptop;
        descripcionInventario+= "\nAudifonos\tCantidad: " + audifonos.size() + "\tPrecio: " + precioAudifonos;
        descripcionInventario+= "\n";

        return descripcionInventario;
    }

    public void vender(Transaccion transaccion){

        if(transaccion.cantidad < 0){
            System.out.println("El usuario esta idiota y no sabe lo que hace");
            return;
        }

        String producto= "";
        ArrayList lista = null;
	
        switch(transaccion.tipoProducto) {
        case 1:
            producto = "USB";
            lista = usbs;
            break;
        case 2:
            producto = "Laptop";
            lista = laptops;
            break;
        case 3:
            producto = "Audifonos";
            lista = audifonos;
            break;
        default:
            System.out.println("\nOpcion invalida!!!\n");
            return;
        }

        if(null != lista) {

            // Si no hay productos de este tipo
            if(lista.size() == 0) {
                System.out.println("\nEl producto: " + producto + " no esta en existencia.\n");
                return;
            }

            // Si se quieren vender mas de los que se tienen en inventario
            if(transaccion.cantidad > lista.size()) {
                System.out.println("\nNo hay suficientes productos de tipo: " + producto);
                System.out.println("\nCantidad vendida: " + lista.size());

                lista.clear(); // Remover todos los elementos de la lista
                return;
            }

            // Si la cantidad a vender es menor o igual que la cantidad en inventario
            int indiceProducto = lista.size() - 1; // el ultimo elemento de la lista
            int k = transaccion.cantidad;
            // removemos los ultimos k productos de la lista
            for (int i = 0; i < k; i++) {
                lista.remove(indiceProducto);
                indiceProducto--;
            }
            System.out.println("\nCantidad vendida: " + transaccion.cantidad + "\n");
            System.out.println("\nEn inventario: " + lista.size() + "\n");
            
        }
        
	
    }
    
    public void comprar(Transaccion transaccion){
        
        if(transaccion.cantidad < 0){
            System.out.println("\nEres un tonto usuario!!!\n");
            return;
        }

        String producto= "";
        ArrayList lista;

        switch(transaccion.tipoProducto) {
        case 1:
            producto = "USB";
            lista = usbs;
            break;
        case 2:
            producto = "Laptop";
            lista = laptops;
            break;
        case 3:
            producto = "Audifonos";
            lista = audifonos;
            break;
        default:
            System.out.println("\nOpcion invalida vayase al carajo!!!!\n");
           return;
        }

        for(int i = 0; i < transaccion.cantidad; i++){
            lista.add(producto);
        }

        System.out.println("\nCantidad de compra: " + transaccion.cantidad + "\n");

    }
    

    public Transaccion solicitarDatosDeTransaccion() {

        Scanner entrada = new Scanner(System.in);
        Transaccion transaccion = new Transaccion();        

        System.out.println("Elija tipo de producto:");
        System.out.println("1. USB");
        System.out.println("2. Laptop");
        System.out.println("3. Audifonos");
        transaccion.tipoProducto = entrada.nextInt();

        System.out.println("Cantidad:");
        transaccion.cantidad = entrada.nextInt();

        return transaccion;
    }

    private void mostrarMenu(){
    
        System.out.println("Bienvenido al inventario");
        System.out.println("Seleccionciuna opcion:");
        System.out.println("1: Productos en existencia");
        System.out.println("2: Vender");
        System.out.println("3: Comprar");
        System.out.println("0: Salir");
        
    }
   
    public static void main(String [] args){
        
        int seleccion = -1;
        Scanner entrada = new Scanner(System.in);
        Inventario inventario = new Inventario();

        while(true) {
            
            inventario.mostrarMenu();

            seleccion = entrada.nextInt();

            if (0 == seleccion) {
                break;
            }            
            switch(seleccion){
            case 1: 
                System.out.println(inventario);
                break;
            case 2:
                Transaccion datosDeVenta = inventario.solicitarDatosDeTransaccion();
                inventario.vender(datosDeVenta);
                break;
            case 3:
                Transaccion datosDeCompra = inventario.solicitarDatosDeTransaccion();
                inventario.comprar(datosDeCompra);
                break;
            default:
                System.out.println("\nOpcion invalida vuelva a nacer!!!!!\n");
                break;
            }
            
        };
    }

}
