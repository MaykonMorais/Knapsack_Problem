#include <iostream>
#include "binario.h"
#include "genetico.h"
#include "windows.h"
#include <locale.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Portuguese");
	unsigned short int sol1, sol2, sol3, sol4, sol5, sol6;

	cout << "Entre com 6 soluções iniciais (números entre 0 e 65535): " << endl;
	cin >> sol1 >> sol2 >> sol3 >> sol4 >> sol5 >> sol6;

	cout << "Resultado da Avaliação" << endl;
	cout << "------------------------" << endl;
	//RESULTADO DAS AVALIAÇÕES INDIVIDUAIS SOBRE AS SOLUÇÕES
	if (avaliacao(sol1) == true) {
		verde(); 	
	}
	else {
		vermelho();
	}
	if (avaliacao(sol2) == true) {
		verde();
	}
	else {
		vermelho();
	}
	if (avaliacao(sol3) == true) {
		verde();
	}
	else {
		vermelho();
	}
	if (avaliacao(sol4) == true) {
		verde();
	}
	else {
		vermelho();
	}
	if (avaliacao(sol5) == true) {
		verde();
	}
	else {
		vermelho();
	}
	if (avaliacao(sol6) == true) {
		verde();
	}
	else {
		vermelho();
	}
	cout << "------------------------" << endl;
	// RESULTADO DAS AVALIAÇÕES SOBRE OS OPERADORES GENETICOS
	cout.width(2); 
	if (avaliacao(CruzamentoPontoUnico(sol1, sol2)) == true) {
		verde();
	}
	else {
		vermelho();
	}
	
	if (avaliacao(CruzamentoAritmerico(sol3, sol4)) == true) {
		verde();
	}
	else {
		vermelho();
	}

	if (avaliacao(MutacaoSimples(sol5)) == true) {
		verde();
	}
	else {
		vermelho();
	}

	if (avaliacao(MutacaoDupla(sol6)) == true) {
		verde();
	}
	else {
		vermelho();
	}
	system("PAUSE");
	return 0;
}
	