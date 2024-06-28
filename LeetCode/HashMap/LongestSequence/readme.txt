In this question it was written than we have to solve it in O(n) time complexity so i was 
very hesitant in using any king of nested loop then i build my own solution using if 
but that solution required removal of duplicate elements which also resulted in increased time 
complexity so from chat gpt we get
 for (auto it = numMap.begin(); it != numMap.end(); ++it) {
            // Check if it is the start of a sequence
            if (numMap.find(it->first - 1) == numMap.end()) {
                int currentNum = it->first;
                int currentStreak = 1;

                // Continue the sequence
                while (numMap.find(currentNum + 1) != numMap.end()) {
                    currentNum++;
                    currentStreak++;
                }

                longestStreak = std::max(longestStreak, currentStreak);
           
a nested loop but not of O(n^2) good question