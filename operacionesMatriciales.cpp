#include "operacionesMatriciales.h"

matrix::matrix() : row(0), col(0), filas(0), columnas(0) {
	
}

matrix::matrix(int rows, int columns) : filas(rows, map<int, double>()), columnas(columns, map<int, double>()) {
	this->col = columns;
	this->row = rows;
}

matrix::matrix(const matrix& mat) : row(mat.numfilas()), col(mat.numcolumnas()), filas(row, map<int, double>()), columnas(col, map<int, double>()){
	//cout << "estoy usando constr. x copia" << endl;
	//cout << mat.numcolumnas() << " " << mat.numfilas()<<" pepito"<<endl;
	//cout << numcolumnas() << " " << numfilas()<<" pepito"<<endl;
	//this->col = mat.numcolumnas();
	//this->row = mat.numfilas();
	for (int i = 0; i < mat.numfilas(); i++) {
		map<int, double>::const_iterator itFila = mat.filas[i].begin();
		map<int, double>::const_iterator itFilaFin = mat.filas[i].end();
		while ( itFila != itFilaFin ) {
			(*this).set(i, itFila->first, itFila->second);
			itFila++;
		}
	}
	//cout << "termine constr. x copia" << endl;
}

int matrix::numfilas() const {
	return this->row;
}

int matrix::numcolumnas() const {
	return this->col;
}

//asumo que son del mismo tamaño
matrix& matrix::operator+(const matrix& mat) {
	for (int i = 0; i < mat.numfilas(); i++) {
		for (int j = 0; j < mat.numcolumnas(); j++) {
			double elem = (*this).get(i, j);
			(*this).set(i, j, elem + mat.get(i, j));
		}
	}

	return (*this);
}

matrix& matrix::operator-(const matrix& mat) {
	for (int i = 0; i < mat.numfilas(); i++) {
		for (int j = 0; j < mat.numcolumnas(); j++) {
			double elem = (*this).get(i, j);
			(*this).set(i, j, elem - mat.get(i, j));
		}
	}

	return (*this);
}

matrix matrix::operator*(const matrix& mat) {
	matrix res(numfilas(), mat.numcolumnas());
	for(int i=0; i<numfilas();i++){
		for(int j=0; j<mat.numcolumnas();j++){
			double elem=(*this).multiplicarFilaPorColumna(i, mat, j);
			res.set(i,j,elem);
		}
	}
	
	return res;
}

matrix& matrix::operator*(double num){
	for(int i=0; i<numfilas(); i++){
		map<int, double>::iterator itFila = this->filas[i].begin();
		map<int, double>::iterator itFilaFin = this->filas[i].end();
		while( itFila!= itFilaFin){
			map<int, double>::iterator itFilaCopia = itFila++;
			(*this).set(i, itFilaCopia->first, num * (itFilaCopia->second) );
		}
	}
	return (*this);
}
matrix& matrix::operator=(const matrix& mat) {
	//cout << "estoy usando la asignacion"<<endl;
	//cout << mat.numcolumnas() << " " << mat.numfilas() << " ";
	
	if (this != &mat) {
		this->col = mat.numcolumnas();
		this->row = mat.numfilas();
		
		vector< map<int, double> > newfilas(mat.numfilas(), map<int, double>());
		filas=newfilas;
		vector< map<int, double> > newcolumnas(mat.numcolumnas(), map<int, double>());
		columnas=newcolumnas;
		
		for (int i = 0; i < mat.numfilas(); i++) {
			map<int, double>::const_iterator itFila = mat.filas[i].begin();
			map<int, double>::const_iterator itFilaFin = mat.filas[i].end();
			while ( itFila != itFilaFin ) {
				(*this).set(i, itFila->first, itFila->second);
				itFila++;
			}
		}
	}
	//cout << "termine la asignacion"<<endl;

	return (*this);
}

double matrix::get(const int x, const int y) const {
	if (this->filas[x].find(y) != this->filas[x].end()) {
		return (this->filas)[x].at(y);
	} else {
		return 0;
	}
}


void matrix::set(const int x, const int y, double elem) {
	if (fabs(elem) > eps) {//entra elem distinto a 0
		(this->filas[x])[y] = elem;
		(this->columnas[y])[x] = elem;
	}else if(this->filas[x].find(y) != this->filas[x].end()){//en x,y hay algo distinto a 0 y elem es 0
		(this->filas[x]).erase(y);
		(this->columnas[y]).erase(x);
	}
}

matrix matrix::transponer() {
	matrix res(this->col, this->row);
	
	for (int i = 0; i < this->row; i++) {
		map<int, double>::iterator itFila = this->filas[i].begin();
		map<int, double>::iterator itFilaFin = this->filas[i].end();
		while (itFila!=itFilaFin) {
			int j=itFila->first;
			res.set(j, i, get(i,j));
			itFila++;
		}
	}
	
	//algoritmo para trasponer si se recorre la summatriz principal mas grande y luego lo parte que falta  
	/*int min=(this->row <= this->col)? this->row : this->col;
	for (int i = 0; i < min; i++) {
		for (int j = 0; j <= i; j++) {
			res.set(j, i, get(i,j));
			res.set(i, j, get(j,i));
		}
	}
	
	if(min==this->row){
		for(int j = min; j < this->col; j++){
			for (int i = 0; i < min; i++) {
				res.set(j, i, get(i,j));
			}
		}
	}else{
		for(int i = min; i < this->row; i++){
			for (int j = 0; j < min; j++) {
				res.set(j,i, get(i,j));
			}
		}
	}*/
		
	return res;
}

