#include<iostream>
#include<vector>
using namespace std;

void find_worms(int n, int m, vector<int> a, vector<int> juicy)
{
    for (int i=0;i<juicy.size();++i)
    {
        int w;
        int left=1;
        int right=n;
        int mid;

        while(right>left)
        {
            mid=(right+left)/2;

            int sum_r=0;
            for(int j=0;j<right;++j)
            {

                sum_r+=a[j];
                //cout<<":sum right:"<<sum_r<<endl;
            }
            //cout<<"here"<<endl;


            int sum_l=0;
            for(int j=0;j<left;++j)
            {
                sum_l+=a[j];
            }


            int sum_m=0;
            for(int j=0;j<mid;++j)
            {
                sum_m+=a[j];
            }
/*
            cout<<"juicy:"<<juicy[i]<<endl;
            cout<<"left:"<<left<<" right:"<<right<<" mid:"<<mid<<endl;
            cout<<"sum left:"<<sum_l<<endl;
            cout<<"sum right:"<<sum_r<<endl;
            cout<<"sum mid:"<<sum_m<<endl;
*/
            if(mid>left)
            {
                //cout<<"here"<<endl;
                if (juicy[i]>sum_m && juicy[i]<=sum_r)
                {
                    left=mid;
                }
                else //if(juicy[i]>=sum_l && juicy[i]<=sum_m)
                {
                    right=mid;
                }
            }

            else if(juicy[i]>sum_l)
            {
                w=right;
                break;
            }
            else
            {
                w=left;
                break;
            }
        }
        cout<<w<<" ";
    }
}

void show(int n,vector<int> a)
{
    int num=0;
    for(int i=0;i<n;++i)
    {
        for(int j=1;j<=a[i];++j)
        {
            ++num;
            cout<<num<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n,m,value_a;
    //input the 1st line
    cin>>n;
    vector<int> a;
    //input the 2nd line
    for (int i=0;i<n;++i)
    {
        cin>>value_a;
        a.push_back(value_a);
    }
    //std::cout<<a[4]<<endl;
    //input the 3rd line
    cin>>m;
    vector<int> juicy;
    //input the 4th line
    for (int i=0;i<m;++i)
    {
        cin>>value_a;
        juicy.push_back(value_a);
    }

    //show(n,a);

    find_worms(n,m,a,juicy);

    return 0;
}
