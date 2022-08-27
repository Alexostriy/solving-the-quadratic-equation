#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

#include "test_kvadratki.h"
#include "quadratic_equation.h"

int main()
{
    double a = NAN, b = NAN, c = NAN;
    T_ans ans = {};

    Test_solving_quadratic();
    Test_solving_line     ();
    Test_comparison       ();

    while (true)
    {

        printf("enter coefficient a\n");
        a = input();

        printf("enter coefficient b\n");
        b = input();

        printf("enter coefficient c\n");
        c = input();

        if (comparison(a))
            solving_line (b, c, &ans);
        else
            solving_quadratic (a, b, c, &ans);

        print (ans);

        printf ("Press e if you want to escape and any other letter if you not\n");
        if (getch() == 'e')
            break;
    }

    return 0;
}
