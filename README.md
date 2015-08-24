Terse STL algorithms
====================

STL algorithms return the generated container.

Example
-------

```c++
#include <terse/algorithm.hpp>
#include <terse/numeric.hpp>
#include <vector>
#include <map>
using namespace std;
using namespace terse::dst_concrete;
using namespace terse::dst_template;
using namespace terse::dst_default;

int main()
{
    vector<const char*> vs{"1", "2"};
    const char* as[] = {"1", "2"};
    vector<int> vi;
    map<int, double> i2d;

    //accepts container:
    vi = transform<vector<int>>(vs, atoi);
    //accepts array:
    vi = transform<vector<int>>(as, atoi);
    //accepts initializer_list:
    vi = transform<vector<int>>({"1", "2"}, atoi);
    //accepts lambda:
    vi = transform<vector<int>>(vs, [](const char* s){return atoi(s);});
    //may deduce value_type:
    vi = transform<vector>(vs, atoi);
    //may use the default container type (vector or basic_string):
    vi = transform(vs, atoi);
    //has all generating STL algorithms:
    vi = copy({1, 2});
    //supports associative containers:
    i2d = generate_n<map>(1, []{return make_pair(1, 2.3);});
}
```

Explanation
-----------

[Article (English)](docs/article-en.html)<br>
[Article (Russian)](docs/article-ru.html)

Installation
------------

Headers only.

Author
------

<a href="mailto:kberezovsky@gmail.com">Konstantin Berezovsky</a>
