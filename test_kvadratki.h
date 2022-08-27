#ifndef TEST_KVADRATKI_H_INCLUDED
#define TEST_KVADRATKI_H_INCLUDED
#include "quadratic_equation.h"

void Test_solving_quadratic();
void check_solving_quadratic (const int count, const int x1, const int x2, const double a, const double b, const double c, int *test_num, int const *cor_num);
void Check_Test (T_ans* const ans, T_ans* const correct, int** const cor_num, int** test_num);
void Test_solving_line();
void check_solving_line (const int count, const double x1, const double x2, const int b, const int c, int* test_num, int* cor_num);
void Test_comparison();
void Check_comparison (const double coef, const int cor_answer, int* test_num, int* cor_num);

#endif // TEST_KVADRATKI_H_INCLUDED
