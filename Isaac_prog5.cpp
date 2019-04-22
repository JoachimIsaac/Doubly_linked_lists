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
    int size();
    void displayReversed(ofstream&);
};



// Implement all member functions here
// Since outside of class, use ::
// Default Constructor
SortedList::SortedList(){
    head = NULL;
    rear = NULL;
}

//Destructor
SortedList::~SortedList(){
    Node * tmp = head;
    while(tmp != NULL){
        
        head = head->next;
        delete tmp;
        tmp = head;
    }
}

//Inserts Nodes in-order lowest from head and highest to rear.
void SortedList::insert(double num){
    
    //Inserts a Node when list is empty.
    if(head == NULL){
        rear = head = new Node(num);
    }
    else{
        //Inserts a Node Infront of head if  head->value is less than num
        //and makes rear equal to that new Node.
        if(head->value < num && head->next == NULL){
            
          rear = head->next = new Node(num,head,NULL);
            
        }
        //Inserts behind of head if head->value is more than num.Then makes
        //that value the new head.
        if(head->value > num && head->prev == NULL){
            
            head = head->prev = new Node(num,NULL,head);
            
          }
        }
        //This traverses through the list and finds node less than num
        //within the list and then inserts it.(inserts between two nodes)
        if(size() >= 2 && head->value < num){
            
            Node * tmp = head;
            Node * prev_t = head;
            
            while(tmp->next != NULL && tmp->value < num){
                prev_t = tmp;
                tmp = tmp->next;
            }
            
            if(tmp->value > num){
                tmp->prev = prev_t->next = new Node(num,prev_t,tmp);
            }
        }
    }
    
//Which removes a Node from the list; either at the front, middle or end
void SortedList::remove(double num){
    
    //If list is empty.
    if(head == NULL){
        cout<<"This list is empty";
    }
    
    if(head != NULL){
       
        //Remove at head (front of list).
        if(head->value == num){
            Node* tmp = head;
            Node* prev_n = head;
            
            tmp = tmp->next;
            delete prev_n;
            prev_n = NULL;
            tmp->prev = NULL;
            head = tmp;
        }
        
        //Remove at end of list.
        if(rear->value == num){
            Node* tmp = rear;
            Node* prev_n = rear;
            
            tmp = tmp->prev;
            delete prev_n;
            prev_n = NULL;
            tmp->next = NULL;
            rear = tmp;
        }
        
        //Traverse and removes from anywhere (middle)
        if(size() >= 2 && head->value != num){
            
            Node * tmp = head;
            Node * prev_t = head;
            
            while(tmp->next != NULL && tmp->value != num){
                prev_t = tmp;
                tmp = tmp->next;
            }
            
            if(tmp->value == num){
                prev_t->next = tmp->next;
                tmp->next->prev = prev_t;
                delete tmp;
                tmp = NULL;
            }
        }
    }
}


//Displays list inorder starting from the head.
void SortedList::display(ofstream& out){
   
    Node * tmp = head;
    
    if(head == NULL){
        out<<"The list is empty";
    }
    
    while(tmp != NULL){
        out<<tmp->value<<"   ";
        tmp=tmp->next;
    }
    out<<endl;
    
}


//Traveres through list and returns the size of the list.
int SortedList::size(){
    
    Node * temp = head;
    int count = 0;
    
    
    while(temp!=NULL){
        temp = temp->next;
        count++;
    }
    
    return count;
}


//This traverses through the list backwards and prints
//the list in reversed order.
void SortedList::displayReversed(ofstream& out){
    Node * tmp = rear;
    
    if(head == NULL){
        out<<"The list is empty";
    }
    
    while(tmp != NULL){
        out<<tmp->value<<"   ";
        tmp=tmp->prev;
    }
    
    out<<endl;
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
        
         //Remove values from list until
        // STOP_REMOVING is found
         while (infile >> num && num != STOP_REMOVING){
            listA.remove(num);
          }
         outfile << "List after removing:\n";
         listA.display(outfile);
        
        
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
         
    
        return 0;
        
    }

