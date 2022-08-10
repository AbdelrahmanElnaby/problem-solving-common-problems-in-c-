#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &subset){
	for(int i=0;i<subset.size();i++){
		cout<<subset[i];
	}
	cout<<endl;
}

void generateSumSubsets(vector<int> &A,vector<int> &subset,int value,int sum,int index){
	if(sum == value)
		print(subset);
	 if(index < A.size()){
		for(int i=index;i<A.size();i++){
			subset[i]=A[i];
			generateSumSubsets(A,subset,value,sum+subset[i],i+1);
			subset[i]=NULL;
		}

	}
}

void main(){
	vector<int> A(4);
	A[0]=5;A[1]=2;A[2]=10;A[3]=-2;
	vector<int> subset(4,0);
	generateSumSubsets(A,subset,15,0,0);
}