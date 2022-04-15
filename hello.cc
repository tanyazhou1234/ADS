#include <iostream>
#include <vector>
#include <algorithm>
// compile method: g++ -std=c++11 -o output_program_name
//  -std=c++11: 用c++11的版本编译
//  -o: o指output_name, -o后面跟的是，编译出来的可执行代码的名字
namespace tanya {
    
    class vector {
        public:
            int a, b;
    };

};

int main() {
    std::cout << "hello" << std::endl;
    std::cout << "world" << std::endl;
    
    std::vector<int> a{3, 1, 2};
    tanya::vector apple;
    apple.a = 3;
    
    std::sort(a.begin(), a.end());
    for(int & x : a) {
        std::cout << x << std::endl;
    }
}
