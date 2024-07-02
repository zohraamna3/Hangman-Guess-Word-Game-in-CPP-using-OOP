#include <iostream>
#include<Windows.h>
#include<windows.h>
#include<conio.h>
#include<string>
#include <fstream>
#include "myfunctions.h"

using namespace std;

class Hangman_GetWord
{
protected:
	char wordarr[20];

public:
	int count, temp_count = 0;
	Hangman_GetWord()
	{
		wordarr[0] = 0;
		count = 0;
	
	}
	char* getword()
	{
		return wordarr;
	}
	void giveword()
	{
		fstream file;
		char a;
		int itterate = 0;
		srand(time(NULL));
		itterate = 1 + rand() % n;
		file.open("Hangman.txt", ios::in);
		if (!file)
		{
			cout << "Error in file opening!\n";
			file.close();
		}
		else
		{
			for (int i = 0; i < itterate; i++)
			{
				count = 0;
				file.get(a);
				while (a != '/')
				{
					wordarr[count] = a;
					count++;
					file.get(a);

				}
				wordarr[count] = 0;
			}
			file.close();
		}


	}

};
class Hangman_Display : public Hangman_GetWord
{
protected:
	bool flagt1 = false, flagt2 = false, flagt3 = false, flagt4 = false;
	bool flag1, flag2, flag3, flag4, flag5;
	int wrong;
public:
	Hangman_Display() : Hangman_GetWord()
	{
		flag1 = false, flag2 = false, flag3 = false, flag4 = false, flag5 = false;
		wrong = 1;
		
	}
	void display()
	{
		/*if (wrong == 1)
			flag1 = true;*/
		if (wrong == 2)
			flag2 = true;
		if (wrong == 3)
			flag3 = true;
		if (wrong == 4)
			flag4 = true;
		if (wrong == 5)
			flag5 = true;
		cout << "\t\t\t\t\t\033[35m|        \033[33m  GUESS THE WORD    \033[35m   |\n";

		cout << "\t\t\t\t\t---------------------------------\t\t\t\t\033[33m------------\033[35m\n";
		cout << "\t\t\t\t\t|      \033[33m       HANGMAN    \033[35m       |\t\t\t\t\033[33m| \033[0mScore: ";
		cout << score << " \033[33m|\033[0m\n";
		cout << "\t\t\t\t\t\033[35m---------------------------------\t\t\t\t\033[33m------------\033[0m\n";
		/*	if (flag1)
				cout << "|                |              |\n";
			else
				cout << "|                               |\n";*/
		if (flag2)
			cout << "\t\t\t\t\t|         \033[31m       |       \033[0m       |\n";
		else
			cout << "\t\t\t\t\t|                               |\n";
		if (flag3)
		{
			if (flag4)
			{
				if (flag5)
					//cout << "|                O Marwa dia yar|\n";
					cout << "\t\t\t\t\t|               \033[31m O\033[0m You killed me|\n";
				//	cout << "|                O Tery sy na ho paay ga..\n";
				else
					cout << "\t\t\t\t\t|\033[33m                O\033[0m Kya krrha hai|\n";
			}
			else
				cout << "\t\t\t\t\t|                O bacha ly bhai|\n";
		}
		else
			cout << "\t\t\t\t\t|                               |\n";
		if (flag4)
			cout << "\t\t\t\t\t|               /|\\             |\n";
		else
			cout << "\t\t\t\t\t|                               |\n";
		if (flag5)
		{
			cout << "\t\t\t\t\t|                |              |\n";

			cout << "\t\t\t\t\t|               / \\             |\n";
		}
		else
		{
			cout << "\t\t\t\t\t|                               |\n";
			cout << "\t\t\t\t\t|                               |\n";
		}
		cout << "\t\t\t\t\t|                               |\n";
		cout << "\t\t\t\t\t|                               |\n";
		cout << "\t\t\t\t\t---------------------------------\n";
	}

};
class Hangman : public Hangman_Display
{
	int wordlen, win, wincheck;

	int t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	//bool masla = true; //Masla in Word

