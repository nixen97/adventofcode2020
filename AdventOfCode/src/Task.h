#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>

#include "CustomReaders.h"

namespace AOC
{
    class Task
    {
    private:
        int m_MajorVersion;
        int m_MinorVersion;
        const std::string m_InputPath;

    protected:
        Task(const int major, const int minor, std::string input)
            : m_MajorVersion(major), m_MinorVersion(minor), m_InputPath(std::move(input))
        { }

    public:
        virtual ~Task() = default;

    public:
        void addSolutionToStream(std::ostream& stream);

    private:
        std::pair<std::string, long long> getSolutionWithTiming();
        virtual std::string solution() = 0;

    protected:
        template<typename T>
        T readWithCustomReader(T(*f)(std::string));

        template<typename T>
        std::pair<std::shared_ptr<std::vector<T>>, size_t> readInput();
    };

    template <typename T>
    T Task::readWithCustomReader(T(* f)(std::string))
    {
        return f(m_InputPath);
    }

    template <typename T>
    std::pair<std::shared_ptr<std::vector<T>>, size_t> Task::readInput()
    {
        std::ifstream fileStream;

        fileStream.open(m_InputPath);

        if (!fileStream.is_open())
            return { nullptr, -1 };

        std::shared_ptr<std::vector<T>> out = std::make_shared<std::vector<T>>();

        T tempObject;

        while (!fileStream.eof())
        {
            fileStream >> tempObject;

            out->push_back(std::move(tempObject));
        }

        return { out, out->size() };
    }
}
