#include <iostream>
#include <cmath>
#include <algorithm>
#define MX 22
using namespace std;
 
struct QUEUE {
    int x, y, dis;
}q[MX*MX];
 
struct SHARK {
    int x, y, k, ate;
}shark;
 
bool com(const QUEUE i, const QUEUE j)
{
    return (i.dis < j.dis) || (i.dis == j.dis && i.y < j.y) || (i.dis == j.dis && i.y == j.y && i.x < j.x);
}
 
int map[MX][MX], numcheck[MX][MX];
int dx[] = { 0, -1, 1, 0 };
int dy[] = { -1, 0, 0, 1 };
int N, M, dab, nx, ny;
 
int bfs()
{
    int st, ed, ix, iy, point, check[MX][MX] = { 0 };
    QUEUE list[MX*MX] = { 0 };
    st = ed = point = -1;
    q[++st].x = shark.x; q[st].y = shark.y; check[shark.y][shark.x] = 1;
 
    while (st != ed)
    {
        ix = q[++ed].x; iy = q[ed].y;
        if (0 < map[iy][ix] && map[iy][ix] < shark.k) { list[++point].x = ix; list[point].y = iy; list[point].dis = check[iy][ix] - 1; }
        for (int i = 0; i < 4; i++)
        {
            nx = ix + dx[i]; ny = iy + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N || check[ny][nx] || map[ny][nx] > shark.k) continue;
            q[++st].x = nx; q[st].y = ny; check[ny][nx] = check[iy][ix] + 1;
        }
    }
    sort(list, list + (point + 1), com);
    shark.x = list[0].x; shark.y = list[0].y;
    return list[0].dis;
}
 
int main(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 9) { shark.k = 2; shark.x = j; shark.y = i; map[i][j] = 0; }
        }
    while (true)
    {
        int dis = bfs();
        if (!dis) break;
        else shark.ate++;
        if (shark.k == shark.ate) { shark.k++; shark.ate = 0; }
        dab += dis;
        map[shark.y][shark.x] = 0;
    }
    cout << dab << endl;
    return 0;
}
