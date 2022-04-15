#include <iostream>
using namespace std;

int main()
{
  unsigned long long int m,n,a;

  unsigned long long int stone_num,m_l,n_l;
cin >> m >> n >> a;
  if (m%a==0)
  {
    m_l=m/a;
  }
    else
  {
    m_l=m/a + 1;
  }
  if (n%a==0)
  {
    n_l=n/a;
  }
    else
  {
    n_l=n/a+1;
  }

  stone_num=m_l*n_l;
  cout<<stone_num<<endl;

  return 0;
}