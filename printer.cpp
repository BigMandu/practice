/*
https://programmers.co.kr/learn/courses/30/lessons/42587

priorities	        location	return
[2, 1, 3, 2]	    2	        1
[1, 1, 9, 1, 1, 1]	0	        5

�켱���� = ���� Ŭ���� ����.
Location�� 0���� ������.
location�� ��ġ�� ������ �μ� ������ �����ϴ°�.

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