//============================================================================
// Name        : 152A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	int x,y,mx,t=0 ; cin >> x >> y ; string s[x] ; bool b[x] ; memset(&b, 0, sizeof(bool) * x);
	for (int i=0 ; i<x ;i++)
	{
		cin >> s[i] ;
	}
	for (int i=0 ; i<y ; i++)
	{
		mx=0 ;
		for (int q=0 ; q<x ; q++)
		{
			mx=max(mx,(int)(s[q][i])) ;
		}
		for (int q=0 ; q<x ; q++)
		{
				if (s[q][i]==mx)	{t++ ; b[q]=true ;}
		}
	}
	cout << count(b, b+x, true) ;
	}


