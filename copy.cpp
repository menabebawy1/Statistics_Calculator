#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

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
    return factorial(n) / (factorial(k) * factorial(n - k));
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
    cout << endl << "Ordered numbers: ";
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

double probabilityCompliment(double a)
{
    return 1.0 - a;
}

double probabilityGiven(double a, double b)
{
    return (a * b) / b;
}

double meanRandomVariable(double x[], double px[], int size)
{
    double total = 0;
    for (int i = 0; i < size; i++)
    {
        total += x[i] * px[i];
    }
    return total;
}

double varianceRandomVariable(double x[], double px[], int size)
{
    double mean = meanRandomVariable(x, px, size);
    double total = 0;
    for (int i = 0; i < size; i++)
    {
        total += pow((x[i] - mean), 2) * px[i];
    }
    return total;
}

double meanLinearRandomVariable(double x[], double px[], int size, double a, double b)
{
    double mean = meanRandomVariable(x, px, size);
    return (a * mean) + b;
}

double varianceLinearRandomVariable(double x[], double px[], int size, double a)
{
    double var = varianceRandomVariable(x, px, size);
    return pow(a, 2) * var;
}

double binomialRandomVariable(double n, double x, double p)
{
    return combination(n, x) * pow(p, x) * pow((1 - p), (n - x));
}

double meanBinomialRandomVariable(double n, double p)
{
    return n * p;
}

double varianceBinomialRandomVariable(double n, double p)
{
    return meanBinomialRandomVariable(n, p) * (1 - p);
}

double zScore(double x, double mean, double SD)
{
    return (x - mean) / SD;
}

double sampleDistributionMeanSD(double SD, int n)
{
    return pow(SD, 2) / n;
}

double sampleDistributionProportionVariance(double p, int n)
{
    return (p * (1 - p)) / n;
}

void confidenceIntervalSampleProportion(double level, double sampleP, double Zc, double n)
{
    double margin = Zc * sqrt((sampleP * (1 - sampleP)) / n);
    double upper = sampleP + margin;
    double lower = sampleP - margin;
    cout << "We are " << level << "% confident that the population is between: " << lower << " - " << upper << " ." << endl;
}

void confidenceIntervalMean(double level, double sampleM, double t, double s, int n)
{
    double margin = t * (s / sqrt(n));
    double upper = sampleM + margin;
    double lower = sampleM - margin;
    cout << "We are " << level << "% confident that the mean is between: " << lower << " - " << upper << " ." << endl;
}

void acceptRejectNull(double pVal, double a)
{
    if (pVal <= a)
    {
        cout << "We reject the null hypothesis." << endl;
    }
    else
    {
        cout << "We fail to reject the null hypothesis. " << endl;
    }
}

double hypothesisTestProportion(double sampleP, double nullP, int n)
{
    return (sampleP - nullP) / sqrt((nullP * (1 - nullP)) / n);
}

double hypothesisTestMean(double sampleM, double nullM, int n, double s)
{
    return (sampleM - nullM) / (s / sqrt(n));
}

void alternateHypothesisComparingTwoValues(double v1, double v2)
{
    if (v1 - v2 > 0)
    {
        cout << "H0: v1 - v2 > 0" << endl;
    }
    else if (v1 - v2 < 0)
    {
        cout << "H0: v1 - v2 < 0" << endl;
    }
    else
    {
        cout << "H0: v1 - v2 ≠ 0" << endl;
    }
}

double samplePCommonComparingTwoProportions(double n1, double n2, double sampleP1, double sampleP2)
{
    return ((n1 * sampleP1) + (n2 * sampleP2)) / (n1 + n2);
}

double zComparingTwoProportions(double n1, double n2, double sampleP1, double sampleP2)
{
    double commonP = samplePCommonComparingTwoProportions(n1, n2, sampleP1, sampleP2);
    return (sampleP1 - sampleP2) / sqrt(((commonP * (1 - commonP)) / n1) + ((commonP * (1 - commonP)) / n2));
}

