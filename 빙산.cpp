/** ������ 1�⸶�� 4���� ������ 0�� ������ŭ ������ ��´�.
 *  �� ����� ������ �־�������, �ε�� �̻����� �и��Ǵ� ������ �ð�(��)�� ���ؾ���.
 *  ���� �� �������� �ε���̻� �и����� ������, 0�� �����.
 * 
 * �Է�
 * ù�� 2�����迭 �� /�� N,M  3<= N,M <=300
 * N������ -> �� ���� �� �� M���� ����  0 <= M��ũ�� <= 10
 *  
 * ���� �Է��� �ް�, �켱 bfs�� search�� ������, ����4���⿡ 0�� ������ �����ϰ�,
 * �ش� ���Ҹ� 0�� ������ŭ ���. �̰� �� �ϰ�,
 * 
 * dfs�� �ѹ��� ������. �̶� �� ������ ������ �����ؼ� ����� �������� ��.
 * 
 * �켱, chk���� �ϳ� ���� ù ���� �Է°��� ���� �Է�.
 * bfs���� search�Ҷ� �� ��ġ�� chk�ʿ� 1(����)�� �������ٸ� �ű⼭ �� dfs�� ���� �� + 1�� ���༭ �Ѱ��ָ� �ɵ�.
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