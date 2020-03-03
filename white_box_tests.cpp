//======== Copyright (c) 2017, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     White Box - Tests suite
//
// $NoKeywords: $ivs_project_1 $white_box_code.cpp
// $Author:     JMENO PRIJMENI <xlogin00@stud.fit.vutbr.cz>
// $Date:       $2017-01-04
//============================================================================//
/**
 * @file white_box_tests.cpp
 * @author JMENO PRIJMENI
 * 
 * @brief Implementace testu prace s maticemi.
 */

#include "gtest/gtest.h"
#include "white_box_code.h"


class Matrix_Testing : public Matrix , public testing::Test
{

    protected:
        

        Matrix matrix_make_1x1_empty()
        {
            Matrix matrix;
            matrix = Matrix::Matrix();
            return matrix;
        }

        Matrix matrix_make_1x1()
        {
            Matrix matrix = Matrix::Matrix(1, 1);
            matrix.set(0,0,9);
            return matrix;
        }

        Matrix matrix_make_5x5()
        {
            Matrix matrix = Matrix::Matrix(5, 5);
            matrix.set(std::vector<std::vector<double>>{
                {1,5,1,-7,1},
                {-2,10,-10,12,-2},
                {1,12,8,4,6},
                {1,-10,-5,-5,-7},
                {1,7,10,5,10},
            });
            return matrix;
        }

        Matrix matrix_make_2x3()
        {
            Matrix matrix = Matrix::Matrix(2, 3);
            matrix.set(std::vector<std::vector<double>>{
                { 1,1 },
                { 2,2 },
                { 3,3 },
            });
            return matrix;
        }

        Matrix matrix_make_3x2()
        {
           Matrix matrix = Matrix(3, 2);
           matrix.set(std::vector<std::vector<double>>{
               {1,1,1},
               {2,2,2},
           });
           return matrix;
        }

  
};

TEST_F(Matrix_Testing, Matrix_Construct)
{
    //WRONG MATRIX CONSTRUCT
    EXPECT_ANY_THROW(Matrix::Matrix(-1,5));
    EXPECT_ANY_THROW(Matrix::Matrix(0, 5));
    EXPECT_ANY_THROW(Matrix::Matrix(5, 0));
    EXPECT_ANY_THROW(Matrix::Matrix(5, -1));

    //CORRECT MATRIX CONSTRUCT
    EXPECT_NO_THROW(Matrix::Matrix(1,1));
    EXPECT_NO_THROW(Matrix::Matrix(5,2));
    EXPECT_NO_THROW(Matrix::Matrix(2,5));
    EXPECT_NO_THROW(Matrix::Matrix(20000, 5000));
    EXPECT_NO_THROW(Matrix::Matrix());
}

/////////////////////////////////////////////////////////////

TEST_F(Matrix_Testing, Matrix_value_set_3x2)
{
    Matrix matrix;
    matrix = matrix_make_3x2();
    //SET RIGHT VALUES TO MATRIX
    EXPECT_TRUE(matrix.set(1, 1, 99));
    EXPECT_TRUE(matrix.set(0, 0, -99));
    EXPECT_TRUE(matrix.set(2, 1, 99));

    //SET WRONG VALUES TO MATRIX
    EXPECT_FALSE(matrix.set(0, 2, 99));
    EXPECT_FALSE(matrix.set(3, 2, 99));
    EXPECT_FALSE(matrix.set(2, 3, 99));
    EXPECT_FALSE(matrix.set(-1, 1, 99));
}

TEST_F(Matrix_Testing, Matrix_value_set_2x3)
{
    Matrix matrix;
    matrix = matrix_make_2x3();
    //SET RIGHT VALUES TO MATRIX
    EXPECT_TRUE(matrix.set(1, 1, 99));
    EXPECT_TRUE(matrix.set(0, 0, -99));
    EXPECT_TRUE(matrix.set(1, 2, 99));

    //SET WRONG VALUES TO MATRIX
    EXPECT_FALSE(matrix.set(2, 0, 99));
    EXPECT_FALSE(matrix.set(3, 2, 99));
    EXPECT_FALSE(matrix.set(2, 3, 99));
    EXPECT_FALSE(matrix.set(-1, 1, 99));
}

