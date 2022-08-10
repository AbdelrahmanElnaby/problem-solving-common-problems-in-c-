#include<iostream>
#include<cmath>
using namespace std;

int lomutoPartitioning(int A[],int l,int r){
	int p=A[l];
	int s=l;
	int temp;
	for(int i=l+1;i<=r;i++){
		if(A[i]<p){
			s++;
			temp=A[i];
			A[i]=A[s];
			A[s]=temp;
		}
	}
	
	A[l]=A[s];
	A[s]=p;
	return s;
}

int quickSelect(int A[],int l,int r,int k){

	int s=lomutoPartitioning(A,l,r);
	if(s == k-1)
		return A[s];
	else if(s > k-1)
		quickSelect(A,l,s-1,k);
	else quickSelect(A,s+1,r,k);
}

void main(){
	int A[]={4,1,10,8,7,12,9,2,15};
	int size=9;
	int k=ceil(size/2.0);
	cout<<quickSelect(A,0,8,k)<<endl;
	for(int i=0;i<9;i++){
		cout<<A[i]<<endl;
	}
}