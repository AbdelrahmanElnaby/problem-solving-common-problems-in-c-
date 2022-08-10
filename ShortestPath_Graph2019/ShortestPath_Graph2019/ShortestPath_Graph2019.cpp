#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int **M;
vector< pair< pair<int,bool>,pair<int,int>> > table;
int sumE;

void initilaizeMatrix(int nodes){

	M=new int*[nodes];
	for(int i=0;i<nodes;i++){
		M[i]=new int[nodes];
		for(int j=0;j<nodes;j++){
			M[i][j]=0;
		}
	}

}

void initializeEdges(int n1,int n2,int value){
	M[n1-1][n2-1]=value;
}
// return summition of the edges
int initializeConnectedNodes(){
	/*int edges;
	cout<<"number of edges"<<endl;
	cin>>edges;
	int n1,n2,value,sumE=0;
	for(int i=0;i<edges;i++){
		cout<<"n1  n2  value"<<endl;
		cin>>n1>>n2>>value;
		initializeEdges(n1,n2,value);
		sumE+=value;
	}*/
	//return sumE;
	initializeEdges(1,2,2);
	initializeEdges(1,3,4);
	initializeEdges(2,3,1);
	initializeEdges(2,4,2);
	initializeEdges(4,3,3);
	initializeEdges(3,5,3);
	initializeEdges(4,6,4);
	initializeEdges(5,4,5);
	initializeEdges(5,6,6);
	return 100;
}
bool isConnected(int n1,int n2){
	return M[n1][n2] > 0;
}

void initializeTable(int nodes){
	for(int i=0;i<nodes;i++){
		table.push_back(make_pair(make_pair(i,false),make_pair(sumE,-1)));
	}
}

// return the the index of minimum cost of the unvisited nodes
int getMinimumCost(){
	
	int min=sumE;
	int index=-1;
	for(int i=0;i<table.size();i++){
		  //    bool of visites       //  the cost at this node 
		if(! (table[i].first.second) && table[i].second.first < min){
			min=table[i].second.first;
			index=i;
		}
	}
	return index;
}

//void shortestpath(int **M,vector< pair< pair<int,int>,pair<int,int>> > table)
void shortestPath(int s,int nodes){
	int node=s-1;
	table[node].second.first=0;
	for(int i=0;i<nodes;i++){
		table[node].first.second=true;
		int nCcost=table[node].second.first;// (nCcost) is the cost at the current node 
		for(int j=0;j<nodes;j++){
			if( isConnected(node,j) && !(table[j].first.second)){
				int nCost=table[j].second.first;// (nCost) is the cost at the sake node 
				int eValue=M[node][j];//(eValue) is the edge value
				int total=nCcost+eValue;
				if(total < nCost){
					table[j].second.first=total;
					table[j].second.second=node;
				}
				
			}
		}
		node=getMinimumCost();
	}
}

void getShortestPath(int eNode){
	if(table[eNode].second.second!=-1){
		getShortestPath(table[eNode].second.second);
		cout<<table[eNode].first.first<<endl;
	}
	else cout<<table[eNode].first.first<<endl;
}

void main(){
	int nodes=6;
	initilaizeMatrix(nodes);
	initializeEdges(1,2,2);
	sumE=initializeConnectedNodes();
	initializeTable(nodes);
	shortestPath(1,nodes);
	getShortestPath(4);
    //cout<<table[5].second.first<<endl;
}