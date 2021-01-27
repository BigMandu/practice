/*
https://programmers.co.kr/learn/courses/30/lessons/42748

array	                commands	                        return
[1, 5, 2, 6, 3, 7, 4]	[[2, 5, 3], [4, 4, 1], [1, 7, 3]]	[5, 6, 3]

배열 array의 i번째 숫자부터 j번째 숫자까지 자르고 정렬했을 때, k번째에 있는 수를 구하려 합니다.

*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) 
{
    vector<int> answer;
    vector<int> tmpvec;

    for(int loop = 0; loop < commands.size(); loop++)
    {
        int i = commands.at(loop).at(0) -1;
        int j = commands.at(loop).at(1) -1;
        int k = commands.at(loop).at(2) -1;

        for(int insert = i; insert <= j; insert++)
        {
            tmpvec.push_back(array[insert]);
        }
        sort(tmpvec.begin(),tmpvec.end(), less<int>());

        answer.push_back(tmpvec[k]);

        tmpvec.erase(tmpvec.begin(),tmpvec.end());
    }

    return answer;
}

int main()
{
    vector<int> sol;
    
    vector<int> inarray;
    vector<vector<int>>incomm;

    printf("--input array--\n");
    for(int i=0; i<30; i++)
    {
        int input = 0;
        scanf("%d",&input);
        if(input < 0) break;
        inarray.push_back(input);
    }

    printf("--input commands--\n");
    for(int i=0;i<50;i++)
    {
        int input = 0;
        incomm.push_back(vector<int>());
        for(int j=0;j<3;j++)
        {
            scanf("%d",&input);
            if(input<0) break;
            incomm[i].push_back(input);
        }
        if(input<0)
        {
            incomm.resize(i);
            break;
        } 
    }

    // inarray = {1, 5, 2, 6, 3, 7, 4 };
    // incomm = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
    
    sol = solution(inarray, incomm);

    for(int x : sol)
    {
        printf("%d ",x);
    }
}