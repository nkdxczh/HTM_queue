#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <mutex>
#include <algorithm>

class Bank{
    private:
        int num_account;
        float* accounts;
        std::mutex* locks;

    public:
        Bank(int num);
        void progagate(float amount);
        float* get(int id){return &accounts[id];}

        int transfer(int account1, int account2, float amount);
        float sum();

        int transfer_lockfree(int account1, int account2, float amount);
        float sum_lockfree();
};

Bank::Bank(int num){
    num_account = num;
    accounts = new float[num];
    locks = new std::mutex[num];
}

void Bank::progagate(float amount){
    float per = (float)((int)((amount / num_account) * 100)) / 100;
    for(int i = 0; i < num_account - 1; ++i)accounts[i] = per;
    accounts[num_account - 1] = amount - per * (num_account - 1);
}

int Bank::transfer_lockfree(int account1, int account2, float amount){
    if(accounts[account1] < amount)return -1;
    accounts[account1] -= amount;
    accounts[account2] += amount;
    return 0;
}

float Bank::sum_lockfree(){
    float res = 0;
    for(int i = 0; i < num_account; ++i)res += accounts[i];
    return res;
}

int Bank::transfer(int account1, int account2, float amount){
    int account_min = std::min(account1, account2);    
    int account_max = std::max(account1, account2);    
    locks[account_min].lock();
    locks[account_max].lock();
    if(accounts[account1] < amount){
        locks[account_min].unlock();
        locks[account_max].unlock();
        return -1;
    }
    accounts[account1] -= amount;
    accounts[account2] += amount;
    locks[account_min].unlock();
    locks[account_max].unlock();
    return 0;
}

float Bank::sum(){
    float res = 0;
    for(int i = 0; i < num_account; ++i)locks[i].lock();
    for(int i = 0; i < num_account; ++i)res += accounts[i];
    for(int i = 0; i < num_account; ++i)locks[i].unlock();
    return res;
}

#endif
