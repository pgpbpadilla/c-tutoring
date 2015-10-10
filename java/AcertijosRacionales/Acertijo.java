public class  Acertijo {

    private int operacion;
    private Racional operando1;
    private Racional operando2;

    public Acertijo (int tipoOperacion, Racional racional1, Racional racional2) {
        operacion = tipoOperacion;
        operando1 = racional1;
        operando2 = racional2;
    }

    public Racional getRespuesta() {

        Racional respuesta= null;

        int a, b, c, d;

        a = operando1.obtenerNum();
        b = operando1.obtenerDen();
        c = operando2.obtenerNum();
        d = operando2.obtenerDen();

        switch(operacion) {
        case 1:
            respuesta = new Racional(a*d + b*c, b*d);
            break;
        case 2:
            respuesta = new Racional(a*d - b*c, b*d);
            break;
        case 3:
            respuesta = new Racional(a*c, b*d);
            break;
        case 4: 
            respuesta = new Racional(a*d, c*b);
            break;
        default:
            break;
        }

        return respuesta;
    }

    public String toString() {

        String cadenaParaAcertijo = "";

        cadenaParaAcertijo += operando1.toString() + " ";
        cadenaParaAcertijo += signoParaOperacion(operacion)+ " ";
        cadenaParaAcertijo += operando2.toString();

        return cadenaParaAcertijo;
    }

    private String signoParaOperacion(int tipoOperacion) {
        String signo= "";

        switch (tipoOperacion){
  
        case 1: 
            signo="+";
            break;
        case 2: 
            signo="-";
            break;
        case 3: 
            signo="*";
            break;
        case 4: 
            signo="/";
            break;
        default:
            signo = "?";
            break;
  
        }
        
        return signo;
    }
}
