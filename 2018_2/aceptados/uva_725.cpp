#include <cstdio>
#include <set>
#include <utility>
#include <cmath>
#include <iostream>
using namespace std;

/*Solucion NO propia
https://github.com/ackoroa/UVa-Solutions/blob/master/UVa%20725%20-%20Division/src/UVa%20725%20-%20Division.cpp
*/

/*Revisa si el numerador y el denominador no comparten digitos en comun*/
bool alldiff(int n, int m) {
  if (n >= 100000) /*El numero no puede ser mayor a 5 digitos*/
  return false;

  int c, mask = 0;
  //Para numerador
  for (int i = 0; i < 5; i++) {
    c = (int) (n / pow(10, i)) % 10; //Obtiene el digito asociado

    if ((mask >> c) % 2) //Usando una mascara de bits revisa si el digito ya fue usado.
    return false; //El digito se repitio, no cumple condicion
    mask |= 1 << c; //Usando un OR logico, indica con la mascara que se utilizo el digito
  }
//Repite procedimiento con el denominador
  for (int i = 0; i < 5; i++) {
    c = (int) (m / pow(10, i)) % 10;
    if ((mask >> c) % 2)
    return false;
    mask |= 1 << c;
  }

//Si no se encontraron digitos repetidos , cumplen la condicion
  return true;
}

int main() {
  int n, count = 0;

  while (scanf("%d", &n), n) { //Si n es distinto de 0 se ejecuta el loop
    int num, denum;
    bool found = false;
    count++;
    if (count > 1)
    //Si no es el primer caso imprimir salto de linea
    printf("\n");
    /*El loop lo realiza desde el menor eleemnto posible con los digitos hasta un numero
    cuyo orden de magnitud acota las soluciones*/
    for (denum = 1234; denum < 50000; denum++) {
      num = denum * n; /*Multiplica el denomindador por el numero buscado*/
      if (alldiff(num, denum)) {//Verifica si no se repite ningunddigto
        printf("%05d / %05d = %d\n", num, denum, n); //Imprime con formato pedido
        found = true; //Encontro resultados
      }
    }
    if (!found)
    //En caso de no haber encontrado resultados esto se imprime
    printf("There are no solutions for %d.\n", n);
  }

  return 0;
}
