#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <functional>
using namespace sol143;
using namespace std;

/*takeaways
  - split the linked list into two from the middle
  - reverse the second list
  - cut off the tie and make sure the two lists are completely
    separated
  - merge two lists into one
*/

void Solution::reorderList(Node *head)
{
  Node *slow = head, *fast = head, *next1, *next2;
  while (fast != nullptr && fast->next != nullptr)
    slow = slow->next, fast = fast->next->next;

  /* slow should now point to the center */
  auto r = reverse(slow->next);

  /*cut it off; so the two lists are completely
    separated
    - this is a very important step and can
      be easily ignored
  */

  slow->next = nullptr;

  /* merge two lists
     - r should run out first as it starts
       from the node after the middle
  */
  while (r != nullptr)
  {
    next1 = head->next;
    next2 = r->next;
    head->next = r;
    r->next = next1;
    head = next1;
    r = next2;
  }
}

Node *Solution::reverse(Node *head)
{
  if (head == nullptr || head->next == nullptr)
    return head;

  Node *prev = nullptr, *cur = head, *next;

  while (cur != nullptr)
  {
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }

  return prev;
}
