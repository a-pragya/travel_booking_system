#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
const int admin_uname=123;
const int admin_password=1204;
void user_update();
void view_dest(int n);
void user_interface();
void admin_interface();
void userfunc();
void admin();
void cancel_booking();
void check_account();
void new_account();
void user_interface();
void manage_user();
void manage_pack();
void delete_pack();
void view_booking();
void view_account();
void delete_account();
void modify_account();
class user
{	int uname;
	int password;
	char booked[20];
	int no_ppl;
	public:
	user();
	int getuname()
	{	return uname;
	}
	int getpass()
	{	return password;
	}
	int getnum()     		//used for view booking
	{	return no_ppl;
	}
	char* getpack() 		//used for view booking
	{	return booked;
	}
       /*	void set_dest(char* A)
	{	strcpy(booked,char*);
	}
	void set_ppl(int N)
	{	no_ppl=N;
	}     */
	void fill();
	void display();
	void update_user(int,char*);
}user_o1,user_o2,user_o3;

void user::update_user(int n,char* name)
{	no_ppl=n;
	strcpy(booked,name);
	return;
}
user::user()
{	strcpy(booked," NONE");
	no_ppl=0;
}
void user::display()

{
	cout<<"           Username: "<<uname<<endl;
	cout<<"           Password: "<<password<<endl;
	cout<<"     Package booked: "<<booked<<endl;
	cout<<"No. of seats booked: "<<no_ppl<<"\n\n";
}
void user::fill()
{
	char d1,d2,d3,d4,*t,*s;
	uname=0;
	clrscr();
	cout<<"Enter username( 3 digit integer only): ";

	do{d1=getchar();}while(d1<'1'||d1>'9');
	do{d2=getchar();}while(d2<'0'||d2>'9');
	do{d3=getchar();}while(d3<'0'||d3>'9');
	t=s;
	*s=d1;
	s++;
	*s=d2;
	s++;
	*s=d3;
	s++;
	*s=NULL;
	s=t;
	uname=atoi(s);

	clrscr();
	cout<<"Enter password ( 4 digit integer only):";

	do{d1=getch();}while(d1<'1'||d1>'9');
	do{d2=getch();}while(d2<'0'||d2>'9');
	do{d3=getch();}while(d3<'0'||d3>'9');
	do{d4=getch();}while(d4<'0'||d4>'9');
	t=s;
	*s=d1;
	s++;
	*s=d2;
	s++;
	*s=d3;
	s++;
	*s=d4;
	s++;
	*s=NULL;
	s=t;
	password=atoi(s);
}
class package
{       char name[100];
	char destination[100];
	int days;
	int totalppl;
	int kids;
	int adults;
	unsigned long int  acost,ccost;
	unsigned long int tcost;
	int avseats;
	char abttrip[200];
	 public:
	package()        //constructor
	{   	 strcpy(name,"NOT ASSIGNED");
		 strcpy(destination,"NOT ASSIGNED");
		 strcpy(abttrip,"NOT ASSIGNED");
		 tcost=0;
	}
	char* getpname()
	{ 	return name;
	}
	char* getdest()
	{	return destination;
	}
	unsigned long int calccost(int adults,int kids);
	void bookinputno();       //inputs user details
	void dispinfo();      //display tour details location etc
	int book();
	void updateppl(int,int);
	void fillpack();        //only for admin
	void dispcompact(int,int);      //display inside displayscreen
	void dispfull(int);	//display full package inside viewfullpack
	void adminmodify();
	void packmodify();
	int getavseats()
	{	return avseats;
	}
	void setavseats(int n2)
	{	avseats+=n2;
	}
}o1,o2,o4;
//end of class
void viewfullpack(int num,int n);
void managebooking();

void modifypackage();
void fillfile();
void displayscreen(int,int );