TEST_F(Matrix_Testing, Matrix_value_set_5x5)
{
    Matrix matrix;
    matrix = matrix_make_5x5();
    //SET RIGHT VALUES TO MATRIX
    EXPECT_TRUE(matrix.set(1, 1, 99));
    EXPECT_TRUE(matrix.set(0, 0, -99));
    EXPECT_TRUE(matrix.set(4, 4, 99));
    EXPECT_TRUE(matrix.set(2, 4, 99));

    //SET WRONG VALUES TO MATRIX
    EXPECT_FALSE(matrix.set(5, 5, 99));
    EXPECT_FALSE(matrix.set(10, 2, 99));
    EXPECT_FALSE(matrix.set(0, 10, 99));
    EXPECT_FALSE(matrix.set(-1, 1, 99));
}

TEST_F(Matrix_Testing, Matrix_value_set_1x1)
{
    Matrix matrix;
    matrix = matrix_make_1x1();
    //SET RIGHT VALUES TO MATRIX
    EXPECT_TRUE(matrix.set(0, 0, 99));

    //SET WRONG VALUES TO MATRIX
    EXPECT_FALSE(matrix.set(1, 1, 99));
    EXPECT_FALSE(matrix.set(0, 1, 99));
}

TEST_F(Matrix_Testing, Matrix_value_set_1x1_empty)
{
    Matrix matrix;
    matrix = matrix_make_1x1_empty();
    //SET RIGHT VALUES TO MATRIX
    EXPECT_TRUE(matrix.set(0, 0, 99));

    //SET WRONG VALUES TO MATRIX
    EXPECT_FALSE(matrix.set(1, 1, 99));
    EXPECT_FALSE(matrix.set(0, 1, 99));
}

/////////////////////////////////////////////////////////////

TEST_F(Matrix_Testing, Matrix_value_arr_set_1x1)
{
    Matrix matrix;
    matrix = matrix_make_1x1();
    //SET RIGHT VALUES TO MATRIX
    EXPECT_TRUE(matrix.set(std::vector<std::vector<double>>{ {99}, }));

    //SET WRONG VALUES TO MATRIX
    EXPECT_FALSE(matrix.set(std::vector<std::vector<double>>{ {99, 99},}));
    EXPECT_FALSE(matrix.set(std::vector<std::vector<double>>{ {99},{99},}));
}

TEST_F(Matrix_Testing, Matrix_value_arr_set_1x1_empty)
{
    Matrix matrix;
    matrix = matrix_make_1x1_empty();
    //SET RIGHT VALUES TO MATRIX
    EXPECT_TRUE(matrix.set(std::vector<std::vector<double>>{ {99}, }));

    //SET WRONG VALUES TO MATRIX
    EXPECT_FALSE(matrix.set(std::vector<std::vector<double>>{ {99, 99}, }));
    EXPECT_FALSE(matrix.set(std::vector<std::vector<double>>{ {99}, { 99 }, }));
}

TEST_F(Matrix_Testing, Matrix_value_arr_set_5x5)
{
    Matrix matrix;
    matrix = matrix_make_5x5();
    //SET RIGHT VALUES TO MATRIX
    EXPECT_TRUE(matrix.set(std::vector<std::vector<double>>{ { 99,99,99,99,99 }, { 99,99,99,99,99 }, { 99,99,99,99,99 }, { 99,99,99,99,99 }, { 99,99,99,99,99 }}));
  
    //SET WRONG VALUES TO MATRIX
    EXPECT_FALSE(matrix.set(std::vector<std::vector<double>>{ {99,99,99,99,99}, }));
    EXPECT_FALSE(matrix.set(std::vector<std::vector<double>>{ {99}, }));
}

TEST_F(Matrix_Testing, Matrix_value_arr_set_2x3)
{
    Matrix matrix;
    matrix = matrix_make_2x3();
    //SET RIGHT VALUES TO MATRIX
    EXPECT_TRUE(matrix.set(std::vector<std::vector<double>>{ { 99, 99, 99 }, { 99,99,99 }, }));

    //SET WRONG VALUES TO MATRIX
    EXPECT_FALSE(matrix.set(std::vector<std::vector<double>>{ {99}, { 99,99 }, { 99,99,99 }}));
    EXPECT_FALSE(matrix.set(std::vector<std::vector<double>>{ {99, 99}, { 99,99 }, { 99,99 } }));
}

