#include <iostream>
#include "arbol.h"

int main(){

	Arbol arb;
	string palabra;


	int numero;
	
	cout<<"Si quiere traducir de ingles a aleman digite 1 \nSi quiere traducir de aleman a ingles digite 2 "<<endl;
	cin>>numero;
	cin.ignore();
	cout<<"INGRESE LA PALABRA ";getline(cin,palabra);
	if(numero==1){
		arb.translate(palabra,english,german,pro_ancestral);
		//arb.translatexp(palabra,english,german,pro_traduccion);
	}
	else if(numero == 2){
		arb.translate(palabra,german,english,pro_ancestral);

	}
	
/*
=======
	//cin>>palabra;
	//arb.indermidiate_translate(palabra,english);
	//arb.translate(palabra,english,german);
	//palabara para la expresion del lenguaje A3
	cin>>palabra;
	arb.translatexp(palabra,english,german);
>>>>>>> b4ed3d36f3ddf01746eb178e5189e9635aee0a1b*/
	return 0;
}

