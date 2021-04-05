#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

float number()
{
    int res = 0;
    while (true)
    {
        char c = cin.get();
        if (c >= '0' && c <= '9')
            res = res * 10 + c - '0';
        else
        {
            cin.putback(c); //возвращает заданный символ назад во входной поток
            return res;
        }
    }
}

float expr();

float ckobki()
{
    char c = cin.get();
    if (c == '(')
    {
        float x = expr();
        cin.get();
        return x;
    }
    else
    {
        cin.putback(c);
        return number();
    }
}

float factor()
{
    int x = ckobki();
    while (true)
    {
        char c = cin.get();
        switch (c)
        {
        case '*':
            x *= ckobki();
            break;
        case '/':
            x /= ckobki();
            break;
        default:
            cin.putback(c);
            return x;
        }
    }
}

float expr()
{
    int x = factor();
    while (true)
    {
        char c = cin.get();
        switch (c)
        {
        case '+':
            x += factor();
            break;
        case '-':
            x -= factor();
            break;
        default:
            cin.putback(c);
            return x;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Введите выражение: ";
    float res = expr();
    cout << "Ответ = " << res << endl;
    return 0;
}