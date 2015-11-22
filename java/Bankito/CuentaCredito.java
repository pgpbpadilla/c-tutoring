public class CuentaCredito extends Cuenta{
    private double debito;
    private double interes;
    private double deficit;
    
    public CuentaCredito(){
        super(5000.0);
    }

    public void retirar(double monto) {
        debito = debito + monto;
        super.retirar(monto);
    }

    public String toString(){
        String s = super.toString();

        s += "\n\tDebito: " + debito;
	
        return s;
    }
    public void depositar(double monto) {
        debito = debito - monto;
        super.depositar(monto);
    }
}

