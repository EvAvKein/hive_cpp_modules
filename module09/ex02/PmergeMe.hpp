/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:36:43 by ekeinan           #+#    #+#             */
/*   Updated: 2025/08/27 18:17:27 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <chrono>
#include <algorithm>
#include <vector>
#include <deque>
#include <iostream>
#include <unordered_map>

std::vector<int> argvToIntVector(int argc, char **argv);

template <typename Container = std::vector<int>>
class PmergeMe
{
public:
    PmergeMe(void) = delete;
    PmergeMe(PmergeMe &copied) = delete;
    PmergeMe &operator=(PmergeMe &assgined) = delete;
    ~PmergeMe(void) = default;

    PmergeMe(Container const &container) : container(container)
    {
    }

    size_t comparisons = 0;

    static void test(int argc, char **argv)
    {
        std::vector<int> vec = argvToIntVector(argc, argv);

        std::cout << "Before sorting: ";
        for (size_t i = 0; i < vec.size(); ++i)
            std::cout << vec[i] << " ";
        std::cout << std::endl;

        PmergeMe<std::vector<int>> pmergeMeVec(vec);
        std::chrono::microseconds vecTime = pmergeMeVec.sort();
        size_t vecComparisons = pmergeMeVec.comparisons;

        std::cout << "After sorting:  ";
        for (size_t i = 0; i < pmergeMeVec.getContainer().size(); ++i)
            std::cout << pmergeMeVec.getContainer()[i] << " ";
        std::cout << std::endl;

        PmergeMe<std::deque<int>> pmergeMeDeq(std::deque<int>(vec.begin(), vec.end()));
        std::chrono::microseconds dequeTime = pmergeMeDeq.sort();
        size_t dequeComparisons = pmergeMeDeq.comparisons;

        std::cout << "Vector sorted in " << std::chrono::duration_cast<std::chrono::microseconds>(vecTime)
                  << ", taking " << vecComparisons << " comparisons" << std::endl;
        std::cout << "Deque sorted in " << std::chrono::duration_cast<std::chrono::microseconds>(dequeTime)
                  << ", taking " << dequeComparisons << " comparisons" << std::endl;
    }

    std::chrono::microseconds sort(void)
    {
        sorting_start = clock.now();
        ford_johnson(container);
        auto time = clock.now() - sorting_start;

        if (!std::is_sorted(container.begin(), container.end()))
            throw std::runtime_error("Container was not sorted (after " + std::to_string(comparisons) + " comparisons)");

        return std::chrono::duration_cast<std::chrono::microseconds>(time);
    }

private:
    std::chrono::high_resolution_clock clock;
    std::chrono::time_point<std::chrono::high_resolution_clock> sorting_start;
    Container container;

    const Container &getContainer() const
    {
        return container;
    }

    Container ford_johnson(Container &source_chain)
    {
        if (source_chain.size() <= 1)
            return source_chain;

        auto straggler = source_chain.back();
        bool odd = source_chain.size() % 2;

        if (odd)
            source_chain.pop_back();

        Container main_chain;
        std::unordered_map<typename Container::value_type, typename Container::value_type> pair_map;
        auto less_than = [this](int val1, int val2) // Needs to declared here due to use in upper_bound
        {
            ++comparisons;
            return (val1 < val2);
        };

        for (auto i = source_chain.cbegin(); i != source_chain.cend(); i += 2)
        {
            auto &num1 = *i;
            auto &num2 = *(i + 1);

            if (less_than(num2, num1))
            {
                main_chain.push_back(num1);
                pair_map.emplace(num1, num2);
            }
            else
            {
                main_chain.push_back(num2);
                pair_map.emplace(num2, num1);
            }
        }

        if (odd)
            source_chain.push_back(straggler);

        ford_johnson(main_chain);

        Container pend_chain;

        for (auto it = main_chain.cbegin(); it != main_chain.cend(); ++it)
            pend_chain.push_back(pair_map.at(*it));
        if (odd)
            pend_chain.push_back(straggler);

        main_chain.insert(main_chain.cbegin(), pend_chain.front());

        size_t prev_jsthal = 1;
        size_t curr_jsthal = 3;

        size_t insertions = 1;
        size_t pend_i;
        size_t to_insert;
        size_t offset;

        while (insertions < pend_chain.size())
        {
            if (curr_jsthal <= pend_chain.size())
            {
                to_insert = curr_jsthal - prev_jsthal;
                pend_i = curr_jsthal - 1;
            }
            else
            {
                to_insert = pend_chain.size() - prev_jsthal;
                pend_i = pend_chain.size() - 1;
            }

            offset = insertions + pend_i;
            if (offset > main_chain.size())
                offset = main_chain.size();

            while (to_insert--)
            {
                auto element = pend_chain[pend_i--];
                auto begin = main_chain.cbegin();
                auto limit = begin + offset;
                auto insertion_pos = std::upper_bound(begin, limit, element, less_than);

                main_chain.insert(insertion_pos, element);
                ++insertions;
            }

            size_t temp = curr_jsthal;

            curr_jsthal += 2 * prev_jsthal;
            prev_jsthal = temp;
        }
        std::swap(source_chain, main_chain);

        return source_chain;
    }
};

#endif
