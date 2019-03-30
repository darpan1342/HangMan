#include <iostream>
#include <fstream>
#include <string>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<bits/stdc++.h>
#include<time.h>
using namespace std;
int hangman();
int faults=0;
char as;
void print(string str)
{
	int len=str.length();
	len=(100-len)/2;
	for(int i=0;i<len;i++)
	{
		cout<<" ";
	}
	cout<<str<<endl;
	
}
void print(string str1,string str2)
{
	int len=str1.length()+str2.length()+3;
	len=(100-len)/2;
	for(int i=0;i<len;i++)
	{
		cout<<" ";
	}
	cout<<str1<<"   "<<str2<<endl;
	
}
void print(int c)
{
	for(int i=0;i<c;i++)
	{
		cout<<endl;
	}
}
void print(int c,int e)
{
	for(int i=0;i<c;i++)
	{
		cout<<" ";
	}
}
void print()
{
	print(49,0);
}
void program_for_1_player()
{	
    print(23);
    char up;
	string choice="which Type Of Movie Name You Want To Guess ?????";
	string choice_bolly="Press B For BOLLYWOOD";
	string choice_holly="Press H For HOLLYWOOD";
	print(choice);
	cout<<endl;
	print(choice_bolly,choice_holly);
	cout<<endl;
	print();
	cin>>up;
	system("CLS");
	if(up=='h'||up=='H')
	{		
		string line;
 		string a[10],a1[10];
  		int i=0,j=0,k=0,count=0;
  		ifstream myfile ("hollywood.txt");
  		if (myfile.is_open())
  		{
    		while ( getline (myfile,line) )
    		{	a1[k++]=line;
    			for(int i=0;i<line.length();i++)
				{	if(line[i]!='a'&& line[i]!='e'&&line[i]!='i'&&line[i]!='o'&&line[i]!='u'&&line[i]!='A'&&line[i]!='E'&&line[i]!='I'&&line[i]!='O'&&line[i]!='U'&&line[i]!=' ')
					{
						line[i]='*';
					}
				}
				a[j++]=line;
    		}
    		myfile.close();
  		}
		else
		{
			system("CLS");
			print("Unable to open file");
			return;
		}
		int n=0;
		while(true)
		{
			count=0;
			int index=rand()%5;
			char c;
			print(2);
			print(a[index]);
			int size=a[index].length()+1;
			int arr[size];
			string s=a[index],s1=a1[index];
			for(i=0;i<size;i++)
			{
				if(s[i]=='*')
				{
					count++;
				}
			}
			for(i=0;i<7 && count>0;i++)
			{
				bool flag=false;
				print();
				cin>>c;
				for(j=0;j<size;j++)
				{
					if(s[j]=='*' && s1[j]==c)
					{
						s[j]=c;
						count--;
						flag=true;
						system("CLS");
						print(2);
						print(s);
					}
			}
			if(!flag)
			{   faults++;
				hangman();
			}
		}
		if(count>0)
		{
			string dead="dead!!dead!! you exceeded attemps";
			print(dead);
			print();
			getch();
			cout<<endl;
		}
		else
		{
			string congo="CONGRATULATIONS";
			print(congo);
		}
		string chose="Do you want to continue playing press";
		print(chose);
		string yes_no="press 'Y' for yes or 'N' for no";
		print(yes_no);
		print();
		cin>>as;
		system("CLS");
		if(as=='Y'||as=='y')
		continue;
		else
		break;
	}
	
  
}
	else
	{	//bollywood file and hangman program
	
		string line;
 		string a[10],a1[10];
  		int i=0,j=0,k=0,count=0;
  		ifstream myfile ("bollywood.txt");
  		if (myfile.is_open())
  		{
    		while ( getline (myfile,line) )
    		{
    			a1[k++]=line;
    			for(int i=0;i<line.length();i++)
				{
					if(line[i]!='a'&& line[i]!='e'&&line[i]!='i'&&line[i]!='o'&&line[i]!='u'&&line[i]!='A'&&line[i]!='E'&&line[i]!='I'&&line[i]!='O'&&line[i]!='U'&&line[i]!=' ')
					{
						line[i]='*';
					}
				}
				a[j++]=line;
    		}
    		myfile.close();
  		}
	else
	{
		system("CLS");
		print("Unable to open file");
		return;
	}
	int n=0;
	while(true)
	{
		count=0;
		int index=rand()%5;
		char c;
		print(2);
		print(a[index]);
		int size=a[index].length()+1;
		int arr[size];
		string s=a[index],s1=a1[index];
		for(i=0;i<size;i++)
		{
			if(s[i]=='*')
			{
				count++;
			}
		}
		for(i=0;i<7 && count>0;i++)
		{
			bool flag=false;
			print();
			cin>>c;
			for(j=0;j<size;j++)
			{
				if(s[j]=='*' && s1[j]==c)
				{
					s[j]=c;
					count--;
					flag=true;
					system("cls");
					print(2);
					print(s);
				}
			}
			if(!flag)
				{	faults++;
					hangman();
				}
		}
		if(count>0)
		{
			cout<<endl;
			print("dead!!dead!! you exceeded attemps");
			print();
			getch();
			cout<<endl;
		}
		else
		{
			cout<<endl;
			print("CONGRATULATIONS");
			cout<<endl;
		}
	    string chose="Do you want to continue playing press";
		print(chose);
		string yes_no="press 'Y' for yes or 'N' for no";
		print(yes_no);
		print();
		cin>>as;
		system("CLS");
		if(as=='Y'||as=='y')
		continue;
		else
		break;
	}
	}
}
void program_for_2_player()
{	print(23);
	print("RULE 1- one player will enter name of any movie and the second player will guess name");
	cout<<endl;
	print("RULE 2-vowels in the name wil be visible and player 2 have to guess the consonants");
	cout<<endl;
	while(true){
	string p;
    string f;
	
	ofstream outfile("two_player.txt");
	if(outfile.fail())
	{
		print("error while opening file");
	}
	print("Player 1-enter the movie name");
	print(45,0);
	cin>>p;
	getline(cin,f);
	outfile<<p<<f;
	outfile.close();
	string line;
 	string a,a1;
  	int i=0,j=0,k=0,count=0;
  	ifstream myfile ("two_player.txt");
  	if (myfile.is_open())
  	{
    	while ( getline (myfile,line) )
    	{
    		a1=line;
    		for(int i=0;i<line.length();i++)
			{
				if(line[i]!='a'&& line[i]!='e'&&line[i]!='i'&&line[i]!='o'&&line[i]!='u'&&line[i]!='A'&&line[i]!='E'&&line[i]!='I'&&line[i]!='O'&&line[i]!='U'&&line[i]!=' ')
				{
					line[i]='*';
				}
			}
    	}
   		myfile.close();
  	}
	else
	{
		print("Unable to open file");
	}
	int n=0;
	count=0;
	char c;
	system("CLS");
	print(2);
	print(line);
	int size=line.length()+1;
	int arr[size];
	string s=line,s1=a1;
	for(i=0;i<size;i++)
	{
		if(s[i]=='*')
		{
			count++;
		}
	}
	for(i=0;i<7 && count>0;i++)
	{
		bool flag=false;
		print();
		cin>>c;
		for(j=0;j<size;j++)
		{
			if(s[j]=='*' && s1[j]==c)
			{
	    		s[j]=c;
				count--;
				flag=true;
				system("CLS");
				print(2);
				print(s);
			}
		}
				if(!flag)
				{	faults++;
					hangman();
				}
	}
	if(count>0)
	{
		    cout<<endl;
			print("dead!!dead!! you exceeded attemps");
			print();
			getch();
			cout<<endl;
	}
	else
	{
		cout<<endl;
		print("CONGRATULATIONS");
		cout<<endl;
	}
	string chose="Do you want to continue playing press";
		print(chose);
		string yes_no="press 'Y' for yes or 'N' for no";
		print(yes_no);
		print();
		cin>>as;
		system("CLS");
	if(as=='Y'||as=='y')
	continue;
	else
	break;
}
}
	int hangman()
	{
    	if (faults == 0)
		{
        	string st="|----------------------";
    		print(st);
    		int len=st.length();
    		len=(100-len)/2;
    		print(len,0);
        	cout << "|"<<std::endl;
        	print(len,0);
        	cout << "|" << std::endl;
        	print(len,0);
        	cout << "|" << std::endl;
        	print(len,0);
        	cout << "|" << std::endl;
    		return 1;
    	}
    	else if (faults == 1)
		{
			string st="|----------------------";
    		print(st);
    		int len=st.length();
    		len=(100-len)/2;
    		print(len,0);
    		cout << "|                      |"<<std::endl;
    		print(len,0);
        	cout << "|" << std::endl;
        	print(len,0);
    	    cout << "|" << std::endl;
    	    print(len,0);
        	cout<<  "|" << std::endl;
     	   return 1;
    	}
    	else if (faults == 2)
		{
        	string st="|----------------------";
    		print(st);
    		int len=st.length();
    		len=(100-len)/2;
    		print(len,0);
        	cout << "|                      |"<<std::endl;
        	print(len,0);
        	cout << "|                      O" << std::endl;
        	print(len,0);
        	cout << "|" << std::endl;
        	print(len,0);
        	cout << "|" << std::endl;
        	return 1;
    	}

    	else if (faults == 3)
		{
        	string st="|----------------------";
    		print(st);
    		int len=st.length();
    		len=(100-len)/2;
    		print(len,0);
        	cout << "|                      |" << std::endl;
        	print(len,0);
    		cout << "|                      O" << std::endl;
    		print(len,0);
        	cout << "|                     ~ " << std::endl;
        	print(len,0);
        	cout << "|                       " << std::endl;
	        return 1;
    	}
    	else if (faults == 4)
		{
    	    string st="|----------------------";
    		print(st);
    		int len=st.length();
    		len=(100-len)/2;
    		print(len,0);
    	    cout << "|                      |" << std::endl;
    	    print(len,0);
    	    cout << "|                      O" << std::endl;
    	    print(len,0);
    	    cout << "|                     ~ ~" << std::endl;
    	    print(len,0);
    	    cout << "|                      " << std::endl;
    	    return 1;
    	}
    	else if (faults == 5)
		{
    	    string st="|----------------------";
    		print(st);
    		int len=st.length();
    		len=(100-len)/2;
    		print(len,0);
    	    cout << "|                      |" << std::endl;
    	    print(len,0);
    		cout << "|                      O" << std::endl;
    		print(len,0);
    		cout << "|                     ~ ~" << std::endl;
			print(len,0);
			cout << "|                      |" << std::endl;
    		print(len,0);
			cout << "|                       " << std::endl;
    	    print(len,0);
			cout << "                       -" << std::endl;
    	    return 1;
    	}
    	else if (faults == 6)
		{
    	    string st="|----------------------";
    		print(st);
    		int len=st.length();
    		len=(100-len)/2;
    		print(len,0);
        	cout << "|                      |" << std::endl;
        	print(len,0);
    	    cout << "|                      O" << std::endl;
    	    print(len,0);
			cout << "|                     ~ ~" << std::endl;
    	    print(len,0);
			cout << "|                      |" << std::endl;
    	    print(len,0);
			cout << "|                     / " << std::endl;
    	    print(len,0);
			cout << "                      - -" << std::endl;
    	    return 1;
    	}
    	else if (faults == 7)
		{
    	    string st="|----------------------";
    		print(st);
    		int len=st.length();
    		len=(100-len)/2;
    		print(len,0);
			cout << "|                      |" << std::endl;
    	    print(len,0);
			cout << "|                      O" << std::endl;
    	    print(len,0);
			cout << "|                     ~ ~" << std::endl;
    	    print(len,0);
			cout << "|                      |" << std::endl;
			print(len,0);
			cout << "|                     / \ " << std::endl;
    	    print(len,0);
			cout << "                      - -" << std::endl;
    	    return 0;
    	}
	}
int main()
{		int a;
		system("color 3A");
		system("MODE CON COLS=100 LINES=50");
		print(23);
		string chose="Choose Number Of Players";
		string chose_inst="Enter 1 For One Player Game Or 2 For 2 Player Game";
		print(chose);
		cout<<endl;
		print(chose_inst);
		cout<<endl;
		print();
		cin>>a;
		system("CLS");
		if(a==1)
		{	
			program_for_1_player();
		}
		else 
		if(a==2)  
		{	
			program_for_2_player();
		}
		else
		{
			cout<<"*******we are trying to improve game to be played by more player sorry for inconvenience********";
		}

}
