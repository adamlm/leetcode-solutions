template <typename InputIterator>
auto isProgression(InputIterator begin, InputIterator end) {
    if (end - begin <= 1) {
        return true;
    }

    const auto delta{*(begin + 1) - *begin};
    for (auto it{begin}; it < end - 1; ++it) {
        if (*(it + 1) - *it != delta) {
            return false;
        }
    }

    return true;
}

class Solution {
public:
    bool canMakeArithmeticProgression(const vector<int>& arr) {
        std::vector<int> numbers{arr};
        std::sort(std::begin(numbers), std::end(numbers));
        
        return isProgression(std::cbegin(numbers), std::cend(numbers));
    }
};

