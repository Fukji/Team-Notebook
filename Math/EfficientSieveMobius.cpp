prima.clear(); memset(B,true,sizeof B); B[0]=B[1]=false;
for (ll i=2;i&lt;MAXN;i++) {
	if (B[i]) prima.pb(i), SPF[i]=i;
	for (ll j=0;j&lt;prima.size() &amp;&amp; i*prima[j]&lt;MAXN &amp;&amp; prima[j]&lt;=SPF[i];j++)
	B[i*prima[j]]=false, SPF[i*prima[j]]=prima[j];}
for (ll i=1;i&lt;MAXN;i++) {
	if (i==1) M[i]=1; else if (SPF[i]==i) M[i]=-1;
	else if ((i/SPF[i])%SPF[i]==0) M[i]=0; else M[i]=M[i/SPF[i]]*M[SPF[i]];}