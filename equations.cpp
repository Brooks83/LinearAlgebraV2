#include <cmath>
#include <iostream>
#include <vector>
#include "equations.h"


void displayMatrix(std::vector<std::vector<float>> m)
{
    for(short x = 0; x < m.size(); x++) 
    {
        std::cout << "[ ";
        for(short y = 0; y < m[x].size(); y++) 
            {std::cout << m[x][y] << " ";}
        std::cout << "]\n";
    }
}

float det2x2(std::vector<std::vector<float>> n)
{ return (n[0][0] * n[1][1]) - (n[0][1] * n[1][0]); }

//  Calculates the submatrix needed for the determinant
std::vector<std::vector<float>> calcSmallerMatrix(std::vector<std::vector<float>> &matrix, short pos)
{
    short mSize = matrix.size();
    std::vector<std::vector<float>> newVector;
    
    for(short row = 1; row < mSize; row++)
    {
        newVector.push_back(std::vector<float>());  //  Push back empty vector at row for elements
        for(short col = 0; col < mSize; col++)
        {
            if(col != pos)
            {
                newVector[row-1].push_back(matrix[row][col]);
            }
        }
    }

    return newVector;
}


//  Grabs the square matrix and loops each set of submatrix calculations down to
//  its 2x2 determinant and adds to a total sum, returning a final determinant.

float detnxn(std::vector<std::vector<float>> matrix)
{
    short mSize = matrix.size();
    float scalar = 1;
    std::vector<std::vector<float>> calcdV;
    float determinant = 0;

    if(mSize == 2) 
    { 
        return det2x2(matrix); 
    }

    for(short col = 0; col < mSize; col++)
    {
        scalar = matrix[0][col];
        if(col % 2)
            scalar *= -1;
        
        if(mSize > 2)
        {
            calcdV = calcSmallerMatrix(matrix, col); //  First split into matrix branch -> recursion until 2x2 -> next col split again
            determinant += detnxn(calcdV) * scalar;
        }
    }
    return determinant;
}