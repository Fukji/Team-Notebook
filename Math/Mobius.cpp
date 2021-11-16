prima.clear(); memset(B,true,sizeof B); B[0]=B[1]=false; 
for (ll i=2;i<MAXN;i++) { 
    if (B[i]) prima.pb(i), SPF[i]=i; 
    for (ll j=0;j<prima.size() && i*prima[j]<MAXN && prima[j]<=SPF[i];j++) 
    B[i*prima[j]]=false, SPF[i*prima[j]]=prima[j];} 
for (ll i=1;i<MAXN;i++) { 
    if (i==1) M[i]=1; else if (SPF[i]==i) M[i]=-1; 
    else if ((i/SPF[i])%SPF[i]==0) M[i]=0; else M[i]=M[i/SPF[i]]*M[SPF[i]];} 