TEST_F(Matrix_Testing, Matrix_value_arr_set_3x2)
{
    Matrix matrix;
    matrix = matrix_make_3x2();
    //SET RIGHT VALUES TO MATRIX
    EXPECT_TRUE(matrix.set(std::vector<std::vector<double>>{ {99, 99}, { 99,99 }, {99,99} }));

    //SET WRONG VALUES TO MATRIX
    EXPECT_FALSE(matrix.set(std::vector<std::vector<double>>{ {99,99,99}, { 99,99,99 }, { 99,99,99 }}));
    EXPECT_FALSE(matrix.set(std::vector<std::vector<double>>{ { 99, 99, 99 }, { 99,99,99 }, }));
}

//////////////////////////////////////////////////////////////

TEST_F(Matrix_Testing, Matrix_value_get_1x1)
{
    Matrix matrix;
    matrix = matrix_make_1x1();
    //GETTING VALUE INSIDE OF MATRIX
    EXPECT_NO_THROW(matrix.get(0, 0));
    
    //GETTING VALUE OUTSIDE OF MATRIX
    EXPECT_ANY_THROW(matrix.get(1, 1));
    EXPECT_ANY_THROW(matrix.get(0, 1));
}

TEST_F(Matrix_Testing, Matrix_value_get_1x1_empty)
{
    Matrix matrix;
    matrix = matrix_make_1x1_empty();
    //GETTING VALUE INSIDE OF MATRIX
    EXPECT_NO_THROW(matrix.get(0, 0));

    //GETTING VALUE OUTSIDE OF MATRIX
    EXPECT_ANY_THROW(matrix.get(1, 1));
    EXPECT_ANY_THROW(matrix.get(0, 1));
}

TEST_F(Matrix_Testing, Matrix_value_get_5x5)
{
    Matrix matrix;
    matrix = matrix_make_5x5();
    //GETTING VALUE INSIDE OF MATRIX
    EXPECT_NO_THROW(matrix.get(0, 0));
    EXPECT_NO_THROW(matrix.get(4, 4));
   
    //GETTING VALUE OUTSIDE OF MATRIX
    EXPECT_ANY_THROW(matrix.get(-1, 1));
    EXPECT_ANY_THROW(matrix.get(0, 5));
    EXPECT_ANY_THROW(matrix.get(5, 5));
}

TEST_F(Matrix_Testing, Matrix_value_get_3x2)
{
    Matrix matrix;
    matrix = matrix_make_3x2();
    //GETTING VALUE INSIDE OF MATRIX
    EXPECT_NO_THROW(matrix.get(0, 0));
    EXPECT_NO_THROW(matrix.get(2, 1));

    //GETTING VALUE OUTSIDE OF MATRIX
    EXPECT_ANY_THROW(matrix.get(-1, 1));
    EXPECT_ANY_THROW(matrix.get(3, 2));
}

TEST_F(Matrix_Testing, Matrix_value_get_2x3)
{
    Matrix matrix;
    matrix = matrix_make_2x3();
    //GETTING VALUE INSIDE OF MATRIX
    EXPECT_NO_THROW(matrix.get(1, 2));
    EXPECT_NO_THROW(matrix.get(1, 1));

    //GETTING VALUE OUTSIDE OF MATRIX
    EXPECT_ANY_THROW(matrix.get(2, 3));
    EXPECT_ANY_THROW(matrix.get(5, 5));
}

//////////////////////////////////////////////////////////////

TEST_F(Matrix_Testing, Matrix_compare_1x1)
{
    Matrix matrix,matrix_1x1_nq,matrix_1x1_eq,matrix_5x5;
    matrix = matrix_make_1x1();
    matrix_1x1_eq = matrix_make_1x1();
    matrix_1x1_nq = matrix_make_1x1();
    matrix_1x1_nq.set(0, 0, 99);
    matrix_5x5 = matrix_make_5x5();
    //COMPARE SAME SIZES SAME VALUES
    EXPECT_TRUE(matrix.operator==(matrix_1x1_eq));

    //COMPARE SAME SIZES DIFFERENT VALUES
    EXPECT_FALSE(matrix.operator==(matrix_1x1_nq));

    //COMPARE DIFFERENT SIZES
    EXPECT_ANY_THROW(matrix.operator==(matrix_5x5));
}

