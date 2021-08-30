//https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/A1
#include <map>
#include <string>
#include <iostream>

using namespace std;

int best_swap_with_single_category(map<char, int>& letter_frequency, int total_letters)
{
    int most_repeated_letter = 0;
    for (auto& [letter, frequency] : letter_frequency)
        most_repeated_letter = max(most_repeated_letter, frequency);
    return 2 * (total_letters - most_repeated_letter);
}

int main()
{
    int n;
    string word;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> word;
        map<char, int> vowel_frequency, consonant_frequency;
        int vowel_count = 0;
        int consonant_count = 0;
        for (auto c : word)
        {
            if (strchr("AEIOU", c))
            {
                vowel_count++;
                vowel_frequency[c]++;
            }
            else
            {
                consonant_count++;
                consonant_frequency[c]++;
            }
        }
        int ans = min(best_swap_with_single_category(consonant_frequency, consonant_count) + vowel_count,
            best_swap_with_single_category(vowel_frequency, vowel_count) + consonant_count);

        cout << "Case #" << i << ": " << ans << '\n';
    }
}