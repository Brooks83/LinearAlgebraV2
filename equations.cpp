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

//  works
float det2x2(std::vector<std::vector<float>> n)
{ return (n[0][0] * n[1][1]) - (n[0][1] * n[1][0]); }

//  IT WORKS (probably)
std::vector<std::vector<float>> calcSmallerMatrix(std::vector<std::vector<float>> matrix, short pos)
{
    short mSize = matrix.size();
    //scalarMMulti(matrix, scalar);
    std::vector<std::vector<float>> newVector;
    
    for(short row = 1; row < mSize; row++)
    {
        newVector.push_back(std::vector<float>());  //  Push back empty vector at row for elements
        for(short col = 0; col < mSize; col++)
        {
            //std::cout << matrix[row][col];
            if(col != pos)
            {
                newVector[row-1].push_back(matrix[row][col]);
                //std::cout << newVector[row-1][col];
            }
        }
    }

    return newVector;
}

//  WORKS :)
float detnxn(std::vector<std::vector<float>> o)
{
    short oSize = o.size();
    float scalar = 1;
    std::vector<std::vector<float>> calcdV;
    float determinant = 0;

    
    //  Need to figure out how to do it without nesting insane loops...
    //  Maybe I can figure out a cleaner way with memory addressing but not now lol.
    //  ----------UPDATE---------
    //  For any perfect matrix larger than 3x3, I don't know if it's possible to
    //  write this nonrecursively in a clean manner... You need to nest shit tons
    //  of matrix calculations because they exponentially multiply in numbers.

    //  Need to figure out how to calculate each determinent branch, with its scalars, 
    //  and nest each of those back into this function AND add up all of the outputs...
    //  I think I gotta add them all to a global float value then return that.

    //  Keep splitting matricies via recursion until it's many scalar*2x2, then return
    //  and add to a variable... however they will be in their own instances so this might be tricky...
    //  DO IT ONE SPLIT MATRIX PATH AT A TIME! This way it's less nesting and easier to track.

    //  I'm very close! Scalars are a bit fucked up, didn't expect that...
    //  You can't just multiply everything in the vector, rather after it's done calculating which will be
    //  much much MUCH more difficult to track. Ugh, what a headache.


    if(oSize == 2) 
    { 
        return det2x2(o); 
    }

    for(short col = 0; col < oSize; col++)
    {
        scalar = o[0][col];
        if(col % 2)
            scalar *= -1;
        std::cout << "scalar:" << scalar << "\n";
        
        if(oSize > 2)
        {
            calcdV = calcSmallerMatrix(o, col); //  First split into matrix branch -> recursion until 2x2 -> next col split again
            displayMatrix(calcdV);
            determinant += detnxn(calcdV) * scalar;
            std::cout << "Determinant:" << determinant << "\n";
        }
    }
    return determinant;
}