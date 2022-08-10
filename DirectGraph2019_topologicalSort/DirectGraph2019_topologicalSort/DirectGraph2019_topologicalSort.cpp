#include<iostream>
#include<stack>
using namespace std;

class Graph{

	private:
		int size;
		int **A;
		stack<int>topologic;
	public:

		Graph(int size){
			this->size=size;
			A=new int*[size];
			twoDimension();
			initialization();
		}

		void twoDimension(){
			for(int i=0;i<size;i++){
				A[i]=new int[size];
			}
		}

		void initialization(){
			for(int i=0;i<size;i++){
				for(int j=0;j<size;j++){
					A[i][j]=0;
				}
			}
		}

		void addNode(int n1,int n2){
			A[n1-1][n2-1]=1;
		}

		bool isConnected(int n1,int n2){
			return A[n1][n2]==1;
		}

		void DFS_TopologicalSort(){

			stack<int>s;
			bool *explored=new bool[size];
			for(int i=0;i<size;i++){
				explored[i]=false;
			}

			for(int i=0;i<size;i++){
				if(!explored[i]){
					s.push(i);
					explored[i]=true;
					while(!s.empty()){
						for(int i=0;i<size;i++){
							if(isConnected(s.top(),i) && !explored[i]){
								s.push(i);
								explored[i]=true;
								i=-1;
							}
						}
						topologic.push(s.top()+1);
						s.pop();
					}
				}
			}
		}

		void print(){
			while(!topologic.empty()){
				cout<<topologic.top()<<endl;
				topologic.pop();
			}
		}
};

void main(){
	Graph g(5);
	g.addNode(1,3);
	g.addNode(3,4);
	g.addNode(3,5);
	g.addNode(4,5);
	g.addNode(2,3);
	g.DFS_TopologicalSort();
	g.print();
}