#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"mouse.cpp"
#include<dos.h>
#include<string.h>


void first_page();
void bacground(void);
void player_f1(void);
void harrow_f2();
void counter(int *p1,int i,int p2);
void numbering_box(void);
void set_boxg(int i);
void mouse(void);
void dise(int x,int y,int c);
void snakegr(void);
void snake(void);
int snake_f1(int x,int y,int d1,int d2,int xx,int yy,int c,int i);
int snake_f2(int x,int y,int d1,int d2,int xx,int yy,int c,int i);
//void second_page(void);

int ax[101],ay[101],ac[101],x,y,p[4],c[4],player,condition=0;
//char player_name[20];
void main()
{
    int driver=DETECT,mode;
    initgraph(&driver,&mode,"C:\\TC\\BGI");
    first_page();
    mouse_reset();
   // second_page();
     player=1;
     p[0]=p[1]=p[2]=p[3]=0;
    numbering_box();
    bacground();
    snakegr();
    snake();
    mouse_on();

    mouse();
    getch();
    closegraph();
}
void first_page()//It,s use fo game introduction.
 {
     int i,k;
     setfillstyle(9,5);
     bar(7,55,633,385);//making bar area

     settextstyle(7,0,5);
     setcolor(25);
     outtextxy(30,52,"WELLCOME TO EVERYBODY");

     settextstyle(7,0,4);
     setcolor(25);
     outtextxy(135,135," TO THE GAME ZONE");

     settextstyle(7,0,3);
     setcolor(12);
     outtextxy(220,200,"SNAKE AND LADDER");
     setcolor(3);
     outtextxy(90,250,"Submitted To: A.S.M Delowar Hossain");
     outtextxy(145,300,"Assistant Professor,Department Of CSE");
     settextstyle(7,0,4);
     setcolor(10);
     outtextxy(100,345,"Developed By: Md.Suzauddin");


  do
 {

   for(k=0;k<3;k++)
   {
    setcolor(k);
    settextstyle(0,0,2);
    outtextxy(110,410,"PRESS ANY KEY TO CONTINUE");
    delay(400);
    }
 }while(!kbhit());
     cleardevice();

 }
void bacground()   //function for graphical view of ludu start
{

    int maxx,maxy,i,z,color;
    char c[4];
    maxx=getmaxx();
    maxy=getmaxy();
    //x axis
    for(x=0;x<=maxx;x++)
    {
	 putpixel(x,0,1);
	 putpixel(x,maxy,1);
    }
    //y axis
     for(y=0;y<=maxy;y++)
    {
	 putpixel(0,y,1);
	 putpixel(maxx,y,1);
    }
		//exit box
    setfillstyle(9,4);
    bar(609,2,637,18);

    setcolor(15);//exit box cross symbol
    line(619,6,627,14);
    line(627,6,619,14);

    //create dise box and box number
    setcolor(0) ;
    settextstyle(0,0,1);
    for(i=1;i<101;i++)
    {
	setfillstyle(1,ac[i]);//for hole style
       //	strcpy(c,'\0');

	gcvt(i,4,c);//for craete box number
	bar(ax[i],ay[i],ax[i]+36,ay[i]+36);//for box size
	outtextxy(ax[i]+5,ay[i]+15,c);//for box number text style
    }

    //corner box left up
    setfillstyle(1,14);
    bar(2,22,114,134);
    bar(115,22,152,58);
    bar(2,135,38,172);

    //corner box right up
    setfillstyle(1,1);
    bar(344,22,456,134);
    bar(306,22,343,58);
    bar(420,135,456,172);

    //corner box left down
    setfillstyle(1,4);
    bar(2,364,114,476);
    bar(2,326,38,363);
    bar(115,440,152,476);

    //corner box right down
    setfillstyle(1,6);
    bar(344,364,456,476);
    bar(420,326,456,363);
    bar(306,440,343,476);

    //press box//
    setcolor(15);
    setfillstyle(1,6);
    bar3d(498,348,592,422,7,1);

   // stating dise and position
    setcolor(15);
    //player 1
    line(467,70,633,70);
    line(467,104,633,104);
    line(467,138,633,138);
    line(467,70,467,138);
    line(633,70,633,138);

    //computer
    line(467,175,633,175);
    line(467,209,633,209);
    line(467,243,633,243);

    line(467,175,467,243);
    line(633,175,633,243);

    dise(618,86,4);//p1
    dise(618,191,1);//com
    //player 1
    settextstyle(0,0,2);
    setcolor(4);
    outtextxy(472,81,"YOUR");
    settextstyle(7,0,1);
    outtextxy(472,110,"POSITION :");

    //computer
    settextstyle(0,0,2);
    setcolor(1);
    outtextxy(472,186,"COMPUTER");
    settextstyle(7,0,1);
    outtextxy(472,215,"POSITION ");
}

 void numbering_box() //function for keep the dise box position and color start

