#include "../../src/System.h"
#include "../../src/Flow.h"
#include "../../src/Model.h"
#include "Exponencial.h"
#include "Logistico.h"
#include "Complexo.h"
#include "Perda.h"
#include "Ganho.h"
#include "Troca.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Teste Exponencial: " << endl;
	testExponencial();
	cout << endl << endl;

	cout << "Teste Logistico: " << endl;
	testLogistico();
	cout << endl << endl;

	cout << "Teste Complexo: " << endl;
	testComplexo();
	cout << endl << endl;

	cout << "Teste Perda: " << endl;
	testPerda();
	cout << endl << endl;

	cout << "Teste Ganho: " << endl;
	testGanho();
	cout << endl << endl;

	cout << "Teste Troca: " << endl;
	testTroca();
	cout << endl << endl;

	return 0;
}