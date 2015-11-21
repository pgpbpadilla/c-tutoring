#include<stdio.h>


typedef struct vector3d{
  int x,y,z;
}v3d;


v3d suma(v3d v1, v3d v2);
int productoPunto(v3d v1, v3d v2);
int main(void){

  v3d v1, v2;
  printf("Dame v1.x: ");
  scanf("%d", &v1.x);
  printf("Dame v1.y: ");
  scanf("%d", &v1.y);
  printf("Dame v1.z: ");
  scanf("%d", &v1.z);

  printf("Dame v2.x: ");
  scanf("%d", &v2.x);
  printf("Dame v2.y: ");
  scanf("%d", &v2.y);
  printf("Dame v2.z: ");
  scanf("%d", &v2.z);


  v3d c= suma(v1, v2);
  int pp= productoPunto(v1, v2);

  printf("Suma (%d, %d, %d) + (%d, %d, %d) = (%d, %d, %d)\n", 
	 v1.x, v1.y, v1.z, v2.x, v2.y, v2.z, c.x, c.y, c.z);
  printf("Producto punto (%d, %d, %d) . (%d, %d, %d) = %d\n", 
    v1.x, v1.y, v1.z, v2.x, v2.y, v2.z, pp);

  return 0;
}

v3d suma(v3d v1,v3d v2){

  v3d resultado;

  resultado.x = (v1.x + v2.x);
  resultado.y = (v1.y + v2.y);
  resultado.z = (v1.z + v2.z);

  return resultado;


}

int productoPunto(v3d v1,v3d v2){

  int x,y,z;
  int resultado;
  
  x= (v1.x * v2.x);
  y= (v1.y * v2.y);
  z= (v1.z * v2.z);

  resultado = x+y+z;
 
  return resultado;



}
