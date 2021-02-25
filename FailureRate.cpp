/*
https://programmers.co.kr/learn/courses/30/lessons/42889


실패율 정의
- 스테이지에 도달했으나, 아직 클리어하지 못한 플레이어의 수 / 스테이지에 도달한 플레이어 수

( 1<= N <=50  // 1 <= 배열length <=200000
    1 <= 배열요소 <=N+1 의 자연수가 담김 (N+1인 경우 N번째 스테이지 까지 클리어한 사용자임.)
)

N - 전체 스테이지 수
배열 - 게임을 이용하는 사용자가 현재 멈춰있는 스테이지의 번호들.

실패율이 높은 스테이지부터 내림차 순으로 스테이지의 번호를 담은 배열을 return.

- 실패율이 같은 stage가 있다면, 작은 번호의 stage가 먼저 오도록 한다.
- 스테이지에 도달한 유저가 없는 경우, 실패율은 0으로 정의.

N	stages	                    result
5	[2, 1, 2, 6, 2, 4, 3, 3]	[3,4,2,1,5]
4	[4,4,4,4,4]	                [4,1,2,3]

*/
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool custom(pair<double,int> cur, pair<double,int> nex)
{
    if(cur.first == nex.first)
    {
        return cur.second  < nex.second;
    }
    else return cur.first > nex.first;
}

vector<int> solution(int N, vector<int> stages) 
{
    vector<int> answer;
    vector<pair<double,int>> save;

    save.resize(N+1);

    for(int x : stages) //플레이어 집어넣기
    {
        if(x == N+1) continue;

        save[x].first += 1;
    }

    for(int i = 0; i<save.size(); i++) //도달플레이어 집어넣기
    {
        if(i != 0 && save[i].second == 0)
        {
            if(i == 1)
            {
                save[i].second = stages.size();
            }
            else
            {
                save[i].second = save[i-1].second - save[i-1].first;
            }
        }
    }

    for(int i = 0; i<save.size(); i++) //실패율 계산
    {
        if(save[i].first != 0)
        {
            save[i].first = save[i].first / save[i].second;
        }
        save[i].second = i;
    }

    sort(save.begin(), save.end(),custom); //정렬

    for(int i = 0; i<save.size(); i++) //스테이지 넣기
    {
        if(save[i].second == 0) continue;
        answer.push_back(save[i].second);
    }

    return answer;
}

int main()
{
    int N;
    vector<int>vec;

    N = 4;
    vec = {4,4,4,4,4};

    vec = solution(N,vec);

    for(int x : vec)
    {
        cout << x;
    }
}