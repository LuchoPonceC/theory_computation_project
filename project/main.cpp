#include <iostream>
#include "arbol.h"

int main(){

	Arbol arb;
	string palabra;

	int numero;
	
	cout<<"Si quiere traducir de ingles a aleman digite 1 \nSi quiere traducir de aleman a ingles digite 2 "<<endl;
	cin>>numero;
	cout<<"INGRESE LA PALABRA ";cin>>palabra;
	if(numero==1){
		arb.translate(palabra,english,german);
		arb.transexp(palabra,english,german);
	}
	else if(numero == 2){
		arb.translate(palabra,german,english);

	}
	

	return 0;
}

