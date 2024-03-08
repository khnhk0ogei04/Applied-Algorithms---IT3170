#include<bits/stdc++.h>
#include<iostream>
#define MAXN 1000001
//using namespace std;
std::set<std::string>list_sorted_accounts;
int number_transactions = 0;
int total_money_transaction = 0;
std::unordered_map<std::string,int>total_money_transaction_from;
std::unordered_map<std::string, std::set<std::string>>nextAccount;
std::map<std::string,bool>visited;
std::vector<std::string>danhdau;
std::vector<std::string>ketQua;
int inspectCycle = 0;
int k;
void inp(){
	std::string fromAccount;
	while (std::cin>>fromAccount){
		if (fromAccount == "#"){
			break;
		}
		std::string toAccount;
		int money;
		std::string timePoint;
		std::string atm;
		std::cin>>toAccount;
		std::cin>>money;
		std::cin>>timePoint;
		std::cin>>atm;
		list_sorted_accounts.insert(fromAccount);
		list_sorted_accounts.insert(toAccount);
		number_transactions += 1;
		total_money_transaction += money;
		if (nextAccount.find(fromAccount) == nextAccount.end()){
			std::set<std::string> tmp;
			nextAccount.insert({fromAccount,tmp});
		}
		nextAccount[fromAccount].insert(toAccount);
		if (total_money_transaction_from.find(fromAccount) == total_money_transaction_from.end()){
			total_money_transaction_from.insert({fromAccount,0});
		}
		total_money_transaction_from[fromAccount] += money;
	}
}
void dfs(std::string Account, int p, std::string root){
	visited[Account] = true;
	danhdau.push_back(Account);
	for ( auto taikhoan: nextAccount[Account] ){
		if (inspectCycle) break;
		if (taikhoan == root && p == k){
			ketQua.resize(k+1);
			danhdau.push_back(taikhoan);
			for (int i = 0 ; i <= k ; i++){
				ketQua[i] = danhdau[i];
			}
			inspectCycle = 1;
			return;
		}
		if (visited[taikhoan] == true) continue;
		if (!visited[taikhoan]){
			if (p < k) {
				dfs(taikhoan,p+1,root);
			}
		}
	}
	visited[Account] = false;
	danhdau.pop_back();
}
int main(int argc, const char** argv){
	std::string cmd;
	inp();
	while (std::cin>>cmd){
		if (cmd == "#"){
			break;
		}
		if (cmd == "?number_transactions"){
			std::cout<<number_transactions;
			continue;
		}
		if (cmd == "?total_money_transaction"){
			std::cout<<total_money_transaction;
			continue;
		}
		if (cmd == "?list_sorted_accounts"){
			for (auto it: list_sorted_accounts){
				std::cout<<it<<" ";
				continue;
			}
		}
		if ( cmd == "?total_money_transaction_from"){
			std::string tmp;
			std::cin>>tmp;
			int sum = total_money_transaction_from[tmp];
			std::cout<<sum;
			continue;
		}
		if (cmd == "?inspect_cycle"){
			std::string tmp;
			std::cin>>tmp;
			std::cin>>k;
			dfs(tmp,1,tmp);
			if (inspectCycle) {
				std::cout<<"1\n";
				for (auto x: ketQua){
					std::cout<<x<<" ";
				}
			}
			else std::cout<<"0";
			continue;
		}
	}
	return 0;
}
/* A01 A02 1000 10:20:30 ATM1
A01 A03 2000 09:30:18 ATM2
A01 A04 1500 14:25:07 ATM1
A02 A03 3000 08:20:31 ATM1
A03 A01 4000 12:40:00 ATM2
A04 A01 2000 10:30:00 ATM1
A02 A04 3000 08:20:31 ATM1
A04 A03 2000 11:30:00 ATM1
A04 A03 1000 18:30:00 ATM1
#
?inspect_cycle A04 4
1
A04 A03 A01 A02 A04 
*/
