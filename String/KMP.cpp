#include <iostream>
using namespace std;

int i,j,lps[100005];
string a,b;

int main()
{
	
	cin>>a>>b;
	int len=0;
	i=1;
	lps[0]=0;
	
	while(i<b.length()) {
		if(b[i]==b[len]) {
			len++;
			lps[i]=len;
			i++;
		}
		else {
			if(len!=0) {
				len=lps[len-1];
			}
			else {
				lps[i]=0;
				i++;
			}
		}
	}
	
	i=j=0;
	
	while(i<a.length()) {
		if(a[i]==b[j]) {
			i++;
			j++;
		}
		if(j==b.length()) {
			cout<<"possible"<<endl;
			return 0;
		}
		else if(i<a.length() && b[j]!=a[i]) {
			if(j!=0) {
				j=lps[j-1];
			}
			else {
				i=i+1;
			}
		}
	}
	cout<<"impossible"<<endl;
	return 0;
}



