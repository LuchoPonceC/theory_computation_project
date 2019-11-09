#include<iostream>

using namespace std;

void translates(){
    bool error=false;
    Arbol arb;
	string palabra;
    string primercaso;
    int ance;
    do{
    try{
	cout<<"\n====================================================================\n"<<endl;
    cout<<"Si quiere realizar una traduccion ancestral escriba \"ANCESTRAL\""<<endl;
    cout<<"Si quiere realizar una traduccion de ingles a aleman escriba \"TRADUCCION\""<<endl;
    cout<<"Si quiere salir del programa escriba \"EXIT\""<<endl;
    cin>>primercaso;
    if(primercaso == "ANCESTRAL"){
        cout<<"Si quiere traducir de ingles a aleman digite 1 \nSi quiere traducir de aleman a ingles digite 2 "<<endl;
        cin>>ance;
        cin.ignore();
        if(ance==1){
            cout<<"INGRESE LA PALABRA ";getline(cin,palabra);
            arb.translate(palabra,english,german,pro_ancestral);
        
        }
        else if(ance == 2){
            cout<<"INGRESE LA PALABRA ";getline(cin,palabra);
            arb.translate(palabra,german,english,pro_ancestral);
        }
        throw 5;
    }
    else if(primercaso == "TRADUCCION"){
        cin.ignore();
        cout<<"INGRESE LA PALABRA ";getline(cin,palabra);
        arb.translatexp(palabra,english,german,pro_traduccion);
    }  
    else if(primercaso =="EXIT"){
        throw 10;
    }
    throw 5;


    }
    catch(int n){
            switch(n){
                case 1:
                    cout<<"\nError interno los vectores estan vacios.\n"<<endl;
                    error=true;
                    break;
                case 2:
                    cout<<"\nError the word is too big.\n"<<endl;
                    error=true;
                    break;
                case 3:
                    cout<<"\nError does not comply with the rules.\n"<<endl;
                    error=true;
                    break;
                case 4:
                    cout<<"\nError the languages do not match.\n"<<endl;
                    error=true;
                    break;
                case 5:
                    cout<<"\nYou choose an incorrect option.\n"<<endl;
                    error=true;
                    break;
                case 10:
                    error=false;
                    break;
            }
    }
    cout<<"\n====================================================================\n"<<endl;
    }while(error);
}