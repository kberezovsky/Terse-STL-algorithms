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
    const vector<const char*> vs{"1", "2"};

    //algorithm returns the generated container:
    const vector<int> vi_1 = transform<vector<int>>(vs, atoi);
    //algorithm may deduce value_type:
    const vector<int> vi_2 = transform<vector>(vs, atoi);
    //algorithm may use the default container type (vector or basic_string):
    const vector<int> vi_3 = transform(vs, atoi);
    //library has all generating STL algorithms:
    const vector<int> vi_4 = copy({1, 2});
    //library supports the associative containers:
    const map<int, double> mid = generate_n<map>(1, []{return make_pair(1, .5);});
}
```

Explanation
-----------

[Article (English)](http://htmlpreview.github.com/?https://github.com/kberezovsky/Terse-STL-algorithms/blob/master/docs/article-en.html)<br>
[Article (Russian)](http://htmlpreview.github.com/?https://github.com/kberezovsky/Terse-STL-algorithms/blob/master/docs/article-ru.html)

Installation
------------

Headers only.

Author
------

<a href="mailto:kberezovsky@gmail.com">Konstantin Berezovsky</a>
