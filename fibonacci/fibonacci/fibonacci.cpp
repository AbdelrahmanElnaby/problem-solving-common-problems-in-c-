#include<iostream>
#include<vector>
using namespace std;

vector<int> F;

int fibonacci(int index){
	if(F.size()-1 < index)
		F.push_back(fibonacci(index-1)+fibonacci(index-2));
	return F[index];
}

void main(){
	int index;
	F.push_back(0);
	F.push_back(1);
	while(true){
		cout<<"enter index"<<endl;
		cin>>index;
		cout<<fibonacci(index)<<endl;
	}
}