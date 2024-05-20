This is the very optimized solution made with the help of chat gpt
to reduce the time complexity we are iterating both the array with the help of single loop
here we are not actually inserting the players element but just pretending to know the position 
by doing that we can save the delete and insert operation 
vector<int> result;
    int rank_size = ranked.size();
    int i = rank_size - 1; // Pointer for ranked array

    for (int score : player) ***this is the direct way to access the value***
    {
        while (i >= 0 && score >= ranked[i]) {
            i--;
        }
        result.push_back(i + 2); // rank is (i + 1 + 1)
        ***normal person will increment the i back but it has used that also***
    }

    return result;