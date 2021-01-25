/*

bridge_length = 2, weight = 10 , [7 4 5 6]

경과 시간	다리를 지난 트럭	다리를 건너는 트럭	대기 트럭
0	        []	                []	                [7,4,5,6]
1~2	        []              	[7]             	[4,5,6]
3	        [7]                	[4]             	[5,6]
4       	[7]             	[4,5]           	[6]
5           [7,4]           	[5]             	[6]
6~7     	[7,4,5]         	[6]             	[]
8       	[7,4,5,6]       	[]              	[]


solution 함수의 매개변수로 
다리 길이 bridge_length, 
다리가 견딜 수 있는 무게 weight, 
트럭별 무게 truck_weights가 주어집니다. 

이때 모든 트럭이 다리를 건너려면 최소 몇 초가 걸리는지 return 하도록 solution 함수를 완성하세요.


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