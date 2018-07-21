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
char medStock[3],medName[40],medId[4];
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
cout<<"Enter Medication ID(Use Four Numbers EX-0000) : "; cin>>medId;
cout<<"Enter Medication Name (Don't Use Space) : ";cin>>medName;
cout<<"Enter Medication Price : "; cin>>medPrice;
cout<<"Enter Stock Of Medication Adding : "; cin>>medStock;
//cout <<medName; //remove
medFile<<setw(10)<<medId<<setw(40)<<medName<<setw(10)<<setprecision(2)<<medPrice<<setw(10)<<medStock<<endl;
//setw will set column width, & setprecision will set floating point
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


void medication::deleteMed(){
clrscr();
int x; //to store tellp
char id[4];
fstream medFile;
medFile.open("med.cg",ios::in|ios::out); //read for in & Out
cout<<endl<<"Enter Medication(ID) To Delete:"; cin>>id;
clrscr();
while(medFile) //search through the file
  {
    medFile>>medId;	
		if(strcmp(id,medId)==0)
		{x=medFile.tellp();        //get the put pointer after reading the medId
		medFile>>medName>>medPrice>>medStock;//then read and get other record details
		medFile.seekp(x-4,ios::beg);
		cout<<endl<<endl<<"\t\t\t"<<"This Will Set Stock To 0."<<endl; getch();
		medFile<<medId<<setw(30)<<medName<<setw(10)<<setprecision(2)<<medPrice<<setw(10)<<"0";
		cout<<endl<<endl<<"\t\t\t"<<"Stock Successfully Cleared.."<<endl; getch();
		break; //if edited break
		 }
		
		else
		{  medFile>>medName>>medPrice>>medStock;
		 }
	}
medFile.close();
}


void medication::upadteMed(){
clrscr();
int x; //to store tellp
char id[4];
fstream medFile;
medFile.open("med.cg",ios::in|ios::out); //read for in & Out
cout<<endl<<"Enter Medication(ID) To Update:"; cin>>id;
while(medFile) //search through the file
  {
    medFile>>medId;	//first get the d
		if(strcmp(id,medId)==0)
		{ x=medFile.tellp();
	medFile.seekp(x-4,ios::beg);
	clrscr();
	cout<<"\t\t"<<"_____Editing Medication In The DataBase____"<<endl;
	cout<<"Enter Medication ID (Use Four Numbers EX-0000) : "; cin>>medId;
	cout<<"Enter New Medication Name (Don't Use Space) : "; cin>>medName;
	cout<<"Enter New Medication Price : "; cin>>medPrice;
	cout<<"Enter Adding Stock Size : "; cin>>medStock;
	medFile<<medId<<setw(30)<<medName<<setw(10)<<setprecision(2)<<medPrice<<setw(10)<<medStock;
	clrscr();
	cout<<endl<<"New Details Successfully Added To The Database.."<<endl;
	break; //if edited break
		 }
		else
		{  medFile>>medName>>medPrice>>medStock;
		 }
	}
}


			void medMenu(){
			clrscr();
			int opt;
			medication mObj;
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			cout<<"\t\t\t"<<"___________MedicationMenu___________"<<endl;
			cout<<"\t\t\t\t"<<"1.Add Medication"<<endl;
			cout<<"\t\t\t\t"<<"2.Update Medication"<<endl;
			cout<<"\t\t\t\t"<<"3.Delete Medication"<<endl<<endl;
			cout<<"\t\t\t"<<"Enter Your Option:";	cin>>opt;
				switch(opt)
				{case 1:mObj.addMed();break;
				 case 2:mObj.upadteMed();break;
				 case 3:mObj.deleteMed();break;

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



