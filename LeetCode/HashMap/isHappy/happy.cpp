class Solution {
public:
    bool isHappy(int n) {
        map<int,int> m;
        int k=n;
        while(k!=1)
        {
            int t=k;int sum=0;
            while(t!=0)
            {
                int r=t%10;
                t=t/10;
                sum+=r*r;
            }
            k=sum;
            cout<<"k-"<<k<<endl;
            m[k]++;
            cout<<"m[k]-"<<m[k]<<endl;
            if(m[k]>1)
            return false;
        }
        cout<<"k-"<<k<<endl;
        if(k==1)
return true;
else
return false;
    }
};