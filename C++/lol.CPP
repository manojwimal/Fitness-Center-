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
char phyNo[4],phyName[50];
char phySex[10], phyAddress[50];
public:
void prescribeMed();
void addPhy();
void updatePhy();
void deletePhy();
void schPhy();
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
char supId[4],supTel[10];
char supName[50],supAddress[60];
public:
void addSup();
void deleteSup();
void updateSup();
void schSup();
};

class supply{
int supId,medId;
char supDate[15];
public:
void schPhy();
void addSupData();
void updateSupData();
};

class payment{
int pNo;
char memId[4];
double pAmount;
char pDate[15],pType[15];
public:
void addPayment(char *a);
void deletePayment();
void searchPayment();

};

class member{
int memWeight;
char memName[40],memNo[4];
char *memMob, *memAddress, *memSex , *memEmail;//if use char array the file wont write with setw() function
struct date d;/////////////////////////////
public:
void doPayment();
void addMem();
void schMem();
void chgWghtMem();
void renewMem();
void getMed();
};

class physiotherapist{
char  phpstId[4];
char phpstName[50], phpstAddress[60];
public:
void addPhysiotherapist();
void updatePhysiotherapist();
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
char manId[4];
char manName[50],manAddress[60];
public:

void addManager();
void deleteManager();
void reservePurchaseReport();
void addMem();
void updateMem();
};

class instructor{
char insId[4],insMob[10];
char insSex[10], insName[50], insAddress[60];//insSex[10] if we dont use an array size, file data cannot be seperated (no column)
public:
void checkDetails();
void addIns();
void deleteIns();
void updateIns();

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
memFile<<setw(10)<<memNo<<setw(40)<<memName<<setw(10)<<memWeight<<setw(10)<<d.day<<" "<<d.month<<" "<<d.year<<setw(20)<<memMob<<setw(50)<<memAddress<<setw(10)<<memSex<<setw(40)<<memEmail<<endl;
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
		    memFile>>memName>>memWeight>>d.day>>d.month>>d.year>>memMob>>memAddress>>memSex>>memEmail;
			memFile<<setw(10)<<" "<<setw(40)<<" "<<setw(10)<<" "<<setw(10)<<" "<<setw(20)<<" "<<setw(50)<<" "<<setw(10)<<" "<<setw(40)<<" "<<endl;
			memFile.seekp(x-10,ios::beg);
			renew=d.year+1;
			memFile<<setw(10)<<memNo<<setw(40)<<memName<<setw(10)<<memWeight<<setw(10)<<d.day<<" "<<d.month<<" "<<renew<<setw(20)<<memMob<<setw(50)<<memAddress<<setw(10)<<memSex<<setw(40)<<memEmail<<endl;
			clrscr();
					cout<<endl<<"Member No: "<<memNo<<"\n"<<"Member Name: "<<memName<<"\n"<<"Member Weight: "<<memWeight<<"\n"<<"Registration Date: "<<d.day<<" "<<d.month<<" "<<d.year<<"\n"<<"Member Mobile No: "<<memMob<<"\n"<<"Member Address: "<<memAddress<<"\n"<<"Member Sex: "<<memSex<<"\n"<<"Member Email: "<<memEmail;

			cout<<endl<<endl<<endl<<" Membership Renewed For One Year...!!"; getch();
	      }
		else
		 {
		 memFile>>memName>>memWeight>>d.day>>d.month>>d.year>>memMob>>memAddress>>memSex>>memEmail;
		 continue;
		 }

		}
memFile.close();
}		

void member::schMem(){
int x;
char no[4];
struct date d; //declare date structure variable
fstream memFile;
memFile.open("mem.cg",ios::in|ios::out);
clrscr();
cout<<"\t\t"<<"_____Search Member____"<<endl;
cout<<endl<<"Enter Member ID to Search(se Four Numbers EX-0000) : "; cin>>no;
while(!memFile.eof() )
  {		memFile>>memNo;
		if(strcmp(no,memNo)==0)
		{
		    memFile>>memName>>memWeight>>d.day>>d.month>>d.year>>memMob>>memAddress>>memSex>>memEmail;
			clrscr();
			cout<<endl<<"Member No: "<<memNo<<"\n"<<"Member Name: "<<memName<<"\n"<<"Member Weight: "<<memWeight<<"\n"<<"Registration Date: "<<d.day<<" "<<d.month<<" "<<d.year<<"\n"<<"Member Mobile No: "<<memMob<<"\n"<<"Member Address: "<<memAddress<<"\n"<<"Member Sex: "<<memSex<<"\n"<<"Member Email: "<<memEmail;
			getch(); break;
	      }
		else
		 {
		 memFile>>memName>>memWeight>>d.day>>d.month>>d.year>>memMob>>memAddress>>memSex>>memEmail;
		 continue;
		 }

		}
memFile.close();
}

