/*
https://programmers.co.kr/learn/courses/30/lessons/12919

seoul	    return
[Jane, Kim]	�輭���� 1�� �ִ�


*/

#include <iostream>

#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) 
{
    string answer = "";

    string sol = "Kim";

    for(int i=0; i<seoul.size(); i++)
    {
        if(sol.compare(seoul[i]) == 0)
        {
            answer = "�輭���� " + to_string(i) + "�� �ִ�";
            break;            
        }
    }

    return answer;
}

int main()
{
    vector<string>input = {"Jane", "Kim"};

    string sol;
    sol = solution(input);

    cout<<sol;
}