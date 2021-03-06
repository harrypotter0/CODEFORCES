#pragma GCC optimize("O3", "unroll-loops")
// God Help me !!
#include <bits/stdc++.h>
using namespace std;
// #define watch(x) cout << (#x) << " is " << (x) << endl
 
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define RANDOM srand(time(nullptr))
#define int long long
#define sz(a) (int)a.size()
#define rep(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define sep(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(),a.end()
#define x first
#define y second
#define endl "\n"
#define n6 3000005
#define n3 3005
#define n5 300005
 
#define pi pair<int,int>
#define pii pair<int,pi>
 
#define dbg1(x)                cout << #x << ": " << x << endl;
#define dbg2(x, y)             cout << #x << ": " << x << " | " << #y << ": " << y << endl;
#define dbg3(x, y, z)          cout << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define dbg4(a, b, c, d)       cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define dbg5(a, b, c, d, e)    cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define dbg6(a, b, c, d, e, f) cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
 
#define dbg(...) fprintf(stderr, __VA_ARGS__)
#define dbgv(x) cout << #x << " = " << x << endl
#define dbga(arr, len) {cout << #arr << " = "; for (int _ = 0; _ < len; _++)\
cout << arr[_] << " "; cout << endl;}
#define dbgi(it) {cout << #it << " = "; for (const auto& _ : it)\
cout << _ << " "; cout << endl;}
 
const int md = (int) 1e9 + 7;
 
inline void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}
 
inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += md;
}
 
inline int mul(int a, int b) {
  return (int) ((long long) a * b % md);
}
 
inline int power(int a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}


const int k = 25;
const int N = 1e5;
const int ZERO = 0; // gcd(ZERO, x) = gcd(x, ZERO) = x (for any x > 0)

int table[N][k + 1]; // k + 1 because we need to access table[r][k]
int arr[N];

int main()
{
    int n, L, R, q;
    cin >> n; // array size
    for(int i = 0; i < n; i++)
        cin >> arr[i]; // between 1 and 10^9

    // build Sparse Table
    for(int i = 0; i < n; i++)
        table[i][0] = arr[i];
    for(int j = 1; j <= k; j++) {
        for(int i = 0; i + (1 << j) <= n ; i++)
            table[i][j] = __gcd(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
    }

    cin >> q; // number of queries
    for(int i = 0; i < q; i++) {
        cin >> L >> R; // boundaries of next query, 0-indexed
        int answer = ZERO;
        for(int j = k; j >= 0; j--) {
            if(L + (1 << j) - 1 <= R) {
                answer = __gcd(answer, table[L][j]);
                L += 1 << j; // instead of having L', we increment L directly
            }
        }
        cout << answer << endl;
    }
    return 0;
}