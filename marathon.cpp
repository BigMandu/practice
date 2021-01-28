/*
https://programmers.co.kr/learn/courses/30/lessons/42576


완주하지 못한 선수의 이름을 return하면된다.

participant	                            completion	                        return
[leo, kiki, eden]	                    [eden, kiki]	                    leo
[marina, josipa, nikola, vinko, filipa]	[josipa, filipa, marina, nikola]	vinko
[mislav, stanko, mislav, ana]	        [stanko, ana, mislav]	            mislav

주의사항

마라톤 경기에 참여한 선수의 수는 1명 이상 100,000명 이하입니다.
completion의 길이는 participant의 길이보다 1 작습니다.
참가자의 이름은 1개 이상 20개 이하의 알파벳 소문자로 이루어져 있습니다.
참가자 중에는 동명이인이 있을 수 있습니다.

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