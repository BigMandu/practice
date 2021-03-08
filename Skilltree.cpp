/*
���� ��ų ���� skill,
�������� ���� ��ųƮ���� skill_trees�� �־�������
������ ��ųƮ�� ������ return�϶�.

��� ���ĺ� �빮���̴�.
skill�� ���̴� 1�̻� 26����, �ߺ��ؼ� �־����� ���� ����.
skill_trees�� ���̴� 1�̻� 20����.
skill_trees�� ���ұ��̴� 2�̻� 26������ ���ڿ� �ߺ��ؼ� �־����� ���� ����.

skill	skill_trees	                        return
"CBD"	["BACDE", "CBADF", "AECB", "BDA"]	2

BACDE -> B�� �������� C�� ������Ѵ�. �Ұ���
CBADF -> ����
AECB  -> ����
BDA   -> B���������� C�� ������Ѵ�. �Ұ���


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