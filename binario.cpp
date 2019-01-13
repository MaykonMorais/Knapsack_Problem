#include "binario.h"
#include "genetico.h"

unsigned short int BitsAltos(unsigned short int num) {
	/* A comparaçao acontecerá com a iniciacao de uma mascara pegando os digitos mais
	signficativos de 16 bits, que no caso são os 8 primeiros. e depois usamos uma porta and */
	unsigned short mascara = 0xFF00;
	return (mascara & num);
	
}
unsigned short int BitsBaixos(unsigned short int num) {
	unsigned short mascara = 0x00FF; // O mesmo acontecerá aqui, mas pegamos os bits menos significativos
	return (mascara & num);
}

unsigned short int LigarBit(unsigned short int valor, unsigned short pos) { // Função recebe o valor e a posicao e liga o bit desejado
	unsigned short int mascara = 1 << pos;  //0 0 0 0 | 1 0 0 0 mascara  (EXEMPLO)
	return (mascara | valor);              // 1 1 0 1 | 0* 0 1 1 numero
}										//    1 1 0 1   1* 0 1 1  OR

unsigned short int DesligaBit(unsigned short int valor, unsigned short pos) { // Funcao responsavel por mudar o bit ligado para desligado
	/*Primeiro é feito a movimentacao do bit por meio de uma mascara 
	e depois a negacao e posteriormente uma And entre o valor e a mascara atual */
	unsigned short int mascara = ~(1 << pos); //  1 1 1 0 | 1 1 1 1 mascara    (EXEMPLO)   
								             //   1 1 0 1 | 1 0 1 1 valor
	return (mascara & valor);				//    1 1 0 0   1 0 1 1  And
}
bool TestaBit(unsigned short int valor, unsigned short pos) { // Funcão irá fazer a verificação dos bits
	unsigned short int mascara = 1 << pos; // 
	if ((mascara & valor)) {  // 1 0 1 1 | 0 1 0 1 | 0 0 1 1 
		return true;		 //  0 0 0 0   0 0 0 0   0 0 0 1
	}
	else {
		return false;
	}
}
unsigned short int AndBin(unsigned short int num1, unsigned short int num2) {
	return num1 & num2;
}
unsigned short int OrBin(unsigned short int num1, unsigned short int num2) {
	return num1 | num2;

}

