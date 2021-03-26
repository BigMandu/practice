/*
https://programmers.co.kr/learn/courses/30/lessons/49993

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


�߰� ����

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
    if(vec.size() == 0) return true; //������ �� ������

    for(int i = 0; i<vec.size(); i++) 
    {
        if(vec[i] != skill[i]) //�ϳ��� �֤����� ������� ���ؼ� ������ �Ұ��� �������ָ�ä���
        {
            return false;
        }
    } 
    return true; //���� ���� ���Ϥ�
}

int solution(string skill, vector<string> skill_trees) 
{
    int answer = 0;
    bool bflag = false;
    vector<char> vec;
    
    for(string userstr : skill_trees) //������ ���� ��ųƮ���� �����´�
    {
        for(char ch : userstr) //������ ���� ��ųƮ���� �ѹ��ڸ� �����ͼ�
        {
            if(skill.find(ch) != -1) //�� ���ڰ� ������ ��ų������ ������ �ִ´�. -1�� �����̸� ���°���
            {
                vec.push_back(ch); //�� ���ڸ� �迭�� �ִ´�.
            }
        }

        if(ChkValid(skill, vec))
        {
            answer++;
        }
        vec.clear(); //�迭 �ʱ�ȭ �� ������.
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
//��