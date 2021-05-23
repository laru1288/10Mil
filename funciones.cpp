#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#define M 25
using namespace std;

#include "rlutil.h"
#include "funciones.h"
using namespace rlutil;

//FUNCION JUGAR
void Juego(int cjugadores,int dados[],int &Maxpoint,int &rondas,bool azar , char  NombreMax[]){
int Mayor,posiciones[cjugadores],cposiciones=0,aux;
int x,b, tam=6, round[cjugadores], tamn=25, puntos=0, puntostotal[cjugadores]{0}, clanzamientos, puntosronda,ganador=-1,i;
char opcion;
char Nombres[cjugadores][M];
bool seguir=true;



// cargamos el nombre de los jugadores
CargarNombre(Nombres,cjugadores);

system("cls");

//for de las 10 rondas
for(x=1;x<=10; x++){
        //for de turnos
   for(i=0;i<cjugadores;i++){
    b=puntosronda=clanzamientos=0;
if(x==11)cout<<"Ronda "<<aux<<"   |\t"<<" Turno de: " <<Nombres [i]<<endl;
else cout<<"Ronda "<<x<<"   |\t"<<" Turno de: " <<Nombres [i]<<endl;
seguir=1;
//while de lanzamientos de dados
while(seguir) {


if(b==0) cout<<"Lanzar dados (S)"<<endl;
else cout<<"Continuar lanzando? (S/N)"<<endl;
cout<<"Abadonar partida (Q)"<<endl;
b=1;
cin>>opcion;
system ("cls");


//  switch de opcion seguir tirando dados o abandonar
switch(opcion){
case 's' : case 'S':
                       colores (i);
                        system ("cls");
        clanzamientos++;
        if(x==11)cout<<"Turno de " <<Nombres[i]<<"   |\t"<<"Ronda "<<aux<<" | "<<"\t"<<"Puntaje total: "<<puntostotal[i]<<" puntos"<<endl;
        else cout<<"Turno de " <<Nombres[i]<<"   |\t"<<"Ronda "<<x<<" | "<<"\t"<<"Puntaje total: "<<puntostotal[i]<<" puntos"<<endl;
        cout<<"--------------------------------------------------------------------------"<<endl;
        cout<<"Puntaje de la ronda: "<<puntosronda<<endl;
        cout<<"Lanzamiento Numero: "<<clanzamientos<<endl;
        cout<<"--------------------------------------------------------------------------"<<endl;
        // llamado de la funcion de lanzmaientos de dados o cargarlos manualmente
        if(azar)LanzarDados(dados,tam);
        else CargarDados(dados,tam);
        cout<<endl;
        colores (i);
        puntos=combinaciones (dados, tam);
        cout<<"Obtuviste "<<puntos<<" puntos"<<endl;
        cout << endl;

        if(puntos==10000){
            cout<<"GANASTE!!!"<<endl;
            puntostotal[i]=puntos;
           cout<<"Has ganado en la ronda "<<x<<" con un total de "<<puntostotal [i]<<"puntos."<<endl;
             seguir=0;
             round[i]=x;

             x=11;
             ganador=i;

        }else {
        puntosronda+=puntos;
        round[i]=x;
        if(puntosronda+puntostotal[i]>10000 || puntos==0){
         seguir=0;
         puntosronda=0;

        }
        if(puntosronda+puntostotal[i]==10000){
            cout<<"Felicitaciones llegastes a los 10000 puntos!!!!!!!!!"<<endl<<endl<<endl;
            round[i]=x;
            seguir=0;
            aux=x;
            x=11;
            system("pause");
        system("cls");
        }

       break;

case 'q': case 'Q':
    i=cjugadores+1;
    x=11;
    seguir=0;
    break;

case 'n': case 'N':
    seguir=0;
    break;
}


}


}
puntostotal[i]+=puntosronda;
//terminacion de ronda

if (x!=11){

entreturnos ( Nombres,x, puntostotal,cjugadores, i);
system("pause");
system("cls");
}
}
rlutil::setBackgroundColor(5);
rlutil::setColor(BLACK);
system("cls");
}



if(ganador==-1){
    ///Busca el Mayor puntaje para saber quien gana
   Mayor=BuscarMayor(ganador,puntostotal,cjugadores);

   // for para saber si hay empates
for(x=0;x<cjugadores;x++){
 if(Mayor==puntostotal[x]){
    posiciones[cposiciones]=x;
    cposiciones++;

 }

}
   }



system("cls");


cout<<endl;
cout<<"------------------"<<endl;
cout<<"Fin la partida. "<<endl;
cout<<"------------------"<<endl;
cout<<endl<<endl;
if(x<11){
//if para abandonar la partida
if (opcion!='Q'){
    if (opcion!='q' ){
 if(cposiciones==1) {
cout<<"Ganador:"<<endl;
cout<<Nombres[ganador]<<endl;
cout<<"-------------------------------------------------------------------------"<<endl;
cout<<"Rondas jugadas: "<<round[ganador]<<endl;
cout<<"-------------------------------------------------------------------------"<<endl;
cout<<"Puntos de ganador: "<<puntostotal[ganador]<<endl;
 }else{
    cout<<endl;
   cout <<"Hubo un empate entre: "<<endl ;
    for (x=0; x<cposiciones;x++){
        cout<<endl<<endl;
        cout<<"-"<<Nombres[posiciones[x]]<<endl;
        cout<<endl;
    }
 }
Buscar_Mejor_Puntuacion(Nombres,NombreMax,round,rondas,puntostotal,Maxpoint,ganador);
  }
}
}

system("pause");

}


