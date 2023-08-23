#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    int i = 0;
    std::string path = "C:/Users/kevin/Documents/test/";

    for (const auto& entry : fs::directory_iterator(path)) {
        std::string my_dest = "img" + std::to_string(i) + ".jpg";
        std::string my_source = entry.path().string();
        my_dest = path + my_dest;

        fs::rename(my_source, my_dest);
        std::cout << "Renamed: " << my_source << " to " << my_dest << std::endl;

        i++;
    }

    return 0;
}