	bool takeword = true;

public:
	void Reset()
	{
		/*wrong = 1;
		flag1 = false;
		flag2 = false;
		flag3 = false;
		flag4 = false;
		flag5 = false;*/

		win = 0;
		wincheck = 0;
		wordlen = 0;
		//////////////////////// constructor
		t1 = 0, t2 = 0, t3 = 0, t4 = 0;
		takeword = true;
		///////////////////////////

		
		/// /////////////////////////////// constructor
		flagt1 = false, flagt2 = false, flagt3 = false, flagt4 = false;
		////////////////////////////

		wordarr[0] = 0;
		count = 0;
		////////////////////////// constructor
		 temp_count = 0;
		//////////////////////////////////
	}
	void Reset(int)
	{
		wrong = 1;
		flag1 = false;
		flag2 = false;
		flag3 = false;
		flag4 = false;
		flag5 = false;

		win = 0;
		wincheck = 0;
		wordlen = 0;
		//////////////////////// constructor
		t1 = 0, t2 = 0, t3 = 0, t4 = 0;
		takeword = true;
		///////////////////////////


		/// /////////////////////////////// constructor
		flagt1 = false, flagt2 = false, flagt3 = false, flagt4 = false;
		////////////////////////////

		wordarr[0] = 0;
		count = 0;
		////////////////////////// constructor
		temp_count = 0;
		//////////////////////////////////
	}

	Hangman():Hangman_Display()
	{
		win = 0;
		wincheck = 0;
		 wordlen = 0, wrong = 1;
		 
	}


