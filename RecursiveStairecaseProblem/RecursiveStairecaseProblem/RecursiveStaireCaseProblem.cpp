#include<iostream>
#include<vector>
using namespace std;

vector<int> F;

int staireCase(int size){
	if(F.size()-1 < size)
		F.push_back(staireCase(size-1)+staireCase(size-2));
	return F[size];
}

void main(){
	int size;
	F.push_back(1);
	F.push_back(1);
	while(true){
		cout<<"enter the aize of stairs"<<endl;
		cin>>size;
		cout<<staireCase(size)<<endl;
	}
}
