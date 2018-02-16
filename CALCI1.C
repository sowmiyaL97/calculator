#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<process.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include<math.h>
#define PI  3.14159265359
#define MAX 180
int l,t,r,b,c1,c2,c3;
char f='2';
enum boolean { false,true };
int left=125,top=75,right=515,bot=105;
int centercolor=15;

void display()
{
 int p[10];
 setcolor(WHITE);
 p[0] = left;  p[1] = top;
 p[2] = right; p[3] = top;
 p[4] = right; p[5] = bot;
 p[6] = left;  p[7] = bot;
 p[8] = left;  p[9] = top;
 setfillstyle(SOLID_FILL,15);
 fillpoly(5,p);
}

void output_tex(char * ptrstring)
{
 display();
 moveto(right,top+(bot-top)/2);
 settextjustify(RIGHT_TEXT,CENTER_TEXT);
 settextstyle(0,HORIZ_DIR,USER_CHAR_SIZE);
 setusercharsize(5,8,1,1);
 setcolor(3);
 outtext(ptrstring);
 settextjustify(LEFT_TEXT,CENTER_TEXT);
}

void output_number(double d)
{
 char buffer[80];
 switch(f)
 {
  case '1': sprintf(buffer,"%16.1lf",d);break;
  case '2': sprintf(buffer,"%16.2lf",d);break;
  case '3': sprintf(buffer,"%16.3lf",d);break;
  case '4': sprintf(buffer,"%16.4lf",d);break;
  case '5': sprintf(buffer,"%16.5lf",d);break;
  case '6': sprintf(buffer,"%16.6lf",d);break;
  case '7': sprintf(buffer,"%16.7lf",d);break;
  case '8': sprintf(buffer,"%16.8lf",d);break;
 }
 output_tex(buffer);
}

void main()
{
 void standard(void);
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"");
 standard();
 closegraph();
}

