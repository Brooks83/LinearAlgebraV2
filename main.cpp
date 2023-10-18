#include <iostream>
#include <string>
#include <vector>
#include "equations.h"

using namespace std;



main()
{
    std::vector<std::vector<float>> matrix1 = { {1, 2, 2, 1},
                                                {0, 3, 2, 1},
                                                {5, 4, 0.5, 0},
                                                {2, 1, 1, 3} };
    std::vector<std::vector<float>> matrix2 = { {2, -4.1},
                                                {8.7, 5.8} };
    std::vector<std::vector<float>> matrix3 = { {1, 2, 3},
                                                {2, 3, 1},
                                                {3, 2, 1} };

    displayMatrix(matrix1);
    float testA = detnxn(matrix1);
    cout << "\nFinal Answer: " << testA;
 
    return 0;
};