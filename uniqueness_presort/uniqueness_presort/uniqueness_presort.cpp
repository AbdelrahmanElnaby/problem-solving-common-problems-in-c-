#include<iostream>
using namespace std;

int lomutoPartition(int A[],int l,int r){
	
	int p=A[l];
	int s=l,temp;
	for(int i=l;i<r;i++){
		if(A[i]<p){
			s++;
			temp=A[i];
			A[i]=A[s];
			A[s]=temp;
		}
	}
	temp=A[s];
	A[s]=p;
	A[l]=temp;
	return s;
}

void quickSort(int A[],int l,int r){

	if(l<r){
	int s=lomutoPartition(A,l,r);
	quickSort(A,l,s);
	quickSort(A,s+1,r);
	}
}
bool uniqueness(int A[],int s,int e){
	quickSort(A,s,e);

	for(int i=0;i<e;i++){
		if(A[i]==A[i+1])
			return false;
	}
	return true;
}

void print(int A[],int e){
	for(int i=0;i<e;i++){
		cout<<A[i]<<"\t";
	}
	cout<<endl;
}
void main(){
	int A[]={1,1,1,4,1,6,7,1};
	cout<<uniqueness(A,0,8)<<endl;;
}