void member::chgWghtMem()
{
int x,nwWght;
char no[4];
struct date d; //declare date structure variable
fstream memFile;
memFile.open("mem.cg",ios::in|ios::out);
clrscr();
cout<<"\t\t"<<"_____Change Member Weight____"<<endl;
cout<<endl<<"Enter Member ID to Update His Weight(Use Four Numbers EX-0000) : "; cin>>no;
while(!memFile.eof() )
  {		memFile>>memNo;
		if(strcmp(no,memNo)==0)
		{   x=memFile.tellp();
		    memFile>>memName>>memWeight>>d.day>>d.month>>d.year>>memMob>>memAddress>>memSex>>memEmail;
			cout<<endl<<"Enter New Weight: "; cin>>nwWght;
			memFile.seekp(x-10,ios::beg);
			memFile<<setw(10)<<memNo<<setw(40)<<memName<<setw(10)<<nwWght<<setw(10)<<d.day<<" "<<d.month<<" "<<d.year<<setw(20)<<memMob<<setw(50)<<memAddress<<setw(10)<<memSex<<setw(40)<<memEmail<<endl;
			clrscr();

			cout<<endl<<endl<<endl<<" Member Weight Updated...!!"; getch();
	      }
		else
		 {
		 memFile>>memName>>memWeight>>d.day>>d.month>>d.year>>memMob>>memAddress>>memSex>>memEmail;
		 continue;
		 }

		}
memFile.close();
}

