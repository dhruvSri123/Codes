#include<iostream.h>

#include<conio.h>

#include<math.h>

#include<stdio.h>

#include<stdlib.h>

#include<dos.h>

#include<graphics.h>

#include<stdlib.h>

void victory()

{  int gdriver=DETECT,gmode;

    initgraph(&gdriver,&gmode,"C:/BGI");

     settextstyle(COMPLEX_FONT,HORIZ_DIR,3);

     setcolor(GREEN);

    outtextxy(270,90,"YOU");

    delay(550);

    settextstyle(COMPLEX_FONT,HORIZ_DIR,3);

    outtextxy(250,140,"ARE A ");

    delay(700);

    setcolor(GREEN);

    settextstyle(TRIPLEX_SCR_FONT,HORIZ_DIR,6);

    setcolor(YELLOW);

    outtextxy(215,220,"WINNER !!!");

     settextstyle(TRIPLEX_SCR_FONT,HORIZ_DIR,1);

     setcolor(GREEN);

      outtextxy(200,350,"Thank You For Playing !");

      delay(3000);

      exit(0);

      getch();

      closegraph();

      }









void prize()

{

    int gdriver=DETECT,gmode;

    initgraph(&gdriver,&gmode,"C:/BGI");

    settextstyle(TRIPLEX_SCR_FONT,HORIZ_DIR,3);

    setcolor(YELLOW);

    outtextxy(250,20,"PRIZES");

    setcolor(RED);

    settextstyle(COMPLEX_FONT,HORIZ_DIR,1);

    outtextxy(30,65,"1) EXTRA 30mks IN THEORY EXAM.");

    delay(4000);

    closegraph();

    getch();

}



int recharge()

{

    int q,m,i=250,j=250,x=0,y=-1,ch,gd=DETECT,gm;

    initgraph(&gd,&gm,"C:/BGI");

    int l,k;

	l=random(getmaxx());

	k=random(getmaxy());

    while(ch!='e')                                                               //infinite loop

    {

	circle(i,j,30);

	outtextxy(1,1,"Press e to Exit.....");

	randomize();

	outtextxy(l,k,"*");

	if(kbhit())                                            //check if a key is pressed

	{

	    ch=getch();

	    if(ch==72)

	    {

		x=0;

		y=-1;

	    }



	    if(ch==75)

	    {

		x=-1;

		y=0;



	    }



	    if(ch==77)

	    {

		x=1;

		y=0;

	    }



	    if(ch==80)

	    {

		x=0;

		y=1;

	    }



	    if(ch==101)

	    {

		int gdriver=DETECT,gmode;

		initgraph(&gdriver,&gmode,"C:/BGI");

		settextstyle(0,HORIZ_DIR,1);

		setcolor(GREEN);

		delay(270);

		prize();                        //exit when esc pressed

		exit(0);

	    }

	}

	i=i+x;

	j=j+y;

	delay(5);

	cleardevice();

	if(sqrt(pow(i-l,2)+pow(j-k,2))<=32)

	{

		closegraph();

	    return 1;

	}

    }

    getch();

    return -1;

}



void intro ()

{



    setbkcolor(rand());

    int x=200,i,gdriver=DETECT,gmode;

    initgraph(&gdriver,&gmode,"C:/BGI");

    settextstyle(COMPLEX_FONT,HORIZ_DIR,2);

    setcolor(GREEN);

    outtextxy(165,168,"Loading");

    setcolor(YELLOW);

    outtextxy(310,223,"Please Wait....");





    for(i=0; i<200; ++i)

    {

	delay(30);

	setcolor(rand());

	line(x,205,x,220);   //IT MEANS (X1Y1)(X2Y2),(C,R)

	x++;

    }

    getch();

    closegraph();

}



void start()

{

    clrscr();

    int at=DETECT,am,i,k;

    initgraph(&at, &am, "C:/BGI");

    for(i=0; i<670; i++)

    {   delay(5);

	if(i<=310)

	    setcolor(GREEN);

	else

	    setcolor(YELLOW);

	circle(0+i,40,20);

    }

    settextstyle(COMPLEX_FONT,HORIZ_DIR,3);

    outtextxy(265,165,"WELCOME");

    delay(250);

    settextstyle(COMPLEX_FONT,HORIZ_DIR,2);

    outtextxy(310,205,"TO");

    delay(500);

    setcolor(GREEN);

    settextstyle(TRIPLEX_SCR_FONT,HORIZ_DIR,6);

    outtextxy(140,240,"HANGCHARGE");

    cout<<"your game starts in : ";

    for(k=5; k>=0; k--)

    {   cout<<k;

	delay(150);

    }











    getch();



    closegraph();

}







void main()

{   clrscr();

    start();

    intro();

    char ch,b[20],c[20];

    char l1[5][20]= {"godzilla","spiderman","superman returns","enter the dragon","interstellar"};

    int r,test=1,gameon=1,i,j,o=3,x,y,flag=-1;

    randomize();

    int p;

    p=random(5);

    for(j=0,x=0; l1[p][j]!='\0'; j++,x++)

    { if(l1[p][j]==' ')

       b[x]='/';

       else

    b[x]=l1[p][j];

    }

    b[x]='\0';

    for(j=0,y=0; l1[p][j]!='\0'; j++,y++)

    {

	if(l1[p][j]=='a')

	{

	    c[y]='a';

	}

	else if(l1[p][j]==' ')

	{

	    c[y]='/';

	}

	else if(l1[p][j]=='e')

	{

	    c[y]='e';

	}

	else if(l1[p][j]=='i')

	{

	    c[y]='i';

	}

	else if(l1[p][j]=='o')

	{

	    c[y]='o';

	}

	else if(l1[p][j]=='u')

	{

	    c[y]='u';

	}

	else

	{

	    c[y]='.';

	}

    }

    c[y]='\0';

    cout<<c;

    while(gameon==1)

    {

	int m,n,k;

	gameon=1;

	for(m=12; ; m=m-3)

	{

	test=1;

	  for(r=0;b[r]!='\0';r++)                       //check

	      {

		if(b[r]!=c[r])

		   {test=-1;

		   break;}

		}

		if(test==1)

		{

		clrscr();

		victory();

		}

	    if(m>=4)

	    {

		textcolor(GREEN);

		clrscr();

		cout<<c;

		gotoxy(69,1);

		for(n=m; n>=1; n--)

		{



		    cout<<"|";

		}



		cin>>ch;

		o--;

		delay(50);

	    }



	    else

	    {

		textcolor(RED+BLINK);

		clrscr();

		cout<<c;

		gotoxy(69,1);

		for(n=m; n>=1; n--)

		{

		    cout<<"|";

		}

		cin>>ch;

		o--;

		delay(50);

	    }

	    for(x=0; b[x]!='\0'; x++)

	    {   if(b[x]==ch)

		{

		    c[x]=ch;

		    flag=1;

		}

	    }

	    if(flag==-1)

		cout<<c;

	    if(flag==1)

	    {   cout<<c;

		flag=-1;

	    }



	    if(m==3)

			{

			    clrscr();

		gotoxy(69,1);

		cout<<"dead";

		gotoxy(1,1);

		textcolor(YELLOW);

		clrscr();

			    cout<<endl<<"you need to recharge the battery , so play this game ."<<endl;

		delay(1000);

		clrscr();

		cout<<endl<<"your game will be saved , PLAY.";

		delay(1500);

		clrscr();

				recharge();

				m=12;



			}

	}         //for for

    }

    getch();

}
