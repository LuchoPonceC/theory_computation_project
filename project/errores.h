#include<iostream>

using namespace std;

void translates(){
    bool error=false;
    Arbol arb;
	string palabra;
    int numero;
    do{
    try{
	
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

    }
    catch(int n){
            switch(n){
                case 1:
                    cout<<"Error interno los vectores estan vacios."<<endl;
                    error=true;
                    break;
                case 2:
                    cout<<"Error the word is too big."<<endl;
                    error=true;
                    break;
                case 3:
                    cout<<"Error does not comply with the rules."<<endl;
                    error=true;
                    break;
                case 4:
                    cout<<"Error the languages do not match."<<endl;
                    error=true;
                    break;
                case 10:
                    error=false;
                    break;
            }
    }
    }while(error);
}