void member::doPayment()
{
int x;
char no[4];
struct date d; //declare date structure variable
fstream memFile;
memFile.open("mem.cg",ios::in|ios::out);
clrscr();
cout<<"\t\t"<<"_____Search Member____"<<endl;
cout<<endl<<"Enter Member ID to Search(Onlt Four Digits EX-0000) : "; cin>>no;
while(!memFile.eof() )
  {		memFile>>memNo;
		if(strcmp(no,memNo)==0)
		{	clrscr();
			cout<<endl<<endl<<"Member Registred In The Database."; getch();
		    payment p; //call payment class
			p.addPayment(memNo);
	      }
		else
		 {
		 memFile>>memName>>memWeight>>d.day>>d.month>>d.year>>memMob>>memAddress>>memSex>>memEmail;
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
			cout<<"\t\t\t\t"<<"3.Search Member"<<endl;
			cout<<"\t\t\t\t"<<"4.Change Member Weight"<<endl;
			cout<<"\t\t\t\t"<<"5.Add Member Payments"<<endl;
			cout<<"\t\t\t\t"<<"6.MainMenu"<<endl;
			cout<<"\t\t\t\t"<<"7.Exit"<<endl<<endl;
			cout<<"\t\t\t"<<"Enter Your Option:";	cin>>opt;
				switch(opt)
				{case 1:memObj.addMem();memMenu(); break;
				 case 2:memObj.renewMem();memMenu(); break;
				 case 3:memObj.schMem() ;memMenu(); break;
				 case 4:memObj.chgWghtMem();memMenu(); break;
				 case 5:memObj.doPayment();memMenu(); break;
				 case 6:clrscr(); callMainMenu(); break;
				 default :clrscr();
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
				cout<<"\t\t\t"<<"    Program Terminated..!"<<endl; break;
				}   }


				

///////////////////////////////////PHYSICAN//////////////////////////////////////////////////	

void physican::addPhy()
{
fstream phyFile;
phyFile.open("phys.cg",ios::app);
clrscr();
cout<<"\t\t"<<"_____Adding Physican To DataBase____"<<endl;
cout<<endl<<"Enter Physican No(Use Four Numbers EX-0000) : "; cin>>phyNo;
phyFile<<setw(10)<<phyNo;
cout<<endl<<"Enter Physican Address(Don't Use Space) : "; cin>>phyAddress;
phyFile<<setw(50)<<phyAddress;
cout<<endl<<"Enter Physican Name (Don't Use Space) : ";cin>>phyName;
phyFile<<setw(50)<<phyName;
cout<<endl<<"Enter Physican Sex('F'-Female or 'M'-Male): "; cin>>phySex;
phyFile<<setw(10)<<phySex<<endl;
//phyFile<<setw(10)<<phyNo<<setw(50)<<phyName<<setw(60)<<phyAddress<<setw(20)<<phySex<<endl;
clrscr();
cout<<endl<<endl<<endl<<"New Physican Added Successfully...!!"; getch();
phyFile.close();
}

void physican::updatePhy()
{int x;
char no[4];
fstream phyFile;
phyFile.open("phys.cg",ios::in|ios::out);
clrscr();
cout<<"\t\t"<<"_____Update Physican In DataBase____"<<endl;
cout<<endl<<"Enter Physican No to Update His Details(Use Four Numbers EX-0000) : "; cin>>no;
while(!phyFile.eof() )
  {		phyFile>>phyNo;
		if(strcmp(no,phyNo)==0)
		{   x=phyFile.tellp();
		    phyFile>>phyAddress>>phyName>>phySex;
			phyFile.seekp(x-10,ios::beg);
			phyFile<<setw(10)<<" "<<setw(50)<<" "<<setw(50)<<" "<<setw(10)<<" ";//after this the seekp will change
			clrscr();
			   phyFile.seekp(x-10,ios::beg);//because of that we need to pint to the location
				cout<<endl<<"Enter Physican No(Use Four Numbers EX-0000) : "; cin>>phyNo;
				phyFile<<setw(10)<<phyNo;
				cout<<endl<<"Enter Physican Address(Don't Use Space) : "; cin>>phyAddress;
				phyFile<<setw(50)<<phyAddress;
				cout<<endl<<"Enter Physican Name (Don't Use Space) : ";cin>>phyName;
				phyFile<<setw(50)<<phyName;
				cout<<endl<<"Enter Physican Sex('F'-Female or 'M'-Male): "; cin>>phySex;
				phyFile<<setw(10)<<phySex<<endl;
							
			clrscr();
			cout<<endl<<endl<<endl<<" Physican Details Updated...!!"; getch();
	      }
		else
		 {
		    phyFile>>phyAddress>>phyName>>phySex;
		 continue;
		 }

		}
phyFile.close();

}			

void physican::deletePhy()
{int x;
char no[4];
fstream phyFile;
phyFile.open("phys.cg",ios::in|ios::out);
clrscr();
cout<<"\t\t"<<"_____Delete Physican In DataBase____"<<endl;
cout<<endl<<"Enter Physican No to Delete His Details(Use Four Numbers EX-0000) : "; cin>>no;
while(!phyFile.eof() )
  {		phyFile>>phyNo;
		if(strcmp(no,phyNo)==0)
		{   x=phyFile.tellp();
		    phyFile>>phyAddress>>phyName>>phySex;
			clrscr();
			   phyFile.seekp(x+50,ios::beg);//because of that we need to pin to the location
				strcat(phyName,"(Deleted)"); //"(Deleted)" string append to the end of phyName variable
				phyFile<<setw(50)<<phyName;
							
			clrscr();
			cout<<endl<<endl<<endl<<" Physican Details Changed To Deleted...!!"; getch();
	      }
		else
		 {
		    phyFile>>phyAddress>>phyName>>phySex;
		 continue;
		 }

		}
phyFile.close();

}			
			
void physican::schPhy()
{
int x;
char no[4];
fstream phyFile;
phyFile.open("phys.cg",ios::in);
clrscr();
cout<<"\t\t"<<"_____Search Physican____"<<endl;
cout<<endl<<"Enter Physican ID to Search(se Four Numbers EX-0000) : "; cin>>no;
while(!phyFile.eof() )
  {		phyFile>>phyNo;
		if(strcmp(no,phyNo)==0)
		{	clrscr();
			phyFile>>phyAddress>>phyName>>phySex;
			cout<<"Physican ID: "<<no<<endl;
			cout<<"Physican Name: "<<phyName<<endl;
			cout<<"Physican Sex: "<<phySex<<endl;
			cout<<"Physican Address: "<<phyAddress<<endl;			
			getch();
			clrscr(); break;
	      }
        else
		 {
		    phyFile>>phyAddress>>phyName>>phySex;
		 continue;
		 }


	}
phyFile.close();
}		

		
			const void physMenu(){
			clrscr();
			int opt;
			physican physObj;
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			cout<<"\t\t\t"<<"___________MemberMenu___________"<<endl;
			cout<<"\t\t\t\t"<<"1.Add Physican"<<endl;
			cout<<"\t\t\t\t"<<"2.Edit Physican"<<endl;
			cout<<"\t\t\t\t"<<"3.Delete Physican"<<endl;
			cout<<"\t\t\t\t"<<"4.Search Physican"<<endl;
			cout<<"\t\t\t\t"<<"5.MainMenu"<<endl;
			cout<<"\t\t\t\t"<<"6.Exit"<<endl<<endl;
			cout<<"\t\t\t"<<"Enter Your Option:";	cin>>opt;
				switch(opt)
				{case 1:physObj.addPhy();physMenu(); break;
				 case 2:physObj.updatePhy();physMenu(); break;
				 case 3:physObj.deletePhy() ;physMenu(); break;
				 case 4:physObj.schPhy() ;physMenu(); break;
				 case 5:clrscr(); callMainMenu(); break;
				 default :clrscr();
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
				cout<<"\t\t\t"<<"    Program Terminated..!"<<endl; break;
				}   }



///////////////////////////////////SUPPLIER//////////////////////////////////////////////////	

void supplier::addSup()
{
fstream supFile;
supFile.open("sup.cg",ios::app);
clrscr();
cout<<"\t\t"<<"_____Adding Supplier To DataBase____"<<endl;
cout<<endl<<"Enter Supplier No(Use Four Numbers EX-0000) : "; cin>>supId;
supFile<<setw(10)<<supId;
cout<<endl<<"Enter Supplier Name(Don't Use Space) : "; cin>>supName;
supFile<<setw(50)<<supName;
cout<<endl<<"Enter Supplier Address (Don't Use Space) : ";cin>>supAddress;
supFile<<setw(50)<<supAddress;
cout<<endl<<"Enter Supplier Telephone No( Single Entry Only): "; cin>>supTel;
supFile<<setw(20)<<supTel<<endl;
clrscr();
cout<<endl<<endl<<endl<<"New Supplier Added Successfully...!!"; getch();
supFile.close();
}
				
void supplier::updateSup()
{int x;
char no[4];
fstream supFile;
supFile.open("sup.cg",ios::in|ios::out);
clrscr();
cout<<"\t\t"<<"_____Update Supplier In DataBase____"<<endl;
cout<<endl<<"Enter Supplier No to Update His Details(Use Four Numbers EX-0000) : "; cin>>no;
while(!supFile.eof() )
  {		supFile>>supId;
		if(strcmp(no,supId)==0)
		{   x=supFile.tellp();
		    supFile>>supName>>supAddress>>supTel;
			supFile.seekp(x-10,ios::beg);
					cout<<endl<<"Enter Supplier No(Use Four Numbers EX-0000) : "; cin>>supId;
					supFile<<setw(10)<<supId;
					cout<<endl<<"Enter Supplier Name(Don't Use Space) : "; cin>>supName;
					supFile<<setw(50)<<supName;
					cout<<endl<<"Enter Supplier Address (Don't Use Space) : ";cin>>supAddress;
					supFile<<setw(50)<<supAddress;
					cout<<endl<<"Enter Supplier Telephone No( Single Entry Only): "; cin>>supTel;
					supFile<<setw(20)<<supTel<<endl;
							
			clrscr();
			cout<<endl<<endl<<endl<<" Supplier Details Updated...!!"; getch();
	      }
		else
		 {
		    supFile>>supName>>supAddress>>supTel;
		 continue;
		 }

		}
supFile.close();

}			

void supplier::deleteSup()
{int x;
char no[4];
fstream supFile;
supFile.open("sup.cg",ios::in|ios::out);
clrscr();
cout<<"\t\t"<<"_____Delete Supplier In DataBase____"<<endl;
cout<<endl<<"Enter Supplier No to Delete His Details(Use Four Numbers EX-0000) : "; cin>>no;
while(!supFile.eof() )
  {		supFile>>supId;
		if(strcmp(no,supId)==0)
		{   x=supFile.tellg();
		    supFile>>supName>>supAddress>>supTel;
				strcat(supName,"(Deleted)"); //"(Deleted)" string append to the end of phyName variable
			clrscr();
				supFile.seekp(x,ios::beg);//because of that we need to pin to the location
				supFile<<setw(50)<<supName;
							
			clrscr();
			cout<<endl<<endl<<endl<<" Supplier Details Changed To Deleted...!!"; getch();
	      }
		else
		 {
		    supFile>>supName>>supAddress>>supTel;
		 continue;
		 }

		}
supFile.close();

}			
		
void supplier::schSup()
{
int x;
char no[4];
fstream supFile;
supFile.open("sup.cg",ios::in);
clrscr();
cout<<"\t\t"<<"_____Search Supplier____"<<endl;
cout<<endl<<"Enter Supplier ID to Search(se Four Numbers EX-0000) : "; cin>>no;
while(!supFile.eof() )
  {		supFile>>supId;
		if(strcmp(no,supId)==0)
		{	clrscr();
		    supFile>>supName>>supAddress>>supTel;
			cout<<"Supplier ID: "<<no<<endl;
			cout<<"Supplier Name: "<<supName<<endl;
			cout<<"Supplier Address: "<<supAddress<<endl;
			cout<<"Supplier Telephone: "<<supTel<<endl;			
			getch();
			clrscr(); break;
	      }
      


	}
supFile.close();
}		
			
			const void supMenu(){
			clrscr();
			int opt;
			supplier supObj;
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			cout<<"\t\t\t"<<"___________SupplierMenu___________"<<endl;
			cout<<"\t\t\t\t"<<"1.Add Supplier"<<endl;
			cout<<"\t\t\t\t"<<"2.Edit Supplier"<<endl;
			cout<<"\t\t\t\t"<<"3.Delete Supplier"<<endl;
			cout<<"\t\t\t\t"<<"4.Search Supplier"<<endl;
			cout<<"\t\t\t\t"<<"5.MainMenu"<<endl;			
			cout<<"\t\t\t\t"<<"6.Exit"<<endl<<endl;
			cout<<"\t\t\t"<<"Enter Your Option:";	cin>>opt;
				switch(opt)
				{case 1:supObj.addSup();supMenu(); break;
				 case 2:supObj.updateSup();supMenu(); break;
				 case 3:supObj.deleteSup() ;supMenu(); break;
				 case 4:supObj.schSup() ;supMenu(); break;
				 case 5:clrscr(); callMainMenu(); break;
				 default :clrscr();
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
				cout<<"\t\t\t"<<"    Program Terminated..!"<<endl; break;
				}   }

///////////////////////////////////INSTRUCTOR//////////////////////////////////////////////////	(search)

void instructor::addIns()
{
fstream insFile;
insFile.open("ins.cg",ios::app);
clrscr();
cout<<"\t\t"<<"_____Adding Instructor To DataBase____"<<endl;
cout<<endl<<"Enter Instructor No(Use Four Numbers EX-0000) : "; cin>>insId;
insFile<<setw(10)<<insId;
cout<<endl<<"Enter Instructor Name(Don't Use Space) : "; cin>>insName;
insFile<<setw(50)<<insName;
cout<<endl<<"Enter Instructor Address(Don't Use Space) : ";cin>>insAddress;
insFile<<setw(50)<<insAddress;
cout<<endl<<"Enter Supplier Instructor Telephone No( Single Entry Only): "; cin>>insMob;
insFile<<setw(20)<<insMob;
cout<<endl<<"Enter Supplier Sex('F'-Female or 'M'-Male): "; cin>>insSex;
insFile<<setw(10)<<insSex<<endl;
clrscr();
cout<<endl<<endl<<endl<<"New Instructor Added Successfully...!!"; getch();
insFile.close();
}
				
void instructor::deleteIns()
{int x;
char no[4];
fstream insFile;
insFile.open("ins.cg",ios::in|ios::out);
clrscr();
cout<<"\t\t"<<"_____Delete Instructor In DataBase____"<<endl;
cout<<endl<<"Enter Instructor No to Delete His Details(Use Four Numbers EX-0000) : "; cin>>no;
while(!insFile.eof() )
  {		insFile>>insId;
		if(strcmp(no,insId)==0)
		{   x=insFile.tellg();
		    insFile>>insName>>insAddress>>insMob>>insSex;
				strcat(insName,"(Deleted)"); //"(Deleted)" string append to the end of phyName variable
			clrscr();
				insFile.seekp(x,ios::beg);//because of that we need to pin to the location
				insFile<<setw(50)<<insName;
							
			clrscr();
			cout<<endl<<endl<<endl<<" Instructor Details Changed To Deleted...!!"; getch();
	      }
		else
		 {
		    insFile>>insName>>insAddress>>insMob>>insSex;
		 continue;
		 }

		}
insFile.close();

}			

void instructor::updateIns()
{int x;
char no[4];
fstream insFile;
insFile.open("ins.cg",ios::in|ios::out);
clrscr();
cout<<"\t\t"<<"_____Update Instructor In DataBase____"<<endl;
cout<<endl<<"Enter Instructor No to Update His Details(Use Four Numbers EX-0000) : "; cin>>no;
while(!insFile.eof() )
  {		insFile>>insId;
		if(strcmp(no,insId)==0)
		{   x=insFile.tellp();
		    insFile>>insName>>insAddress>>insMob>>insSex;
			insFile.seekp(x-10,ios::beg);
				cout<<endl<<"Enter Instructor No(Use Four Numbers EX-0000) : "; cin>>insId;
				insFile<<setw(10)<<insId;
				cout<<endl<<"Enter Instructor Name(Don't Use Space) : "; cin>>insName;
				insFile<<setw(50)<<insName;
				cout<<endl<<"Enter Instructor Address(Don't Use Space) : ";cin>>insAddress;
				insFile<<setw(50)<<insAddress;
				cout<<endl<<"Enter Supplier Instructor Telephone No( Single Entry Only): "; cin>>insMob;
				insFile<<setw(20)<<insMob;
				cout<<endl<<"Enter Supplier Sex('F'-Female or 'M'-Male): "; cin>>insSex;
				insFile<<setw(10)<<insSex<<endl;
							
			clrscr();
			cout<<endl<<endl<<endl<<" Instructor Details Updated...!!"; getch();
	      }
		else
		 {
		    insFile>>insName>>insAddress>>insMob>>insSex;
		 continue;
		 }

		}
insFile.close();

}			

			const void insMenu(){
			clrscr();
			int opt;
			instructor inObj;
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			cout<<"\t\t\t"<<"___________InstructorMenu___________"<<endl;
			cout<<"\t\t\t\t"<<"1.Add Instructor"<<endl;
			cout<<"\t\t\t\t"<<"2.Edit Instructor"<<endl;
			cout<<"\t\t\t\t"<<"3.Delete Instructor"<<endl;
			cout<<"\t\t\t\t"<<"4.MainMenu"<<endl;
			cout<<"\t\t\t\t"<<"5.Exit"<<endl<<endl;
			cout<<"\t\t\t"<<"Enter Your Option:";	cin>>opt;
				switch(opt)
				{case 1:inObj.addIns();insMenu(); break;
				 case 2:inObj.updateIns();insMenu(); break;
				 case 3:inObj.deleteIns() ;insMenu(); break;
				 case 4:clrscr(); callMainMenu(); break;
				 default :clrscr();
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
				cout<<"\t\t\t"<<"    Program Terminated..!"<<endl; break;
				}   }


				
///////////////////////////////////MANAGER//////////////////////////////////////////////////	
/*class manager{
int manId;
char manName[50],manAddress[60];
public:

void addManager();
void deleteManager();
void reservePurchaseReport();
void addMem();
void updateMem();
};*/
				

void manager::addManager()
{
fstream File;
File.open("manager.cg",ios::app);
clrscr();
cout<<"\t\t"<<"_____Adding Manager To DataBase____"<<endl;
cout<<endl<<"Enter Manager No(Use Four Numbers EX-0000) : "; cin>>manId;
File<<setw(10)<<manId;
cout<<endl<<"Enter Manager Name(Don't Use Space) : "; cin>>manName;
File<<setw(50)<<manName;
cout<<endl<<"Enter Manager Address(Don't Use Space) : ";cin>>manAddress;
File<<setw(50)<<manAddress<<endl;
clrscr();
cout<<endl<<endl<<endl<<"New Manager Added Successfully...!!"; getch();
File.close();
}
					
					
void manager::updateMem()
{int x;
char no[4];
fstream File;
File.open("manager.cg",ios::in|ios::out);
clrscr();
cout<<"\t\t"<<"_____Update Manager In DataBase____"<<endl;
cout<<endl<<"Enter Manager No to Update His Details(Use Four Numbers EX-0000) : "; cin>>no;
while(!File.eof() )
  {		File>>manId;
		if(strcmp(no,manId)==0)
		{   x=File.tellp();
		    File>>manName>>manAddress;
			File.seekp(x-10,ios::beg);
					clrscr();
					cout<<endl<<"Enter Manager No(Use Four Numbers EX-0000) : "; cin>>manId;
					File<<setw(10)<<manId;
					cout<<endl<<"Enter Manager Name(Don't Use Space) : "; cin>>manName;
					File<<setw(50)<<manName;
					cout<<endl<<"Enter Manager Address(Don't Use Space) : ";cin>>manAddress;
					File<<setw(50)<<manAddress;
					clrscr();
			cout<<endl<<endl<<endl<<" Manager Details Updated...!!"; getch();
	      }
		else
		 {
		    File>>manName>>manAddress;
		 continue;
		 }

		}
File.close();

}			
			
								
void manager::deleteManager()
{int x;
char no[4];
fstream File;
File.open("manager.cg",ios::in|ios::out);
clrscr();
cout<<"\t\t"<<"_____Delete Manager In DataBase____"<<endl;
cout<<endl<<"Enter Manager No to Delete His Details(Use Four Numbers EX-0000) : "; cin>>no;
while(!File.eof() )
  {		File>>manId;
		if(strcmp(no,manId)==0)
		{   x=File.tellg();
		    File>>manName>>manAddress;
				strcat(manName,"(Deleted)"); //"(Deleted)" string append to the end of phyName variable
			clrscr();
				File.seekp(x,ios::beg);//because of that we need to pin to the location
				File<<setw(50)<<manName;
							
			clrscr();
			cout<<endl<<endl<<endl<<" Manager Details Changed To Deleted...!!"; getch();
	      }
		else
		 {
		    File>>manName>>manAddress;
		 continue;
		 }

		}
File.close();

}		

		

			const void manMenu(){
			clrscr();
			int opt;
			manager manObj;
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			cout<<"\t\t\t"<<"___________ManagerMenu___________"<<endl;
			cout<<"\t\t\t\t"<<"1.Add Manager"<<endl;
			cout<<"\t\t\t\t"<<"2.Edit Manager"<<endl;
			cout<<"\t\t\t\t"<<"3.Delete Manager"<<endl;
			cout<<"\t\t\t\t"<<"4.MainMenu"<<endl;
			cout<<"\t\t\t\t"<<"5.Exit"<<endl<<endl;
			cout<<"\t\t\t"<<"Enter Your Option:";	cin>>opt;
				switch(opt)
				{case 1:manObj.addManager();manMenu(); break;
				 case 2:manObj.updateMem();manMenu(); break;
				 case 3:manObj.deleteManager() ;manMenu(); break;
				 case 4:clrscr(); callMainMenu(); break;
				 default :clrscr();
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
				cout<<"\t\t\t"<<"    Program Terminated..!"<<endl; break;
				}   }
				
				
///////////////////////////////////PHYSITHERAPIST//////////////////////////////////////////////////	(search)
/*
class physiotherapist{
int phpstId;
char phpstName[50], phpstAddress[60];
public:
void addPhysiotherapist();
void deletePhysiotherapist();
void provideTreatment();
};

};*/
				

void physiotherapist::addPhysiotherapist()
{
fstream File;
File.open("Physiotherapist.cg",ios::app);
clrscr();
cout<<"\t\t"<<"_____Adding Physiotherapist To DataBase____"<<endl;
cout<<endl<<"Enter Physiotherapist No(Use Four Numbers EX-0000) : "; cin>>phpstId;
File<<setw(10)<<phpstId;
cout<<endl<<"Enter Physiotherapist Name(Don't Use Space) : "; cin>>phpstName;
File<<setw(50)<<phpstName;
cout<<endl<<"Enter Physiotherapist Address(Don't Use Space) : ";cin>>phpstAddress;
File<<setw(50)<<phpstAddress<<endl;
clrscr();
cout<<endl<<endl<<endl<<"New Physiotherapist Added Successfully...!!"; getch();
File.close();
}
						

void physiotherapist::updatePhysiotherapist()
{int x;
char no[4];
fstream File;
File.open("Physiotherapist.cg",ios::in|ios::out);
clrscr();
cout<<"\t\t"<<"_____Update Physiotherapist In DataBase____"<<endl;
cout<<endl<<"Enter Physiotherapist No to Update His Details(Use Four Digits EX-0000) : "; cin>>no;
while(!File.eof() )
  {		File>>phpstId;
		if(strcmp(no,phpstId)==0)
		{   x=File.tellp();
		    File>>phpstName>>phpstAddress;
			File.seekp(x-10,ios::beg);
					clrscr();
					cout<<endl<<"Enter Physiotherapist No(Use Four Digits EX-0000) : "; cin>>phpstId;
					File<<setw(10)<<phpstId;
					cout<<endl<<"Enter Physiotherapist Name(Don't Use Space) : "; cin>>phpstName;
					File<<setw(50)<<phpstName;
					cout<<endl<<"Enter Physiotherapist Address(Don't Use Space) : ";cin>>phpstAddress;
					File<<setw(50)<<phpstAddress;
					clrscr();
			cout<<endl<<endl<<endl<<" Physiotherapist Details Updated...!!"; getch();
	      }
		else
		 {
		    File>>phpstName>>phpstAddress;
		 continue;
		 }

		}
File.close();

}							

				
void physiotherapist::deletePhysiotherapist()
{int x;
char no[4];
fstream File;
File.open("Physiotherapist.cg",ios::in|ios::out);
clrscr();
cout<<"\t\t"<<"_____Delete Physiotherapist In DataBase____"<<endl;
cout<<endl<<"Enter Physiotherapist No to Delete His Details(Use Four Numbers EX-0000) : "; cin>>no;
while(!File.eof() )
  {		File>>phpstId;
		if(strcmp(no,phpstId)==0)
		{   x=File.tellg();
		    File>>phpstName>>phpstAddress;
				strcat(phpstName,"(Deleted)"); //"(Deleted)" string append to the end of phyName variable
			clrscr();
				File.seekp(x,ios::beg);//because of that we need to pin to the location
				File<<setw(50)<<phpstName;
							
			clrscr();
			cout<<endl<<endl<<endl<<" Physiotherapist Details Changed To Deleted...!!"; getch(); break;
	      }
		else
		 {
		    File>>phpstName>>phpstAddress;
		 continue;
		 }

		}
File.close();

}		


			const void phyMenu(){
			clrscr();
			int opt;
			physiotherapist phyObj;
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			cout<<"\t\t\t"<<"___________PhysiotherapistMenu___________"<<endl;
			cout<<"\t\t\t\t"<<"1.Add Physiotherapist"<<endl;
			cout<<"\t\t\t\t"<<"2.Edit Physiotherapist"<<endl;
			cout<<"\t\t\t\t"<<"3.Delete Physiotherapist"<<endl;
			cout<<"\t\t\t\t"<<"4.MainMenu"<<endl;
			cout<<"\t\t\t\t"<<"5.Exit"<<endl<<endl;
			cout<<"\t\t\t"<<"Enter Your Option:";	cin>>opt;
				switch(opt)
				{case 1:phyObj.addPhysiotherapist();phyMenu(); break;
				 case 2:phyObj.updatePhysiotherapist();phyMenu(); break;
				 case 3:phyObj.deletePhysiotherapist() ;phyMenu(); break;
				 case 4:clrscr(); callMainMenu(); break;
				 default :clrscr();
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
				cout<<"\t\t\t"<<"    Program Terminated..!"<<endl; break;
				}   }


				
////////////////////////////////////PAYMENT////////////////////////////////////////////////////				
/*class payment{
char pNo[4],memId[4];
double pAmount;
char pDate[15],pType;
public:
void addPayment();
void deletePayment();
void searchPayment();
};*/



				
void payment::addPayment(char *a)
{
fstream File1;
struct date d;
File1.open("payment.cg",ios::app|ios::in);
clrscr();
cout<<"\t\t"<<"_____Adding Payment To DataBase____"<<endl;
int temp;
File1.seekg(-79,ios::end);//pint to the last entered record and move to the beg
File1>>pNo;
cout<<endl<<"Last Entered Payment No: "<<pNo;

strcpy(memId,a); //parameter
cout<<endl<<endl<<"Enter New Payment No: "; cin>>pNo;
File1<<setw(10)<<pNo;
File1<<setw(10)<<memId;
cout<<endl<<"Enter Payment Type: "; cin>>pType;
File1<<setw(20)<<pType;
cout<<endl<<"Enter Payment Amount: ";cin>>pAmount;
File1<<setw(10)<<pAmount;
cout<<endl<<"Enter Payment Date(dd mm yyyy): ";cin>>d.day>>d.month>>d.year;
File1<<setw(20)<<d.day<<" "<<d.month<<" "<<d.year<<endl;


clrscr();
cout<<endl<<endl<<endl<<"New Payment Added Successfully...!!"; getch();
File1.close();
}


			
void payment::deletePayment()
{int x,no;
date d;
fstream File;
File.open("payment.cg",ios::in|ios::out);
clrscr();
cout<<"\t\t"<<"_____Delete Payment In DataBase____"<<endl;
cout<<endl<<"Enter Payment No to Delete Details: "; cin>>no;
while(!File.eof() )
  {		File>>pNo;
		if(no==pNo)
		{   x=File.tellg();
		    File>>memId>>pType>>pAmount>>d.day>>d.month>>d.year;
				strcat(pType,"(Del)"); //"(Deleted)" string append to the end of variable
			clrscr();
				File.seekp(x+10,ios::beg);//because of that we need to pin to the location
				File<<setw(20)<<pType;
							
			clrscr();
			cout<<endl<<endl<<endl<<" Payment Details Changed To Deleted...!!"; getch(); break;
	      }
		  
		else
		 {
		    File>>memId>>pType>>pAmount>>d.day>>d.month>>d.year;
		 continue;
		 }

		}
File.close();

}					
				
void payment::searchPayment()
{
char no[4];
date d;
fstream File;
File.open("payment.cg",ios::in|ios::out);
clrscr();
cout<<"\t\t"<<"_____Search Payment In DataBase____"<<endl;
cout<<endl<<"Enter Member No to Search Details(Use Four Digits EX-0000): "; cin>>no;
while(!File.eof() )
  {		File>>pNo>>memId;
		if(strcmp(no,memId)==0)
		{   
		    File>>pType>>pAmount>>d.day>>d.month>>d.year;
			cout<<pNo<<"\t"<<memId<<"\t"<<pType<<"\t"<<pAmount<<"\t"<<d.day<<" "<<d.month<<" "<<d.year<<endl;
			getch();
	      }
		  
		else
		 {
		  File>>pType>>pAmount>>d.day>>d.month>>d.year;
		 continue;
		 }

	}
		
File.close();
}				
				
			const void pMenu(){
			clrscr();
			int opt;
			payment pObj;
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			cout<<"\t\t\t"<<"___________PaymentMenu___________"<<endl;
			cout<<"\t\t\t\t"<<"1.Remove Payment"<<endl;
			cout<<"\t\t\t\t"<<"2.Search Payment"<<endl;
			cout<<"\t\t\t\t"<<"3.MainMenu"<<endl;
			cout<<"\t\t\t\t"<<"4.Exit"<<endl<<endl;
			cout<<"\t\t\t"<<"Enter Your Option:";	cin>>opt;
				switch(opt)
				{case 1:pObj.deletePayment();pMenu(); break;
			  	 case 2:pObj.searchPayment();pMenu(); break;
				 case 3:clrscr(); callMainMenu(); break;
				 default :clrscr();
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
				cout<<"\t\t\t"<<"    Program Terminated..!"<<endl; break;
				}   }			
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				

		void callMainMenu(){
			int opt;

			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			cout<<"\t\t\t"<<"___________MainMenu___________"<<endl;
			cout<<"\t\t\t\t"<<"1.Medication"<<endl;
			cout<<"\t\t\t\t"<<"2.Member"<<endl;
			cout<<"\t\t\t\t"<<"3.Physican"<<endl;
			cout<<"\t\t\t\t"<<"4.Supplier"<<endl;
			cout<<"\t\t\t\t"<<"5.Instructor"<<endl;
			cout<<"\t\t\t\t"<<"6.Manager"<<endl;
			cout<<"\t\t\t\t"<<"7.Physiotherapist"<<endl;
			cout<<"\t\t\t\t"<<"8.Payments"<<endl;
			cout<<"\t\t\t\t"<<"0.Exit"<<endl<<endl;

			cout<<"\t\t\t"<<"Enter Your Option:";	cin>>opt;
			switch(opt)
			  {case 1: medMenu(); break;
			   case 2: memMenu(); break;
			   case 3: physMenu(); break;
			   case 4: supMenu(); break;
			   case 5: insMenu(); break;
			   case 6: manMenu(); break;
			   case 7: phyMenu(); break;
			   case 8: pMenu(); break;
			   case 0:  break;
			  }   }
void main()
{clrscr();
callMainMenu();
getch();
}



