#include <iostream>
#include <string>
#include <fstream>
#include "operacionesMatriciales.h"
#include <iomanip>
using namespace std;

void print_vector(const vector<double>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}

void print_matrix(const matrix& matriz) {
	for (int i = 0; i < matriz.numfilas(); i++) {
		for (int j = 0; j < matriz.numcolumnas(); j++) {
			cout << matriz.get(i, j) << "  ";
		}
		cout << endl;
	}
}

void salida(double p, const vector<double>& vec, const char* myFile){
	//Hace la salida con formato del enunciado
	ofstream myWriteFile(myFile);
	
	if(myWriteFile.is_open()){
		myWriteFile << p <<endl;
		int i=0;
		myWriteFile << fixed << setprecision(15);
		while(i<vec.size()){
			myWriteFile << vec[i] << endl;
			i++;
		}
		
	}
	myWriteFile.close();
}