void main()
  {

	char ch1='0';
	while(ch1 < '1' || ch1 >'3')
	{
	clrscr();
	cout<<endl<<"\t\t\t\tWELCOME";
	cout<<"\n\n\n\n"
	    <<"\t\tLog in as \n\n\t\t\t1.User \n\n\t\t\t2.Admin\n"
	    <<"\n\t\t\t3.Exit \n\n \t\tEnter choice:";
	ch1=getchar();
	}

	switch(ch1)
	{	case '1': userfunc();
			  user_interface();
			  break;
		case '2': admin();
			  admin_interface();
			  break;
		case '3': exit(0);
			  break;
	}
  }

void userfunc()
{       char ch2='a';
	while(ch2<'1' || ch2 >'3')
	{
	clrscr();
	cout<<"\n\n\n\n\t Choose an option\n ";
	cout<<"\n\n\t\t1.To log in \n\n\t\t2.To create new account "
	    <<"\n\n\t\tEnter choice:";
	ch2=getchar();
	};
	switch(ch2)
	{	case '1': check_account();
			break;
		case '2': new_account();
			break;
		case '3': return;
	}
}

void admin()
{       clrscr();
	retry:

	cout<<"\n\n";
	user_o2.fill();
	if(user_o2.getuname()==admin_uname&&user_o2.getpass()==admin_password)
	{	cout<<"\n\n\nLog in successful..<press a key to continue> ";
		getch();
		return;
	}
	else
	clrscr();
	{	cout<<"\n\n\n\t\tWrong username or password!!!\n\nEnter"
		<<"\n\n     1.To try again\n\n     2.Back\n\nEnter choice:";
		int ch4;
		cin>>ch4;
		if(ch4==1)
		goto retry;
		else main();
	}
}
void check_account()
{	clrscr();
	retry3:
	user_o2.fill();          //account stored in user_o2
	ifstream fin("user.dat",ios::binary);
	while(fin.read((char*)&user_o1,sizeof(user_o1)))     //user_o1 is dummy object
	{	if(user_o2.getuname()==user_o1.getuname()&&user_o2.getpass()==user_o1.getpass())
		{	cout<<"\n\n\nLog in successful..";
			getch();
			return;
		}
	}
	fin.close();

	char ch5='0';
	while(ch5<'1' || ch5>'2')
	{
	clrscr();
	cout<<"\n\n\nEither username or password wrong!\n\n\tChoose an option\n"
	    <<"\n\t  1.To try again\n"
	    <<"\n\t  2.Back \n\n Enter choice:";
	 ch5=getchar();
	}

	switch(ch5)
	{
	 case '1': goto retry3;
		break;
	 case '2': main();
	}

}
void new_account()
{       clrscr();
	retry3:
	user_o2.fill();  //account stored in user_o2
		ifstream fin("user.dat",ios::binary);
		while(fin.read((char*)&user_o1,sizeof(user_o1))) //user_o1 is dummy object
		{	if(user_o2.getuname()==user_o1.getuname()||user_o2.getpass()==user_o1.getpass())
			{	cout<<"\nUsername or password already exists. Try again.";
				getch();
				//flag2=0;
				goto retry3;
			}
		}
		fin.close();
		ofstream fout("user.dat",ios::binary|ios::app);
		fout.write((char*)&user_o2,sizeof(user_o2));	//creating new account;
		fout.close();
		cout<<"\n\nAccount created. Congratulations!";
		getch();

}

void user_interface()
{       flag1:
	char ch3='a';
	while(ch3<'1' || ch3 > '3')
	{
	clrscr();
	cout<<"\n\n\n";
	cout<<"\t\t\t\tWELCOME USER!\n\n";
	cout<<"\t\tMENU: \n "
	    <<"\n\n\t\t1.View packages \n\n\t\t2.View your bookings "
	    <<"\n\n\t\t3.Back \n\n\t\tEnter choice:";
	ch3=getchar();
	}
	switch(ch3)
	{	case '1':int z1;
			 clrscr();
			 cout<<"\n1.View all\n2.View by destination:- ";
			 cin>>z1;
			 switch(z1)
			  {	case 1:displayscreen(200,1);
					break;
				/*case 2:displayscreen(200,2);
					break; */
				case 2: view_dest(200);
					break;
				default:cout<<"\nInvalid option !";
					getch();
					user_interface();

			  }
			  break;
		case '2': view_booking();
			  getch();
			  clrscr();
			  user_interface();
			  break;
		case '3': clrscr();
			  main();
	}
}

