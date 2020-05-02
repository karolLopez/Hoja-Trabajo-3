/*
Un empresa que se dedica a la venta de seguros de vehiculos, calcula el importe
según el modelo y color del automovil, asi como la edad del conductor.

Modelo       Color             Precio
A              Blanco           240.50
                  Metalizado    330.00
                Otros             270.50
B               Blanco          300.00
                 Metalizado     360.50
                 Otros             330.00
           
Incremento de precio
Edad            % Incremento
<31                    25%
Entre 31 y 65    0%
>65                   30%

Determine el importe a pagar mostrandolo en pantalla según los datos del vehículo (modelo y color)
y la edad del conductor.

Grabe los datos a un archivo.
*/
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include<ctime> 
#include <stdio.h>
#include <vector>
using namespace std;

struct Automoviles{
  string modelo;
  int color[3];
  float precio[3];
};

std::vector<Automoviles> automovil;

string colorstr(int x){
  string var;
  if (x==1){
    var="Blanco";
  }
  else if (x==2) {
    var="Metalizado";
  }
  else if (x==3) {
    var="Otro";
  }
  return var;
}

void inicio_auto(){
  automovil.push_back({"A",{1,2,3},{240.50,330.00,270.50}});
  automovil.push_back({"B",{1,2,3},{300,360.50,330}});
}

float calculo_incremento(int edad, float precio){
  
  if (edad<31){
    precio=(precio*0.25)+precio;
    cout << "Cargo del 25%" << "\n";
  }
  else if ((edad>=31) and (edad<=65)) {
    precio=precio;
    cout << "Cargo del 0%" << "\n";
  }
  else {
    precio=(precio*0.30)+precio;
    cout << "Cargo del 30%" << "\n";
  }
  return precio;
}

void cotizador(){
  string nombre, strcolor;
  int edad, indicev, indicea, color;
  float total;
  bool control=false;
  fflush(stdin);
  getchar();
  cout << "Ingrese Nombre de la persona: " << "\n";
  fflush(stdin);
  getline(cin,nombre);
  cout << "Ingrese la Edad de "<< nombre << "\n";
  cin >> edad;
  while (control==false){
    string var1;
    cout << "Ingrese el Modelo del vehiculo (A ó B) ?" << "\n";
    cin >> var1;
    if ((var1=="A") or (var1=="a")){
      indicev=0;
      control=true;
    }
    else if ((var1=="B") or (var1=="b")){
      indicev=1;
      control=true;
    }
  }
  
  string var1;
  cout << "Ingrese # del Color del vehiculo del vehiculo: \n";
  cout << "1\t -- Blanco \n";
  cout << "2\t -- Metalizado \n";
  cout << "3\t -- Otros \n";

  control=false;
  while (control==false){
    cin >> color;
    strcolor=colorstr(color);
    color=color-1;
    if ((color>=0) and (color<=2)){
      control=true;
    }
    else{
      cout << "Ingrese nuevamente (1,2,3): \n";
    }
  }
  
  total=calculo_incremento(edad, automovil[indicev].precio[color]);
  cout << "Total a pagar: " << total << "\n";
  string empty;
  getchar();
  getline(cin, empty);

  ofstream archivo("automoviles.txt", ios::out|ios::app);  
  if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
  archivo << nombre << "\t" << edad << "\t" << automovil[indicev].modelo << "\t" << strcolor << "\t" << total << "\n";
  archivo.close();
}

void menu(){
  char tecla;
  string empty;
  bool bandera=false;
  
  do
    {
        system("clear");
        cin.clear();
        cout << "Seguros de vehiculo" << endl;
        cout << "-----------" << endl << endl;
        cout << "\t1 .- Calculo de Poliza" <<endl;
        cout << "\t2 .- Salir" << endl << endl;
        cout << "Elije una opcion: ";
 
        cin >> tecla;
 
		switch(tecla)
    		{
			case '1':
				system("clear");
        fflush(stdin);
        cotizador();
        break;
 
      case '2':
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
  inicio_auto();
  menu();
  return 0;
}
