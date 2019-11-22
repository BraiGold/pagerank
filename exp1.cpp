#include "inputOutput.h"
#include "operacionesMatriciales.h"

void test_ConstXCopia(){
	matrix matrizDiagonal(4,4);
	for(int i=0;i<matrizDiagonal.numfilas();i++){
		matrizDiagonal.set(i,i,i+1);
	}
	matrix matrizCopia(matrizDiagonal);
	
	cout<< "la primera es una copia de la segunda, la segunda es de 4x4, ahora deben ser iguales"<<endl;
	print_matrix(matrizCopia);
	cout << endl;
	print_matrix(matrizDiagonal);
	cout << endl;
	
	
	matrix BmatrizVacia;
	matrix BmatrizCopia(BmatrizVacia);
	
	cout<< "la primera es una copia de la segunda, la segunda es vacia, ahora deben ser iguales"<<endl;
	print_matrix(BmatrizCopia);
	cout << endl;
	print_matrix(BmatrizVacia);
	cout << endl;
	
	
}

void test_Asignacion(){
	matrix matriz2X2(2,2);
	matriz2X2.set(0,0,10);
	matriz2X2.set(0,1,20);
	matriz2X2.set(1,1,30);
	
	matrix matriz4X4(4,4);
	matriz4X4.set(1,1,-1);
	matriz4X4.set(2,2,-2);
	matriz4X4.set(3,3,-3);
	matriz4X4.set(2,3,-4);
	matriz4X4.set(3,2,-5);
	
	matriz2X2=matriz4X4;
	cout<< "la primera era de 2x2, la segunda es de 4x4, ahora deben ser iguales"<<endl;
	print_matrix(matriz2X2);
	cout << endl;
	print_matrix(matriz4X4);
	cout << endl;
	
	
	matrix Bmatriz3X3(3,3);
	for(int i=0; i<Bmatriz3X3.numfilas(); i++){
		Bmatriz3X3.set(i,0,i);
		Bmatriz3X3.set(i,1,i);
		Bmatriz3X3.set(i,2,i);
	}
	
	matrix Bmatriz4X4(4,4);
	Bmatriz4X4.set(3,3,-20);
	Bmatriz4X4.set(0,3,-10);
	Bmatriz4X4.set(3,0,-10);
	
	Bmatriz3X3=Bmatriz4X4;
	cout<< "la primera era de 3x3, la segunda es de 4x4, ahora deben ser iguales"<<endl;
	print_matrix(Bmatriz3X3);
	cout << endl;
	print_matrix(Bmatriz4X4);
	cout << endl;
	
	
	matrix Cmatriz4X4(4,4);
	for(int i=0;i<Cmatriz4X4.numfilas();i++){
		for(int j=0;j<=i;j++){
			Cmatriz4X4.set(i,j,i+j+1);
		}
	}
	
	matrix Cmatriz2X2(2,2);
	Cmatriz2X2.set(0,1,-5);
	
	Cmatriz4X4=Cmatriz2X2;
	cout<< "la primera era de 4x4, la segunda es de 2x2, ahora deben ser iguales"<<endl;
	print_matrix(Cmatriz4X4);
	cout << endl;
	print_matrix(Cmatriz2X2);
	cout << endl;
	
	
	matrix matrizDiagonal(5,5);
	for(int i=0;i<matrizDiagonal.numfilas();i++){
		matrizDiagonal.set(i,i,2); 
	}
	
	matrix matrizDiagonalAlReves(5,5);
	for(int i=0;i<matrizDiagonal.numfilas();i++){
		int col=matrizDiagonalAlReves.numfilas()-1-i;
		cout<<col<<endl;
		matrizDiagonalAlReves.set(i,col,5); 
	}
	
	matrizDiagonal=matrizDiagonalAlReves;
	cout<< "la primera era diag de 5x5, la segunda es diag al reves de 5x5, ahora deben ser iguales"<<endl;
	print_matrix(matrizDiagonal);
	cout << endl;
	print_matrix(matrizDiagonalAlReves);
	cout << endl;
}

