#include <iostream>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

#ifdef _WIN32
#define popen _popen
#define pclose _pclose
#endif

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

int main() {
    const char* command = "python script.py";  // �����쿡���� python�� �⺻ ��ɾ�
    std::string result = exec(command);
    std::cout << "Result from Python script: " << result << std::endl;
    return 0;
}