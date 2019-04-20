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
        
        Node(double num, Node* n = NULL, Node* p = NULL){
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
    while(head != NULL){
        
        head = head->prev;
        delete tmp;
        tmp = head;
        
        
    }
 
}

/*
void SortedList::insert(double num){
    Node * tmp = rear;
    Node * previous_n = rear;
    
    // if list is empty , inserts a node.
    if(head == NULL){
        rear = head = new Node(num,NULL,NULL);
    }
    else{
        //at the front
        //if node at front is less than num put it infront
    
        //in case where num is less than node at end of list.insert at end.
        
        if(num > head->value){
            head = head->next = new Node(num,NULL,head);
        }
         if(num < rear->value){
            
            rear = rear->prev = new Node(num,rear,NULL);
        }
         else{
    
            // starts from rear if num is greater than tmp value then
            //it move up the list to go to front.
            //when it finds a value less than tmp it falls out.
             Node * tmp = rear;
             Node * previous_n = rear;
            while(tmp!= NULL && num > tmp->value){
                
                previous_n = tmp;
                tmp = tmp->next;
                
                
                
            }
            //when it falls out it inserts the node before the node which is greater than it.
            if(tmp != NULL){
            previous_n = previous_n->next = new Node(num,tmp,previous_n);
            tmp->prev = previous_n;
            }
        }
       
        
    }
}


*/

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
    else{
        
    Node * tmp = rear;
    while(tmp != NULL){
        out<<tmp->value<<"\t";
        tmp = tmp->next;
    }
        out<<endl;
}
    
}



//void SortedList::size(){}

void SortedList::displayReversed(ofstream& out){


if(head == NULL){
    
    out<<"This list is empty!";
    }
    else{
        
        Node * tmp = head;
        while(tmp != NULL){
            out<<tmp->value<<"\t";
            tmp = tmp->prev;
        }
        out<<endl;
    }
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
        outfile << "Reverse order:\n";
        listA.displayReversed(outfile);
        outfile << endl << endl;
        
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
