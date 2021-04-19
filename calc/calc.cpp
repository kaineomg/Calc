#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

float number();

float expr();

float ckobki();

float factor();




int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Введите выражение: ";
    float res = expr();
    cout << "Ответ = " << res << endl;
    return 0;
}

float factor()
{
    float x = ckobki();
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
float expr()
{
    float x = factor();
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
float number()
{
    float res = 0;
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
