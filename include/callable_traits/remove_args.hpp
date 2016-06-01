/*!
@file

@copyright Barrett Adair 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/

#ifndef CALLABLE_TRAITS_REMOVE_ARGS_HPP
#define CALLABLE_TRAITS_REMOVE_ARGS_HPP

#include <callable_traits/detail/required_definitions.hpp>

namespace callable_traits {

    namespace detail {

        template<bool Sfinae>
        struct remove_args_error : sfinae_error {

            static_assert(Sfinae,
                "callable_traits::push_back<T, Args...> is "
                "not a meaningful operation for this T.");
        };
    }

    template<std::size_t Index, typename T, std::size_t Count = 1>
    using remove_args = detail::fail_if_invalid<
        typename detail::traits<T>::template remove_args<Index, Count>,
        detail::remove_args_error<true>>;
}

#endif //CALLABLE_TRAITS_REMOVE_ARGS_HPP
