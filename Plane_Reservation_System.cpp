#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
#include<dos.h>
#include<string.h>
void exit1()
{  int gdriver=DETECT,gmode;
    initgraph(&gdriver,&gmode,"C:/BGI");
     settextstyle(10,HORIZ_DIR,4);
     setcolor(LIGHTBLUE);
     outtextxy(70,150,"POLESTAR AIRLINES");
     delay(20);
     settextstyle(7,HORIZ_DIR,1);
     setcolor(WHITE);
     outtextxy(250,220,"Do It With Style.....");
       delay(3000);
      cleardevice();
      getch();
      closegraph();
      }
void intro ()
{

    setbkcolor(rand());
    int x=200,i,gdriver=DETECT,gmode;
    initgraph(&gdriver,&gmode,"C:/BGI");
    settextstyle(COMPLEX_FONT,HORIZ_DIR,2);
    setcolor(WHITE);
    outtextxy(165,168,"searching");
    setcolor(LIGHTBLUE);
    outtextxy(310,223,"Please Wait....");


    for(i=0; i<200; ++i)
    {
	delay(30);
	setcolor(LIGHTBLUE);
	line(x,205,x,220);   //IT MEANS (X1Y1)(X2Y2),(C,R)
	x++;
    }
    getch();
    closegraph();
}
void faqs1()
{
textcolor(WHITE);
clrscr();
gotoxy(28,1);
cout<<"FREQUENTLY ASKED QUESTIONS";
gotoxy(1,8);
getch();
 }