TEST_F(Matrix_Testing, Matrix_compare_1x1_empty)
{
    Matrix matrix, matrix_1x1_nq, matrix_1x1_eq, matrix_5x5;
    matrix = matrix_make_1x1_empty();
    matrix_1x1_eq = matrix_make_1x1_empty();
    matrix_1x1_nq = matrix_make_1x1();
    matrix_1x1_nq.set(0, 0, 99);
    matrix_5x5 = matrix_make_5x5();

    //COMPARE SAME SIZES SAME VALUES
    EXPECT_TRUE(matrix.operator==(matrix_1x1_eq));

    //COMPARE SAME SIZES DIFFERENT VALUES
    EXPECT_FALSE(matrix.operator==(matrix_1x1_nq));

    //COMPARE DIFFERENT SIZES
    EXPECT_ANY_THROW(matrix.operator==(matrix_5x5));
}

TEST_F(Matrix_Testing, Matrix_compare_2x3)
{
    Matrix matrix, matrix_2x3_nq, matrix_2x3_eq, matrix_5x5;
    matrix = matrix_make_2x3();
    matrix_2x3_eq = matrix_make_2x3();
    matrix_2x3_nq = matrix_make_2x3();
    matrix_2x3_nq.set(0, 0, 99);
    matrix_5x5 = matrix_make_5x5();

    //COMPARE SAME SIZES SAME VALUES
    EXPECT_TRUE(matrix.operator==(matrix_2x3_eq));

    //COMPARE SAME SIZES DIFFERENT VALUES
    EXPECT_FALSE(matrix.operator==(matrix_2x3_nq));

    //COMPARE DIFFERENT SIZES
    EXPECT_ANY_THROW(matrix.operator==(matrix_5x5));
}

TEST_F(Matrix_Testing, Matrix_compare_3x2)
{
    Matrix matrix, matrix_3x2_nq, matrix_3x2_eq, matrix_5x5;
    matrix = matrix_make_3x2();
    matrix_3x2_eq = matrix_make_3x2();
    matrix_3x2_nq = matrix_make_3x2();
    matrix_3x2_nq.set(0, 0, 99);
    matrix_5x5 = matrix_make_5x5();

    //COMPARE SAME SIZES SAME VALUES
    EXPECT_TRUE(matrix.operator==(matrix_3x2_eq));

    //COMPARE SAME SIZES DIFFERENT VALUES
    EXPECT_FALSE(matrix.operator==(matrix_3x2_nq));

    //COMPARE DIFFERENT SIZES
    EXPECT_ANY_THROW(matrix.operator==(matrix_5x5));
}

TEST_F(Matrix_Testing, Matrix_compare_5x5)
{
    Matrix matrix, matrix_5x5_nq, matrix_5x5_eq, matrix_2x3;
    matrix = matrix_make_5x5();
    matrix_5x5_eq = matrix_make_5x5();
    matrix_5x5_nq = matrix_make_5x5();
    matrix_5x5_nq.set(0, 0, 99);
    matrix_2x3 = matrix_make_2x3();

    //COMPARE SAME SIZES SAME VALUES
    EXPECT_TRUE(matrix.operator==(matrix_5x5_eq));

    //COMPARE SAME SIZES DIFFERENT VALUES
    EXPECT_FALSE(matrix.operator==(matrix_5x5_nq));

    //COMPARE DIFFERENT SIZES
    EXPECT_ANY_THROW(matrix.operator==(matrix_2x3));
}

///////////////////////////////////////////////////////////////

TEST_F(Matrix_Testing, Matrix_sum_1x1)
{
    Matrix matrix, matrix_sum, matrix_5x5;
    matrix = matrix_make_1x1();
    matrix_sum = matrix_make_1x1();
    matrix_5x5 = matrix_make_5x5();
    //SUM OF SAME SIZES MATRIX
    EXPECT_NO_THROW(matrix.operator+(matrix_sum));

    //SUM OF DIFFERENT SIZES MATRIX
    EXPECT_ANY_THROW(matrix.operator+(matrix_5x5));
}

TEST_F(Matrix_Testing, Matrix_sum_1x1_empty)
{
    Matrix matrix, matrix_sum, matrix_5x5;
    matrix = matrix_make_1x1_empty();
    matrix_sum = matrix_make_1x1();
    matrix_5x5 = matrix_make_5x5();
    //SUM OF SAME SIZES MATRIX
    EXPECT_NO_THROW(matrix.operator+(matrix_sum));

    //SUM OF DIFFERENT SIZES MATRIX
    EXPECT_ANY_THROW(matrix.operator+(matrix_5x5));
}

