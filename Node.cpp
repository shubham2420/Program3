/**
 * Description: Implementation for node 
 * @author: Shubham Kamboj 
 * @version date: November 12, 2020 
 * */

#include "Node.h"

    //no arg constructor for node 
    Node::Node(){
        this->next = NULL;
    }

    //returns the id of the node
    int Node::getID() const{
        return id;
    }

    //sets the id of the node
    void Node::setID(const int id){
        this->id = id;
    }

    //gets the data of the node 
    double Node::getData() const{
        return data;
    }

    //sets the data of the node 
    void Node::setData(const double data){
        this->data = data;
    }

    //gets the name from the money is coming from 
    string Node::getFromName() const{
        return fromName;
    }

    //sets the name from who the money is coming from 
    void Node::setFromName(const string name){
        this->fromName = name;
    }

    //gets the name of who is recieiving the money 
    string Node::getToName() const{
        return toName;
    }

    //sets the name of who is recieving the money 
    void Node::setToName(const string name){
        this->toName = name;
    }

    //gets the next node 
    Node* Node::getNext() const{
        return next;
    }

    //sets the next node 
    void Node::setNext(Node* myNode){
        this->next = myNode;
    }