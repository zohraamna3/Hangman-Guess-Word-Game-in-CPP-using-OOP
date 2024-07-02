//#include<iostream>
//#include<fstream>
//#include<string>
//#include<string.h>
//using namespace std;
//int main()
//{
//	fstream file, file1;
//	char a;
//	char wordarr[50];
//	char comparr[50];
//	//string comparr;
//	int count = 0;
//	int check = 0;
//
//	cout << "\nEnter The Word You Want to Remove: ";
//	cin.getline(comparr,49);
//
//
//
//	file.open("Hangman.txt", ios::in);
//	file1.open("temp.txt", ios::app | ios::out);
//	if (!file && !file1)
//	{
//		cout << "Error in file opening!\n";
//		file.close();
//		file1.close();
//	}
//	else
//	{
//		for (int i = 0; i < 6; i++)
//		{
//			count = 0;
//			check = 0;
//			file.get(a);
//			while (a != '/')
//			{
//				wordarr[count] = a;
//				count++;
//				file.get(a);
//
//			}
//			wordarr[count] = 0;
//			cout<<wordarr<<endl<<comparr<<endl;
//			for (int i = 0; i < count; i++)
//				if (wordarr[i+1] == comparr[i])
//					check++;
//			if(count==check)
//				cout << "found!";
//			//cout << check<<"  "<<count;
//		}
//		file.close();
//		file1.close();
//
//	}
//}