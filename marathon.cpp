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

using namespace std;

/*
bool comparestring(string participant, vector<string> complete, vector<bool> &chkvec)
{
    vector<string>::iterator it;
    int i = 0;

    for( it = complete.begin(); it != complete.end(); it++, i++)
    {
        if(chkvec.at(i) == false && *it == participant)
        {
            chkvec.at(i) = true;
            return true;
        }
    }
    return false;
}
*/

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    vector<bool> chkvec;
    chkvec.assign(completion.size(),false);
    bool bSuccess = false;
    int i = 0;

    vector<string>::iterator it;
    for(it = participant.begin(); it != participant.end(); it++)
    {
        if(chkvec.at(i)==false && *it == completion[i])
        {
            chkvec.at(i) = true;
            i++;
            continue;
        }
        else
        {
            answer = *it;
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