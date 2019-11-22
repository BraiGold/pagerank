#ifndef operacionesMatriciales_H
#define operacionesMatriciales_H

#include <vector>
#include <map>
#include <math.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

const double eps = 0.001;

class matrix {

	public:
		matrix();
		matrix(int rows, int columns);
		matrix(const matrix& mat);
		int numfilas() const;
		int numcolumnas() const;
		matrix& operator+(const matrix& mat);
		matrix& operator-(const matrix& mat);
		matrix operator*(const matrix& mat);
		matrix& operator*(double num);
		matrix& operator=(const matrix& mat);
		double get(const int x, const int y) const;
		void set(const int x, const int y, double elem);
		matrix transponer();
		void eliminacionGaussiana(vector < double > &terminoInd);
		void eliminacionGaussianaSinPivoteo(vector < double > &terminoInd);
		bool eq(double a, double b);
		vector < double > sustitucionParaAtras(const vector < double > &b); //para resolver sistema
		double cantidadDeLinksSalientes(int numPagina);

	private:
		int col;
		int row;
		vector < map < int, double > > filas;
		vector < map < int, double > > columnas;
		
		double multiplicarFilaPorColumna(int fil, const matrix& mat, int col);
		void sumarFilas(int i, int k, const matrix& mat, int j);
};

#endif