void test_Multiplicacion_Cuadrada(){
	matrix A(3,3);
	matrix B(3,3);
	
	A.set(0,0,2);
	A.set(0,2,1);
	A.set(1,0,3);
	A.set(2,0,5);
	A.set(2,1,1);
	A.set(2,2,1);
	
	B.set(0,0,1);
	B.set(0,2,1);
	B.set(1,0,1);
	B.set(1,1,2);
	B.set(1,2,1);
	B.set(2,0,1);
	B.set(2,1,1);
	
	cout<< "la primera matriz es A y la segunda es B"<<endl;
	print_matrix(A);
	cout<<endl;
	print_matrix(B);
	cout<<endl;
	
	//RECORDAR si operator* devuelve una referencia se puede usar A*B
	//pero si devuelve una copia usar matrix res(A*B)
	matrix resObt(A*B);
	
	cout<<"la primera es lo que obtenemos y la segunda es lo que debe dar"<<endl;
	print_matrix(resObt);
	cout<<endl;
	
	matrix resAxB(3,3);
	resAxB.set(0,0,3);
	resAxB.set(0,1,1);
	resAxB.set(0,2,2);
	resAxB.set(1,0,3);
	resAxB.set(1,2,3);
	resAxB.set(2,0,7);
	resAxB.set(2,1,3);
	resAxB.set(2,2,6);
	
	print_matrix(resAxB);
	cout<<endl;
	
	
	matrix diagonal(20,20);
	for(int i=0; i<diagonal.numfilas(); i++){
		diagonal.set(i,i,3);
	}
	
	matrix rala(20,20);
	for(int i=0; i<rala.numfilas()-2; i++){
		rala.set(i,i+2,i);
		rala.set(i+2,i,6);
	}
	
	cout<<"se muestra la matriz rala"<<endl;
	print_matrix(rala);
	cout<<endl;
	
	matrix otraRala(diagonal*rala);
	
	cout<<"se muestra el resultado de hacer el prod de 3.I y una matriz con elementos en la segunda subdiagonal y superdiagonal"<<endl;
	print_matrix(otraRala);
	cout<<endl;
}

void test_Multiplicacion_NoCuadrada(){
	matrix A(2,3);
	matrix B(3,3);
	
	A.set(0,0,1);//A=1 0 1
	A.set(0,2,1);//  0 2 0
	A.set(1,1,2);
	
	B.set(0,1,5);//B=0 5 6
	B.set(0,2,6);//  1 0 2
	B.set(1,0,1);//  0 2 0
	B.set(1,2,2);
	B.set(2,1,2);
	
	cout<< "la primera matriz es A y la segunda es B"<<endl;
	print_matrix(A);
	cout<<endl;
	print_matrix(B);
	cout<<endl;
	
	matrix resObtAxB(A*B);
	
	cout<<"la primera es lo que obtenemos y la segunda es lo que debe dar"<<endl;
	print_matrix(resObtAxB);
	cout<<endl;
	
	matrix resAxB(2,3);
	resAxB.set(0,1,7);//AxB=0 7 6
	resAxB.set(0,2,6);//    2 0 4
	resAxB.set(1,0,2);
	resAxB.set(1,2,4);
	
	print_matrix(resAxB);
	cout<<endl;
	
	
	matrix C(4,4);
	matrix b(4,1);
	
	C.set(0,0,4);//C=4 0 0 2
	C.set(0,3,2);//  0 8 0 0
	C.set(1,1,8);//  0 0 3 0
	C.set(2,2,3);//  0 0 0 9
	C.set(3,3,9);
	
	b.set(0,0,4);//b=4
	b.set(1,0,3);//  3
	b.set(3,0,1);//  0
                 //  1
	
	cout<< "la primera matriz es C y la segunda es b"<<endl;
	print_matrix(C);
	cout<<endl;
	print_matrix(b);
	cout<<endl;
	
	matrix resObtCxb(C*b);
	
	cout<<"la primera es lo que obtenemos y la segunda es lo que debe dar"<<endl;
	print_matrix(resObtCxb);
	cout<<endl;
	
	matrix resCxb(4,1);
	resCxb.set(0,0,18);//C*b=18
	resCxb.set(1,0,24);//    24
	resCxb.set(3,0,9); //    0
	                   //    9
	
	print_matrix(resCxb);
	cout<<endl;
	
	
	matrix E(3,10);
	matrix F(10,20);
	
	E.set(0,0,5);
	E.set(1,1,10);
	E.set(2,2,20);
	
	for(int i=0; i<F.numfilas(); i++){
		F.set(i,i,i+1);
		F.set(i,i+5,i+2);
	}
	
	cout<<"la primera es de 3x10 y la segunda es de 10x20"<<endl;
	print_matrix(E);
	cout<<endl;
	print_matrix(F);
	cout<<endl;
	
	matrix resObtExF(E*F);
	
	cout<<"es lo que debe dar"<<endl;
	print_matrix(resObtExF);
	cout<<endl;
	
}

