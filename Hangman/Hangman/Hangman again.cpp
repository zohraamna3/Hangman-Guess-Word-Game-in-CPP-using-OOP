//#include <iostream>
//#include<Windows.h>
//#include<string>
//#include <fstream>
//using namespace std;
//static int n = 0;
//void get_numberofwords()
//{
//	fstream file;
//	file.open("nofwords.txt", ios::in);
//	if (!file)
//	{
//		cout << "Error in file opening!\n";
//		file.close();
//	}
//	else
//	{
//
//		file >> n;
//		file.close();
//	}
//}
//class Hangman
//{
//	int wordlen, wrong, win, wincheck;
//
//	int t1 = 0, t2 = 0, t3 = 0, t4 = 0;
//	bool flagt1 = false, flagt2 = false, flagt3 = false, flagt4 = false;
//
//	bool masla = true; //Masla in Word
//
//	char wordarr[20];
//	bool flag1, flag2, flag3, flag4, flag5;
//	bool takeword = true;
//
//public:
//	bool you_win;
//
//
//	int count;
//	Hangman()
//	{
//		wordarr[0] = 0;
//		win = 0;
//		wincheck = 0;
//		count = 0, wordlen = 0, wrong = 1;
//		flag1 = false, flag2 = false, flag3 = false, flag4 = false, flag5 = false;
//		you_win = false;
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
//		/*	if (flag1)
//				cout << "|                |              |\n";
//			else
//				cout << "|                               |\n";*/
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
//				cout << "|                O bacha ly bhai|\n";
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
//		itterate = 1 + rand() % n;
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
//			t1 = rand() % (count - 1);
//			do {
//				t2 = rand() % (count - 1);
//			} while (t1 == t2);
//			do
//			{
//				t3 = rand() % (count - 1);
//			} while (t3 == t2 || t3 == t1);
//			t4 = rand() % (count - 1);
//			if (count < 5)
//			{
//				t1 = t2, t3 = t4;
//				win = 2;
//			}
//			//if (t1 < count && t1 != t2 && t1 != t3 && t1!=t4 &&t2!=t3)
//			else if (t4 < count && t4 != t1 && t4 != t2 && t4 != t3)
//			{
//				win = 4;
//
//			}
//			else
//			{
//				win = 3;
//			}
//			/*else if (t1 == t3&&t1==t2)
//			{
//				win = 1;
//			}
//			else if (t1 == t2)
//			{
//				win =  2;
//			}
//			else if (t1 == t3)
//			{
//				win = 2;
//			}
//			else if (t2 == t3)
//			{
//				win = 2;
//			}*/
//
//
//			takeword = false;
//		}
//		//	cout << "t1: " << t1 << " t2: " << t2 << " t3: " << t3 << " t4: " << t4 <<endl;
//		
//			if (wordarr[t1] == temp )
//			{
//				flagt1 = true;
//			}
//			if (wordarr[t2] == temp)
//			{
//				flagt2 = true;
//			}
//			if (wordarr[t3] == temp)
//			{
//				flagt3 = true;
//			}
//			if (wordarr[t4] == temp)
//			{
//				flagt4 = true;
//			}
//		
//
//		for (int i = 0; i < count; i++)
//		{
//			/*if (i == t1 || t2 == i || t3 == i)
//				cout << "_";*/
//			if (i == t1)
//			{
//				if (flagt1)
//					cout << wordarr[i];
//				else
//					cout << "_";
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
//				cout << wordarr[i];
//
//		}
//		if (masla)  //Masla
//		{
//			cout << wordarr;
//			masla = false;
//		}
//		cout << "\n---------------------------------\n";
//	}
//	void check(char temp)
//	{
//
//		if (wordarr[t1] != temp && wordarr[t2] != temp && wordarr[t3] != temp && wordarr[t4] != temp)
//		{
//			wrong++;
//			cout << "\n          Wrong Input!\n";
//			Sleep(0700);
//			Sleep(0700);
//		}
//		else
//		{
//			
//
//			cout << "\n      '"<<temp<<"'was a missing letter!\n";
//			wincheck++;
//			Sleep(0700);
//			Sleep(0700);
//		}
//
//	}
//	void validate()
//	{
//		if (flagt1 == true && flagt2 == true && flagt3 == true && flagt4 == true)
//		{
//			you_win = true;
//		}
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
//		cout << "|                               |\n";
//
//		cout << "|                O  Thanks Bro  |\n";
//		//cout << "|                O  Mout ko chu k taak sy wapas..  |\n";
//
//		cout << "|               /|\\             |\n";
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
//	char* getword()
//	{
//		return wordarr;
//	}
//};
//bool login()
//{
//	int choice = 0;
//	do {
//		cout << "Press 1 to Login as Admin\nPress 2 to Login as Player\nChoice: ";
//		if (choice != 1 && choice != 2)
//		{
//			cout << "Wrong Input Enter Your Choice Again\n";
//		}
//	} while (choice != 1 && choice != 2);
//	if (choice == 1)
//		return true;
//
//	return false;
//
//}
//void Admin()
//{
//	int choice = 0;
//	while (choice != 4)
//	{
//
//
//		do {
//			cout << "Press 1 to Display Words\nPress 2 to Remove a Word\nPress 3 to Add a Word\nPress 4 to Exit Admin Panel\nChoice: ";
//			cin >> choice;
//			if (choice != 1 && choice != 2 && choice != 3 && choice != 4)
//				cout << "Wrong Input Enter Your Choice Again\n";
//		} while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
//		switch (choice)
//		{
//		case 1:
//		{
//			fstream file;
//			char a;
//			int count = 0;
//			char wordarr[50] = { 0 };
//			cout << "\nWords:\n\n";
//			file.open("Hangman.txt", ios::in);
//			if (!file)
//			{
//				cout << "Error in file opening!\n";
//				file.close();
//			}
//			else
//			{
//				for (int i = 0; i < n; i++)
//				{
//					count = 0;
//					file.get(a);
//					while (a != '/')
//					{
//						wordarr[count] = a;
//						count++;
//						file.get(a);
//
//					}
//					wordarr[count] = 0;
//					cout << i + 1 << ". " << wordarr << endl;
//				}
//				file.close();
//			}
//			break;
//		}
//		case 2:
//		{
//			fstream file, file1;
//			char a;
//			bool flag = true;
//			char wordarr[50] = { 0 };
//			char comparr[50] = { 0 };
//			int count = 0, check = 0;
//			cin.ignore();
//			cout << "\nEnter The Word You Want to Remove: ";
//			cin.getline(comparr, 49);
//
//
//
//			file.open("Hangman.txt", ios::in);
//			file1.open("temp.txt", ios::app | ios::out);
//			if (!file && !file1)
//			{
//				cout << "Error in file opening!\n";
//				file.close();
//			}
//			else
//			{
//				for (int i = 0; i < n; i++)
//				{
//					count = 0;
//					check = 0;
//					file.get(a);
//					while (a != '/')
//					{
//						wordarr[count] = a;
//						count++;
//						file.get(a);
//
//					}
//					wordarr[count] = 0;
//					for (int i = 0; i < count; i++)
//						if (wordarr[i] == comparr[i])
//							check++;
//					if (count == check)
//					{
//						fstream file3;
//						file3.open("nofwords.txt", ios::out);
//						if (!file3)
//						{
//							cout << "Error in file opening!\n";
//							file3.close();
//						}
//						else
//						{
//							n = n - 1;
//							file3 << n;
//							file3.close();
//						}
//						cout << "Found and Deleted '" << wordarr << "'\n";
//						flag = false;
//
//					}
//					else
//					{
//						file1 << wordarr << "/";
//
//					}
//
//				}
//				file.close();
//				file1.close();
//				remove("Hangman.txt");
//				rename("temp.txt", "Hangman.txt");
//				if (flag)
//					cout << "\nNot Found!\n";
//			}
//			break;
//		}
//		case 3:
//		{
//			fstream file;
//			string addword;
//			file.open("Hangman.txt", ios::app | ios::out);
//			if (!file)
//			{
//				cout << "Error in file opening!\n";
//				file.close();
//			}
//			else
//			{
//				cout << "Enter the word you want to add: ";
//				cin >> addword;
//				file << addword << "/";
//				cout << "Word Successfully Added!\n";
//				fstream file3;
//				file3.open("nofwords.txt", ios::out);
//				if (!file3)
//				{
//					cout << "Error in file opening!\n";
//					file3.close();
//				}
//				else
//				{
//					n++;
//					file3 << n;
//					file3.close();
//				}
//				file.close();
//			}
//			break;
//
//
//
//
//		}
//		case 4:
//		{
//			return;
//		}
//
//
//		}
//	}
//}
//bool check_Admin()
//{
//	string email, pass, email1, pass1;
//	fstream file;
//
//	file.open("admin.txt", ios::in);
//	if (!file)
//	{
//		cout << "Error in file opening!\n";
//		file.close();
//	}
//	else
//	{
//		cout << "\nEnter Email: ";
//		cin >> email1;
//		cout << "Enter Pass: ";
//		cin >> pass1;
//		file >> email;
//		file >> pass;
//		if (email == email1 && pass == pass1)
//		{
//			file.close();
//
//			return true;
//		}
//		file.close();
//
//		return false;
//
//	}
//}
//
//int main()
//{
//	get_numberofwords();
//	int repeat = 1;
//	int choice = 0;
//	while (true)
//	{
//		do {
//			system("cls");
//			cout << "Press 1 to Login as Admin\nPress 2 to Play the Game as User\n\nChoice: ";
//			cin >> choice;
//			if (choice != 1 && choice != 2)
//				cout << "Wrong Input Enter Again!\n";
//		} while (choice != 1 && choice != 2);
//		if (choice == 2)
//			do {
//				Hangman H1;
//				char Take = 0;
//				H1.giveword();
//				H1.displayword(Take);
//				system("cls");
//				H1.displayword(Take);  //Masla
//				system("cls");
//
//				for (int i = 0; ;)
//				{
//					H1.display();
//					H1.displayword(Take);
//					cout << "       Guess the letter: ";
//					cin >> Take;
//					H1.check(Take);
//					H1.validate();
//					system("cls");
//					if (H1.getwrong() == 5)
//					{
//						system("cls");
//						H1.display();
//						cout << "\nGame Over!\n";
//						cout << "Correct word was '" << H1.getword() << "'\n";
//						break;
//					}
//					if (H1.you_win==true)
//					{
//						system("cls");
//						H1.displaywin();
//						cout << "\nCongratulations!\n-   You Saved the Hangman!\n";
//						break;
//					}
//				}
//				cout << "\nPress 1 to continue playing\nPress any other number to exit\nChoice: ";
//				cin >> repeat;
//			} while (repeat == 1);
//		else
//		{
//			if (check_Admin())
//				Admin();
//			else
//			{
//				cout << "\nIncorrect Email or Password!\n";
//				Sleep(0700);
//				Sleep(0700);
//			}
//		}
//	}
//	return 0;
//}