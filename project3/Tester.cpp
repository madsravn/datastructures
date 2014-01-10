#include "Tester.hpp"
#include "Timer.hpp"
#include <cmath>
#include <random>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "Fully.hpp"
#include "Partial.hpp"

Tester::Tester()
{
}

/*
 * INSERT TESTS
 */
void Tester::PartialUpdateTop(const unsigned int times)
{
    Partial p;
    for(unsigned i = 0; i <= times; i++) {
        p.Insert(i+1);
    }

	Timer t;
    unsigned int comparisons = 0;
    for(unsigned i = times + 1; i < REPS + times + 1; i++) {
        Partial p_test = p;
        t.start();
        p_test.Insert(i+1);
		t.stop();

    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}

void Tester::PartialUpdateMid(const unsigned int times)
{

    Partial p;
    for(unsigned i = 0; i <= times; i++) {
        p.Insert(i+1);
    }

	Timer t;
    unsigned int comparisons = 0;
    for(unsigned i = times + 1; i < REPS + times + 1; i++) {
        Partial p_test = p;
        int size = p.late()/2;
        if(size % 2 == 0) {
            size++;
        }
        t.start();
        p_test.Insert(i+1, size);
		t.stop();

    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;

}

void Tester::PartialUpdateBottom(const unsigned int times)
{
    Partial p;
    for(unsigned i = 0; i <= times; i++) {
        p.Insert(i+1);
    }

	Timer t;
    unsigned int comparisons = 0;
    for(unsigned i = times + 1; i < REPS + times + 1; i++) {
        Partial p_test = p;
        t.start();
        p_test.Insert(i+1, 1);
		t.stop();

    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;


}

/*
 * DELE TESTS
 */
void Tester::FullyUpdateTop(const unsigned int times)
{
    Fully f;
    for(unsigned i = 0; i <= times; i++) {
        f.Insert(i+1);
    }
    f.Rebalance();
	Timer t;
    unsigned int comparisons = 0;
    for(unsigned i = times + 1; i < REPS + times + 1; i++) {
        Fully f_test = f;
        t.start();
        f_test.Insert(i+1);
		t.stop();

    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;

}

void Tester::FullyUpdateMid(const unsigned int times)
{
    Fully f;
    for(unsigned i = 0; i <= times; i++) {
        f.Insert(i+1);
    }
    f.Rebalance();
	Timer t;
    unsigned int comparisons = 0;
    for(unsigned i = times + 1; i < REPS + times + 1; i++) {
        Fully f_test = f;
        int size = f.late()/2;
        if(size % 2 == 0) {
            size++;
        }
 
        t.start();
        f_test.Insert(i+1,size);
		t.stop();

    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;



}

void Tester::FullyUpdateBottom(const unsigned int times)
{
    Fully f;
    for(unsigned i = 0; i <= times; i++) {
        f.Insert(i+1);
    }
    f.Rebalance();

	Timer t;
    unsigned int comparisons = 0;
    for(unsigned i = times + 1; i < REPS + times + 1; i++) {
        Fully f_test = f;
        t.start();
        f_test.Insert(i+1,1);
		t.stop();

    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;



}

/*
 * DECREASE KEY TESTS
 */
void Tester::PartialQueryTop(const unsigned int times)       
{
    Partial p;
    for(unsigned i = 0; i <= times; i++) {
        p.Insert(i+1);
    }

	Timer t;
    unsigned int comparisons = 0;
    for(unsigned i = times + 1; i < REPS + times + 1; i++) {
        Partial p_test = p;
        t.start();
        p_test.Query(1);
		t.stop();

    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;


}

void Tester::PartialQueryMid(const unsigned int times)
{
    Partial p;
    for(unsigned i = 0; i <= times; i++) {
        p.Insert(i+1);
    }

	Timer t;
    unsigned int comparisons = 0;
    for(unsigned i = times + 1; i < REPS + times + 1; i++) {
        Partial p_test = p;
        int size = p.late()/2;
        if(size % 2 == 0) {
            size++;
        }
        t.start();
        p_test.Query(1, size);
		t.stop();

    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;

}

void Tester::PartialQueryBottom(const unsigned int times)
{
    Partial p;
    for(unsigned i = 0; i <= times; i++) {
        p.Insert(i+1);
    }

	Timer t;
    unsigned int comparisons = 0;
    for(unsigned i = times + 1; i < REPS + times + 1; i++) {
        Partial p_test = p;
        t.start();
        p_test.Query(1, 3);
		t.stop();

    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;

}



void Tester::FullyQueryTop(const unsigned int times)       
{
    Fully f;
    for(unsigned i = 0; i <= times; i++) {
        f.Insert(i+1);
    }
    f.Rebalance();

	Timer t;
    unsigned int comparisons = 0;
    for(unsigned i = times + 1; i < REPS + times + 1; i++) {
        Fully f_test = f;
        t.start();
        f_test.Query(1);
		t.stop();

    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;



}

void Tester::FullyQueryMid(const unsigned int times)
{
    Fully f;
    for(unsigned i = 0; i <= times; i++) {
        f.Insert(i+1);
    }
    f.Rebalance();

	Timer t;
    unsigned int comparisons = 0;
    for(unsigned i = times + 1; i < REPS + times + 1; i++) {
        Fully f_test = f;
        int size = f.late()/2;
        if(size % 2 == 0) {
            size++;
        }
        t.start();
        f_test.Query(1, size);
		t.stop();

    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;




}

void Tester::FullyQueryBottom(const unsigned int times)
{
    Fully f;
    for(unsigned i = 0; i <= times; i++) {
        f.Insert(i+1);
    }
    f.Rebalance();

	Timer t;
    unsigned int comparisons = 0;
    for(unsigned i = times + 1; i < REPS + times + 1; i++) {
        Fully f_test = f;
        t.start();
        f_test.Query(1, 3);
		t.stop();

    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;

}

void Tester::TestRetro(const unsigned int highpower) {
	std::cout << "\n *** >>> Testing Queue <<< ***\n" << std::endl;
	unsigned int i;
	int power;

	
	i = 4;
    power = 2;
	
	std::cout << "\nTesting PartialUpdateTop\n" << std::endl;
	
	while(power <= highpower) {
        PartialUpdateTop(i);
        power++;
        i = pow(2,power);
    }
	
	std::cout << "\nTesting PartialUpdateMid\n" << std::endl;
	i = 4;
    power = 2;
	while(power <= highpower) {
        PartialUpdateMid(i);
        power++;
        i = pow(2,power);
    }
	
	std::cout << "\nTesting PartialUpdateBottom\n" << std::endl;
    i = 4;
    power = 2;
	while(power <= highpower) {
        PartialUpdateBottom(i);
        power++;
        i = pow(2,power);
    }

	std::cout << "\nTesting FullyUpdateTop\n" << std::endl;
	i = 4;
    power = 2;
	while(power <= highpower) {
        FullyUpdateTop(i);
        power++;
        i = pow(2,power);
    }

	std::cout << "\nTesting FullyUpdateMid\n" << std::endl;
	i = 4;
    power = 2;
	while(power <= highpower) {
        FullyUpdateMid(i);
        power++;
        i = pow(2,power);
    }

    std::cout << "\nTesting FullyUpdateBottom\n" << std::endl;
    i = 4;
    power = 2;
	while(power <= highpower) {
        FullyUpdateBottom(i);
        power++;
        i = pow(2,power);
    }

    std::cout << "\nTesting PartialQueryTop\n" << std::endl;
	i = 4;
    power = 2;
	while(power <= highpower) {
		PartialQueryTop(i);
        power++;
        i = pow(2,power);
    }

	std::cout << "\nTesting PartialQueryMid\n" << std::endl;
	i = 4;
    power = 2;
	while(power <= highpower) {
        PartialQueryMid(i);
        power++;
        i = pow(2,power);
    }

	std::cout << "\nTesting PartialQueryBottom\n" << std::endl;
	i = 4;
    power = 2;
	while(power <= highpower) {
		PartialQueryBottom(i);
        power++;
        i = pow(2,power);
    }
	
	std::cout << "\nTesting FullyQueryTop\n" << std::endl;
	i = 4;
    power = 2;
	while(power <= highpower) {
		FullyQueryTop(i);
        power++;
        i = pow(2,power);
    }

	std::cout << "\nTesting FullyQueryMid\n" << std::endl;
	i = 4;
    power = 2;
	while(power <= highpower) {
        FullyQueryMid(i);
        power++;
        i = pow(2,power);
    }

	std::cout << "\nTesting FullyQueryBottom\n" << std::endl;
	i = 4;
    power = 2;
	while(power <= highpower) {
		FullyQueryBottom(i);
        power++;
        i = pow(2,power);
    }
}

void Tester::run(const unsigned int highpower) {	

	unsigned int seed = 12345;
    std::default_random_engine dre(seed);
    std::uniform_int_distribution<> dis(1, 10000);
 
	for (int n = 0; n < (REPS * 2) + pow(2, highpower) + 1; ++n) {
		
		RAN_NUMS.push_back(n);
        UPS.push_back(n);
        DOWNS.push_back(n);
	}

    std::random_shuffle(RAN_NUMS.begin(), RAN_NUMS.end()); // Shuffle the data
    std::reverse(DOWNS.begin(), DOWNS.end()); // Reverse the data

	TestRetro(highpower);
}