void test_backwardSubstitution() {
	cout << "BACKWARD SUBSTITUTION" << endl;
	matrix A(4, 4);

	A.set(0, 0, 1);
	A.set(0, 1, 2);
	A.set(0, 2, 3);
	A.set(0, 3, 4);
	A.set(1, 0, 1);
	A.set(1, 1, 4);
	A.set(1, 2, 9);
	A.set(1, 3, 16);
	A.set(2, 0, 1);
	A.set(2, 1, 8);
	A.set(2, 2, 27);
	A.set(2, 3, 64);
	A.set(3, 0, 1);
	A.set(3, 1, 16);
	A.set(3, 2, 81);
	A.set(3, 3, 256);

	double mydoubles[] = {2, 10, 44, 190};
	vector<double> terminoInd(mydoubles, mydoubles + sizeof(mydoubles) / sizeof(int));

	A.eliminacionGaussianaSinPivoteo(terminoInd);

	vector < double > pepe = A.sustitucionParaAtras(terminoInd);
	for (int i = 0; i < pepe.size(); i++) {
		cout << i << ": " << pepe[i] << endl;
	}
}

void test_eliminacionGaussiana() {
	cout << "ELIMINACION GAUSSIANA" << endl;

	matrix A(4, 4);

	A.set(0, 0, 1);
	A.set(0, 1, 2);
	A.set(0, 2, 3);
	A.set(0, 3, 4);
	A.set(1, 0, 1);
	A.set(1, 1, 4);
	A.set(1, 2, 9);
	A.set(1, 3, 16);
	A.set(2, 0, 1);
	A.set(2, 1, 8);
	A.set(2, 2, 27);
	A.set(2, 3, 64);
	A.set(3, 0, 1);
	A.set(3, 1, 16);
	A.set(3, 2, 81);
	A.set(3, 3, 256);

	double mydoubles[] = {2, 10, 44, 190};
	vector<double> terminoInd(mydoubles, mydoubles + sizeof(mydoubles) / sizeof(int) );
	cout << "esta es la matriz original" << endl;
	print_matrix(A);
	cout << endl;

	A.eliminacionGaussianaSinPivoteo(terminoInd);
	cout << "esta es la matriz despues de eliminacionGaussiana" << endl;
	print_matrix(A);
	cout << endl;
}

void test_Trasponer(){
	matrix A(3,5);
	
	A.set(0,0,2);//A=2 0 9 0 7
	A.set(0,2,9);//  0 0 0 6 1
	A.set(0,4,7);//  0 8 0 5 4
	A.set(1,3,6);
	A.set(1,4,1);
	A.set(2,1,8);
	A.set(2,3,5);
	A.set(2,4,4);
	
	matrix resObtAt(A.transponer());
	
	cout<<"esta es la martiz es la original"<<endl;
	print_matrix(A);
	cout<<endl;
	
	cout<<"la primera es lo que se obtiene y la segunda es lo que se debe dar"<<endl;
	print_matrix(resObtAt);
	cout<<endl;
	
	matrix resAt(5,3);
	
	resAt.set(0,0,2);//At=2 0 0
	resAt.set(1,2,8);//   0 0 8
	resAt.set(2,0,9);//   9 0 0
	resAt.set(3,1,6);//   0 6 5
	resAt.set(3,2,5);//   7 1 4
	resAt.set(4,0,7);
	resAt.set(4,1,1);
	resAt.set(4,2,4);
	
	print_matrix(resAt);
	cout<<endl;
	
	
	matrix B(6,3);
	
	B.set(0,1,6);//B=0 6 8
	B.set(0,2,8);//  4 0 0
	B.set(1,0,4);//  0 0 0
	B.set(3,1,5);//  0 5 8
	B.set(3,2,8);//  1 0 9
	B.set(4,0,1);//  4 5 0
	B.set(4,2,9);
	B.set(5,0,4);
	B.set(5,1,5);
	
	matrix resObtBt(B.transponer());
	
	cout<<"esta es la martiz es la original"<<endl;
	print_matrix(B);
	cout<<endl;
	
	cout<<"la primera es lo que se obtiene y la segunda es lo que se debe dar"<<endl;
	print_matrix(resObtBt);
	cout<<endl;
	
	matrix resBt(3,6);
	
	resBt.set(0,1,4);//Bt=0 4 0 0 1 4
	resBt.set(0,4,1);//   6 0 0 5 0 5
	resBt.set(0,5,4);//   8 0 0 8 9 0
	resBt.set(1,0,6);//
	resBt.set(1,3,5);//
	resBt.set(1,5,5);//
	resBt.set(2,0,8);//
	resBt.set(2,3,8);//
	resBt.set(2,4,9);//
	
	print_matrix(resBt);
	cout<<endl;
	
	
	matrix C(4,4);
	
	C.set(0,0,4);//C=4 0 5 1
	C.set(0,2,5);//  0 0 0 1
	C.set(0,3,1);//  0 2 0 0
	C.set(1,3,1);//  1 0 0 2  
	C.set(2,1,2);//  
	C.set(3,0,1);//  
	C.set(3,3,2);//  
	
	matrix resObtCt(C.transponer());
	
	cout<<"esta es la martiz es la original"<<endl;
	print_matrix(C);
	cout<<endl;
	
	cout<<"la primera es lo que se obtiene y la segunda es lo que se debe dar"<<endl;
	print_matrix(resObtCt);
	cout<<endl;
	
	matrix resCt(4,4);
	
	resCt.set(0,0,4);//Ct=4 0 0 1
	resCt.set(0,3,1);//   0 0 2 0
	resCt.set(1,2,2);//   5 0 0 0
	resCt.set(2,0,5);//   1 1 0 2  
	resCt.set(3,0,1);//  
	resCt.set(3,1,1);//  
	resCt.set(3,3,2);//
	
	print_matrix(resCt);
	cout<<endl;
	
}

