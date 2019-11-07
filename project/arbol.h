#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <iostream>

#define english 0
#define german 1

using namespace std;

class Arbol{
private:
	vector<string> english_accepted{"great","grand","mother","father"};
	vector<string> german_accepted{"ur","gross","mutter","vater"};
	string indermidiate_language="";
	list<string> language;
	list<string> traduccion;

	
	void min_max_word_size(vector<string> *&vec,int &min, int &max){
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

	bool check_word(vector<string> *&vec,string &temp_word,int &min,int &max){
		if(temp_word.size()>max) throw exception();
		if(temp_word.size()<min) return false;
		if(find(vec->begin(),vec->end(),temp_word)==vec->end()) return false;
		return true;
	}

	bool check_priority(vector<string> *&vec, string &temp_word){
		if(language.empty()){
			language.push_front(temp_word);
			return true;
		}
		if(language.back()==(*vec)[0]){
			if(temp_word == (*vec)[0] or temp_word == (*vec)[1]){
				language.push_back(temp_word);
				return true;
			}
		}
		if(language.back()==(*vec)[1]){
			if(temp_word == (*vec)[2] or temp_word == (*vec)[3]){
				language.push_back(temp_word);
				return true;
			}
		}

		return false;

	}

	bool check_last_word(vector<string> *&vec){
		return (((*vec)[vec->size()-1] == language.back()) or ((*vec)[vec->size()-1])==language.back());
	}

	void intermidiate(){
		
		indermidiate_language += ((language.back()).substr(0,2)+"()");
		
		for(int i=0;i<language.size()-1;i++){
			indermidiate_language = "g("+indermidiate_language+")"; 
		}

		cout<<indermidiate_language<<endl;
	}

	void translate(vector<string> *&vec_from, vector<string> *&vec_to){
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




public:

	void indermidiate_translate(string &word,int lang){
		if(lang!=english and lang != german) throw exception();
		vector<string> *vec = nullptr;
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

				if(!check_priority(vec,temp_word)) throw exception();

				temp_word="";
			}
		}

		if(!(check_last_word(vec))) throw exception();

		intermidiate();

	}

	void translate(string word, int lang_from, int lang_to){
		language.clear();
		indermidiate_translate(word,lang_from);
		translate(lang_from, lang_to);
	}

	
	void translate(int lang_from, int lang_to){
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

};