def stack_way(text):
    stack = []
    for x in text:
        stack.append(x)
    reverse = ""
    while stack:
        reverse += stack.pop()
    return reverse

def recursive_way(text):
    if len(text) <= 1:
        return text
    return recursive_way(text[1:]) + text[0]

def simple_way(text):
    return text[::-1]

original = input('Enter some text: ')
print(stack_way(original))
print(recursive_way(original))
print(simple_way(original))
