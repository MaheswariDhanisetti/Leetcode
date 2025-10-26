class Bank {
public:

    int n = 0;

    vector<long long>bal ;

    Bank(vector<long long>& balance) {
        
        n = balance.size();
        bal = balance;

    }
    
    bool transfer(int account1, int account2, long long money) {
        
        if(account1 <= n and account2 <= n and bal[account1-1]>=money){
            bal[account1-1]-=money;
            bal[account2-1]+=money;
            return true;
        }

        return false;

    }
    
    bool deposit(int account, long long money) {
      
        if(account <= n){
            bal[account-1] += money;
            return true;
        }

        return false;
    }
    
    bool withdraw(int account, long long money) {
        if(account <= n and bal[account-1] >= money ){
            bal[account-1] -= money;
            return true;
        }

        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */