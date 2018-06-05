type = {}
type['('] = ')'
type[')'] = '('
type['{'] = '}'
type['}'] = '{'
type['['] = ']'
type[']'] = '['

stack = []
s = input()
ans = 0
for i in s:
    if i in '])}':
        if len(stack):
            if stack[-1] ==