//FUNCION LANZAR DADOS
void LanzarDados(int v[],int tam){
int x, r;
srand(time(NULL));

	for(x=1;x<=tam;x++){
        v[x-1]= 1 + rand() % tam ;
        r=v[x-1];
        dibujardado ( x, r);

	}

}

// FUNCION CARGAR NOMBRE
void CargarNombre(char N[][M],int tam){
int x;
for(x=0;x<tam;x++){
cout<<"Ingrese Nombre del jugador "<<x+1<<": ";
cin.getline(N[x],25);
cout<<endl;
}
}
//FUNCION COMBINACIONES DE DADOS
int combinaciones (int dados [],int tam ) {
    int puntajes[9] {0}, puntos, trio=0, trio1=0, trio2=0, triomas, cdos=0, ccuatro=0,cseis=0,dtrio=0, mayor=0;
    int suma=0, i,x, vcontador[6] {0}, p[6]{0}, r=0;
    bool escalera;
   cout<<endl<<endl<<endl<<endl<<endl<<"Sacaste:"<<endl;

// contador de cuantos hay de cada numero de dados
  for (i=1; i<=6; i++) {
        for (x=0; x<6; x++){
           if ( dados[x]==i) {
            vcontador[i-1]++;
           }
        }
}

if (vcontador[0]==0 && vcontador[2]==0 && vcontador[4]==0){
    mayor=0;
}
else{
if (vcontador[0]==6){
    puntajes[0]=10000;
    cout <<"- SEXTETO, MAQUINA, IDOLO,MASTER,CAPO,EMINENCIA!!!!  "<<endl<<endl;
    system("pause");
}
if (vcontador[0]==1||vcontador[0]==2){
    puntajes[8]=100*vcontador[0];
    cout <<"- Juego de 1."<<endl;
}
if (vcontador[0]==3){
    puntajes[6]=1000;
    cout <<"- Trio de 1."<<endl;
}
if (vcontador[0]==4||vcontador[0]==5){
    puntajes[3]=2000;
    cout <<"- Trio de 1 ampliado."<<endl;
}
if (vcontador[4]==1||vcontador[4]==2){
    puntajes[7]=50*vcontador[4];
    cout <<"- Juego de 5."<<endl;
}
for (i=0; i<6; i++){
        for (x=0; x<6; x++){
             if ( dados[x] == dados [i]) {
                p[i]++;
             }

        }
        r+=p[i];
    }

    escalera=(6==r);
if(escalera){
    puntajes[1]=1500;
    cout <<"- Escalera."<<endl;
}

for (i=1; i<6; i++){
    if(vcontador[i]==3){
        if(trio==0){
        trio1=i+1;
        puntajes[5]=trio1*100;
        trio=1;
        }else{
        trio2=i+1;
        puntajes[5]=trio2*100;
        trio=2;
        }
}
}
if(trio==1){
    cout <<"- Trio de "<<trio1<<endl;
    }
if(trio==2){
    cout <<"- Trio de "<<trio1<<endl;
    cout <<"- Trio de "<<trio2<<endl;
    }
for (i=1; i<6; i++){
    if(vcontador[i]==4||vcontador[i]==5){
     puntajes[4]=vcontador[i]*200;
     triomas=i+1;
    }
}
if(puntajes[4]>0){
    cout <<"- Trio++ de "<<triomas<<endl;
}
for(i=0; i<6; i++){
    if(vcontador[i]==2){
        cdos++;
    }
    if(vcontador[i]==4){
        ccuatro++;
    }
    if(vcontador[i]==6&&i!=0){
        cseis++;
    }
}

if(cdos==3||(ccuatro==1&&cdos==1)||cseis==1){
    puntajes[2]=1000;
    cout <<"- Tres pares."<<endl;
}

for(i=0; i<9; i++){
    if(puntajes[i]>mayor){
        mayor=puntajes[i];
    }
}
}
if(mayor==0){
        cout<<"- Mala suerte no obtuvo ninguna combinacion ganadora :(  F"<<endl;
        system("pause");
        system("cls");

}

return mayor;
}
//FUNCION CARGAR DADOS MANUALMENTE
void CargarDados(int dados[],int tam){
int x, i,r;
cout<<"Cargue los dados:";
for(x=0;x<tam;x++){
        cout<<endl;
    cin>>dados[x];

    }
 for (i=1; i<=6;i++){
  r=dados[i-1];
    dibujardado(i,r);
 }

}

