/**
 * Description: test driver for Ledger  
 * @author: Shubham Kamboj 
 * @version date: November 12, 2020 
 * */

#include "Ledger.h"


int main(){
    Ledger* one = new Ledger();
    cout << "------------------------------------" << endl;
    one->AddExternalMoney("Mike", 19.40);
    one->AddExternalMoney("Jay", 120.87);
    one->AddExternalMoney("Silo", 13.12);
    one->AddExternalMoney("Yotom", 1.26);
    cout << "------------------------------------" << endl;
    one->Print(); 
    cout << "------------------------------------" << endl;
    one->AddPayment("Jay", "Yotom", 50);
    one->AddPayment("Yotom", "Mike", .26);
    cout << "------------------------------------" << endl;
    one->Print("Yotom");
    cout << "------------------------------------" << endl;
    one->AddPayment("Mike", "Silo", 30);
    one->AddExternalMoney("Silo", 100);
    cout << "------------------------------------" << endl;
    one->Print();
    cout << "------------------------------------" << endl;
    one->RefundPayment(5);
    one->RefundPayment("Jay", "Yotom", 50);
    cout << "------------------------------------" << endl;
    cout << one->RefundPayment(8) << endl;
    cout << "------------------------------------" << endl;
    one-> AddPayment("Brian", "Yotom", 10);
    one->Print();
    cout << "------------------------------------" << endl;
    one->Settle();
    cout << "------------------------------------" << endl;
    one->AddPayment("Silo", "Mike", 120);
    cout << "------------------------------------" << endl;
    one->InTheBlack();
    cout << "------------------------------------" << endl;
    one->InTheRed();
    cout << "------------------------------------" << endl;
    one->clear();
    cout << "MEMORY CLEARED" << endl;
    cout << "------------------------------------" << endl;
    one->Print();
}