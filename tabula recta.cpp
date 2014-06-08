/*
	 By : Sahil Narula( 12BCE0416 )
		  Deepak Kumar Singh ( 12BCE0534 )
		  Program for Improved Tabula Recta.

*/
#include <windows.h>
#include <stdio.h>
#include <winuser.h>
#include <windowsx.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <time.h>
#include <fstream>
using namespace std;
void wait ( int seconds )
{
	clock_t endwait;
	endwait = clock () + seconds * CLOCKS_PER_SEC ;
	while (clock() < endwait) {}
}
main()
{
    	cout<<"\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4 Improved Tabula Recta \4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n";
	ifstream fin;
	ofstream fout;
	cout<<"Creating Tabula Recta.";
	for(int i=0;i<4; i++)
	{
		wait(1);
		cout<<".";
	}
	cout<<"\nTable file created successfully.";
	char ch;
	int chInt=65;
	int chent;
	fout.open("tabulaRecta.txt");
	   for(int i=0; i<26;i++)
	   {
				chent=chInt;
		    	
		    for(int j=0; j<26; j++)
				{
					if(chent>90)
					   chent=65;
					ch=chent;
				    fout<<ch;
				    chent++;
				}
				fout<<"\n";
				chInt++;
       }
       fout.close();
     getch();
}
