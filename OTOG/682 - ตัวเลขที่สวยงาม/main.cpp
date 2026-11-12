#pragma GCC optimize("O5, unroll-loops, inline")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
using namespace std;

int main(){
	string last = "NO";
	ifstream file("a.txt");
	file >> last;
	string current = (last == "YES" ? "NO" : "YES");
	printf("%s", current.c_str());
	ofstream fout("a.txt");
	fout << current;
}
