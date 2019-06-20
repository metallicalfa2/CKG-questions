vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    // We create a hashmap to maintain occurence of each string in strings array.
    // I choose map because lookup time complexity is O(logn) 
    map <string, int> hashmap;

    // vector to return the answer array 
    vector<int> answer;
    for(int i=0; i<strings.size(); i++){
        hashmap[strings[i]]++;
    }

    for(int i=0; i<queries.size(); i++){
        // Push occurences to answer
        answer.push_back(hashmap[queries[i]]);
    }
    return answer;

}