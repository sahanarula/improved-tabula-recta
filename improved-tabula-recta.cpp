/*
	 By : Sahil Narula( 12BCE0416 )
		  Project 2 : Cryptography Algorithm.

*/
#include <windows.h>
#include <winuser.h>
#include <windowsx.h>
#include <stdlib.h>
#include<conio.h>
#include<fstream>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
char tabulaRecta[26][26];
int key[26]={0};
int adMatrix[50][50]={0};
string cipher;
char pass[50];
void wait()
{
     for(int i=0; i<4; i++)
      {
			cout<<".";
			Sleep(500);
      }
}
void fetchTable()
{
	char ch;
   ifstream fin;
   fin.open("tabulaRecta.txt");
   int i, j;
	 for(i=0;i<26;i++)
	   for(j=65;j<91;j++)
           {
			   fin>>ch;
			   tabulaRecta[i][j]=ch;
           }
      cout<<"\nfetching";
     wait();
      
      cout<<"\n\nfetching done.\n\n";
    fin.close();
}


void displayTable()
{
	cout<<"\n\n\4\4\4\4\4\4\4Tabula Recta\4\4\4\4\4\4\4\n\n";
	int i, j;
      for(i=0;i<26;i++)
	   {
			for(j=65;j<91;j++)

         {
				cout<<tabulaRecta[i][j];
         }
		   cout<<"\n\n";
	   }
}

int getkey(string password)
{

	int len=0, i=0;
	len=password.length();
	for(i=0;i<len;i++)
	key[i]=0;
	//time seed random value -- start
	time_t t;
	unsigned int seedval;
	seedval = time(&t);
	srand(seedval);
	//time seed random value -- end

	for(i=0;i<len;i++)
       key[i]=(rand()%len)+1;
	 cout<<"\n";
	//for(i=0;i<len;i++)
	//	cout<<key[i];
	 cout<<"\n";
		return len;
}


void createMatrix(string password, int length)
{
	int i, j, k, sum=0;
	int check[50];
	for(i=0;i<50;i++)
	   for(j=0;j<50;j++)
		  adMatrix[i][j]=0;
	int count;
	//time seed random value -- start
	time_t t;
	unsigned int seedval;
	seedval = time(&t);
	srand(seedval);
	//time seed random value -- end
	for(i=0; i<length; i++)
        {
			for(int p=0;p<50;p++)
			   check[p]=0;
            count=key[i];

            while(count)
			{
             sos:
			     j=(rand()%length);
			     if(check[j]==1)
			 goto sos;
			     adMatrix[i][j]=1;
			     count--;
			     check[j]=1;
			}
		 }
	cout<<"\nThe adjacency matrix for encrypted message is : \n\n";
	for(i=0;i<length;i++)
	{
		cout<<"\n";
		   for(j=0;j<length;j++)
			  cout<<adMatrix[i][j]<<"\t";
	}

}

void cipherText(string password,int length)
{
	int chInt;
	int i=0, j=0;
	for(i=0;i<length;i++)
	   cipher[i]=0;
    for(i=0;i<length;i++)
      {
          chInt=password[i];
      //    cout<<chInt<<"\n";
       	  cipher[i]=tabulaRecta[key[i]][chInt];
      // 	  cout<<cipher[i]<<"\n";
	  }

	cout<<"\n\ncipher text for the encrypted message is : ";

    for(i=0;i<length;i++)
	     cout<<cipher[i];

}

void getCipherText()
{
	int len, i;
	
	 cout<<"\n\nEnter the cipher text : ";
	 cin>>cipher;
	 len=cipher.length();
//   cout<<len;
	 for(i=0;i<len;i++)
		cipher[i]=toupper(cipher[i]);
//	 cout<<cipher;
}
void getAdMatrix(int len)
{
	int i, j;
	char ch='y';
	for(i=0;i<50;i++)
	   for(j=0;j<50;j++)
		  adMatrix[i][j]=0;

	//cout<<len;
     again:
	for(i=0; i<len; i++)
		for(j=0; j<len; j++)
          {
				cout<<"\nenter matrix element <"<<i+1<<"-"<<j+1<<">";
		        cin>>adMatrix[i][j];
		  }
	 cout<<"the given matrix is:\n";
	 for(i=0; i<len; i++)
     {
		cout<<"\n";
		for(j=0; j<len; j++)
			cout<<adMatrix[i][j]<<"\t";
	  }
	  cout<<"\nProceed?<y/n>";
	  cin>>ch;
	  if(ch=='y'||ch=='Y')
		   return;
		   else
		 goto again;

}

void fetchKey(int len)
{
	int i=0,j=0;
	for(i=0;i<len;i++)
	  key[i]=0;
	  cout<<"\n";
	 for(i=0;i<len;i++)
	 {
		 for(j=0;j<len;j++)
		 {
				key[i]+=adMatrix[i][j];
		 }
//		 cout<<key[i]<<"\t";
	 }
}

void fetchPassword(int len)
{
	 int i=0, j=0, k=0, row, col, chIntCipher, chIntTable;
	 char intChar;
	 for(i=0;i<50;i++)
	 {
			pass[i]=0;
	 }
	for(i=0;i<len;i++)
    {
		for(k=0;k<10;k++)
		{
			if(key[i]==k)
			   row=k;
//			   cout<<"\n"<<k<<"\n";}
	    }
	//	for(j=0;j<len;j++)
        //{
         chIntCipher=cipher[i];
//         cout<<"\n"<<chIntCipher<<"\n";
		for(k=65;k<91;k++)
		{
			chIntTable=tabulaRecta[row][k];
			
			if(chIntCipher==chIntTable)
			   {
					col=k;
					intChar=col;
//					cout<<chIntTable;
			   }
	    }
//		 cout<<intChar;
		 pass[i]=intChar;
	}
	cout<<"\nPassword after decryption is : "<<pass;
       // }

    //}
    
}

main(){
	cout<<"\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4 Improved Tabula Recta \4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4";
	char ch='y';
	int opt, length, i;
	string password;
	  do
	   {
	    cout<<"\n\nenter from the following options:\n1.Fetch Tablula Recta\n2.Display Tabula Recta\n3.Encoding\n4.Decoding\n5.Exit\n\n";
	    cin>>opt;
	      switch(opt)
	      {
				case 1:
					fetchTable();
   		             break;


				case 2:
					displayTable();
					break;



				case 3:
					cout<<"enter password to encrypt: ";
					cin>>password;
					length=password.length();
					for(i=0;i<length;i++)
					{
						password[i]=toupper(password[i]);
					}
					length=getkey(password);
					cout<<"\nEncoding. Please wait";
					wait();
					cout<<"\n\n"<<password;
					createMatrix(password,length);
					cipherText(password,length);
//					cout<<"\nAnd the keyword for the message is: ";
//					for(i=0;i<length;i++)
//						cout<<key[i];
						cout<<"\n\n";
					break;


				case 4:
					getCipherText();
					length=cipher.length();
					getAdMatrix(length);
					fetchKey(length);
					cout<<"Decoding password. Please wait";
					wait();
					cout<<"\n\n";
					fetchPassword(length);
					break;
				case 5:
					goto exit;
					break;
		  }
		}while(ch=='y'||ch=='Y');
	exit:;
}




