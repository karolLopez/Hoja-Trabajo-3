/*
En la Pizzeria "Gran sabor" se tienen las siguientes ofertas:
Por la compra de una pizza grande (Q80.00), recibe un descuento de 10%
Por la compra de una pizza familiar (Q115.00), recibe un descuento de 15%
Por la compra de una pizza fiesta(Q100.00), recibe un descuento de 20%

Solicitar el tipo de pizza, el precio unitario y hallar el precio a pagar.

Grabar los datos a un archivo y mostrar el total global de la venta del dia y determinar el total de lo vendido por producto, mostrando tambien el porcentaje con relacion al total.

*/
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include<ctime> 
#include <stdio.h>
#include <vector>
using namespace std;

// Declaramos la estrecutura de las pizzas
struct Pizzas{
  int tipo;
  string descripcion;
  float precio;
  float descuento;
  int pedidas;
};

// Declaramos el vector de pizzas
std::vector<Pizzas> pizza;

void inicio_pizzas(){
  pizza.push_back({1,"grande",80.00,0.10,0}); // 1 pizza grande (Q80.00), recibe un descuento de 10%
  pizza.push_back({2,"family",115.00,0.15,0}); // 2 pizza familiar (Q115.00), recibe un descuento de 15%
  pizza.push_back({3,"fiesta",100.00,0.20,0}); // 3 pizza fiesta(Q100.00), recibe un descuento de 20%
}

void mostrar_pizzas(){
  cout << "# Pizza     Precio (Q)    Descuento(%)" << "\n";
  cout << "===========================================" << "\n";
  for (int x=0; x<pizza.size(); x++){
    cout << pizza[x].tipo << " " << pizza[x].descripcion << "\t" << pizza[x].precio << "\t " << "\t " << "\t " << pizza[x].descuento << "\n";
  }
}  

void pedido(){
  // mostramos las opciones de pizzas que tenemos
  mostrar_pizzas();

  string vacio;
  float total;
  float descuento, descuentototal;
  int cantidad;
  // variable para selecionar la opcion
  int x=0;
  cin >> x;
  
  

  if ((x>=1) and (x<=3)){
    
    // restamos 1 por el indice del vector
    x=x-1;

    cout << "Cuantas pizzas de tipo " << pizza[x].descripcion << " es el pedido? " << "\n";
    cin >> cantidad;
    descuento= pizza[x].precio*pizza[x].descuento;
    descuentototal=descuento*cantidad;
    total=(pizza[x].precio - descuento)*cantidad;
    if (cantidad >=1) {
      cout << "El total a pagar es: " << total << "\n";
      pizza[x].pedidas=pizza[x].pedidas+cantidad;
    }
    getchar();
    getline(cin, vacio);

    // Creamos el archivo si no existe o abrimos el archivo en modo append
    ofstream archivo("pizzas.txt", ios::out|ios::app);
    
    // Si existe algun error de apertura en el archivo, muestra error
    if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	  }

    // Grabamos nuestro vector en una linea del archivo
    archivo << pizza[x].tipo << "\t" << pizza[x].descripcion << "\t" << pizza[x].precio << "\t" << "\t"  << cantidad << "\t" << descuento << "\t" << total << "\n";
    
    //cerramos el archivo
    archivo.close();

  }
}

// Realizamos la funcion de reporte
void reporte(){
  //declaramos la clase archivo, 
  ifstream archivo;
  
  // abrimos archivo pizza.txt
  archivo.open("pizzas.txt",ios::in);
  
  // Si existe algun error de apertura en el archivo, muestra error
  if(archivo.fail()){
  cout<<"No se pudo abrir el archivo";
  exit(1);
  }

  string linea;

  cout << "#   Desc    Precio  Cant Des Total" << endl;
  cout << "======================================" << endl;
  //hacemos un ciclo, mientras exista una linea
  while(getline(archivo,linea))
  {
    // mostramos la lina en pantalla
    cout << linea << endl;
  }

  //Cerramos el arhivo.
  archivo.close();
  cout << "========================================" << endl;
  // Declaramos la variables que muestra la venta total, descuento 
  // porcentaje
  float total, descuento, porcentaje;
  float totalglobal=0;

  for (int x=0; x<pizza.size(); x++){
    // Iniciamos las variables para cada tipo de pizza
    total=0;
    descuento=0;
    porcentaje=0;

    // mostramos el resultado
    cout << "Pizza de tipo " << pizza[x].descripcion << ": \t" << pizza[x].pedidas << "\n";
    
    // obtenemos el total de descuento por producto
    descuento=pizza[x].precio*pizza[x].descuento*pizza[x].pedidas;
    
    // obtenemos el total de venta incluyendo el descuento
    total=(pizza[x].precio*pizza[x].pedidas)-descuento;
    
    // obtenemos el porcentaje de total de venta del producot
    porcentaje = pizza[x].descuento * 100;
        
    // obtenemos el totalglobal de venta
    totalglobal=totalglobal+total;
    
    // mostramos el reporte por por producto
    cout << "Total de venta:" << total << "\n";
    cout << "Total de descuentos " << descuento <<  "\n";
    cout << "Con el porcentaje de "<< porcentaje << "%" << "\n";
    cout << "========================================" << "\n";
  }

  // al finalizar el for, mostramos el total de venta global
  cout << "El total de venta es de " << totalglobal << "\n";

  // hacemos una pausa
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
        cout << "Pizzeria" << endl;
        cout << "-----------" << endl << endl;
        cout << "\t1 .- Agregar Pedido" <<endl;
        cout << "\t2 .- Mostrar Reporte" <<endl;
        cout << "\t3 .- Salir" << endl << endl;
        cout << "Elije una opcion: ";
 
        cin >> tecla;
 
		switch(tecla)
    		{
			case '1':
				system("clear");
        pedido();
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
  // iniciamos el vector de Pizzas con valores de 0;
  // esta es la primera funcion declarada
  inicio_pizzas();
  // llamamos el menu
  menu();
  return 0;
}