TEST_F(Matrix_Testing, Matrix_sum_2x3)
{
    Matrix matrix, matrix_sum, matrix_5x5;
    matrix = matrix_make_2x3();
    matrix_sum = matrix_make_2x3();
    matrix_5x5 = matrix_make_5x5();
    //SUM OF SAME SIZES MATRIX
    EXPECT_NO_THROW(matrix.operator+(matrix_sum));

    //SUM OF DIFFERENT SIZES MATRIX
    EXPECT_ANY_THROW(matrix.operator+(matrix_5x5));
}

TEST_F(Matrix_Testing, Matrix_sum_3x2)
{
    Matrix matrix, matrix_sum, matrix_5x5;
    matrix = matrix_make_3x2();
    matrix_sum = matrix_make_3x2();
    matrix_5x5 = matrix_make_5x5();
    //SUM OF SAME SIZES MATRIX
    EXPECT_NO_THROW(matrix.operator+(matrix_sum));

    //SUM OF DIFFERENT SIZES MATRIX
    EXPECT_ANY_THROW(matrix.operator+(matrix_5x5));
}

TEST_F(Matrix_Testing, Matrix_sum_5x5)
{
    Matrix matrix, matrix_sum, matrix_2x3;
    matrix = matrix_make_5x5();
    matrix_sum = matrix_make_5x5();
    matrix_2x3 = matrix_make_2x3();
    //SUM OF SAME SIZES MATRIX
    EXPECT_NO_THROW(matrix.operator+(matrix_sum));

    //SUM OF DIFFERENT SIZES MATRIX
    EXPECT_ANY_THROW(matrix.operator+(matrix_2x3));
}

///////////////////////////////////////////////////////////////

TEST_F(Matrix_Testing, Matrix_multiplikation_1x1)
{
    Matrix matrix, matrix_mul, matrix_5x5;
    matrix = matrix_make_1x1();
    matrix_mul = matrix_make_1x1();
    matrix_5x5 = matrix_make_5x5();
    //CORRECT MULTIPLIKATION
    EXPECT_NO_THROW(matrix.operator*(matrix_mul));
    EXPECT_NO_THROW(matrix.operator*(99));

    //FALSE MULTIPLIKATION
    EXPECT_ANY_THROW(matrix.operator*(matrix_5x5));
}

TEST_F(Matrix_Testing, Matrix_multiplikation_1x1_empty)
{
    Matrix matrix, matrix_mul, matrix_5x5;
    matrix = matrix_make_1x1_empty();
    matrix_mul = matrix_make_1x1();
    matrix_5x5 = matrix_make_5x5();
    //CORRECT MULTIPLIKATION
    EXPECT_NO_THROW(matrix.operator*(matrix_mul));
    EXPECT_NO_THROW(matrix.operator*(99));

    //FALSE MULTIPLIKATION
    EXPECT_ANY_THROW(matrix.operator*(matrix_5x5));
}

TEST_F(Matrix_Testing, Matrix_multiplikation_2x3)
{
    Matrix matrix, matrix_mul_2x3, matrix_mul_3x2, matrix_5x5;
    matrix = matrix_make_2x3();
    matrix_mul_2x3 = matrix_make_2x3();
    matrix_mul_3x2 = matrix_make_3x2();
    matrix_5x5 = matrix_make_5x5();
    //CORRECT MULTIPLIKATION
    EXPECT_NO_THROW(matrix.operator*(matrix_mul_3x2));
    EXPECT_NO_THROW(matrix.operator*(99));

    //FALSE MULTIPLIKATION
    EXPECT_ANY_THROW(matrix.operator*(matrix_5x5));
    EXPECT_ANY_THROW(matrix.operator*(matrix_mul_2x3));
}

TEST_F(Matrix_Testing, Matrix_multiplikation_3x2)
{
    Matrix matrix, matrix_mul_2x3, matrix_mul_3x2, matrix_5x5;
    matrix = matrix_make_3x2();
    matrix_mul_2x3 = matrix_make_2x3();
    matrix_mul_3x2 = matrix_make_3x2();
    matrix_5x5 = matrix_make_5x5();
    //CORRECT MULTIPLIKATION
    EXPECT_NO_THROW(matrix.operator*(matrix_mul_2x3));
    EXPECT_NO_THROW(matrix.operator*(99));

    //FALSE MULTIPLIKATION
    EXPECT_ANY_THROW(matrix.operator*(matrix_5x5));
    EXPECT_ANY_THROW(matrix.operator*(matrix_mul_3x2));
}

