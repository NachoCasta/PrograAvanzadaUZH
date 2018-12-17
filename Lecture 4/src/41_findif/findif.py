def findIf(iterator, matcher):
    for elem in iterator:
        if matcher.match(elem):
            return elem
    return None

class Matcher:
    def match(elem):
        return elem > 4000000
