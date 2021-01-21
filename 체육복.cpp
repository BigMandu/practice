#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

/*
n	lost	reserve	    return
5	[2, 4]	[1, 3, 5]	5
5	[2, 4]	[3]	        4
3	[3]	    [1]     	2
5   [1, 2]  [2, 3, 5]   4 // 3이 2에게 주고, 2는 기존껄 1한테 주면 5인데?
*/

/*
0   1   2   3   4
    +1  -1  +1  -1  
*/

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    vector<int> vec(n,0);

    for(int i=0;i<n;i++)
    {
        if(i<lost.size())
        {
            vec[lost[i]-1] -=1;
        }
        if(i<reserve.size())
        {
            vec[reserve[i]-1] +=1;
        }
    }
    
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i] == -1)
        {
            if(i-1>=0)
            {
                if(vec[i-1] == 1)
                {
                    vec[i-1] -=1;
                    vec[i] +=1;
                    continue;
                }
            }
            if (i+1<vec.size())
            {
                if(vec[i+1] ==1)
                {
                    vec[i+1] -=1;
                    vec[i] +=1;
                }
            }
        }
    }

    for(int i=0;i<vec.size();i++)
    {
        if(vec[i] == -1)
        {
            continue;
        }
        else
        {
            answer++;
        }
    }

    return answer;
}


int main()
{
    vector<int> inlost;
    vector<int> inreserve;
    int n;
    
    scanf("%d", &n);

    for(int i=0; i<n;i++)
    {
        int input = 0;
        scanf("%d ",&input);
        if(input == -1) break;
        inlost.push_back(input);
    }

    for(int i=0; i<n;i++)
    {
        int input=0;
        scanf("%d ",&input);
        if(input == -1) break;
        inreserve.push_back(input);
    }

    printf("%d",solution(n, inlost, inreserve));
}