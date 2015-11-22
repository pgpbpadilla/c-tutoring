public class Bankito{  

    public static void main(String[ ] args){

        Cliente cliente1 = new Cliente("Mirna");
        Cliente cliente2 = new Cliente("Malnacido");
        Cuenta cta1 = new Cuenta(500.85);

        cliente1.agregarCuenta(cta1);

	cliente1.reportarEdosDeCuenta();
      
        CuentaCredito cuentaCredito = new CuentaCredito();
	CuentaCredito cuentaCredito1 = new CuentaCredito();
        cliente2.agregarCuenta(cuentaCredito);
	cliente2.agregarCuenta(cuentaCredito1);

        cuentaCredito.retirar(100.0);
	cuentaCredito.depositar(300.0);

	cuentaCredito1.retirar(234.5);
	cuentaCredito1.depositar(34.9);
	
        
	cliente2.reportarEdosDeCuenta();
    } 

} 
