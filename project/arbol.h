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

	void intermidiate(){
		
		indermidiate_language += ((language.back()).substr(0,2)+"()");
		
		for(int i=0;i<language.size()-1;i++){
			indermidiate_language = "g("+indermidiate_language+")"; 
		}

		cout<<indermidiate_language<<endl;
	}

public:

	bool indermidiate_translate(string word,int lang){
		if(lang!=english and lang != german) throw exception();
		vector<string> *vec;
		if(lang==english){
			vec = &english_accepted;
		}
		else{
			vec = &german_accepted;
		}
		string temp_word="";
		int min,max;
		min_max_word_size(vec,min,max);
		cout<<min<<" - "<<max<<endl;
		for(auto it : word){

			temp_word+=it;

			if(check_word(vec,temp_word,min,max)){

				if(!check_priority(vec,temp_word)) throw exception();

				temp_word="";
			}
		}

		intermidiate();

	}

};