#include<iostream>
#include<vector>
using namespace std;
//selection Sort
void selectionSort(int t[],int n){
	int smindex,temp;
	for(int i=0;i<n-1;i++){
		smindex=i;
		for(int j=i+1;j<n;j++){
			if(t[j]<t[smindex])
				smindex=j;
		}
		if(smindex !=i){
		temp=t[i];
		t[i]=t[smindex];
		t[smindex]=temp;
		}
	}
}
//bubble Sort
void bubbleSort(int t[],int n){
	int temp=t[0];
	for(int i=0;i<n-1;i++){
		for(int j=1;j<n-i;j++){
			if(t[j-1]>t[j]){
				temp=t[j];
				t[j]=t[j-1];
				t[j-1]=temp;
			}
		}
		if(temp==t[0])
			return;
	}
}
//insertion Sort
void insertionSort(int T[],int n){
	int u,j;
	for(int i=1;i<n;i++){
		u=T[i];
		j=i-1;
		while(j>=0 && T[j]>u){
			T[j+1]=T[j];
			j--;
	}
		T[j+1]=u;
}
}


void print(int t[],int n){
	for(int i=0;i<n;i++){
		cout<<t[i]<<"\t";
	}
	cout<<endl;
}

void printMerge(vector<int> A){
	for(int i=0;i<A.size();i++){
		cout<<A[i]<<"\t";
	}
	cout<<endl;
}
//Merge Sort
void copyReminder(vector<int> &A,vector<int> &part,int s,int k){

	for(int i=s ;i < part.size();i++,k++){
		A[k]=part[i];
		
	}
}


void merge(vector<int> &A,vector<int> &B,vector<int> &C){
	int i=0,j=0,k=0;

	while( i < B.size()  && j < C.size() ){
		if(B[i] <= C[j]){
			A[k]=B[i];
			i++;
		}
		else{
			A[k]=C[j];
			j++;
		}
		k++;
	}

	if( i == B.size() )
		copyReminder(A,C,j,k);
	else copyReminder(A,B,i,k);
}

vector<int> makeCopy(vector<int> A,int s,int e){
	
	vector<int> copy;
	for(int i=s;i<e;i++){
		copy.push_back(A[i]);
	}
	return copy;
}

void mergeSort(vector<int> &A){
	if(A.size()>1){
		vector<int> B=makeCopy(A,0,A.size()/2);
		vector<int> C=makeCopy(A,A.size()/2,A.size());
		mergeSort(B);
		mergeSort(C);
		merge(A,B,C);
	}
}

//Quick Sort
int lomutoPartition(int A[],int l,int r){
	int s=l,temp;

	for(int i=l+1;i<=r;i++){
		if(A[i] < A[l]){
			s++;
			temp=A[i];
			A[i]=A[s];
			A[s]=temp;
		}
	}
	temp=A[l];
	A[l]=A[s];
	A[s]=temp;
	return s;
}

void quickSort(int A[],int l,int r){
	if(l<r){
		int s=lomutoPartition(A,l,r);
		quickSort(A,l,s-1);
		quickSort(A,s+1,r);
	}
}

void main(){
	int t[]={4,10,8,7,3,5};
	print(t,6);
	cout<<"after selection Sort \t time complexity is O(n^2)"<<endl;
	selectionSort(t,6);
	print(t,6);

	cout<<"after bubble Sort \t time comlexity is O(n^2) \t best case is O(n)"<<endl;
	bubbleSort(t,6);
	print(t,6);
	cout<<"after insertion Sort \t time complexity is O(n^2) \t best case is O(n)"<<endl;
	insertionSort(t,6);
	print(t,6);
	cout<<"after merge sort \t time complexity is O(nlogn)"<<endl;
	vector<int> A;
	A.push_back(4);
	A.push_back(10);
	A.push_back(8);
	A.push_back(7);
	A.push_back(3);
	A.push_back(5);
	mergeSort(A);
	printMerge(A);
	cout<<"after Quick Sort \t time complexity is O(n^2) \t best case is O(nlogn)"<<endl;
	quickSort(t,0,5);
	print(t,6);
}