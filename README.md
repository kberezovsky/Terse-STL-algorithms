Terse STL algorithms
====================

STL algorithms return the generated container.

Example
-------

//include, using
vector<const char*> vs{"1", "2"};
const char* as[] = {"1", "2"};
vector<int> vi;
map<int, double> i2d;
vi = transform<vector<int>>(vs, atoi);            //accepts container
vi = transform<vector<int>>(as, atoi);            //accepts array
vi = transform<vector<int>>({"1", "2"}, atoi);    //accepts initializer_list
vi = transform<vector<int>>(vs, [](const char* s){return atoi(s);});    //accepts lambda
vi = transform<vector>(vs, atoi);                 //may deduce value_type
vi = transform(vs, atoi);                         //may use the default container type (vector or basic_string)
vi = copy({1, 2});                                //all generating STL algorithms
i2d = generate_n<map>(1, []{return make_pair(1, 2.3);})    //supports associative containers

Explanation
-----------

[Article (English)](doc/article-en.html)
[Article (Russian)](doc/article-ru.html)

Installation
------------

Headers only.

Author
------

[Konstantin Berezovsky]<kberezovsky@gmail.com>
