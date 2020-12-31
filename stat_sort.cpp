#include <iostream>
#include <cmath>
using namespace std;

double mean(double arr[], double size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum / size;
}

double variance(double arr[], int size)
{
    double total = 0;
    double average = mean(arr, size);
    for (int i = 0; i < size; i++)
    {
        total += pow((average - arr[i]), 2);
    }
    return total / size;
}

double stddev(double arr[], int size)
{
    return sqrt(variance(arr, size));
}

double stderror(double arr[], int size)
{
    return (stddev(arr, size) / sqrt(size));
}

int factorial(int x)
{
    if (x == 0)
    {
        return 1;
    }
    else
    {
        return x * factorial(x - 1);
    }
}

int combination(int n, int k)
{
    return factorial(n) / (factorial(k) * (factorial(n - k)));
}

double *insertionSort(double arr[], int size)
{
    double *p = new double[size];

    for (int i = 0; i < size; i++)
    {
        p[i] = arr[i];
    }

    for (int i = 0; i < size - 1; i++)
    {

        if (p[i + 1] < p[i])
        {
            swap(p[i], p[i + 1]);
        }

        for (int x = i; x > 0; x--)
        {
            if (p[x] < p[x - 1])
            {
                swap(p[x], p[x - 1]);
            }
        }
    }

    return p;
}

double max(double arr[], int size)
{
    double max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

double min(double arr[], int size) //Better use this woithout the helper sort function because that would be O(n^2) while this is only O(n)
{
    double min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

double median(double arr[], int size) //Works on its own without BoxWhisker function
{

    double med = 0;
    double *p = insertionSort(arr, size);

    if (size % 2 != 0)
    {
        med = p[size / 2];
    }
    else
    {
        med = (p[size / 2] + p[(size / 2) - 1]) / 2;
    }
    return med;
}

void BoxWhisker(double arr[], int size)
{
    double *p = insertionSort(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;

    double med = median(p, size);
    cout << "Median: " << med << endl;

    double q1 = 0;
    q1 = median(p, size / 2);
    cout << "Q1: " << q1 << endl;

    double q3 = 0;
    int s = size / 2;
    double arr2[s];
    if (size % 2 != 0) //odd
    {
        for (int i = 0; i < s; i++)
        {
            arr2[i] = p[s + i + 1];
        }
    }
    else //even
    {
        for (int i = 0; i < s; i++)
        {
            arr2[i] = p[s + i];
        }
    }
    q3 = median(arr2, s);
    cout << "Q3: " << q3 << endl;

    double IQR = 0;
    IQR = q3 - q1;
    cout << "IQR: " << IQR << endl;
}

double binomialRandomVariable(double n, double x, double p)
{
    return combination(n, x) * pow(p, x) * pow((1 - p), (n - x));
}

int main()
{
    double nums[20] = {21, 98, 5, 55, 12, 76, 8, 11, 98, 3, 21, 4, 12, 5, 30, 10, 17, 6, 9, 51};
    BoxWhisker(nums, 20);
    //cout << combination(7, 3) << endl;
    //cout << min(nums, 20) << endl;
    //cout << binomialRandomVariable(12, 8, .6) << endl;
    //cout << median(nums, 21) << endl;
    //cout << Q1(nums, 21) << endl;
}