	void displayword(char temp)
	{
		cout << "\n\t\t\t\t\t---------------------------------\n";
		cout << "\t\t\t\t\t\t     ";

		srand(time(NULL));
		if (takeword)
		{
			t1 = rand() % (count - 1);
			do {
				t2 = rand() % (count - 1);
			} while (t1 == t2);
			do
			{
				t3 = rand() % (count - 1);

			} while (t3 == t2 || t3 == t1);

			t4 = rand() % (count - 1);
			if (count < 5)
			{
				t1 = t2, t3 = t4;
				win = 2;
			}
			//if (t1 < count && t1 != t2 && t1 != t3 && t1!=t4 &&t2!=t3)
			else if (t4 < count && t4 != t1 && t4 != t2 && t4 != t3)
			{
				win = 4;

			}
			else
			{
				win = 3;
			}
			
			/*else if (t1 == t3&&t1==t2)
			{
				win = 1;
			}
			else if (t1 == t2)
			{
				win =  2;
			}
			else if (t1 == t3)
			{
				win = 2;
			}
			else if (t2 == t3)
			{
				win = 2;
			}*/


			takeword = false;
		}
		//	cout << "t1: " << t1 << " t2: " << t2 << " t3: " << t3 << " t4: " << t4 <<endl;
		for (;;)
		{
			if (wordarr[t1] == temp && flagt1 != true)
			{
				flagt1 = true;
				if (t1 == t2)
					flagt2 = true;
				if (t1 == t3)
					flagt3 = true;
				if (t1 == t4)
					flagt4 = true;
				break;
			}
			if (wordarr[t2] == temp && flagt2 != true)
			{
				flagt2 = true;
				if (t1 == t2)
					flagt2 = true;
				if (t2 == t3)
					flagt3 = true;
				if (t2 == t4)
					flagt4 = true;
				break;
			}
			if (wordarr[t3] == temp && flagt3 != true)
			{
				flagt3 = true;
				if (t1 == t3)
					flagt3 = true;
				if (t3 == t2)
					flagt2 = true;
				if (t3 == t4)
					flagt4 = true;
				break;
			}
			if (wordarr[t4] == temp && flagt4 != true)
			{
				flagt4 = true;
				if (t1 == t4)
					flagt4 = true;
				if (t4 == t2)
					flagt2 = true;
				if (t4 == t3)
					flagt3 = true;
				break;
			}
			break;
		}
		for (int i = 0; i < count; i++)
		{
			/*if (i == t1 || t2 == i || t3 == i)
				cout << "_";*/
			if (i == t1)
			{
				if (flagt1)
					cout << wordarr[i];
				else
					cout << "\033[34m_\033[0m";


			}
			else if (i == t2)
			{
				if (flagt2)
					cout << wordarr[i];
				else
					cout << "\033[34m_\033[0m";


			}
			else if (i == t3)
			{
				if (flagt3)
					cout <<wordarr[i];
				else
					cout << "\033[34m_\033[0m";
			}
			else if (i == t4)
			{
				if (flagt4)
					cout << wordarr[i];
				else
					cout << "\033[34m_\033[0m";


			}
			else
				cout << wordarr[i];

		}
		//if (masla)  //Masla
		//{
		//	cout << wordarr;
		//	masla = false;
		//}
		cout << "\n\t\t\t\t\t---------------------------------\n";
	}
	void check(char temp)
	{

		if (wordarr[t1] != temp && wordarr[t2] != temp && wordarr[t3] != temp && wordarr[t4] != temp)
		{
			wrong++;
			cout << "\n    \t\t\t\t\t      Wrong Input!\n";
			Sleep(0700);
			Sleep(0700);
		}
		else
		{
			if (flagt1 && !flagt2 && !flagt3 && !flagt4)
				if (wordarr[t2] != temp && wordarr[t3] != temp && wordarr[t4] != temp)
				{
					wrong++;
					cout << "\n   \t\t\t\t\t       Wrong Input!\n";
					Sleep(0700);
					Sleep(0700);
					return;
				}
			if (!flagt1 && flagt2 && !flagt3 && !flagt4)
				if (wordarr[t1] != temp && wordarr[t3] != temp && wordarr[t4] != temp)
				{
					wrong++;
					cout << "\n      \t\t\t\t\t    Wrong Input!\n";
					Sleep(0700);
					Sleep(0700);
					return;
				}
			if (!flagt1 && !flagt2 && flagt3 && !flagt4)
				if (wordarr[t1] != temp && wordarr[t2] != temp && wordarr[t4] != temp)
				{
					wrong++;
					cout << "\n     \t\t\t\t\t     Wrong Input!\n";
					Sleep(0700);
					Sleep(0700);
					return;
				}
			if (!flagt1 && !flagt2 && !flagt3 && flagt4)
				if (wordarr[t1] != temp && wordarr[t3] != temp && wordarr[t2] != temp)
				{
					wrong++;
					cout << "\n     \t\t\t\t\t     Wrong Input!\n";
					Sleep(0700);
					Sleep(0700);
					return;
				}


			//

			if (flagt1 && flagt2 && !flagt3 && !flagt4)
				if (wordarr[t3] != temp && wordarr[t4] != temp)
				{
					wrong++;
					cout << "\n    \t\t\t\t\t      Wrong Input!\n";
					Sleep(0700);
					Sleep(0700);
					return;
				}
			if (flagt1 && !flagt2 && flagt3 && !flagt4)
				if (wordarr[t2] != temp && wordarr[t4] != temp)
				{
					wrong++;
					cout << "\n     \t\t\t\t\t     Wrong Input!\n";
					Sleep(0700);
					Sleep(0700);
					return;
				}
			if (flagt1 && !flagt2 && !flagt3 && flagt4)
				if (wordarr[t3] != temp && wordarr[t2] != temp)
				{
					wrong++;
					cout << "\n    \t\t\t\t\t      Wrong Input!\n";
					Sleep(0700);
					Sleep(0700);
					return;
				}
			//
			if (!flagt1 && flagt2 && flagt3 && !flagt4)
				if (wordarr[t1] != temp && wordarr[t4] != temp)
				{
					wrong++;
					cout << "\n   \t\t\t\t\t       Wrong Input!\n";
					Sleep(0700);
					Sleep(0700);
					return;
				}
			if (!flagt1 && flagt2 && !flagt3 && flagt4)
				if (wordarr[t1] != temp && wordarr[t3] != temp)
				{
					wrong++;
					cout << "\n     \t\t\t\t\t     Wrong Input!\n";
					Sleep(0700);
					Sleep(0700);
					return;
				}
			if (!flagt1 && !flagt2 && flagt3 && flagt4)
				if (wordarr[t1] != temp && wordarr[t2] != temp)
				{
					wrong++;
					cout << "\n   \t\t\t\t\t       Wrong Input!\n";
					Sleep(0700);
					Sleep(0700);
					return;
				}
			if (flagt1 && flagt2 && flagt3 && !flagt4)
				if (wordarr[t4] != temp)
				{
					wrong++;
					cout << "\n    \t\t\t\t\t      Wrong Input!\n";
					Sleep(0700);
					Sleep(0700);
					return;
				}
			if (flagt1 && flagt2 && !flagt3 && flagt4)
				if (wordarr[t3] != temp)
				{
					wrong++;
					cout << "\n     \t\t\t\t\t     Wrong Input!\n";
					Sleep(0700);
					Sleep(0700);
					return;
				}
			if (flagt1 && !flagt2 && flagt3 && flagt4)
				if (wordarr[t2] != temp)
				{
					wrong++;
					cout << "\n      \t\t\t\t\t    Wrong Input!\n";
					Sleep(0700);
					Sleep(0700);
					return;
				}
			if (!flagt1 && flagt2 && flagt3 && flagt4)
				if (wordarr[t1] != temp)
				{
					wrong++;
					cout << "\n    \t\t\t\t\t      Wrong Input!\n";
					Sleep(0700);
					Sleep(0700);
					return;
				}



			wincheck++;
			cout << "\n   \t\t\t\t\t       Correct Input!\n";
			Sleep(0700);
			Sleep(0700);
		}

	}
	int getwrong()
	{
		return wrong;
	}
	int getwin()
	{
		return win;
	}
	int getwincheck()
	{
		return wincheck;
	}
	void displaywin()
	{

		cout << "|          GUESS THE WORD       |\n";

		cout << "---------------------------------\n";
		cout << "|             HANGMAN           |\t\t\t\tScore: ";
		cout << score << "\n";
		cout << "---------------------------------\n";
		/*	if (flag1)
				cout << "|                |              |\n";
			else
				cout << "|                               |\n";*/

		cout << "|                               |\n";

		cout << "|                O  Thanks Bro  |\n";
		//cout << "|                O  Mout ko chu k taak sy wapas..  |\n";

		cout << "|               /|\\             |\n";

		{
			cout << "|                |              |\n";

			cout << "|               / \\             |\n";
		}

		cout << "|                               |\n";
		cout << "|                               |\n";
		cout << "---------------------------------\n";
	}
	

