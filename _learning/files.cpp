#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream in("input.txt"); //oggetto per gestire l’input
	ofstream out("output.txt"); //oggetto per gestire l’output
	int N, i, temp, somma = 0;
	in >> N; //viene letto il primo numero intero
	for (i=0; i < N ; i++) { //ciclo per leggere gli N numeri seguenti
		in >> temp;
		somma += temp;
	}
	out << somma << endl; //scrittura del risultato	
}

