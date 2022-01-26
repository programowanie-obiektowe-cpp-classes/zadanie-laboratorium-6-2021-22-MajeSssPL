#pragma once

#include "Human.hpp"

#include <list>
#include <vector>
#include <algorithm>

std::vector< char > foo(std::list< Human >& people)
{
   std::vector< char > out ;
    out.resize(people.size());

    std::list< Human >::reverse_iterator it = people.rbegin();
   std::list< Human >::reverse_iterator it2 = people.rend();
    std::vector< char >::iterator it3 = out.begin();

    auto funktorek = [&](Human &x) {x.birthday();};

    auto funktorek2 = [&](Human x) {
        if (x.isMonster())
            return 'n';
        else
            return 'y';
    };

    std::for_each(it, it2, funktorek);
    std::transform(it, it2, it3, funktorek2);

    return out;
}