void standard(void)
{
 int a,b,f,e,i,j;
 const char ESC=27;
 char dstring[80];
 char tempbuf[80];
 int numchars = 0;
 char ch;
 char oper;
 double number1,number2;
 double answer;
 double temp;
 char isfirst,chain;
 char A[80],B[80];

 isfirst = true;
 chain = false;

 screen();

 isfirst = true;
 chain = false;

 while ((ch = getch()) != ESC)
 {
  sound(1200); delay(10); nosound();
  delay(100);
  sound(300); delay(10); nosound();
  if((ch>='0' && ch <= '9') || ch =='.'||ch=='p')
  {
   switch(ch)
   {
    case '6':
	      button(295,230,345,260,7,0,15);
	      setcolor(4);
	      outtextxy(305,240,"6");
	      delay(100);
	      button(295,230,345,260,7,15,0);
	      setcolor(4);
	      outtextxy(305,240,"6");
	      break;
    case '7':
	      button(175,180,225,210,7,0,15);
	      setcolor(4);
	      outtextxy(185,190,"7");
	      delay(100);
	      button(175,180,225,210,7,15,0);
	      setcolor(4);
	      outtextxy(185,190,"7");
	      break;
    case '8':
	      button(235,180,285,210,7,0,15);
	      setcolor(4);
	      outtextxy(245,190,"8");
	      delay(100);
	      button(235,180,285,210,7,15,0);
	      setcolor(4);
	      outtextxy(245,190,"8");
	      break;
    case '9':
	      button(295,180,345,210,7,0,15);
	      setcolor(4);
	      outtextxy(305,190,"9");
	      delay(100);
	      button(295,180,345,210,7,15,0);
	      setcolor(4);
	      outtextxy(305,190,"9");
	      break;
    case '2':
	      button(235,280,285,310,7,0,15);
	      setcolor(4);
	      outtextxy(245,290,"2");
	      delay(100);
	      button(235,280,285,310,7,15,0);
	      setcolor(4);
	      outtextxy(245,290,"2");
	      break;
    case '3':
	      button(295,280,345,310,7,0,15);
	      setcolor(4);
	      outtextxy(305,290,"3");
	      delay(100);
	      button(295,280,345,310,7,15,0);
	      setcolor(4);
	      outtextxy(305,290,"3");
	      break;
    case '4':
	      button(175,230,225,260,7,0,15);
	      setcolor(4);
	      outtextxy(185,240,"4");
	      delay(100);
	      button(175,230,225,260,7,15,0);
	      setcolor(4);
	      outtextxy(185,240,"4");
	      break;
    case '5':
	      button(235,230,285,260,7,0,15);
	      setcolor(4);
	      outtextxy(245,240,"5");
	      delay(100);
	      button(235,230,285,260,7,15,0);
	      setcolor(4);
	      outtextxy(245,240,"5");
	      break;
    case '.':
	      button(295,330,345,360,7,0,15);
	      setcolor(4);
	      outtextxy(305,340,".");
	      delay(100);
	      button(295,330,345,360,7,15,0);
	      setcolor(4);
	      outtextxy(305,340,".");
	      break;
    case '1':
	      button(175,280,225,310,7,0,15);
	      setcolor(4);
	      outtextxy(185,290,"1");
	      delay(100);
	      button(175,280,225,310,7,15,0);
	      setcolor(4);
	      outtextxy(185,290,"1");
	      break;
    case '0':
	      button(175,330,225,360,7,0,15);
	      setcolor(4);
	      outtextxy(185,340,"0");
	      delay(100);
	      button(175,330,225,360,7,15,0);
	      setcolor(4);
	      outtextxy(185,340,"0");
	      break;
    case 'p':
	      button(235,330,285,360,7,0,15);
	      setcolor(4);
	      outtextxy(245,340,"pi");
	      setcolor(1);
	      outtextxy(245,345,"_");
	      delay(100);
	      button(235,330,285,360,7,15,0);
	      setcolor(4);
	      outtextxy(245,340,"pi");
	      setcolor(1);
	      outtextxy(245,345,"_");
	      break;
   }
   dstring[numchars++] = ch;
   dstring[numchars] = '\0';
   if(ch=='p')
   {
    strcpy(dstring,"3.14159265359");
   }
   if(atof(dstring) > 999999999999999999999999999999999999999999999999.99 || numchars > 48)
   {
    delay(100); sound(200); delay(300); nosound();
    dstring[--numchars] = '\0';
   }
   output_tex(dstring);
  }
  else if(ch == '/'||ch=='-' || ch == '+' || ch == '=' || ch == '*'|| ch == 's'|| ch == 'o'|| ch == 't'|| ch == 'l'|| ch == 'q'|| ch == '%'|| ch == 'x'|| ch == 'y'|| ch == 'u'|| ch == 'r'|| ch == 'n'||ch == 'm'||ch == 'e'||ch == 'h')
  {
   strcpy(tempbuf,dstring);
   numchars=0;
   dstring[numchars] = '\0';
   output_tex(dstring);
   if(isfirst)
   {
    number1 = (chain) ? answer : atof(tempbuf);
    isfirst = false;
    switch(ch)
    {
     case '/' :
	       button(355,180,405,210,7,0,15);
	       setcolor(4);
	       outtextxy(365,190,"/");
	       delay(100);
	       button(355,180,405,210,7,15,0);
	       setcolor(4);
	       outtextxy(365,190,"/");
	       oper='/';
	       break;
     case '*' :
	       button(355,230,405,260,7,0,15);
	       setcolor(4);
	       outtextxy(365,240,"*");
	       delay(100);
	       button(355,230,405,260,7,15,0);
	       setcolor(4);
	       outtextxy(365,240,"*");
	       oper='*';
	       break;
     case '-' :
	       button(355,280,405,310,7,0,15);
	       setcolor(4);
	       outtextxy(365,290,"-");
	       delay(100);
	       button(355,280,405,310,7,15,0);
	       setcolor(4);
	       outtextxy(365,290,"-");
	       oper='-';
	       break;
     case '+' :
	       button(355,330,405,360,7,0,15);
	       setcolor(4);
	       outtextxy(365,340,"+");
	       delay(100);
	       button(355,330,405,360,7,15,0);
	       setcolor(4);
	       outtextxy(365,340,"+");
	       oper='+';
	       break;
     case '=' :
	       button(415,330,465,360,7,0,15);
	       setcolor(4);
	       outtextxy(425,340,"=");
	       delay(100);
	       button(415,330,465,360,7,15,0);
	       setcolor(4);
	       outtextxy(425,340,"=");
	       break;
     case 's':
	       button(115,180,165,210,7,0,15);
	       setcolor(4);
	       outtextxy(125,190,"sin");
	       setcolor(1);
	       outtextxy(125,195,"_");
	       delay(100);
	       button(115,180,165,210,7,15,0);
	       setcolor(4);
	       outtextxy(125,190,"sin");
	       setcolor(1);
	       outtextxy(125,195,"_");
	       oper='s';
	       break;
     case 'o':
	       button(115,230,165,260,7,0,15);
	       setcolor(4);
	       outtextxy(125,240,"cos");
	       setcolor(1);
	       outtextxy(133,245,"_");
	       delay(100);
	       button(115,230,165,260,7,15,0);
	       setcolor(4);
	       outtextxy(125,240,"cos");
	       setcolor(1);
	       outtextxy(133,245,"_");
	       oper='o';
	       break;
     case 't':
	       button(115,280,165,310,7,0,15);
	       setcolor(4);
	       outtextxy(125,290,"tan");
	       setcolor(1);
	       outtextxy(125,295,"_");
	       delay(100);
	       button(115,280,165,310,7,15,0);
	       setcolor(4);
	       outtextxy(125,290,"tan");
	       setcolor(1);
	       outtextxy(125,295,"_");
	       oper='t';
	       break;
     case 'q':
	       button(415,180,465,210,7,0,15);
	       setcolor(4);
	       outtextxy(425,190,"sqrt");
	       setcolor(1);
	       outtextxy(433,195,"_");
	       delay(100);
	       button(415,180,465,210,7,15,0);
	       setcolor(4);
	       outtextxy(425,190,"sqrt");
	       setcolor(1);
	       outtextxy(433,195,"_");
	       oper='q';
	       break;
     case '%':
	       button(415,230,465,260,7,0,15);
	       setcolor(4);
	       outtextxy(425,240,"%");
	       delay(100);
	       button(415,230,465,260,7,15,0);
	       setcolor(4);
	       outtextxy(425,240,"%");
	       oper='%';
	       break;
     case 'x':
	       button(415,280,465,310,7,0,15);
	       setcolor(4);
	       outtextxy(425,290,"1/x");
	       setcolor(1);
	       outtextxy(440,295,"_");
	       delay(100);
	       button(415,280,465,310,7,0,15);
	       setcolor(4);
	       outtextxy(425,290,"1/x");
	       setcolor(1);
	       outtextxy(440,295,"_");
	       oper='x';
	       break;
     case 'l':
	       button(475,180,525,210,7,0,15);
	       setcolor(4);
	       outtextxy(485,190,"log");
	       setcolor(1);
	       outtextxy(485,195,"_");
	       delay(100);
	       button(475,180,525,210,7,15,0);
	       setcolor(4);
	       outtextxy(485,190,"log");
	       setcolor(1);
	       outtextxy(485,195,"_");
	       oper='l';
	       break;
     case 'y':
	       button(475,230,525,260,7,0,15);
	       setcolor(4);
	       outtextxy(485,240,"x^y");
	       setcolor(1);
	       outtextxy(500,245,"_");
	       delay(100);
	       button(475,230,525,260,7,15,0);
	       setcolor(4);
	       outtextxy(485,240,"x^y");
	       setcolor(1);
	       outtextxy(500,245,"_");
	       oper='y';
	       break;
     case 'u':
	       button(475,280,525,310,7,0,15);
	       setcolor(4);
	       outtextxy(485,290,"x^3");
	       setcolor(1);
	       outtextxy(485,300,"(u)");
	       delay(100);
	       button(475,280,525,310,7,15,0);
	       setcolor(4);
	       outtextxy(485,290,"x^3");
	       setcolor(1);
	       outtextxy(485,300,"(u)");
	       oper='u';
	       break;
     case 'r':
	       button(475,330,525,360,7,0,15);
	       setcolor(4);
	       outtextxy(485,340,"x^2");
	       setcolor(1);
	       outtextxy(485,350,"(r)");
	       delay(100);
	       button(475,330,525,360,7,15,0);
	       setcolor(4);
	       outtextxy(485,340,"x^2");
	       setcolor(1);
	       outtextxy(485,350,"(r)");
	       oper='r';
	       break;
     case 'n':
	       button(115,330,165,360,7,0,15);
	       setcolor(4);
	       outtextxy(125,340,"n!");
	       setcolor(1);
	       outtextxy(125,345,"_");
	       delay(100);
	       button(115,330,165,360,7,15,0);
	       setcolor(4);
	       outtextxy(125,340,"n!");
	       setcolor(1);
	       outtextxy(125,345,"_");
	       oper='n';
	       break;
     case 'm':
	       button(415,380,465,410,7,0,15);
	       setcolor(4);
	       outtextxy(425,390,"rem");
	       setcolor(1);
	       outtextxy(440,395,"_");
	       delay(100);
	       button(415,380,465,410,7,15,0);
	       setcolor(4);
	       outtextxy(425,390,"rem");
	       setcolor(1);
	       outtextxy(440,395,"_");
	       oper='m';
	       break;
     case 'e':
	       button(355,380,405,410,7,15,0);
	       setcolor(4);
	       outtextxy(365,390,"exp");
	       setcolor(1);
	       outtextxy(365,395,"_");
	       delay(100);
	       button(355,380,405,410,7,15,0);
	       setcolor(4);
	       outtextxy(365,390,"exp");
	       setcolor(1);
	       outtextxy(365,395,"_");
	       oper='e';
	       break;
     case 'h':
	       button(475,380,525,410,7,15,0);
	       setcolor(4);
	       outtextxy(485,390,"hypo");
	       setcolor(1);
	       outtextxy(485,395,"_");
	       delay(100);
	       button(475,380,525,410,7,15,0);
	       setcolor(4);
	       outtextxy(485,390,"hypo");
	       setcolor(1);
	       outtextxy(485,395,"_");
	       oper='h';
	       break;
    }
   }
   else
   {
    number2 = atof(tempbuf);
    switch(oper)
    {
     case '/' : answer = number1 / number2; break;
     case '*' : answer = number1 * number2; break;
     case '-' : answer = number1 - number2; break;
     case '+' : answer = number1 + number2; break;
     case 's' : number1=(PI/MAX)*number1;
		answer = sin(number1);break;
     case 'o' : number1=(PI/MAX)*number1;
		answer = cos(number1);break;
     case 't' : number1=(PI/MAX)*number1;
		answer = tan(number1);break;
     case 'l' : answer = log10(number1);break;
     case 'q' : answer = sqrt(number1); break;
     case 'y' :
		answer=1;
		for(e=0;e<number2;e++)
		{
		 answer = answer * number1;
		}
		break;
     case 'u' : answer = number1 * number1 * number1; break;
     case 'r' : answer = number1 * number1; break;
     case 'x' : answer = 1/number1 ;break;
     case '%' : answer = answer * 100; break;
     case 'n' : answer = fact(number1);break;
     case 'm' : answer = fmod(number1,number2);break;
     case 'e' : answer = exp(number1);break;
     case 'h' : answer = hypot(number1,number2);break;
    }
    if(answer > 999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999.99)
    {
     output_tex("Overflow");
    }
    else
    {
     output_number(answer);
     number1 = answer;
     ltoa(answer,dstring,10);
     isfirst = true;
     chain = true;
    }
   }
  }
  else if( ch == 'C' || ch == 'c')
  {
   button(415,130,525,160,7,0,15);
   setcolor(4);
   outtextxy(470,140,"c");
   setcolor(1);
   outtextxy(470,145,"_");
   delay(100);
   button(415,130,525,160,7,15,0);
   setcolor(4);
   outtextxy(470,140,"c");
   setcolor(1);
   outtextxy(470,145,"_");
   isfirst = true;
   chain = false;
   numchars = 0;
   dstring[numchars] = '\0';
   output_number(0);
  }
  else if( ch == 'b')
  {
   button(115,130,225,160,7,0,15);
   setcolor(4);
   outtextxy(135,140,"backspace");
   setcolor(1);
   outtextxy(135,145,"_");
   delay(100);
   button(115,130,225,160,7,15,0);
   setcolor(4);
   outtextxy(135,140,"backspace");
   setcolor(1);
   outtextxy(135,145,"_");
   dstring[numchars-1]='\0';
   output_tex(dstring);
   numchars=numchars-1;
  }
  else if( ch == 'S')
  {
   button(235,380,285,410,7,0,15);
   setcolor(4);
   outtextxy(245,390,"S");
   setcolor(1);
   outtextxy(245,395,"_");
   delay(100);
   button(235,380,285,410,7,15,0);
   setcolor(4);
   outtextxy(245,390,"S");
   setcolor(1);
   outtextxy(245,395,"_");
   ch=getch();
   if( ch == 'A')
   {
    button(115,380,165,410,7,0,15);
    setcolor(4);
    outtextxy(125,390,"A");
    setcolor(1);
    outtextxy(125,395,"_");
    delay(100);
    button(115,380,165,410,7,15,0);
    setcolor(4);
    outtextxy(125,390,"A");
    setcolor(1);
    outtextxy(125,395,"_");
    strcpy(A,dstring);
    numchars=0;
    dstring[numchars] = '\0';
   }
   else if( ch == 'B')
   {
    button(175,380,225,410,7,0,15);
    setcolor(4);
    outtextxy(185,390,"B");
    setcolor(4);
    outtextxy(185,395,"_");
    delay(100);
    button(175,380,225,410,7,15,0);
    setcolor(4);
    outtextxy(185,390,"B");
    setcolor(4);
    outtextxy(185,395,"_");
    strcpy(B,dstring);
    numchars=0;
    dstring[numchars] = '\0';
   }
  }
  else if( ch == 'R')
  {
   button(295,380,345,410,7,0,15);
   setcolor(4);
   outtextxy(305,390,"R");
   setcolor(1);
   outtextxy(305,395,"_");
   delay(100);
   button(295,380,345,410,7,15,0);
   setcolor(4);
   outtextxy(305,390,"R");
   setcolor(1);
   outtextxy(305,395,"_");
   ch=getch();
   if( ch == 'A')
   {
    button(115,380,165,410,7,0,15);
    setcolor(4);
    outtextxy(125,390,"A");
    setcolor(1);
    outtextxy(125,395,"_");
    delay(100);
    button(115,380,165,410,7,15,0);
    setcolor(4);
    outtextxy(125,390,"A");
    setcolor(1);
    outtextxy(125,395,"_");
    output_tex(A);
   }
   else if( ch == 'B')
   {
    button(175,380,225,410,7,0,15);
    setcolor(4);
    outtextxy(185,390,"B");
    setcolor(4);
    outtextxy(185,395,"_");
    delay(100);
    button(175,380,225,410,7,15,0);
    setcolor(4);
    outtextxy(185,390,"B");
    setcolor(4);
    outtextxy(185,395,"_");
    output_tex(B);
   }
  }
  else if (ch == 'H')
  {
   button(235,130,285,160,7,0,15);
   setcolor(4);
   outtextxy(245,140,"Hyp");
   setcolor(1);
   outtextxy(245,145,"_");
   delay(100);
   button(235,130,285,160,7,15,0);
   setcolor(4);
   outtextxy(245,140,"Hyp");
   setcolor(1);
   outtextxy(245,145,"_");
   ch=getch();
   if( ch == 's'|| ch == 'o'|| ch == 't')
   {
    strcpy(tempbuf,dstring);
    numchars=0;
    dstring[numchars] = '\0';
    output_tex(dstring);
    if(isfirst)
    {
     number1 = (chain) ? answer : atof(tempbuf);
     isfirst = false;
     switch(ch)
     {
      case 's':
		button(115,180,165,210,7,0,15);
		setcolor(4);
		outtextxy(125,190,"sin");
		setcolor(1);
		outtextxy(125,195,"_");
		delay(100);
		button(115,180,165,210,7,15,0);
		setcolor(4);
		outtextxy(125,190,"sin");
		setcolor(1);
		outtextxy(125,195,"_");
		oper='s';
		break;
      case 'o':
		button(115,230,165,260,7,0,15);
		setcolor(4);
		outtextxy(125,240,"cos");
		setcolor(1);
		outtextxy(133,245,"_");
		delay(100);
		button(115,230,165,260,7,15,0);
		setcolor(4);
		outtextxy(125,240,"cos");
		setcolor(1);
		outtextxy(133,245,"_");
		oper='o';
		break;
      case 't':
		button(115,280,165,310,7,0,15);
		setcolor(4);
		outtextxy(125,290,"tan");
		setcolor(1);
		outtextxy(125,295,"_");
		delay(100);
		button(115,280,165,310,7,15,0);
		setcolor(4);
		outtextxy(125,290,"tan");
		setcolor(1);
		outtextxy(125,295,"_");
		oper='t';
		break;
//   }
//  }
     }
    }
    else
    {
//   number2 = atof(tempbuf);
     switch(oper)
     {
      case 's' : //number1=(PI/MAX)*number1;
		answer = sinh(number1);break;
      case 'o' : //number1=(PI/MAX)*number1;
//		number1=0.5;
		answer = cosh(number1);break;
      case 't' : //number1=(PI/MAX)*number1;
		answer = tanh(number1);break;
     }
     if(answer > 999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999.99)
     {
      output_tex("Overflow");
     }
     else
     {
      output_number(answer);
      number1 = answer;
      ltoa(answer,dstring,10);
      isfirst = true;
      chain = true;
//      chain = false;
     }
    }
   }
  }
  else
  {
   delay(100); sound(200); delay(300); nosound();
  }
 }
}

button(l,t,r,b,c1,c2,c3)
{
 setcolor(c1);
 setfillstyle(1,c1);
 bar(l,t,r,b);
 setcolor(c2);
 line(l,t,l,b);
 line(l,t,r,t);
 setcolor(c3);
 line(l,b,r,b);
 line(r,t,r,b);
 return 0;
}
fact(double number1)
{
 double num1;
 if(number1==1)
  return(1);
 else
  num1=number1*fact(number1-1);
 return(num1);
}
screen()
{
 setbkcolor(LIGHTBLUE);

 setfillstyle(1,7);
 bar(100,50,540,430);

 button(120,70,520,110,7,15,0);

 setfillstyle(1,15);
 bar(125,75,515,105);

 button(115,130,225,160,7,15,0);
 setcolor(4);
 outtextxy(135,140,"backspace");
 setcolor(1);
 outtextxy(135,145,"_");
 button(415,130,525,160,7,15,0);
 setcolor(4);
 outtextxy(470,140,"c");
 setcolor(1);
 outtextxy(470,145,"_");
/* button(235,130,285,160,7,15,0);
 setcolor(4);
 outtextxy(245,140,"Hyp");
 setcolor(1);
 outtextxy(245,145,"_");
 button(295,130,345,160,7,15,0);
 setcolor(4);
 outtextxy(305,140,"Sht");
 setcolor(1);
 outtextxy(305,145,"_");*/

 button(115,180,165,210,7,15,0);
 setcolor(4);
 outtextxy(125,190,"sin");
 setcolor(1);
 outtextxy(125,195,"_");
 button(115,230,165,260,7,15,0);
 setcolor(4);
 outtextxy(125,240,"cos");
 setcolor(1);
 outtextxy(133,245,"_");
 button(115,280,165,310,7,15,0);
 setcolor(4);
 outtextxy(125,290,"tan");
 setcolor(1);
 outtextxy(125,295,"_");
 button(115,330,165,360,7,15,0);
 setcolor(4);
 outtextxy(125,340,"n!");
 setcolor(1);
 outtextxy(125,345,"_");
 button(115,380,165,410,7,15,0);
 setcolor(4);
 outtextxy(125,390,"A");
 setcolor(1);
 outtextxy(125,395,"_");

 button(175,180,225,210,7,15,0);
 setcolor(4);
 outtextxy(185,190,"7");
 button(175,230,225,260,7,15,0);
 setcolor(4);
 outtextxy(185,240,"4");
 button(175,280,225,310,7,15,0);
 setcolor(4);
 outtextxy(185,290,"1");
 button(175,330,225,360,7,15,0);
 setcolor(4);
 outtextxy(185,340,"0");
 button(175,380,225,410,7,15,0);
 setcolor(4);
 outtextxy(185,390,"B");
 setcolor(4);
 outtextxy(185,395,"_");

 button(235,180,285,210,7,15,0);
 setcolor(4);
 outtextxy(245,190,"8");
 button(235,230,285,260,7,15,0);
 setcolor(4);
 outtextxy(245,240,"5");
 button(235,280,285,310,7,15,0);
 setcolor(4);
 outtextxy(245,290,"2");
 button(235,330,285,360,7,15,0);
 setcolor(4);
 outtextxy(245,340,"pi");
 setcolor(1);
 outtextxy(245,345,"_");
 button(235,380,285,410,7,15,0);
 setcolor(4);
 outtextxy(245,390,"S");
 setcolor(1);
 outtextxy(245,395,"_");

 button(295,180,345,210,7,15,0);
 setcolor(4);
 outtextxy(305,190,"9");
 button(295,230,345,260,7,15,0);
 setcolor(4);
 outtextxy(305,240,"6");
 button(295,280,345,310,7,15,0);
 setcolor(4);
 outtextxy(305,290,"3");
 button(295,330,345,360,7,15,0);
 setcolor(4);
 outtextxy(305,340,".");
 button(295,380,345,410,7,15,0);
 setcolor(4);
 outtextxy(305,390,"R");
 setcolor(1);
 outtextxy(305,395,"_");

 button(355,180,405,210,7,15,0);
 setcolor(4);
 outtextxy(365,190,"/");
 button(355,230,405,260,7,15,0);
 setcolor(4);
 outtextxy(365,240,"*");
 button(355,280,405,310,7,15,0);
 setcolor(4);
 outtextxy(365,290,"-");
 button(355,330,405,360,7,15,0);
 setcolor(4);
 outtextxy(365,340,"+");
 button(355,380,405,410,7,15,0);
 setcolor(4);
 outtextxy(365,390,"exp");
 setcolor(1);
 outtextxy(365,395,"_");

 button(415,180,465,210,7,15,0);
 setcolor(4);
 outtextxy(425,190,"sqrt");
 setcolor(1);
 outtextxy(433,195,"_");
 button(415,230,465,260,7,15,0);
 setcolor(4);
 outtextxy(425,240,"%");
 button(415,280,465,310,7,15,0);
 setcolor(4);
 outtextxy(425,290,"1/x");
 setcolor(1);
 outtextxy(440,295,"_");
 button(415,330,465,360,7,15,0);
 setcolor(4);
 outtextxy(425,340,"=");
 button(415,380,465,410,7,15,0);
 setcolor(4);
 outtextxy(425,390,"rem");
 setcolor(1);
 outtextxy(440,395,"_");

 button(475,180,525,210,7,15,0);
 setcolor(4);
 outtextxy(485,190,"log");
 setcolor(1);
 outtextxy(485,195,"_");
 button(475,230,525,260,7,15,0);
 setcolor(4);
 outtextxy(485,240,"x^y");
 setcolor(1);
 outtextxy(500,245,"_");
 button(475,280,525,310,7,15,0);
 setcolor(4);
 outtextxy(485,290,"x^3");
 setcolor(1);
 outtextxy(485,300,"(u)");
 button(475,330,525,360,7,15,0);
 setcolor(4);
 outtextxy(485,340,"x^2");
 setcolor(1);
 outtextxy(485,350,"(r)");
 button(475,380,525,410,7,15,0);
 setcolor(4);
 outtextxy(485,390,"hypo");
 setcolor(1);
 outtextxy(485,395,"_");

 return 0;
}