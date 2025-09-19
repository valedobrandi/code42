#include "Span.hpp"
#include <limits>
#include <algorithm>
#include <stdexcept>


Span::Span(void)
{
}

Span::Span(unsigned int n): max_store_size(n)
{
}

Span::~Span(void)
{
}

Span::Span(const Span &other) : max_store_size(other.max_store_size)
{
    container.clear();
    for (size_t it = 0; it < container.size() && it < max_store_size; ++it) {
        container[it] = other.container[it];
    }
}

Span &Span::operator=(const Span &other)
{
    if (this != &other) {
        this->max_store_size = other.max_store_size;
        container.clear();
        for (size_t it = 0; it < container.size() && it < max_store_size; ++it) {
            container[it] = other.container[it];
        }
    }
    return *this;
}

void Span::addNumber(unsigned int value)
{
    unsigned int next_store_size = container.size() + 1;
    if (next_store_size > max_store_size) {
        throw std::runtime_error("the container is full");
        return;
    }
    container.push_back(value);
}

unsigned int Span::shortestSpan(void)
{
    if (container.size() < 2) {
        throw std::runtime_error("not enough elements in the span");
    }

    std::vector<int> sorted = container;
    std::sort(sorted.begin(), sorted.end());

    unsigned int last_diff = std::numeric_limits<unsigned int>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        unsigned int diff = (sorted[i] - sorted[i - 1]);
        if (diff < last_diff) {
            last_diff = diff;
        }
    }
    return last_diff;
}

unsigned int Span::longestSpan(void)
{
    if (container.size() < 2) {
        throw std::runtime_error("not enough elements in the span");
    }

    std::vector<int>::const_iterator min_it = std::min_element(container.begin(), container.end());
    std::vector<int>::const_iterator max_it = std::max_element(container.begin(), container.end());
    return static_cast<unsigned int>(*max_it - *min_it);
}

void Span::addMultipleNumbers(vectorIntIt begin, vectorIntIt end)
{
    container.insert(container.end(), begin, end);
}
