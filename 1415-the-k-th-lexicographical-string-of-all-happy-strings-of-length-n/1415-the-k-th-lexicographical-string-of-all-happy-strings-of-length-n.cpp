class Solution {
public:

    string kthHappy = "";
    int k = 0;

    void solve(int n ,string  curr)
    {

        if(k==0) return;

        if(n==0)
        {
            k-=1;
            if(k==0){
                kthHappy = curr;
                cout<<"hello";
            }

            return;
        }

        //try placing a
        if(curr=="" or curr.back()!='a')
        {
            solve(n-1, curr+'a');
        }

        //try placing b
        if(curr=="" or curr.back()!='b')
        {
            solve(n-1, curr+'b');
        }

        //try placing c
        if(curr=="" or curr.back()!='c')
        {
            solve(n-1, curr+'c');
        }


    }
    string getHappyString(int n, int m) {

        k = m;

        solve(n,  "");

        return kthHappy;
    }
};



