#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

void job_sort()
{
	map <string, int> words;

	string arr[5] = { "one", "two", "three", "one", "one" };

	for (auto word : arr) {
		words[word]++;
	}

	ofstream out;
	out.open("out.txt");

	int count = 0;

	map <string, int>::iterator cur;

	out << "Job count:" << endl;

	for (cur = words.begin(); cur != words.end(); cur++)
	{
		out << (*cur).first << ": " << (*cur).second << endl; count += (*cur).second;
	}

	out << "Job percenc:" << endl;

	for (cur = words.begin(); cur != words.end(); cur++)
	{
		out << (*cur).first << ": " << (float)((float)(*cur).second / (float)count) * 100 << "%" << endl;
	}
}