void view_booking()
{ ifstream fin("user.dat",ios::binary);
  while(fin.read((char*)&user_o1,sizeof(user_o1)))
    { if(user_o1.getuname()==user_o2.getuname())
	{       clrscr();
		cout<<"\nYou have booked the following package: ";
	  cout<<user_o1.getpack()<<endl;
	  cout<<"\n                  No. of seats booked: ";
	  cout<<user_o1.getnum()<<endl;
	  cout<<"\n\n\t\t<Press any key to go back> ";
	}
    }
}

void admin_interface()
{       do{
	char ch4='a';
	while(ch4<'1' || ch4>'6')
	{
	clrscr();
	cout<<"\n\n\t\t\t\tWELCOME ADMIN!";
	cout<<"\n\nMENU:"
	    <<"\n\n1.Add package   \n\n2.Delete package"
	    <<"\n\n3.Modify package\n\n4.Manage customer accounts"
	    <<"\n\n5.View packages \n\n6.Back\n\nEnter choice:";
	ch4=getchar();
	}
	switch(ch4)
	{	case '1':fillfile();
			break;
		case '2':delete_pack();
			break;
		case '3': modifypackage();
			break;
		case '4': manage_user();
			break;
		case '5':	int z1;
				clrscr();
				  cout<<"\nChoose an option\n1.View all\n2.View by destination:- ";
				  cin>>z1;
			  switch(z1)
			  {	case 1:displayscreen(100,1);
					break;
				/*case 2:displayscreen(100,2);
					break;*/
				case 2: view_dest(100);
					break;
				default:cout<<"\nInvalid option !";


			  }
			break;
		case '6': main();
			break;
	}
	getch();
	}while(1);
}
void manage_user()
{
	char ch5='a';
	while(ch5< '1' || ch5>'6')
	{
	clrscr();
	cout<<"\n\nMENU:"
	    <<"\n\n1.View all accounts \n\n2.Delete account"
	    <<"\n\n3.Add account \n\n4.Modify account"
	    <<"\n\n5.Cancel booking\n\n6.Back\n\nEnter choice:";
	ch5=getchar();
	}
	switch(ch5)
	{	case '1': view_account();
			break;
		case '2': delete_account();
			break;
		case '3': new_account();
			admin_interface();
			break;
		case '4': modify_account();
			break;
		case '5':cancel_booking();
			break;
		case '6': admin_interface();
			break;
	}
}
void modify_account()
  {
	retry5:
	int uname5;
	clrscr();
	cout<<"\nEnter user name of account to be modified:";
	cin>>uname5;
	int flag=0;
	ifstream fin("user.dat",ios::binary);
	ofstream fout("temp.dat",ios::binary);
	while(fin.read((char*)&user_o1,sizeof(user_o1)))
	{	if(user_o1.getuname()==uname5)
		{       int n=user_o1.getnum();
			//char name[20];
			//str
			user_o3.fill();
			user_o3.update_user(n,user_o1.getpack());
			fout.write((char*)&user_o3,sizeof(user_o3));
			flag=1;
			continue;  //CHECK
		}
		else
		fout.write((char*)&user_o1,sizeof(user_o1));
	}
	fin.close();
	fout.close();
	remove("user.dat");
	rename("temp.dat","user.dat");
	if(flag==0)
	{
	cout<<"\n\nAccount not found!!!\n\nEnter:\n "
	    <<"\n1.To try again \n\n2.To go back \n\n\nEnter choice:";
	int ch5;
	cin>>ch5;
	if(ch5==1)
	goto retry5;  }
	else
	cout<<"\n\nAccount modified! < Press enter... >";
	return;
}
void view_account()

