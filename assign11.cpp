/*Department maintains student information. <the file contains roll number, name division and address.
Allow users to add, delete information about students. Display information of a particular student. 
If the record of the student does not exist an appropriate message is displayed.
If it is , then the system displays the student detials. Use a sequantial file to maintain the data.*/

#include <iostream>
#include <fstream>
using namespace std;
struct student{
	int rollN;
	char name[20];
	char address[20];
	char div[5];

	void getdata(){
	cout<<"\nEnter student rollNo:";
	cin>>rollN;
	cout<<"\nEnter student name:";
	cin>>name;	
	cout<<"\nEnter student address:";
	cin>>address;	
	cout<<"\nEnter student's division:";
	cin>>div;
	}

	void putdata()
	{	
	cout<<"\n"<<rollN<<"\n"<<name<<"\n"<<address<<"\n"<<div<<"\n"<<endl;
	}
};


class file{
	fstream fp;
	student s;
	public:
	void create();
	void display();
	void append();
	void search();

};


void file :: create(){
	char ans;
	fp.open("student.txt",ios::out);
	do{
		s.getdata();
		fp.write((char*)&s,sizeof(s));
		cout<<"\nAdd more?";
		cin>>ans;
	}
	while(ans=='y');
		fp.close();
}

void file :: display(){
	fp.open("student.txt",ios::in);
	while(!fp.eof()){
	fp.read((char*)&s,sizeof(s));
		if(!fp.eof())
		s.putdata();
	}
	fp.close();
	}


void file :: append(){
	char ans;
	fp.open("student.txt",ios::app);
	do{
		s.getdata();
		fp.write((char*)&s,sizeof(s));
		cout<<"\nAdd more?";
		cin>>ans;
	}
	while(ans=='y');
		fp.close();
}


void file :: search(){
           fp.open("student.txt",ios::in);
	   int r;
           cout << "\n Enter rollNo to be searched :";
           cin >> r;
           while (!fp.eof()){
                fp.read((char*)&s,sizeof(s));
                if (!fp.eof() and s.rollN==r) {
                     s.putdata();
                     break;
                }
		else{
		cout<<"Data not found.";
		}
           }
           fp.close();
}


int main(){
file f;
int ch;
do{
cout<<"\n1.Create file\n2.Display file contents\n3.Append more data\n4.Search data\n5.Exit\nEnter your choice:";
cin>>ch;
switch(ch){
case 1:
	f.create();
	break;
case 2:
	f.display();
	break;
case 3:
	f.append();
	break;
case 4:
	f.search();
	break;
case 5: 
        cout << "Exiting.";
        break;
   }
}while(ch!=5);

return 0;
}
