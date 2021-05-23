#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define M 25
void Juego(int cjugadores,int dados[],int &Maxpoint,int &rondas,bool azar, char  NombreMax[]);

void LanzarDados(int v[],int tam);

void MostrarDados(int v[],int tam, int i);

void CargarNombre(char N[][M],int tam);

int combinaciones (int dados [],int tam );

void CargarDados(int dados[],int tam);

void entreturnos ( char nombre [] [M],int rondas, int vpuntosjugadores[],  int cjugadores, int x);

void reglas ();

void bienvenida ();

int BuscarMayor(int &ganador,int puntostotal[],int cjugadores);

void Buscar_Mejor_Puntuacion(char Nombres[][M],char NombreMax[],int round[],int &rondas,int puntostotal[],int &Maxpoint,int ganador);

void recuadro ( int x, int y, int ancho, int alto);

void dibujardado ( int numerodado , int valor );

void colores (int i);
#endif // FUNCIONES_H_INCLUDED
