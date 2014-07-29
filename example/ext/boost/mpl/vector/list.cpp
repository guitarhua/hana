/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/detail/static_assert.hpp>
#include <boost/hana/ext/boost/mpl/vector.hpp>
#include <boost/hana/ext/std/integral_constant.hpp>
#include <boost/hana/type.hpp>

#include <boost/mpl/vector.hpp>
#include <type_traits>
using namespace boost::hana;
namespace mpl = boost::mpl;


int main() {
    //! [main]
    using namespace operators; // required to be able to == MPL vectors

    BOOST_HANA_STATIC_ASSERT(
        cons(type<int>, mpl::vector<char>{}) == mpl::vector<int, char>{}
    );

    // error: only Types can go in a MPL vector
    // cons(1, mpl::vector<int>{});

    BOOST_HANA_STATIC_ASSERT(
        filter(trait<std::is_integral>, mpl::vector<int, float, char, void>{})
        ==
        mpl::vector<int, char>{}
    );
    //! [main]
}
