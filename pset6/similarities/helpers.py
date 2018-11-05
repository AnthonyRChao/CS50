from nltk.tokenize import sent_tokenize


def intersection(a, b):
    return list(set(a) & set(b))


def lines(a, b):

    """
    Return lines in both a and b

    Implement lines in such a way that, given two strings, a and b,
    it returns a list of the lines that are, identically, in both a and b.
    The list should not contain any duplicates. Assume that lines in
    a and b will be be separated by \n, but the strings in the
    returned list should not end in \n. If both a and b contain
    one or more blank lines (i.e., a \n immediately preceded by
    no other characters), the returned list should include an
    empty string (i.e., "").
    """

    a_list = a.splitlines()
    b_list = b.splitlines()

    return intersection(a_list, b_list)


def sentences(a, b):

    """
    Return sentences in both a and b

    Implement sentences in such a way that, given two strings,
    a and b, it returns a list of the unique English sentences
    that are, identically, present in both a and b. The list
    should not contain any duplicates. Use sent_tokenize from
    the Natural Language Toolkit to "tokenize" (i.e., separate)
    each string into a list of sentences. It can be imported with:

    `from nltk.tokenize import sent_tokenize`

    Per its documentation, sent_tokenize, given a str as input,
    returns a list of English sentences therein. It assumes that
    its input is indeed English text (and not, e.g., code, which
    might coincidentally have periods too).
    """

    return intersection(sent_tokenize(a), sent_tokenize(b))


def substrings(a, b, n):

    """
    Return substrings of length n in both a and b

    Implement substrings in such a way that, given two strings, a and b,
    and an integer, n, it returns a list of all substrings of length n
    that are, identically, present in both a and b. The list should
    not contain any duplicates.

    Recall that a substring of length n of some string is just
    a sequence of n characters from that string. For instance,
    if n is 2 and the string is Yale, there are three possible
    substrings of length 2: Ya, al, and le. Meanwhile, if n is
    1 and the string is Harvard, there are seven possible substrings
    of length 1: H, a, r, v, a, r, and d. But once we eliminate
    duplicates, there are only five unique substrings: H, a, r, v, and d.
    """

    a_substrings = [a[i:i+n] for i in range(len(a) - (n-1))]
    b_substrings = [b[i:i+n] for i in range(len(b) - (n-1))]

    return intersection(a_substrings, b_substrings)
