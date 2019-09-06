#include <bits/stdc++.h>

using namespace std;

int n,a[400005],b[400005],tempa[400005],tempb[200005],lps[200005];
map<int,int> m1,m2;

void computeLPSArray(char* pat, int M) 
{ 
    // length of the previous longest prefix suffix 
    int len = 0; 
  
    lps[0] = 0; // lps[0] is always 0 
  
    // the loop calculates lps[i] for i = 1 to M-1 
    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
            // This is tricky. Consider the example. 
            // AAACAAAA and i = 7. The idea is similar 
            // to search step. 
            if (len != 0) { 
                len = lps[len - 1]; 
  
                // Also, note that we do not increment 
                // i here 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
} 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	for(int i=0;i<n;i++) {
		cin>>b[i];
	}
	sort(a,a+n);
	a[n]=a[0]+360000;
	for(int i=0;i<n;i++) {
		tempa[i]=a[i+1]-a[i];
	}
	sort(b,b+n);
	b[n]=b[0]+360000;
	for(int i=0;i<n;i++) {
		tempb[i]=b[i+1]-b[i];
	}
	for(int i=n;i<2*n;i++) {
		tempa[i]=tempa[i-n];
	}
	int len=0;
	lps[0]=0;
	int i=1;
	while(i<n) {
		if(tempb[i]==tempb[len]) {
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
	i=0;
	int j=0;
	while(i<2*n) {
		if(tempa[i]==tempb[j]) {
			i++;
			j++;
		}
		if(j==n) {
			cout<<"possible"<<endl;
			return 0;
		}
		else if(i<2*n && tempb[j]!=tempa[i]) {
			if(j!=0) {
				j=lps[j-1];
			}
			else {
				i=i+1;
			}
		}
	}
	cout<<"impossible"<<endl;
}
