#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <fstream>
using namespace std;
void factura();
int main ();
struct supermercado
{
int cant;
double precio;
string nombre_p;
}
super[10];
char name[75];
ofstream entrada;        //En esta parte del codigo, se estan declarando las variables a utilizar
ofstream entrada1;
ifstream entrada2("ProductosSuperFeo.txt");
float totalv = 0;
double totalar = 0;
double total = 0, isv = 0;
char resp;
int j=0;
int resp2=1;
int conj=0;
void registrar()
{
float totalv = 0;
double totalar = 0;
double total = 0, isv = 0;
string nomb;
int cod;
int i=0;
int j=0;
int cant1=0;
int cant11=0;
cout << "Bienvenido, ingrese los articulos a comprar (no superar el limite de 5) : ";
cin >> resp2;
if (resp2>=6) //Con este if estamos diciendo que si la cant. de art supera a 6, se terminara el programa 
{
system("cls");
cout << "Error, cantidad excedida de articulos\nGracias por preferirnos";
main();
}
else
{
for(i=0; i<=resp2;i++)
{
do
{
cout << "Ingrese el codigo de articulo: " << endl;
cin>>cod;
switch(cod) //y empezamos a declarar todos los switch
{
case 1: super[i].nombre_p="Sandia";
entrada << "Nombre producto: " <<super[i].nombre_p ;
super[i].precio=5.5;
do{
cout << "Ingrese cantidad que se vende: " << endl;
cin >> super[i].cant;
if(super[i].cant>resp2)
cout<<"Cantidad sobrepasa los articulos que lleva "<<endl;
}while(super[i].cant>resp2);
entrada << "cantidad " << super[i].cant << endl;
entrada1 << super[i].cant << " ";
break;
case 2: super[i].nombre_p="Gillete";
entrada << "Nombre producto: " <<super[i].nombre_p;
super[i].precio=6.5;
do{
cout << "Ingrese cantidad que se vende: " << endl;
cin >> super[i].cant;
super[i].cant>resp2;
cout<<"Cantidad sobrepasa los articulos que lleva "<<endl;
}while(super[i].cant>resp2);
break;
case 3: super[i].nombre_p="Manzana";
entrada << "Nombre producto: " <<super[i].nombre_p;
super[i].precio=5.2;
do{
cout << "Ingrese cantidad que se vende: " << endl;
cin >> super[i].cant;
if(super[i].cant>resp2)
cout<<"Cantidad sobrepasa los articulos que lleva "<<endl;
}while(super[i].cant>resp2);
break;
case 4: super[i].nombre_p=" Huevos ";
entrada << "Nombre producto: " <<super[i].nombre_p;
super[i].precio=3.8;
do{
cout << "Ingrese cantidad que se vende: " << endl;
cin >> super[i].cant;
if(super[i].cant>resp2)
cout<<"Cantidad sobrepasa los articulos que lleva "<<endl;
}while(super[i].cant>resp2);
break;
case 5: super[i].nombre_p=" Leche ";
entrada << "Nombre producto: " <<super[i].nombre_p;
super[i].precio=22.8;
do{
cout << "Ingrese cantidad que se vende: " << endl;
cin >> super[i].cant;
if(super[i].cant>resp2)
cout<<"Cantidad sobrepasa los articulos que lleva "<<endl; //Este mensaje saltara en la pantalla, si se supera el numero de productos
}while(super[i].cant>resp2);
break;
default:cout<<"Solo existen articulos del 1-10"<<endl;
break;
}
}while(cod>10);
conj++;
j=super[i].cant+j;
if(j>=resp2)
{
i=11;
factura();
}
}
}
}
void factura()
{
float totalv = 0;
double totalar = 0;
double total = 0, isv = 0;
system("cls");
cout << "\t-------------------Factura---------------------------------\t" << endl;
cout << "Nombre: " << name << endl;
cout << "Cant/Arti " << "\t " << "Nom/Art" << " \t " << " Precio " << endl;
for(int i=0; i<=conj-1;i++)
{
cout << super[i].cant << " \t " << super[i].nombre_p << " \t " << super[i].precio << endl;
totalv = totalv + (super[i].precio * super[i].cant);
totalar = totalar + super[i].cant; //Las operaciones que se utilizaran para sacar los precios de los productos 
total = totalv;
}
entrada << "Total " << total << " " << endl;
entrada1 << total << " ";
entrada << "**************************" << endl;
cout << "---------------------------------------------------" << endl;
cout << "Subtotal: " << totalv << endl;
cout << "Total de articulos vendidos: " << totalar << endl;
cout << "Total: " << total << endl;
system("PAUSE");
entrada.close();
do
{
system("cls");
cout<<"Desea ingresa otra compra "<<endl;
cin>>resp;
resp=toupper(resp);
if(resp=='S')
{
resp2=0;
j=0;
conj=0;
main();
}
}while(resp=='S');
}
int main()
{
entrada.open("ProductosSuper.txt", ios::out | ios::app);
entrada1.open("ProductosSuperFeo.txt", ios::out | ios::app);
if ((entrada.fail()) && (entrada1.fail()))
{
cout << "ERROR AL ABRIR EL ARCHIVO" << "\n";
}
else
{
cout << "Mercado premium para pasar la materia :  " << endl;
cout << "Para finalizar ingrese 0 " << endl;
cout << "Ingrese nombre: " << endl;
cin >> name;
entrada << " Nombre factura: " << name << " ";
entrada1 << name << " ";
registrar();
return 0;
}
}