void rtable()
{
gotoxy (22,6);
for(int i=0;i<36;i++)
{
cout<<"-";
}
gotoxy (22,20);
for(int j=0;j<36;j++)
{
cout<<"-";
}
int k=5;
for(i=0;i<7;i++)
{
gotoxy(21,k=k+2);
cout<<"|";
}
k=5;
for(i=0;i<7;i++)
{
gotoxy(58,k=k+2);
cout<<"|";
}
gotoxy(25,8);
}
void start()
{
    clrscr();
    int at=DETECT,am,i,k;
    initgraph(&at, &am, "C:/BGI");
    for(i=0; i<670; i++)
    {   delay(2);
	if(i%30==0)
	    setcolor(WHITE);
	else
	    setcolor(LIGHTBLUE);
	circle(0+i,40,20);
    }
    setcolor(WHITE);
    settextstyle(COMPLEX_FONT,HORIZ_DIR,6);
    outtextxy(180,110,"POLESTAR");
    delay(25);
    delay(50);
    setcolor(LIGHTBLUE);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,6);
    outtextxy(200,185,"AIRLINES");
    getch();
    setcolor(WHITE);
     settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
    outtextxy(200,280," connecting the world...... ");
    delay(100);
    getch();
     for(i=0; i<670; i++)
    {   delay(2);
	if(i%30==0)
	    setcolor(WHITE);
	else
	    setcolor(LIGHTBLUE);
	circle(0+i,388,20);
    }
    delay(500);
    closegraph();
}
class ticket
{
private:
int age;
char name[100],origin[100],destination[100],gender,doj[100],passno[100],type[100];
public:
int retpassno(char a[20])
{if(strcmp(passno,a)==0)
return 1;
else
return -1;
}
void display()
{cout<<"NAME:"<<name<<"\n"<<"AGE:"<<age<<"\n"<<"GENDER:"<<gender<<"\n"<<"PASSPORT NO:"<<passno<<"\n"<<"ORIGIN:"<<origin<<"\n"<<"DESTINATION:"<<destination<<"\n"<<"CLASS:"<<type<<"\n"<<"DATE OF JOURNEY:"<<doj<<"\n";
cout<<"-----------------------------------------------------"<<"\n";
}
void calcfare()
{cout<<"TOTAL PRICE : Rs.";
if(strcmp("executive",type)==0)
{
int rate1;
rate1=random(5001);
if(rate1<100)
{
rate1=17*rate1;
cout<<rate1;
}
else if(rate1>100&&rate1<1000)
{
rate1=13*rate1;
cout<<rate1;
}
else cout<<19*rate1;
}
if(strcmp("economy",type)==0)
{
int rate2;
rate2=random(4001);
if(rate2<100)
{rate2=99*rate2;
cout<<rate2;
}
else if(rate2>100&&rate2<1000)
{
rate2=11*rate2;
cout<<rate2;
}
else cout<<rate2;
}
}

void accept()
{
rtable();
cout<<"NAME : ";
gets(name);
gotoxy(25,10);
cout<<"AGE : ";
cin>>age;
gotoxy(25,12);
cout<<"GENDER M/F: ";
cin>>gender;
gotoxy(25,14);
cout<<"PASSPORT NO : ";
gets(passno);
clrscr();
rtable();
cout<<"ORIGIN : ";
gets(origin);
gotoxy(25,10);
cout<<"DESTINATION : ";
gets(destination);
gotoxy(25,12);
cout<<"CLASS : ";
gets(type);
gotoxy(25,14);
cout<<"DOJ : ";
gets(doj);
gotoxy(25,16);
calcfare();
cout<<endl;
}
};
void main()
{
fstream file;
clrscr();
ticket t;
char ct='m';
//  start();
int j;
while (ct=='m')
{
gotoxy (22,4);
for(int i=0;i<36;i++)
{
cout<<"-";
}
gotoxy (22,18);
for(j=0;j<36;j++)
{
cout<<"-";
}
int k=3;
for(i=0;i<7;i++)
{
gotoxy(21,k=k+2);
cout<<"|";
}
k=3;
for(i=0;i<7;i++)
{
gotoxy(58,k=k+2);
cout<<"|";
}
gotoxy(25,6);
cout<<"1. RESERVATION";
gotoxy(25,8);
cout<<"2. CANCELLATION";
gotoxy(25,10);
cout<<"3. PASSENGER DETAILS";
gotoxy(25,12);
cout<<"4. FAQs";
gotoxy(25,14);
cout<<"5. SEARCH";
gotoxy(25,16);
cout<<"6. EXIT";
fstream file1;
char choice;
gotoxy(25,20);
cout<<"enter choice : ";
cin>>choice;
clrscr();
switch(choice)
{
case '1':file1.open("project12.dat",ios::app);
	 t.accept();
	 file1.write((char*)&t,sizeof(t));
	 gotoxy(25,22);
	 cout<<"enter m for main menu :";
	 cin>>ct;
	 file1.close();
	 getch();
	 clrscr();
	 break;
case '2':
	 ifstream ifile("project12.dat");
	 ofstream ofile("temp.dat");
	 char n[20];
	 cout<<"please enter the passport no of passenger: ";
	 cin>>n;
	 // intro();
	 while(!ifile.eof())
	 {ifile.read((char*)&t,sizeof(t));
	 if(ifile.eof())
	 break;
	 if(t.retpassno(n)!=1)
	 ofile.write((char*)&t,sizeof(t));}
	 ofile.close();
	 ifile.close();
	 remove("project12.dat");
	 rename("temp.dat","project.dat");
	 cout<<"The ticket has been cancelled";
	 cout<<endl;
	 cout<<"enter m for main menu :";
	 cin>>ct;
	 clrscr();
	  break;
case'3':file1.open("project12.dat",ios::in);
	while(!file1.eof())
	{file1.read((char*)&t,sizeof(t));
	if(file1.eof())
	break;
	t.display();
	}
	file1.close();
	cout<<"enter m for main menu: ";
	cin>>ct;
	clrscr();
	break;
case '4':
faqs1();
cout<<"1.I am visually impaired and will be carrying a white cane with me, how shall I inform the airlines?"<<endl;
cout<<"- Kindly contact us at 0124 6613838 if you have any assisting devices. We will find out the best way to store them so they arrive without damage. At the airport, please let the check-in personnel know that you may need extra time to board the plane. After the plane has landed, kindly wait in the plane until you see or have your assisting device, wheelchair, etc."<<endl;
delay(2500);clrscr();faqs1();
cout<<"2. I am visually impaired, can I travel with my guide dog? If yes, what are the formalities involved?"<<endl;
cout<<"- We will make special arrangements for your Guide/Assistance Dog, to ensure they are able to travel with you in the aircraft cabin. Certified Assistance Dogs for blind passengers can travel free of charge in the aircraft cabin. Notify us at 0124 6613838 when travelling with a Guide/Assistance Dog at the time of booking as the number carried on each aircraft is restricted ."<<endl;
delay(2500);clrscr();faqs1();
cout<<"3. Can I cancel my reservation on polestarair.com?"<<endl;
cout<<"- Yes, if your plans change and you prefer not to change your itinerary immediately, you may cancel the reservation and return to it later to make flight changes for up to one year from the date of issue."<<endl;
delay(2500);clrscr();faqs1();
cout<<"4. Travelling with electronic cigarettes?"<<endl;
cout<<"- Electronic cigarettes are not allowed in checked baggage. You may travel with electronic cigarettes in your carry-on bags only. Smoking is never allowed onboard any flight."<<endl;
delay(2500);clrscr();faqs1();
cout<<"5. About the Plane. "<<endl;
cout<<"- We maintain a fleet of 139 planes and each plane is a BOEING 787 DREAMLINER , the  best in the market."<<endl;
gotoxy(25,12);
cout<<"enter m for main menu: ";
cin>>ct;
getch();
clrscr();
break;
case'5':file.open("project12.dat",ios::in);
	cout<<"enter the passport no of passenger to be searched:";
	cin>>n;
	while(!file.eof())
	{file.read((char*)&t,sizeof(t));
	if(file.eof())
	break;
	if(t.retpassno(n)==1)
	t.display();
	}
	if(t.retpassno(n)==-1)
	cout<<endl<<"This record does not exist:";
	file.close();
	cout<<endl;
	cout<<"enter m for main menu";
	cin>>ct;
	clrscr();
	break;
case'6':gotoxy(25,26);
	exit1();
	getch();
	exit(0);

    }

}
getch();
}
