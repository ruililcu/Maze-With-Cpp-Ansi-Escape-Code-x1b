#ifndef Themazegame
#define Themazegame
#ifndef __cplusplus
#include<stdio.h>
int main()
{
	printf("Error 1000000:This Code CAN'T run in C.");
	return 0;
}
#else
#if __cplusplus<201103l
#include<bits/stdc++.h>
int main()
{
	printf("Error 1%d:This Code CAN'T run in Less than cpp11.",__cplusplus);
	return 0;
}
#else
#include<bits/stdc++.h>
#ifdef __WIN32
#include<windows.h>
#include<conio.h>
#else
#include<curses.h>
#endif
#define Curr (maze[a.first][a.second])
#define Ncurr (maze[Newa.first][Newa.second])
#define Do Beep(512,700);Sleep(50);
#define Re Beep(575,700);Sleep(50);
#define Mi Beep(645,700);Sleep(50);
#define So Beep(768,700);Sleep(50);
#define St Sleep(2000);
using namespace std;
typedef pair<int,int>pos;
string mazm;
unsigned SZ,seed,sl=1,sr=1;atomic<bool>Cptplay(1);
char maze[1010][1010],c;pos a,block,prevblock;bool f=1,asd=1; 
mt19937 randrand(0);
uniform_int_distribution<int>randmods(0,3);
pos randjump()
{
	int cmod=randmods(randrand);
	if(cmod==0)return make_pair(2,0);
	else if(cmod==1)return make_pair(-2,0);
	else if(cmod==2)return make_pair(0,-2);
	else return make_pair(0,2);
}
void Chiptune()
{
	#ifdef __WIN32
	while(Cptplay)
	{
		Mi Re Do Re Mi Mi Mi St Re Re Re St Mi So So St
		Mi Re Do Re Mi Mi Mi St Mi Re Re Mi Re Do St St
	}
	#else
	cout<<"\aError 2000001:Can't get sound.";
	#endif
}
#ifdef __WIN32
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
bool Winansi()
{
	HANDLE Ouh=GetStdHandle(STD_OUTPUT_HANDLE);
	if(Ouh==INVALID_HANDLE_VALUE)return 0;
	DWORD Dwmod=0;
	if(!GetConsoleMode(Ouh,&Dwmod))return 0;
	Dwmod|=ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(Ouh,Dwmod);
	return 1;
}
#endif
void draw(int bi,int bj)
{
	cout<<"\x1b[2J\x1b[H";
	for(int i=bi*45;i<=min(bi*45+45,(int)SZ);i++)
	{
		for(int j=bj*45;j<=min(bj*45+45,(int)SZ);j++)
		{
			if(asd)
			{
				if(i==SZ-1&&j==SZ-1)cout<<"\x1b[43m  ";
				else if(maze[i][j]=='#')cout<<"\x1b[47m  ";
				else cout<<"  ";
				cout<<"\x1b[0m";
		    }
			else
			{
				if(i==a.first&&j==a.second)cout<<'@';
				else if(i==SZ-1&&j==SZ-1)cout<<'*';
				else cout<<maze[i][j];
		    }
		}
		cout<<"\n";
	}
	cout<<"\x1b[0m";
}
int main()
{
	#ifdef __WIN32
	asd=Winansi();
	cout<<"\x1b[94mWelcome To The Maze Game(Windows Editon)!\n";
	#else
	cout<<"\x1b[33mWelcome To The Maze Game(Unix Editon)!\n";
	#endif
	if(!asd)cout<<"\nError 2000002:YOU COMPUTER CAN'T PLAY THE MAZE(JUST SHOW YOU)!\n";
	thread cpth(Chiptune);
	cout<<"\n\x1b[33mplease maxinum the window!\n\x1b[91mGet Mode(rand/seed/read-save)...";
	cin>>mazm;
	if(mazm=="seed")
	{
		cout<<"\x1b[36mWhat seed?";
		cin>>seed;
		
	}
	if(mazm=="rand")seed=time(NULL);
	if(mazm=="read-save")
	{
		cout<<"\x1b[36mWhat save?";
		cin>>seed>>sl>>sr>>mazm>>SZ;
	}
	randrand.seed(seed); 
	cout<<"\n\x1b[33mGet Size(<500)...";
	if(mazm=="rand"||mazm=="seed")cin>>SZ;
	SZ*=2;
	cout<<"\x1b[94mBuilding The Maze...\n\n";
	cout<<"\n\nUsing wasd to move.q to lower difficult.e to get save.\x1b[0m\n\n";
	cout<<"\x1b[32mInput The difficult(easy/middle/hard,expect read-save.)";
	if(mazm=="rand"||mazm=="seed")cin>>mazm;
	memset(maze,'#',sizeof(maze));
	maze[1][1]='.'; 
	a=make_pair(1,1);
	for(int i=1;i<=2e7||f;i++)
	{
		pos Da=randjump();
		pos Newa=make_pair(a.first+Da.first,a.second+Da.second);
		pos Fita=make_pair(a.first+Da.first/2,a.second+Da.second/2);
		if(Newa.first<SZ&&Newa.first>0&&Newa.second<SZ&&Newa.second>0)
		{
			a=Newa;
			if(Curr=='#')
			{
				maze[Fita.first][Fita.second]='.';
			}
			Curr='.';
		}
		f&=!(a.first==SZ-1&&a.second==SZ-1);
	}
	cout<<"\n\nBuilding Ending\nThe Maze:\n\n";
	a=make_pair(sl,sr); 
	pos Newa=make_pair(sl,sr);
	draw(sl/45,sr/45);
	while(1)
	{
	    if(!asd)continue; 
		if(mazm=="easy")cout<<"\x1b["<<(a.first%45)+1<<";"<<(a.second%45)*2+1<<"H\x1b[42m  ";
		else if(mazm=="hard")
		{
			cout<<"\x1b["<<(a.first%45)+1<<";"<<(a.second%45)*2+1<<"H\x1b[41m  ";
			Curr='#';
		}
		else cout<<"\x1b["<<(a.first%45)+1<<";"<<(a.second%45)*2+1<<"H\x1b[40m  ";
		if(!(a.first<SZ&&a.first>0&&a.second<SZ&&a.second>0&&Ncurr=='#'))a=Newa;
		if(a.first==SZ-1&&a.second==SZ-1)break;
		cout<<"\x1b["<<(a.first%45)+1<<";"<<(a.second%45)*2+1<<"H\x1b[104m  \x1b[0m";
		prevblock=block;
		block=make_pair(a.first/45,a.second/45);
		if(prevblock!=block)draw(block.first,block.second);
		#ifdef __WIN32
		c=_getch();
		#else
		c=getch();
		#endif
		Newa=a;
		if(c=='w')Newa.first--;
		if(c=='a')Newa.second--;
		if(c=='s')Newa.first++;
		if(c=='d')Newa.second++;
		if(c=='q'&&mazm=="hard")mazm="middle";
		else if(c=='q')mazm="easy";
		if(c=='e'&&mazm=="hard")cout<<"\x1b[031We Can't Save.";
		else if(c=='e')cout<<seed<<" "<<a.first<<" "<<a.second<<" "<<mazm<<" "<<SZ/2;
	}
	cout<<"\x1b[33mFreedom!";
	Cptplay=0;
	cpth.join();
	while(1);
} 
#endif
#endif
#endif

