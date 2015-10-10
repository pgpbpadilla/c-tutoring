public class Racional{

    private int num;
    private int den;

    public Racional(int n, int d){
        num=n;
        if(d==0)
            den=1;
        else
            den=d;
    }

    public Racional(){
        num=den=1;
    }

    public void establecer(int num, int den){
        this.num=num;
        if(den == 0)
            this.den=1;
        else
            this.den=den;
    }

    public void multiplicar(Racional R){		
        this.num= this.num * R.num;
        this.den= this.den * R.den;
    }

    public void imprimir(){
        System.out.println("[" + num + "," + den + "]");
    }
	
    public int obtenerNum(){
        return num;
    }
	
    public int obtenerDen(){	
        return den;
    }
    
    public String toString() { 
        return num + "/" + den;
    }

    public Boolean equals(Racional racional) {

        if (num == racional.obtenerNum() 
            && den == racional.obtenerDen()) {
            return true;
        }
        
        return false;
    }
}
