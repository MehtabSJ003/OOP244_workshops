#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include "cStrTools.h"
#include "Phone.h"

using namespace std;

namespace sdds
{
	void phoneDir(const char* programTitle, const char* fileName)
	{
		cout << programTitle << " phone directory search\n";
		cout << "-------------------------------------------------------\n";

		while (1)
		{
			FILE* f = fopen(fileName, "r");

			if (!f)
			{
				cout << fileName << " file not found!\n";
				break;
			}
			else
			{
				cout << "Enter a partial name to search (no spaces) or enter '!' to exit\n> ";
				string partialName;
				cin >> partialName;
				if (partialName == "!")
				{
					fclose(f);
					break;
				}
				// convert to lower case
				for (char& ch : partialName)
				{
					ch = toLower(ch);
				}

				char name[50];
				int area = 0, prefix = 0;
				char number[5];

				while (1)
				{
					fscanf(f, " %[^\t]s", name);
					getc(f);
					fscanf(f, "%d", &area);
					getc(f);
					fscanf(f, "%d", &prefix);
					getc(f);
					fscanf(f, "%4s", number);
					if (getc(f) == EOF)
						break;

					string lowerCaseName(name);
					for (char& ch : lowerCaseName)
					{
						ch = toLower(ch);
					}

					if (strStr(lowerCaseName.c_str(), partialName.c_str()))
						cout << name << ": (" << area << ") " << prefix << "-" << number << "\n";
				}
			}
			fclose(f);
		}

		cout << "Thank you for using " << programTitle << " directory.\n";
	}
}