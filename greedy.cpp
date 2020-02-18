#include <iostream>

using namespace std;

int main(void) {
    int n; // 거스름돈의 양
    int result = 0;

    cin >> n;

    result = result + (n/500); // 몫의 양만큼 result에 더해줌 
    n = n%500;

    result = result + (n/100); // 몫의 양만큼 result에 더해줌 
    n = n % 100;

    result = result + (n/50); // 몫의 양만큼 result에 더해줌 
    n = n % 50;

    result += n/10; // 몫의 양만큼 result에 더해줌 

    cout << result;
    
    return 0;
}