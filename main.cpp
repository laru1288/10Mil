#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "locale.h"
using namespace std;

#include "rlutil.h"
#include "funciones.h"
using namespace rlutil;

int main(){
int dados[6],cjugadores;
int opcion=0,Maxpoint=0,rondas=11, i;
char NombreMax[25];
bool azar=false;

rlutil::setBackgroundColor(5);
rlutil::setColor(BLACK);
if (opcion==0){
system ("cls");
bienvenida();
system("pause");
}
do{
system("cls");
bienvenida();
cout<<"Ingrese la opcion deseada:"<<endl;
cout<<"1. Juego de 1."<<endl;
cout<<"2. Juego de 2."<<endl;
cout<<"3. Juego de 3."<<endl;
cout<<"4. Mejor Puntuacion."<<endl;
cout<<"5. Reglas. "<< endl;
cout<<"0. Salir del juego"<< endl;
cout<<"OPCION:"<<endl;
cin>>opcion;
cin.ignore();
system("cls");

switch(opcion){
case 0: return 0;
case 1:cjugadores=opcion;
     Juego(cjugadores,dados,Maxpoint,rondas,azar, NombreMax);
break;
case 2:cjugadores=opcion;
    Juego(cjugadores,dados,Maxpoint,rondas,azar, NombreMax);
break;
case 3:cjugadores=opcion;
    Juego(cjugadores,dados,Maxpoint,rondas,azar, NombreMax);
break;
case 4: system("cls");
    if(Maxpoint==0) cout<<endl<<endl<<"\t"<<"-QUE MEJOR PUNTUACION QUERES SI TODAVIA NO JUGASTE??,JUGATE UNA PARTIDA MASTER ;) "<<endl<<endl<<endl;
        else cout<<"MEJOR PUNTUACION: "<<NombreMax<<" \t "<<rondas<<"\t"<<Maxpoint<<endl;
system("pause");
break;
case 5 : reglas();
break;
default:
    cout<<"Esta opcion es incorrecta"<<endl;

}
}while (opcion!=0);

return 0;
}
