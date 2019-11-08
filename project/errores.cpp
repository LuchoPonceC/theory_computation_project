#include<iostream>

using namespace std;

void translates(){
    bool error=false;
    do{
    try{
        Arbol arb;
	    string palabra;
	    cin>>palabra;
        arb.translate(palabra,english,german);
    }
    catch(int n){
            switch(n){
                case 1:
                    cout<<"Error interno el tamaño del vector no puede ser menor a cero."<<endl;
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
                default:
                    error=true;
            }
    }
    }while(error);
}



