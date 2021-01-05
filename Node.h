/**
 * Description: Interface for Node
 * @author: Shubham Kamboj 
 * @version date: November 9, 2020 
 * */

#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;
class Node{
    private: 
        int id;
        double data;
        string fromName;
        string toName;
        Node *next;
    
    public: 
        Node();
        int getID() const;
        void setID(const int id);
        double getData() const;
        void setData(const double data);
        string getFromName() const;
        void setFromName(const string name);
        string getToName() const;
        void setToName(const string name);
        Node* getNext() const;
        void setNext(Node* myNode);
};

#endif