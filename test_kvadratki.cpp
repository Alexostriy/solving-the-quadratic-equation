#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "quadratic_equation.h"

const int discr_test_num      = 8;
const int line_test_num       = 6;
const int comparison_test_num = 3;

void Check_Test (T_ans*  ans, T_ans*  correct, int**  cor_num, int** test_num)
{
    if ((ans->count == correct->count) && (comparison (ans->x1 - correct->x1)) && (comparison (ans->x2 - correct->x2)))
        **cor_num += 1;
    else printf("FAIL\nTest Number %d\n Result count=%d x1=%lf x2=%lf\n Correct count=%d x1=%lf x2=%lf\n",
                **test_num, ans->count, ans->x1, ans->x2, correct->count, correct->x1, correct->x2);
}

void check_solving_quadratic(const int count, const double x1, const double x2, const double a, const double b, const double c, int *test_num, int*  cor_num)
{
    T_ans ans = {0,0,0};
    T_ans correct = {count, x1, x2};

    solving_quadratic (a, b, c, &ans);
    Check_Test (&ans, &correct, &cor_num, &test_num);

    (*test_num)++;
}


void Test_solving_quadratic()
{
     int test_num = 1;
     int cor_num = 0;

     check_solving_quadratic(1, -1,  0, 1, 2, 1  , &test_num, &cor_num);
     check_solving_quadratic(2,  3,  1, 1,-4, 3  , &test_num, &cor_num);
     check_solving_quadratic(0,  0,  0, 1, 1, 1  , &test_num, &cor_num);
     check_solving_quadratic(2,  0, -1, 1, 1, 0  , &test_num, &cor_num);
     check_solving_quadratic(1,  0,  0, 1, 0, 0  , &test_num, &cor_num);
     check_solving_quadratic(1,  1,  0,-2, 4,-2  , &test_num, &cor_num);
     check_solving_quadratic(0,  0,  0, 1, 0, 4.5, &test_num, &cor_num);
     check_solving_quadratic(1,  0,  0, 7, 0, 0  , &test_num, &cor_num);

     printf("Test discr\n%d Tests were passed correct, Test number was %d\n",
            cor_num, discr_test_num);
}

void check_solving_line (const int count, const int x1, const int x2, const int b, const int c, int *test_num, int *cor_num)
{
    T_ans ans = {0,0,0};
    T_ans correct;

    correct.count = count;
    correct.x1 = x1;
    correct.x2 = x2;

    solving_line (b, c, &ans);
    Check_Test (& ans, &correct, &cor_num, &test_num);

    (*test_num)++;
}

void Test_solving_line()
{
    int test_num = 1;
    int cor_num  = 0;

    check_solving_line( 1, 1, 0, 1   ,-1 , &test_num, &cor_num);
    check_solving_line( 0, 0, 0, 0   , 1 , &test_num, &cor_num);
    check_solving_line( 1, 0, 0, 10.8, 0 , &test_num, &cor_num);
    check_solving_line(-1, 0, 0, 0   , 0 , &test_num, &cor_num);
    check_solving_line( 1,-1, 0, 9   , 9 , &test_num, &cor_num);
    check_solving_line( 1, 9, 0, 9   ,-81, &test_num, &cor_num);

    printf("Test solving_line\n%d Tests were passed correct, Test number was %d\n", cor_num, line_test_num);
}

void Check_comparison(const double coef, const int cor_answer,int *test_num, int *cor_num)
{
    int answer = comparison(coef);

    if (answer == cor_answer) *cor_num+=1;
    else printf("FAIL\nTest Number %d\n Result %d\n Correct %d\n",
                 *test_num, answer, cor_answer);
}

void Test_comparison()
{
    int test_num = 1;
    int cor_num  = 0;

    Check_comparison( 1e-6, 0, &test_num, &cor_num);
    Check_comparison(-1e10, 0, &test_num, &cor_num);
    Check_comparison( 0   , 1, &test_num, &cor_num);

    printf("Test comparison\n%d Tests were passed correct, Test number was %d\n", cor_num, comparison_test_num);
}
