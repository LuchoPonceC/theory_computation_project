#include <iostream>
#include "arbol.h"

int main(){

	Arbol arb;
	string palabra;
	//cin>>palabra;
	//arb.indermidiate_translate(palabra,english);
	//arb.translate(palabra,english,german);
	//palabara para la expresion del lenguaje A3
	cin>>palabra;
	arb.translatexp(palabra,english,german);
	return 0;
}

