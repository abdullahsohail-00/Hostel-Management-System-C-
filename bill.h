#ifndef BILL_H
#define BILL_H

#include<fstream>
using namespace std;

class billPayment{                                                   //Display bill Payment
   private:
    string z;
     char b;
    public :
     void insertBill();

     void Displaybill();
     
     void deleteOrder();
};
#endif