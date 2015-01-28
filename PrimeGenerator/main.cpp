//
//  main.cpp
//  PrimeGenerator
//
//  Created by Vinod Gupta on 1/28/15.
//  Copyright (c) 2015 Vinod Gupta. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>

void primeGenerator(std::vector<int> &prime_vct, unsigned int maxPrime)
{
    prime_vct.push_back(1);
    prime_vct.push_back(2);
    
    for (unsigned int i = 3; i < maxPrime; i += 2)
    {
        int found = 1;
        double i_sqrt = sqrt(i);
        std::vector<int>::iterator itr = prime_vct.begin();
        while (itr != prime_vct.end())
        {
            if (*itr >= 3)
            {
                if (*itr>i_sqrt)
                    break;
                
                if (i%*itr == 0)
                {
                    found = 0;
                    break;
                }
            }
            ++itr;
        }
        if (found)
        {
            prime_vct.push_back(i);
            if (prime_vct.size() > maxPrime-1)
                break;
        }
    }
    
}

int main(int argc, char* argv[])
{
    std::vector<int> prime_vct;
    primeGenerator(prime_vct, 50000);
    
    for (std::vector<int>::iterator itr = prime_vct.begin(); itr != prime_vct.end(); ++itr)
    {
        std::cout << *itr << "\t";
    }
    std::cout << std::endl;
    return 0;
    
}