{
	int n=1;
	clrscr();
	cout<<"\n\t\t\tUSER DETAILS:\n";
	ifstream fin("user.dat",ios::binary);
	while(fin.read((char*)&user_o3,sizeof(user_o3)))
	{       cout<<"\n\n"<<n<<".\n";
		user_o3.display();
		n++;
	}
	fin.close();
	if(n==1)
	cout<<"\n\nThere are no accounts!";
}
void delete_account()
{
	int uname5,ch6,n=0;
	retry6:
	clrscr();
	cout<<"\nEnter details of the account to be deleted:\nUsername: ";
	cin>>uname5;
	ifstream fin("user.dat",ios::binary);
	ofstream fout("temp.dat",ios::binary|ios::app);
	while(fin.read((char*)&user_o1,sizeof(user_o1)))
	{	if(uname5!=user_o1.getuname())
		{		fout.write((char*)&user_o1,sizeof(user_o1));
		}
		else
		n=1;
	}
	fin.close();
	fout.close();
		remove("user.dat");
	rename("temp.dat","user.dat");
	if(n==0)
	{	cout<<"\nAccount not found!\n "
		<<"\nEnter choice (1 or 2) "
		<<"\n\n1.To try again \n\n2.Back\n\nEnter :";
		cin>>ch6;
		if(ch6==1)
		goto retry6;
		else admin_interface();
	}
	else
	cout<<"Account deleted! Press any key to go back..";
	getch();

       //	if(ch6==1)
       //	goto retry6;
       admin_interface();

}
void delete_pack()
{       clrscr();
	char pack[10];
	int flag=0;
	getchar();
	cout<<"\nEnter name of package to be deleted: ";


		int i;
		for(i=0;pack[i-1]!='\r';i++)
		{
			pack[i]=getch();
				if(pack[i]=='\b')
			{
				cout<<'\b';
				cout<<' ';
				cout<<'\b';
				i=i-2;
				continue;

			}
			cout<<pack[i];
		}
		cout<<endl;
		pack[i]='\0';
	ifstream fin("package.dat",ios::binary);
	ofstream fout("temp2.dat",ios::binary);
	while(fin.read((char*)&o1,sizeof(o1)))
	{	if(strcmp (o1.getpname(),pack)!=0)
		   fout.write((char*)&o1,sizeof(o1));
		if(strcmp(o1.getpname(),pack)==0)
		{	//cout<<o1.getpname();
			flag++;
		}
	}

	if(flag==0)
	{	cout<<"\nPackage not found !";
	}
	else
	cout<<"\n DELETED!";
	cout<<"\n\n<Press any key to go back..>";
	getch();
	fin.close();
	fout.close();
	remove("package.dat");
	rename("temp2.dat","package.dat");
	admin_interface();
}

void fillfile()         //admin interface. will fill pack and write to file
{
	ofstream fout("package.dat",ios::binary|ios::app);

	if(!fout)
	{	cout<<"\nError opening in output mode !";
	}

	o1.fillpack();
	fout.write((char*)&o1,sizeof(o1));
	fout.close();


}

