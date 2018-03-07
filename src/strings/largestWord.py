# Problem Name is &&& Longest Word &&& PLEASE DO NOT REMOVE THIS LINE.

"""
Instructions to candidate.
 1) Given a a string of letters and a dictionary, the function longestWord should
    find the longest word or words in the dictionary that can be made from the letters
    Input: letters = "oet", dictionary = {"to","toe","toes"}
    Output: {"toe"}
    Only lowercase letters will occur in the dictionary and the letters
    The length of letters will be between 1 and 10 characters
    The solution should work well for a dictionary of over 100,000 words
 2) Run this code in the REPL to observe its behaviour. The
    execution entry point is main.
 3) Consider adding some additional tests in doTestsPass().
 4) Implement the longestWord() method correctly.
 5) If time permits, introduce '?' which can represent any letter.  "to?" could match to "toe", "ton" etc
"""

class Dictionary:
    def __init__(self, entries):
        self.entries = entries;

    def contains(self, word):
        return word in self.entries;


def longestWord(letters, dictionary):

    # list of words
    words = list(dictionary.entries)
    words = sorted(words, key = len, reverse=True)

    lmap = {}
    # mappings of (letters , count)
    for char in letters:
        lmap[char] = lmap.get(char, 0) + 1

    count , ans = 0, []

    for word in words:
        if count > 0 and len(word) < count:
            continue

        wmap = {}
        for char in word:
            wmap[char] = wmap.get(char, 0) + 1

        found = all(val <= lmap.get(key, 0) for key, val in wmap.iteritems())

        if found:
            if (count == 0) or (len(word) == count):
                ans.append(word)
                count = len(word)
    return ans

words = ('to', 'toe', 'toes', 'doe', 'dog', 'god', 'dogs', 'book', 'banana')
words = ('to', 'too', 'tooo')
dictionary = Dictionary(words)

def doTestsPass():
    result = ['too'] == longestWord('oto', dictionary)
    result = result and ['toe'] == longestWord('toe', dictionary)
    result = result and ['toes','dogs'] == longestWord('osetdg', dictionary)

    if(result):
        print('All tests pass')
    else:
        print('There are test failures')

if __name__ == "__main__":
    doTestsPass()


