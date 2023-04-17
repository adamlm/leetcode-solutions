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
    bool canMakeArithmeticProgression(vector<int>& arr) {
        std::sort(std::begin(arr), std::end(arr));

        return isProgression(std::cbegin(arr), std::cend(arr));
    }
};

