#include <time.h>
#include <windows.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
//-----------------------------------------------------------------//
class Ficha{
	private:
		char etiqueta;
		char simbolo;
	public:
		Ficha();
		Ficha(char);
		void setSimbolo(char);
		char getSimbolo();
		void getEtiqueta();
		void dibujarse();
}
Ficha::Ficha(){
	etiqueta = ' ';
	simbolo = ' ';
}

Ficha::Ficha(char etiqueta){
	this -> etiqueta = etiqueta;
}
void Ficha::setSimbolo(char simbolo){
	this -> simbolo = simbolo;
}

char Ficha::getSimbolo(){
	return simbolo;
}

char Ficha::getEtiqueta(){
	return etiqueta;
}

void Ficha::dibujarse(){
	cout << simbolo;
}

//-----------------------------------------------------------------//

class Tablero{
	private:
		Ficha matriz[3][3];
	public:
		Tablero(string);
		void dibujarse();
		Ficha* obtenerFicha(char);
		bool verificarTriquiFilas(int &fila);
		bool verificarTriquiCols(int &cols);
		bool verificarTriquiDiags(int &diag);
}
Tablero::Tablero(string etiquetas){
	int indice = 0;
	for(int i = 0; i < 3;i++){
		for (int j = 0; j < 3; j++){
			matriz[i][i].setEtiqueta(etiquetas[indice]);
			indice ++;
		}
	}
}
void Tablero::dibujarse(){
	for(int i = 0; i < 3;i++){
		for (int j = 0; j < 3; j++)
			cout << " | " << matriz[i][i].getSimbolo();
		cout <<"|"<<endl
	}
}

Ficha* Tablero::obtenerFicha(char etiqueta){
	for(int i = 0; i < 3;i++){
		for (int j = 0; j < 3; j++){
			if (matriz[i][j].etiqueta == etiqueta)
				return *matriz[i][j];
		}
	}
}

bool Tablero::verificarTriquiFilas(int &fila){
	for(int i = 0; i < 3;i++){
		if ((matriz[i][0].simbolo == matriz[i][1].simbolo) && (matriz[i][1].simbolo == matriz[i][2].simbolo)){
			fila = i
			return TRUE;
		}
	}
	return FALSE;
}

bool Tablero::verificarTriquiCols(int &cols){
	for(int i = 0; i < 3;i++){
		if ((matriz[0][i].simbolo == matriz[1][i].simbolo) && (matriz[1][i].simbolo == matriz[2][i].simbolo)){
			cols = i
			return TRUE;
		}
	}
	return FALSE;
}

bool Tablero::verificarTriquiDiags(int &diag){
	if ((matriz[0][0].simbolo == matriz[1][1].simbolo) && (matriz[1][1].simbolo == matriz[2][2].simbolo)){
		diag = 1;
		return TRUE;
	}
	else if((matriz[0][2].simbolo == matriz[1][1].simbolo) && (matriz[1][1].simbolo == matriz[2][0].simbolo)){
		diag = 2;
		return TRUE;
	}
}

//-----------------------------------------------------------------//

 class Jugador{ //Herencia Ojo
 	private:
 		char simbolo;
 	public:
 		Jugador(char);
 		char getSimbolo();
}

Jugador::Jugador(char simbolo){
	this -> simbolo = simbolo;
}

char Jugador::getSimbolo(){
	return simbolo;
}

class Persona : public Jugador{
	public:
	char nextJugada()
}

char Persona::nextJugada(){
	char jugada;
	cout << "Jugada >> ";
	cin >> jugada;
	cout << endl;
	return jugada;
}

class Maquina:: public Jugador{
	char nextJugada(Tablero*)
}

char Maquina::nextJugada(Tablero* tb){ //Ojo punteros
	string posibles[6]; 
	char jugada;
	for(int i = 0; i < 0; i++){
		for (int j = 0; j < 0; j++){
			if (tb->matriz[i][j].getSimbolo() == ' '){
				posibles[indice] = tb->matriz[i][j].getEtiqueta()
				indice++;
			}
		}
	}
	jugada = string[rand()%(indice+1)];
	return jugada;
}