void confidenceIntervalComparingTwoProportions(double level, double n1, double n2, double sampleP1, double sampleP2, double Zc)
{
    double commonP = samplePCommonComparingTwoProportions(n1, n2, sampleP1, sampleP2);
    double margin = Zc * (((commonP * (1 - commonP)) / n1) + ((commonP * (1 - commonP)) / n2));
    double upper = (sampleP1 - sampleP2) + margin;
    double lower = (sampleP1 - sampleP2) - margin;
    cout << "We are " << level << "% confident that the difference between the proportions is between: " << lower << " - " << upper << " ." << endl;
}

double tComparingTwoIndependentMeans(double n1, double n2, double sampleM1, double sampleM2, double variance1, double variance2)
{
    return (sampleM1 - sampleM2) / sqrt((variance1 / n1) + (variance2 / n2));
}

void confidenceIntervalComparingTwoIndependentMeans(double level, double n1, double n2, double sampleM1, double sampleM2, double variance1, double variance2, double t)
{
    double margin = t * sqrt((variance1 / n1) + (variance2 / n2));
    double upper = (sampleM1 - sampleM2) + margin;
    double lower = (sampleM1 - sampleM2) - margin;
    cout << "We are " << level << "% confident that the difference between the means is between: " << lower << " - " << upper << " ." << endl;
}

double tComparingTwoRelatedMeans(double arr1[], double arr2[], int size)
{
    double arr3[size];
    for (int i = 0; i < size; i++)
    {
        arr3[i] = arr1[i] - arr2[i];
    }
    double meanD = mean(arr3, size);
    double varianceD = variance(arr3, size);
    return meanD / (varianceD / sqrt(size));
}
double readNumber(string name){
    double x = 0;
    string full = "Enter " + name + ": ";
    cout << full;
    cin >> x;
    return x;
}

double *readArray(int* length)
{
    double *nums = new double[100];

    cout << endl;
    cout << "Example: 1,5,7.5,9,3,18" << endl;

    string str = "";
    cout << "Enter your values separated by commas as shown above: ";
    cin >> str;

    int y = 0;
    bool dot = false;
    bool after = false;
    stringstream ss(str);

    for (int i; ss >> i;)
    {

        if (dot == true)
        {
            nums[y - 1] += i * .1;
            dot = false;
            after = true;
        }
        if (ss.peek() == '.')
        {
            dot = true;
            ss.ignore();
        }
        if (ss.peek() == ',' || ss.peek() == ' ')
        {
            ss.ignore();
        }
        if (after == false)
        {
            nums[y] = i;
            y++;
        }
        after = false;
    }

    *length = y;
    return nums;
}

