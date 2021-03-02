/*
https://programmers.co.kr/learn/courses/30/lessons/64061

���� ����� ���� 2���� �ٱ��Ͽ��� ������ �Ǹ� �����.

������ ���� ������ ���ԵǸ� �ƹ��ϵ� �Ͼ�� ����.

board - ����ȭ���� ������ ���°� ��� 2���� �迭 (5by5�̻� 30by30 ����)
moves - ũ������ �۵���Ų ��ġ�� ��� �迭 (1�̻� 1000������ ũ��.) 

ũ������ ��� �۵���Ų �� ��Ʈ���� ������ ������ return.

������ ����� board�迭�� �� ���ҿ� �ش�.
0~100�� ����̸�, 0�� ��ĭ�� �ǹ��Ѵ�.

moves�迭�� �� ������ ���� 1 �̻�, board�迭�� ����ũ�� ������ ��.


����� ��
board	                                                        moves	            result
[[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]]	[1,5,3,5,1,2,1,4]	4

4���� ������ ������.

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