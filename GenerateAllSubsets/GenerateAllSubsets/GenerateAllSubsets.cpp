#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &subset){
	for(int i=0;i<subset.size();i++){
		cout<<subset[i];
	}
	cout<<endl;
}

void generateSubsets(vector<int> &A,vector<int> &subset,int index){
	if(index==A.size())
		print(subset);
	else{
		subset[index]=NULL;
		generateSubsets(A,subset,index+1);
		subset[index]=A[index];
		generateSubsets(A,subset,index+1);
	}
} 

void main(){
	vector<int> A(3);
	A[0]=1;A[1]=2;A[2]=3;
	vector<int> subset(3,0); 
	generateSubsets(A,subset,0);
}