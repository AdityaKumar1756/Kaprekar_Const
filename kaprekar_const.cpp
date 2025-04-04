#include <iostream>
#include <vector>
#include <bits/stdc++.h>


int main() {
    
    int digit_1 = 0;
    int digit_2 = 0;
    int digit_3 = 0;
    int digit_4 = 0;

    std::cout<<"Please enter the four digit number by entering each digit."<<std::endl;
    // stores the values of the digits into the variables "digit_i"
    // for 1 <= i <= 4
    std::cin>>digit_1>>digit_2>>digit_3>>digit_4; 

    std::vector<int> digits = {digit_1, digit_2, digit_3, digit_4};

    std::vector<int> digits_ascending = digits;
    std::sort(digits_ascending.begin(), digits_ascending.end());

    std::vector<int> digits_descending = digits;
    std::reverse(digits_ascending.begin(), digits_ascending.end());

    int four_digit_version = 0;
    int num_it = 0;

    while (four_digit_version != 6174) {
        four_digit_version = 1000*digits.at(0) + 100*digits.at(1) + 10*digits.at(2) + digits.at(3);

        if (four_digit_version == 0000 || 
            four_digit_version == 1111 || 
            four_digit_version == 2222 || 
            four_digit_version == 3333 || 
            four_digit_version == 4444 || 
            four_digit_version == 5555 || 
            four_digit_version == 6666 || 
            four_digit_version == 7777 || 
            four_digit_version == 8888 || 
            four_digit_version == 9999) {
                std::cout<<"Sorry! Only 4-digit numbers with at least 2 distinct digits..."<<std::endl;
            }


        if (num_it == 0) {
            std::cout<<std::endl<<"Four digit number entered: "<<four_digit_version<<std::endl;
        }

        num_it ++;

        int big_4_digit = digits_descending.at(3)*1000 + digits_descending.at(2)*100 + digits_descending.at(1)*10 + digits_descending.at(0);
        int small_4_digit = digits_ascending.at(3)*1000 + digits_ascending.at(2)*100 + digits_ascending.at(1)*10 + digits_ascending.at(0);

        four_digit_version = big_4_digit - small_4_digit;

        std::cout<<"The difference between the descending digits number and the ascending digits number is "<<big_4_digit<<" - "<<small_4_digit<<" = "<<four_digit_version<<std::endl<<std::endl;
        if (four_digit_version == 6174) {
            std::cout<<"6174 was reached! It took "<<num_it<<" iteration(s).\n\n";
            break;
        }
        std::cout<<"For the next iteration, the unordered four digit number is "<<four_digit_version<<std::endl;

        digits = {(four_digit_version / 1000) % 10, (four_digit_version / 100) % 10, (four_digit_version / 10) % 10, four_digit_version % 10};

        digits_ascending = digits;
        std::sort(digits_ascending.begin(), digits_ascending.end());


        digits_descending = digits_ascending;
        std::reverse(digits_ascending.begin(), digits_ascending.end());
    }

}
