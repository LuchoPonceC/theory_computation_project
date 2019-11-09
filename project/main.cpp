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
		//arb.translate(palabra,english,german,pro_ancestral);
		arb.translatexp(palabra,english,german,pro_traduccion);
	}
	else if(numero == 2){
		arb.translate(palabra,german,english,pro_ancestral);
	}
	return 0;
}

