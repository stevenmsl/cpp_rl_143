#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol143;

/*
Given 1->2->3->4, reorder it to 1->4->2->3.
*/

tuple<Node *, string>
testFixture1()
{

  auto l = new Node(1);
  l->next = new Node(2);
  l->next->next = new Node(3);
  l->next->next->next = new Node(4);
  return make_tuple(l, "1->4->2->3");
}

/*
Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
*/

tuple<Node *, string>
testFixture2()
{

  auto l = new Node(1);
  l->next = new Node(2);
  l->next->next = new Node(3);
  l->next->next->next = new Node(4);
  l->next->next->next->next = new Node(5);

  return make_tuple(l, "1->5->2->4->3");
}

void test1()
{
  auto f = testFixture1();
  auto l = get<0>(f);
  Solution sol;

  cout << "Expect to see : " << get<1>(f) << endl;

  sol.reorderList(l);

  string s;

  while (l != nullptr)
  {
    s += to_string(l->val) + "->";
    l = l->next;
  }

  if (s.back() == '>')
    s.pop_back(), s.pop_back();

  cout << s << endl;
}

void test2()
{
  auto f = testFixture2();
  auto l = get<0>(f);
  Solution sol;

  cout << "Expect to see : " << get<1>(f) << endl;

  sol.reorderList(l);

  string s;

  while (l != nullptr)
  {
    s += to_string(l->val) + "->";
    l = l->next;
  }

  if (s.back() == '>')
    s.pop_back(), s.pop_back();

  cout << s << endl;
}

main()
{
  test1();
  test2();
  return 0;
}