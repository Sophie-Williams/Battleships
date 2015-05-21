#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<graphics.h>


//TITLE DISPLAY
void intro()
{
 char ch='Y';
 int gdriver=DETECT,gmode;
 initgraph(&gdriver,&gmode," ");
 cleardevice();
 settextstyle(4,0,7);
 setcolor(LIGHTGREEN);
 outtextxy(175,140,"Battleships");
 settextstyle(1,0,2);
 setcolor(LIGHTGRAY);
 outtextxy(250,275,"Created By, ");
 setcolor(LIGHTBLUE);
 settextstyle(1,0,1);
 outtextxy(200,300,"Anupam Krishna.G");
 outtextxy(200,320,"Aravind B. Pradhyumnan");
 outtextxy(200,340,"Aadhithya.R");
 setcolor(YELLOW);
 settextstyle(4,0,1);
 outtextxy(160,450,"Do thee want to proceed?(Enter 'Y' or 'N')");

 ch=getch();
 if(ch=='N')
   exit(0);
 closegraph();
}

//DISPLAY RULES FROM TXT FILE
void rules()
{
   char ch;
   int f=0,line=0;
   ifstream fin;
   fin.open("Rules.txt",ios::in);
   fin.seekg(0);
   while(fin)
   {

      fin.get(ch);
      if(ch=='' || ch=='')
       {  textcolor(WHITE);
	  putch(ch);
       }
      else if(ch=='°' || ch=='±')
       { if(f<2)
	  textcolor(LIGHTBLUE);
	 else
	  textcolor(CYAN);
	  f++;
	  putch(ch);
       }
      else if(ch=='%')
	  break;
      else if(ch=='')
       {  textcolor(RED);
	  putch(ch);
       }
      else if(ch=='\n')
       {  gotoxy(1,++line);

       }
      else if(ch=='*' || ch=='\\')
       {  textcolor(YELLOW);
	  putch(ch);
       }
      else
       {  textcolor(GREEN);
	  putch(ch);
       }
      if(line==25)
      { getch();
	clrscr();
	line=2;
      }
    }
    getch();
}


//DECLARE THE ARENA
class carena
{ public:
   char t[14][14];
   carena();
}ch[7],a,b,c;
carena::carena()
{ int i,j;
  char u;
  for(i=0;i<14;i++)
   for(j=0;j<14;j++)
    if(i%2==0)
     t[i][j]=176;
    else
     t[i][j]=177;

 for(i=0,u='A';i<14;u++,i++)
   t[0][i]=u;

 for(i=0,u='A';i<14;u++,i++)
   t[i][0]=u;
}


//CLASS TO GET COORDINATES
class coord
{ public:
   int q,w,desn;
   char f1,f2;
   void getfchar(char Q,char W)
   {  q=Q-65;
      w=W-65;
   }
   void getfint(int Q,int W)
   {  q=Q;
      w=W;
   }
   void charcoord(char Q,char W,int d)
   {  f1=Q;
      f2=W;
      desn=d;
   }
};



void chekwin(int shot,int who)
{
  if(shot==20)
  {
    textcolor(RED +BLINK);
    if(who==1)
     cprintf("\n\n\n\n\n\n\n           !!!!    YOU WIN    !!!!");
    else if(who==7)
     cprintf("\n\n\n\n\n\n\n          !!!!!!\m/ COMPUTER WINS \m/ !!!!!!!");
    getch();
    textcolor(GREEN);
    gotoxy(13,13);
    cprintf("GAME OVER");
    getch();
    clrscr();
    exit(0);
  }
}



