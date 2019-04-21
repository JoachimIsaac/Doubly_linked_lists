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
////////

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
     Node * tmp = head ;
     Node * prev_tmp = head;
     
     if(head == NULL){
         
         head = rear = new Node(num,NULL,NULL);
         
     }
     else{
            //adding at the begining
         if(num <= head->value){//will try or equal to ref
             head = new Node(num,head,NULL);
             head->prev->next = head;
         }
         else{
         while(tmp!= NULL && tmp->next != NULL && num >= tmp->value){
            prev_tmp= tmp;
             tmp = tmp->next;
         }
         
         prev_tmp = prev_tmp->next= new Node(num,prev_tmp,tmp);
         
         prev_tmp->prev->next = prev_tmp;
         }
          //if(num >= rear->value )
           //  rear = new Node(num,rear,NULL);
            // rear->prev->next = rear;
        // }
         
         
     }
     
     
     
 }
 
 */

void SortedList::insert(double num){
    
    Node * tmp = rear;
    
    if(head == NULL){
        
        head = rear = new Node(num,NULL,NULL);
        
    }
    if(head!=NULL){
        rear = rear->next = new Node(num,tmp,NULL);
        //tmp = tmp->next;
    }

}
 


void SortedList::remove(double num){
    
}



void SortedList::display(ofstream& out){
    Node* tmp = head;
    Node* tmp_n = head->next;
    int list_size = size();
    int i=0;
    bool start = false;
    

    while(tmp!=NULL && (i < (list_size * 100))){
        
    if (tmp->value > tmp_n->value)
     swap(tmp_n->value, tmp->value);
        
        tmp=tmp->next;
        tmp_n= tmp->next;
        
        if(tmp == rear){
            tmp = head;
            tmp_n = head->next;
            
        }
        i++;
    }
    
    start = true;
    
    
    while(tmp!= NULL && start){
        out<<tmp->value<<"\t";
        tmp=tmp->next;
    }
    out << endl;
}



int SortedList::size(){
    Node * temp = head;
    int count = 0;
    
    
    while(temp!=NULL){
        temp = temp->next;
        
        
        count++;
    }
    
    return count;
}

void SortedList::displayReversed(ofstream& out){
    Node* tmp = head;
    Node* tmp_rear = rear;
    Node* tmp_n = head->next;
    int list_size = size();
    int i=0;
    bool start = false;
    
    
    
    
    
    
    while(tmp!=NULL && (i < (list_size * 100))){
        
        if (tmp->value > tmp_n->value)
            swap(tmp_n->value, tmp->value);
        
        tmp=tmp->next;
        tmp_n= tmp->next;
        
        if(tmp == rear){
            tmp = head;
            tmp_n = head->next;
            
        }
        i++;
    }
    
    start = true;
    
    
    while(tmp_rear!= NULL && start){
        out<<tmp_rear->value<<"\t";
        tmp_rear=tmp_rear->prev;
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