{
     int i,k=0;
     ax[1]=154;ay[1]=440;ac[1]=7;ax[5]=306;ay[5]=402;ac[5]=12;ax[11]=116;ay[11]=364;ac[11]=8;
     ax[17]=382;ay[17]=326;ac[17]=9; ax[27]=2;ay[27]=288;ac[27]=7;ax[39]=420;ay[39]=250;ac[39]=12;
     ax[51]=2;ay[51]=212;ac[51]=9;ax[63]=420;ay[63]=174;ac[63]=7;ax[75]=40;ay[75]=136;ac[75]=12;
     ax[85]=306;ay[85]=98;ac[85]=13;ax[91]=116;ay[91]=60;ac[91]=9;ax[97]=268;ay[97]=22;ac[97]=7;
     for(i=2;i<101;i++)
     {
     if(k==0)
     {
	 ax[i]=ax[i-1]+38;
	 ay[i]=ay[i-1];
	 if(ac[i-1]==13)
	 ac[i]=7;
	 else
	 ac[i]=ac[i-1]+1;
	 if(i==4||i==16||i==38||i==62||i==84||i==96)
	 {
	     i++;
	     k=1;
	 }
     }
    else
     {
	 ax[i]=ax[i-1]-38;
	 ay[i]=ay[i-1];
	 if(ac[i-1]==7)
	 ac[i]=13;
	 else
	 ac[i]=ac[i-1]-1;
	 if(i==10||i==26||i==50||i==74||i==90)
	 {
	    i++;
	    k=0;
	 }
     }

     }


 }
  //function for keep the dise box position and color end
 //-------------------------------*---------------------------------//


void mouse()//This function is use for mouse on in game zone and click on dise box for get score.

{

		setfillstyle(1,0);
		bar(470,305,618,330);
		settextstyle(0,0,2);
		setcolor(14);
		outtextxy(473,310,"YOUR TURN");
		outtextxy(505,365,"CLICK");
		outtextxy(510,387,"HERE");

		while(1)
		{


		get_position(&x,&y);
		delay(300);



		if(left_button_pressed())
		{
		     if(x>608&&y>1&&x<638&&y<19)
		     exit(0);



		     if(x>=500&&y>=350&&x<=590&&y<=420)
		     {
			   mouse_off();
			       if(player==1)
			       {
				   counter(&p[0],4,115);
				   delay(3000);
				   setfillstyle(1,0);
				   bar(470,305,618,330);
				   if(condition!=1)
				   {
			       com: condition=0;
				   settextstyle(0,0,2);
				   setcolor(14);
				   outtextxy(473,310,"COMP TURN");
				   setfillstyle(1,6);
				   bar(500,350,590,420);
				   delay(3000);
				   counter(&p[1],1,220);
				   delay(3500);
				   if(condition==1)
				   goto com;
				   }

				   if(p[0]==100||p[1]==100)
				   player_f1();

				   condition=0;
				   setfillstyle(1,0);
				   bar(470,305,618,330);

				   settextstyle(0,0,2);
				   setcolor(14);
				   outtextxy(473,310,"YOUR TURN");

				   setfillstyle(1,6);
				   bar(500,350,590,420);
				   outtextxy(505,365,"CLICK");
				   outtextxy(510,387,"HERE");

			   }

			   mouse_on();

		     }


	}     }

}
//-------------------------------*-----------------------------------//



void dise(int x,int y,int c) //reset dise
{   int r=12,i;
    setcolor(c);
    for(i=0;i<r;i++)
    circle(x,y,i);
}