	void giveword_hard()
	{




		fstream file;
		char a;
		int itterate = 0;
		srand(time(NULL));
		itterate = 1 + rand() % 7;
		file.open("Hangman_hard.txt", ios::in);
		if (!file)
		{
			cout << "Error in file opening!\n";
			file.close();
		}
		else
		{
			for (int i = 0; i < itterate; i++)
			{
				count = 0;
				file.get(a);
				while (a != '/')
				{
					wordarr[count] = a;
					count++;
					file.get(a);

				}
				wordarr[count] = 0;
			}
			file.close();
		}


	}

};
class Admin
{
public:
	bool login()
	{
		int choice = 0;
		do {
			cout << "Press 1 to Login as Admin\nPress 2 to Login as Player\nChoice: ";
			if (choice != 1 && choice != 2)
			{
				cout << "Wrong Input Enter Your Choice Again\n";
			}
		} while (choice != 1 && choice != 2);
		if (choice == 1)
			return true;

		return false;

	}
	void admin()
	{
		int choice = 0;
		system("cls");

		cout << "\n\t\t\033[35m--------------------------------------------------------------\n\t\t";
		cout << "|\033[33m                        ADMIN PANEL                         \033[35m|";
		cout << "\n\t\t--------------------------------------------------------------\033[0m\n";


		cout << "\t\t\t\tLogged in!\n";

		while (choice != 4)
		{

			do {
				cout << "\t\t\t\tPress 1 to Display Words\n\t\t\t\tPress 2 to Remove a Word\n\t\t\t\tPress 3 to Add a Word\n\t\t\t\tPress 4 to Exit Admin Panel\n\t\t\t\tChoice: ";
				cin >> choice;
				if (choice != 1 && choice != 2 && choice != 3 && choice != 4)
					cout << "\t\t\t\tWrong Input Enter Your Choice Again\n";
			} while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
			switch (choice)
			{
			case 1:
			{
				system("cls");

				fstream file;
				char a;
				int count = 0;
				char wordarr[50] = { 0 };
				cout << "\nWords:\n\n";
				file.open("Hangman.txt", ios::in);
				if (!file)
				{
					cout << "Error in file opening!\n";
					file.close();
				}
				else
				{
					for (int i = 0; i < n; i++)
					{
						count = 0;
						file.get(a);
						while (a != '/')
						{
							wordarr[count] = a;
							count++;
							file.get(a);

						}
						wordarr[count] = 0;
						if (wordarr[0] != 0)
							cout << i + 1 << ". " << wordarr << endl;
					}
					file.close();
				}
				break;
			}
			case 2:
			{
				system("cls");

				fstream file, file1;
				char a;
				bool flag = true;
				char wordarr[50] = { 0 };
				char comparr[50] = { 0 };
				int count = 0, check = 0;
				cin.ignore();
				cout << "\nEnter The Word You Want to Remove: ";
				cin.getline(comparr, 49);



				file.open("Hangman.txt", ios::in);
				file1.open("temp.txt", ios::app | ios::out);
				if (!file && !file1)
				{
					cout << "Error in file opening!\n";
					file.close();
				}
				else
				{
					for (int i = 0; i < n; i++)
					{
						count = 0;
						check = 0;
						file.get(a);
						while (a != '/')
						{
							wordarr[count] = a;
							count++;
							file.get(a);

						}
						wordarr[count] = 0;
						for (int i = 0; i < count; i++)
							if (wordarr[i] == comparr[i])
								check++;
						if (count == check)
						{
							fstream file3;
							file3.open("nofwords.txt", ios::out);
							if (!file3)
							{
								cout << "Error in file opening!\n";
								file3.close();
							}
							else
							{
								n = n - 1;
								file3 << n;
								file3.close();
							}
							cout << "Found and Deleted '" << wordarr << "'\n";
							flag = false;

						}
						else
						{
							file1 << wordarr << "/";

						}

					}
					file.close();
					file1.close();
					remove("Hangman.txt");

					rename("temp.txt", "Hangman.txt");

					if (flag)
						cout << "\nNot Found!\n";
				}
				break;
			}
			case 3:
			{
				system("cls");
				//cout << "Press 1 to Add a Hard Word\nPress 2 to Add a Medium Word\nChoice: ";
				fstream file;
				string addword;
				file.open("Hangman.txt", ios::app | ios::out);
				if (!file)
				{
					cout << "Error in file opening!\n";
					file.close();
				}
				else
				{
					cout << "Enter the word you want to add: ";
					cin >> addword;
					file << addword << "/";
					cout << "Word Successfully Added!\n";
					fstream file3;
					file3.open("nofwords.txt", ios::out);
					if (!file3)
					{
						cout << "Error in file opening!\n";
						file3.close();
					}
					else
					{
						n++;
						file3 << n;
						file3.close();
					}
					file.close();
				}
				break;




			}
			case 4:
			{
				return;
			}


			}
		}
	}
	bool check_Admin()
	{
		string email, pass, email1, pass1;
		fstream file;

		file.open("admin.txt", ios::in);
		if (!file)
		{
			cout << "Error in file opening!\n";
			file.close();
		}
		else
		{
			cout << "\nEnter Email: ";
			cin >> email1;
			cout << "Enter Pass: ";
			cin >> pass1;
			file >> email;
			file >> pass;
			if (email == email1 && pass == pass1)
			{
				file.close();

				return true;
			}
			file.close();

			return false;

		}


	}



};