// FUNCION ENTRE TURNOS
void entreturnos ( char nombre [] [M],int rondas, int vpuntosjugadores[],  int cjugadores, int exis){
cout <<"RONDA NUMERO: " << rondas << endl;
if (exis!=cjugadores-1){
cout << "PROXIMO TURNO: " << nombre[exis+1]<< endl;}
else {
    cout<<"RONDA FINALIZADA"<<endl;
    if (rondas==9) {
        cout << "FIN DE LA PARTIDA" << endl;
    } else{
         cout << "PROXIMO TURNO: " << nombre[0]<< endl;
    }
}

int i;

cout <<"---------------------------------------------------------------------------"<< endl;
for (i=0; i<cjugadores; i++) {

      cout << "PUNTAJE DE "<< nombre [i] << ": " <<vpuntosjugadores[i]<< endl;
}
}


//FUNCION BIENVENIDA
 void bienvenida () {
 cout <<"-----------------------------------------------------------------------"<< endl;
 cout <<"                     BIENVENIDO A DADOS 10MIL                          "<<endl;
 cout <<"-----------------------------------------------------------------------"<< endl;


 }

//FUNCION DE REGLAS DE JUEGO
void reglas (){
 cout <<"-----------------------------------------------------------------------------------------------------------------------"<< endl;
 cout <<"                                             REGLAS DEL JUEGO                                                          "<<endl;
 cout <<"-----------------------------------------------------------------------------------------------------------------------"<< endl;
cout<<"- El objetivo del juego es obtener 10000 puntos en la menor cantidad de rondas posibles."<<endl<<endl ;
cout<<"- Una ronda puede estar compuesta por varios lanzamientos."<<endl<<endl;
cout<<"- Un lanzamiento consiste en tirar seis dados y evaluar sus valores para determinar el puntaje."<<endl<<endl;
cout<<"- Si en un lanzamiento el jugador obtiene una combinacion ganadora entonces acumulara provisoriamente"<<endl;
cout<<"el puntaje correspondiente."<<endl<<endl;
cout <<"- Luego de un lanzamiento ganador, el jugador debe elegir si desea volver a lanzar los dados o asegurarse"<<endl;
cout<<"el puntaje acumulado hasta el momento."<<endl<<endl;
cout<<"- Si en un lanzamiento el jugador no obtiene una combinacion ganadora perdera todo el puntaje acumulado de esa ronda"<<endl;
cout<<"y sera el turno del otro jugador."<<endl<<endl;
cout<<"-Cuando un jugador obtiene exactamente 10000 puntos, el juego termina. Si un jugador se excede de los 10000 puntos"<<endl;
cout<<"volvera al puntaje que tenia previamente al comenzar la ronda."<<endl<<endl;

cout<<"Combinacion                                      Nombre jugada           Puntaje otorgado"<<endl;
cout<<"1 o 2 dados con valor 1                          Juego de 1              100 puntos por cada dado con el valor 1"<<endl;
cout<<"1 o 2 dados con valor 5                          Juego de 5              50 puntos por cada dado con valor 5 "<<endl;
cout<<"3 dados con valor 1                              Trio 1                  1000 puntos"<<endl;
cout<<"3 dados con el mismo valor                       Trio X                  X*100 puntos"<<endl;
cout<<"4 o 5 dados con el mismo valor (excepto el 1)    Trio X++                X*200 puntos"<<endl;
cout<<"4 o 5 dados con el valor 1                       Trio 1 ampliado         2000 puntos"<<endl;
cout<<"Tres pares                                       Tres pares              1000 puntos"<<endl;
cout<<"Escalera de 6 dados(1, 2, 3, 4, 5, 6)            Escalera larga          1500 puntos"<<endl;
cout<<"Seis unos                                        Sexteto                 Gana la partida en esa ronda"<<endl;
system ("pause");

}