void test_MultiplicacionPorEscalar(){
	matrix A(4,4);
	
	//0.002 es distinto a cero
	A.set(0,1,16);    //A= 0 16 0.002   0
	A.set(0,2,0.002); //   0 0  0       8
	A.set(1,3,8);     //   0 0  6       0
	A.set(2,2,6);     //   0 0  -0.0022 0
	A.set(3,2,-0.0022);
	
	cout<<"esta es la matriz original"<<endl;
	print_matrix(A);
	cout<<endl;
	
	double e=0.5;
	A*e;
	
	cout<<"la primera es lo que obtengo y la segunda lo que aprox debe dar"<<endl;
	print_matrix(A);
	cout<<endl;
	
	matrix resAxe(4,4);
	
	//0.001 es igual a cero
	resAxe.set(0,1,8);       //A= 0 8  0.001   0
	//resAxe.set(0,2,0.0005);//   0 0  0       4
	resAxe.set(1,3,4);       //   0 0  3       0
	resAxe.set(2,2,3);       //   0 0  -0.0011 0
	resAxe.set(3,2,-0.0011);
	
	print_matrix(resAxe);
	cout<<endl;
	
	
	matrix B(5,10);
	
	for(int i=0; i<B.numfilas(); i++){
		B.set(i,i,i+1);
		B.set(i,i+2,3);
		B.set(i,i+4,i);
	}
	
	cout<<"esta es la matriz original"<<endl;
	print_matrix(B);
	cout<<endl;
	
	matrix resBxf(B);
	
	double f=-2;
	
	for(int i=0; i<resBxf.numfilas(); i++){
		for(int j=0; j<resBxf.numcolumnas(); j++){
			resBxf.set(i,j, B.get(i,j) * f );
		}
	}
	
	B*f;
	
	cout<<"la primera es lo que obtengo y la segunda lo que aprox debe dar"<<endl;
	print_matrix(B);
	cout<<endl;
	
	print_matrix(resBxf);
	cout<<endl;
	
	
}

void test_salida(double p){
	vector<double> myVec;
	
	myVec.push_back(0.000001);
	myVec.push_back(0.00000043);
	myVec.push_back(0.0000000000015);
	myVec.push_back(0.00009);

	string nombreArchivo="salida";
	salida(p, myVec, nombreArchivo.c_str());
}

