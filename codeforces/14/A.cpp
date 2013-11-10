//============================================================================
// Name        : 14A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {
	int n,m ; cin >> n >> m ;
	vector <string> s ; string ss ;
	for (int i=0 ; i<n ; i++) {cin >> ss  ; s.push_back (ss) ;}
	for (int i=0 ; i<=s.size()-1 ; i++) {if (s[i] == string(m,'.'))	{s.erase (s.begin()+i) ; i-- ;}		else break ;}
	for (int i=s.size()-1 ; i>=0 ; i--) {if (s[i] == string(m,'.')) s.erase (s.begin()+i) ;		else break ;}
	for (int i=0 ; i<s[0].size() ; i++)	for (int ii=0 ; ii<s.size() ; ii++)
	{if (s[ii][i] != '.') goto r ; if (ii==s.size()-1)
			{
			for (int z=0 ; z<s.size() ; z++) s[z].erase (i,1) ; i-- ;
			} }
		r:
		for (int i=s[0].size()-1 ; i>=0 ; i--)	for (int ii=0 ; ii<s.size() ; ii++)
			{if (s[ii][i] != '.') goto rr ; if (ii==s.size()-1)
				{
				for (int z=0 ; z<s.size() ; z++) s[z].erase(i,1) ;
				}

			}
	rr:for (int i=0 ; i<s.size() ; i++) {cout << s[i] << endl ;}



}
