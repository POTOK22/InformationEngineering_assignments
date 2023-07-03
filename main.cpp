#include <iostream>
#include <string>
#include <vector>

class Account{
protected:
    std::string accountNumber_;
    double balance_;
public:
    /*constructor done in form of initializer list*/
    /*name(variables names without _) : variable_(variable without _) {}*/
    Account(const std::string& accountNumber, const double& balance)
        : accountNumber_(accountNumber), balance_(balance) {};
    void deposit(double amount){
        /*there are no conditions, you can deposit as much money as you want*/
        balance_ += amount;
        std::cout<<"Deposit successfull. New balance: "<<balance_<<std::endl;
    }
    void withdraw(double amount){
        /*there are conditions because you cannot withdraw more money than you have*/
        if(balance_>=amount){
            balance_ -= amount;
            std::cout<<"Withdrawal successfull. New balance: "<<balance_<<std::endl;
        }
        else{
            std::cout<<"Insufficient funds. Balance: "<<balance_<<std::endl;
        }
    }
    /*getter*/
    double getBalance() const{
        return balance_;
    }
    /*getter*/
    const std::string& getAccountNumber() const{
        return accountNumber_;
    }
};

class CheckingAccount : public Account{
public:
    /*constructor with inheritance of Account class*/
    /*name(variables which are form the inheritated class) : name_of_inheritated_class(GETTERS OF INHERITATED CLASS)*/
    CheckingAccount(const std::string& accountNumber, double balance)
        : Account(accountNumber, balance) {};
    void withdraw(double amount){
        /*there is a task to add 1.50 fee for each withdrawal, but in normal case this method is the same as this one in inherited class*/
        double totalamount = 1.50 + amount;
        if(balance_ >= totalamount){
            balance_ -= totalamount;
            std::cout<<"Withdrawal successfull. New balance: "<<balance_<<std::endl;
        }
        else{
            std::cout<<"Insufficient funds. Balance: "<<balance_<<std::endl;
        }
    }
};

class SavingsAccount: public Account{
protected:
    double interestRate_;
public:
    /*the same maner as before, BUT REMEMBER TO ADD A SETTER FOR INTEREST RATE BECASUSE IT IS ALSO A VARIABLE BUT NOT IN INHERITANCE*/
    SavingsAccount(const std::string& accountNumber, double balance, double interestRate)
        : Account(accountNumber, balance), interestRate_(interestRate) {};
    /*idk why this function does what it does, maybe it will be specified in task*/
    void addInterest(){
        double interest = balance_ * interestRate_ / 100;
        balance_ += interest;
        std::cout << "Interest added. New balance: " << balance_ << std::endl;
    }
    /*getter*/
    double getInterestRate(){
        return interestRate_;
    }
};

class Client{
public:
    Client(const std::string& name)
        : name_(name) {};
    /*adding element of type Account to vector accounts_ of type Account*/
    void addAccount(Account* account){
        accounts_.push_back(account);
    }
    /*printing the accounts*/
    void printAccounts() const{
        std::cout<<"Accounts for "<<name_<<std::endl;
        for(auto &el : accounts_){
            std::cout<<el->getAccountNumber()<<" - $"<<el->getBalance()<<std::endl;
        }
    }
    std::string getName(){
        return name_;
    }
private:
    std::string name_;
    std::vector<Account*> accounts_;
};

class Bank{
public:
    void addClient(Client* client){
        clients_.push_back(client);
    }
    void printClients(){
        std::cout<<"Clients:"<<std::endl;
        for(auto &el : clients_){
            std::cout<<el->getName()<<std::endl;
            /*the method responsible for printing all elements from vector is without cout!!*/
            el->printAccounts();
            std::cout<<std::endl;
        }
    }
private:
    std::vector<Client*> clients_;
};

int main()
{
    // Create accounts
    Account account1("A10001", 5000);
    SavingsAccount account2("S10001", 10000, 2.5);
    CheckingAccount account3("C10001", 2000);

    // Deposit and withdraw from accounts
    account1.deposit(1000);
    account1.withdraw(2000);
    account2.deposit(500);
    account2.addInterest();
    account3.withdraw(500);

    // Create clients and add accounts to them
    Client client1("John Doe");
    client1.addAccount(&account1);
    client1.addAccount(&account2);

    Client client2("Jane Smith");
    client2.addAccount(&account3);

//     Create bank and add clients to it
    Bank bank;
    bank.addClient(&client1);
    bank.addClient(&client2);

//     Print bank clients and their accounts
    bank.printClients();
    return 0;
}