int main(int argc, char** argv) {
	/*matrix mat(10, 10);
	matrix mat1(10, 10);

	mat1.set(1, 2, 3);
	mat.set(1, 2, 3);
	mat.set(1, 3, 5);

	cout << "llege" << endl;
	matrix pepe(mat);
	cout << "filas:" << pepe.numfilas() << "columnas:" << pepe.numcolumnas()<<endl;
	matrix pepe2;
	pepe2=mat;*/
	

	//print_matrix(pepe);
	/*test_Asignacion();
	cout << "----------------------"<<endl;
	test_ConstXCopia();
	cout << "----------------------" << endl;
	test_eliminacionGaussiana();*/
	/*cout << "----------------------"<<endl;
	test_Multiplicacion_Cuadrada();
	cout << "----------------------"<<endl;
	test_Multiplicacion_NoCuadrada();
	cout << "----------------------"<<endl;
	test_Trasponer();*/
	/*cout << "----------------------"<<endl;
	test_MultiplicacionPorEscalar();
	cout << "----------------------" << endl;
	test_backwardSubstitution();*/

	char* archivo = argv[1];
	char* pString = argv[2];
	double p;
	sscanf(pString,"%lf",&p);

	ifstream myReadFile;
 	myReadFile.open(archivo);

  	string cantidadDePaginasString;
  	string cantLinksString;

  	int cantidadDePaginas;
  	int cantLinks;

  	string primeroString;
	string segundoString;

	int primero;
	int segundo;

  	string line;
  	if (myReadFile.is_open()) {
		getline(myReadFile, line);
		cantidadDePaginasString = line;
		getline(myReadFile, line);
		cantLinksString = line;

		cantidadDePaginas = atoi(cantidadDePaginasString.c_str());
		cantLinks = atoi(cantLinksString.c_str());

		matrix W(cantidadDePaginas, cantidadDePaginas);
		vector<int> cantLinkEntrantes(cantidadDePaginas,0);
		for (int i = 0; i < cantLinks; i++) {
			getline(myReadFile, primeroString, ' ');
			getline(myReadFile, segundoString);

			primero = atoi(primeroString.c_str());
			segundo = atoi(segundoString.c_str());

			W.set(segundo - 1, primero - 1, 1.0);
			// Genero vector de links entrantes.
			cantLinkEntrantes[segundo-1]++;
			//cout << primero << " y " << segundo << endl;
		}
		
		//print_matrix(W);
		//cout << endl;

		matrix D(cantidadDePaginas, cantidadDePaginas);

		for (int i = 0; i < cantidadDePaginas; i++) {
			double UnosobreCantSalientes =  W.cantidadDeLinksSalientes(i);
			D.set(i, i, UnosobreCantSalientes);
		}
		//print_matrix(D);

		matrix WxD(W*D);

		//cout<<endl;

		//print_matrix(WxD);
		
		WxD * p;

		//cout<<endl;

		//print_matrix(WxD);

		matrix I(cantidadDePaginas, cantidadDePaginas);

		for (int i = 0; i < cantidadDePaginas; i++) {
			I.set(i, i, 1.0);
		}

		//cout<<endl;

		//print_matrix(I);

		matrix I_pWxD(I - WxD);

		//out <<endl;

		vector<double> e(cantidadDePaginas,1.0);

		//cout << endl;

		//print_vector(e);

		I_pWxD.eliminacionGaussiana(e);

		//cout << endl;

		//print_matrix(I_pWxD);
		//print_vector(e);

		//cout << "hasta aca" << endl;

		//cout << endl;

		//print_matrix(I_pWxD);

		vector<double> x_res;
		x_res = I_pWxD.sustitucionParaAtras(e);

		//cout << endl;
		//print_vector(x_res);

		//normalizando
		double sumaParcial=0;
		for(int i=0; i<x_res.size();i++) {
			sumaParcial+=x_res[i];
		}

		for(int i=0; i<x_res.size();i++) {
			x_res[i]=x_res[i] / sumaParcial;
		}

		//cout <<endl;
		print_vector(x_res);

		//test_salida(p);
		string archivonombre(archivo);
		string nombreArchivo="salidas/" + archivonombre.substr(20) + ".out";
		salida(p, x_res, nombreArchivo.c_str());


		//aca ya tengo la D.

		/*matrix B(4, 5);

		B.set(0,0,5);
		B.set(0,1,5);
		B.set(0,2,5);
		B.set(0,3,5);

		B.set(1,0,1);
		B.set(1,1,2);
		B.set(1,2,2);
		B.set(1,3,2);

		B.set(2,0,0);
		B.set(2,1,1);
		B.set(2,2,2);
		B.set(2,3,2);

		B.set(3,0,0);
		B.set(3,1,0);
		B.set(3,2,1);
		B.set(3,3,2);

		B.set(0,4,1);
		B.set(1,4,1);
		B.set(2,4,1);
		B.set(3,4,1);
		vector<double> c(cantidadDePaginas,1.0);
		B.eliminacionGaussiana(c);

		vector<double> e2;
		e2.push_back(1);
		e2.push_back(0.8);
		e2.push_back(0.2);
		e2.push_back(0.8);
		vector<double> e3;
		e3 = B.sustitucionParaAtras(e2);
		print_matrix(B);

		print_vector(e2);

		print_vector(e3);
*/

	
	}
	myReadFile.close();

	return 0;
}
