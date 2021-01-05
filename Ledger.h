/**
 * Description: Interface for Ledger
 * @author: Shubham Kamboj 
 * @version date: November 9, 2020 
 * */

#ifndef LEDGER_H
#define LEDGER_H

#include <iostream>
#include "Node.h"
#include <map>

using namespace std;

class Ledger{

private:
    Node* head; //creates node head 
    map<string, double> myMap; // a map to store the user and their balance 
    int count; //keeps track of the user id 
public: 
    Ledger();
    ~Ledger();
    void AddExternalMoney(string name, double amount);
    int AddPayment(string fromName, string toName, double amount);
    int RefundPayment(int id);
    void RefundPayment(string fromName, string toName, double amount);
    void clear();
    void Print();
    void Print(string name);
    void Settle();
    void InTheBlack();
    void InTheRed();
};

#endif