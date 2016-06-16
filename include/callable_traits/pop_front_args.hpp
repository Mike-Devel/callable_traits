/*!
@file

@copyright Barrett Adair 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/

#ifndef CALLABLE_TRAITS_POP_FRONT_HPP
#define CALLABLE_TRAITS_POP_FRONT_HPP

#include <callable_traits/detail/core.hpp>

namespace callable_traits {

    template<typename T, std::size_t Count = 1>
    struct pop_front_args {

        using type = detail::fail_if_invalid<
            typename detail::traits<T>::template pop_front<Count>,
            cannot_determine_parameters_for_this_type>;
    };


    template<typename T, std::size_t Count = 1>
    using pop_front_args_t =
        typename pop_front_args<T, Count>::type;

}

#endif //CALLABLE_TRAITS_POP_BACK_HPP
