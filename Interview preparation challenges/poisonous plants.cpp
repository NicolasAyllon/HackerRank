#include <bits/stdc++.h>
#include <list>

using namespace std;

int poisonousPlants(vector<int> p) {
    // If there are 0 or 1 plants, immediately return 0 days
    if(p.size() <= 1) return 0;
    
    // Step 1:
    // create list of non-increasing lists
    int days = 0;
    list<list<int>> plant_lists;
    list<int> nonIncreasingPlants;
    for(int i = 0; i < p.size(); ++i) {
        // Current plant is less than or equal to previous, 
        // so add to end of non-increasing sequence
        if(p[i] <= nonIncreasingPlants.back() || nonIncreasingPlants.empty()) {
            nonIncreasingPlants.push_back(p[i]);
        }
        // This plant has more pesticide than previous plant
        // Add current nonIncreasing list to plant_lists,
        // Wipe list, then start new non-increasing plant list with p[i] 
        else{
            plant_lists.push_back(nonIncreasingPlants);
            nonIncreasingPlants.clear();
            nonIncreasingPlants.push_back(p[i]);
        }
    }
    // push last nonIncreasingPlants list onto plant_lists
    plant_lists.push_back(nonIncreasingPlants);
    // Testing
    // printLists(plant_lists);
    while(plant_lists.size() > 1) {
        // Pop element from front of all lists
        auto it = plant_lists.begin();
        ++it; // skip over first list because 
        // its leftmost plant always survives
        while(it != plant_lists.end()) {
            (*it).pop_front();
            // Remove list if it's now empty
            if((*it).empty()) { 
                // std::list<T>.erase() returns an iterator 
                // to the following element
                it = plant_lists.erase(it); 
            }
            else { 
                ++it; 
            }
        }
        
        // Step 2: 
        // Merge adjacent lists into longer non-increasing lists. 
        // Example: {6, 5, 4} + {4, 3} -> {6, 5, 4, 4, 3}
        
        // Reset iterator it to beginning
        it = plant_lists.begin();
        // create iterator to element ahead of one pointed to by it (note the ++)
        auto it_next = ++plant_lists.begin();
        while(it_next != plant_lists.end()) {
            // Last element in current list is >= first element in next
            // so the lists can be merged (concatenated) into a non-increasing
            if((*it).back() >= (*it_next).front()) {
                // splice next list to end of this one
                (*it).splice((*it).end(), *it_next);
                // Now it_next points to an empty list so erase it
                // The erase() function returns the iterator to the next item
                it_next = plant_lists.erase(it_next);
                // Iterator it remains in place in case more lists need to be merged
            }
            // First element of next list is greater than last element in this one.
            // Lists can't be merged, so advance both iterators.  
            else {
                ++it;
                ++it_next;
            }
        }
        ++days;
    }
    return days;
}