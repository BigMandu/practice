/*
https://programmers.co.kr/learn/courses/30/lessons/12917

*/

#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";

    sort(s.begin(), s.end(),greater<char>());

    answer = s;
    return answer;
}

int main()
{
    string s = "Zbcdefg";

    s = solution(s);
    cout << s <<endl;
}