void Buscar_Mejor_Puntuacion(char Nombres[][M],char NombreMax[],int round[],int &rondas,int puntostotal[],int &Maxpoint,int ganador){

// para saber si tiene la mejor puntuacion
if(puntostotal[ganador]>Maxpoint){
    Maxpoint=puntostotal[ganador];
    rondas=round[ganador];
    strcpy( NombreMax, Nombres[ganador]);
}else if(puntostotal[ganador]==Maxpoint){
if(round[ganador]<rondas){
    Maxpoint=puntostotal[ganador];
    rondas=round[ganador];
    strcpy( NombreMax, Nombres[ganador]);

}
}

}












 int BuscarMayor(int &ganador,int puntostotal[],int cjugadores){
  int x,Mayor;

   for(x=0;x<cjugadores;x++){
   if(x==0){
    Mayor=puntostotal[x];
    ganador=x;

   }
//para saber si hay mas de un jugador
   else{
   if(puntostotal[x]>Mayor){
     Mayor=puntostotal[x];
     ganador=x;



   }
 }
}
return Mayor;
}
// FUNCION RECUADRO
 void recuadro ( int x, int y, int ancho, int alto){
    const char *UI_BOTTOM_RIGHT = "\xD9"; // 217 - ┘
    const char *UI_BOTTOM_LEFT = "\xC0"; // 192 - └
    const char *UI_TOP_LEFT = "\xDA"; // 218 - ┌
    const char *UI_TOP_RIGHT = "\xBF"; // 191 - ┐
    const char *UI_CROSS = "\xC5"; // 197 - ┼
    const char *UI_HORIZONTAL_LINE = "\xC4"; // 196 - ─
    const char *UI_HORIZONTAL_LINE_TOP = "\xC1"; // 193 - ┴
    const char *UI_HORIZONTAL_LINE_BOTTOM = "\xC2"; // 194 - ┬";
    const char *UI_VERTICAL_LINE = "\xB3"; // 179 - │
    const char *UI_VERTICAL_LINE_LEFT = "\xC3"; // 195 - ├
    const char *UI_VERTICAL_LINE_RIGHT = "\xB4"; // 180 - ┤

    int i, j;
     for (i=x; i<=x+ancho; i++){
        for (j=y; j<=y+alto; j++){

          setBackgroundColor(WHITE);
            locate (i,j);
            cout <<" "; }

    }
/*
// lineas horizontales
   for (i=x; i<x+ancho; i++){
    locate (i,y);
    cout<<UI_HORIZONTAL_LINE;
    locate (i, y+alto);
    cout<<UI_HORIZONTAL_LINE;
   }

// lineas verticales
    for (i=y; i<y+alto; i++){
    locate (x,i);
    cout<<UI_VERTICAL_LINE;
    locate (x+ancho, i);
    cout<<UI_VERTICAL_LINE;
   }

// vertices
  locate (x, y);
  cout<<UI_TOP_LEFT;
  locate (x, y+alto);
  cout<<UI_BOTTOM_LEFT;
  locate (x+ancho, y);
  cout<<UI_TOP_RIGHT;
  locate (x+ancho, y+alto);
  cout<<UI_BOTTOM_RIGHT;

*/
}

