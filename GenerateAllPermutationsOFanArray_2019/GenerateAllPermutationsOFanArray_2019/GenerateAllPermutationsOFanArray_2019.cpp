#include<iostream>
#include<string>
using namespace std;

void generatePermutations(string word,string result,int index){
	
	if(word.size()==0)
		cout<<result<<endl;
	else {
		for(int i=0;i<word.size();i++){
			result[index]=word[i];
			string word2=word;
			word2.erase(word2.begin()+i);
			generatePermutations(word2,result,index+1);
		}
	}
}

void main(){
	string word="abc";
	string result=word;
	generatePermutations(word,result,0);
}