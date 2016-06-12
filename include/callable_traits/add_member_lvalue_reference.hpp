/*!
@file

@copyright Barrett Adair 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/

#ifndef CALLABLE_TRAITS_ADD_MEMBER_LVALUE_REFERENCE_HPP
#define CALLABLE_TRAITS_ADD_MEMBER_LVALUE_REFERENCE_HPP

#include <callable_traits/detail/core.hpp>

namespace callable_traits {

    template<typename T>
    struct add_member_lvalue_reference {

        using type = detail::fail_if_invalid<
            typename detail::traits<T>::add_member_lvalue_reference,
            member_qualifiers_are_illegal_for_this_type>;
    };

    template<typename T>
    using add_member_lvalue_reference_t =
        typename add_member_lvalue_reference<T>::type;
}

#endif
