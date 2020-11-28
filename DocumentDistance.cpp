//============================================================================
// Name        : DocumentDistance.cpp
// Author      : My Code
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

string RemoveChar(string &str) // removes the ending punctionation
{
   string result;
   char c = ',';
   char c2 = ';';
   char c3 = '.';
   char c4 = '?';
   char c5 = '!';

   for (size_t i = 0; i < str.size(); i++)
   {
          char currentChar = str[i];
          if (currentChar != c && currentChar != c2 && currentChar != c3 && currentChar != c4 && currentChar != c5)
              result += currentChar;
   }
   return result;
}


void eraseSubStr(string & mainStr, const string toErase)
{
    size_t pos = mainStr.find(toErase);
    if (pos != string::npos)
    {
        // If found then erase it from string
        mainStr.erase(pos, toErase.length());
    }
}

string CreateWords(string str, string &str2)
{
   string result;
   string alNum = "abcdefghijklmnopqrstuvwxyz0123456789";

   for (size_t i = 0; i < str.size(); i++)
   {
          char currentChar = str[i];

          if (alNum.find(currentChar) != string::npos) // if alNum contains the char
          {
              result += currentChar;
          }
          else{ // if the alNum do not contain the char, then add this word + char into a new string so that it can be removed from the original word
              str2 = result;
              str2 += currentChar;
              return result;
          }
   }

       return result;
}


void getFrequency(ifstream& file, unordered_map<string, int>& freqmap)
{
    //unordered_map<string, int>::iterator itr;

    string word;
    string word2 = " "; // getting the word to remove

    while(file >> word)
    {
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	string w = CreateWords(word, word2);

	if(word == word2){ // meaning that if the original word contains an end char such as , ; or . only this needs to be removed. word2 will also contain the word + punctuation
	    w = RemoveChar(word);
	    ++freqmap[w];
	    continue;
	}
	while(word != w){ // if the returned value is not same as the actual word, meaning that this word still needs to be parsed
	    //cout << "inside while: word and w:" << word << " " << w << "\n";
	    ++freqmap[w]; // add the word that is parsed so far
	    eraseSubStr(word, word2); // remove the parsed word and get the remaining word
	    //cout << "new word:" << word << " " << "\n";
	    word2 = " ";
	    w = CreateWords(word, word2); // get the new word
	    //cout << "new w:" << w << " " << "\n";
	}
	if(!w.empty()){ // not so needed because we do not include empty elements in dot product but good to not store ' ' as element in map
	    ++freqmap[w];
	}
	word2 = " ";
}
/*
    int result = 0;
    for(itr = freqmap.begin(); itr != freqmap.end(); ++itr)
    {
	result += itr->second;
	cout << "itr:" <<itr->first << " " << itr->second <<"\n";
    }
*/
}

double getDotProduct(unordered_map<string, int> firstmap, unordered_map<string, int> secondmap)
{
    unordered_map<string, int>::iterator itr;

    double dproduct = 0.0;

    for(itr = firstmap.begin(); itr != firstmap.end(); ++itr)
    {
	string element = itr->first;
	if(secondmap.find(element) != secondmap.end() && !element.empty())
	{
	    //cout <<"element: " << element << "\n";
	    dproduct += itr->second * secondmap.at(element);

	}
    }

    return dproduct;
}

int main() {

    ifstream file1;
    ifstream file2;

    file1.open("first.txt");
    file2.open("second.txt");

    if(!file1.is_open() || !file2.is_open())
    {
	cout << "Error opening the files " <<"\n";
	return 0;
    }

    auto start = high_resolution_clock::now();

    unordered_map<string, int> firstmap;
    unordered_map<string, int> secondmap;

    getFrequency(file1, firstmap);
    cout << "------second map starts after-----" << "\n";
    getFrequency(file2, secondmap);

    //cout << " ------------ dotProduct ------------ "<< "\n";
    double dotProduct = getDotProduct(firstmap, secondmap);
    //cout << " ------------ dotProduct2 ------------ "<< "\n";
    double dotProduct2 = getDotProduct(firstmap, firstmap);
    //cout << " ------------ dotProduct3 ------------ "<< "\n";
    double dotProduct3 = getDotProduct(secondmap, secondmap);


    cout << "dotProduct: " << dotProduct << "\n";
    cout << "sqrt(double(dotProduct2)):" << sqrt(double(dotProduct2)) << "\n";
    cout << "sqrt(double(dotProduct3)):" << sqrt(double(dotProduct3)) << "\n";

    double result = acos(dotProduct / (sqrt(dotProduct2) * sqrt(dotProduct3)));
    cout << "result is: " << result << "\n";

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds";

	return 0;
}

