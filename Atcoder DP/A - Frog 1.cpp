/*      ॐ       */
#ifndef LOCAL
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#endif

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define float long double
#define ff first
#define ss second

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

using vint = vector<int>;
using vchar = vector<char>;
using vpairint = vector<pair<int, int>>;

//  1> sqrtl function for long dobule
//  2> digitwise thinking
//  3> static_cast<char>(x[0] - 1)
//  4> If sum doesn't exceed 1e5 just consider it as 1 test case in which temp is 1e5
//  5> Every problem i practice is like contest
//  6> In circle if iam increamenting some x from pos and after some opern i
//      get at satrting point and then again doing those operations is reptition of steps.  And to get back do moudlo
// 7> greatest integer that can't be there is (m-1)*(n-1)- 1
// total integers that cant be there is (m-1)*(n-1)/2
//
int power(int a, int b, int d)
{
    int res = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            res = ((res % d) * (a % d)) % d;
            b--;
        }
        b = b / 2;
        a = (a * a) % d;
    }
    return res;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int fact(int num)
{
    int res = 1;

    for (int i = 1; i <= num; i++)

        res = (res * i) % MOD;

    return res;
}
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
vint pri_factors(int x)
{
    vint factors;
    int temp = x;
    for (int i = 2; i <= sqrtl(x); i++)
    {
        while (temp % i == 0)
        {
            temp /= i;
            factors.push_back(i);
        }
    }
    if (temp > 1)
        factors.push_back(x);
    return factors;
}

bool isprime(int temp)
{
    if (temp == 1)
        return false;
    for (int i = 2; i <= sqrtl(temp); i++)
    {
        if (temp % i == 0)
            return false;
    }
    return true;
}
void fill(vector<bool> &sv)
{
    int temp = sv.size() - 1;
    for (int i = 2; i <= sqrtl(temp); i++)
    {
        for (int j = 2 * i; j <= temp; j = j + i)
        {
            sv[j] = 0;
        }
    }
}
bool comp(pair<int, int> &a,
          pair<int, int> &b)
{
    if (a.first > b.first)
        return true;
    else if (a.first == b.first)
    {
        if (a.second > b.second)
            return true;
        else
            return false;
    }
    else
        return false;
}

void print(vint &v)
{
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << '\n';
}
int func(int x)
{
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x ^ (x >> 1);
}

// change approach may be

void solve()
{
    int n;
    cin>>n;

    vint v(n);
    for(int i=0 ;i<n ; i++){
        cin>>v[i];
    }

    vint dp(n,-1);
    dp[n-1] = 0;
    dp[n-2] = abs(v[n-1] - v[n-2]);

    for(int i=n-3 ; i>=0 ; i--){
        dp[i] = min( {dp[i+1] + abs(v[i+1] - v[i]) ,  dp[i+2] + abs(v[i+2] - v[i])});
    } 
    cout<<dp[0]<<'\n';
}

// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
signed main()
{
    std::ios::sync_with_stdio(0);
#ifdef ONLINE_JUDGE
    std::cin.tie(0);
#endif

    int T = 1;
    // cin >> T;

    while (T--)
    {
        solve();
    }
    return 0;
}