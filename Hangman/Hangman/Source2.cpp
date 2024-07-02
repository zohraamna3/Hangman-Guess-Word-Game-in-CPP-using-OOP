//#include<iostream>
//#include<fstream>
//using namespace std;
//int main()
//{
//	int t1 = 0, t2 = 0, t3 = 0, count = 0;
//	bool flagt1 = false, flagt2 = false, flagt3 = false;
//	char wordarr[100] ;
//	char a;
//	int itterate = 0;
//
//	srand(time(NULL));
//	itterate = 1 + rand() % 5;
//
//	fstream file;
//	file.open("Hangman.txt", ios::in);
//	if (!file)
//	{
//		cout << "Error in file opening!\n";
//		file.close();
//	}
//	else
//	{
//		for (int i = 0; i < itterate; i++)
//		{
//			count = 0;
//			file.get(a);
//			while (a != '/')
//			{
//				wordarr[count] = a;
//				count++;
//				file.get(a);
//
//			}
//			wordarr[count] = 0;
//		}
//		file.close();
//	}
//	cout << wordarr<<count;
//}