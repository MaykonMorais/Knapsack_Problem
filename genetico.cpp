#include "binario.h"
#include "genetico.h"
#include <iostream>
#include "windows.h"


using namespace std;
unsigned short int CruzamentoPontoUnico(unsigned short int sol1, unsigned short int sol2) {
	return OrBin(BitsAltos(sol1), BitsBaixos(sol2));  // Usamos as funções dos bits baixos e altos e fazemos uma OR com o resultado
 													
}
unsigned short int CruzamentoAritmerico(unsigned short int sol3, unsigned short int sol4) {

	return AndBin(sol3,sol4); // fazemos uma And entre a solução 3 e 4 e retornamos o resultado
}

unsigned short int MutacaoSimples(unsigned short int sol5) {
	
	if (TestaBit(sol5, 9) == 0) { // Modifica o bit da posicao 9 usando uma XOR
		unsigned short int mascara = 1 << 9;    
		return	sol5 ^ mascara;					
	}											
		
}

unsigned short int MutacaoDupla(unsigned short int sol6) {
	if ((TestaBit(sol6, 12) == 0)) { // Modifica Dois Bits das posiçoes 12 e 3 Da Solução 6
		sol6 = LigarBit(sol6, 12);
	}
	else {
		sol6 = DesligaBit(sol6, 12);
	}
	if ((TestaBit(sol6, 3) == 0)) {
		sol6 = LigarBit(sol6, 3);
	}
	else {
		sol6 = DesligaBit(sol6, 3);
	}
	return sol6;
}


bool avaliacao(unsigned short valor) {
	unsigned short preco = 0, peso = 0;
	bool confirmacao = false;
	// A AVALIACAO ACONTECERÁ COM O TESTE BIT A BIT DO VALOR
	if ((TestaBit(valor, 0) == 1)) { // p
		peso = peso + 1;
		preco = preco + 12;
	}
	if (TestaBit(valor, 1) == 1) { // o
		peso = peso + 4;
		preco = preco + 4;
	}
	if (TestaBit(valor, 2) == 1) { // n
		peso = peso + 2;
		preco = preco + 3;
	}
	if (TestaBit(valor, 3) == 1) { // m
		peso = peso + 5;
		preco = preco + 10;
	}
	if (TestaBit(valor, 4) == 1) { // l
		peso = peso + 4;
		preco = preco + 15;
	}
	if (TestaBit(valor, 5) == 1) { // k
		peso = peso + 2;
		preco = preco + 20;
	}
	if (TestaBit(valor, 6) == 1) { // j
		peso = peso + 1;
		preco = preco + 10;
	}
	if (TestaBit(valor, 7) == 1) { // i
		peso = peso + 4;
		preco = preco + 2;
	}
	if (TestaBit(valor, 8) == 1) { // h
		peso = peso + 3;
		preco = preco + 1;
	}
	if (TestaBit(valor, 9) == 1) { // g
		peso = peso + 2;
		preco = preco + 1;
	}
	if (TestaBit(valor, 10) == 1) { // f
		peso = peso + 1;
		preco = preco + 3;
	}
	if (TestaBit(valor, 11) == 1) { // e
		peso = peso + 9;
		preco = preco + 15;
	}
	if (TestaBit(valor, 12) == 1) { // d
		peso = peso + 4;
		preco = preco + 10;
	}
	if (TestaBit(valor, 13) == 1) { // c
		peso = peso + 5;
		preco = preco + 8;
	}
	if (TestaBit(valor, 14) == 1) { // b
		peso = peso + 3;
		preco = preco + 4;
	}
	if (TestaBit(valor, 15) == 1) { // a
		peso = peso + 12;
		preco = preco + 4;
	}
	// RESULTADO DO SOMATORIO DOS PESOS E PRECO 
	cout.width(5);
	cout << right << valor;
	cout << " - ";
	cout << left  << "$" << preco;
	cout << " - ";
	cout << left << peso << right;
	cout.width(1);
	cout << "Kg – "; 

	// VERIFICACAO DO PESO E RETORNO
	if (peso <= 20) {
		confirmacao = true;
	}
	return confirmacao;
}

// DEFINIÇÃO DA FUNÇÕES QUE FAZEM A MODIFICAÇÃO DAS CORES
void verde() { 
 	HANDLE x = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(x, FOREGROUND_GREEN);
	cout.width(1);
	cout << left <<"OK" << endl;
	SetConsoleTextAttribute(x, 7);
}
void vermelho() {
	HANDLE x = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(x, FOREGROUND_RED);
	cout.width(1);
	cout << left << "X" << endl;
 	SetConsoleTextAttribute(x, 7);
}