void disary(char G[14][14],int q=30,int w=30)
{
 int pos=3;
 for(int i=0;i<14;i++)
 { pos++;
   gotoxy(1,pos);
   cprintf("           ");
  for(int j=0;j<14;j++)
  { if(G[i][j]==30 || G[i][j]==17)
    { textcolor(LIGHTGRAY);
      putch(G[i][j]);
    }
    else if(G[i][j]==(char)173)
    { if(i==q && j==w)
       textcolor(LIGHTGREEN + BLINK);
      else
       textcolor(LIGHTGREEN);

      if(i%2==0)
       putch(176);
      else
       putch(177);
    }
    else if(G[i][j]==(char)271)
    { if(i==q && j==w)
       textcolor(LIGHTRED+BLINK);
      else
       textcolor(LIGHTRED);
      putch(G[i][j]);
    }
    else if(G[i][j]>='A' && G[i][j]<='Z')
    { textcolor(CYAN);
      putch(G[i][j]);
    }
    else
    { textcolor(LIGHTBLUE);
      putch(G[i][j]);
    }
  }
 }
 textcolor(WHITE);
}

coord cheat(char x[50])
{ coord c;
  char f1,f2;
  int desn;
  if(strlen(x)==3 && x[1]==' ')
  { f1=x[0];
    f2=x[2];
    desn=2;
  }
  else if(!strcmp(x,"argetlam"))
  {  cout<<"Cheat Activated";
     disary(a.t);
     desn=1;
     getch();
  }
  else if(!strcmp(x,"jupejones"))
  {  cout<<"Cheat Activated";
     disary(ch[random(5)+2].t);
     desn=1;
     getch();
  }
  else if(!strcmp(x,"draumr kopa"))
  {  cout<<"Cheat Activated";
     disary(ch[random(5)+2].t);
     desn=1;
     getch();
  }
  else
  {  cout<<"Cheatcode Wrong...You lose your turn";
     desn=1;
     getch();
  }
  c.charcoord(f1,f2,desn);
  return c;
}



void comship(int size)
{
 int d,i,j,chk;
 coord com;
 randomize();
 do{  chk=2;
      com.getfint(random(13)+1,random(13)+1);
      d=random(2);
      if(d==1)
      { for(i=com.q;i<com.q+size;i++)
	 if(a.t[i][com.w]=='' || a.t[i][com.w]=='')
	   chk=7;
      }
      else
      {	for(i=com.w;i<com.w+size;i++)
	 if(a.t[com.q][i]=='' || a.t[com.q][i]=='')
	   chk=7;
      }
   }while(com.q+size>13 || com.w+size>13 || chk==7);

 if(d==1)
   for(i=com.q;i<com.q+size;i++)
   { a.t[i][com.w]=30;
     ch[size].t[i][com.w]=30;
   }
 else
   for(i=com.w;i<com.w+size;i++)
   { a.t[com.q][i]=17;
     ch[size].t[com.q][i]=17;
   }
}


void plaship(int size)
{ int i,j,flag=1,chk;
  char Q,W,alg;
  coord pla;
  do
  { clrscr();
    textcolor(MAGENTA);
    gotoxy(20,3);
    cprintf("DEPLOY SHIP : SIZE ");
    putch(48+size);
    disary(c.t);

    textcolor(WHITE);
    cout<<"\n\n\t\tEnter alignment (vertical-V horizontal-H) : ";
    cin>>alg;

    chk=2;
    cout<<"\n\t\tEnter coordinates to deploy ship of size "<<size<<" : ";
    cin>>Q>>W;

    pla.getfchar(Q,W);
    if(pla.q==0 || pla.w==0)
    { cout<<"\nCoordinates inaccessable.....";
      getch();
      continue;
    }
    if(alg=='V')
      { for(i=pla.q;i<pla.q+size;i++)
	 if(c.t[i][pla.w]=='' || c.t[i][pla.w]=='')
	   chk=7;
      }
    else if(alg=='H')
      {	for(i=pla.w;i<pla.w+size;i++)
	 if(c.t[pla.q][i]=='' || c.t[pla.q][i]=='')
	   chk=7;
      }
    if(chk==7)
    { cout<<"\nShip already exists in the place....";
      getch();
      continue;
    }
    if((alg=='V' && pla.q+size>14) || (alg=='H' && pla.w+size>14))
    { cout<<"\nUnable to deploy ship...ship is out of the arena..";
      getch();
      continue;
    }

    flag++;
  }while(flag==1);
  switch(alg)
  { case 'V':  for( i=pla.q;i<pla.q+size;i++)
		 c.t[i][pla.w]=30;
	       break;


    case 'H':
	       for(i=pla.w;i<pla.w+size;i++)
		 c.t[pla.q][i]=17;
	       break;

    default :  cout<<"Improper alignment.....";
	       break;
  }
  clrscr();
  disary(c.t);


  }


