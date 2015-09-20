#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

#define ll long long

/*
	1 will always be at the position (n*(n+1)/2 + 1), for n = 0, 1, 2 and so on.
	n*(n+1)/2 is just the sum of the first n numbers. Since each 10^i contributes i 
	digits, there will be n*(n+1)/2 digits upto 10^n. Therefore n*(n+1)/2 + 1 will be a 1.

	So the idea is to just check whether k = n*(n+1)/2 + 1 for any n.
	Binary search is the programmer's way to look for such k, since it avoids any mathematics 
	that might be needed for solving such an equation. Look up binary search somewhere if you need to,
	but the idea is quite simple.

	Another thing that you might notice in the code is the line : m = (l+r) >> 1.
	It is essentially m = (l+r)/2, but I thought this way you could learn something new.
	Try and figure out why the two statements are the same. >> is a bit right-shift operator. 
	Look that up too if needed.
*/

int main() {
	ll n, k;
	cin >> n;
	while (n--) {
		int ans = 0;
		cin >> k;
		ll l = 0, r = pow(2,31);
		while (l <= r) {
			ll m = (l+r) >> 1;
			// printf("l = %lld, m = %lld, r = %lld\n", l, m, r);
			// It always helps to print l, m, and r when implementing binary search. Its a tricky algorithm
			// to get correct the first time :|
			if (m*(m+1) == 2*(k-1)) {
				ans = 1;
				break;
			}
			else if (m*(m+1) < 2*(k-1)) 
				l = m+1;
			else
				r = m-1;		
		}
		cout << ans << ' ';
	}
	return 0;
}