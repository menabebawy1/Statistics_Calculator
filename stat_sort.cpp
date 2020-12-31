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

double* insertionSort(double arr[], int size)
{
    double *p = new double[size];

    for (int i = 0 ; i < size; i++){
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

double min(double arr[], int size)
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

double median(double arr[], int size){
    double *p = insertionSort(arr, size);
    for(int i = 0; i < size; i++){
        cout << p[i] << " ";
    }
    cout << endl;
    delete p;
    p = nullptr;
}

void BoxWhisker(double arr[], int size)
{
}

double binomialRandomVariable(double n, double x, double p)
{
    return combination(n, x) * pow(p, x) * pow((1 - p), (n - x));
}

int main()
{
    double nums[20] = {9, 2, 5, 4, 12, 7, 8, 11, 9, 3, 7, 4, 12, 5, 4, 10, 9, 6, 9, 4};
    //cout << combination(7, 3) << endl;
   // cout << min(nums, 20) << endl;
    //cout << binomialRandomVariable(12, 8, .6) << endl;
   cout << median(nums, 20) << endl;
    
}