void displayscreen(int n,int z)    //when user clicks view package
{       //flag2:
	char choice='a';
	char chr;
	int c;
	while(choice <'1' || choice >'5')
	{
	clrscr();
	int packch=0;
	ifstream fin("package.dat",ios::binary);
		while(fin.read((char*)&o1,sizeof(o1)))
		{
		   packch=packch+1;
		   cout<<endl<<endl<<endl<<endl;
		   cout<<packch<<".";
		   o1.dispcompact(200,z);
		   cout<<" To view more details about this package,PRESS "<<packch;
		}
		c=packch;
		fin.close();
	if(packch==0)
	{  cout<<"\n\nThere are no packages. ";
	}
      //	flag2:
      //	char choice;
	if(packch!=0)	cout<<endl<<endl;
	cout<<"\n\n Enter correct pacakage number or  PRESS 5 to skip:";
	choice=getchar();
       /*	if(choice>c)
       */
      }
	flag2:
	switch(choice)
	{	case '1':viewfullpack(1,n);
			break;
		case '2':viewfullpack(2,n);
			if(c==0||c<2)
			{ goto excase;
			}
			break;

		case '3':viewfullpack(3,n);
			if(c==0||c<3)
			{ goto excase;
			}
			break;
		case '4':viewfullpack(4,n);
			if(c==0||c<4)
			{ goto excase;
			}
			break;
		case '5':    excase:
			if(n==100)
			admin_interface();
			else
			user_interface();
			break;
		default:cout<<"\nWrong choice. Please enter a valid option:";
			//choice=getchar();
			cin>>choice;
			goto flag2;

	}


}
void viewfullpack(int num,int n)      //viewing full details and press for booking
{        clrscr();
	int count=0;


	ifstream fin("package.dat",ios::binary);
	while(fin.read((char*)&o4,sizeof(o4)))
	{
		count++;
		if(count==num)
		{	o4.dispfull(n);
			break;
		}

	}
	fin.close();

}

void package::bookinputno()      //books and manages vacancies
{
		//booklabel:
		clrscr();
		cout<<"\n\t\t\tBOOK MENU:\n";
		cout<<"\nThe number of available seats is :"<<avseats;
		cout<<"\nEnter total number of persons for the trip:";
		cin>>totalppl;
		if(totalppl==0)
		{       return;
		}
		char n;
		if(totalppl>avseats)
		{	cout<<"\n"<<(totalppl-avseats)<<" seat/'s' short ";
			cout<<"\nPress any key to go back:";
			getch();
			return;
		}
		l1:
		cout<<"\nEnter the number of adults :";      //put conditions like >0
		cin>>adults;
     {                 if(totalppl<adults)
		{	cout<<"\nContradictory entry.Please try again.\n ";
			goto l1;
		}

			else if(adults<totalppl)       //check for adults=totalppl

		{	cout<<"\nEnter the number of children (age 13 and below):";
			cin>>kids;
			if(kids>totalppl-adults||(adults+kids)<totalppl)

		       {	cout<<"\nContradictory entry.Please try again.\n ";
				goto l1;
		       }



		}
		else if(adults=totalppl)
		{	kids=0;
		}
     }
		tcost=calccost(adults,kids);
		cout<<"\n\nThe total cost is :"<<tcost;
		int choice2;
		flag10:
		cout<<"\n\nPress 1 to confirm booking \nPress 2 to revisit booking menu\nPress 3 to exit to main menu :";
		cin>>choice2;
		switch(choice2)
		{       clrscr();       //should be out of switch
			case 1: cout<<"\n\n\t\t\tBOOKING CONFIRMED !";
				cout<<"\nPAYABLE AMOUNT :"<<tcost;
				updateppl(0,1);      //check
				user_o2.update_user(totalppl,name);
				user_update();
				getch();
				user_interface();
				break;
			case 2: bookinputno();
				break;
			case 3:user_interface();
				break;
			default:cout<<"\nPlease enter valid option.";
				goto flag10;



		}
	return;
}
unsigned long int package::calccost(int adults,int kids) //class fn to calc total cost
{       tcost=(adults*acost)+(kids*ccost);
		return tcost;
}
void package::updateppl(int oldppl,int z) //class fn to update seats after
{
	if(z==1)
	{avseats=(avseats+oldppl)-totalppl;
	}
	else if(z==2)
	{	avseats=avseats+oldppl;
	}
	ofstream fout("temp4.dat",ios::binary|ios::app);
	ifstream fin("package.dat",ios::binary);
	package obj;
	while(fin.read((char*)&obj,sizeof(obj)))
	{
		if(strcmp(name,obj.name)==0)
		{	fout.write((char*)&o4,sizeof(o4));


		}
		else
		{
			fout.write((char*)&obj,sizeof(obj));

		}
	}
		fin.close();
		fout.close();
		remove("package.dat");
		rename("temp4.dat","package.dat"); //booking

}


