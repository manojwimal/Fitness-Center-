#include<conio.h>
#include<iostream.h>
#include<fstream.h>
#include<iomanip.h>
#include<string.h>
void medMenu();
void callMainMenu();
void memMenu();



class member{
int memWeight;
char memSex [1][5],memName[1][20],memNo[1][10];
char memMob[1][10], memAddress[1][20], memEmail[1][25],memStatus[1][10];
public:
void add(){
cout<<"\nweight=";
cin>>memWeight[0];
cout<<"\nemail";
cin>>memEmail[0];
char *stat;
stat="registered";
strcpy(memStatus[0],stat);
}
void dis(){
cout<<memWeight[0]<<setw(10)<<memEmail[0]<<setw(10)<<memStatus[0]<<endl;
}
};
void main(){
clrscr();
member m1;
fstream file;
file.open("www.txt",ios::ate|ios::in|ios::out|ios::binary);
cout<<"\nenter data";
m1.add();
cin.get(ch);
file.write((char *) & m1,sizeof m1);
cout<<"\ndisplay data";
file.seekg(0,ios::beg);
file.read((char *) & m1,sizeof m1);
m1.dis();
file.clear();
getch();
}

 



