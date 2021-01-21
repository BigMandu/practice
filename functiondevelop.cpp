
/*
https://programmers.co.kr/learn/courses/30/lessons/42586

progresses	                speeds	            return
[93, 30, 55]	            [1, 30, 5]	        [2, 1]
[95, 90, 99, 99, 80, 99]	[1, 1, 1, 1, 1, 1]	[1, 3, 2]
*/

//7 4 9
//5 10 1 1 20 1

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    int pop=0;
    int cnt = 0;

    for(int i=0; i<progresses.size(); i++)
    {
        int temp = 0;
        int x = (100-progresses[i])/speeds[i];
        if((double)(100-progresses[i])/speeds[i] == x)
        {
            temp = x;
        }
        else
        {
            temp =  x+1;
        }
        q.push(temp);
    }

    while(!q.empty())
    {
        if(pop == 0)
        {
            pop = q.front();
        }

        if(pop >= q.front())
        {
            q.pop();
            cnt++;
        }
        else
        {
            answer.push_back(cnt);
            cnt = 0;
            pop = 0;
        }
    }
    answer.push_back(cnt);
    
    return answer;
}

int main()
{
    vector<int> inprogress;
    vector<int> inspeed;
    vector<int>answer;
    
    for(int i=0; i<100;i++)
    {
        int input = 0;
        scanf("%d",&input);
        if(input == -1) break;
        inprogress.push_back(input);
    }

    for(int i=0; i<100;i++)
    {
        int input = 0;
        scanf("%d",&input);
        if(input == -1) break;
        inspeed.push_back(input);
    }


    answer = solution(inprogress, inspeed);

    for(int i=0; i<answer.size();i++)
    {
        printf("%d",answer[i]);
    }
}