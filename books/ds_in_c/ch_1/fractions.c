#include <stdio.h>

typedef struct {
    int num;
    int den;
} Fraction;

void print_fraction(Fraction);
Fraction addition(Fraction, Fraction);
Fraction multiplication(Fraction, Fraction);
Fraction a, b, c, answ;

int main(void)
{
    a.num = 5; a.den = 8;
    b.num = 18; b.den = 10;
    c.num = 7; c.den = 1;

    answ = multiplication(a, addition(b, c));

    print_fraction(answ);

    return 0;
}

// Doing addition on the members within the Fraction structures
//
// Since ther are two numerators and two denominators at a multiplication sum
// two structures are needed
Fraction addition(Fraction a, Fraction b)
{
    answ.num = a.num + b.den;
    answ.den = a.den + b.num;

    return answ;
}

// Doing multiplication on the members within the Fraction structures
Fraction multiplication(Fraction a, Fraction b)
{
    answ.num = a.num * b.den;
    answ.den = a.den * b.num;

    return answ;
}

// Print the result fraction after performing an opperation (manipulating the
// data)
void print_fraction(Fraction f)
{
    printf("%d/%d\n", f.num, f.den);
}