//funcion dibujar dados
void dibujardado ( int numerodado , int valor ){
   const int Y=8;
   const int ALTO=4;
   const int INI=5;
   const int X= INI + ( numerodado *10);
   const int ANCHO=8;

   // uBICACIONES DEL PUNTO
   const int CENTRO_X = X+ANCHO/2;
   const int CENTRO_Y = Y+ALTO/2;
   const int ARRIBA_X = CENTRO_X-2;
   const int ARRIBA_Y = CENTRO_Y-1;
   const int ABAJO_X = CENTRO_X +2;
   const int ABAJO_Y = CENTRO_Y+1;

   recuadro(X,Y,ANCHO,ALTO);


   switch (valor) {
   case 1:
         locate (CENTRO_X,CENTRO_Y);
         cout<<"*";
         break;
   case 2:
         locate (ARRIBA_X, ARRIBA_Y);
         cout<<"*";
         locate (ABAJO_X, ABAJO_Y);
         cout<<"*";
         break;
   case 3:
         locate (ARRIBA_X, ARRIBA_Y);
         cout<<"*";
         locate (CENTRO_X,CENTRO_Y);
         cout<<"*";
         locate (ABAJO_X, ABAJO_Y);
         cout<<"*";
         break;
   case 4:
         locate(ARRIBA_X, ARRIBA_Y);
         cout<<"*";
         locate (ABAJO_X,ABAJO_Y);
         cout<<"*";
         locate (ABAJO_X,ARRIBA_Y);
         cout<<"*";
         locate (ARRIBA_X, ABAJO_Y);
         cout<<"*";
         break;
   case 5:
         locate(ARRIBA_X, ARRIBA_Y);
         cout<<"*";
         locate(ABAJO_X,ABAJO_Y);
         cout<<"*";
         locate (CENTRO_X,CENTRO_Y);
         cout<<"*";
         locate (ABAJO_X,ARRIBA_Y);
         cout<<"*";
         locate (ARRIBA_X, ABAJO_Y);
         cout<<"*";
         break;
   case 6:
         locate(ARRIBA_X, ARRIBA_Y);
         cout<<"*";
         locate (ABAJO_X,ABAJO_Y);
         cout<<"*";
         locate (ABAJO_X,ARRIBA_Y);
         cout<<"*";
         locate (ARRIBA_X, ABAJO_Y);
         cout<<"*";
         locate (ABAJO_X, CENTRO_Y);
         cout<<"*";
         locate (ARRIBA_X, CENTRO_Y);
         cout<<"*";
         break;
   }

}

void colores ( int i){
             if (i==0){
             rlutil::setColor(BLACK);
             rlutil::setBackgroundColor(3); }

             if (i==1) {
                    rlutil::setColor(BLACK);
                    rlutil::setBackgroundColor(4);}
             if (i==2){
                       rlutil::setColor(BLACK);
                       rlutil::setBackgroundColor(8); }
}
