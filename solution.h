
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <string>
#include <stack>

using namespace std;
namespace sol143
{

  class Solution
  {
  private:
    Node *reverse(Node *head);

  public:
    void reorderList(Node *head);
  };
}
#endif