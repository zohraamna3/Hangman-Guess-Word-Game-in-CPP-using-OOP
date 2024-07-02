#include <iostream>
#include<Windows.h>
#include<string>
#include<string.h>
#include <fstream>
using namespace std;
static int n = 0;
static int score = 0;

class A
{
public:
	string name;
	int Score = 0;
};
void get_numberofwords()
{
	fstream file;
	file.open("nofwords.txt", ios::in);
	if (!file)
	{
		cout << "Error in file opening!\n";
		file.close();
	}
	else
	{

		file >> n;
		file.close();
	}
}
void get_numberofhardwords()
{
	fstream file;
	file.open("nofhardwords.txt", ios::in);
	if (!file)
	{
		cout << "Error in file opening!\n";
		file.close();
	}
	else
	{

		file >> n;
		file.close();
	}
}
 void displayfront()
{

	cout << "\t\t\t\t\t\033[35m|    \033[33m      GUESS THE WORD   \033[35m    |\n";

	cout << "\t\t\t\t\t---------------------------------\n";
	cout << "\t\t\t\t\t|     \033[33m        HANGMAN   \033[35m        |\n";
	cout << "\t\t\t\t\t---------------------------------\033[0m\n";
	/*	if (flag1)
			cout << "|                |              |\n";
		else
			cout << "|                               |\n";*/

	cout << "\t\t\t\t\t|     I  AM                     |\n";

	cout << "\t\t\t\t\t|      THE       O              |\n";

	cout << "\t\t\t\t\t|    HANGMAN    /|\\             |\n";

	{
		cout << "\t\t\t\t\t|                |              |\n";

		cout << "\t\t\t\t\t|               / \\             |\n";
	}

	cout << "\t\t\t\t\t|                               |\n";
	cout << "\t\t\t\t\t|                               |\n";
	cout << "\t\t\t\t\t---------------------------------\n";
}
//void displayfront()
//{
//
//	cout << "|          GUESS THE WORD       |\n";
//
//	cout << "---------------------------------\n";
//	cout << "|             HANGMAN           |\n";
//	cout << "---------------------------------\n";
//	/*	if (flag1)
//			cout << "|                |              |\n";
//		else
//			cout << "|                               |\n";*/
//
//	cout << "|                               |\n";
//
//	cout << "| Arsh ki Tingri O  ka hu yar...|\n";
//
//	cout << "|               /|\\             |\n";
//
//	{
//		cout << "|                |              |\n";
//
//		cout << "|               / \\             |\n";
//	}
//
//	cout << "|                               |\n";
//	cout << "|                               |\n";
//	cout << "---------------------------------\n";
//}

void display_quote()
{
	cout << "\t\t\tIshq Junoon jab had sy barh jaye...\n";
	Sleep(0700); Sleep(0700); Sleep(0700); Sleep(0700); Sleep(0700);

	cout << "\t\t\t  Hastay hastay Ashiq suli charh jaye...";
	Sleep(0700); Sleep(0700); Sleep(0700); Sleep(0700); Sleep(0700);
	system("cls");

}
void score_update(string NAME,int SCORE)
{

	A ar[6];
	string name;
	int Score = 0;
	fstream file;
	file.open("leaderboard.txt", ios ::in);
	if (!file)
	{
		cout << "Error in file opening!\n";
		file.close();
	}
	else
	{
		string temp;
		for (int i = 0; i < 5; i++)
		{
			file >> name;
			file >> temp;
			while (temp != "/")
			{
				name += " ";
				name += temp;
				file >> temp;
			}
			file >> Score;

			ar[i].name = name;
			ar[i].Score = Score;
		}
		file.close();
	}

	/*for (int i = 0; i < 5; i++)
	{
		if (NAME == ar[i].name)
		{
			ar[i].Score = SCORE;
		}
	}*/
	
	for(int i=0;i<5;i++)
	{
		if (SCORE >= ar[i].Score)
		{
			
				//for (int j = i+1; j < 5; j++)
				for (int j = 4; j >i; j--)
				{
					ar[j].name = ar[j - 1].name;
					ar[j].Score = ar[j - 1].Score;
				}
				ar[i].name = NAME;
				ar[i].Score = SCORE;
				break;
			
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
			if (ar[j].Score > ar[j + 1].Score)
		{
			{
				A temp;
				  temp.name=ar[j + 1].name;
				  temp.Score= ar[j + 1].Score;

				  ar[j+1].name = ar[j].name;
				  ar[j+1].Score = ar[j].Score;

				  ar[j].name = temp.name;
				  ar[j].Score = temp.Score;
			}
		}
	}

	//////////////////////////////////////

	file.open("leaderboard.txt", ios::out);
	if (!file)
	{
		cout << "Error in file opening!\n";
		file.close();
	}
	else
	{
		for (int i = 4; i >=0; i--)
		{
			file << ar[i].name << " / " << ar[i].Score << endl;
		}
		file.close();
	}

}

void display_leaderboard()
{
	string name;
	fstream file;
	int Score = 0;
	A ar[5];

	file.open("leaderboard.txt", ios::in);
	if (!file)
	{
		cout << "Error in file opening!\n";
		file.close();
	}
	else
	{
		string temp;
		for (int i = 0; i < 5; i++)
		{
			file >> name;
			file >> temp;
			while (temp != "/")
			{
				name += " ";
				name += temp;
				file >> temp;
			}
			file >> Score;

			ar[i].name = name;
			ar[i].Score = Score;
		}
		file.close();
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
			if (ar[j].Score > ar[j + 1].Score)
		{
			{
				A temp;
				  temp.name=ar[j + 1].name;
				  temp.Score= ar[j + 1].Score;

				  ar[j+1].name = ar[j].name;
				  ar[j+1].Score = ar[j].Score;

				  ar[j].name = temp.name;
				  ar[j].Score = temp.Score;
			}
		}
	}

	
	cout << "\n\t\t\033[35m--------------------------------------------------------------\n\t\t";
	cout << "|\033[33m                        LEADERBOARD                         \033[35m|";
	cout << "\n\t\t--------------------------------------------------------------\033[0m\n";

	for (int i = 0,j=4; j >=0; j--,i++)
	{

		cout << "\t\t\t\t---------" << i + 1 << "---------\n";
		cout << "\t\t\t\tName: " << ar[j].name << endl;
		cout << "\t\t\t\tScore: " << ar[j].Score << endl;
	}

	/*file.open("leaderboard.txt", ios::in);
	if (!file)
	{
		cout << "Error in file opening!\n";
		file.close();
	}
	else
	{
		string temp;
		for (int i = 0; i <5;i++)
		{

			file >> name;
			file >> temp;
			while (temp != "/")
			{
				name += " ";
				name += temp;
				file >> temp;
			}
			file >> Score;
			cout << "\t\t\t\t---------" << i + 1 << "---------\n";
			cout << "\t\t\t\tName: " << name << endl;
			cout << "\t\t\t\tScore: " << Score << endl;
		}
		file.close();
	}*/
}
void loading()
{
	for (int i = 0; i < 46; i++)
	{
		cout << "\n\n\n\n\t\t\t\t\t\t\033[33mLOADING THE HANGMAN...";
		cout << "\n";
		cout << "\t\t\t\t\033[35m|-----------------------------------------------|\n\t\t\t\t|";
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		cout << "\033[33m|\033[35m";

		for (int j = 46; j > i; j--)
			cout << " ";
		cout << "|\n\t\t\t\t";

		cout << "|_______________________________________________|\033[0m";
		Sleep(0030);
		system("cls");
	}
}