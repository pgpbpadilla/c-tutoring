import java.util.Scanner;


public class Inventario {
  
    private class Transaccion {
        int tipoProducto;
        int cantidad;
    }
    
    public String toString(){
      
        String descripionInvetario = "";

        // "USB (Kingston) - Cantidad: 30 - Precio - $40";
        // "Laptop (Acer) - Cantidad: 30 - Precio - $50";

        descripcionInventario+= "USB\tCantidad: " + usbs.size() + "\tPrecio:" + precioUSB;
        descripcionInventario+= "Laptop\tCantidad: " + laptops.size() + "\tPrecio:" + precioLaptop;
        descripcionInventario+= "Audifonos\tCantidad: " + audifonos.size() + "\tPrecio:" + precioAudifonos;

        return descripcionInvetario;
    }

    public void vender(Transaccion transaccion){
        System.out.println("Vendiendo!!!!");
    }
    
    public void comprar(Transaccion transaccion){
        System.out.println("Comprando!!!!");
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
                break;
            }
            
        };
    }

}
