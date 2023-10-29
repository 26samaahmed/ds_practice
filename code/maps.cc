#include <map>
#include <iostream>
#include <string>

int main(){
std::map<int, char> number_map {{1, 'a'}, {2, 'b'}, {3, 'c'}};
for (std::pair<int, char> pair : number_map) {
  std::cout << "key is: " << pair.first << " and value is: " << pair.second << '\n';
}
std::cout << '\n';

// Testing the index operator to search for a pair that doesnt exist
// this is the process of using the index operartor, we will look at the left side since the key is defined there
// we will search first if the key is in the map. Since none of the keys are value 6, the operator will insert a new pair
// with the key and value that i specified. so the map now would have 4 elements
number_map[6] = 'e'; 
std::cout << "After first modification\n";
for (std::pair<int, char> pair : number_map) {
  std::cout << "key is: " << pair.first << " and value is: " << pair.second << '\n';
}
std::cout << '\n';

// testing if i search for a key that already exists
// this is the process of what will happen if we already have a pair with the same key. Remember that maps don't have duplicates,
// if we want duplicates, we would use std::multimap and so here, when we use a key that already exists, it would override the original
// value. If my original pair was {2, 'b'}, the pair would become {2, 'f'}
number_map[2] = 'f'; 
std::cout << "After second modification\n";
for (std::pair<int, char> pair : number_map) {
  std::cout << "key is: " << pair.first << " and value is: " << pair.second << '\n';
}
std::cout << '\n';

// Note that keys are sorted in a map, if i searched for a key 6 and it didnt exists, it would be inserted at the end of the map. BUT,
// if i were to to search for a pair with key 0 and it didnt exist, the pair would be inserted at the beginning. What's good about this
// is that when we have sorted elements, searching for a pair would be logarithmic time. Like a binary search algorithm, we keep splitting
// into halves instead of going through the whole container.

// Note that there is no push back in maps but we do have the insert function
// if we dont specify the insertion point/ where, then the time complexity O(log2 n)
// if we did have a location specified, then it would be constant time



}
