#include<bits/stdc++.h>
using namespace std;
vector<string> v1;

void generate_paranthesis(char *a, int n, int open = 0, int close = 0, int i = 0) {
	//base case
	if (i == 2 * n) {
		a[i] = '\0';
		v1.push_back(a);
		//cout << a << endl;
		return;
	}

	//open
	if (open < n) {
		a[i] = '(';
		generate_paranthesis(a, n, open + 1, close, i + 1);
	}

	//closing
	if (close < open) {
		a[i] = ')'; 
		generate_paranthesis(a, n, open, close + 1, i + 1);
	}
	return;
}


int main() {


	char output[100];
	int n;
	cin >> n;
	generate_paranthesis(output, n);
	reverse(v1.begin(),v1.end());
	for(auto i:v1)
		cout<<i<<endl;

	return 0;
}