double matrix::multiplicarFilaPorColumna(int fil, const matrix& mat, int col){
	map<int, double>::iterator itFila=this->filas[fil].begin();
	map<int, double>::iterator itFilaFin=this->filas[fil].end();
	
	map<int, double>::const_iterator itCol=mat.columnas[col].begin();
	map<int, double>::const_iterator itColFin=mat.columnas[col].end();
	
	double res=0;
	while(itFila!=itFilaFin && itCol!=itColFin){
		if(itFila->first == itCol->first){
			res=res+(itFila->second*itCol->second);
			itFila++;
			itCol++;
		}else{
			if(itFila->first < itCol->first){
				itFila++;
			}else{
				itCol++;
			}
		}
	}
	return res;
}

void matrix::eliminacionGaussianaSinPivoteo(vector<double> &terminoInd) {
	for (int i = 0; i < (*this).numfilas(); i++) {
		for (int j = i + 1; j < (*this).numfilas(); j++) {
			if (!eq((*this).get(j,i), 0)) {
				double k = (*this).get(j, i) / (*this).get(i, i);
				//a la fila j le resto k por fila i
				for (int col = i; col < (*this).numcolumnas(); col++) {//resto filas
					(*this).set(j, col, (*this).get(j, col) - k*(*this).get(i, col));
				}
				terminoInd[j] = (terminoInd[j] - k*terminoInd[i]);//resto los numeros a la derecha del igual
			}
		}
	}
}

void matrix::eliminacionGaussiana(vector<double> &terminoInd) {
	int h = 0;
	int k = 0;
	while (h < (*this).numfilas() && k < (*this).numcolumnas()) {
	  	/* Encontrar el k-pivote: */
		int i_max = h;
		double elem_max = (*this).get(h, k);
		for (int p = h + 1; p < (*this).numfilas(); p++) {
			double elem_comparar = (*this).get(p, k);
			if (fabs(elem_comparar) > fabs(elem_max)) {
				elem_max = elem_comparar;
				i_max = p;
			}
		}
		if (eq((*this).get(i_max, k), 0)) {
			/* No hay pivote en esta columna, paso a la siguiente */
			k++;
		} else {
			//swapRows(h, i_max);
			map < int, double > guardar = (*this).filas[h];
			(*this).filas[h] = (*this).filas[i_max];
			(*this).filas[i_max] = guardar;
			/* Hacer para todas las filas debajo: */
			for (int i = h + 1; i < (*this).numfilas(); i++) {
				if (!(eq((*this).get(i, k), 0))) {
					double f = (*this).get(i, k) / (*this).get(h, k);
					/* Llenar con ceros la parte baja de la columna: */
					(*this).set(i, k, 0);
					/* Los elementos restantes de la matriz: */
					for (int j = k + 1; j < (*this).numcolumnas(); j++) {
					   double elem = (*this).get(i, j);
					   double elemARestar = ((*this).get(h, j) * f);
					   //cout << "elem: " << elem << " elemARestar: " << elemARestar << endl;
					   (*this).set(i, j, elem - elemARestar);
					   
					}
					terminoInd[i] = terminoInd[i] - f*terminoInd[h];
				}	
			}		
				//veo como quedo hasta ahora la matriz
				/*cout << "hasta ahora: " << endl;
				for (int i = 0; i < (*this).numfilas(); i++) {
					for (int j = 0; j < (*this).numcolumnas(); j++) {
						cout << (*this).get(i, j) << "  ";
					}
					cout << endl;
				}*/
			/* incrementar pivote columna y fila */
			h++; 
			k++;
		}
	}
}

vector < double > matrix::sustitucionParaAtras(const vector < double > &b) {
	//supongo A es matriz triangular superior
	vector < double > res((*this).numcolumnas(), 0);
	double suma = 0;
	for (int i = (*this).numfilas() - 1; i >= 0; i--) {
		if (eq((*this).get(i, i), 0)) throw runtime_error("encontre un cero!! estas haciendo las cosas mal");
		suma = 0;
    	map <int, double>::iterator it = ((*this).filas[i]).end();
    	it--;
    	int j = it->first;
		while (it != ((*this).filas[i]).begin() && j > i) {
			suma += (*this).get(i, j) * res[j];
			it--;
      		j = it->first;
		}
		res[i] = (b[i] - suma) / (*this).get(i, i);
	}

	return res;
}

bool matrix::eq(double a, double b) {
	return fabs(a - b) < eps;
}

//este es el c_j.
double matrix::cantidadDeLinksSalientes(int numPagina) {
	double suma = 0;
	/*for (int j = 0; j < (*this).numfilas(); j++) {
		suma += (*this).columnas[numPagina][j];
	}*/
	double res=0;
	if(!(*this).columnas[numPagina].empty()){
		res = 1.0 / (*this).columnas[numPagina].size();
	}
	//cout << suma << endl;

	/*if (suma == 0) {
		return 0;
	}*/
	return /*1/suma*/ res;
}
