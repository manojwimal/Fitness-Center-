#include<conio.h>
#include<iostream.h>
#include<fstream.h>
#include<iomanip.h>
#include<string.h>
void medMenu();
void callMainMenu();


class physican{
int phyNo,phyAge;
char phyName[50],phyAddress[60];
public:
void prescribeMed();
void addPhy();
void updatePhy();
void deletePhy();
};

class medication{
double medPrice;
char medId[5],medStock[3],medName[60];
public:
void addMed();
void upadteMed();
void deleteMed();
};

class prescribe{
char date[20];
int medId,pNo;
int phyNo;
public:
void prData();
};

class supplier{
int supId,supTel;
char supName[50],supAddress[60];
public:
void addSup();
void deleteSup();
void updateSup();
};

class supply{
int supId,medId;
char supDate[15];
public:
void addSupData();
void updateSupData();
};

class payment{
int pNo,memId;
double pAmount;
char pDate[15],pType;
public:
void addPayment();
void deletePayment();
void refundPayment();
};

class member{
int memNo,memMob,memWeight;
char memName[50], memSex, memEmail[30], memDob[15], memAddress[60];
public:
void doPayment();
void getMed();
};

class physiotherapist{
int phpstId;
char phpstName[50], phpstAddress[60];
public:
void addPhysiotherapist();
void deletePhysiotherapist();
void provideTreatment();
};

class provideTreatment{
int phpstId, memNo;
char trtType[10],trtDate[15];
public:
void addTrtData();
};

class manager{
int manId;
char manName[50],manAddress[60];
public:

void addManager();
void deleteManager();
void reservePurchaseReport();
void addMem();
void updateMem();
};

class instructor{
int insId,insMob;
char insSex, insName[50], insAddress[60];
public:
void checkDetails();
void addIns();
void deleteins();
};

void medication::addMed(){
char loop='y'; // use to go first while loop
fstream medFile;
medFile.open("med.cg",ios::app);
while(loop=='y'){//if loop=y the loop will continue 
if(loop=='y'){//checking after first loop whether the continue the loop
clrscr();
cout<<"\t\t"<<"_____Adding Medication To DataBase____"<<endl;
cout<<"Enter Medication ID:"; cin>>medId;
cout<<"Enter Medication Name:";cin.ignore();  cin.get( medName, 60 );
cout<<"Enter Medication Price:"; cin>>medPrice;
cout<<"Enter Stock Of Medication Adding:"; cin>>medStock;
//cout <<medName; //remove
medFile<<medId<<"\t"<<medName<<setprecision(2)<<"\t"<<medPrice<<"\t"<<medStock<<endl;
cout<<endl<<endl<<"Add Another Medication ('y'-Yes, 'n'-No): " ;
cin>>loop; //this will decide the loop or other if condition 

	if( loop=='n')
	{int opt;
	clrscr();
	cout<<endl<<"_____SubMenu_____"<<endl;
	cout<<endl<<"1.Move To MainMenu";
	cout<<endl<<"2.Move To MedicationMenu";
	cout<<endl<<"3.Exit"<<endl<<endl;
	cout<<"\t\t\t"<<"Enter Your Option:";	cin>>opt;
	switch(opt)
	{case 1:clrscr();callMainMenu();break;
	 case 2:clrscr();medMenu();break;
	 default :clrscr(); 
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"\t\t\t"<<"    Program Terminated..!"<<endl; break;
	}

	}        }
}//while loop
medFile.close();
}

void medication::upadteMed(){
clrscr();
char id[5]; //medId is a char variable, if user enter a char into a int, program will loop. and the database will be messedup
int x,y;
fstream medFile;
medFile.open("med.cg",ios::in|ios::out);
cout<<endl<<"Enter Medication(ID) To Update:"; cin>>id;
while(medFile)
  {//cout<<id<<endl;
    medFile>>medId;
    if(int(medId)== int(id))
    {
      x=medFile.tellg();
	  y=medFile.tellp();
	  cout<<medId<<endl<<x<<endl<<y;
      break;
    }
	else{
	medFile>>medName>>medPrice>>medStock;
	}
}
medFile.seekp(x,ios::beg);
medFile<<endl<<0<<"\t"<<0<<"\t"<<0<<"\t"<<0<<endl;
medFile.close();
}

			void medMenu(){
			clrscr();
			int opt;
			medication mObj;
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			cout<<"\t\t\t"<<"___________MedicationMenu___________"<<endl;
			cout<<"\t\t\t\t"<<"1.Add Medication"<<endl;
			cout<<"\t\t\t\t"<<"2.Update Medication"<<endl;
			cout<<"\t\t\t\t"<<"2.Delete Medication"<<endl<<endl;
			cout<<"\t\t\t"<<"Enter Your Option:";	cin>>opt;
				switch(opt)
				{case 1:mObj.addMed();break;
				 case 2:mObj.upadteMed();break;
				}   }
			
			void callMainMenu(){
			int opt;

			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			cout<<"\t\t\t"<<"___________MainMenu___________"<<endl;
			cout<<"\t\t\t\t"<<"1.Medication"<<endl;
			cout<<"\t\t\t\t"<<"2.Member"<<endl<<endl;
			cout<<"\t\t\t"<<"Enter Your Option:";	cin>>opt;
			switch(opt)
			  {case 1: medMenu(); break;

			  }   }

void main()
{clrscr();
callMainMenu();
getch();
}



