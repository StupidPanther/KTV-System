#include"stdafx.h"
#include"service.h"
#include<fstream>
using namespace std;

vector<string> tolist::get(string filename)
{
	string temp = "";
	ifstream fin(filename);

	bool end = false;

	vector<string> queue;
	for (int i = 1; end == false; i++)
	{
		fin >> temp;
		if (fin.eof() == true)
		{
			end = true;
			break;
		}
		
		queue.push_back(temp);
	}

	fin.close();
	return queue;
}