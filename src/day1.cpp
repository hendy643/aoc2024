#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

#include "day1.h"

// counts the number of times the left lists number appears in the right list.
int appearance_counter(int left_number) {
    int ret = 0;

    for (const auto right_number: right) {
        if (left_number == right_number) {
            ret += right_number;
        }
    }

    return ret;
}

void similarity_calculator() {
    int appearances = 0;
    for (const auto left_number: left) {
        appearances = appearances + appearance_counter(left_number);
    }

    std::cout << "Total Similarity: " << appearances << std::endl;
}

int main() {
    // this is part 1.
    distance_calculator();

    //this is part 2.
    similarity_calculator();
}

void distance_calculator() {
    process_input();

    std::ranges::sort(left);
    std::ranges::sort(right);

    const auto count = left.size();
    auto distances = 0;

    for (int i = 0; i < count; i++) {
        distances = distances + std::abs(left[i] - right[i]);
    }

    std::cout << "Total distance: " << distances << std::endl;
}

std::vector<std::string> split_newline(const std::string &ip) {
    auto result = std::vector<std::string>{};
    auto ss = std::stringstream{ip};

    for (std::string line; std::getline(ss, line, '\n');)
        result.push_back(line);

    return result;
}

std::pair<int, int> split_space(const std::string &ip) {
    auto left = ip.substr(0, ip.find(' '));
    auto right = ip.substr(ip.find(' ') + 1);

    return {std::stoi(left), std::stoi(right)};
}

void process_input() {
    auto lines = split_newline(input);

    for (const auto &line: lines) {
        auto [first, second] = split_space(line);
        left.emplace_back(first);
        right.emplace_back(second);
    }
}
