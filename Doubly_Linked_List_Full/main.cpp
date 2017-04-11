/*
    Name - Daniel Erhabor
    ID - @02778845
*/

#include <iostream>
#include <string>

using namespace std;



struct node{
    string destination;
    node* next;         //Node struct
    node* previous;

};

class DoublyLinkedList{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void Append(string someDest);   // Append funcvtion
    void Prepend(string someDest);      // Prepend function
    void Remove(string someDest);       // Remove function
    void InsertAfter(string someDest, string destToInsert);     // Insert destToInsert after someDest
    void PrintList();       // This just prints the list in a regular order
    void PrintGateInfo();        // Prints lost according to specifications
private:
                                                // Private data members
    node* head;
    node* tail;

};

int main()
{
    //cout << "Hello world!" << endl;
    cout << "***************************" << endl << "Gate 56 Flight Records" << endl << "***************************"<< endl << endl;

    cout << "Flight Records for HowardAir Flight 0136:" << endl;
    string houston  = "Houston";
    string chicago = "Chicago";
    string baltimore = "Baltimore";
    string detroit = "Detroit";
    string denver = "Denver";
    string kansasCity = "Kansas City";
    DoublyLinkedList FirstList;
    string dallas = "Dallas";   // String to prepend to list
    FirstList.Append(houston);
    FirstList.Append(chicago);
    FirstList.Append(baltimore);
    FirstList.Append(detroit);
    FirstList.Append(denver);
    FirstList.Append(kansasCity);
    FirstList.Prepend(dallas);
    //FirstList.PrintList();
    FirstList.PrintGateInfo();
    cout << endl << endl << "***************************" << endl;

    cout << endl;
    cout << "Flight Records for HowardAir Flight 0137:" << endl;
    string losAngeles = "Los Angeles";
    string sanFran = "San Francisco";
    string saltLake = "Salt Lake City";
    string westPalm = "West Palm Beach";
    DoublyLinkedList SecondList;
    SecondList.Append(losAngeles);
    SecondList.Append(sanFran);
    SecondList.Append(saltLake);
    SecondList.Append(detroit);
    SecondList.Append(westPalm);
    SecondList.Remove(westPalm);        // Remove westpalm
    SecondList.PrintGateInfo();
    cout << endl << endl << "**************************" << endl;

    cout << endl;
    cout << "Flight Records for HowardAir Flight 0138:" << endl;

    string littleRock = "Little Rock";
    string demoines = "Demoines";
    string minneapolis = "Minneapolis";
    string indiana = "Indianapolis";
    DoublyLinkedList ThirdList;
    ThirdList.Append(littleRock);
    ThirdList.Append(demoines);
    ThirdList.Append(minneapolis);
    ThirdList.Append(chicago);
    ThirdList.Append(dallas);
    ThirdList.InsertAfter(demoines,indiana);        // Insert indiana after demoines
    //ThirdList.PrintList();
    ThirdList.PrintGateInfo();
    cout << endl << endl << "**************************" << endl;

    cout << endl;
    cout << "Flight Records for HowardAir Flight 0139:" << endl;

    string reno = "Reno";
    string lasAlamos = "Las Alamos";
    string lasVegas = "Las Vegas";
    string pheonix = "Phoenix";
    string sanAntonio = "San Antonio";
    DoublyLinkedList FourthList;
    FourthList.Append(houston);
    FourthList.Append(reno);
    FourthList.Append(lasAlamos);
    FourthList.Append(lasVegas);
    FourthList.Append(pheonix);
    FourthList.Append(sanAntonio);      // Append san antonio
    //FourthList.PrintList();
    FourthList.PrintGateInfo();
    cout << endl << endl << "**************************" << endl;

    cout << endl;
    cout << "Flight Records for HowardAir Flight 0140:" << endl;

    string oakland = "Oakland";
    string sanDiegeo = "San Diego";
    string memphis = "Memphis";
    string greenville = "Greenville";
    DoublyLinkedList FifthList;         // Leave list as is
    FifthList.Append(oakland);
    FifthList.Append(sanDiegeo);
    FifthList.Append(denver);
    FifthList.Append(memphis);
    FifthList.Append(greenville);
    //FifthList.PrintList();
    FifthList.PrintGateInfo();



    return 0;
}

