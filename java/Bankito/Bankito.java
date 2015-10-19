public class Bankito{  


    public static void main(String[ ] args){
        Cuenta ctaAux; 
        Cuenta ctaAux2;
			
        Cliente qx= new Cliente("El Quijote","QX400");
        Cliente sx=new Cliente("Sancho Panza","SPANZA");
				
        qx.establecerCuenta(new Cuenta(550.45));
        sx.establecerCuenta(new Cuenta(100.35));
							
        ctaAux= qx.obtenerCuenta( );
        ctaAux2= sx.obtenerCuenta( );
	
        System.out.println("Cliente:" + qx.obtenerNombre());

        /*ctaAux.depositar(300.55);
          ctaAux2.retirar(100);
          ctaAux.depositar(49);*/
        System.out.println("Nombre Cliente:" +qx.obtenerNombre());
        System.out.println("Num cta: " +qx.obtenerNumCta());
        System.out.println("Saldo: "+ctaAux.consultar());
        System.out.println("Nombre Cliente:" +sx.obtenerNombre());
        System.out.println("Num cta: " +sx.obtenerNumCta());
        System.out.printf("Saldo: %.2f\n", ctaAux2.consultar());
    } 
} 
