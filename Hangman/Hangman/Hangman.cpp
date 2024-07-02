//#include <iostream>
//#include<Windows.h>
//#include <fstream>
//using namespace std;
//static int n = 6;
//class Hangman
//{
//	int wordlen,wrong,win,wincheck;
//
//	int t1 = 0, t2 = 0, t3 = 0,t4=0;
//	bool flagt1 = false, flagt2 = false, flagt3 = false,flagt4=false;
//
//	bool masla = true; //Masla in Word
//
//	char wordarr[20];
//	bool flag1, flag2, flag3, flag4, flag5;
//	bool takeword = true;
//
//public:
//	int count;
//	Hangman()
//	{
//		wordarr[0] = 0;
//		win = 0;
//		wincheck = 0;
//		count = 0,wordlen=0,wrong=1;
//		flag1 = false, flag2 = false, flag3 = false, flag4 = false, flag5 = false;
//
//	}
//	void display()
//	{
//		/*if (wrong == 1)
//			flag1 = true;*/
//		if (wrong == 2)
//			flag2 = true;
//		if (wrong == 3)
//			flag3 = true;
//		if (wrong == 4)
//			flag4 = true;
//		if (wrong == 5)
//			flag5 = true;
//		cout << "|          GUESS THE WORD       |\n";
//
//		cout << "---------------------------------\n";
//		cout << "|             HANGMAN           |\n";
//		cout << "---------------------------------\n";
//	/*	if (flag1)
//			cout << "|                |              |\n";
//		else
//			cout << "|                               |\n";*/
//		if (flag2)
//			cout << "|                |              |\n";
//		else
//			cout << "|                               |\n";
//		if (flag3)
//		{
//			if (flag4)
//			{
//				if (flag5)
//					cout << "|                O Marwa dia yar|\n";
//				//	cout << "|                O Tery sy na ho paay ga..\n";
//				else
//					cout << "|                O Kya krrha hai|\n";
//			}
//			else
//			cout << "|                O bacha ly bhai|\n";
//		}
//		else
//			cout << "|                               |\n";
//		if (flag4)
//			cout << "|               /|\\             |\n";
//		else
//			cout << "|                               |\n";
//		if (flag5)
//		{
//			cout << "|                |              |\n";
//
//			cout << "|               / \\             |\n";
//		}
//		else
//		{
//			cout << "|                               |\n";
//			cout << "|                               |\n";
//		}
//		cout << "|                               |\n";
//		cout << "|                               |\n";
//		cout << "---------------------------------\n";
//	}
//
//	void giveword()
//	{
//		fstream file;
//		char a;
//		int itterate = 0;
//		srand(time(NULL));
//		itterate =1+ rand() % n;
//		file.open("Hangman.txt", ios::in);
//		if (!file)
//		{
//			cout << "Error in file opening!\n";
//			file.close();
//		}
//		else
//		{
//			for (int i = 0; i < itterate; i++)
//			{
//				count = 0;
//				file.get(a);
//				while (a != '/')
//				{
//					wordarr[count] = a;
//					count++;
//					file.get(a);
//
//				}
//				wordarr[count] = 0;
//			}
//			file.close();
//		}
//		
//
//	}
//
//	void displayword(char temp)
//	{
//		cout << "\n---------------------------------\n";
//		cout << "\t     ";
//
//		srand(time(NULL));
//		if (takeword)
//		{
//		t1 = 1+rand() % (count-1);
//		do {
//			t2 = 1 + rand() % (count - 1);
//		} while (t1 == t2);
//		do
//		{ 
//		t3 = 1 + rand() % (count - 1);
//		} while (t3 == t2 || t3 == t1);
//		t4 = 1 + rand() % (count - 1);
//		if (count < 5)
//		{
//			t1 = t2, t3 = t4;
//			win = 2;
//		}
//		//if (t1 < count && t1 != t2 && t1 != t3 && t1!=t4 &&t2!=t3)
//		else if (t4 < count && t4 != t1 && t4 != t2 && t4!=t3 )
//		{
//			win=4;
//			
//		}
//		else
//		{
//			win = 3;
//		}
//		/*else if (t1 == t3&&t1==t2)
//		{
//			win = 1;
//		}
//		else if (t1 == t2)
//		{
//			win =  2;
//		}
//		else if (t1 == t3)
//		{
//			win = 2;
//		}
//		else if (t2 == t3)
//		{
//			win = 2;
//		}*/
//
//
//		takeword = false;
//		}
//	//	cout << "t1: " << t1 << " t2: " << t2 << " t3: " << t3 << " t4: " << t4 <<endl;
//		for(;;)
//		{
//			if (wordarr[t1] == temp && flagt1 != true)
//			{
//				flagt1 = true;
//				break;
//			}
//			if (wordarr[t2] == temp && flagt2 != true)
//			{
//				flagt2 = true;
//				break;
//			}			
//			if (wordarr[t3] == temp && flagt3 != true)
//			{
//				flagt3 = true;
//				break;
//			}
//			if (wordarr[t4] == temp && flagt4 != true)
//			{
//				flagt4 = true;
//				break;
//			}
//			break;
//		} 
//		for (int i = 0; i < count; i++)
//		{
//			/*if (i == t1 || t2 == i || t3 == i)
//				cout << "_";*/
//			if (i == t1)
//			{
//				if(flagt1)
//			cout<<wordarr[i];
//				else
//				cout << "_";
//
//
//			}
//			else if (i == t2)
//			{
//				if (flagt2)
//					cout << wordarr[i];
//				else
//					cout << "_";
//
//
//			}
//			else if (i == t3)
//			{
//				if (flagt3)
//					cout << wordarr[i];
//				else
//					cout << "_";
//			}
//			else if (i == t4)
//			{
//				if (flagt4)
//					cout << wordarr[i];
//				else
//					cout << "_";
//
//
//			}
//			else
//			cout<<wordarr[i];
//
//		}
//		if (masla)  //Masla
//		{
//		cout << wordarr;
//		masla = false;
//		}
//		cout << "\n---------------------------------\n";
//	}
//	void check(char temp)
//	{
//
//			if (wordarr[t1] != temp && wordarr[t2] != temp && wordarr[t3] != temp&&wordarr[t4]!=temp)
//			{
//				wrong++;
//				cout << "\n          Wrong Input!\n";
//				Sleep(0700);
//				Sleep(0700);
//		    }
//			else
//			{
//				cout << "\n          Correct Input!\n";
//				wincheck++;
//				Sleep(0700);
//				Sleep(0700);
//			}
//			
//	}
//	int getwrong()
//	{
//		return wrong;
//	}
//	int getwin()
//	{
//		return win;
//	}
//	int getwincheck()
//	{
//		return wincheck;
//	}
//	void displaywin()
//	{
//		
//		cout << "|          GUESS THE WORD       |\n";
//
//		cout << "---------------------------------\n";
//		cout << "|             HANGMAN           |\n";
//		cout << "---------------------------------\n";
//		/*	if (flag1)
//				cout << "|                |              |\n";
//			else
//				cout << "|                               |\n";*/
//		
//			cout << "|                               |\n";
//		
//				cout << "|                O  Thanks Bro  |\n";
//				//cout << "|                O  Mout ko chu k taak sy wapas..  |\n";
//		
//			cout << "|               /|\\             |\n";
//	
//		{
//			cout << "|                |              |\n";
//
//			cout << "|               / \\             |\n";
//		}
//		
//		cout << "|                               |\n";
//		cout << "|                               |\n";
//		cout << "---------------------------------\n";
//	}
//	char * getword()
//	{
//		return wordarr;
//	}
//};
//
//int main()
//{
//	int repeat = 1;
//	do {
//		Hangman H1;
//		char Take = 0;
//		H1.giveword();
//		H1.displayword(Take);
//		system("cls");
//		H1.displayword(Take);  //Masla
//		system("cls");
//
//		for (int i = 0; ;)
//		{
//			H1.display();
//			H1.displayword(Take);
//			cout << "       Guess the letter:\n=>              ";
//			cin >> Take;
//			H1.check(Take);
//			system("cls");
//			if (H1.getwrong() == 5)
//			{
//				system("cls");
//				H1.display();
//				cout << "\nGame Over!\n";
//				cout << "Correct word was '" << H1.getword() << "'\n";
//				break;
//			}
//			if (H1.getwin() == H1.getwincheck())
//			{
//				system("cls");
//				H1.displaywin();
//				cout << "\nCongratulations!\n   You Saved the Hangman!\n";
//				break;
//			}
//		}
//			cout << "\nPress 1 to continue playing: ";
//			cin >> repeat;
//	} while (repeat == 1);
//	return 0;
//}