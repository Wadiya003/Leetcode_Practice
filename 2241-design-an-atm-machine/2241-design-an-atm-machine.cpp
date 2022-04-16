class ATM {
public:
    vector<long long> bank;
    vector<int> val;
    ATM() {
    bank = vector<long long>(5, 0);
   val= {20,50,100,200,500};
    }
    
    void deposit(vector<int> banknotesCount) {
    
        for(int i=0;i<5;i++){
            bank[i]+=banknotesCount[i];
        }
       
       
    }
    
    vector<int> withdraw(int amount) {
     vector<int>ans(5,0);
    vector<long long>banks=bank;
     for(int i = 4; i >= 0; i--) {
            if(amount == 0) {
                return ans;
            }
            if(amount >= val[i]) {
                int req = amount / val[i];
                if(bank[i] >= req) {
                    bank[i] -= req;
                    amount -= (val[i] * req);
                   ans[i] += req;
                   
                }
                else {
                  ans[i] +=bank[i];
                 amount -= (val[i] * bank[i]);
                 bank[i] = 0;
                }
                
            }
        }
    
        if(amount == 0) {
            return ans;
        }
        bank=banks;
        return {-1};
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */