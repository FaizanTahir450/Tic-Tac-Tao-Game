#include<iostream>
#include<graphics.h>
#pragma GCC diagnostic ignored "-Wwrite-strings"



class Game {
public:
    virtual void Loading_Game() = 0;
    virtual void Menu(int theme) = 0;
    virtual void Selection() = 0;
    virtual void Esc_Theme(int option, int theme) = 0;
    virtual void Game_Interface(int theme) = 0;
    virtual void X_O(int theme, int place) = 0;
    virtual void Check_Multi_Winner(int no) = 0;
    virtual void Multiplayer(int theme) = 0;
    virtual void Singleplayer(int theme)= 0;
    virtual void Function_Execution(int choice, int theme) = 0;
    virtual void Start()= 0;
};


class TicTacTao:public Game{
int Theme;

int board_color,  box_color;
	int p1=1,p2=1,p3=1,p4=1,p5=1,p6=1,p7=1,p8=1,p9=1;  
	int n=0;
	int a[9]={-1,-1,-1,-1,-1,-1,-1,-1,-1};
	int flag=0;

public:
void Loading_Game()
{
	readimagefile("res/game_logo.jpg",600,220,700,320);
	rectangle(610,330,690,340);
	setcolor(CYAN);
	for(int i=0;i<=76;i++)
	{
		line(612+i,332,612+i,338);
		delay(50);
	}
	cleardevice();
}

void Menu(int theme)
{
	setbkcolor(BLACK);
	cleardevice();
    if(theme==2)
    {
	readimagefile("res/logo.gif",350,20,950,130);
	readimagefile("res/menu2.jpg",535,250,765,520);
	Selector(240,1,1);
	delay(10);
	Theme=2;
	}
    else
    {
	readimagefile("res/logo.gif",350,20,950,130);
	readimagefile("res/menu1.jpg",535,250,765,520);
	Selector(240,1,1);
	delay(10);
	Theme=1;
	}
}
void Selector(int h,int key,int choice)
{
	if(key==0)
	setcolor(BLACK);
	else
	setcolor(YELLOW);
	int d=0;
    if(choice==1)
    	d=0;
	if(choice==2)
    	d=20;
	if(choice==3)
		d=50;
	if(choice==4)
		d=80;
	if(choice==5)
		d=100;
	
	settextstyle(0,HORIZ_DIR,6);
	outtextxy(450+d,h,"<");
	outtextxy(780+30-d,h,">");
}
void Selection()
{
	int choice=1;
	while(1)
	{
		if(GetAsyncKeyState(VK_F1))
		{
			Selector(240,1,1);
			Selector(300,0,2);
			Selector(360,0,3);
			Selector(420,0,4);
			Selector(480,0,5);
          // PlaySound(TEXT("res/select_option.wav"),NULL,SND_SYNC);
            choice=1;
		}
		else if(GetAsyncKeyState(VK_F2))
		{
			Selector(240,0,1);
			Selector(300,1,2);
			Selector(360,0,3);
			Selector(420,0,4);
			Selector(480,0,5);
           // PlaySound(TEXT("res/select_option.wav"),NULL,SND_SYNC);
            choice=2;
		}
		else if(GetAsyncKeyState(VK_F3))
		{
			Selector(240,0,1);
			Selector(300,0,2);
			Selector(360,1,3);
			Selector(420,0,4);
			Selector(480,0,5);
           // PlaySound(TEXT("res/select_option.wav"),NULL,SND_SYNC);
            choice=3;
		}
		else if(GetAsyncKeyState(VK_F4))
		{
			Selector(240,0,1);
			Selector(300,0,2);
			Selector(360,0,3);
			Selector(420,1,4);
			Selector(480,0,5);
           // PlaySound(TEXT("res/select_option.wav"),NULL,SND_SYNC);
            choice=4;
		}
		else if(GetAsyncKeyState(VK_F5))
		{
			Selector(240,0,1);
			Selector(300,0,2);
			Selector(360,0,3);
			Selector(420,0,4);
			Selector(480,1,5);
           //PlaySound(TEXT("res/select_option.wav"),NULL,SND_SYNC);
		   choice=5;	
		}
		else if(GetAsyncKeyState(VK_F6))
		{
            Menu(1);
           // PlaySound(TEXT("res/select_option.wav"),NULL,SND_SYNC);
		}
		else if(GetAsyncKeyState(VK_F7))
		{
			Menu(2);
           // PlaySound(TEXT("res/select_option.wav"),NULL,SND_SYNC);
		}
        else if(GetAsyncKeyState(VK_RETURN))
        {   
         Function_Execution(choice,Theme);
		}
		delay(10);
	}
}
// Escape 
void Esc_Theme(int option,int theme)
{
	while(1)
	{
        if(GetAsyncKeyState(VK_ESCAPE))
        {
         Menu(theme);
        // PlaySound(TEXT("res/select_option.wav"),NULL,SND_SYNC);
	   	 Selection();
		}
		if(GetAsyncKeyState(VK_F6))
		{
			Function_Execution(option,1);
          //  PlaySound(TEXT("res/select_option.wav"),NULL,SND_SYNC);
		}
		if(GetAsyncKeyState(VK_F7))
		{
			Function_Execution(option,2);
          //  PlaySound(TEXT("res/select_option.wav"),NULL,SND_SYNC);
		}		
	}
}

void Game_Interface(int Theme)
{    
  if(Theme==1)
    {
    	board_color=10;          // green
    	box_color=10;	
	}
	else
    {
    	board_color=9;           // blue
    	box_color=9;   	
    }
    setcolor(board_color);
    for(int i=0;i<5;i++)
    {
    		// vertical
    	line(200+148+i,75,200+148+i,525);
    	line(200+298+i,75,200+298+i,525);
    	//horizontal
    	line(250,223+i,625,223+i);
    	line(250,373+i,625,373+i);	
	}
	setcolor(box_color);
	for(int i=0;i<5;i++)
	{
	rectangle(750+i,25+i,975-i,575-i);
	}
}

void X_O(int Theme,int place)
{   
	int l,t,r,b;
	char ch;
    if(Theme==1)
    {
      if(a[place-1]==-1)
      {
      if(n%2==0)
      {
      readimagefile("res/player21.jpg",780,150,900+35,170);     	
	  }
	  else
	  {
       readimagefile("res/player11.jpg",780,150,900+35,170);	  	
	  }
	  }
	}
  if(Theme==2)
	{
	if(a[place-1]==-1)
	{
      if(n%2==0)
      {
       readimagefile("res/player22.jpg",780,150,900+35,170);      	
	  }
	  else
	  {
     readimagefile("res/player12.jpg",780,150,900+35,170);	  	
	  }
	}   
	}
	if(place==1 && p1==1)
	{
		l= 230 ; t= 100 ;r=330  ;b=200   ;
		p1++;
		n++;
	}
	else if(place==2 && p2==1)
	{
		l=380 ; t=100  ;r=480  ;b=200   ;	
		p2++;
		n++;	
	}
	else if(place==3 && p3==1)
	{
		l= 530 ; t=100  ;r=630  ;b=200   ;	
		p3++;
		n++;	
	}
	else if(place==4 && p4==1)
	{
		l= 230  ; t=250 ;r=330  ;b= 350  ;	
		p4++;
		n++;	
	}
	else if(place==5 && p5==1)
	{
		l=380  ; t=250  ;r=480  ;b= 350   ;	
		p5++;
		n++;	
	}
	else if(place==6 && p6==1)
	{
		l=530  ; t=250  ;r=630  ;b=350   ;	
		p6++;
		n++;	
	}
	else if(place==7 && p7==1)
	{
		l=230  ; t=400  ;r=330  ;b=500   ;	
		p7++;
		n++;
	}
	else if(place==8 && p8==1)
	{
		l=380  ; t=400  ;r=480  ;b=500   ;
		p8++;
		n++;	
	}
	else if(place==9 && p9==1)
	{
		l=530  ; t=400  ;r=630  ;b=500   ;	
		p9++;
		n++;
	}
    if(a[place-1]==-1)
    {
    	if(n%2==0)
        ch='o';
        else
        ch='x';
	}
    
	if(Theme==1&&ch=='o')
	readimagefile("res/o1.jpg",l,t,r,b);
	else if(Theme==1&&ch=='x')
	readimagefile("res/x1.jpg",l,t,r,b);	
	else if(Theme==2&&ch=='o')
	readimagefile("res/o2.jpg",l,t,r,b);	
	else if(Theme==2&&ch=='x')
	readimagefile("res/x2.jpg",l,t,r,b);
	delay(500);	
		if(ch=='o')
    {
    a[place-1]=0;
    Check_Multi_Winner(0);
	}
   else if(ch=='x')
    {
    a[place-1]=1;
    Check_Multi_Winner(1);
	}
else if(p1>=2 &&p2>=2&&p3>=2&&p4>=2&&p5>=2&&p6>=2&&p7>=2&&p8>=2&&p9>=2){
		Menu(Theme);
		Selection();
	}
}
 
void Check_Multi_Winner(int no)
{
	if((a[0]==no &&a[1]== no )&& (a[2]==no))
    flag++;
    if((a[3]==no &&a[4]==no )&& (a[5]==no))
    flag++;  
	if((a[6]==no &&a[7]==no )&& (a[8]==no))
    flag++;    
	if((a[0]==no &&a[3]==no )&& (a[6]==no))
    flag++;    
	if((a[1]==no &&a[4]==no )&& (a[7]==no))
    flag++;    
	if((a[2]==no &&a[5]==no )&& (a[8]==no))
    flag++;    
	if((a[0]==no &&a[4]==no )&& (a[8]==no))
    flag++;   
	if((a[2]==no &&a[4]==no )&& (a[6]==no))
    flag++;    
    if(flag==1)
    {
    	if(no==0&&Theme==1){
		
    	cleardevice();
    	delay(1000);
    	readimagefile("res/winner1.jpg",550,200,750,300);
    	readimagefile("res/player21.jpg",570,330,730,400);
    }
    	if(no==0&&Theme==2){
		
    	cleardevice();
    	delay(1000);
    	readimagefile("res/winner2.jpg",550,200,750,300);	
    	readimagefile("res/player22.jpg",570,330,730,400);}
    	if(no==1&&Theme==1){
		
    	cleardevice();
         delay(1000);
    	readimagefile("res/player11.jpg",570,330,730,400);
		readimagefile("res/winner1.jpg",550,200,750,300);
    	}
    	if(no==1&&Theme==2){
		
    	cleardevice();
    	delay(1000);
    	readimagefile("res/winner2.jpg",550,200,750,300);	
    	readimagefile("res/player12.jpg",570,330,730,400);}
    	if(GetAsyncKeyState(VK_ESCAPE))
		{	
          p1=1,p2=1,p3=1,p4=1,p5=1,p6=1,p7=1,p8=1,p9=1;
          n=0;	
          flag=0;
         for(int i=0;i<9;i++)
         {
         	a[i]=-1;
		 }
	     	Menu(Theme);
           //PlaySound(TEXT("res/select_option.wav"),NULL,SND_SYNC);
		
		}
	}
}

void Multiplayer(int Theme)
{
	if(Theme==1)
    {
     readimagefile("res/turn1.jpg",810,90,900,120);
     readimagefile("res/player11.jpg",780,150,935,170);
     
	}
	else
	{
     readimagefile("res/turn2.jpg",810,90,900,120);
     readimagefile("res/player12.jpg",780,150,935,170);
     	
	}
	int place=0;
	while(1)
	{
		if(GetAsyncKeyState(0x31))
		{
			place=1;
			X_O(Theme,place);			
		}
		if(GetAsyncKeyState(0x32))
		{
	    	place=2;
			X_O(Theme,place);			
		}
		if(GetAsyncKeyState(0x33))
		{
			place=3;			
			X_O(Theme,place);			
		}
		if(GetAsyncKeyState(0x34))
		{			
			place=4;			
			X_O(Theme,place);			
		}
		if(GetAsyncKeyState(0x35))
		{			
			place=5;			
			X_O(Theme,place);			
		}
		if(GetAsyncKeyState(0x36))
		{		
			place=6;			
			X_O(Theme,place);			
		}
		if(GetAsyncKeyState(0x37))
		{
     		place=7;			
			X_O(Theme,place);			
		}
		if(GetAsyncKeyState(0x38))
		{		
		    place=8;			
			X_O(Theme,place);			
		}
		if(GetAsyncKeyState(0x39))
		{			
			place=9;			
			X_O(Theme,place);			
		}
		if(GetAsyncKeyState(VK_ESCAPE))
		{	
          p1=1,p2=1,p3=1,p4=1,p5=1,p6=1,p7=1,p8=1,p9=1;
          n=0;	
          flag=0;
         for(int i=0;i<9;i++)
         {
         	a[i]=-1;
		 }
	     	Menu(Theme);
           //PlaySound(TEXT("res/select_option.wav"),NULL,SND_SYNC);
			break;
		}
	}
}

void Singleplayer(int Theme){
	if(Theme==1)
    {
     readimagefile("res/turn1.jpg",810,90,900,120);
     readimagefile("res/player11.jpg",780,150,935,170);
    
	}
	else
	{
     readimagefile("res/turn2.jpg",810,90,900,120);
     readimagefile("res/player12.jpg",780,150,935,170);
}
	int place=0;
	int check[9]={0,0,0,0,0,0,0,0,0};
	int n=1;
	while(1)
	{
		if(GetAsyncKeyState(VK_ESCAPE))
		{	
          p1=1,p2=1,p3=1,p4=1,p5=1,p6=1,p7=1,p8=1,p9=1;
          n=0;	
          flag=0;
         for(int i=0;i<9;i++)
         {
         	a[i]=-1;
		 }
	     	Menu(Theme);
           //PlaySound(TEXT("res/select_option.wav"),NULL,SND_SYNC);
			break;
		}
		if(n%2==0){
	
		if(GetAsyncKeyState(0x31))
		{
			place=1;
			X_O(Theme,place);
			if(check[place]==0){
			check[place]++;
		n++;}			
		}
		if(GetAsyncKeyState(0x32))
		{
	    	place=2;
			X_O(Theme,place);
				if(check[place]==0){
			check[place]++;
		n++;}
			
		}
		if(GetAsyncKeyState(0x33))
		{
			place=3;			
			X_O(Theme,place);
			if(check[place]==0){
			check[place]++;
		n++;}
			
		}
		if(GetAsyncKeyState(0x34))
		{			
			place=4;			
			X_O(Theme,place);
				if(check[place]==0){
			check[place]++;
		n++;}	
		}
		if(GetAsyncKeyState(0x35))
		{			
			place=5;			
			X_O(Theme,place);
					if(check[place]==0){
			check[place]++;
		n++;}	
	}
		if(GetAsyncKeyState(0x36))
		{		
			place=6;			
			X_O(Theme,place);
				if(check[place]==0){
			check[place]++;
		n++;}	
		}
		if(GetAsyncKeyState(0x37))
		{
     		place=7;			
			X_O(Theme,place);
				if(check[place]==0){
			check[place]++;
		n++;}	
		}
		if(GetAsyncKeyState(0x38))
		{		
		    place=8;			
			X_O(Theme,place);
				if(check[place]==0){
			check[place]++;
		n++;}		
		}
		if(GetAsyncKeyState(0x39))
		{			
			place=9;			
			X_O(Theme,place);
				if(check[place]==0){
			check[place]++;
		n++;}
		}
		
		
	}
	else{
		place=rand() % 9 + 1;
		if(check[place]==0){
		check[place]++;
		X_O(Theme,place);
		n++;	
	}
	else{
		continue;
	}
	if(GetAsyncKeyState(VK_ESCAPE))
		{	
          p1=1,p2=1,p3=1,p4=1,p5=1,p6=1,p7=1,p8=1,p9=1;
          n=0;	
          flag=0;
         for(int i=0;i<9;i++)
         {
         	a[i]=-1;
		 }
	     	Menu(Theme);
           //PlaySound(TEXT("res/select_option.wav"),NULL,SND_SYNC);
			break;
		}
	}
	}
}


void Function_Execution(int choice,int Theme)
{
	if(choice==1)
	{
		cleardevice();
		Game_Interface(Theme);
		Singleplayer(Theme);
	}
	if(choice==2)
	{
		cleardevice();
		Game_Interface(Theme);
		Multiplayer(Theme);
	}
	if(choice==3)
	{
		cleardevice();
		if(Theme==1)
		{
		readimagefile("res/menu_controls1.jpg",550,20,750,50);
        readimagefile("res/menucontrols1.jpg",550,80,780,230);
		readimagefile("res/game_controls1.jpg",550,250,750,280);         
        readimagefile("res/gamecontrols1.jpg",420,300+10,880,330);
    	readimagefile("res/other_controls1.jpg",560,380,740,410);
        readimagefile("res/othercontrols1.jpg",550,440,780,590);
		}
		if(Theme==2)
		{
		readimagefile("res/menu_controls2.jpg",550,20,750,50);
        readimagefile("res/menucontrols2.jpg",550,80,780,230);
		readimagefile("res/game_controls2.jpg",550,250,750,280);         
        readimagefile("res/gamecontrols2.jpg",420,300+10,880,330);
    	readimagefile("res/other_controls2.jpg",560,380,740,410);
        readimagefile("res/othercontrols2.jpg",550,440,780,590);			
		}       
       // PlaySound(TEXT("res/select_option.wav"),NULL,SND_SYNC);
        Esc_Theme(3,Theme);		
	}
	if(choice==4)
	{   int page=0;
        //PlaySound(TEXT("res/select_option.wav"),NULL,SND_SYNC);
        cleardevice();
		for(int i=100;i<1200;i++)
		{
        setfillstyle(SOLID_FILL,BLACK);
         if(Theme==1)
         {
            readimagefile("res/title1.jpg",350,620-i,950,730-i);        
            readimagefile("res/about_b2.jpg",350,800-i,950,1320-i);
            bar(250,1320-i,850,2000-i);
		 }
		 if(Theme==2)
		{
        readimagefile("res/title2.jpg",350,620-i,950,730-i);        
        readimagefile("res/about_b2.jpg",350,800-i,950,1320-i);		
        bar(250,1320-i,850,2000-i);		
		}
        if(GetAsyncKeyState(VK_ESCAPE))
        {
        break;
		}
		if(GetAsyncKeyState(VK_F6))
		{
			Function_Execution(4,1);
           // PlaySound(TEXT("res/select_option.wav"),NULL,SND_SYNC);
		}
		if(GetAsyncKeyState(VK_F7))
		{
		Function_Execution(4,2);
           // PlaySound(TEXT("res/select_option.wav"),NULL,SND_SYNC);
		}
        page=1-page;
        delay(1);
		}
         Menu(Theme);
        // PlaySound(TEXT("res/select_option.wav"),NULL,SND_SYNC);
	   	 Selection();	
	}
	if(choice==5)
	{
		cleardevice();
        //PlaySound(TEXT("res/select_option.wav"),NULL,SND_SYNC);
          

		exit(0);
        
	}
}
void Start(){
		int height = GetSystemMetrics(SM_CYSCREEN);
    	int width = GetSystemMetrics(SM_CXSCREEN);

	initwindow(width,height,"");
	
	Loading_Game();

	Menu(1);

	Selection();

	getch();

	closegraph();
}};

int main()

{
Game *Game1;
Game1=new TicTacTao;
Game1->Start();

}
