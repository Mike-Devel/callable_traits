/*!
@file

@copyright Barrett Adair 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/

#ifndef CALLABLE_TRAITS_ADD_VARARGS_HPP
#define CALLABLE_TRAITS_ADD_VARARGS_HPP

#include <callable_traits/detail/required_definitions.hpp>

namespace callable_traits {

    namespace detail {

        template<bool Sfinae>
        struct add_varargs_error : sfinae_error {

            static_assert(Sfinae,
                "callable_traits::add_varargs<T> is not "
                "a meaningful operation for this T. T must "
                "be a function, function pointer, function "
                "reference, or member function pointer.");
        };
    }

    template<typename T>
    struct add_varargs {

        using type = detail::fail_if_invalid<
            typename detail::traits<T>::add_varargs,
            detail::add_varargs_error<true>>;
    };

    template<typename T>
    using add_varargs_t = typename add_varargs<T>::type;
}

#endif
