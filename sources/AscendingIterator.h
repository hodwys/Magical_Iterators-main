# ifndef ASCENDINGHITERATOR.H
# define ASCENDINGHITERATOR.H
#include <iostream>
#include <vector>
#include "MagicalContainer.h"

using namespace std;
namespace ariel{

    class AscendinfIterator{

        public:
            AscendinfIterator(MagicalContainer container);
            AscendinfIterator begin();
            AscendinfIterator end();

    };


}
# endif