import java.util.Scanner;

public class Fechas {
    
    private int mes, anio;
    private String[] meses;
    
    Fechas(int mes, int anio) {
        this.mes = mes;
        this.anio = anio;
        
        meses = new String[]{"Enero", "Febrero", "Marzo", "Abril", "Mayo", 
            "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre",
            "Diciembre"};
    }
    
    String calcularFecha(int intervalo) {
        int nuevoAnio=0, nuevoMes=0;
        
        if (intervalo >= 0){
            nuevoMes = (this.mes-1 + intervalo) % 12;
            
            if (intervalo < 12 
                    && (this.mes-1 + intervalo >= 12)) {
                nuevoAnio = this.anio + 1;
            } else {
                nuevoAnio = (this.anio + (int)Math.floor(intervalo/12));
            }
        } else { // intervalo negativo
            if (this.mes-1 + intervalo >= 0){
                nuevoMes = this.mes-1 + intervalo;
                nuevoAnio = this.anio;
            } else {
                nuevoMes = (((this.mes-1 + intervalo) % 12 ) + 12) % 12;
                
                if (Math.abs(intervalo) < 12 
                        && this.mes-1 + intervalo < 0) {
                    nuevoAnio = this.anio-1;
                } else {
                    nuevoAnio = this.anio + (int)Math.floor(intervalo/12.0f);
                }
            }
        }
        
        return (meses[nuevoMes] + ", " + nuevoAnio);
    }
    
    public String toString(){
        return (meses[this.mes-1] + ", " + anio);
    }
    
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        int opcion = -1, mes, anio, intervalo;
        
        while(0 != opcion) {
            System.out.println("Opciones:");
            System.out.println("\t 0. Salir");
            System.out.println("\t 1. Calcular fecha+intervalo");
            opcion = s.nextInt();
            
            if (0==opcion) {
                return;
            }
            
            System.out.println("Ingresar mes [entero]: ");
            mes = s.nextInt();
            System.out.println("Ingresar anio [entero]: ");
            anio = s.nextInt();
            System.out.println("Ingresar intervalo [entero]: ");
            intervalo = s.nextInt();
            
            Fechas f = new Fechas(mes, anio);
            System.out.println("Fecha creada: " + f.toString());
            
            System.out.println("Fecha + intervalo: " + f.calcularFecha(intervalo));
            
        }
    }
}
