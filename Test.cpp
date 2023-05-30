#include "doctest.h"
# include "sources/MagicalContainer.hpp"
#include "doctest.h"
#include <iostream>
#include <vector>
#include <algorithm> 

using namespace ariel;



TEST_CASE("MagicalContainer containet"){

    MagicalContainer container;

    CHECK_EQ(container.size(),0);

    container.addElement(1);
    CHECK_EQ(container.size(),1);

    container.addElement(4);
    container.addElement(2);
    container.addElement(3);
    CHECK_EQ(container.size(),4);

    CHECK_EQ(container.get_vector()[0] , 1);

    CHECK_EQ(container.get_vector()[1] , 4);
    CHECK_EQ(container.get_vector()[2] , 2);
    CHECK_EQ(container.get_vector()[3] , 3);

    container.removeElement(3);
    CHECK_EQ(container.size(),3);

    CHECK_NOTHROW(container.get_vector()[5] = 7);

// set container
    vector temp {6,8};
    container.set_mystical_elements(temp);
    CHECK_EQ(container.size(),2);
    CHECK_EQ(container.get_vector()[0] , 6);
    CHECK_EQ(container.get_vector()[1] , 8);
    
// same parametrim
    vector same {6,6};
    container.set_mystical_elements(same);

    CHECK_EQ(container.get_vector()[0] , 6);
    CHECK_EQ(container.get_vector()[1] , 6);

}






TEST_CASE("AscendingIterator"){

    MagicalContainer container;

    container.addElement(10);
    container.addElement(20);
    container.addElement(50);
    CHECK_EQ( container.get_vector()[2],50 );
    container.addElement(90);
    container.addElement(30);
    container.addElement(80);
    container.addElement(60);
    container.addElement(40);
    container.addElement(70);

    MagicalContainer::AscendingIterator Asc_container(container);

    CHECK_EQ( container.get_vector()[2],30 );


    auto start = Asc_container.begin();
    CHECK_EQ(*start, 10);

    size_t end = container.get_vector().size()-1;

   for( size_t i = 0; i<end ; i++ ){
        ++start;
   }
    CHECK_EQ(*start, 90);

    ++start;
    auto fin = Asc_container.end();
    CHECK_EQ(start, fin);    
}

TEST_CASE("same paramtres whit AscendingIterator") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(2);
    container.addElement(2);
    container.addElement(3);
    
    MagicalContainer::AscendingIterator Asc_con(container);
    auto start = Asc_con.begin();

    CHECK_EQ(*start,  1);  
    ++start;
    CHECK_EQ(*start,  2);     
    ++start;
    CHECK_EQ(*start,  2);  
    ++start;
    CHECK_EQ(*start,  2);  
    ++start;
    CHECK_EQ(*start, 3); 
    ++start;

    container.removeElement(2);
    auto start2 = Asc_con.begin();

    CHECK_EQ(*start2,  1);  
    ++start2;
    CHECK_EQ(*start2,  3);     

}


TEST_CASE("PrimeIterator"){

    MagicalContainer container;

    container.addElement(11);
    container.addElement(23);
    container.addElement(50);
    CHECK_EQ( container.get_vector()[2],50 );
    container.addElement(97);
    container.addElement(30);
    container.addElement(83);
    container.addElement(60);
    container.addElement(40);
    container.addElement(79);
    // 11 23 30 40 50 60 79 83 97 
    // 11 23 79 83 97

    MagicalContainer::PrimeIterator prime_container(container);

    CHECK_EQ( container.get_vector()[2],79 );


    auto start = prime_container.begin();
    CHECK_EQ(*start, 11);

    size_t end = container.get_vector().size()-1;

   for( size_t i = 0; i<end ; i++ ){
        ++start;
   }
    CHECK_EQ(*start, 97);

    ++start;
    auto fin = prime_container.end();
    CHECK_EQ(start, fin);

}


TEST_CASE("SideCrossIterator"){

    MagicalContainer container;

    container.addElement(10);
    container.addElement(20);
    container.addElement(50);
    CHECK_EQ( container.get_vector()[2],50 );
    container.addElement(90);
    container.addElement(30);
    container.addElement(80);
    container.addElement(60);
    container.addElement(40);
    container.addElement(70);
    // 10 20 30 40 50 60 70 80 90 
    // 10 90 20 80 30 70 40 60 50 

    MagicalContainer::SideCrossIterator cross_container(container);

    CHECK_EQ( container.get_vector()[2],20 );


    auto start = cross_container.begin();
    CHECK_EQ(*start, 10);

    size_t end = container.get_vector().size()-1;

   for( size_t i = 0; i<end ; i++ ){
        ++start;
   }
    CHECK_EQ(*start, 50);

    ++start;
    auto fin = cross_container.end();
    CHECK_EQ(start, fin);

}