void comarena(int q=30,int w=30)
{
   clrscr();
   textcolor(MAGENTA);
   gotoxy(3,0);
   cprintf("\nCOMPUTER'S ARENA :\n");
   disary(b.t,q,w);
}

void plarena(int q=30,int w=30)
{
   clrscr();
   textcolor(MAGENTA);
   gotoxy(3,0);
   cprintf("\nYOUR ARENA :\n");
   disary(c.t,q,w);
}






void main()
{
 intro();
 rules();
 clrscr();
 randomize();
 coord pla,com,Q,W;
 char u,ch,cod[30];
 int i,j,x,y,d,f3,f4,ns,flag=1,q,w,g,flag2,k,pshot=0,cshot=0;
 int e,r,t,nes;




 plaship(2);
 clrscr();
 plaship(3);
 clrscr();
 plaship(4);
 clrscr();
 plaship(5);
 clrscr();
 plaship(6);
 clrscr();


 comship(2);
 comship(3);
 comship(4);
 comship(5);
 comship(6);
 clrscr();



 textcolor(RED + BLINK);
 cprintf("\n\n\n\n\n\n\n\n\n    <<<<<<<<<<<<<<<SHIPS DEPLOYED...THE BATTLE STARTS NOW!!>>>>>>>>>>>>>>>>");
 getch();
 clrscr();

 textcolor(WHITE);


do
{
 do
 {pxtratrn:
  comarena();
  textcolor(WHITE);
  cout<<"\t\tEnter coordinates to fire!!!  ";                  //player's turn
  gets(cod);
  Q=cheat(cod);
  pla.getfchar(Q.f1,Q.f2);

  if(pla.q==0 || pla.w==0)
  { cout<<"\nCoordinates inaccessable....." ;
    goto pxtratrn;
  }
  if(Q.desn==2)
  { if(a.t[pla.q][pla.w]==17 || a.t[pla.q][pla.w]==30)
    { clrscr();
      b.t[pla.q][pla.w]=271;
      comarena(pla.q,pla.w);
      textcolor(RED + BLINK);
      cprintf("          !!  BULLS EYE  !!\a  \a  ");
      pshot++;
      getch();
      textcolor(WHITE);
      clrscr();
      chekwin(pshot,1);
    }
   else
    { clrscr();
      b.t[pla.q][pla.w]=173;
      comarena(pla.q,pla.w);
      cout<<"\t\tTarget misseD";
      getch();
      clrscr();
    }
  }
   flag++;
 }while(flag==1);



  com.getfint(random(13)+1,random(13)+1);                       //computer's turn
do
{ cxtratrn:
  if(c.t[com.q][com.w]==17 || c.t[com.q][com.w]==30)
   { clrscr();
     c.t[com.q][com.w]=271;
     plarena(com.q,com.w);
     textcolor(RED + BLINK);
     cprintf("         !! COMPUTER'S ROCKET ON TARGET !!\a  \a  \a");
     cshot++;
     getch();
     chekwin(cshot,7);
     nes=random(4);
     if(nes==1)
      com.q++;
     else if(nes==2)
      com.q--;
     else if(nes==3)
      com.w++;
     else
      com.w--;
     textcolor(WHITE);
     clrscr();
     goto cxtratrn;
   }

  else
   { clrscr();
     comarena();
     c.t[com.q][com.w]=173;
     plarena(com.q,com.w);
     cout<<"\t\tCOMPUTER missed..";
     getch();
     clrscr();
   }
 flag2=1;
}while(flag2==7);

}while(1);

}




