#include <iostream>
#include<string>
using namespace std;

template<class T>
class SLList {
protected:
	class Node {
	public:
		T element;
		Node *next;
		Node(T x) {
		    //@start-editable@

		element=x;	
			//@end-editable@
		}
	};
	Node *head;
	Node *tail;
	int n;

public:
	SLList() {
		n = 0;
		head = tail = NULL;
	}

	bool isEmpty(){
		//@start-editable@

		if(n==0)
		    return true;
		else
		    return false;
		//@end-editable@
	}

	int size() {
	    //@start-editable@

	    return n;
	    //@end-editable@
	}

	bool insertLast(T x) {
	    //@start-editable@

		Node *nNode=new Node(x);
		nNode->next=NULL;
		if(n!=0)
		{
		    tail->next=nNode;
		    tail=nNode;
		}
		else{
		    head=nNode;
		    tail=nNode;
		}
		n+=1;
		//@end-editable@
		return true;
	}

	T insertFirst(T x) {
	    //@start-editable@

        Node *nNode=new Node(x);
        nNode->next=NULL;
        if(n!=0)
        {
            nNode->next=head;
            head=nNode;
        }
        else
        {
            head=nNode;
            tail=nNode;
        }
        n+=1;
		//@end-editable@
		return x;
	}

	T removeLast() {
	    //@start-editable@

		Node *tHead=head;
		Node *tNode;
		T x=tail->element;
		while(tHead->next->next!=NULL)
		{
		    tHead=tHead->next;
		}
		delete tHead->next;
		tail=tHead;
		tail->next=NULL;
		n-=1;
			//@end-editable@
			return x;
		
		
	}

	T removeFirst() {
	    //@start-editable@

		Node *t=head;
		T x=head->element;
		head=head->next;
		delete t;
		n-=1;
		//@end-editable@
		return x;
	}
//Prints the list
	void printlist(){
		if (!isEmpty()) {
			Node *temp = head;
			while (temp != NULL) {
				cout << temp->element << " ";
				temp = temp->next;
			}
			cout << endl;
			return;
		}
		cout << ("List is empty!")<<endl;
	}

};

//Driver Code
int main(){
	SLList<int> slist1;
 	string noOfInputs,str;
 	getline(cin, noOfInputs);
 	for(int i=0;i<stoi(noOfInputs);i++){
 	    getline(cin, str); 
 	    
 	    if (str.substr(0, 2) == "IF"){
 	        int value = stoi(str.substr(3, 5));
 	        slist1.insertFirst(value);
 	        slist1.printlist();
 	    }
 	    else if (str.substr(0, 2) == "IL"){
 	        int value = stoi(str.substr(3, 5));
 	        slist1.insertLast(value);
 	        slist1.printlist();
 	    }
 	    else if (str.substr(0, 2) == "DF"){
 	        slist1.removeFirst();
 	        slist1.printlist();
 	    }
 	    else if (str.substr(0, 2) == "DL"){
 	        slist1.removeLast();
 	        slist1.printlist();
 	    }
 	    else if (str.substr(0, 1) == "S"){
 	       cout<< slist1.size()<<endl;
 	    }
 	    else if (str.substr(0,1) == "I"){
 	        //cout<<slist1.isEmpty()<<endl;
 	        if(slist1.isEmpty()){
 	            cout<<"True"<<endl;
 	        }
 	        else{
 	            cout<<"False"<<endl;
 	        }
 	    }
 	}
}
