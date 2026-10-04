// 1. Lucky Number Using Prime and Composite Numbers
//    - Given N numbers:
//      - calculate sum of prime numbers,
//      - calculate sum of composite numbers.
//    - Then:Lucky Number = Sum of Primes - Sum of Composite Numbers


#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    int compositeSum = 0;
    int primeSum = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++)
    {
        // 0 and 1 are neither prime nor composite
        if(arr[i] <= 1)
        {
            continue;
        }

        bool isPrime = true;

        for(int j = 2; j * j <= arr[i]; j++)
        {
            if(arr[i] % j == 0)
            {
                isPrime = false;
                break;
            }
        }

        if(isPrime)
        {
            primeSum += arr[i];
        }
        else
        {
            compositeSum += arr[i];
        }
    }

    cout << primeSum - compositeSum;

    return 0;
}