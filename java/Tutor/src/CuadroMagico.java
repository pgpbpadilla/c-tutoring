// importamos la libreria para poder leer la entrada del teclado
import java.util.Scanner;


// declaracion de la clase
public class CuadroMagico
{
    // attributos privados
    private int tamanio;
    // arreglo bi-dimensional para guardar 
    // la representacion matricial del cuadro magico
    private int[][]matriz;


    // Metodos publicos
    // constructor (publico)
    CuadroMagico(int tamanio) throws Exception {
        // Si el tamanio utilizado es par
	if (tamanio % 2 == 0){
            // arroja un Exception
	    System.out.println("Se esperaba un tamanio impar, pero se tiene tamanio = " + tamanio);
	    throw new Exception("Se esperaba un tamanio impar, pero se tiene tamanio = " + tamanio);
            
            // !!! Si hay una Excepcion aqui termina la ejecucion.
	}
        
	// Si no hay excepcion, el programa continua.
        // Quiere decir que tamanio es impar.
        // guardamos el tamanio del cuadro
	this.tamanio = tamanio;
        // inicializamos el arreglo donde guardaremos el cuadro magico
        // por defecto todos los elementos de este arreglo son inicializados
        // con el numero cero.
	this.matriz = new int [tamanio][tamanio];

	// solucion: Metodo Siames??
        
        // el numero que estamos tratando de asignar en el cuadro
	int numeroActual = 1;
        
        // indican la posicion en el arreglo en la cual se 
        // va  a poner el numero actual.
	int i=0, j = 1;

        // En total hay tamanio*tamanio elementos, por lo que 
        // continuaremos colocando numeros siempre y cuando sean
        // menores que tamanio*tamanio
	while (numeroActual <= tamanio*tamanio){
            // si el elemento i,j no es cero, 
            // quiere decir que ya ha sido asignado
	    if (0 != matriz[i][j]) {
                // nos movemos una fila hacia abajo de la posicion
                // original, respetando el tamanio del cuadro (%tamanio)
		i = (i+2)%tamanio;
                // nos movemos una columna hacia la izquierda, 
                // respetando el tamanio del cuadro
                j = (j-1)<0 ? tamanio+(j-1) : j-1;
	    }

            // asigna el numero actual a la posicion i,j
	    matriz[i][j] = numeroActual;
            // una vez asignado el numero actual, hay que incrementar
            // para obtener el siguiente numero a colocar
            numeroActual++;
            
            // Nos movemos en diagonal hacia arriba y a la derecha.
            // primero nos movemos una fila hacia arriba, respetando
            // el tamanio del cuadro.
	    i = i-1 < 0 ? tamanio - 1 : i-1;
            // luego nos movemos una columna hacia la derecha, respetando
            // el tamanio del cuadro (%tamanio).
	    j = (j+1)%(tamanio);
	}
    }
    
    // Implementamos el metodo `toString` para poder imprimir el 
    // cuadro magico.
    public String toString() {
	String s = new String();
        
        // variables para calcular la suma de filas y columnas
        int sumaFila = 0, sumaColumna = 0;

	// ciclo para recorrer las filas
	for ( int i = 0; i<tamanio ; ++i){
            // inicializa la suma para la fila actual
            // sumaFila sera reiniciado a cero para cada fila 
            // porque esta en el ciclo que recorre las filas
            sumaFila = 0;
            
            // ciclo para recorrer las columnas
	    for (int j =0; j <tamanio ; ++j){
                // concatena el elemento i,j con un caracter separador: <TAB>
		s += matriz[i][j] + "\t"; // \t == <TAB>
                // agregar el valor del elemento i,j
                sumaFila += matriz[i][j];
	    }
            
            // concatena el total para esta fila
	    s += "=" + sumaFila + "\n";
	}
        
        // ciclo para recorrer las columans
        for (int x = 0; x<tamanio; ++x) {
            // inicializamos la suma para la columna actual
            // sumaColumna sera reiniciado a cero para cada columna
            sumaColumna = 0; 
            
            // ciclo para recorrer las filas
            for (int y = 0; y<tamanio; ++y) {
                // agregamos el valor del elemento actual
                sumaColumna += matriz[y][x];
            }
            // concatenamos las sumas de cada columna separadas
            // por el caracter <TAB> == \t
            s += "=" + sumaColumna + "\t";
        }

	return s;
    }


    // metodo main: este es la primera parte que se ejecuta
    public static void main(String[] args){
        
        // Declaramos una variable de tipo CuadroMagico
	CuadroMagico c1;

        // Inicializamos un scanner para leer del teclado.
	Scanner s = new Scanner(System.in);

        // pedimos el tamanio del cuadro al usuario
        System.out.println("Ingresa el tamanio del cuadro: ");
        // escaneamos la entrada del teclado
	int tamanio = s.nextInt();
	
	try {
            // inicializamos un cuadro magico con el tamanio ingresado
            // en este momento es cuando se executa el algoritmo para
            // construir el cuadro magico.
	    c1 = new CuadroMagico(tamanio);
	
            // Imprimimos la cadena que representa el cuadro magico
            // Estamos utilizando el metodo `toString` que definimos en esta
            // misma clase.
	    System.out.println("El cuadro magico es: \n" + c1.toString());
	} catch (Exception e){ // capturamos la exception en caso de haberla
            // imprime la exception
	    System.out.println(e);
	}
	
    }
    
}
