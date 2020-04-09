#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#if 0
int GCD(int a,int b)
{
  int c;
  while(c=a%b)
  {
    a=b;
    b=c;
  }
  return b;
}
int main()
{
  int n, power;
  vector<int> num;
  while(cin>>n>>power)
  {
    num.resize(n);
    for(int i = 0;i < n; i++)
    {
      cin >> num[n];
    }
    
    for(int j=0; j<n ;j++)
    {
      if(power>=num[j])
        power+=num[j];
      else
        power+=GCD(power,num[j]);
    }
    cout<<power<<endl;
  }
  
  return 0;
}
#endif

#if 0
//0725 2
int main()
{
  string s;
  while(cin>>s)
  {
    int hashtable[256]={0};
    for(auto &e : s)
    {
      hashtable[e]++;
    }
    size_t i;
    for(i=0;i<s.size();i++)
    {
      if(hashtable[s[i]]==1)
      {
        cout<<s[i]<<endl;
        break;
      }
    }
    if(i>=s.size())
      cout<<-1<<endl;
  }
  return 0;
}

#endif

#if 0
//0726 1
class Gift
{
  public:
    int getValue(vector<int> gifts, int n)
    {
      sort(gifts.begin(),gifts.end());
      
      int middle = gifts[n/2];
      int count = 0;

      for(int i=0;i<n;i++)
      {
       if(gifts[i]==middle) 
         count++;
      }
      if(count > n/2)
        return middle;
      else
        return 0;
    }
};

int main()
{
  vector<int> v;
  int n;
  Gift a;

  while(cin>>n)
  {
    v.resize(n);
    for(int i=0;i<n;i++)
    {
      cin>>v[i];
    }
    cout<<a.getValue(v,n)<<endl;
  }
  return 0;
}

#endif

#if 0
// 0726 2
int main()
{
  string s1,s2;

  vector<vector<int> > f(3,vector<int>(3,0));

  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      cout<<f[i][j];
    }
    cout<<endl;
  }
  return 0;
}

#endif

#if 1
// 0726 2
int minDistance(string s1, string s2)
{
  if(s1.empty() || s2.empty())
  {
    return max(s1.size(), s2.size());
  }

  int len1=s1.size();
  int len2=s2.size();

  vector<vector<int> > f(1 + len1, vector<int>(1+len2 ,0 ));
  for(int i = 0; i <= len1; i++)
    f[i][0] = i;
  for(int j = 0; j <= len2; j++)
    f[0][j] = j;

  for(int i = 1; i <= len1; i++)
  {
    for(int j = 1; j <= len2; j++)
    {
      if(s1[i - 1] == s2[j - 1])
      {
        f[i][i] = 1 + min(f[i][j - 1], f[i - 1][j]);
        f[i][j] = min(f[i][j], f[i - 1][j - 1]);
      }
      else
      {
        f[i][j] = 1 + min(f[i][j], f[i - 1][j]);
        f[i][j]=min(f[i][j], 1 + f[i - 1][j - 1]);
      }
    }
  }
  return f[len1][len2];
}

int main()
{
  string a,b;
  while(cin >> a >> b)
    cout<<minDistance(a, b)<<endl;
  return 0;
}

#endif
