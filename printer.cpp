/*
https://programmers.co.kr/learn/courses/30/lessons/42587

priorities	        location	return
[2, 1, 3, 2]	    2	        1
[1, 1, 9, 1, 1, 1]	0	        5

우선순위 = 값이 클수록 높음.
Location은 0부터 시작함.
location에 위치한 문서의 인쇄 순서를 리턴하는것.

*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>>q;
    priority_queue<int,vector<int>, less<int>> pq;

    for(int i = 0;i<priorities.size();i++)
    {
        q.push(make_pair(i,priorities[i]));
        pq.push(priorities[i]);
    }

    while(!q.empty())
    {
        if(q.front().second == pq.top())
        {
            if(q.front().first == location)
            {
                answer++;
                break;
            }
            else
            {
                q.pop();
                pq.pop();
                answer++;
            }
        }
        else
        {
            q.push(q.front());
            q.pop();
        }
    }

    return answer;
}

int main()
{
    vector<int> inprice;
    int sol;
    
    for(int i=0; i<100;i++)
    {
        int input = 0;
        scanf("%d",&input);
        if(input < 0) break;
        inprice.push_back(input);
    }

    int input = 0;
    scanf("%d",&input);

    sol = solution(inprice, input);

    printf("%d",sol);
}