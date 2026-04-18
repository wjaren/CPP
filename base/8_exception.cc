#include <iostream>
#include <stdexcept>

int divide(int a, int b) {
    if (b == 0) {
        // throw 后面的语句不会再执行，所以通常只保留一种异常类型即可。
        throw std::runtime_error("Division by zero is not allowed");
    }
    return a / b;
}

int main() {
    try {
        divide(10, 0);

        // 上面已经抛出异常时，这里就不会执行到。
        throw std::runtime_error("An error occurred");
    } catch (const int e) {
        std::cerr << "Caught exception: " << e << std::endl;
    } catch (const char *e) {
        std::cerr << "Caught exception: " << e << std::endl;
    } catch (const std::exception &e) {
        // 大多数标准库异常都继承自 std::exception。
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
