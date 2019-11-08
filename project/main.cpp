#include <iostream>
#include "arbol.h"

int main(){

	Arbol arb;
	string palabra;
	cin>>palabra;
	//arb.indermidiate_translate(palabra,english);
	arb.translate(palabra,english,german);

	return 0;
}

