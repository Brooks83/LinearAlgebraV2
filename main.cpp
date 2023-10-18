#include <iostream>
#include <string>
#include <vector>
#include "equations.h"


main()
{
    std::vector<std::vector<float>> matrix1 = {{1, 2, 2, 1}, {0, 3, -2, 1}, {-5, 4, 0.5, 0}, {2, 1, 1, 3}};

    displayMatrix(matrix1);
    float testA = detnxn(matrix1);
    std::cout << "\nFinal Answer: " << testA;
 
    return 0;
};