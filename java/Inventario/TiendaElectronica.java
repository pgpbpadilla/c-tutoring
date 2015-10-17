import java.util.Scanner;

public class TiendaElectronica {

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
