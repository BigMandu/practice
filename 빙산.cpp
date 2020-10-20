/** 빙산은 1년마다 4방향 인접한 0의 갯수만큼 빙산은 녹는다.
 *  한 덩어리의 빙산이 주어졌을때, 두덩어리 이상으로 분리되는 최초의 시간(년)을 구해야함.
 *  전부 다 녹을동안 두덩어리이상 분리되지 않으면, 0을 출력함.
 * 
 * 입력
 * 첫줄 2차원배열 행 /열 N,M  3<= N,M <=300
 * N개의줄 -> 각 줄의 각 행 M개의 정수  0 <= M의크기 <= 10
 *  
 * 전부 입력을 받고, 우선 bfs로 search를 돌린뒤, 인접4방향에 0의 개수를 저장하고,
 * 해당 원소를 0의 개수만큼 깎아. 이걸 쭉 하고,
 * 
 * dfs로 한번더 돌린다. 이때 이 돌리는 개수를 저장해서 덩어리가 떨어지면 땡.
 * 
 * 우선, chk맵을 하나 만들어서 첫 얼음 입력값을 전부 입력.
 * bfs에서 search할때 그 위치의 chk맵에 1(얼음)이 없어졌다면 거기서 땡 dfs에 돌린 값 + 1을 해줘서 넘겨주면 될듯.
 **/
#include <iostream>
#define MAX 305
using namespace std;

int map[MAX][MAX];
int prevmap[MAX][MAX];
bool chkmap[MAX][MAX];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void input(int r, int c)
{
    for(int i=0; i < r; i++)
    {
        for(int j=0; j < c; j++)
        {
            cin >> map[i][j];
        }
    }
}

void search(int x, int y, int N, int M)
{
    chkmap[x][y] = true;

    for(int i = 0; i < 4; i++)
    {
        int nr = x + dr[i];
        int nc = y + dc[i];

        if( 1 <= nr && nr < N-1 && 1<= nc && nc < M-1)
        {
            if(map[nr][nc] && chkmap[nr][nc] == false)
            {
                search(nr,nc,N,M);
            }
        }
    }
}

int melt(int r, int c)
{
    int zerocnt = 0;
    for(int i = 0; i < 4; i++)
    {
        int nr = r+dr[i];
        int nc = c+dc[i];

        if(prevmap[nr][nc] == 0)
        {
            zerocnt++;
        }
    }
    return zerocnt;;
}

void solve(int r, int c)
{
    bool flag = false;
    int year = 0;
    while(1)
    {
        fill(chkmap[0], chkmap[0]+MAX*MAX, 0);
        fill(prevmap[0], prevmap[0]+MAX*MAX, 0);

        int cnt = 0;

        for(int i = 1; i < r-1; i++)
        {
            for(int j = 1; j < c-1; j++)
            {
                if(map[i][j] != 0 && chkmap[i][j] != true)
                {
                     cnt++;
                    search(i,j, r, c);
                }
            }
        }
        if(cnt >= 2)
        {
            cout << year <<endl;
            break;
        }
        if(cnt == 0)
        {
            year = 0;
            cout << year <<endl;
            break;
        }


        for(int i = 0; i< r; i++)
        {
            for(int j = 0; j< c; j++)
            {
                if(map[i][j] != 0)
                {
                    prevmap[i][j] = map[i][j] - melt(i,j);
                    if(prevmap[i][j] <= 0)
                    {
                        prevmap[i][j] = 0;
                    }
                }
            }
        }

        for(int i= 0; i<r; i++)
        {
            for(int j= 0; j<c; j++)
            {
                map[i][j] = prevmap[i][j];
            }
        }
        year++;
    }
    //cout << year <<endl;
}

int main()
{
    int N, M;
    cin >> N >> M;
    input(N, M);
    solve(N, M);
}