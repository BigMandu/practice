/*
https://programmers.co.kr/learn/courses/30/lessons/64061

같은 모양의 인형 2개가 바구니에서 만나게 되면 사라짐.

인형이 없는 곳에서 집게되면 아무일도 일어나지 않음.

board - 게임화면의 격자의 상태가 담긴 2차원 배열 (5by5이상 30by30 이하)
moves - 크레인을 작동시킨 위치가 담긴 배열 (1이상 1000이하의 크기.) 

크레인을 모두 작동시킨 후 터트려진 인형의 개수를 return.

인형의 모양은 board배열의 각 원소에 해당.
0~100이 모양이며, 0은 빈칸을 의미한다.

moves배열의 각 원소의 값은 1 이상, board배열의 가로크기 이하의 값.


입출력 예
board	                                                        moves	            result
[[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]]	[1,5,3,5,1,2,1,4]	4

4개의 인형이 터졌다.

*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) 
{
    int answer = 0;
    vector<int> temp;

    for(int i =0; i<moves.size(); i++)
    {
        for(int x = 0; x<board.size();x++)
        {
            int doll = board[x][moves[i]-1];
            if(doll == 0)
            {
                continue;
            }
            else
            {
                if(temp.size() && temp.back() == doll)
                {
                    temp.pop_back();
                    answer+=2;
                }
                else
                {
                    temp.push_back(doll);
                }
                board[x][moves[i]-1] = 0;
                break;
            }
        }
    }
    

    return answer;
}

int main()
{
    vector<vector<int>> machine;
    vector<int> crane;
    int sol;

    machine = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
    crane = {1,5,3,5,1,2,1,4};

    sol = solution(machine,crane);

    printf("%d",sol);
}