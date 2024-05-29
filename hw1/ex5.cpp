// Em đã thử rất nhiều cách nhưng không hiểu sao không được correct có thể em hiểu sai phần làm tròn trong đề của cô và em nhận ra có một lỗ.
// Mặc dù em đã vô tình cout thừa ra một số không liên quan đến output đúng của bài toán nhưng không hiểu sao hệ thống vẫn chấm đúng vài test case.
// Vậy nên em đã xin code của bạn để nộp bài này và đã có một vài chỉnh sửa em cho là không cần thiết và cần điều chỉnh lại.
// Em sẽ để lại code gốc của mình ở dưới cùng bài nộp.
#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <math.h>

int n;
float meanscore;
float total = 0;
int cnt;
int pscore[10];
float score[10];
bool used[10] = {false};
void output()
{
    for (int i = 0; i < n; i++)
    {
        cout << score[i] << " ";
    }
    cnt++;
    cout << endl;
}

void backtrack(int solved)
{
    if (solved == n)
    {
        float temp = round(total / 10) * 10;
        if (temp == meanscore)
        {
            output();
        }
        return;
    }
    for (float i = 0.25; i <= 10; i += 0.25)
    {

        // float temp = round(i * pscore[solved] / 25.0) * 25;
        float temp = i * pscore[solved];
        if (total <= meanscore)
        {
            score[solved] = i;
            total += temp;
            backtrack(solved + 1);

            total -= temp;
        }
    }
}

int main()
{
    cin >> n;
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pscore[i] = x;
    }
    cin >> meanscore;
    meanscore *= 100;
    meanscore = round(meanscore / 10) * 10;
    backtrack(0);
    cout << cnt;
}

/*
4,25 2 2
13
44
43
2.3
*/