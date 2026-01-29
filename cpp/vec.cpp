#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v_arr;
    v_arr.push_back(7);
    v_arr.push_back(56);
    v_arr.push_back(2);
    
    for(const auto& i: v_arr) {
        std::cout<< i << std::endl;
    }
    
    std::vector<int> v2_arr;
   

    std::cout << "Size: " << v_arr.capacity() << std::endl;
    std::cout << "Empty ? " << (v2_arr.empty() ?  "YES" : "NO") << std::endl;
    std::cout << "Max Size: " << v_arr.max_size() << std::endl;
    v_arr.pop_back();
    
    for(const auto& i: v_arr) {
        std::cout<< i << std::endl;
    }

    return 0;
}