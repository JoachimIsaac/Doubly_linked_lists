/*
 This program defines and implements a class named SortedList.
 SortedList creates and maintains a sorted list of doubles.
 
 */
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

class SortedList{
    // Declare member variables and functions
protected:
    struct Node{
        double value;
        Node* next;
        Node* prev;
        
        Node(double num, Node* p = NULL, Node* n = NULL){
            value = num;
            next = n;
            prev = p;
        }
    };
    
private:
    Node* head;
    Node* rear;
    
public:
    SortedList();
    ~SortedList();
    void insert(double);
    
    void remove(double);
    void display(ofstream&);
    void size();
    void displayReversed(ofstream&);
    
    
    
    
    
};

// Implement all member functions here
// Since outside of class, use ::
// Default Constructor
SortedList::SortedList(){
    head = NULL;
    rear = NULL;
    
    
}

SortedList::~SortedList(){
    Node * tmp = head;
    while(tmp != NULL){
        
        head = head->next;
        delete tmp;
        tmp = head;
        
        
    }
 
}

/*
void SortedList::insert(double num){
    
    Node* tmp = head;
    Node * previous_n = head;
    
    if(head == NULL){//////
      rear = head = new Node(num,NULL,NULL);
    }
    
    if(head != NULL){
    /////this happens if the first value is less than the new one
    //the new one is inserted behind.
    if(head->value <  num){
        rear = tmp->prev = new Node(num,tmp,NULL);
        }
    if(head->value > num)//if the new node is less than the present node it is put infront.
        head = tmp->next = new Node(num,NULL,tmp);
    
        
        tmp = rear;
        previous_n = rear;
        while(tmp->next != NULL && num > tmp->value){
            
            previous_n = tmp;
            tmp = tmp->next;
        }
        
        if(tmp->value > num){
            
            previous_n->next = new Node(num,tmp,previous_n);
            tmp->prev =previous_n->next;
        }
    
        
    }
}

*/

/*
void SortedList::insert(double num){
    
    
    // If first node to be insetailed in doubly
    // linked list
    if (head == NULL){
        rear = head = new Node(num,NULL,NULL);
    }
    
    
    // If node to be insetailed has value less
    // than first node
    if (num < rear->value)
    {
         rear = rear->prev = new Node(num,rear,NULL);
       
    }
    
    // If node to be insetailed has value more
    // than last node
    if(num > head->value){
        head = head->next = new Node(num,NULL,head);
    }
    
    // Find the node before which we need to
    // insert p.
    Node *temp = head;
    while (temp->value > num)
        temp = temp->prev;
    
    // Insert new node infront temp
    temp = temp->next = new Node(num,temp->next,temp);
    temp->next->prev = temp;

}

*/



void SortedList::insert(double num){
    Node * tmp = head;
    Node * prev_n = head;
    
    //empty list

    if(head == NULL){
         rear = head = new Node(num);
    }
    else{//if list not empty
        if(num < head->value){//inserts at the beginning.
            
            head = new Node(num,head,NULL);
            head->prev->next = head;
        }
        
        while(tmp->prev!= NULL && num > tmp->value){//middle
            
            prev_n = tmp;
            tmp = tmp->prev;
        }
        
        prev_n = prev_n->prev = new Node(num,tmp,prev_n);
        tmp->next = prev_n;
        
        if(num > rear->value){//adds at the end
            
            rear =new Node(num,NULL,rear);
            rear->next->prev = rear;
        }

    }
}
   




















void SortedList::remove(double num){
    Node* tmp = head;
    Node * previous_node = head;
    
    if(head == NULL){//////
        cout<<"The list is empty";
    }
    
    if(head != NULL){
        if(head->value == num){
            head = head->prev;
            delete tmp;
            tmp = previous_node = head;
            head->next=NULL;
            
        }
        else{
            while(tmp != NULL && tmp->value!=num){
            tmp = tmp->prev;
        }
            //found the node anywhere in the list beside head and end
            if(tmp != NULL){
                if(tmp->prev != NULL){
                previous_node->prev = tmp->prev;
                tmp->next = previous_node;
                delete tmp;
                tmp=NULL;
            }
                else{
                    //if at end of list
                    rear = rear->next;
                    previous_node = tmp;
                    previous_node->next->prev=NULL;
                    delete tmp;
                    previous_node = tmp = NULL;
                    
                }
        }
        
    }
    
    
}
}

void SortedList::display(ofstream& out){
    if(head == NULL){
        
        out<<"This list is empty!";
    }
    Node* tmp = head;
    while(tmp!=NULL){
        
        out<<tmp->value<<"\t";
        tmp = tmp->prev;
    }
    
  
    
}



//void SortedList::size(){}

void SortedList::displayReversed(ofstream& out){


 
}



int main(){
    // Objects to read/write to files
    ifstream infile;
    ofstream outfile;
    double num; //Number read from file
    // Sentinels
    const double STOP_READING = -99.99;
    const double STOP_REMOVING = -999.99;
    // Open files
    infile.open("values.dat");
    outfile.open("Isaac_List.txt"); //Change this line
    SortedList listA;
    if (infile && outfile){
        outfile << "Joachim Isaac\n"; //Change this line
        outfile << "Program 5 Sorted Linked Lists\n\n";
        // Read until sentinel of STOP_READING is found
        while (infile >> num && num != STOP_READING){
            listA.insert(num);
        }
        
        outfile << "List after inserting:\n";
        listA.display(outfile);
       // outfile << "Reverse order:\n";
       // listA.displayReversed(outfile);
        //outfile << endl << endl;
        
        // Remove values from list until
        // STOP_REMOVING is found
       // while (infile >> num && num != STOP_REMOVING){
       //     listA.remove(num);
       // }
        //outfile << "List after removing:\n";
        //listA.display(outfile);
         /*
        outfile << "Reverse order:\n";
        listA.displayReversed(outfile);
        outfile << endl;
        outfile << endl;
        
        // Read until sentinel of STOP_READING is found
        while (infile >> num && num != STOP_READING){
            listA.insert(num);
        }
        outfile << "List after inserting again:\n";
        outfile << "Current Size: " << listA.size() << endl;
        listA.display(outfile);
        outfile << "Reverse order:\n";
        listA.displayReversed(outfile);
        outfile << endl << endl;
        // Close files
        outfile.close();
        infile.close();
    }
    else
        cout << "Couldn't open one or more files.\n";
    
    */
    return 0;
    
}
}