void set_boxg(int i) //function for reset the dise box start
{
char ch[5];

    setcolor(0);
    settextstyle(0,0,1);

    setfillstyle(1,ac[i]);
    strcpy(ch,'\0');
    gcvt(i,5,ch);

    bar(ax[i],ay[i],ax[i]+36,ay[i]+36);

    outtextxy(ax[i]+5,ay[i]+15,ch);

}


 //function for reset the dise box end

//-------------------------------*-----------------------------//

 void harrow(int a,int b)//for making ladder foundation
{   int i;
    setcolor(15);
    for(i=0;i<4;i++)
    {
    line(ax[b]+10+i,ay[b]+22,ax[a]+10+i,ay[a]+12);
    line(ax[b]+26+i,ay[b]+22,ax[a]+26+i,ay[a]+12);

    }
    setfillstyle(1,15);
    bar(ax[a]+20,ay[a]+3,ax[a]+35,ay[a]+5);
    bar(ax[b]+4,ay[b]+28,ax[b]+19,ay[b]+30);


}
void harrow_f2()//for making ladder midle foundation
{
    int i;
    setfillstyle(1,15);
    bar(ax[52]+12,ay[52]+13,ax[52]+27,ay[52]+15);
    bar(ax[72]+12,ay[72]+14,ax[72]+27,ay[72]+16);
    bar(ax[77]+15,ay[77]+13,ax[77]+30,ay[77]+15);
    bar(ax[89]+18,ay[89]+13,ax[89]+33,ay[89]+15);
    bar(ax[69]+15,ay[69]+13,ax[69]+30,ay[69]+15);
    bar(ax[65]+13,ay[65]+16,ax[65]+28,ay[65]+18);
    bar(ax[14]+13,ay[14]+13,ax[14]+28,ay[14]+15);
    bar(ax[20]+2,ay[20]+26,ax[20]+18,ay[20]+28);
    bar(ax[35]+14,ay[35]+16,ax[35]+29,ay[35]+18);

 //   bar(ax[b]+4,ay[b]+28,ax[b]+19,ay[b]+30);

}


void snakegr()
{
   harrow(6,16);
   harrow(8,41);
		  //all harrow function call and make Ladder
   harrow(26,29);
   harrow(50,93);
   harrow(55,80);
   harrow(59,84);
   harrow_f2();

 //  snake();
}


void snake()//use for make all snake
{


   setcolor(6);
   snake_f1(ax[71]+13,ay[71]+36,220,40,33,33,2,9);
   snake_f2(ax[78]+10,ay[78]+25,95,250,30,30,2,9);

   //snake_73//
   snake_f1(ax[48]+31,ay[48],150,294,30,30,2,9);
   snake_f2(ax[52]+15,ay[52]+13,340,63,30,30,2,9);

   //snake_32//
   snake_f1(ax[22]+13,ay[22]+13,107,260,23,23,2,6);
   snake_f2(ax[12]+28,ay[12]+14,0,50,23,23,2,6);

   //snake_82//
   snake_f1(ax[66]+10,ay[66]+18,95,242,30,30,2,9);
   snake_f2(ax[58]+17,ay[58]+28,280,60,27,27,2,9);

   //snake_63//
   snake_f1(ax[61]+30,ay[61]+15,70,236,42,42,2,9);
   snake_f2(ax[36]+30,ay[36]+9,225,70,38,38,2,9);
   snake_f1(ax[16]+18,ay[16],60,220,45,45,2,9);
   snake_f2(ax[7]+33,ay[7]+14,260,40,35,35,2,9);

   //snake_70//
   snake_f1(ax[46]+10,ay[46]+10,93,202,45,65,2,9);
   snake_f2(ax[29]+16,ay[29]+16,274,31,33,38,2,9);

   //snake_97 //
   snake_f1(ax[86],ay[86],80,255,53,53,2,9);
   snake_f2(ax[68]+5,ay[68]+26,262,70,53,53,2,9);
   snake_f1(ax[22]+30,ay[22]-7,80,235,68,68,2,9);

   //snake_60//
   snake_f2(ax[40],ay[40]+15,330,98,27,27,2,9);
   snake_f1(ax[39]+15,ay[39]+30,180,260,29,29,2,9);

   setfillstyle(9,3);//make head of snake
   sector(ax[97]+16,ay[97]+27,30,360,10,10);
   sector(ax[89]+16,ay[89]+27,30,360,10,10);
   sector(ax[70]+16,ay[70]+23,30,360,10,10);
   sector(ax[82]+16,ay[82]+27,30,360,10,10);
   sector(ax[60]+16,ay[60]+23,180,360,10,10);
   sector(ax[60]+16,ay[60]+23,0,150,10,10);
   sector(ax[63]+16,ay[63]+20,0,330,10,10);
   sector(ax[32]+16,ay[32]+27,30,360,10,10);
   sector(ax[73]+21,ay[73]+18,180,360,10,10);
   sector(ax[73]+21,ay[73]+18,0,150,10,10);




}

 int snake_f1(int x,int y,int d1,int d2,int xx,int yy,int c,int i)//for making of snake body
{
     if(i==0)
     return 0;

     else
     {
     setcolor(c);
     ellipse(x,y,d1,d2,xx,yy);
     return(snake_f1(x,y,d1,d2,xx-1,yy-1,c,i-1));
     }
}

