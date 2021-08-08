// https://leetcode.com/problems/minimum-number-of-frogs-croaking/

/*
    Note the use of c and k
*/

class Solution {
    unordered_map<char, int> frequency; // Stores how many times each sound has occured. Sounds are c, r, o, a, k. 
    /*
     *  At any time, for a sequence to be valid, number of 'c' must not be less than 'r'.
     *  Similarly, #'r' shouldn't  less than #'o', and so on.
     */
    bool isStateValid() {
         return (frequency['c'] >= frequency['r']) &&
                (frequency['r'] >= frequency['o']) &&
                (frequency['o'] >= frequency['a']) && 
                (frequency['a'] >= frequency['k']);
    }
    
public:
    /*
     *  Minimum number of frogs that we need is maximum number of frogs that are croaking
     *  simultaneously.
     *  Each "croaking" is a sequence of c, r, o, a, and k.
     *  Sound is a character in croakSequence.
     */
    int minNumberOfFrogs(string croakSequence) {
        int numCroakingFrogs = 0; // Number of distinct frogs that are croaking at any given time.
        int answer = 0; // Hold the final answer.
        for (char &sound: croakSequence) { // for each sound i.e. character.
            frequency[sound]++; // Note the sound.
            if (!isStateValid()) { // Make sure we are still in valid state.
                return -1;
            }
            if (sound == 'c') { // New "croaking" always begins at 'c'.
                numCroakingFrogs++; // Addional frog for the new "croaking".
            } else if (sound == 'k') { // A "croaking" ends at 'k'.
                numCroakingFrogs--; // Some frog has stopped croaking now.
            }
            answer = max(answer, numCroakingFrogs); // Maximum number of frogs that are croaking 
                                                    // simultaneously over a period.
        }
        return numCroakingFrogs == 0 ? answer : -1; // Make sure all frogs have completed the croaking.
    }
};