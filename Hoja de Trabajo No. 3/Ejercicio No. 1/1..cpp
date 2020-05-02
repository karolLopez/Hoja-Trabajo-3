/*
El presidente de un club de futbol requiere calcular el sueldo de sus jugadores
si se tiene como dato la edad y la nacionalidad del jugador.

Ademas se sabe que el sueldo se calculara de la siguiente manera:
Sueldo fijo $2500.00
Si es extranjero recibe un bono de $500.00

Si la edad esta entre 15 y 20, el salario incrementa en $1400.00
Si la edad esta entre 21 y 25, el salario incrementa en $1500.00
Si la edad esta entre 26 y 30, el salario incrementa en $1200.00
Si la edad es mayor a 30, el salario incrementa en $800.00
Determine el sueldo del jugador si se tiene como datos la edad y nacionalidad.

Mostrar un reporte del total a pagar de planilla, así como el total de jugadores por
los rangos de edad. Ademas de indicar que rango de edad es el mas remunerado.
*/

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include<ctime> 
#include <stdio.h>
#include <vector>
using namespace std;

// Hacemos la estructura de jugadores.
struct Jugadores{
  string nombre;
  int edad;
  float sueldo;
  bool extranjero=false;
};

// cada grupo es el rango de edad definido en el requerimiento del ejercicio
// llevaremos la cuenta de ingresos por grupo
int grupo1=0, grupo2=0, grupo3=0, grupo4=0;

// Creamos el vector de forma Global
std::vector<Jugadores> jugador;

// realizamos la funcion de tipo float, ya que es lo que vamos devolver un tipo float en el return que es sueldo, tambien agregamos variables en la función de tipo entero que es edad y booleano que es si es extranjero o no.
float calcular(int edad, bool extranjero){
  // declaramos la variables que nos ayudara a calcular el salario.
  float salario;

  // verificamos si el ingreso de la variable es true o false.
  if (extranjero==true){
    salario=800;
  }
  else {
    salario=0;
  }

  // comparamos el rango de edad.
  if ((edad>=15) and (edad<=20)){
    salario=salario+1400;
    grupo1=grupo1+1;
  }
  else if ((edad>=21) and (edad<=25)){
    salario=salario+1500;
    grupo2=grupo2+1;
  }
  else if ((edad>=26) and (edad<=30)) {
    salario=salario+1200;
    grupo3=grupo3+1;
  }
  else if ((edad>30)) {
    salario=salario+800;
    grupo4=grupo4+1;
  }
  else {
    salario=0;
  }
  return salario;
}

// realizamos la funcion ingreso, aca no tenemos ningun return, por lo tanto es de tipo void.
void ingreso(){
  
  // Variables que utilizaremos para ayuda de la logica de ingreso
  string var1;
  bool control=false;
  
  // pasamos la estructura de Jugadores a X
  Jugadores x;
  
  //Ingresamos los datos de los jugadores y mostramos en pantalla
  cout << "Ingrese nombre: " << "\n";
  cin >> x.nombre;
  cout << "Ingrese Edad: "<< "\n";
  cin >> x.edad;
  
  // hacemos un mientras nos devuelve un si o no, para hacer un booleano
  // la variable control nos servira para terminar el while
  while (control==false) {
    cout << "Es extranjero, (si/no): "<< endl;
    cin >> var1;
    if ((var1=="si") or (var1=="SI")){
      x.extranjero=true;
      control=true; // validamos que la opcion es correcta para finalizar el while
    } else if ((var1=="no") or (var1=="NO")){
      x.extranjero=false;
      control=true; // validamos que la opcion es correcta para finalizar el while
    } else {
      cout << "Ingreso una opcion invalida, intente de nuevo " << endl;
    }
  }
  // llamamos la funcion de calcular y nos devuelve el sueldo
  x.sueldo=calcular(x.edad, x.extranjero);

  // grabamos en el vector
  jugador.push_back(x);

}


void reporte(){
  // Hacemos un recorrido en todo el vector para mostrar la informacion
  cout << "========== Planilla ==========" << "\n";
  for (int x=0; x<jugador.size(); x++) {
    cout << jugador[x].nombre << "\t" << jugador[x].edad << "\t";
    
    // confirmamos si son extranjeros o nacionales
    if (jugador[x].extranjero==true){
      cout << "extranjero"<< "\t";
    } else {
      cout << "nacional"<< "\t";
    }
    cout << jugador[x].sueldo << endl;
  }
  cout << "========================================" << "\n \n";
  // Mostramos el total de ingresos por rango de edad
  cout << "Jugadores de 15 a 20 : " << grupo1 << endl;
  cout << "Jugadores de 21 a 25 : " << grupo2 << endl;
  cout << "Jugadores de 26 a 30 : " << grupo3 << endl;
  cout << "Jugadores mayores de 30 : " << grupo4 << "\n \n";

  // ahora hacemos la comparacion que grupo fue el mayor pagado
  if ((grupo1>grupo2) and (grupo1>grupo3) and (grupo1>grupo4)) {
    cout << "El rango de Jugadores de 15 a 20 es el mas remunerado";
  }
  else if ((grupo2>grupo3) and (grupo2>grupo4) and (grupo2>grupo1)){
    cout << "El rango de Jugadores de 21 a 25 es el mas remunerado";
  }
  else if ((grupo3>grupo4) and (grupo3>grupo1) and (grupo3>grupo2)){
    cout << "El rango de Jugadores de 26 a 30 es el mas remunerado";
  }
  else if ((grupo4>grupo1) and (grupo4>grupo2) and (grupo4>grupo3)){
    cout << "El rango de Jugadores de mayores de 30 es el mas remunerado";
  }
    cout << "\n";
  
  // variable para pausar el despliegue
  string empty;
  getchar();
  getline(cin, empty);
}

// hacemos la funcion menu
void menu(){
  char tecla;
  string empty;
  bool bandera=false;
  
  do
    {
        system("clear");
        cin.clear();
        cout << "Club de futbol" << endl;
        cout << "-----------" << endl << endl;
        cout << "\t1 .- Agregar Jugador" <<endl;
        cout << "\t2 .- Mostrar Reporte" <<endl;
        cout << "\t3 .- Salir" << endl << endl;
        cout << "Elije una opcion: ";
 
        cin >> tecla;
 
		switch(tecla)
    		{
			case '1':
				system("clear");
        ingreso();
        break;
 
			case '2':
        system("clear");
        reporte();
        break;
      
      case '3':
				bandera=true;
				//exit(1);
				break;
 
			default:
				system("clear");
				cout << "Opcion no valida.\a\n";
				getchar();
        getline(cin, empty);
				break;
		}
    }while(bandera!=true);
}

int main(){
  // llamamos la funcion menu
  menu();
  return 0;
}
