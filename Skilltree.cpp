/*
선행 스킬 순서 skill,
유저들이 만든 스킬트리인 skill_trees가 주어졌을때
가능한 스킬트리 개수를 return하라.

모두 알파벳 대문자이다.
skill의 길이는 1이상 26이하, 중복해서 주어지는 경우는 없다.
skill_trees의 길이는 1이상 20이하.
skill_trees의 원소길이는 2이상 26이하인 문자열 중복해서 주어지는 경우는 없다.

skill	skill_trees	                        return
"CBD"	["BACDE", "CBADF", "AECB", "BDA"]	2

BACDE -> B를 배우기전에 C를 배워야한다. 불가능
CBADF -> 가능
AECB  -> 가능
BDA   -> B를배우기전에 C를 배워야한다. 불가능


*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) 
{
    int answer = 0;
    int j = 0;
    bool bflag = false;
    for(int i = 0; i<skill.size(); i++)
    {
        for(string str : skill_trees)
        {
            if(skill[i] == str[j])
            {
                bflag = true;
            }
        }
        if(bflag) answer++;
    }
    
    return answer;
}

int main()
{
    string skill = "CBD";
    vector<string> sktree;
    sktree = {"BACDE", "CBADF", "AECB", "BDA"};

    int sol = 0;

    sol = solution(skill, sktree);

    cout << sol;
}