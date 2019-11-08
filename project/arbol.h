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
	vector<string> english_accepted{"great","grand","mother","father","the","of","Mary","John"};
	vector<string> german_accepted{"ur","gross","mutter","vater","Die","Der","Eine","Ein","von","Maria","Johann"};
	string indermidiate_language="";
	
	list<string> language;
	list<string> traduccion;

	
	void min_max_word_size(vector<string> *&vec,int &min, int &max);

	string get_word(queue<string> &accepted_words);

	bool check_word(vector<string> *&vec,string &temp_word,int &min,int &max);

	bool check_priority(vector<string> *&vec, queue<string> &accepted_words);

	bool rule_A(vector<string> *&vec, queue<string> &accepted_words);

	bool rule_B(vector<string> *&vec, queue<string> &accepted_words);

	bool rule_C(vector<string> *&vec, queue<string> &accepted_words);

	bool rule_D(vector<string> *&vec, queue<string> &accepted_words);

	void intermidiate();

	void translate(vector<string> *&vec_from, vector<string> *&vec_to);
	int posEnDicc(vector<string> *&vec,string word);
	void translatexp(vector<string> *&vec_from,vector<string> *&vec_to);
	bool rule_S(vector<string> *&vec, queue<string> &accepted_words);
	bool rule_B1(vector<string> *&vec, queue<string> &accepted_words);
	bool rule_C1(vector<string> *&vec, queue<string> &accepted_words);
	bool rule_D1(vector<string> *&vec, queue<string> &accepted_words);
	bool rule_E1(vector<string> *&vec, queue<string> &accepted_words);

public:

	void indermidiate_translate(string &word,int lang);

	void translate(string word, int lang_from, int lang_to);

	void translate(int lang_from, int lang_to);

	void translatexp(string word,int lang_from,int lang_to);

	void translatexp(int lang_from,int lang_to);
};



void Arbol::min_max_word_size(vector<string> *&vec,int &min, int &max){
	//if(vec->size()<0) throw exception();
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
	if(language.back()!=(*vec_from)[2] and language.back()!=(*vec_from)[3]) throw exception();
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
	if(lang!=english and lang != german) throw exception();
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
	if(!(check_priority(vec,accepted_words))) throw exception();
}

int Arbol::posEnDicc(string<vector> dic,string word){
	vector<string>::iterator it = std::find(dic.begin(),dic.end(),word);
	if (it != dic.end()){
		return std::distance(dic.begin(), it);
	}
	else
		return -1 ;
}
void Arbol::translatexp(vector<string> *&vec_from, vector<string> *&vec_to){
	//for mother, father 
	if (language.back()==(*vec_from)[6]){traduccion.push_front((*vec_to)[10];)}
	if (language.back()==(*vec_from)[7]){traduccion.push_front((*vec_to)[11];)}
	//for of 
	if (language[language.size()-1] ==(*vec_from)[5]){
		traduccion.push_front((*vec_to[9]))
	}
	//para 4 
	if (){}
	//para 7
	if (){}

	//para 10 a más 

}


void Arbol::translate(string word, int lang_from, int lang_to){
	language.clear();
	indermidiate_translate(word,lang_from);
	intermidiate();
	translate(lang_from, lang_to);
}



void Arbol::translate(int lang_from, int lang_to){
	if((lang_from!=english and lang_from!=german) or (lang_to!=german and lang_to!=english)) throw exception();
	vector<string> *vec_from = nullptr;
	vector<string> *vec_to = nullptr;
	if(lang_from==english){
		vec_from = &english_accepted;
		if(lang_to==english){
			vec_to = &english_accepted;
		}
		else{
			vec_to = &german_accepted;
		}
	}

	else{
		vec_from = &german_accepted;
		if(lang_to==english){
			vec_to = &english_accepted;
		}
		else{
			vec_to = &german_accepted;
		}
	}
	translate(vec_from,vec_to);

}
void Arbol::translatexp(string word, int lang_from, int lang_to){
	language.clear();
	indermidiate_translate(word,lang_from);
	//intermidiate(); no se necestta
	translatexp(lang_from, lang_to);
}
void Arbol::translatexp(int lang_from, int lang_to){
	vector<string> *vec_from = nullptr;
	vector<string> *vec_to = nullptr;
	if (lang_from==english){
		vec_from=&english_accepted;
	}
	vec_to=&german_accepted;
	translatexp(vec_from,vec_to);
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






