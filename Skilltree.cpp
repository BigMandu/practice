/*
https://programmers.co.kr/learn/courses/30/lessons/49993

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


추가 테케

skill	skill_trees                                     	                        return
"CBD"   ["CAD"]                                                                     0
"CBD"   ["AEF", "ZJW"]                                                              2
"REA"   ["REA", "POA"]                                                              1
"CBDK"  ["CB", "CXYB", "BD", "AECD", "ABC", "AEX", "CDB", "CBKD", "IJCB", "LMDK"]   4
"BDC"   ["AAAABACA"]                                                                0
"CBD"   ["C", "D", "CB", "BDA"]                                                     2

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool ChkValid(string skill, vector<char>vec)
{
    if(vec.size() == 0) return true; //없으면 걍 가능함

    for(int i = 0; i<vec.size(); i++) 
    {
        if(vec[i] != skill[i]) //하나라도 있ㅇ츠면 순서대로 비교해서 없으면 불가능 리턴해주며ㅓㄴ됨
        {
            return false;
        }
    } 
    return true; //있음 가능 리턴ㅁ
}

int solution(string skill, vector<string> skill_trees) 
{
    int answer = 0;
    bool bflag = false;
    vector<char> vec;
    
    for(string userstr : skill_trees) //유저가 찍은 스킬트리를 가져온다
    {
        for(char ch : userstr) //유저가 찍은 스킬트리중 한문자를 가져와서
        {
            if(skill.find(ch) != -1) //이 문자가 정해진 스킬순서에 있으면 넣는다. -1이 리턴이면 없는거임
            {
                vec.push_back(ch); //그 문자를 배열에 넣는다.
            }
        }

        if(ChkValid(skill, vec))
        {
            answer++;
        }
        vec.clear(); //배열 초기화 꼭 해주자.
    }
    
    return answer;
}

int main()
{
    string skill = "CBD";
    vector<string> sktree;
    sktree = {"C", "D", "CB", "BDA"};

    int sol = 0;

    sol = solution(skill, sktree);

    cout << sol;
}
//굿