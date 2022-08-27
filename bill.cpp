#include<iostream>
#include<string>
#include<windows.h>
#include"manager.h"
#include"staff.h"
#include"room.h"
#include"bill.h"
#include<fstream>
using namespace std;

    static int amount , count , ch_K_H , ch_K_F , s_k_f , s_k_h , fishf, fishh;

     void billPayment::insertBill(){
      while(true){
       g:
       system("cls");
     	 cout<<"\n\t\t\t\tOrder Your Food\n";
     	 cout<<"\n\tPress 1 For Chicken karhai full   800 PKR";
       cout<<"\n\tPress 2 For Chicken karhai half   400 PKR"; 
     	 cout<<"\n\tPress 3 For Sekh kabab 12 pcs     300 PKR";  
     	 cout<<"\n\tPress 4 For Sekh kabab 6 pcs      150 PKR";
     	 cout<<"\n\tPress 5 For Fish 1 kg             900 PKR";
     	 cout<<"\n\tPress 6 For Fish 1/2 kg           450 PKR";
       cout<<"\n\tPress 7 For Enough Order\n";
       cin>>b;

     	 if(b=='1')
         {
          if(count<=50){
          amount = amount + 800 ;
          count = count + 1;
          ch_K_F=ch_K_F+1;
          cout<<"\nOrder Successfull";
          Sleep(1000);
          }else
          {
          cout<<"No More Full Chicken Karhai Available!"<<endl;
          Sleep(1000);         
          }
          }else if(b=='2')
          {
          if(count<=50)
          {
          amount = amount + 400 ;
          count = count + 1;
          ch_K_H = ch_K_H+1;
          cout<<"\nOrder Successfull";
          Sleep(1000);          
          }else
          {
          cout<<"No more Half Chicken Karhai Available!"<<endl;
          Sleep(1000);
          }
          }else if(b=='3')
          {
          if(count<=50){
          amount = amount + 300 ;
          count = count + 1;
          s_k_f=s_k_f+1; 
          cout<<"\nOrder Successfull";
          Sleep(1000); 
          }else
          {
          cout<<"No more Full Plate Seekh Kabab Available !"<<endl;
          Sleep(1000);
          }
          }else if(b=='4')
          {
          if(count<=50)
          {
          amount = amount + 150 ;
          count = count + 1;
          s_k_h=s_k_h+1; 
          cout<<"\nOrder Successfull";
          Sleep(1000); 
          }else
          {
          cout<<"No more Half Plate Seekh Kabab Available !"<<endl;
          Sleep(1000);
          }
          }else if(b=='5')
          {
          if(count<=50)
          {
          amount = amount + 900 ;
          count = count + 1;
          fishf=fishf+1; 
          cout<<"\nOrder Successfull";
          Sleep(1000);          
          }else
          {
          cout<<"No more 1KG Fish Available !"<<endl;
          Sleep(1000);
          }
          }else if(b=='6')
          {
          if(count<=50)
          {
          amount = amount + 450 ;
          count = count + 1;
          fishh=fishh+1; 
          cout<<"\nOrder Successfull";
          Sleep(1000); 
          }else
          {
          cout<<"No more 1/2 KG Fish Available !"<<endl;
          Sleep(1000);
          }
          }else if(b=='7')
          {
             goto t;
          }else
          {
             cout<<"\n\tPress Correct Number\n";
             Sleep(3000);
             goto g;
          }
          }
          t: 
          cin.ignore();
      }
    
     void billPayment::Displaybill(){
         system("cls");
         if((ch_K_F || ch_K_H || s_k_f || s_k_h || fishf || fishh || amount) > 0){  
             cout<<"\n\t\t\t\tDisplay Payment\n";
             Sleep(800);
             cout<<"**************************************"<<endl;
             cout<<"Number of Chicken karhai full = "<<ch_K_F<<endl;
             cout<<"Number of Chicken karhai half = "<<ch_K_H<<endl;
             cout<<"Number of Sekh kabab 12 pcs   = "<<s_k_f<<endl;
             cout<<"Number of Sekh kabab 6 pcs    = "<<s_k_h<<endl;
             cout<<"Number of Fish 1 kg           = "<<fishf<<endl;
             cout<<"Number of Fish 1/2 kg         = "<<fishh<<endl;
             cout<<"Total amount                  = "<<amount<<endl;
             cout<<"**************************************"<<endl;
          }else{
             cout<<"\n\tPayment Bill is Empty!";
          }
     }

     void billPayment::deleteOrder(){
    while(true){
      	 g:
         system("cls");
       cout<<"\n\t\t\tYour pending Orders\n";
       cout<<"\n\tChicken karhai Full :"<<ch_K_F;
       cout<<"\n\tChicken karhai Half :"<<ch_K_H;
       cout<<"\n\t Sekh kabab 12 pcs  :"<<s_k_f;
       cout<<"\n\t  Sekh kabab 6 pcs  :"<<s_k_h;
       cout<<"\n\t    Fish 1 kg       :"<<fishf;
       cout<<"\n\t   Fish 1/2 kg      :"<<fishh;
       cout<<"\n\t   Total amount     :"<<amount;         

     	 cout<<"\n\n\t\t\t\tDelete Your Food\n";	
   	 cout<<"\n\tPress 1 For Chicken karhai full ";    
       cout<<"\n\tPress 2 For Chicken karhai half "; 
     	 cout<<"\n\tPress 3 For Sekh kabab 12 pcs   ";  
     	 cout<<"\n\tPress 4 For Sekh kabab 6 pcs    ";
     	 cout<<"\n\tPress 5 For Fish 1 kg           ";
     	 cout<<"\n\tPress 6 For Fish 1/2 kg         ";
       cout<<"\n\tPress 7 For Enough Delete Order\n";
       cin>>b;
     	 if(b=='1'){
          if(ch_K_F>0){
          amount = amount - 800 ;
          count = count - 1;
          ch_K_F=ch_K_F-1;
          cout<<"\nOrder Cancel Successfull";
          Sleep(1000);          
          }else{
          cout<<"No Pending Full Chicken Karhai Available!"<<endl;
          cout<<"\n\n\tPress any key for Continue\n";
			 cin>>z;          
          }
          }else if(b=='2'){
          if(ch_K_H>0){
          amount = amount - 400 ;
          count = count - 1;
          ch_K_H = ch_K_H-1;
          cout<<"\nOrder Cancel Successfull";
          Sleep(1000);
          }else{
          cout<<"No Pending Half Chicken Karhai Available!"<<endl;
          cout<<"\n\n\tPress any key for Continue\n";
			 cin>>z;         
          }
          }else if(b=='3'){
          if(s_k_f>0){
          amount = amount - 300 ;
          count = count - 1;
          s_k_f=s_k_f-1; 
          cout<<"\nOrder Cancel Successfull";
          Sleep(1000); 
          }else{
          cout<<"No Pending Full Plate Seekh Kabab Available !"<<endl;
          cout<<"\n\n\tPress any key for Continue\n";
			 cin>>z;         
          }
          }else if(b=='4'){
          if(s_k_h>0){
          amount = amount - 150 ;
          count = count - 1;
          s_k_h=s_k_h-1; 
          cout<<"\nOrder Cancel Successfull";
          Sleep(1000); 
          }else{
          cout<<"No Pending Half Plate Seekh Kabab Available !"<<endl;
          cout<<"\n\n\tPress any key for Continue\n";
			 cin>>z;
          }
          }else if(b=='5'){
          if(fishf>0){
          amount = amount - 900 ;
          count = count - 1;
          fishf=fishf-1; 
          cout<<"\nOrder Cancel Successfull";
          Sleep(1000);  
          }else{
          cout<<"No Pending 1KG Fish Available !"<<endl;
          cout<<"\n\n\tPress any key for Continue\n";
			 cin>>z;         
          }
          }else if(b=='6'){
          if(fishh>0){
          amount = amount - 450 ;
          count = count - 1;
          fishh=fishh-1; 
          cout<<"\nOrder Cancel Successfull";
          Sleep(1000);  
          }else{
          cout<<"No Pending 1/2 KG Fish Available !"<<endl;
          cout<<"\n\n\tPress any key for Continue\n";
			 cin>>z;        
          }
          }else if(b=='7'){            
             goto t;
          }else{
             cout<<"\n\tPress Correct Number\n";
             Sleep(3000);
             goto g;
          }
          system("cls");
          }
          system("cls");
          t: 
          cin.ignore();      
       }