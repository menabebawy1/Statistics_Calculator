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

    double min = p[0];
    double max = p[size - 1];

    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;

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

    double range = 0;
    range = max - min;
    cout << "Range: " << range << endl;

    cout << endl;

    for (int i = round(min); i <= round(max); i++)
    {
        if (i == min || ((min < i + 1) && (min > i)))
        {
            cout << " --- MIN: " << min << " ---" << endl;
        }
        else if (i == q1 || ((q1 < i + 1) && (q1 > i)))
        {
            cout << " --- Q1 : " << q1 << " ---" << endl;
        }
        else if (i == med || ((med < i + 1) && (med > i)))
        {
            cout << " --- MED: " << med << " ---" << endl;
        }
        else if (i == q3 || ((q3 < i + 1) && (q3 > i)))
        {
            cout << " --- Q3 : " << q3 << " ---" << endl;
        }
        else if (i == max || ((max < i + 1) && (max > i)))
        {
            cout << " --- MAX: " << max << " ---" << endl;
        }
        else if (i > q1 && i < q3 && i < 10)
        {
            cout << "|      " << i << "        |" << endl;
        }
        else if (i > q1 && i < q3)
        {
            cout << "|      " << i << "       |" << endl;
        }
        else if (i < max)
        {
            cout << "       " << i << "        " << endl;
        }
    }

    cout << endl;
}

double probabilityOR(double a, double b)
{
    return a + b - (a * b);
}

double binomialRandomVariable(double n, double x, double p)
{
    return combination(n, x) * pow(p, x) * pow((1 - p), (n - x));
}
double meanRandomVariable(double n, double p)
{
    return n * p;
}
double varianceRandomVariable(double n, double p)
{
    return meanRandomVariable(n,p)*(1-p);
}


int main()
{
    double nums[21] = {2, 4, 6, 8, 10, 41.2, 14, 43.3, 18, 16.7, 45.5, 22, 24, 22.6, 28, 30, 19.45, 34, 36, 38, 40};
    BoxWhisker(nums, 21);
    //cout << combination(7, 3) << endl;
    //cout << min(nums, 20) << endl;
    //cout << binomialRandomVariable(12, 8, .6) << endl;
    //cout << median(nums, 21) << endl;
    //cout << Q1(nums, 21) << endl;
}