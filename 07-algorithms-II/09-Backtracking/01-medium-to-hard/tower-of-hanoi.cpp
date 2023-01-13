// https://practice.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1
#include<bits/stdc++.h>
using namespace std;

/// INSTRUCTOR NOTES ///
/*
Without WHAT-not-HOW recursive thinking, understanding below code can take hours and days

let towerOfHanoi(n, from_rod, to_rod, aux_rod)
	a function that print how to take the top n items from 'from_rod' and move them to 'to_rod', utilizing 'aux_rod'

The idea is well presented here: https://www.includehelp.com/data-structure-tutorial/images/tower-of-hanoi-1.png

	Say n = 5: we want to move from A to B, using C
		[5,4,3,2,1]  []  []
	First, take the top n=4 disks and move from A to C
	Now we have: [5]  []   [4,3,2,1]
	Now move 5 from A to B
	Now we have: []  [5]   [4,3,2,1]
	Now move the 4 disks from C to B
	[] [5,4,3,2,1]  []

	Both these moves can be coded based on the function definition as:
		towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
		towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);

If you get your self in step by step thinking/moving = you will get LOST
------------------------------------

Let T(n) = number of steps of this code
	From the code we see, the code recursively calls itself with n-1
	So T(n)   = 2 * T(n-1) + 1
	   T(n-1) = 2 * T(n-2) + 1

	   Then
	   T(n)   = 2 * [2 * T(n-2) + 1] + 1
	   Keep expanding to reach
	   T(n) =   2^(n-1) + 2^(n-2) + 2^(n-3) .... + 1
	   	   which is known as 2^n  -1
	   	   https://math.stackexchange.com/questions/22599/how-to-prove-a-formula-for-the-sum-of-powers-of-2-by-induction


https://www.youtube.com/watch?v=kJeaLssB16A
 */

long long steps = 0;
long long toh(int N, int from, int to, int aux) {
    if(N == 0)
        return steps;

    toh(N-1, from, aux, to);
    cout << "move disk " << N << " from rod " << from << " to rod " << to << "\n";
    toh(N-1, aux, to, from);

    ++steps;
    return steps;
}

int main() {

    return 0;
}
