/*
    Copyright 2015 Adobe
    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*/

/**************************************************************************************************/

#ifndef SLABFUTURE_IMMEDIATE_EXECUTOR_HPP
#define SLABFUTURE_IMMEDIATE_EXECUTOR_HPP

#include <chrono>

/**************************************************************************************************/

namespace stlab {

/**************************************************************************************************/

inline namespace v1 {

/**************************************************************************************************/

namespace detail {

/**************************************************************************************************/

struct immediate_executor_type
{
    template <typename F>
    void operator()(F&& f) {
        std::forward<F>(f)();
    }

    template <typename F>
    void operator()(std::chrono::system_clock::time_point, F&& f) {
        std::forward<F>(f)();
    }
};

/**************************************************************************************************/

} // namespace detail

/**************************************************************************************************/

constexpr auto immediate_executor = detail::immediate_executor_type{};

/**************************************************************************************************/

} // namespace v1

/**************************************************************************************************/

} // namespace stlab

/**************************************************************************************************/

#endif //SLABFUTURE_IMMEDIATE_EXECUTOR_HPP
