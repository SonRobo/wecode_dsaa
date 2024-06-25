// #include <iostream>
// #include <algorithm>
// #include <fstream>
// #include <vector>
// using namespace std;

// int binary_search(const vector<pair<pair<int, int>, int>> &subject, int i)
// {
//     int l = 0, r = i - 1;
//     while (l <= r)
//     {
//         int mid = l + (r - l) / 2;
//         if (subject[mid].first.second < subject[i].first.first)
//         {
//             if (mid + 1 <= r && subject[mid + 1].first.second < subject[i].first.first)
//             {
//                 l = mid + 1;
//             }
//             else
//             {
//                 return mid;
//             }
//         }
//         else
//         {
//             r = mid - 1;
//         }
//     }
//     return -1;
// }

// int solve(const vector<pair<pair<int, int>, int>> &subject, int n)
// {
//     vector<long long> f(n);
//     vector<pair<pair<int, int>, int>> sorted_subject = subject;
//     sort(sorted_subject.begin(), sorted_subject.end(), [](const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b)
//          { return a.first.second < b.first.second; });
//     f[0] = sorted_subject[0].second;

//     for (int i = 1; i < n; i++)
//     {
//         long long sum = sorted_subject[i].second;
//         int idx = binary_search(sorted_subject, i);
//         if (idx != -1)
//         {
//             sum += f[idx];
//         }
//         f[i] = max(sum, f[i - 1]);
//     }
//     return f[n - 1];
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n;
//     cin >> n;
//     vector<pair<pair<int, int>, int>> subject(n);
//     for (int i = 0; i < n; ++i)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         subject[i] = make_pair(make_pair(a, b), c);
//     }
//     cout << solve(subject, n) << endl;
//     return 0;
// }

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

// Hàm tìm kiếm nhị phân để tìm đồ án cuối cùng kết thúc trước khi đồ án hiện tại bắt đầu
int binary_search(const vector<pair<pair<int, int>, long long int>> &subject, int i)
{
    int l = 0, r = i - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (subject[mid].first.second < subject[i].first.first)
        {
            if (mid + 1 <= r && subject[mid + 1].first.second < subject[i].first.first)
            {
                l = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        else
        {
            r = mid - 1;
        }
    }
    return -1;
}

// Hàm giải quyết bài toán
long long int solve(const vector<pair<pair<int, int>, long long int>> &subject, int n)
{
    vector<long long int> f(n);
    vector<pair<pair<int, int>, long long int>> sorted_subject = subject;

    // Sắp xếp các đồ án theo ngày kết thúc
    sort(sorted_subject.begin(), sorted_subject.end(), [](const pair<pair<int, int>, long long int> &a, const pair<pair<int, int>, long long int> &b)
         { return a.first.second < b.first.second; });

    // Khởi tạo giá trị đầu tiên của mảng f
    f[0] = sorted_subject[0].second;

    // Tính toán giá trị tối đa có thể đạt được cho mỗi đồ án
    for (int i = 1; i < n; i++)
    {
        long long int sum = sorted_subject[i].second;
        int idx = binary_search(sorted_subject, i);
        if (idx != -1)
        {
            sum += f[idx];
        }
        f[i] = max(sum, f[i - 1]);
    }

    // Trả về giá trị tối đa có thể đạt được
    return f[n - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream input("./input8.txt");
    if (!input)
    {
        cerr << "Unable to open file input.txt";
        exit(1); // call system to stop
    }

    int n;
    input >> n;
    vector<pair<pair<int, int>, long long int>> subject(n);

    // Đọc dữ liệu từ tệp
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        long long int c;
        input >> a >> b >> c;
        subject[i] = make_pair(make_pair(a, b), c);
    }

    input.close();

    // Gọi hàm solve và in kết quả
    cout << solve(subject, n) << endl;
    return 0;
}
