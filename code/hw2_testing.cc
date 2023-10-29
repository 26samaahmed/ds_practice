#include <iomanip>
#include <utility>
#include <stack>
#include <memory>
#include <array>
#include <algorithm>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

void testing(std::vector<std::string> names, std::string word)
{
  auto iterating = std::find(names.begin(), names.end(), word);
  if (iterating != names.end())
  {
    std::cout << iterating - names.begin() << '\n';
  }
  else
  {
    std::cout << names.size() << '\n';
  }
}

// inserting to the right
void testing2(std::vector<std::string> words, std::string name, std::size_t position)
{
  // const auto        array          = words.begin();                       // An array is just a pointer to the first element
  // for (auto i = words.size() - 1; i != position; --i) {
  //   array[i] = std::move(array[i - 1]);
  // }
  auto it = words.begin();
  auto nx = std::next(it, position);
  words.insert(nx, name);

  for (auto i = 0; i < words.size(); i++)
  {
    std::cout << words[i] << " ";
  }
  std::cout << '\n';
}

// std::size_t find(std::vector<std::string> vector, std::string word) {
//    auto it = std::find(vector.begin(),
//                   vector.end(), word);
//    if (it != vector.end()) {
//      std::cout << "Element " << word <<
//                   " found at position : ";
//      return it - vector.begin() << '\n';
//      std::cout << " true\n";
//    }
//    else {
//      return vector.size();
//    }
//  }

// void testing5(std::vector<std::string> names, std::string word, std::vector<std::string> new_vec) {
//   if(find(names, word) > 1) {
//     return;
//   } else {
//     new_vec.insert(new_vec.begin(), word);
//   }

//   for (auto i = 0; i < new_vec.size(); i++)
//   {
//     std::cout << new_vec[i] << " ";
//   }
//   std::cout << '\n';

// }
// void findTheDifference(std::string s, std::string t) {
//     std::stack<char> s1;
//     std::stack<char> t1;
//     char uncommon;
//     for (char i : s) {
//       s1.push(i);
//       std::cout << i << " ";
//     }
//     std::cout << '\n';
//     for (char j : t) {
//       t1.push(j);
//       std::cout << j << " ";
//     }
//     std::cout << '\n';
//     for (int i = 0; i < t.size(); i++) {
//       if (!s.empty()) {
//         if (s1.top() != t1.top()) {
//           uncommon = t1.top();
//         } else {
//             s1.pop();
//             t1.pop();
//         }
//       }
//     }
//     std::cout << uncommon << '\n';
// }

// void insert(std::vector<int> vec, int val, size_t offset) {
//   auto position = vec.begin() + offset + 1;
//    std::construct_at( vec.end(),   std::move( *(vec.end()-1) ) );
//    *position = val;
//    for (auto i: vec) {
//     std::cout << i << " ";
//    }
//    std::cout << '\n';
// }

// int main()
// {
//   std::vector<int> names = {1, 54 ,2 , 9, 0};
//   insert(names, 60, 2);
//   // std::vector<std::string> names = {"sama", "salma", "salma", "nesma", "saad"};
//   // std::vector<std::string> new_vec = {"nothing yet"};
//   // testing(names, "mohamed");
//   // testing2(names, "mostafa", 2);
//   // find(names, "saad");
//   // testing5(names, "nesma", new_vec);
//   // testing5(names, "mo", new_vec);
//   // testing5(names, "aloha", new_vec);
//   // testing5(names, "salma", new_vec);
//   // findTheDifference("abcd", "abcde");
//   // findTheDifference("", "y");
// }
int main()
{

  // std::array<int, 5> an_array {1, 2, 3, 4, 5};

  // for (auto i : an_array) {
  //     std::cout << i << " ";
  // }
  // std::cout << "\n\n";

  // /////////////////////////////////////////////////

  // std::cout << *an_array.end() << '\n';
  // std::cout << *(an_array.end() - 1) << '\n';
  // std::cout << *(an_array.end() - 2) << '\n';
  std::vector<int> a{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> b{1, 2, 3, 4, 5, 6, 7};
  std::vector<std::string> c{"α", "β", "γ", "δ", "ε", "ζ", "η"};

  // std::cout << "vector<S> \tvector<int> \tvector<string>\n";
  // std::cout << a << "  " << b << "  " << c << '\n';
  std::cout << "the original a";
  for (auto i : a)
  {
    std::cout << i << " ";
  }
  std::cout << '\n';
  std::cout << "shifting a to the left";
  std::shift_left(begin(a), end(a), 3);
  for (auto i : a)
  {
    std::cout << i << " ";
  }
  std::cout << '\n';

  std::cout << "shifting a to the right";
  std::shift_right(begin(a), end(a), 2);
  for (auto i : a)
  {
    std::cout << i << " ";
  }
  std::cout << '\n';

  std::cout << " the original b";
  for (auto i : b)
  {
    std::cout << i << " ";
  }
  std::cout << '\n';

  std::cout << "shifting b to the left";
  for (auto i : b)
  {
    std::cout << i << " ";
  }
  std::cout << '\n';

  std::shift_left(begin(b), end(b), 3);
  for (auto i : b)
  {
    std::cout << i << " ";
  }
  std::cout << '\n';

  std::cout << "shifting b to the right";
  std::shift_right(begin(b), end(b), 2);
  for (auto i : b)
  {
    std::cout << i << " ";
  }
  std::cout << '\n';

  std::cout << " the original c";
  for (auto i : c)
  {
    std::cout << i << " ";
  }
  std::cout << '\n';

  std::cout << "shifting c to the left";
  std::shift_left(begin(c), end(c), 3);
  for (auto i : c)
  {
    std::cout << i << " ";
  }
  std::cout << '\n';

  std::cout << "shifting c to the right";
  std::shift_right(begin(c), end(c), 2);
  for (auto i : c)
  {
    std::cout << i << " ";
  }
  std::cout << '\n';
  // std::cout << a << "  " << b << "  " << c << '\n';
}