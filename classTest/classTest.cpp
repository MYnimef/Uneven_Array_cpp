#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

class UnevenArray
{
public:
    UnevenArray()
    {
        setValue(0, 0);
    }

    void setValue(size_t n, size_t m)
    {
        linesNum = n, columnNum = m;
        element = new double* [linesNum];
        for (size_t i = 0; i < linesNum; i++)
        {
            element[i] = new double[columnNum];
            for (size_t j = 0; j < columnNum; j++)
            {
                element[i][j] = (1 + rand() % 9) * 0.01;
            }
        }
    }

    void printValue()
    {
        for (size_t i = 0; i < linesNum; i++)
        {
            for (size_t j = 0; j < columnNum; j++)
            {
                cout << setw(4) << element[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void clearValue()
    {
        for (size_t i = 0; i < linesNum; i++)
        {
            delete[] element[i];
        }
    }

private:
    size_t linesNum, columnNum;
    double** element;
};

int main()
{
    cout << "This is uneven array" << endl;

    UnevenArray* d = new UnevenArray[10];
    for (size_t i = 0; i < 10; i++)
    {
        d[i].setValue(i + 1, i + 1);
        d[i].printValue();
        d[i].clearValue();
    }
    delete[] d;

    return 0;
}