/*
https://programmers.co.kr/learn/courses/30/lessons/42576


�������� ���� ������ �̸��� return�ϸ�ȴ�.

participant	                            completion	                        return
[leo, kiki, eden]	                    [eden, kiki]	                    leo
[marina, josipa, nikola, vinko, filipa]	[josipa, filipa, marina, nikola]	vinko
[mislav, stanko, mislav, ana]	        [stanko, ana, mislav]	            mislav

���ǻ���

������ ��⿡ ������ ������ ���� 1�� �̻� 100,000�� �����Դϴ�.
completion�� ���̴� participant�� ���̺��� 1 �۽��ϴ�.
�������� �̸��� 1�� �̻� 20�� ������ ���ĺ� �ҹ��ڷ� �̷���� �ֽ��ϴ�.
������ �߿��� ���������� ���� �� �ֽ��ϴ�.

*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> hashmap;
    int i=0;
    for(string x : participant)
    {
        hashmap[x]++;
        i++;
    }

    for(string x : completion)
    {
        hashmap[x]--;
    }

    for(auto check : hashmap)
    {
        if(check.second > 0)
        {
            answer = check.first;
            break;
        }
    } 

    
    return answer;
}

int main()
{
    vector<string> inpartici;
    vector<string> incomple;
    string sol = "";
    inpartici = {"marina", "josipa", "nikola", "vinko", "filipa"}; //{"mislav", "stanko", "mislav", "ana"}; //{"leo", "kiki", "eden"}; 
    incomple = {"josipa", "filipa", "marina", "nikola"}; //{"stanko", "ana", "mislav"}; //{"eden", "kiki"};

    sol = solution(inpartici, incomple);


    cout<<sol;

    //printf("%s",sol);
}