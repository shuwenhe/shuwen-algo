#include<bits/stdc++.h>
using namespace std;

int T,n,k,q,l[200010],xx[200010],yy[200010],dp[200010][110];
vector<int>v[200010];//每个人的词库

inline int read(){//快读
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
    	if(c=='-')f=-1;
    	c=getchar();
	}
	while(c>='0'&&c<='9'){
    	x=x*10+c-'0';
		c=getchar();
    }
    return x*f;
}
int main()
{
	T=read();
	while(T--){
		n=read();k=read();q=read();
		int maxl=0,maxr=0;
		for(int i=1;i<=n;i++){
			l[i]=read();
			v[i].clear();
			for(int j=1;j<=l[i];j++){
				int x=read();
				maxl=max(maxl,x);
				v[i].push_back(x);
			}
		}
		for(int i=1;i<=q;i++){
			xx[i]=read(),yy[i]=read();
			maxr=max(maxr,xx[i]);
		}
		for(int i=0;i<=maxl;i++){
			for(int j=0;j<=maxr;j++){
				dp[i][j]=-1;
			}
		}
		dp[1][0]=0;//必须从1开始
		for(int i=1;i<=maxr;i++){//i为轮数
			for(int j=1;j<=n;j++){
				int x=-1;
				for(int k1=0;k1<v[j].size();k1++){
					int t1=v[j][k1];//t1为这个人的第k1+1个单词
					if(k1>=k){//长度超过k
						int t2=v[j][k1-k];
						if(dp[t2][i-1]!=-1&&dp[t2][i-1]!=j&&x==k1-k)x=-1;//如果唯一能转移的状态出界
					}
					if(x!=-1){//更新当前状态
						if(dp[t1][i]==-1)dp[t1][i]=j;
						else if(dp[t1][i]!=j)dp[t1][i]=0;
					}
					if(dp[t1][i-1]!=-1&&dp[t1][i-1]!=j)x=k1;//更新x
				}
			}
		}
		for(int i=1;i<=q;i++){
			if(yy[i]>maxl)cout<<"0";//如果不存在yy[i]
			else cout<<(dp[yy[i]][xx[i]]!=-1);//否则输出是否无解
			puts("");
		}
	}
}
