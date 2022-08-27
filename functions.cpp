#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "quadratic_equation.h"

const double accuracy = 1e-7;

int comparison (const double x)
{
    return (fabs (x) < accuracy);
}

void solving_quadratic (const double a, const double b, const double c, T_ans* const ans)
{
    assert (ans != NULL  && "ans is null link");
    assert (isfinite (a) && "a is not a number");
    assert (isfinite (b) && "b is not b number");
    assert (isfinite (c) && "c is not c number");

    double D = b*b-4*a*c;
    if (comparison (D))
    {
        ans->count = ONE_ROOT;
        ans->x1 = -b/(2*a);
    }
    else if (D<0)
    {
        ans->count = ZERO_ROOTS;
    }
    else
    {
        ans->count = TWO_ROOTS;
        double D_sqrt = sqrt(D);

        ans->x1 = (D_sqrt - b) /(2*a);
        ans->x2 = (-D_sqrt - b)/(2*a);
    }
}

void solving_line (const double b, const double c, T_ans* const ans)
{
    assert (ans != NULL   && "ans is null link");
    assert (isfinite (b) && "b is not b number");
    assert (isfinite (c) && "c is not c number");
    if (comparison (b))
    {
        if (comparison (c))
            ans->count = ANY_NUMBER;
        else
            ans->count = ZERO_ROOTS;
    }
    else
    {
        ans->count = ONE_ROOT;
        ans->x1= -c/b;
    }
}

double input()
{
    double coef;
    int k = 0;

    while (1)
    {
        scanf("%lf", &coef);
        char c;

        while ((c = getchar()) != '\n')
            if ((c<'9') || (c>'0'))
                k++;
        if (k > 0)
            printf("You entered incorrectly try again\n");
        else
            return coef;

        k = 0;
    }
}

void print(const T_ans ans)
{
    switch (ans.count)
    {
        case TWO_ROOTS:
            printf ("2 roots\n%lg %lg\n", ans.x1, ans.x2);
                break;

        case ONE_ROOT:
            printf ("1 root\n%lg\n", ans.x1);
            break;

        case ZERO_ROOTS:
            printf ("No roots\n");
            break;

        case ANY_NUMBER:
            printf ("The solution is any number\n");
            break;

        default:
            printf ("unknown error\n");
            break;
    }
}

