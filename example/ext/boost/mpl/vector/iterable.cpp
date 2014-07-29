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

    BOOST_HANA_STATIC_ASSERT(head(mpl::vector<int, char, void>{}) == type<int>);

    BOOST_HANA_STATIC_ASSERT(tail(mpl::vector<int, char, void>{}) == mpl::vector<char, void>{});

    BOOST_HANA_STATIC_ASSERT(
        drop_while(trait<std::is_floating_point>, mpl::vector<float, double const, int, float&>{})
        ==
        mpl::vector<int, float&>{}
    );
    //! [main]
}