TEST_F(Matrix_Testing, Matrix_multiplikation_5x5)
{
    Matrix matrix, matrix_mul_5x5, matrix_mul_3x2;
    matrix = matrix_make_5x5();
    matrix_mul_3x2 = matrix_make_3x2();
    matrix_mul_5x5 = matrix_make_5x5();
    //CORRECT MULTIPLIKATION
    EXPECT_NO_THROW(matrix.operator*(matrix_mul_5x5));
    EXPECT_NO_THROW(matrix.operator*(99));

    //FALSE MULTIPLIKATION
    EXPECT_ANY_THROW(matrix.operator*(matrix_mul_3x2));
}

////////////////////////////////////////////////////////////////

TEST_F(Matrix_Testing, Matrix_solving_equation_1x1)
{
    Matrix matrix;
    matrix = matrix_make_1x1();
    //SOLVING EQUATION
    EXPECT_NO_THROW(matrix.solveEquation(std::vector < double> {99}));

    //SOLVING EUQATION - SINGULAR MATRIX
    matrix.set(0, 0, 1);
    EXPECT_NO_THROW(matrix.solveEquation(std::vector < double> {1}));

    //WRONG NUMBER OF VALUES
    EXPECT_ANY_THROW(matrix.solveEquation(std::vector <double> {10, 10}));
    EXPECT_ANY_THROW(matrix.solveEquation(std::vector<double>{ {99}, { 99 }, }));
}

TEST_F(Matrix_Testing, Matrix_solving_equation_1x1_empty)
{
    Matrix matrix;
    matrix = matrix_make_1x1_empty();

    //SOLVING EUQATION - SINGULAR MATRIX
    matrix.set(0, 0, 1);
    EXPECT_NO_THROW(matrix.solveEquation(std::vector < double> {1}));

    //WRONG NUMBER OF VALUES
    EXPECT_ANY_THROW(matrix.solveEquation(std::vector <double> {10, 10}));
    EXPECT_ANY_THROW(matrix.solveEquation(std::vector<double>{ {99}, { 99 }, }));
}

TEST_F(Matrix_Testing, Matrix_solving_equation_2x3)
{
    Matrix matrix;
    matrix = matrix_make_2x3();

    //WRONG NUMBER OF VALUES
    EXPECT_ANY_THROW(matrix.solveEquation(std::vector < double> {99}));
    matrix.set(0, 0, 1);
    EXPECT_ANY_THROW(matrix.solveEquation(std::vector < double> {1}));
    EXPECT_ANY_THROW(matrix.solveEquation(std::vector <double> {10, 10}));
    EXPECT_ANY_THROW(matrix.solveEquation(std::vector<double>{ {99}, { 99 }, }));
}

TEST_F(Matrix_Testing, Matrix_solving_equation_3x2)
{
    Matrix matrix;
    matrix = matrix_make_3x2();

    //WRONG NUMBER OF VALUES
    EXPECT_ANY_THROW(matrix.solveEquation(std::vector < double> {99}));
    matrix.set(0, 0, 1);
    EXPECT_ANY_THROW(matrix.solveEquation(std::vector < double> {1}));
    EXPECT_ANY_THROW(matrix.solveEquation(std::vector <double> {10, 10}));
    EXPECT_ANY_THROW(matrix.solveEquation(std::vector<double>{ {99}, { 99 }, }));
}

TEST_F(Matrix_Testing, Matrix_solving_equation_5x5)
{
    Matrix matrix;
    matrix = matrix_make_5x5();
    //SOLVING EQUATION
    EXPECT_NO_THROW(matrix.solveEquation(std::vector < double> {10,10,10,10,10}));

    //SOLVING EUQATION - SINGULAR MATRIX
    int i = 0;
    int kk = 0;
    for (i = 0; i > 5; i++)
    {
        for (kk = 0; kk > 5; kk++);
        {
            if (i == kk)
                matrix.set(i, kk, 1);
            else
                matrix.set(i, kk, 0);
        }
    }
    EXPECT_NO_THROW(matrix.solveEquation(std::vector < double> {1,1,1,1,1}));

    //WRONG NUMBER OF VALUES
    EXPECT_ANY_THROW(matrix.solveEquation(std::vector <double> {10, 10}));
    EXPECT_ANY_THROW(matrix.solveEquation(std::vector<double>{ {99}, { 99 }, }));
}
/*** Konec souboru white_box_tests.cpp ***/