void package::fillpack()
//only for admin
{               clrscr();
		char key;
		cout<<"\t\t\t**NEW PACKAGE** ";
		cout<<"\n\nName of package:";
		//cin>>name;
		int i;
		for(i=0;name[i-1]!='\r';i++)
		{
			name[i]=getch();
			if(name[i]=='\b')
			{
				cout<<'\b';
				cout<<' ';
				cout<<'\b';
				i=i-2;
				continue;

			}
			cout<<name[i];
		}
		name[i]='\0';
	   //	cin.getline(name,100,'\r');
		cout<<"\nPackage Destination:";
	     //	cin>>destination;
			for(i=0;destination[i-1]!='\r';i++)
		{
			destination[i]=getch();
				if(destination[i]=='\b')
			{
				cout<<'\b';
				cout<<' ';
				cout<<'\b';
				i=i-2;
				continue;

			}
			cout<<destination[i];
		}
		//new line
		cout<<endl;
		destination[i]='\0';
		//	cin.getline(destination,100,'\r');
		cout<<"\nEnter package details:";
	     //	cin>>abttrip;
		for(i=0;abttrip[i-1]!='\r';i++)
		{
			abttrip[i]=getch();
				if(abttrip[i]=='\b')
			{
				cout<<'\b';
				cout<<' ';
				cout<<'\b';
				i=i-2;
				continue;

			}
			cout<<abttrip[i];
		}
		//new line
		cout<<endl;

		abttrip[i]='\0';

	     //	cin.getline(abttrip,100,'\r');
		cout<<"\nTrip no. of days :";
		cin>>days;
		cout<<"\nInitial vacancies:";
		cin>>avseats;
		cout<<"\nCost per adult:";
		cin>>acost;
		cout<<"\nCost per child:";
		cin>>ccost;
		cout<<"\n\n\t\t\tCongratulations.Package uploaded !";

}
void package::dispcompact(int n,int z)      //display inside displayscreen

{
    if(z==1)
    {	cout<<name;
    }
    else if(z==2)

    {
	puts(destination);
    }
	cout<<endl;

}
void package::dispfull(int n)	//For user when he views the full pack
{
	char choice='a';
	dispfullmenu:
      do
       {
	clrscr();
	cout<<"\n\t\t       PACKAGE DETAILS \n\n";
	cout<<"\nName of package:"; //and wants to book
	cout<<name;
	cout<<"\nDestination:";
	cout<<destination;
	cout<<"\nDetails:";
	cout<<abttrip;
	cout<<"\nNo. of days:";
	cout<<days;
	cout<<"\n\nRemaining vacancies:";
	cout<<avseats;
	cout<<"\n\nTicket Fare per adult:";
	cout<<acost;
	cout<<"\n\nTicket Fare per child:";
	cout<<ccost;

	cout<<"\n\n\n\n\n\n\n PRESS  \n";
	if(n!=100)
	{
		cout<<"\n'1' to proceed towards booking\n";
	}
		cout<<"\n'2' to go back\n";
	choice=getch();
       } while(choice<'1' || choice>'2');

	switch(choice)
	   {   	case '1':if(n!=100)bookinputno();
			 break;
		case '2':if(n!=100)user_interface();
			   else
			     admin_interface();
			 break;
	   }
	goto dispfullmenu;

}



