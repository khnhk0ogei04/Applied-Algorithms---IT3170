#include<bits/stdc++.h>
#include<iostream>
#define MAXN 100001
using namespace std;
std::unordered_map<std::string,int>mp; //<userID,numError>
std::unordered_map<std::string,std::map<std::string,int>>mp2; //<userID,<problemID,pointPerProblem>
int total_number_submissions = 0;
int number_error_submissions = 0;
int time1[MAXN];
int convert(string time){
    int hour = std::stoi(time.substr(0, 2));
    int minute = std::stoi(time.substr(3, 2));
    int second = std::stoi(time.substr(6, 2));
    return hour * 3600 + minute * 60 + second;

}
void inp(){
	std::string userID;
	memset(time1,0,sizeof(time1));
	while (std::cin>>userID){
		if (userID == "#"){
			break;
		};
		std::string problemID;
		std::string timePoint;
		std::string status;
		int point;
		std::cin>>problemID;
		std::cin>>timePoint;
		std::cin>>status;
		std::cin>>point;
		total_number_submissions += 1;
		if (status == "ERR"){
			number_error_submissions += 1;
		}
		if (mp.find(userID) == mp.end()){
			mp.insert({userID,0}); 
		}
		if (status == "ERR"){
			mp[userID] += 1;
		}
		else {
			if (mp2.find(userID) == mp2.end()){
				map<string,int> temp;
				temp.insert({problemID,point});
				mp2.insert({userID,temp});
			}
			else if (point >mp2[userID][problemID])
			mp2[userID][problemID] = point;
		}
		time1[convert(timePoint)]++;		
	}
}
void cal(){
	for (int i = 1 ; i <= MAXN ; i++){
		time1[i] += time1[i-1];
	}
}
int main(int argc, const char** argv){
	inp();
	cal();
	std::string cmd;
	while (std::cin>>cmd){
		if (cmd == "#"){
			break;
		}
		if (cmd == "?total_number_submissions"){
			std::cout<<total_number_submissions;
			continue;
		}
		if (cmd == "?number_error_submissions"){
			std::cout<<number_error_submissions;
			continue;
		}
		if (cmd == "?number_error_submission_of_user"){
			std::string tmp;
			std::cin>>tmp;
			int count = 0;
			count += mp[tmp];
			std::cout<<count;
			continue;
		}
		if (cmd == "?total_point_of_user"){
			std::string tmp;
			std::cin>>tmp;
			int count = 0;
			for (auto it: mp2[tmp]){
				count += it.second;
			}
			std::cout<<count;
			continue;
		}
		if (cmd == "?number_submission_period"){
			std::string tmp1,tmp2;
			std::cin>>tmp1>>tmp2;
			std::cout<<time1[convert(tmp2)] - time1[convert(tmp1)];
			continue;
		}
	}
	return 0;
}

/* /tmp/HdwPu9mYiH.o
U001 P01 10:30:20 ERR 0
U001 P01 10:35:20 OK 10
U001 P02 10:40:20 ERR 0
U001 P02 10:55:20 OK 7
U002 P01 10:40:20 ERR 0
U001 P01 11:35:20 OK 8
U002 P02 10:40:20 OK 10
#
?total_number_submissions
7
?number_error_submissions
3
?number_error_submission_of_user U002
1
?total_point_of_user U001
17
?number_submission_period 10:00:00 11:30:45
6 */