DoublyLinkedList::DoublyLinkedList(){
    head = NULL;                        //Constructor
    tail = NULL;
}

DoublyLinkedList::~DoublyLinkedList(){} // Destructor

void DoublyLinkedList::Append(string someDest){
    if (head==NULL){
        node* newObj = new node;
        newObj->destination = someDest;                   // Append function definition
        head = newObj;
        tail = newObj;
        newObj->previous = NULL;
        newObj->next = NULL;
    }
    else{
        node* newObj = new node;
        newObj->destination = someDest;
        node* temp = tail;
        newObj->previous = temp;
        temp->next = newObj;
        newObj->next = NULL;
        tail = newObj;

    }
    return;

}

void DoublyLinkedList::Prepend(string someDest){
    if (head==NULL){
        node* newObj = new node;
        newObj->destination = someDest;                   // Prepend item
        head = newObj;
        tail = newObj;
        newObj->previous = NULL;
        newObj->next = NULL;

    }
    else{
        node* newObj = new node;
        newObj->destination = someDest;
        node* temp = head;
        newObj->next = temp;
        temp->previous = newObj;
        newObj->previous = NULL;
        head = newObj;

    }
    return;

}

//Remove function definition
void DoublyLinkedList::Remove(string someDest){
    if (head->next == NULL){
        if (head->destination == someDest){           // If only one item in list
            node* temp = head;
            head = NULL;
            tail = NULL;
            delete temp;
        }
    }
    else{
        if (head->destination==someDest){
            node* temp = head;                                  // If item is the head
            head = temp->next;
            head->previous = NULL;
            temp->next = NULL;
            delete temp;
        }
        if (tail->destination==someDest){
            node* temp = tail;
            tail = temp->previous;                                  // If item is the tail - I made this special case so I would not
            tail->next = NULL;                                      // Have to remove all occurrences of Houston then prepend it again before prepending Dallas
            temp->previous = NULL;
            delete temp;
        }
        else{
            for (node* traverse = head->next; traverse->next != NULL; traverse = traverse->next){
                if (traverse->destination==someDest){
                    traverse->next->previous = traverse->previous;                      // If item is between the head and the tail
                    traverse->previous->next = traverse->next;
                    traverse->next = NULL;
                    traverse->previous = NULL;
                    delete traverse;

                }
            }
        }

    }
    return;
}

void DoublyLinkedList::InsertAfter(string someDest, string destToInsert){
    if (head->destination==someDest){
        node* newObj = new node;                    // if head has the item to insert after
        newObj->destination = destToInsert;
        node* temp = head->next;
        newObj->next = temp;
        temp->previous = newObj;
        newObj->previous = head;
        head->next = newObj;
    }
    if (tail->destination==someDest){
        node* newObj = new node;
        newObj->destination = destToInsert;     // if tail has item we want to insert after
        node* temp = tail;
        temp->next = newObj;
        tail = newObj;
        newObj->previous = temp;
        newObj->next = NULL;
    }
    else{
        for (node* traverse = head->next; traverse != tail; traverse = traverse->next){
            if (traverse->destination == someDest){
                node* newObj = new node;
                newObj->destination = destToInsert;                     // Traverse through the list between head and tail but NOT including them
                traverse->next->previous = newObj;                      // check if item to insert after is between the head and the tail
                newObj->next = traverse->next;
                newObj->previous = traverse;
                traverse->next = newObj;
            }
        }
    }

    return;
}

void DoublyLinkedList::PrintList(){
    for (node* traverse = head; traverse != NULL; traverse = traverse->next){           // Print the list as regular as possible
        cout << traverse->destination << endl;
    }
    return;
}

void DoublyLinkedList::PrintGateInfo(){
    int i = 1;
    for (node* traverse = head; traverse != tail; traverse = traverse->next){
        if (traverse==tail->previous){
            cout << i << ". " << traverse->destination << " to " << traverse->next->destination;            // Print list according to flight specification
        }
        else{
            cout << i << ". " << traverse->destination << " to " << traverse->next->destination << endl;
        }
        ++i;
    }
    return;

}
