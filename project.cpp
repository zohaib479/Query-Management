#include"iostream"
#include"fstream"
#include"cstring"
#include"conio.h"
#include "cstdlib"
#include "cstdio"
#include "chrono"
#include"time.h"
#include"dos.h"
#include"windows.h"//loading screen

#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_LIGHT_BLUE "\x1b[104m" 



using namespace std;

int stdcount;
string *stdarray = nullptr;

template<typename t>
class queue{		// abstract class
	
	t *x;
	
	public:
		
		queue(){
			
		}
		
		queue(t h){
			*x=h;
		}
		
		virtual void display() = 0;		//pure virtual functions 
	
};

void gotoxy (int x, int y) {
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void load_screen() {
	
	system("cls");
	gotoxy(50, 7);
	printf("Loading...");
	gotoxy(50, 8);
	for (int i=1; i<=20;i++) {
		for (int j=0; j<=10000000; j++);
		cout << char(219);
	}
	system("cls");
	
}

void MainMenu();//prototype
class info{ // INFO CLASS 
	protected:
	char name[20];
	char id[10];
	friend class student;
	friend class faculty;
	
	public:
		info()
		{
			strcpy(name,"");
			strcpy(id,"");
		}
		info(char n[20],char i[10]){
			strcpy(name,i);
			strcpy(id,i);
		}		
};

class student	:public info // STUDENT 
{	
	char department[20];
	char batch[20];
	char query[100];
	char response[100];
	public:
		friend ostream& operator<<(ostream& o , student& s);
		string get_id(){
			return id;
		}
		
		student()
		{
			strcpy(name,"");
			strcpy(department,"");
			strcpy(batch,"");
			strcpy(query,"");
			strcpy(id,"");
			strcpy(response,"");
		}
	student(char n[20],char i[20],char dep[20], char b[20], char q[100]){
			strcpy(name,n);
			strcpy(department,dep);
			strcpy(batch,b);
			strcpy(query,q);
			strcpy(id,i);
			strcpy(response,"");
		}
		int input()
		{
			string tempquery;
			load_screen();
			cout<<"Enter ID :";
			cin>>id;
			cin.ignore();
			cout<<"Enter Name :";
			cin>>name;
			cin.ignore();
			cout<<"Enter Department :";
			cin>>department;
			cin.ignore();			
			cout<<"Enter Batch :";
			cin>>batch;
			cin.ignore();
			cout<<"Enter Query :";
			getline(cin,tempquery);
			cout<<endl;
			for(int i=0;i<tempquery.length();i++)
		{
			query[i]=tempquery[i];
		}
			
		return 0;	
		}

		
		
		void display(){
				
			cout<<"\nName :"<<name<<"\nID :"<<id<<"\nBatch :"<<batch<<"\nDepartment :"<<department<<"\nQuery :"<<query<<"\nResponse:"<<response<<"\n";
		
		}
			
	

		int create();
		int login(char *n,char *i);
		void readdata(char *s);
		void readall();
		int deletestudent(char *z);
		void updatequery(char *t);
		void respondquery(char *t);
		void inputquery()
		{ string tempquery;
			cout<<"Enter Your Query :";
			cin.ignore();	
			getline(cin,tempquery);
			
			for(int i=0;i<tempquery.length();i++)
		{
			query[i]=tempquery[i];
		}		
		}
		void inputrespond()
		{
		string temprespond;
			cin.ignore();
			cout<<"Enter Your Respond :";
			getline(cin,temprespond);
			
			for(int i=0;i<temprespond.length();i++)
		{
		response[i]=temprespond[i];
		}		
		}
};


//OPERATOR OVERLOADING
ostream& operator<<(ostream& o , student& s1){
	
	o <<"\nName :"<<s1.name<<"\nID :"<<s1.id<<"\nBatch :"<<s1.batch<<"\nDepartment :"<<s1.department<<"\nQuery :"<<s1.query<<"\nResponse:"<<s1.response<<"\n";
	return o;
}


class faculty:public info{
	char department[20];
	char designation[20];
	public:
		
		
	
	faculty(){
		}
	faculty(char n[20],char dep[20],char i[10], char des[20]){
			strcpy(name,n);
			strcpy(department,dep);
			strcpy(designation,des);
			strcpy(id,i);
		}
	int	input()
		{
			load_screen();
			cout<<"Enter ID :";
			cin>>id;
			cin.ignore();
			cout<<"Enter Name :";
			cin>>name;
			cin.ignore();
			cout<<"Enter Department :";
			cin>>department;
			cin.ignore();
			cout<<"Enter Designation :";
			cin>>designation;
			cin.ignore();
			cout << endl;
		return 0;	
		}
		
		
		
		int create();
		void readdata(char *s);
		bool login(char *n,char *i);
		void readall();
		int deletefaculty(char *z);
		
		void Attendance();
void display()
{
	//load_screen();
	cout<<"\nName :"<<name<<"\nID :"<<id<<"\nDesignation :"<<designation<<"\nDepartment :"<<department;	
}
		
		
};



int faculty::create()
{
	ofstream fout;
	fout.open("Faculty.dat",ios::app|ios::binary);
	fout.write((char*)this,(sizeof(*this)));
	cout<<"Account Registered";	
	fout.close();
return 0;
}
void faculty::readdata(char *s)
{
	ifstream fin;
	fin.open("Faculty.dat");
	fin.read((char*)this,(sizeof(*this)));
	while(!fin.eof())
	{
		if(!strcmp(s,name)||!strcmp(s,id))
		{
		display();
			
		fin.read((char*)this,(sizeof(*this)));
		}
		fin.read((char*)this,(sizeof(*this)));
	}
	
	fin.close();
}
int student::create()
{
	ofstream fout;
	fout.open("AccountData.dat",ios::app|ios::binary);
	fout.write((char*)this,(sizeof(*this)));
	load_screen();
	cout<<"Account Registered";	
	fout.close();
	return 0;
}
void student::readdata(char *s){
	ifstream fin;
	fin.open("AccountData.dat");
	fin.read((char*)this,(sizeof(*this)));
	while(!fin.eof())
	{
		if(!strcmp(s,name)||!strcmp(s,id))
		{
		display();
			
		fin.read((char*)this,(sizeof(*this)));
		}
		fin.read((char*)this,(sizeof(*this)));
	}
	
	fin.close();
}
void student::readall()
{
	ifstream fin;
	fin.open("AccountData.dat");
	fin.read((char*)this,(sizeof(*this)));
	while(!fin.eof())
	{
		
		display();
		fin.read((char*)this,(sizeof(*this)));
	}
	fin.close();
}
void faculty::readall()
{
	ifstream fin;
	fin.open("Faculty.dat");
	fin.read((char*)this,(sizeof(*this)));
	while(!fin.eof())
	{
		
		display();
		fin.read((char*)this,(sizeof(*this)));
	}
		
	
	
	fin.close();
}
bool faculty::login(char *n,char *i)
{
	ifstream fin;
	fin.open("Faculty.dat");
	int x=0;
	fin.read((char*)this,(sizeof(*this)));
	while(!fin.eof())
	{
		if(!strcmp(n,name)&&!strcmp(i,id))
		{
			display();x=1;
			fin.read((char*)this,(sizeof(*this)));
		}
		 fin.read((char*)this,(sizeof(*this)));
		
	}
	if(x==0)
	{
		cout<<"Wrong Name/ID";
		return false;
	}
	else return true;
	fin.close();
return 0;	
}
int student::login(char *n,char *i)
{
	
		
		
	
	ifstream fin;
	fin.open("AccountData.dat");
	int x=0;
	fin.read((char*)this,(sizeof(*this)));
	while(!fin.eof())
	{
		if(!strcmp(n,name)&&!strcmp(i,id))
		{
			display();x=1;
			fin.read((char*)this,(sizeof(*this)));
		}
		 fin.read((char*)this,(sizeof(*this)));
		
	}
	if(x==0)
	{
		cout<<"Wrong Name/ID";
		return false;
	}
	else return true;
	fin.close();
	return 0;
	
}
void student::updatequery(char *t)
{
	fstream file;
	file.open("AccountData.dat",ios::in|ios::out|ios::ate|ios::binary);
	file.seekg(0);
	file.read((char*)this,sizeof(*this));
	while(!file.eof())
	{
		if(!strcmp(t,name))
		{
			inputquery();
			strcpy(response,"");			
			file.seekp(file.tellp());//sizeof(*this));
			file.write((char*)this,sizeof(*this));
		}
		file.read((char*)this,sizeof(*this));
	}
	file.close();
	cout<<"\n\nQuery Updated";
}

int student::deletestudent(char *z)
{

	ifstream fin;
	ofstream fout;
	fin.open("AccountData.dat",ios::in|ios::binary);
	fout.open("tempfile.dat",ios::out|ios::binary);
	_getch();
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(strcmp(z,name))
		{
		fout.write((char*)this,sizeof(*this));			
		}
		fin.read((char*)this,sizeof(*this));
		
		
		
	}
	fin.close();
	fout.close();
	_getch();
	remove("AccountData.dat");
	_getch();
	rename("tempfile.dat","AccountData.dat");
	_getch();
	cout<<"\nRecord Deleted Successfully! by ZOHAIB";
return 0;
}
int faculty::deletefaculty(char *z)
{
	ifstream fin;
	ofstream fout;
	fin.open("Faculty.dat",ios::in|ios::binary);
	fout.open("tempfile.dat",ios::out|ios::binary);
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(strcmp(z,name))
		{
		fout.write((char*)this,sizeof(*this));			
		}
		fin.read((char*)this,sizeof(*this));
		
		
		
	}
	fin.close();
	fout.close();
	remove("Faculty.dat");
	rename("tempfile.dat","Faculty.dat");
	cout<<"\nRecord Deleted Successfully! by Zohaib faculty (member:23k-0546)";
	return 0;
}
void student::respondquery(char *t)
{
	fstream f;
	f.open("AccountData.dat",ios::in|ios::out|ios::ate|ios::binary);
	f.seekg(0);
	f.read((char*)this,sizeof(*this));
	while(!f.eof())
	{
		if(!strcmp(t,name))
		{
			inputrespond();
			f.seekp(f.tellp());//-sizeof(*this));
			f.write((char*)this,sizeof(*this));
		}
		f.read((char*)this,sizeof(*this));
	}
	f.close();
	cout<<"\nResponse Updated";
}
void MainMenu();
int main(){
	
load_screen();
cout << ANSI_COLOR_LIGHT_BLUE ;

	
MainMenu();
return 0;
}
void MainMenu(){
	int choice;
	k:
	system("cls");
	system("pause");
	cout<< "\n\n\n\t\t\t\t\tFast University Query System\n\n"<<endl;
	Sleep(1000);
	cout<<"\n\n\n\t\t\t\t\t(1) Admin\n\n\t\t\t\t\t";	Sleep(1000);
	cout<<"(2)Faculty\n\n\t\t\t\t\t";	Sleep(1000);	
	cout<<"(3)Student\t ";	Sleep(1000);
	cout<<"(4)Exit\t ";	Sleep(1000);	
	cout<<"\nSelect Your Choice :";
	cin>>choice;
	system("cls");
	switch(choice)
	{	
		case 1:
			
			{
			q:
			string user,pass;
			cout<<"\nEnter Username :";
			cin.ignore();
			getline(cin,user);
			cout<<"\nEnter Password :";
		
			getline(cin,pass);
			if(user=="admin"&&pass=="1234")
			{system("cls");
			a:
			cout<< "\n\n\n\t\t\t\t\tFast University Query System\n\n"<<endl;
	 
	   
			
			
			
			int c1;
			cout<<"\n\n\n\n(1)Register Student\t\t(2)Register Faculty\t\t\n\n\n(3)Display Students\t\t(4)Display Faculty\t\t\n\n\n(5)Delete Student\t\t(6)Delete Faculty\n\n\t\t\t(7)Main Menu:";
			
			
			
			
			cin>>c1;
			if(c1==1)
			{
				
			student s1;
			s1.input();	
			s1.create();
			getch();
			
			
			//string *stdarray;
		    int size = 0; // Initialize size of array
		
		        // Reallocate memory for the array
		    string* newarray = new string[size + 1]; // Increase size by 1
		    for (int i = 0; i < size; ++i) {
	        	newarray[i] = stdarray[i]; // Copy old elements
	        }
	        newarray[size] = s1.get_id(); // Add new value at the end
		
		    // Delete old array and update pointer to point to the new array
		    delete[] stdarray;
		    stdarray = newarray;
		
		    ++size; // Increment size
			
			stdcount += 1;		
			
			
			
			
					
			}
			if(c1==2)
			{
				faculty f1;
				f1.input();
				f1.create();
			}
			if(c1==3)
			{char str[10];
			student s1;
			s1.readall();
			cout<<endl;
				cout<<"Search By Name/ID :";
				cin>>str;
				s1.readdata(str);
			}
			if(c1==4)
			{
			char str[10];
			faculty f1;
			f1.readall();
				cout<<"\nSearch By Name/ID :";
				cin>>str;
				f1.readdata(str);	
			}
			if(c1==5)
			{student s1;char name[100];char ch;
				cout<<"\nEnter Name or Id of the Student To Delete ";
				cin>>name;
				cout<<name;

				s1.readdata(name);
				cout<<"Are U Sure U Want To Delete This Record (y/n):";
				cin>>ch;
				cin.ignore();
				if(ch=='y')
				{
				s1.deletestudent(name);					
				}
				else cout<<"\nDeletion Stopped!";
				
				s1.readall();
			}
			
			if(c1==6)
			{
				faculty f1;char name[100];char ch;
				cout<<"\nEnter Name or Id of the Faculty To Delete ";
				cin>>name;
				cin.ignore();
				cout<<name;
				f1.readdata(name);
				cout<<"Are U Sure U Want To Delete This Record (y/n):";
				cin>>ch;
				cin.ignore();
				if(ch=='y')
				{
				f1.deletefaculty(name);					
				}
				else cout<<"\nDeletion Stopped!";
				f1.readall();
				
			}
			if(c1==7)
			goto k;
			
			system("pause");
			system("cls");			
			goto a;
	
		}
		else 
		{
			cout<<"\nWrong Entry!";goto q;
		}
	}
		break;
	 case 2:
			{
				 
	
		   
	cout<< "\n\n\n\t\t\t\t\tFast University Query System\n\n"<<endl;
	 
			char name[100],id[100];
			faculty f1;
		cout<<"Enter Your Name:" ;
		cin>>name;
		cin.ignore();
		cout<<"\nEnter ID :";
		cin>>id;
		cin.ignore();
		
		if(f1.login(name,id))
		{
		
	
		cout<<"Welcome!";
		
		system("pause");
		b:
		system("cls");
		cout<<"\n(1)Search Student\t(2)DisplayAll Students\t(3)Update Attendance\t(4)Main-Menu\n:";
		int ch;
		cin>>ch;	
		if(ch==1)
		{char x;
			student s1;
			cout<<"\nEnter Student Name or ID :";
			cin>>name;
			cin.ignore();
			s1.readdata(name);
			cout<<"\nRespond?(y/n) :";
			cin>>x;
			if(x=='y');
			s1.respondquery(name);
			system("pause");
			goto b;
			}
			if(ch==2)
			{
				student s1;
				s1.readall();
				system("pause");
			goto b;
			}
			
				if (ch == 3){
				
					// Get the current time
			    auto currentTime = chrono::system_clock::now();
			
			    // Subtract days
			    
			    auto oneDaysAgo = currentTime - chrono::hours(24);
			    auto twoDaysAgo = currentTime - chrono::hours(48);
			    auto threeDaysAgo = currentTime - chrono::hours(72);
			    auto fourDaysAgo = currentTime - chrono::hours(96);
			    auto fiveDaysAgo = currentTime - chrono::hours(120);
			    auto sixDaysAgo = currentTime - chrono::hours(144);
			    auto sevenDaysAgo = currentTime - chrono::hours(168);
			    
				auto today = currentTime;
			
			    // Convert to time_t
			    time_t timeoneDaysAgo = chrono::system_clock::to_time_t(oneDaysAgo);
			    time_t timetwoDaysAgo = chrono::system_clock::to_time_t(twoDaysAgo);
			    time_t timethreeDaysAgo = chrono::system_clock::to_time_t(threeDaysAgo);
			    time_t timefourDaysAgo = chrono::system_clock::to_time_t(fourDaysAgo);
			    time_t timefiveDaysAgo = chrono::system_clock::to_time_t(fiveDaysAgo);
			    time_t timesixDaysAgo = chrono::system_clock::to_time_t(sixDaysAgo);
			    time_t timesevenDaysAgo = chrono::system_clock::to_time_t(sevenDaysAgo);
			    
			    time_t timetoday = chrono::system_clock::to_time_t(today);
			
				ofstream file;
				file.open("student_attendance.txt",ios::app);
				
			    // Convert to tm struct
			   
				string day1;
				string day2;
				string day3;
				string day4;
				string day5;
				string day6;
				string day7;
				string day8;


			
				//today
				tm* timeInfo8 = localtime(&timetoday);
				day8 = to_string(timeInfo8->tm_year + 1900) + "-" + to_string(timeInfo8->tm_mon + 1) + "-" + to_string(timeInfo8->tm_mday) + " (0)";
				cout << day8;
				file << (timeInfo8->tm_year + 1900) << '-' << (timeInfo8->tm_mon + 1) << '-' << timeInfo8->tm_mday << " (0)" << endl;
				cout << endl;
		
				//previous days
				tm* timeInfo1 = localtime(&timeoneDaysAgo);
			    day1 = to_string(timeInfo1->tm_year + 1900) + "-" + to_string(timeInfo1->tm_mon + 1) + "-" + to_string(timeInfo1->tm_mday) + " (1)";
			    cout << day1;
				file << (timeInfo1->tm_year + 1900) << '-' << (timeInfo1->tm_mon + 1) << '-' << timeInfo1->tm_mday << " (1)" << endl;
			    cout << endl;
				
				 
			    tm* timeInfo2= localtime(&timetwoDaysAgo);
			    day2 = to_string(timeInfo2->tm_year + 1900) + "-" + to_string(timeInfo2->tm_mon + 1) + "-" + to_string(timeInfo2->tm_mday) + " (2)";
			    cout << day2;
				file << (timeInfo2->tm_year + 1900) << '-' << (timeInfo2->tm_mon + 1) << '-' << timeInfo2->tm_mday << " (2)" << endl;
			    cout << endl;
			    
			    
			    
				tm* timeInfo3 = localtime(&timethreeDaysAgo);
			    day3 = to_string(timeInfo3->tm_year + 1900) + "-" + to_string(timeInfo3->tm_mon + 1) + "-" + to_string(timeInfo3->tm_mday) + " (3)";
			    cout << day3;
				file << (timeInfo3->tm_year + 1900) << '-' << (timeInfo3->tm_mon + 1) << '-' << timeInfo3->tm_mday << " (3)" << endl;
			    cout << endl;
			    
			    
			    
			    tm* timeInfo4 = localtime(&timefourDaysAgo);
			    day4 = to_string(timeInfo4->tm_year + 1900) + "-" + to_string(timeInfo4->tm_mon + 1) + "-" + to_string(timeInfo4->tm_mday) + " (4)";
			    cout << day4;
				file << (timeInfo4->tm_year + 1900) << '-' << (timeInfo4->tm_mon + 1) << '-' << timeInfo4->tm_mday << " (4)" << endl;
				cout << endl;
				 
				
				tm* timeInfo5 = localtime(&timefiveDaysAgo);
			    day5 = to_string(timeInfo5->tm_year + 1900) + "-" + to_string(timeInfo5->tm_mon + 1) + "-" + to_string(timeInfo5->tm_mday) + " (5)";
			    cout << day5;
				file << (timeInfo5->tm_year + 1900) << '-' << (timeInfo5->tm_mon + 1) << '-' << timeInfo5->tm_mday << " (5)" << endl;
				cout << endl;
				
			    	
				tm* timeInfo6 = localtime(&timesixDaysAgo);
			    day6 = to_string(timeInfo6->tm_year + 1900) + "-" + to_string(timeInfo6->tm_mon + 1) + "-" + to_string(timeInfo6->tm_mday) + " (6)";
			    cout << day6;
				file << (timeInfo6->tm_year + 1900) << '-' << (timeInfo6->tm_mon + 1) << '-' << timeInfo6->tm_mday << " (6)" << endl;
				cout << endl;
				
				
				tm* timeInfo7 = localtime(&timesevenDaysAgo);
				day7 = to_string(timeInfo7->tm_year + 1900) + "-" + to_string(timeInfo7->tm_mon + 1) + "-" + to_string(timeInfo7->tm_mday) + " (7)";
				cout << day7;
				file << (timeInfo7->tm_year + 1900) << '-' << (timeInfo7->tm_mon + 1) << '-' << timeInfo7->tm_mday << " (7)" << endl;
				cout << endl;
				
				file.close();	
							
				int day;
				cout << "\n\nEnter the day(in brackets) for which you want to update attendance: ";
				cin >> day;
						
						
				switch(day){
					
					case(1):
					{
						
						ifstream file1("student_attendance.txt");
					    ofstream outFile("temp.txt");
					try{		//exception handling
					    
						if (!file1.is_open()) {
					        throw "Unable to open file for reading.";
					        
					    }
					
					    ofstream outFile("temp.txt");
					    if (!outFile.is_open()) {
					        throw "Unable to open file for writing." ;
					        
					    }
					}
					
					catch(const char* ch){
						cout << "Error Occured--->"<< ch  << endl;
					}	
					
						string line;
					    char ch;
						
															
					    while (getline(file1, line)) {
					        if (line == day1) {
					            outFile << line << endl;
					            for (int x = 0; x < stdcount; x++) {
					                outFile << stdarray[x] << " ";
					                cout << stdarray[x] << ": ";
					                cin >> ch;
					                outFile << ch << endl;
					            }
					        } 
							else {
					            outFile << line << endl;
					        }
					    }
						
					
						file1.close();
						outFile.close();
						
						remove("student_attendance.txt");
					    rename("temp.txt", "student_attendance.txt");
						
						
						break;
					
					}
					
					case(2):{
						
							ifstream file1("student_attendance.txt");
					    ofstream outFile("temp.txt");
					try{		//exception handling
					    
						if (!file1.is_open()) {
					        throw "Unable to open file for reading.";
					        
					    }
					
					    ofstream outFile("temp.txt");
					    if (!outFile.is_open()) {
					        throw "Unable to open file for writing." ;
					        
					    }
					}
					
					catch(const char* ch){
						cout << "Error Occured--->"<< ch  << endl;
					}	
					
					
						string line;
					    char ch;
						
					
																	
					    while (getline(file1, line)) {
					        if (line == day2) {
					            outFile << line << endl;
					            for (int x = 0; x < stdcount; x++) {
					                outFile << stdarray[x] << " ";
					                cout << stdarray[x] << ": ";
					                cin >> ch;
					                outFile << ch << endl;
					            }
					        } 
							else {
					            outFile << line << endl;
					        }
					    }
						
					
						file1.close();
						outFile.close();
						
						remove("student_attendance.txt");
					    rename("temp.txt", "student_attendance.txt");
						
						
						break;
					
					}
					
					case(3):
						{
						
							ifstream file1("student_attendance.txt");
					    ofstream outFile("temp.txt");
					try{		//exception handling
					    
						if (!file1.is_open()) {
					        throw "Unable to open file for reading.";
					        
					    }
					
					    ofstream outFile("temp.txt");
					    if (!outFile.is_open()) {
					        throw "Unable to open file for writing." ;
					        
					    }
					}
					
					catch(const char* ch){
						cout << "Error Occured--->"<< ch  << endl;
					}	
					
						
						string line;
					    char ch;
						
					  												
					    while (getline(file1, line)) {
					        if (line == day3) {
					            outFile << line << endl;
					            for (int x = 0; x < stdcount; x++) {
					                outFile << stdarray[x] << " ";
					                cout << stdarray[x] << ": ";
					                cin >> ch;
					                outFile << ch << endl;
					            }
					        } 
							else {
					            outFile << line << endl;
					        }
					    }
						
					
						file1.close();
						outFile.close();
						
						remove("student_attendance.txt");
					    rename("temp.txt", "student_attendance.txt");
						
						
						break;
					
					}
					
					case(4):{
						
							ifstream file1("student_attendance.txt");
					    ofstream outFile("temp.txt");
					try{		//exception handling
					    
						if (!file1.is_open()) {
					        throw "Unable to open file for reading.";
					        
					    }
					
					    ofstream outFile("temp.txt");
					    if (!outFile.is_open()) {
					        throw "Unable to open file for writing." ;
					        
					    }
					}
					
					catch(const char* ch){
						cout << "Error Occured--->"<< ch  << endl;
					}	
					
					    string line;
					    char ch;
																	
					    while (getline(file1, line)) {
					        if (line == day4) {
					            outFile << line << endl;
					            for (int x = 0; x < stdcount; x++) {
					                outFile << stdarray[x] << " ";
					                cout << stdarray[x] << ": ";
					                cin >> ch;
					                outFile << ch << endl;
					            }
					        } 
							else {
					            outFile << line << endl;
					        }
					    }
						
					
						file1.close();
						outFile.close();
						
						remove("student_attendance.txt");
					    rename("temp.txt", "student_attendance.txt");
						
						
						break;
					

					}
					
					case(5):{
						
							ifstream file1("student_attendance.txt");
					    ofstream outFile("temp.txt");
					try{		//exception handling
					    
						if (!file1.is_open()) {
					        throw "Unable to open file for reading.";
					        
					    }
					
					    ofstream outFile("temp.txt");
					    if (!outFile.is_open()) {
					        throw "Unable to open file for writing." ;
					        
					    }
					}
					
					catch(const char* ch){
						cout << "Error Occured--->"<< ch  << endl;
					}	
					
					    string line;
					    char ch;
																	
					    while (getline(file1, line)) {
					        if (line == day5) {
					            outFile << line << endl;
					            for (int x = 0; x < stdcount; x++) {
					                outFile << stdarray[x] << " ";
					                cout << stdarray[x] << ": ";
					                cin >> ch;
					                outFile << ch << endl;
					            }
					        } 
							else {
					            outFile << line << endl;
					        }
					    }
						
					
						file1.close();
						outFile.close();
						
						remove("student_attendance.txt");
					    rename("temp.txt", "student_attendance.txt");
						
						
						break;
					
					}
						
					
					
					case(6):{
						
							ifstream file1("student_attendance.txt");
					    ofstream outFile("temp.txt");
					try{		//exception handling
					    
						if (!file1.is_open()) {
					        throw "Unable to open file for reading.";
					        
					    }
					
					    ofstream outFile("temp.txt");
					    if (!outFile.is_open()) {
					        throw "Unable to open file for writing." ;
					        
					    }
					}
					
					catch(const char* ch){
						cout << "Error Occured--->"<< ch  << endl;
					}	
					
					    string line;
					    char ch;
																	
					    while (getline(file1, line)) {
					        if (line == day6) {
					            outFile << line << endl;
					            for (int x = 0; x < stdcount; x++) {
					                outFile << stdarray[x] << " ";
					                cout << stdarray[x] << ": ";
					                cin >> ch;
					                outFile << ch << endl;
					            }
					        } 
							else {
					            outFile << line << endl;
					        }
					    }
						
					
						file1.close();
						outFile.close();
						
						remove("student_attendance.txt");
					    rename("temp.txt", "student_attendance.txt");
						
						
						break;
					
					}
						
					
					
					case(7):{
							ifstream file1("student_attendance.txt");
					    ofstream outFile("temp.txt");
					try{		//exception handling
					    
						if (!file1.is_open()) {
					        throw "Unable to open file for reading.";
					        
					    }
					
					    ofstream outFile("temp.txt");
					    if (!outFile.is_open()) {
					        throw "Unable to open file for writing." ;
					        
					    }
					}
					
					catch(const char* ch){
						cout << "Error Occured--->"<< ch  << endl;
					}	
					
					    string line;
					    char ch;
																	
					    while (getline(file1, line)) {
					        if (line == day7) {
					            outFile << line << endl;
					            for (int x = 0; x < stdcount; x++) {
					                outFile << stdarray[x] << " ";
					                cout << stdarray[x] << ": ";
					                cin >> ch;
					                outFile << ch << endl;
					            }
					        } 
							else {
					            outFile << line << endl;
					        }
					    }
						
					
						file1.close();
						outFile.close();
						
						remove("student_attendance.txt");
					    rename("temp.txt", "student_attendance.txt");
						
						
						break;
					
					}
						
					
					
					case(0):{
							ifstream file1("student_attendance.txt");
					    ofstream outFile("temp.txt");
					try{		//exception handling
					    
						if (!file1.is_open()) {
					        throw "Unable to open file for reading.";
					        
					    }
					
					    ofstream outFile("temp.txt");
					    if (!outFile.is_open()) {
					        throw "Unable to open file for writing." ;
					        
					    }
					}
					
					catch(const char* ch){
						cout << "Error Occured--->"<< ch  << endl;
					}	
					
					    string line;
					    char ch;
																	
					    while (getline(file1, line)) {
					        if (line == day8) {
					            outFile << line << endl;
					            for (int x = 0; x < stdcount; x++) {
					                outFile << stdarray[x] << " ";
					                cout << stdarray[x] << ": ";
					                cin >> ch;
					                outFile << ch << endl;
					            }
					        } 
							else {
					            outFile << line << endl;
					        }
					    }
						
					
						file1.close();
						outFile.close();
						
						remove("student_attendance.txt");
					    rename("temp.txt", "student_attendance.txt");
						
						
						break;
					
					}
						
					
					
					default:{
						cout << "Invalid Input.\n";
						break;
					}
						
					
				}
				
			}
			
			
			
			
			if(ch==4)
			{
				goto k;
				}	
		}
		
			
			}	break;	
			
		
		case 3:
			{
	cout<< "\n\n\n\t\t\t\t\tFast University Query System\n\n"<<endl;
	 
	   	
		char name[100],id[100];
		char cc;	
		student s1;
		cout<<"\nEnter Your Name :";
		cin.ignore();
		cin.get(name,19);
		cout<<"\nEnter Your ID :";	
		cin>>id;
		cin.ignore();
		if(s1.login(name,id))
		{
			cout<<"\nDo U Want To Update Query :";
		cin>>cc;
	
		if(cc=='y')
		{
		cout<<"\n"<<name;
		s1.updatequery(name);
		}
		}
				
		
	}break;
	case 4:
		exit(0);
		break;
	default:
		cout<<"\nEntered Wrong! Try Again\n";
		goto k;
 }
	char e;
	cout<<"\n\nEXIT? :";
	cin>>e;
	if(e!='y')
	goto k;
	
}
