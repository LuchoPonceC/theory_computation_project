#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <queue>

#define english 0
#define german 1

using namespace std;

class Arbol{
private:
	vector<string> english_accepted{"great","grand","mother","father","the","for","Mary","John"};
	vector<string> german_accepted{"von","ur","gross","mutter","vater","Die","Der","Die","Eine"};
	string indermidiate_language="";
	
	list<string> language;
	list<string> traduccion;

	//Encuentras el minimo y maximo tamanio de las palabras del vector enviado (lenguaje -> english_accepted o german_accepted)
	void min_max_word_size(vector<string> *&vec,int &min, int &max);

	//Devuelves la palabra que se encuentra en la cola y lo elimina, sirve para verificar si la palabra es valida
	string get_word(queue<string> &accepted_words);

	//verivida si la palabra se encuentra en el diccionario, si es menor al diccionario sigue pidiendo data, si es mayor al diccionario se rompe, si esta en el diccionario pasa
	bool check_word(vector<string> *&vec,string &temp_word,int &min,int &max);

	//verifica las formas normales de chomsky y llama a la regla numero 1
	bool check_priority(vector<string> *&vec, queue<string> &accepted_words);

	bool rule_A(vector<string> *&vec, queue<string> &accepted_words);

	bool rule_B(vector<string> *&vec, queue<string> &accepted_words);

	bool rule_C(vector<string> *&vec, queue<string> &accepted_words);

	bool rule_D(vector<string> *&vec, queue<string> &accepted_words);

	//imprime el legunaje intermedio : g(g(g(g(mo()))))
	void intermidiate();

	//Traduce realmente el lenguaje que ya paso por la gramatica y fue aceptado a su respectiva traduccion previamente solicitada
	//tracude urgrossvater a greatgrandfather, traduce greatgrandfather a urgrossvater dependiendo de a que se quiere traducir
	void translate(vector<string> *&vec_from, vector<string> *&vec_to);


	bool rule_S(vector<string> *&vec, queue<string> &accepted_words);
	bool rule_B1(vector<string> *&vec, queue<string> &accepted_words);
	bool rule_C1(vector<string> *&vec, queue<string> &accepted_words);
	bool rule_D1(vector<string> *&vec, queue<string> &accepted_words);
	bool rule_E1(vector<string> *&vec, queue<string> &accepted_words);

public:

	void indermidiate_translate(string &word,int lang);


	//Recibe los lenguajes como numero-> 0 ingles y 1 aleman. Luego estos envian sus respectivos vectores from y to a la funcion
	void translate(int lang_from, int lang_to);

	

	//Recibe la palabra, y el numero(ingles o aleman) del lenguaje de entrada y el numero(ingles o aleman) del lenguaje al que sera traducido
	//y traduce a cada palabra de ingles o aleman ya previamente evaluado al otro lenguaje.
	void translate(string word, int lang_from, int lang_to);


	void translatexp(string word,int lang_from,int lang_to);
	void translatexp(int lang_from,int lang_to);

};



void Arbol::min_max_word_size(vector<string> *&vec,int &min, int &max){

	//throw que verifica si los vectores aleman o ingles  estan vacios, si esta vacion manda un throw
	if(vec->size()<0) throw exception();

	min=vec[0].size();
	max=vec[0].size();
	for(auto it : *vec){
		if(it.size()<min){
			min = it.size();
		}
		if(it.size()>max){
			max = it.size();
		}
	}
}



string Arbol::get_word(queue<string> &accepted_words){
	string temp = accepted_words.front();
	accepted_words.pop();
	return temp;
}



bool Arbol::check_word(vector<string> *&vec,string &temp_word,int &min,int &max){
	//throw que si la palabra es mayor en tamaño a la palabra mas grande de mi arreglo de posibles palabras, significa que hay un error
	//por el tamaño.
	if(temp_word.size()>max) throw exception();
	if(temp_word.size()<min) return false;
	if(find(vec->begin(),vec->end(),temp_word)==vec->end()) return false;
	return true;
}



bool Arbol::check_priority(vector<string> *&vec, queue<string> &accepted_words){
	return rule_A(vec,accepted_words);
}



bool Arbol::rule_A(vector<string> *&vec, queue<string> &accepted_words){

	string temp = get_word(accepted_words);
	if(temp == (*vec)[0]){
		return rule_B(vec,accepted_words);
	}
	if(temp == (*vec)[1]){
		return rule_C(vec,accepted_words);
	}
	if(temp == (*vec)[2]){
		return rule_D(vec,accepted_words);
	}
	if(temp == (*vec)[3]){
		return rule_D(vec,accepted_words);
	}
	return 0;
}



bool Arbol::rule_B(vector<string> *&vec, queue<string> &accepted_words){
	string temp = get_word(accepted_words);

	if(temp == (*vec)[0]){
		return rule_B(vec,accepted_words);
	}
	if(temp == (*vec)[1]){
		return rule_C(vec,accepted_words);
	}
	return 0;
}