int main()
{
	char takeword[50];
//	Sleep(1700);
	Admin admin;
	Hangman H1;
	get_numberofwords();
	 //display_quote();
	loading();
	int repeat = 1;
	int choice = 0;


	while (true)
	{
	bool lost = false;
		do {
			system("cls");
			displayfront();
			cout << "\n\n\n\n\t\t\t\t\tPress 1 to Login as Admin\n\t\t\t\t\tPress 2 to Play the Game as User\n\t\t\t\t\tPress 3 to See Leaderboard\n\t\t\t\t\tPress 4 to Exit\n\n\t\t\t\t\tChoice: ";
			cin >> choice;

			while (!cin>>choice)
			{
				//cout << "Invalid Input\nEnter Again: ";
				cin.clear();
				cin.ignore(123, '\n');
			}

			if (choice != 1 && choice != 2 && choice != 3 && choice != 4)
			{
				cout << "\t\t\t\t\tWrong Input Enter Again!\n";
				Sleep(0700); Sleep(0700);
			}

		} while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
		if (choice == 4)
			return 0;
		if (choice == 3)
		{
			system("cls");
			display_leaderboard();
			cout << "\n\t\t\t\tPress any key to continue...";
			_getche();
		}

		else if (choice == 2)
		{
			string name_of_user;
			cin.ignore();
			cout << "\t\t\t\t\tEnter Your Name: ";
			getline(cin, name_of_user);
			do {
				//Hangman H1;
				char Take = 0;
				H1.giveword();
				H1.displayword(Take);
				system("cls");
				H1.displayword(Take);  //Masla
				system("cls");

				for (int i = 0; ;)
				{
					H1.display();
					H1.displayword(Take);
					//	cout << "       Guess the letter:\n=>              ";
					cout << "\t\t\t\t\t       Guess the letter: ";
					do {
						cin.getline(takeword, 49);
						if (takeword[1] != 0)
						{
							cout << "\t\t\t\t\tInvalid! Just Enter one letter at a time\n\t\t\t\t\tEnter Again: ";
						}
					} while (takeword[1] != 0);


					 Take=takeword[0];
					 //cin >> Take;
					H1.check(Take);
					system("cls");
					if (H1.getwrong() == 5)
					{
						system("cls");
						H1.display();
						cout << "\nGame Over!\n";
						cout << "Correct word was '" << H1.getword() << "'\n";
						cout << "Loading Leaderboard";
						Sleep(0700);
						Sleep(0700);

						for (int i = 0; i < 4; i++)
						{
							cout << ".";
							Sleep(0700);

						}
						Sleep(0700);
						score_update(name_of_user, score);
						display_leaderboard();
						cout << "\n\t\t\t\tPress any key to continue...";
						_getche();

						score = 0;
						lost = true;
						break;
					}
					if (H1.getwin() == H1.getwincheck())
					{
						score += 3;
						system("cls");
						H1.display();
						//H1.displaywin();
						//cout << "\nCongratulations!\n   You Saved the Hangman!\n";
						break;
					}
				}
				cout << "\n\t\t\t\t\tPress 1 to continue playing\n\t\t\t\t\tPress any other key to exit\n\t\t\t\t\tChoice: ";
				cin >> repeat;
				while (!cin >> repeat)
				{
					cout << "Invalid Input\nEnter Again: ";
					cin.clear();
					cin.ignore(123, '\n');
				}
				if (repeat == 1)
				{
					cin.ignore();
					H1.Reset();
				}
				else
				{
					H1.Reset(1);
					score_update(name_of_user, score);
					score = 0;
					cin.ignore();
					cout << "\n\t\t\t\tExited! Press any key to continue...";
					_getch();
					break;
				}
				if (lost)
					break;
			} while (repeat == 1);
		}
		
		else
		{
			if (admin.check_Admin())
			{
				admin.admin();
			}
			else
			{
				cout << "\nIncorrect Email or Password!\n";
				Sleep(0700);
				Sleep(0700);
			}
		}
	}
	return 0;
}


