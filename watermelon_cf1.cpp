#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int count,sum=0,flag=1;
  cin>>count;
  for(int i=2;sum<=count;i=i+2)
    {
      for(int j=2;sum<=count;j=j+2)
          {
          sum=i+j;
          if(sum==count)
          {
            flag=-1;
            cout<<"Answer : "<<i<<" "<<j;
            break;

          }
          }
          if(flag==-1)
          {
          cout<<"YES";
          break;
          }
    }
    if(flag==1)
    cout<<"NO";
}