void  modifypackage()
{     package o2;
	char newname[30];
      clrscr();
      cout<<"\nEnter name of package to be modified :";
    //  cin>>newname;
		int i;
		for(i=0;newname[i-1]!='\r';i++)
		{
			newname[i]=getch();
				if(newname[i]=='\b')
			{
				cout<<'\b';
				cout<<' ';
				cout<<'\b';
				i=i-2;
				continue;

			}
			cout<<newname[i];
		}
		cout<<endl;
		newname[i]='\0';
      ifstream fin("package.dat",ios::binary);
      if(!fin){	cout<<"error !";}
      ofstream fout("temp1.dat",ios::binary);
      if(!fout){ cout<<"error !";}
      int flag=0;

      while(fin.read((char*)&o2,sizeof(o2)))
      {  	if(strcmp(newname,o2.getpname())==0)
	       {
			o2.packmodify();   //goes to packmodify
			fout.write((char*)&o2,sizeof(o2));
			flag++;
			break;
	       }

		else
		{   fout.write((char*)&o2,sizeof(o2));
		}

      }
      if(flag==0)
      {		cout<<"\nPackage not found !";

      }
      fin.close();
      fout.close();

      remove("package.dat");
      rename("temp1.dat","package.dat");
      cout<<"\n<Press any key to go back..>";
      getch();
      admin_interface();
}
void package::packmodify()
{               cout<<"\n\n*You have chosen to modify pack: ";
		cout<<name;
		cout<<"\nEnter new name of package:";

	       //	cin>>name;
	       int i;
		for(i=0;name[i-1]!='\r';i++)
		{
			name[i]=getch();
				if(name[i]=='\b')
			{
				cout<<'\b';
				cout<<' ';
				cout<<'\b';
				i=i-2;
				continue;

			}
			cout<<name[i];
		}
		cout<<endl;
		name[i]='\0';
		cout<<"\nPackage Destination:";
	    //	cin>>destination;

		for(i=0;destination[i-1]!='\r';i++)
		{
			destination[i]=getch();
				if(destination[i]=='\b')
			{
				cout<<'\b';
				cout<<' ';
				cout<<'\b';
				i=i-2;
				continue;

			}
			cout<<destination[i];
		}
		cout<<endl;
		destination[i]='\0';
		cout<<"\nEnter package details:";
	      //	cin>>abttrip;

		for(i=0;abttrip[i-1]!='\r';i++)
		{
			abttrip[i]=getch();
				if(abttrip[i]=='\b')
			{
				cout<<'\b';
				cout<<' ';
				cout<<'\b';
				i=i-2;
				continue;

			}
			cout<<abttrip[i];
		}
		cout<<endl;
		abttrip[i]='\0';
		cout<<"\nTrip no. of days :";
		cin>>days;
		cout<<"\nInitial vacancies:";
		cin>>avseats;
		cout<<"\nFare per adult:";
		cin>>acost;
		cout<<"\nFare per child:";
		cin>>ccost;
		cout<<"\nPackage modified!";
}
void user_update()
{       user user_dummy;
	ifstream fin("user.dat",ios::binary);
	ofstream fout("temp3.dat",ios::binary);
	while(fin.read((char*)&user_dummy,sizeof(user_dummy)))
	{	if(user_dummy.getuname()==user_o2.getuname())
		{	fout.write((char*)&user_o2,sizeof(user_o2));
			continue;
		}
		else
		{	fout.write((char*)&user_dummy,sizeof(user_dummy));
		}
	}
	fin.close();
	fout.close();
	remove("user.dat");
	rename("temp3.dat","user.dat");
}
void cancel_booking()
{       clrscr();
	int ch6=0;
	char name2[20];
	int n2;
	user user_5;
	flag1:
	cout<<"Enter username:";
	int uname;
	cin>>uname;
	int count1;
	ifstream fin("user.dat",ios::binary);
	ofstream fout7("temp7.dat",ios::binary);
	while(fin.read((char*)&user_5,sizeof(user_5)))
	{	if(uname==user_5.getuname())
		{       count1=1;
			cout<<"\nCurrent booking:"<<user_5.getpack();
			cout<<"\nNo. of seats booked: "<<user_5.getnum();
		      /*	if(user_5.getnum()==0)
			{	cout<<"\n<Press any key to go back..>";
				fin.close();
				getch();
				admin_interface();
			}         */
			strcpy(name2,user_5.getpack());    //name2 contains name of package
			n2=user_5.getnum();//no. of seats booked
			flag2:
			cout<<"\nEnter 1 to cancel booking,2 to go back:";
			//int ch6;
			cin>>ch6;
			if(ch6==2)
			{ fout7.write((char*)&user_5,sizeof(user_5));
				continue;
			}
			//cin>>ch6;
			else if(ch6==1)
			{	user_5.update_user(0,"NONE"); //booking cancelled
				//fin.close();
				fout7.write((char*)&user_5,sizeof(user_5));
				cout<<"\n\t\t\tBooking cancelled";
				continue;

			}
		   /*	else if(ch6==2)
			{       fin.close();
				admin_interface();
			}
			else
			{	cout<<"Wrong choice. Enter again:";
				goto flag2;
			}
		}
		      */
		}
		      fout7.write((char*)&user_5,sizeof(user_5));
	}
	fin.close();
	fout7.close();
	remove("user.dat");
	rename("temp7.dat","user.dat");
	if(ch6==2)
	admin_interface();
     /*	if(count1==0)
	{       int ch6;
		cout<<"Account not found.\nEnter 1 to try again,2 to go back: ";
		cin>>ch6;
		switch(ch6)
		{	case 1: admin_interface();
				break;
			case 2: goto flag1;
				break;
		}
	}      */
     /*	else
	{	//upadating user file
	ifstream fin("user.dat",ios::binary);
	ofstream fout("temp4.dat",ios::binary);
	 user user_dummy;
	while(fin.read((char*)&user_dummy,sizeof(user_dummy)))
	{	if(user_dummy.getuname()==uname)
		{	fout.write((char*)&user_5,sizeof(user_5));
		}
		else
		fout.write((char*)&user_dummy,sizeof(user_dummy));
	}
	fin.close();
	fout.close();
	remove("user.dat");
	rename("temp4.dat","user.dat");        */
	//updating no. of seats
		if(count1!=1)
	{	cout<<"\nAccount not found!\nEnter 1 to try again,2 to go back: ";
		int ch8;
		cin>>ch8;
		switch(ch8)
		{	case 1: cancel_booking();
			break;
			case 2: admin_interface();
		}
	}
	ifstream fin2("package.dat",ios::binary);
	ofstream fout2("temp5.dat",ios::binary);
	package dummy2;
	while(fin2.read((char*)&dummy2,sizeof(dummy2)))
	{     //  cout<<"\npupdate loop"<<n2;
		if(strcmp(name2,dummy2.getpname())==0)
		{
			dummy2.setavseats(n2);
		    //	cout<<"set av seats loop";
			fout2.write((char*)&dummy2,sizeof(dummy2));
		}
		else
		fout2.write((char*)&dummy2,sizeof(dummy2));
	}
	fin2.close();
	fout2.close();
	remove("package.dat");
	rename("temp5.dat","package.dat");


}
void view_dest(int n)
{       clrscr();
	package dummy3;
	int counter=0;
	char name3[100];
	cout<<"Enter destination: ";
		int i;
		for(i=0;name3[i-1]!='\r';i++)
		{
			name3[i]=getch();
			//cout<<name3[i];
			if(name3[i]=='\b')
			{	cout<<'\b';
				cout<<' ';
				cout<<'\b';
				i=i-2;
				continue;
			}
			cout<<name3[i];
		}
		name3[i]='\0';
		cout<<endl;
		//name3[i]='\0';
	ifstream fin3("package.dat",ios::binary);
	if(!fin3)
	{	cout<<"Error";
	}
	while(fin3.read((char*)&dummy3,sizeof(dummy3)))
	{
		//if(strcmp(name2,dummy2.getpname())==0)
		if(strcmp(name3,dummy3.getdest())==0)
		{     //  cout<<"check2";
			cout<<counter++<<endl;
			dummy3.dispfull(n);

		}
	}
	fin3.close();
	if(counter==0)
	{	cout<<"\nPackage not found!";
	}
	cout<<"\n\n<Press any key to go back..>";
	getch();
	if(n==100)
	{	admin_interface();
	}
	else user_interface();
}