bool Arbol::rule_C(vector<string> *&vec, queue<string> &accepted_words){
	string temp = get_word(accepted_words);
	if(temp == (*vec)[2]){
		return rule_D(vec,accepted_words);
	}
	if(temp == (*vec)[3]){
		return rule_D(vec,accepted_words);
	}
	return -1;
}



bool Arbol::rule_D(vector<string> *&vec, queue<string> &accepted_words){
	return accepted_words.empty();
}



void Arbol::intermidiate(){
	
	indermidiate_language += ((language.back()).substr(0,2)+"()");
	
	for(int i=0;i<language.size()-1;i++){
		indermidiate_language = "g("+indermidiate_language+")"; 
	}

	cout<<indermidiate_language<<endl;
}



void Arbol::translate(vector<string> *&vec_from, vector<string> *&vec_to){
	//if(language.back()!=(*vec_from)[2] and language.back()!=(*vec_from)[3]) throw exception();
	if(language.back()==(*vec_from)[2]){traduccion.push_front((*vec_to)[2]);}
	if(language.back()==(*vec_from)[3]){traduccion.push_front((*vec_to)[3]);}
	if(language.size()>1){traduccion.push_front((*vec_to)[1]);}
	for(int i=0;i<(int)language.size()-2;i++){

		traduccion.push_front((*vec_to)[0]);
	}
	for(auto it : traduccion){
		std::cout<<it<<" ";
	}
	cout<<endl;
}



void Arbol::indermidiate_translate(string &word,int lang){
	
	vector<string> *vec = nullptr;
	queue<string> accepted_words;
	if(lang==english){
		vec = &english_accepted;
	}
	else{
		vec = &german_accepted;
	}
	string temp_word="";
	int min,max;
	min_max_word_size(vec,min,max);
	for(auto it : word){

		temp_word+=it;

		if(check_word(vec,temp_word,min,max)){

			accepted_words.push(temp_word);
			language.push_back(temp_word);

			temp_word="";
		}
	}

	//Throw que en caso que todas la pabras si esten en el lenguaje, se procede a evaluar su procedencia "gramatica de chomsky" (creo)
	if(!(check_priority(vec,accepted_words))) throw exception();
	


}



void Arbol::translate(string word, int lang_from, int lang_to){
	//Throw que al recibir dos inputs(que son lengaujes) te bota throw si algun lenguaje(como numero) no existe
	if((lang_from!=english or lang_from!=german) and (lang_from != german or lang_to!=english)) throw exception();
	language.clear();
	indermidiate_translate(word,lang_from);
	intermidiate();
	translate(lang_from, lang_to);
}



void Arbol::translate(int lang_from, int lang_to){
	
	vector<string> *vec_from = nullptr;
	vector<string> *vec_to = nullptr;

	if(lang_from==english){
		vec_from = &english_accepted;
		vec_to = &german_accepted;	
	}

	else{
		vec_from = &german_accepted;
		vec_to = &english_accepted;	
	}

	translate(vec_from,vec_to);

}
void Arbol::translatexp(string word, int lang_from, int lang_to){
	language.clear();
	indermidiate_translate(word,lang_from);
	//intermidiate(); no se necestta
	translatexp(lang_from, lang_to);
}

bool Arbol::rule_S(vector<string> *&vec, queue<string> &accepted_words){
	//hacer un find por palabra temp = find(vec,"The")
	string temp = get_word(accepted_words);
	if (temp==(*vec)[4]){
		return rule_B1(vec,accepted_words);
	}
	return 0;

}
bool Arbol::rule_B1(vector<string> *&vec, queue<string> &accepted_words){
	string temp = get_word(accepted_words);
	if (temp==(*vec)[2]){
		return rule_C1(vec,accepted_words);
	}
	if (temp==(*vec)[3]){
		return rule_C1(vec,accepted_words);
	}
	return 0;
}
bool Arbol::rule_C1(vector<string> *&vec, queue<string> &accepted_words){
	string temp = get_word(accepted_words);
	if (temp==(*vec)[5]){
		return rule_D1(vec,accepted_words);
	}
	if (temp==(*vec)[5]){
		return rule_S(vec,accepted_words);
	}
	return 0;
	
}
bool Arbol::rule_D1(vector<string> *&vec, queue<string> &accepted_words){
	string temp = get_word(accepted_words);
	if (temp==(*vec)[6]){
		return rule_E1(vec,accepted_words);
	}
	if (temp==(*vec)[7]){
		return rule_E1(vec,accepted_words);
	}
	return 0;
}

bool Arbol::rule_E1(vector<string> *&vec, queue<string> &accepted_words){
	return accepted_words.empty();
}






