#include <cstdio>

#include <iostream>

using namespace std;



int sum(int m)

{

if (m == 1) return 1;

int ans = 0;

for (int i = m/2; i >= 1; i--) ans += sum(i);

return ans+1;

} 



int main()

{

int read;

cin >> read;

cout << sum(read);

return 0;

} 