int main()
{

    cout << endl;
    cout << "Hello, welcome to the MINSTAT calculator (Copyright © 2021 | Mena Bebawy). Here you will find the calculations neccessary for problems for an Introductory Statistics Class. " << endl;
    cout << "Select from the following options, and enter the number related to your problem. " << endl;
    cout << endl;

    cout << "1. Find the Mean. " << endl;
    cout << "2. Find the Variance. " << endl;
    cout << "3. Find the Standard Deviation. " << endl;
    cout << "4. Find the Standard Error. " << endl;
    cout << "5. Find the factorial value of a number n. " << endl;
    cout << "6. Find the combination of 2 numbers x and y. That is x choose y. " << endl;
    cout << "7. Find the Maximum value in a data set. " << endl;
    cout << "8. Find the Minimum value in a data set. " << endl;
    cout << "9. Find the Median in a data set. " << endl;
    cout << "10. Display a Box and Whisker Plot using a data set and dsiplay all the related varible such Q1, Q3, IQR, and Range. " << endl;
    cout << "11. Find the probability of A OR B. " << endl;
    cout << "12. Find the compliment Probability of A. " << endl;
    cout << "13. Find the probability of A GIVEN B. " << endl;
    cout << "14. Find the mean of a Random Variable Table. " << endl;
    cout << "15. Find the variance of a Random Variable Table. " << endl;
    cout << "16. Find the mean of a Linear Random Variable Table. " << endl;
    cout << "17. Find the variance of a Linear Random Variable Table. " << endl;
    cout << "18. Find the Binomial Random Variable. " << endl;
    cout << "19. Find the mean of a Binomial Random Variable. " << endl;
    cout << "20. Find the variance of a Binomial Random Variable. " << endl;
    cout << "21. Find the z score of a certain value given the standard deviation. " << endl;
    cout << "22. Find the standard deviation of the sampling distribution of the sample mean. " << endl;
    cout << "23. Find the variance of the sampling distribution of the sample proportion. " << endl;
    cout << "24. Find the confidence interval given a certain confidence level of the sampling distribution of the sample proportion. " << endl;
    cout << "25. Find the confidence interval of the mean. " << endl;
    cout << "26. Should the null hypothesis be accepted or fail to be rejected. " << endl;
    cout << "27. Find the Z value for the hypothesis test for a proportion. " << endl;
    cout << "28. Find the T value for the hypothesis test for a mean. " << endl;
    cout << "29. Find the alternate hypothesis for comparing 2 values. " << endl;
    cout << "30. Find the value of the sample p common when comparing 2 proportions." << endl;
    cout << "31. Find the Z value for comparing two proportions from independent samples." << endl;
    cout << "32. Find the confidence interval given a confidence level for comparing two  proportions from independent samples. " << endl;
    cout << "33. Find the T value for comparing two means from independent samples. " << endl;
    cout << "34. Find the confidence interval given a confidence level for comparing two means from independent samples." << endl;
    cout << "35. Find the T value for comparing two means from related samples. " << endl;

    int x = 0;
    cout << endl << "Enter a number: ";
    cin >> x;

    int size = 0;
    double *copy = nullptr;
    if (x == 1)
    {
        copy = readArray(&size);
        cout << endl << "Mean: " << mean(copy, size) << endl << endl;
    }
    else if (x == 2)
    {
        copy = readArray(&size);
        cout << endl << "Variance: " << variance(copy, size) << endl << endl;
    }
    else if (x == 3)
    {
        copy = readArray(&size);
        cout << endl << "Standard Deviation: " << stddev(copy, size) << endl << endl;
    }
    else if (x == 4)
    {
        copy = readArray(&size);
        cout << endl << "Standard Error: " << stderror(copy, size) << endl << endl;
    }
    else if (x == 5){
        int n = readNumber("number");
        cout << endl << n << " factorial is: " << factorial(n) << endl << endl;
    }
    else if (x == 6){
        int a = readNumber("first number");
        int b = readNumber("second number");
        cout << endl << a << " choose " << b << " is: " << combination(a,b) << endl << endl;
    }
    else if (x == 7)
    {
        copy = readArray(&size);
        cout << endl << "Max: " << max(copy, size) << endl << endl;
    }
    else if (x == 8)
    {
        copy = readArray(&size);
        cout << endl << "Min: " << min(copy, size) << endl << endl;
    }
    else if (x == 9)
    {
        copy = readArray(&size);
        cout << endl << "Median: " << median(copy, size) << endl << endl;
    }
    else if (x == 10)
    {
        copy = readArray(&size);
        BoxWhisker(copy, size);
    }
    else if (x == 11){
        double a = readNumber("first probability");
        double b = readNumber("second probability");
        cout << endl << "The probability of " << a << " or " << b << " is: " << probabilityOR(a,b) << endl << endl;
    }
    else if (x == 12){
        double a = readNumber("probability");
        cout << a << endl;
        cout << endl << "The compliment of " << a << " is: " << probabilityCompliment(a) << endl << endl;
    }

    



    
}
