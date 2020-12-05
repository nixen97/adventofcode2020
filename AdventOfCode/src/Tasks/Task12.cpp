#include "Task12.h"

namespace AOC
{
    /**
     * Binary search
     *
     * O(N^2) time
     * O(1) space
     */
    std::string Task12::solution()
    {
        auto [l, N] = readInput<int>();

        auto v = *l.get();

        // O(N log N)
        std::sort(v.begin(), v.end());

        // O(N^2)
        for (int i = 0; i < N-2; i++)
        {
            // Two pointer search
            int left = i + 1;
            int right = N - 1;

            while (left < right)
            {
                if (v[i] + v[left] + v[right] == m_Target)
                    return std::to_string(v[i] * v[left] * v[right]);

                if (v[i] + v[left] + v[right] > m_Target)
                    right--;
                else if (v[i] + v[left] + v[right] < m_Target)
                    left++;
            }
        }
        return "No result";
    }
}
