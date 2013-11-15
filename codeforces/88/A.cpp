//============================================================================
// Name        : 88A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;int i[3] ;

int sum(int i1, int i2)
{
	if (i1<i2) return i2-i1 ;
	else return i2+12-i1 ;
}

bool sss()
{
	if (sum(i[0],i[1])==4 && sum(i[1],i[2])==3) {cout << "major" ;return true ;}
	else if (sum(i[0],i[1])==3 && sum(i[1],i[2])==4) {cout << "minor" ;return true ;}
	else return false ;
}

void swap(int x,int y)
{
	int t = i[x] ;
	i[x]=i[y] ;
	i[y]=t ;
}
int main() {
	string s ;
	for (int w=0 ; w<3;w++)
	{cin >> s ;
	if (s=="C") i[w]=1 ;
	if (s=="C#") i[w]=2 ;
	if (s=="D") i[w]=3 ;
	if (s=="D#") i[w]=4 ;
	if (s=="E") i[w]=5 ;
	if (s=="F") i[w]=6 ;
	if (s=="F#") i[w]=7 ;
	if (s=="G") i[w]=8 ;
	if (s=="G#") i[w]=9 ;
	if (s=="A") i[w]=10 ;
	if (s=="B") i[w]=11 ;
	if (s=="H") i[w]=12 ;}
	if (sss()) return 0 ;else swap(1,2) ;
	if (sss()) return 0 ;else swap(0,2) ;
	if (sss()) return 0 ;else swap(1,2) ;
	if (sss()) return 0 ;else swap(0,2) ;
	if (sss()) return 0 ;else swap(1,2) ;
	if (sss()) return 0 ;else cout << "strange" ;


}
