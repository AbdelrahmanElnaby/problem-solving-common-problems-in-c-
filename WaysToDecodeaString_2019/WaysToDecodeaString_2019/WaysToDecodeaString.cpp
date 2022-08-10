#include<iostream>
#include<vector>
using namespace std;

vector<int> F;

int decodeString(string data,int size){
	if(size==0){
		return 1;
	}

	else if(F[size] > -1)
		return F[size];

	else if(data[data.size() - size] == '0'){
		F[size]=0;
		return F[size];
	}
	else{
		F[size]=decodeString(data,size-1);
		if(size>1){
		    int i=(data[data.size() - size]-'0')*10;
			i+=data[data.size() - size +1]-'0';
			if(i<26)
			F[size]+=decodeString(data,size-2);
		}
		return F[size];
	}
}


void main(){
string d="12";
F.resize(d.size()+1,-1);
cout<<decodeString(d,d.size())<<endl;

}
