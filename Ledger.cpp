/**
 * Description: Implementation for Ledger 
 * @author: Shubham Kamboj 
 * @version date: November 12, 2020 
 * */
#include "Ledger.h"

    //No arg constructer for Ledger class 
    Ledger::Ledger(){
        this->head = NULL;
        count = 0;
    }   

    //destructor for Ledger
    Ledger::~Ledger(){
        clear();
    }

    //Adds a external money transfer to the front of the ledger 
    void Ledger::AddExternalMoney(string name, double amount){
        Node* newNode = new Node();
        newNode->setFromName("External");
        newNode->setToName(name);
        newNode->setData(amount);
        newNode->setID(count++);
        newNode->setNext(head);
        head = newNode;
        if(myMap.count(name) <=0 ){
            myMap[name] = amount;
        }else{
            double temp = myMap[name];
            myMap[name] = amount + temp;
        }
    }
    
    //Adds a payment from one individual to another to the front of the ledger 
    int Ledger::AddPayment(string fromName, string toName, double amount){
         Node* newNode = new Node();
        newNode->setFromName(fromName);
        newNode->setToName(toName);
        newNode->setData(amount);
        newNode->setID(count++);
        newNode->setNext(head);
        head = newNode;
        if(myMap.count(fromName) <=0 ){
            myMap[fromName] = 0 - amount;
        }else{
            double temp = myMap[fromName];
            myMap[fromName] = temp - amount;
        }

        if(myMap.count(toName) <=0 ){
            myMap[toName] = amount;
        }else{
            double temp = myMap[toName];
            myMap[toName] = temp + amount;
        }
        return newNode->getID();
    }

    //refunds the payment by finding the given node id. 1 arg
    int Ledger::RefundPayment(int id){
        Node *temp;
        temp = head;
        while(temp->getNext() != NULL){
            if(temp->getID() == id){
                if(temp->getFromName() == "External"){
                    double tempMoney = myMap[temp->getToName()];
                    myMap[temp->getToName()] = tempMoney - temp->getData();
                }else{
                    double tempMoney = myMap[temp->getToName()];
                    myMap[temp->getToName()] = tempMoney - temp->getData();
                    tempMoney = myMap[temp->getFromName()];
                    myMap[temp->getFromName()] = tempMoney + temp->getData();
                }
                temp->setData(head->getData());
                temp->setFromName(head->getFromName());
                temp->setID(head->getID());
                temp->setToName(head->getToName());
                Node* newTemp = head;
                head = head->getNext();
                newTemp->setNext(NULL);
                delete newTemp;
                newTemp = NULL;
                return id;
            }
        temp = temp->getNext();       
        }
        return -1;
    }

    //refunds a specific payment from one individual to another. 3 args 
    void Ledger::RefundPayment(string fromName, string toName, double amount){
        Node* temp;
        temp = head;
        while(temp->getNext() != NULL){
            if(temp->getFromName() == fromName & temp->getToName() == toName){
                double tempMoney = myMap[toName];
                myMap[toName] = tempMoney - temp->getData();
                tempMoney = myMap[fromName];
                myMap[fromName] = tempMoney + temp->getData();
                temp->setData(head->getData());
                temp->setFromName(head->getFromName());
                temp->setID(head->getID());
                temp->setToName(head->getToName());
                Node* newTemp = head;
                head = head->getNext();
                newTemp->setNext(NULL);
                delete newTemp;
                newTemp = NULL;
            }
        temp = temp->getNext();       
        }
    }

    //Wipes the content of the nodes and sets them to null in the ledger 
    void Ledger::clear(){ 
        Node* temp;
        while(head != NULL){
            temp = head;
            head = head->getNext();
            temp->setNext(NULL);
            delete temp;
        }
        temp = NULL;
        count = 0;
    }

    //prints all the nodesin the ledger 
    void Ledger::Print(){
        Node* temp;
        temp = head;
        while(temp != NULL){
            cout << "Sender: " << temp->getFromName() << ", Recipient: " << 
            temp->getToName() << ", Data: " << temp->getData() << " , ID: " 
            << temp->getID() << endl; 
            temp = temp->getNext();
        }
    }

    //prints the ledger transactions of one individual
    void Ledger::Print(string name){
        Node* temp;
        temp = head;
        while(temp != NULL){
            if(temp->getToName() == name || temp->getFromName() == name){
                cout << "Sender: " << temp->getFromName() << ", Recipient: " << 
                temp->getToName() << ", Data: " << temp->getData() << " , ID: " 
                << temp->getID() << endl; 
            }
            temp = temp->getNext();
        }
    }

    //prints the name and balance of each user 
    void Ledger::Settle(){
        for(auto const& pair: myMap){
            cout << "{" << pair.first << ", " << pair.second  << "}" << endl;
        }
    }

    //Prints the name and balance of each user with positive money 
    void Ledger::InTheBlack(){
        for(auto const& pair: myMap){
            if(pair.second >= 0){
                cout << "{" << pair.first << ", " << pair.second  << "}" << endl;
            }
        }
    }

    //Prints the name and balance of each user with negative money 
    void Ledger::InTheRed(){
        for(auto const& pair: myMap){
            if(pair.second < 0){
                cout << "{" << pair.first << ", " << pair.second  << "}" << endl;
            }
        }
    }