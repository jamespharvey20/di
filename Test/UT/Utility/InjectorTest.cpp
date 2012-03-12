//
// Copyright (c) 2012 Krzysztof Jusiak (krzysztof at jusiak dot net)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#include <gtest/gtest.h>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/equal.hpp>
#include "QDeps/Utility/Injector.hpp"

namespace QDeps
{
namespace Utility
{
namespace UT
{

using namespace boost::mpl;

class A { };
class B { };
class C { };

struct Module
{
    typedef vector0<> Binding;
    template<typename T> struct Deps : boost::mpl::vector<A, B, C> { };
    template<typename T> struct Keys : boost::mpl::vector<int> { };
};

TEST(Injector, CtorEmpty)
{
    typedef Injector<> Inj;

    Inj l_inj; //have to compile
    (void)l_inj;

    EXPECT_TRUE((
        equal
        <
            vector0<>,
            Inj::Deps
        >::value
    ));

    EXPECT_TRUE((
        equal
        <
            vector0<>,
            Inj::Keys
        >::value
    ));
}

TEST(Injector, Module)
{
    typedef Injector<Module> Inj;

    Inj l_inj; //have to compile
    (void)l_inj;

    EXPECT_TRUE((
        equal
        <
            vector<C, B, A>,
            Inj::Deps
        >::value
    ));

    EXPECT_TRUE((
        equal
        <
            vector<int>,
            Inj::Keys
        >::value
    ));
}

} // namespace UT
} // namespace Utility
} // namespace QDeps

