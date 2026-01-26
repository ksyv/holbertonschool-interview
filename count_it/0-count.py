#!/usr/bin/python3
"""
Recursive function to count keywords in Reddit hot titles.
"""
import requests


def count_words(subreddit, word_list, counts=None, after=None):
    """Queries Reddit API and counts keyword occurrences recursively."""
    if counts is None:
        counts = {}
        for word in word_list:
            w = word.lower()
            counts[w] = counts.get(w, 0) + 1
        
        # Initialize match tracker: {word: 0}
        # and store multiplier: {word: frequency_in_list}
        multiplier = {w: counts[w] for w in counts}
        matches = {w: 0 for w in counts}
        return count_words(subreddit, word_list, (matches, multiplier), after)

    matches, multiplier = counts
    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    headers = {"User-Agent": "linux:count_it:v1.0"}
    params = {"after": after, "limit": 100}

    response = requests.get(url, headers=headers, params=params,
                            allow_redirects=False)

    if response.status_code != 200:
        return

    data = response.json().get("data")
    children = data.get("children")
    for post in children:
        title_words = post.get("data").get("title").lower().split()
        for word in title_words:
            if word in matches:
                matches[word] += 1

    after = data.get("after")
    if after:
        return count_words(subreddit, word_list, (matches, multiplier), after)

    # Calculate final results by applying multipliers
    final_counts = {}
    for word in matches:
        if matches[word] > 0:
            final_counts[word] = matches[word] * multiplier[word]

    if not final_counts:
        return

    sorted_res = sorted(final_counts.items(), key=lambda kv: (-kv[1], kv[0]))
    for word, count in sorted_res:
        print(f"{word}: {count}")