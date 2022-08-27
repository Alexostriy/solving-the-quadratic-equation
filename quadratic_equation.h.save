#ifndef quadratic_equation_H_INCLUDED
#define quadratic_equation_H_INCLUDED
/// Possible number of solutions to the quadratic equation
typedef struct
{
    int count; ///< integer number of solutions to the equation
    double x1; ///< the first root of the equation
    double x2; ///< the second root of the equation
} T_ans;

/// Possible number of solutions to the quadratic equation
enum Num_Roots
{
    ANY_NUMBER = -1,///< the equation has infinitely many solutions
    ZERO_ROOTS,     ///< the equation has 1 solution
    ONE_ROOT,       ///< the equation has 2 solutions
    TWO_ROOTS,      ///< the equation has 3 solutios
};

/**
 * \brief the function compares double numbers with zero
 * \param[in] the function gets a number that needs to be compared with zero
 * \return 1 if equal to zero and 0 if not
 */
int comparison(const double x);

/**
 * \brief solves the quadratic equation
 * \param[in] coefficient a of quadratic equation of the double type
 * \param[in] coefficient b of quadratic equation of the double type
 * \param[in] coefficient c of quadratic equation of the double type
 * \param[in] the address of a variable of type T_ans in which the response will be written
 * \param[out] ans - the structure contains roots and number of solutions
 * \note the equation is ax^2 + bx + c = 0
 */
void solving_quadratic(const double a, const double b, const double c, T_ans* const ans);

/**
 * \brief solves linear equations
 * \param[in] b quadratic equation of the double type
 * \param[in] c quadratic equation of the double type
 * \param[in] the address of a variable of type T_ans in which the response will be written
 */
void solving_line (const double b, const double c, T_ans* const ans);

/**
 * \brief the function reads the number and checks for the correctness of the input
 * \return the value of a correctly read number
 * \note the correct inputs are an integer or decimal fraction (exponential notation of the number is allowed)
 */
double input();

/**
 * \brief the function prints the answer of the quadratic equation
 * \param[in] a variable of T_ans type with information of answer
 * \return the answer is a line with information about the number of solutions and a second line with their values if any
 */
void print(T_ans ans);
#endif // VADRATKA_H_INCLUDED
