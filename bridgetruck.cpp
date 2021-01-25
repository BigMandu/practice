/*

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

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int Onbridgeweight=0;
    bool bcheck = false;
    queue<int>q;

    for(int i=0;i<truck_weights.size();i++)
    {
       q.push(truck_weights[i]);
    }

    while(!q.empty())
    {
        if(Onbridgeweight + q.front() < weight)
        {
            Onbridgeweight += q.front();
            q.pop();
            if(bcheck)
            {
                answer += 1;
                bcheck = false;
            }
            
            if(Onbridgeweight + q.front()<= weight)
            {
                bcheck = true;
            }
        }
        else
        {
            Onbridgeweight = 0;
            answer += bridge_length;
        }
    }
    //answer += bridge_length + 1;

    return answer;
}

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