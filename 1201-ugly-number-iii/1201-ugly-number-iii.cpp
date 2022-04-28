typedef long long ll;
class Solution {
public:
    ll lcm(ll a, ll b) {
        return a*b / __gcd(a, b);
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        long long l=1;
        long long h=2000000000;
        ll N = (ll)n, A = ll(a), B = ll(b), C = ll(c);
        ll ans;
        while(l<=h){
            ll m = l + (h - l)/2;
            ll cnt = 0;
            cnt += m/A;
            cnt += m/B;
            cnt += m/C;
            cnt -= m / lcm(A, B);
            cnt -= m / lcm(B, C);
            cnt -= m / lcm(C, A);
            cnt += m / lcm(A, lcm(B, C));
            
            if(cnt>=N){
            ans=m;
            h=m-1;
            }
            else{
            l=m+1;
            }
            
        }
        return ans;
    }
};