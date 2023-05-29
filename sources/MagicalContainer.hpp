# ifndef MAGICALCONTAINER_HPP
# define MAGICALCONTAINER_HPP
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
namespace ariel{


    class MagicalContainer{

        vector<int> mystical_elements = {};


        public:
            void set_mystical_elements(vector<int>& container){
              mystical_elements = container;
            }
            MagicalContainer(){}

            void addElement(int num_to_add){
                mystical_elements.push_back(num_to_add);
            }

            void removeElement(int num_to_remove){
              //  mystical_elements.pop(num_to_remove);
                for(auto i= mystical_elements.begin(); i!=mystical_elements.end();i++){

                    if(*i == num_to_remove){
                        mystical_elements.erase(i);
                        i--;
                    }

                }

            }
            int size(){
                return mystical_elements.size();
            }

            vector<int>& get_vector(){
                return mystical_elements;
            }

            ~MagicalContainer()= default; 
            MagicalContainer (MagicalContainer &other){}

        
        public:

            class AscendingIterator{
                 
                MagicalContainer &container;
                int curr_index = 0;

                public:
                AscendingIterator(MagicalContainer &container): container(container){
                    sort(container.get_vector().begin(),container.get_vector().end());
                }

                AscendingIterator begin(){
                    return AscendingIterator(container);
                }
                AscendingIterator end(){
                    AscendingIterator end(container);
                    end.curr_index = container.size();
                    return end;
                }

                // copy con
                AscendingIterator(AscendingIterator &c_container): container(c_container.container){}


                // dealfult constractor plus opertorim


                 //Copy constructor
                   // AscendingIterator(const AscendingIterator& copy_container) : container(copy_container.container){}//Copy constructor

                    
                    int& operator*() const {
                        return container.get_vector()[static_cast<vector<int>::size_type>(curr_index)];
                    }

                    //Destructor
                    ~AscendingIterator() = default;


                    AscendingIterator& operator++(){
                        // Increment the index
                        curr_index++;
                        return *this;
                    }

                    // MagicalContainer& operator=(const MagicalContainer& other){
                    //     if (this != &other)
                    //     {
                    //         // Perform any necessary deep copying or assignment
                    //         // of data members and iterators

                    //         // Example:
                    //         // Copy the data members
                    //         // this->data = other.data;

                    //         // Copy the iterators
                    //         // this->iterator = other.iterator;
                    //     }

                    //     // Return the reference to the current object
                    //     return *this;
                    // }

                    bool operator==(const AscendingIterator& other_iterator) const {
                        return curr_index == other_iterator.curr_index;
                    }

                    bool operator!=(const AscendingIterator& other_iterator) const {
                        return curr_index != other_iterator.curr_index;
                    }

            };


            class PrimeIterator{

                int curr_index =0;
                MagicalContainer &container;
                
                bool is_prime(int num){
                    if(num == 2 || num==3){
                        return true;
                    }
                    if(num <=1){
                        return false;
                    }
                    for(int j = 2; j<=sqrt(num); j++){
                        if(num % j ==0){
                            return false;
                        }
                    }
                    return true;

                }

                public:

                PrimeIterator(MagicalContainer &container): container(container){
                    vector<int> is_prime_vector ={};
                    for(size_t i = 0; i<container.size(); i++){
                        if(is_prime(container.get_vector()[i])){
                            is_prime_vector.push_back(container.get_vector()[i]);
                        }
                    }
                    sort(is_prime_vector.begin(),is_prime_vector.end());

                    container.set_mystical_elements(is_prime_vector);
                }

                PrimeIterator begin(){
                    return PrimeIterator(container);
                }
                PrimeIterator end(){
                    PrimeIterator end(container);
                    end.curr_index = container.size();
                    return end; 
                }




//Copy constructor
                PrimeIterator(const PrimeIterator& other_container) : container(other_container.container){} //Copy constructor

                int& operator*() const {
                    return container.get_vector()[static_cast<vector<int>::size_type>(curr_index)];
                }

                //Destructor
                ~PrimeIterator() = default;

                PrimeIterator& operator++(){
                    // Increment the index
                    curr_index++;
                    return *this;
                }

                bool operator==(const PrimeIterator& other) const{
                    return curr_index == other.curr_index;
                }

                bool operator!=(const PrimeIterator& other) const{
                    return curr_index != other.curr_index;
                }

                bool operator>(const PrimeIterator& other) const{
                    return curr_index > other.curr_index;
                }

                bool operator<(const PrimeIterator& other) const{
                    return curr_index < other.curr_index;
                }

                
            };

            class SideCrossIterator{
                 
                MagicalContainer &container;
                int curr_index =0;

                public:
                SideCrossIterator(MagicalContainer &container): container(container){

                    int j = 0;
                    size_t beagin = 0;
                    size_t end = container.get_vector().size()-1;
                    vector<int> cross ={};
                    sort(container.get_vector().begin(),container.get_vector().end());

                    while(beagin <= end){

                        if (beagin == end){
                            cross.push_back(container.get_vector()[beagin]);
                            break;
                        }
                        else if(j % 2 == 0){
                            cross.push_back(container.get_vector()[beagin]);
                            beagin++;
                        }

                        else{
                            cross.push_back(container.get_vector()[end] );
                            end--;
                        }
                        j++;
                    }
            
                              container.set_mystical_elements(cross);
                }
          
                SideCrossIterator begin(){
                    return SideCrossIterator(container);
                }
                SideCrossIterator end(){
                    SideCrossIterator end(container);
                    end.curr_index = container.size();
                    return end;         
                }



  //Copy constructor
            SideCrossIterator(const SideCrossIterator& other_container) : container(other_container.container){} //Copy constructor

            int& operator*() const {
                return container.get_vector()[static_cast<vector<int>::size_type>(curr_index)];
            }

            //Destructor
            ~SideCrossIterator() = default;

            SideCrossIterator& operator++(){
                // Increment the index
                curr_index++;
                return *this;
            }

            bool operator==(const SideCrossIterator& other) const{
                return curr_index == other.curr_index;
            }

            bool operator!=(const SideCrossIterator& other) const{
                return curr_index != other.curr_index;
            }

            bool operator>(const SideCrossIterator& other) const{
                return curr_index > other.curr_index;
            }

            bool operator<(const SideCrossIterator& other) const{
                return curr_index < other.curr_index;
            }

            };

    }; 




}
# endif