#include <bits/stdc++.h>
using namespace std;

void findingPairOfElement(int ar[], int n, int k) {
        map < int, int > mp;
        for ( int i = 0; i < n-1; i++ ) {

                if ( mp[k-ar[i]] == 1 ) {
                        cout << "( " << ar[i] << ", " << k-ar[i] << " )" << endl;
                        mp[k-ar[i]]--;
                }
                mp[ar[i]]++;
        }
}

int main()
{
        int ar[] = {6, 3, 8, 7, 10, 16, 7, 5, 2, 9, 14};
        int n = sizeof(ar) / sizeof(ar[0]);

        findingPairOfElement(ar, n, 10);

        return 0;
}
