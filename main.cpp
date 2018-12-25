#include <fstream>
#include <iostream>
#include <string>

using namespace std;
void open(string *name, int e)
{
		fstream inpt(name[e], ios_base::in);
		try
		{
			if (!inpt)
			{
				throw 404;
			}
		}
		catch (int i)
		{
			cout <<"Error # "<< i<<", file not found." << endl;
			exit(EXIT_SUCCESS);
		}
		fstream outpt("D:\\dout.txt", ios_base::out);
		string s;

		while (!inpt.eof())
		{
			inpt >> s;
			int l = s.size();
			for (int i = 0; i < l; i++) {
				if (s[i] == 'a')
					s[i] = 'A';
				if (s[i] == 'e')
					s[i] = 'E';
				if (s[i] == 'u')
					s[i] = 'U';
				if (s[i] == 'i')
					s[i] = 'I';
				if (s[i] == 'o')
					s[i] = 'O';
			}
			outpt << s << " ";
			cout << s << " ";
		}
		cout << endl;
		inpt.close();

}
	

int main()
{
	int e;
	string name[4] = { "D:\\text1.txt","D:\\text2.txt","D:\\text3.txt","D:\\text4.txt" };
	cout << "Choose File:\n" << "1. My name is Kate." << endl << "2. My family." << endl << "3. Lunches for school." << endl << "4. No file." << endl << "5. Exit." << endl;
	while (true)
	{
		switch (getchar()) {
		case '1': {
			e = 0;

			open(name, e);
			break;		}
		case '2': {
			e = 1;

			open(name, e);		}
		case '3': {
			e = 2;

			open(name, e);
			break;	}
		case '4': {
			e = 3;

			open(name, e);
			break;	}

		case '5':
			cout << "Exit" << endl;
			exit(EXIT_SUCCESS);
			return 0;
		}
	}
}
