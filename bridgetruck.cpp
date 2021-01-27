/*

https://programmers.co.kr/learn/courses/30/lessons/42583

bridge_length = 2, weight = 10 , [7 4 5 6]

��� �ð�	�ٸ��� ���� Ʈ��	�ٸ��� �ǳʴ� Ʈ��	��� Ʈ��
0	        []	                []	                [7,4,5,6]
1~2	        []              	[7]             	[4,5,6]
3	        [7]                	[4]             	[5,6]
4       	[7]             	[4,5]           	[6]
5           [7,4]           	[5]             	[6]
6~7     	[7,4,5]         	[6]             	[]
8       	[7,4,5,6]       	[]              	[]


solution �Լ��� �Ű������� 
�ٸ� ���� bridge_length, 
�ٸ��� �ߵ� �� �ִ� ���� weight, 
Ʈ���� ���� truck_weights�� �־����ϴ�. 

�̶� ��� Ʈ���� �ٸ��� �ǳʷ��� �ּ� �� �ʰ� �ɸ����� return �ϵ��� solution �Լ��� �ϼ��ϼ���.


*/

#include <string>
#include <vector>
#include <queue>
using namespace std;

void CheckCrossingBridge(int bdlength, int &OnWeight, queue<int>&que)
{
    if(que.size() == bdlength)
    {
        OnWeight -= que.front();
        que.pop();
    }
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int OnbridgeWeight = 0;
    int loop = 0;
    queue<int>q;

    while(true)
    {
        if(loop == truck_weights.size())
        {
            answer += bridge_length;
            break;
        }

        CheckCrossingBridge(bridge_length, OnbridgeWeight, q);

        answer++;

        if(OnbridgeWeight + truck_weights[loop] <= weight)
        {
            OnbridgeWeight += truck_weights[loop];
            q.push(truck_weights[loop]);
            loop++;
        }
        else
        {
            q.push(0); //0�� Ǫ�������� Ʈ���� �ٸ������� ������.
        }
    }

    return answer;
}

/* 
 Ʈ���� �Ѵ볻�������� �ٷ� ����Ʈ���� �ø� �� �ִ��� �Ǵ� �ؾ� �ϱ� ������. �������� ��ǰ.

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int Onbridgeweight=0;
    int truckcnt = 0;
    int tottruckcnt = 0;
    bool bcheck = false;
    queue<int>q;

    for(int i=0;i<truck_weights.size();i++)
    {
       q.push(truck_weights[i]);
    }

    while(true)
    {
        if((!q.empty() && (Onbridgeweight + q.front() < weight)) || bcheck)
        {
            truckcnt++;
            tottruckcnt++;
            bcheck = false;
            Onbridgeweight += q.front();
            q.pop();
            if(q.empty()) continue;

            if(Onbridgeweight + q.front()<= weight)
            {
                bcheck = true;
            }
        }
        else
        {
            if(truckcnt >= 2)
            {
                answer += bridge_length + truckcnt;
            }
            else
            {
                answer += bridge_length;
            }
            bcheck = false;
            truckcnt = 0;
            Onbridgeweight = 0;
            if(q.empty())
            {
                if(tottruckcnt == 1)
                {
                    answer++;
                }
                break;
            } 
        }
    }
   
    

    return answer;
}
*/


int main()
{
    vector<int>invec;
    int sol;
    int bdlength;
    int bdweight;

    scanf("%d",&bdlength);
    scanf("%d",&bdweight);

    for(int i=0; i<100;i++)
    {
        int input = 0;
        scanf("%d",&input);
        if(input < 0) break;
        invec.push_back(input);
    }

    sol = solution(bdlength, bdweight, invec);

    printf("%d",sol);
}