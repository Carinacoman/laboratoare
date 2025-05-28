#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string toLower(const string& str)
{
	string lower = "";
	for (char c : str)
	{
		if (c >= 'A' and c <= 'Z')
			lower += string(1, c - 'A' + 'a');
		else
			lower += c;
	}
	return lower;
}

bool separator(char c)
{
	if (c == ' ' || c == ',' || c == '?' || c == '!' || c == '.')
		return true;
	return false;
}

class Compare {
public:
	bool operator()(const pair<string, int>& a, const pair<string, int>& b) {
		if (a.second != b.second)
			return a.second < b.second;

		int mij = (int)a.first.length() < (int)b.first.length() ? (int)a.first.length() : b.first.length();
		for (int i = 0; i < mij;i++)
		{
			if (a.first[i] != b.first[i])
				return a.first[i] > b.first[i];
		}
		return mij == (int)b.first.length();
	}
};


int main()
{
	string s;
	ifstream fin("input.txt.txt");
	getline(fin, s);
	fin.close();


	vector<string> v;
	int i = 0;

	while (i < s.length())
	{
		while (i < s.length() && separator(s[i]))
			i++;
		if (i >= s.length())
			break;

		int l = i;
		while (i < s.length() && !separator(s[i]))
			i++;

		v.push_back(s.substr(l, i - l));
	}

	map<string, int>fr;
	for (auto x : v)
		fr[toLower(x)]++;

	priority_queue<pair<string, int>, vector<pair<string, int>>, Compare>p;
	p.push({ "i", 2 });
	p.push({ "bought", 1 });
	p.push({ "an", 2 });
	p.push({ "apple", 3 });
	p.push({ "then", 1 });
	p.push({ "eat", 1 });
	p.push({ "is", 1 });
	p.push({ "my", 1 });
	p.push({ "favorite", 1 });


	for (auto i : fr)
		p.push(make_pair(i.first, i.second));

	while (!p.empty())
	{
		cout << p.top().first << " => " << p.top().second << endl;
		p.pop();
	}

	return 0;
}