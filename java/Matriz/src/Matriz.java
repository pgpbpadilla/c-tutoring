/* package whatever; // don't place package name! */

import java.util.Random;
import java.util.Scanner;

public class Matriz
{
  private Random r;
  private int filas;
  private int columnas;
  private int[][] matriz;

  public Matriz (int filas, int columnas) {
    this.r = new Random();
    this.filas = filas;
    this.columnas = columnas; 

    this.matriz = new int[filas][columnas];

    for(int i = 0; i<filas; ++i) {
      for(int j = 0; j<columnas; ++j) {
        this.matriz[i][j] = r.nextInt(filas*columnas);
      }
    }

  }

  public int get(int i, int j) {
    return this.matriz[i][j];
  }

  public void set(int valor, int i, int j) {
    this.matriz[i][j] = valor;
  }

  public Matriz suma(Matriz m) {
    Matriz suma = new Matriz(filas, columnas);

    for(int i = 0; i<filas; ++i) {
      for(int j = 0; j<columnas; ++j) {
        suma.set(this.matriz[i][j] + m.get(i, j), i, j);
      }
    }
    return suma;
  }

  @Override
  public String toString() {
    String string = new String();

    for(int i = 0; i<this.filas; ++i) {
      string += "[";
      for(int j = 0; j<this.columnas; ++j) {
        string += this.matriz[i][j] + "\t";
      }
      string+= "]\n";
    }
    return string;
  }

  public static void main (String[] args) throws java.lang.Exception
  {
    Scanner s =  new Scanner(System.in);
    int filas, columnas;

    System.out.println("Filas: ");
    filas = s.nextInt();

    System.out.println("Columnas: ");
    columnas = s.nextInt();

    Matriz m1, m2;
    m1 = new Matriz(filas, columnas);
    m2 = new Matriz(filas, columnas);

    System.out.println(m1);
    System.out.println(m2);
    System.out.println(m1.suma(m2));

  }
}