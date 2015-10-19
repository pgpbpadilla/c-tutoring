public class Bankito{  

    public static void main(String[ ] args){
        Cliente cliente1 = new Cliente("Mirna","xs0098");

        Cuenta cta1 = new Cuenta(500.85);

        cliente1.establecerCuenta(cta1);

        System.out.println("Nombre del Cliente: "  + cliente1.obtenerNombre() + "\n\n"
                           + "\tNo. Cuenta: " + cliente1.obtenerNumCta() + "\n"
                           + "\tSaldo: " +  cliente1.obtenerCuenta().consultar() + "\n");
	
    } 

} 