int snake_f2(int x,int y,int d1,int d2,int xx,int yy,int c,int i)//for making of snake body
{
     if(i==0)
     return 0;

     else
     {
     setcolor(c);
     ellipse(x,y,d1,d2,xx,yy);
     return(snake_f2(x,y,d1,d2,xx+1,yy+1,c,i-1));
     }
}

void counter(int *p1,int i,int p2)
{
      int temp;
      char c[4];

			t: randomize();
			   temp=(rand() % 6)+1;
			   setcolor(15);
			   setfillstyle(1,6);
			   bar(500,350,590,420);

			   setcolor(15);
			   settextstyle(0,0,6);
			   setfillstyle(4,5);
			   strcpy(c,'\0');
			   gcvt(temp,4,c);
			   outtextxy(525,365,c);

			   if(*p1==100)
			   {
			      set_boxg(100);
			   }


			   if(*p1==0)
			   {
			       if(temp==1)
			       {
				   *p1=1;
				   dise(ax[*p1]+18,ay[*p1]+18,i);
			       }
			   }

			   else if(*p1+temp<=100)
			   {
			       set_boxg(*p1);
			       *p1+=temp;
			       if(*p1==6)
			       *p1=16;
			       else if(*p1==8)
			       *p1=41;
			       else if(*p1==26)
			       *p1=29;
			       else if(*p1==32)
			       *p1=13;
			       else if(*p1==50)
			       *p1=93;
			       else if(*p1==55)
			       *p1=80;
			       else if(*p1==59)
			       *p1=84;
			       else if(*p1==60)
			       *p1=38;
			       else if(*p1==63)
			       *p1=3;
			       else if(*p1==70)
			       *p1=25;
			       else if(*p1==73)
			       *p1=47;
			       else if(*p1==82)
			       *p1=43;
				else if(*p1==89)
			       *p1=53;
			       else if(*p1==97)
			       *p1=12;
			       snakegr();
			       if(p[0]==*p1&&p[1]!=0)
			       dise(ax[p[1]]+18,ay[p[1]]+18,1);
			       else if(p[0]!=0)
			       dise(ax[p[0]]+18,ay[p[0]]+18,4);

			       dise(ax[*p1]+18,ay[*p1]+18,i);
			   }

			   setfillstyle(1,0);
			   bar(580,p2-4,617,p2+20);
			   setcolor(15);
			   settextstyle(0,0,2);
			   setfillstyle(4,5);
			   strcpy(c,'\0');
			   gcvt(*p1,4,c);
			   outtextxy(582,p2,c);
			 //  if(temp==1)
			 //  counter(&*p,i);
			 if(temp==1&&*p!=100)
			 {
			    condition =1;
			 }

   }

void player_f1(void)
{

	   delay(1000);
	   setfillstyle(1,1);
	   bar(0,0,639,476);
	   settextstyle(0,0,4);
	   setcolor(15);

	    if (p[0]==100)
	   {
		outtextxy(ax[69]+13,ay[69],"YOU WIN");
	   }
	   else
		outtextxy(ax[73]+13,ay[73],"YOU HAVE LOST!!!");
		delay (5000);
		exit(0);
}