#include<conio.h>
#include<iostream.h>
#include<fstream.h>
#include<iomanip.h>
#include<string.h>
void medMenu();
void callMainMenu();
void memMenu();

struct date
{//to get dates from user
 int day;
 int month;
 int year;
};

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
void searchMed();
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
int memWeight;
char memSex ,memName[40],memNo[4];
char *memMob, *memAddress, *memEmail, *memStatus;//if use char array the file wont write with setw() function
struct date d; ///////
public:
void doPayment();
void addMem();
void rmvMem();
void renewMem();
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

/////////////////////////////////MEDICATION///////////////////////////////////////
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
medFile<<setw(10)<<medId<<setw(40)<<medName<<setw(20)<<setprecision(2)<<medPrice<<setw(20)<<medStock<<endl;
//setw will set column width, & setprecision will set floating point
cout<<endl<<endl<<"Add Another Medication ('y'-Yes, 'n'-No): " ;
cin>>loop; //this will decide the loop or other if condition 

}
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
while(!medFile.eof() ) //search through the file//.ef() will run the else part :D :D
  {
    medFile>>medId;	
		if(strcmp(id,medId)==0)
		{x=medFile.tellp();        //get the put pointer after reading the medId
		medFile>>medName>>medPrice>>medStock;//then read and get other record details
		medFile.seekp(x-4,ios::beg);
		cout<<endl<<endl<<"\t\t\t"<<"This Will Set Stock To 0."<<endl; getch();
		medFile<<medId<<setw(40)<<medName<<setw(20)<<setprecision(2)<<medPrice<<setw(20)<<"0";
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
int x,opt; //to store tellp
fstream medFile;
cout<<"1.Add New Stock"<<endl;
cout<<"2.Edit Medication Details"<<endl<<endl;
cout<<"Enter Your Option : ";
cin>>opt;

if (opt==2)
{clrscr();
char id[4];
medFile.open("med.cg",ios::in|ios::out); //read for in & Out
cout<<endl<<"Enter Medication(ID) To Update:"; cin>>id;
while(!medFile.eof() ) //search through the file
  {
    medFile>>medId;	//first get the d
		if(strcmp(id,medId)==0)
		{ x=medFile.tellp();
	medFile.seekp(x-10,ios::beg);
	clrscr();
	cout<<"\t\t"<<"_____Editing Medication In The DataBase____"<<endl;
	cout<<"Enter Medication ID (Use Four Numbers EX-0000) : "; cin>>medId;
	cout<<"Enter New Medication Name (Don't Use Space) : "; cin>>medName;
	cout<<"Enter New Medication Price : "; cin>>medPrice;
	cout<<"Enter Adding Stock Size : "; cin>>medStock; clrscr();
	medFile<<setw(10)<<medId<<setw(40)<<medName<<setw(20)<<setprecision(2)<<medPrice<<setw(20)<<medStock;
	cout<<endl<<"New Details Successfully Added To The Database.."<<endl;getch();
	break; //if edited break
		 }
	else
	 {
	 medFile>>medName>>medPrice>>medStock;
	 }
	
	}
}		

else if(opt==1)
{clrscr();
char id[4];
int newStock;
medFile.open("med.cg",ios::in|ios::out); //read for in & Out
cout<<endl<<"Enter Medication(ID) To Add New Stock:"; cin>>id;
while(!medFile.eof() ) //search through the file
  {
    medFile>>medId;	//first get the d
		if(strcmp(id,medId)==0)
		{ x=medFile.tellp();
		medFile>>medName>>medPrice>>medStock;
	medFile.seekp(x-10,ios::beg);
	clrscr();
	cout<<"\t\t"<<"_____Add Medication To DataBase____"<<endl;
	cout<<"Enter New Medication Price : "; cin>>medPrice;
	cout<<"Enter New Stock Size : "; cin>>newStock; clrscr();
	    
		//char to int convertation		//char to int gives ASCII values		//convert them to integers
		int  i, len;
		int intMedStock=0;
		len = strlen(medStock);
		for(i=0; i<len; i++){
		intMedStock = intMedStock * 10 + ( medStock[i] - '0' );
		}
		
    newStock=newStock+intMedStock;
	medFile<<setw(10)<<medId<<setw(40)<<medName<<setw(20)<<setprecision(2)<<medPrice<<setw(20)<<newStock;
	cout<<endl<<"New Stock Details Successfully Added To The Database.."<<endl;getch();
	break; //if edited break
		 }
	else
	 {
	 medFile>>medName>>medPrice>>medStock;
	 }
	
	}
}		

else
{clrscr();
cout<<endl<<endl<<"Incorrect Input..!"; getch();
}
medFile.close();


}

void medication::searchMed(){
clrscr();
int x; //to store tellp
char id[4];
fstream medFile;
medFile.open("med.cg",ios::in); //read for in & Out
cout<<endl<<"Enter Medication(ID) To Get Details : "; cin>>id;
clrscr();
while(!medFile.eof() ) //search through the file
  {
		medFile>>medId;		//first get the d
		if(strcmp(id,medId)==0)
		{   x=medFile.tellg();
			medFile>>medName>>medPrice>>medStock;
			medFile.seekg(x-4,ios::beg);
			cout<<medId<<"\t"<<medName<<"\t"<<setprecision(2)<<medPrice<<"\t"<<medStock;
			getch();
			break; //if edited break
		 }
		 else
		 {
		 medFile>>medName>>medPrice>>medStock;
		 continue;
		 }
		 
	}
	medFile.close();



}

			const void medMenu(){
			clrscr();
			int opt;
			medication mObj;
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			cout<<"\t\t\t"<<"___________MedicationMenu___________"<<endl;
			cout<<"\t\t\t\t"<<"1.Add Medication"<<endl;
			cout<<"\t\t\t\t"<<"2.Update Medication"<<endl;
			cout<<"\t\t\t\t"<<"3.Delete Medication"<<endl;
			cout<<"\t\t\t\t"<<"4.Search Medication"<<endl;
			cout<<"\t\t\t\t"<<"5.MainMenu"<<endl;
			cout<<"\t\t\t\t"<<"6.Exit"<<endl<<endl;
			cout<<"\t\t\t"<<"Enter Your Option:";	cin>>opt;
				switch(opt)
				{case 1:mObj.addMed();medMenu(); break;
				 case 2:mObj.upadteMed();medMenu(); break;
				 case 3:mObj.deleteMed();medMenu(); break;
				 case 4:mObj.searchMed();medMenu(); break;
				 case 5:clrscr(); callMainMenu(); break;
				 default :clrscr(); 
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
				cout<<"\t\t\t"<<"    Program Terminated..!"<<endl; break;
				}   }


				
////////////////////////////////////MEMBER////////////////////////////////////////////
void member::addMem(){
struct date d; //declare date structure variable
fstream memFile;
memFile.open("mem.cg",ios::app);
clrscr();
cout<<"\t\t"<<"_____Adding Member To DataBase____"<<endl;
cout<<endl<<"Enter Member ID(Use Four Numbers EX-0000) : "; cin>>memNo;
cout<<endl<<"Enter Member Name (Don't Use Space) : ";cin>>memName;
cout<<endl<<"Enter Member Waight (kg's): "; cin>>memWeight;
cout<<endl<<"Enter Member Registration Date (dd mm yyyy) : "; cin>>d.day>>d.month>>d.year;
cout<<endl<<"Enter Member Mobile No (Single Entry): "; cin>>memMob;
cout<<endl<<"Enter Member Address(Don't Use Space) : "; cin>>memAddress;
cout<<endl<<"Enter Member Sex ('F'-Female or 'M'-Male): "; cin>>memSex;
cout<<endl<<"Enter Member Email : ";cin>>memEmail;
memStatus="Registered";//member has registered
memFile<<setw(10)<<memNo<<setw(40)<<memName<<setw(10)<<memWeight<<setw(10)<<d.day<<" "<<d.month<<" "<<d.year<<setw(20)<<memMob<<setw(50)<<memAddress<<setw(10)<<memSex<<setw(40)<<memEmail<<setw(10)<<memStatus<<endl;
clrscr();
cout<<endl<<endl<<endl<<"New Member Added Successfully...!!"; getch();
memFile.close();
}

void member::renewMem(){
int x,renew;
char no[4];
struct date d; //declare date structure variable
fstream memFile;
memFile.open("mem.cg",ios::in|ios::out);
clrscr();
cout<<"\t\t"<<"_____Renew Membership____"<<endl;
cout<<endl<<"Enter Member ID to Update One Year(Use Four Numbers EX-0000) : "; cin>>no;
while(!memFile.eof() )
  {		memFile>>memNo;
		if(strcmp(no,memNo)==0)
		{   x=memFile.tellp();
			////x;getch();////////delete///
		    memFile>>memName>>memWeight>>d.day>>d.month>>d.year>>memMob>>memAddress>>memSex>>memEmail>>memStatus;
			//cout<<memName<<memWeight<<d.day<<d.month<<d.year<<memMob<<memAddress<<memSex<<memEmail<<endl; getch();///////delete//////////////
			memFile.seekp(x-10,ios::beg);
			renew=d.year+1;
			memFile<<setw(10)<<memNo<<setw(40)<<memName<<setw(10)<<memWeight<<setw(10)<<d.day<<" "<<d.month<<" "<<renew<<setw(20)<<memMob<<setw(50)<<memAddress<<setw(10)<<memSex<<setw(40)<<memEmail<<setw(10)<<memStatus<<endl;
			clrscr();
			cout<<endl<<endl<<endl<<" Membership Renewed For One Year...!!"; getch();
	      }
		else
		 {
		 memFile>>memName>>memWeight>>d.day>>d.month>>d.year>>memMob>>memAddress>>memSex>>memEmail>>memStatus;
		 continue;
		 }  
		  
		}
cin.sync(); 
memFile.close();
}

void member::rmvMem(){
date d;
int x;
char no[4];
fstream memFile;
memFile.open("mem.cg",ios::in|ios::out);
clrscr();
cout<<"\t\t"<<"_____Renew Membership____"<<endl;
cout<<endl<<"Enter Member ID to Remove(Use Four Numbers EX-0000) : "; cin>>no;
while(!memFile.eof() )
{
memFile>>memNo;
		if(strcmp(no,memNo)==0)
		{x=memFile.tellp();
		memFile>>memName>>memWeight>>d.day>>d.month>>d.year>>memMob>>memAddress>>memSex>>memEmail>>memStatus;
		memFile.seekp(x-10,ios::beg);
		memStatus="Removed";
		memFile<<setw(10)<<memNo<<setw(40)<<memName<<setw(10)<<memWeight<<setw(10)<<d.day<<" "<<d.month<<" "<<d.year<<setw(20)<<memMob<<setw(50)<<memAddress<<setw(10)<<memSex<<setw(40)<<memEmail<<memStatus<<endl;	   	
		cout<<endl<<endl<<endl<<"Member Removed..!!";getch();
		}
		else{
		 memFile>>memName>>memWeight>>d.day>>d.month>>d.year>>memMob>>memAddress>>memSex>>memEmail>>memStatus;
		 continue;		
		}
	}
memFile.close();	
}










			const void memMenu(){
			clrscr();
			int opt;
			member memObj;
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			cout<<"\t\t\t"<<"___________MemberMenu___________"<<endl;
			cout<<"\t\t\t\t"<<"1.Add Member"<<endl;
			cout<<"\t\t\t\t"<<"2.Renew Member Registration"<<endl;
			cout<<"\t\t\t\t"<<"3.Reomve Member"<<endl;
			cout<<"\t\t\t\t"<<"4.Search Member"<<endl;
			cout<<"\t\t\t\t"<<"5.Search Members Overdue"<<endl;
			cout<<"\t\t\t\t"<<"6.MainMenu"<<endl;
			cout<<"\t\t\t\t"<<"7.Exit"<<endl<<endl;
			cout<<"\t\t\t"<<"Enter Your Option:";	cin>>opt;
				switch(opt)
				{case 1:memObj.addMem();memMenu(); break;
				 case 2:memObj.renewMem();callMainMenu(); break;
				 case 3:memObj.rmvMem();memMenu(); break;
				// case 4:memObj.searchMed();memMenu(); break;
				 //case 5:clrscr(); callMainMenu(); break;
				 default :clrscr(); 
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
				cout<<"\t\t\t"<<"    Program Terminated..!"<<endl; break;
				}   }
			

			
			void callMainMenu(){clrscr();
			int opt;
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			cout<<"\t\t\t"<<"___________MainMenu___________"<<endl;
			cout<<"\t\t\t\t"<<"1.Medication"<<endl;
			cout<<"\t\t\t\t"<<"2.Member"<<endl;
			cout<<"\t\t\t\t"<<"3.Physican"<<endl<<endl;
			cout<<"\t\t\t"<<"Enter Your Option:";	cin>>opt;
			switch(opt)
			  {case 1: medMenu(); break;
			   case 2: memMenu(); break;
			  // case 3: phyMenu(); break;
			  }   }			
void main()
{clrscr();
callMainMenu();
getch();
}



