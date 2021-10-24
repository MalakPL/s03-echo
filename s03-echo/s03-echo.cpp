#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::logic_error;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;
using std::reverse;

auto main(int argc, const char* argv[]) -> int
{
	try
	{
		if (argc <= 1)
		{
			throw logic_error{ "Nie podano zadnego argumentu" };
		}

		vector<string> Argumenty(argv + 1, argv + argc); // argv+1 aby pominac sciezke do pliku.
		vector<string> Arg{};
		bool isN = false;
		bool isR = false;
		bool isL = false;

		for (int i = 0; i < argc - 1; i++)
		{
			if (Argumenty[i] == "-n")
			{
				isN = true;
				continue;
			}

			if (Argumenty[i] == "-r")
			{
				isR = true;
				continue;
			}

			if (Argumenty[i] == "-l")
			{
				isL = true;
				continue;
			}

			Arg.push_back(Argumenty[i]);
		}

		if (isR)
		{
			reverse(Arg.begin(), Arg.end());
		}

		for (int i = 0; i < Arg.size(); i++)
		{
			cout << Arg[i];

			if (i < Arg.size() - 1) {
				if (isL)
				{
					cout << endl;
				}
				else {
					cout << "-";
				}
			}
		}

		if (!isN)
		{
			cout << endl;
		}

		return 0;
	}
	catch (logic_error ex)
	{
		cerr << ex.what() << endl;
		return 1;
	}
}