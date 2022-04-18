#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <map>
//#include <algorithm>
#include <utility>
using namespace std;
ifstream in("String.txt");

class Compare
{
public:
	bool operator()(pair<string, int> pair1, pair<string, int> pair2)
	{
		if (pair1.second == pair2.second)
		{
			return pair1.first > pair2.first;
		}
		return pair1.second < pair2.second;
	}
};
bool TestSep(char c, string strtemp);
char ToLower(char c);
template <typename InputIterator, typename OutputIterator, typename Function> // class InputIterator, class OutputIterator, class Function
OutputIterator Transform(InputIterator first, InputIterator last, OutputIterator result, Function op);

int main()
{
	string str;
	string separators = " .,!?";
	getline(in, str);

	/*
	vector<string> vstr;
	int pos = 0;
	for (int i = 0; i < str.length(); i++)
	{
		char c = str.at(i); // char c = str[i];
		if (TestSep(c, separators))
		{
			string substring = str.substr(pos, i - pos);
			pos = i+1;
			if (substring.length() > 0)
			{
				//cout<< substring<<"  ";
				vstr.push_back(substring);
			}
		}
	}
	for (auto i : vstr)
	{
		printf("%s\n", i.c_str());
	}

	map<string, int> mapstr;
	for (string str : vstr)
	{
		Transform(str.begin(), str.end(), str.begin(), ToLower); // transform(str.begin(), str.end(), str.begin(), ::tolower);
		mapstr[str]++;
	}

	*/

	map<string, int> mapstr;
	int pos = 0;
	Transform(str.begin(), str.end(), str.begin(), ToLower);
	for (int i = 0; i < str.length(); i++)
	{
		char c = str.at(i); // char c = str[i];
		if (TestSep(c, separators))
		{
			string substring = str.substr(pos, i - pos);
			pos = i + 1;
			if (substring.length() > 0)
			{
				mapstr[substring]++;
			}
		}
	}

	/*
	map<string, int>::iterator it;
	for (it = mapstr.begin(); it != mapstr.end(); it++)
		printf("Word \"%s\" times %d\n", it->first.c_str(), it->second);
	*/

	//vector<pair<string, int>> pr;
	//for (auto i : mapstr) 
	//{
	//	//cout <<"\""<< i.first<< "\"" << " : " << i.second << '\n';
	//	pr.push_back(make_pair(i.first, i.second));
	//}

	priority_queue < pair<string, int>, vector<pair<string, int> >, Compare>  pq;
	//for (auto i : pr)
	//{
	//	pq.push(i);
	//}

	/*
	for (map<string, int>::iterator it = mapstr.begin(); it != mapstr.end(); it++)
		pq.push(make_pair(it->first, it->second));
	*/
	for (auto i : mapstr)
	{
		pq.push(make_pair(i.first, i.second));
	}
	while (!pq.empty())
	{
		cout << pq.top().first << " => " << pq.top().second << "\n";
		pq.pop();
	}
	return 0;
}

char ToLower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A'; // +32
	return c;
}

//bool TestSep(char c, string strtemp)
//{
//	for (auto i : strtemp)
//	{
//		if (c == i)
//		{
//			return true;
//		}
//	}
//	return false;
//}

bool TestSep(char c, string strtemp)
{
	for (string::iterator i = strtemp.begin(); i != strtemp.end(); ++i) // (string::const_iterator i = strtemp.cbegin(); i != strtemp.cend(); ++i)
	{
		if (c == *i) // cout << typeid(i).name(); 
		{
			return true;
		}
	}
	return false;
}
template <typename InputIterator, typename OutputIterator, typename Function>
OutputIterator Transform(InputIterator first, InputIterator last, OutputIterator result, Function op)
{
	while (first != last)
	{
		*result = op(*first);
		++result;
		++first;
	}
	return result;
}