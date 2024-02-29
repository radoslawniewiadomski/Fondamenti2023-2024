#include<iostream>
using namespace std;

main(){
 char st[20];
 char st2[20];

 char *p,*j;
 cout<<"inserisci una stringa di massimo 20 elementi: ";
 cin>>st;

 p=&st[0];
 j=&st2[0];

 do{
     *j=*p;
     p++;j++;
 }while(*p!='\0');

 *j='\0';
 cout<<st2;

}

