#include<iostream>
using namespace std;

class Queue{
	
	private:
		struct Node{
			int data;
			Node *next;
		};
		int counter;
		Node *rear,*front;
	public:

		Queue(){
			front=NULL;
			rear=NULL;
			counter=0;
		}

		void enqueue(int val){
			Node *newn=new Node;
			newn->data=val;
			newn->next=NULL;
			counter++;
			if(front==NULL){
				rear=newn;
				front=rear;
			}
		   else {
				rear->next=newn;
				rear=newn;
		   }

			
		}

		void dequeue(){
			if(!isEmpty()){
				Node *block=front;
				front=front->next;
				cout<<"deleted node is "<<block->data<<endl;
				delete block;
				counter--;
			}
			else cout<<"empty Queue"<<endl;
		}

		void print(Node *front){
			if(front!=NULL){
				cout<<front->data<<endl;
				print(front->next);
			}
		}

		void getSize(){
			cout<<"Queue size is "<<counter<<endl;
		}

		bool isEmpty(){
			return front==NULL;
		}
		Node *getFront(){
			return front;
		}
};

void main(){
	
	Queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.print(q.getFront());
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.print(q.getFront());
	q.enqueue(4);
	q.enqueue(5);
	q.print(q.getFront());
	q.getSize();
}