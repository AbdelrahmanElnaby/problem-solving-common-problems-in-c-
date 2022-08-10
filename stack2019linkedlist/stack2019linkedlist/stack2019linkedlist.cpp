#include<iostream>
using namespace std;

class Stack{
	private:

		struct Node{
			int data;
			Node *next;
		};
		int size;
		Node *top;
	public:
		Stack(){
			this->size=0;
			top=NULL;
		}

		~Stack(){
			Node *block=top;
			while(block!=NULL){
				top=top->next;
				delete block;
				block=top;
			}
		}
		void push(int data){
			Node *block=new Node;
			block->data=data;
			block->next=top;
			top=block;
		}
		void pop(){
			if(!isEmpty()){
				Node *block=top;
				top=top->next;
				delete block;
			}
		
		}
		

		void print(Node *top){
			if(top!=NULL){
				print(top->next);
				cout<<top->data<<endl;
			}

		}

		int getSize(Node *top){
			if(top!=NULL){
				return 1+getSize(top->next);
			}
			else return 0;
		}
		Node *getTop(){
			return top;
		}

		bool isEmpty(){
			return top==NULL;
		}

};

void main(){
	
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout<<"size is"<<s.getSize(s.getTop())<<endl;
	s.pop();
	s.print(s.getTop());
	s.~Stack();
	cout<<"size "<<s.getSize(s.getTop())<<endl;
}