// main.cpp
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>
#include <numeric>
#include <future>
#include <thread>
#include "sample.h"
#include "sample.h"

int main()
{

    std::string strs[]{"Ruby", "Emerald", "Sapphire", "Opal"};
    unsigned nums[]{10, 20, 30, 40};

    std::unique_ptr<TreasureBox> tbr(newTreasureBox());
    std::unique_ptr<TreasureBox> ptr(newTreasureBox(strs, nums, 4));

    std::string_view sv = "Ruby";
    std::string s = "Opal";
    ptr->update(sv);
    ptr->update(s);
    ptr->display();

    *ptr += Gem{"Diamond", 50} += Gem{"Amber", 60};
    (*ptr += Gem{"Pearl", 70}).display();

    std::promise<unsigned> pro;
    std::future<unsigned> fut = pro.get_future();

    std::thread t1;
    t1.join();
    t1 = std::thread(task, std::ref(pro));
    std::cout << "Promised Future: " << fut.get() << std::endl;
    t1.join();
}