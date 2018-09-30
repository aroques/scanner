#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <algorithm>

template <typename T, typename Container>
bool item_in_list(T item, Container list)
{
    return std::find(list.begin(), list.end(), item) != list.end();
}

#endif // !CONTAINER_HPP